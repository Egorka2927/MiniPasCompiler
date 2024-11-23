%{

  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "strtab.h"

  void yyerror(char *msg);    /* forward declaration */
  /* exported by the lexer (made with flex) */
  FILE *output;
  extern int yylex(void);
  extern char *yytext;
  extern void showErrorLine();
  extern void initLexer(FILE *f);
  extern void finalizeLexer();
  extern char *identifier;
  extern int linenr;
  int currentScope = 0;
  int count = 0;
  int startRange;
  int endRange;
  char *functionIdentifier;
  char *arrayIdentifier;
  int indexes[100];
  void addIndex();
  void addIdentifierData(int type, int dataType);
  void addArrayData(int type, int dataType, int startRange, int endRange);
  void prepareFunction();
  void popSymbolTableList();
  void addFunctionData(int type, int dataType);
  void addFunctionIdentifierToList();
  void checkUndeclaredIdentifier(int rhsFlag);
  void checkRedeclaredConstant();
  void checkFunctionParameters();
  void updateParamList(int type, int dataType, int isVar);
  void addPassedParam(int type);
  void checkRedeclaredIdentifier();
  int getArrayReturnDataType(char *arrayIdentifier);
  int getFunctionReturnDataType();
  int getIdentifierReturnDataType();
  int resolveArithExpr(int expr1, int expr2);
  void checkBinaryArithTypes(int expr1, int expr2);
  void checkDivModArithTypes(int expr1, int expr2);
  void checkNegation(int expr);
  void checkArrayIndex(int expr);
  void checkArrayRange(int expr1, int expr2);
  void checkIfFunction();
  void checkAssignment(int expr1, int expr2);
  void checkLhsAssignment();
  void checkBoolAtom(int expr1, int expr2);
  void generateConstants(int type);
  void generateVariables(int type);
  void generateArray(int type);
  void generateFunction(int type);
  void generateTempVariable(int type, int identifierCheck);
  void generateTempVariableExpression(char operator);
  void generateAssignment();
  void getArrayIndex();
  void addArrayIdentifierToList();
  void addTempVariableStartToList();
  void addReadingIdentifierToList();
  void generateReadingIdentifiers();
  void generateWriting();
  void generateTempVariableRelop(char operator, int type);
  void getArrayIndexIdentifier();
  void generateTempVariableArray();
  void generateTempVariableArrayReading();

  typedef enum Type {
    INT_DATA_TYPE,
    REAL_DATA_TYPE,
    VOID_DATA_TYPE,
    CONST_INT_TYPE,
    CONST_REAL_TYPE,
    ARRAY_TYPE
  } Type;

  typedef struct PassedParam {
    Type type;
    Type dataType;
    int isVar;
    char name[100];
    char arrayIdentifierIndexes[100][100];
    int arrayIdentifierIndexesLength;
  } PassedParam;

  typedef struct Identifier {
    char name[100];
    int created;
    int location;
    int startRange;
    int endRange;
    Type type;
    Type dataType;
    struct Identifier *params;
    int isVar;
    int paramsLength;
    PassedParam passedParamList[100];
    int passedParamListLength;
    int isFunction;
  } Identifier;

  int paramCount = 0;
  int paramLength = 0;
  Identifier paramList[100];
  int passedParamsFlag = 0;

  int passedParamIndexesList[100];
  int passedParamIndexesListLength = 0;

  int functionIdentifierIndexes[100];
  int functionIdentifierIndexesLength = 0;

  char arrayIdentifierIndexes[100][100];
  int arrayIdentifierIndexesLength = 0;
  int inArray = 0;
  char currentIndex[100];

  int isVar = 1;
  int isVarSwitch = 0;
  
  int lhsArrayFlag = 0;

  Identifier **symbolTableList;

  int generationParamCount = 0;
  int generationCount = 0;
  int generateVariablesFlag = 1;

  int tempVariableCount = 0;
  int labelCount = 0;
  
  int labelStack[100];
  int labelStackLength = 0;

  typedef struct TempVariable {
    int count;
    int type;
    int isArr;
  } TempVariable;

  TempVariable tempStack[100];
  int tempStackSize = 0;

  int tempVariableFlag = 1;
  int tempVariableFlagHelper = 1;

  char lhsIdentifier[100];

  int arrayIndexFlag = 1;
  char arrayIndexLhs[100];
  int arrayIndexRhs;
  int arrayLhsFlag = 0;

  int tempVariableStartList[100];
  int tempVariableStartListLength = 0;
  int tempVariableStart = 0;

  int negativeTempFlag = 0;

  typedef struct ReadingIdentifier {
    char name[100];
    char index[100];
    char arrayIdentifierIndexes[100][100];
    int arrayIdentifierIndexesLength;
  } ReadingIdentifier;

  ReadingIdentifier readingIdentifiers[100];
  int readingIdentifiersLength = 0;
  int readingFlag = 0;
  int readingArrayFlag = 0;
  char readingIdentifier[100];
  int readingIdentifierArrayCount = 0;

  Type currentType;
%}

%token PROGRAM CONST IDENTIFIER VAR ARRAY RANGE INTNUMBER REALNUMBER OF 
       FUNCTION PROCEDURE BEGINTOK ENDTOK ASSIGN IF THEN ELSE WHILE DO
       RELOPLT RELOPLEQ RELOPEQ RELOPNEQ RELOPGEQ RELOPGT INTEGER REAL
       AND OR NOT DIV MOD SKIP READLN WRITELN

%left '+' '-'
%left '*' '/' DIV MOD
%left OR
%left AND
%left NOT

%union {
  int ival;     /* used for passing int values from lexer to parser */
  double dval;  /* used for passing double values from lexer to parser */
  int basicType;
  char operator;
  /* add here anything you may need */
  /*....*/
}

%type <basicType> BasicType NumericValue IdentifierList TypeSpec ArithExpr ArithExprList Lhs
%type <operator> Relop


%%

program            : PROGRAM IDENTIFIER ';' {fprintf(output, "#include <stdio.h>\n\n");}
                     ConstDecl
                     VarDecl
                     FuncProcDecl
                     {fprintf(output, "int main(int argc, char *argv[]) {\n");} CompoundStatement {fprintf(output, "return 0;\n}\n");}
                     '.'
                   ;

ConstDecl          : ConstDecl CONST IDENTIFIER {addIndex();} RELOPEQ NumericValue {generateConstants($6); addIdentifierData($6 + 3, -1);} ';'
                   | %empty
                   ;

NumericValue       : INTNUMBER {$$ = 0;}
                   | REALNUMBER {$$ = 1;}
                   ;

VarDecl            : VarDecl VAR IdentifierList ':' TypeSpec ';'
                   | %empty
                   ;

IdentifierList     : IDENTIFIER {addIndex();} {$$ = 1;}
                   | IdentifierList ',' IDENTIFIER {addIndex();} {$$ = $1 + 1;}
                   ;

TypeSpec           : BasicType {if (generateVariablesFlag == 1) {generateVariables($1);}; addIdentifierData($1, -1);} {$$ = $1;}
                   | ARRAY '[' INTNUMBER {startRange = atoi(yytext);} RANGE INTNUMBER {endRange = atoi(yytext);} ']' OF BasicType {addArrayData(ARRAY_TYPE, $10, startRange, endRange); generationCount = count; count = 0; if (generateVariablesFlag) {generateArray($10);}; generationCount = 0;} {$$ = 5;}
                   ;

BasicType          : INTEGER {$$ = 0;}
                   | REAL {$$ = 1;}
                   ;

FuncProcDecl       : FuncProcDecl SubProgDecl ';'
                   | %empty
                   ;

SubProgDecl        : SubProgHeading VarDecl CompoundStatement {fprintf(output, "}\n\n"); popSymbolTableList();}
                   ;

SubProgHeading     : FUNCTION IDENTIFIER {prepareFunction(); generateVariablesFlag = 0;} Parameters ':' BasicType ';' {generateFunction($6); addFunctionData($6, -1); generateVariablesFlag = 1;}
                   | PROCEDURE IDENTIFIER {prepareFunction(); generateVariablesFlag = 0;} PossibleParameters ';' {generateFunction(2); addFunctionData(VOID_DATA_TYPE, -1); generateVariablesFlag = 1;}
                   ;

PossibleParameters : Parameters
                   | %empty
                   ;

Parameters         : '(' ParameterList ')'
                   ;

ParameterList      : ParamList
                   | ParameterList ';' ParamList
                   ;

ParamList          : VAR IdentifierList {paramCount = $2; generationParamCount = count;} ':' TypeSpec {updateParamList($5, -1, 1);}
                   | IdentifierList {paramCount = $1; generationParamCount = count;} ':' TypeSpec {updateParamList($4, -1, 0);}
                   ;                   

CompoundStatement  : BEGINTOK OptionalStatements ENDTOK
                   ;

OptionalStatements : StatementList
                   | %empty
                   ;

StatementList      : Statement
                   | StatementList ';' Statement
                   ;

Statement          : Lhs ASSIGN ArithExpr {checkAssignment($1, $3); generateAssignment(); tempVariableFlagHelper = 1; arrayLhsFlag = 0;}
                   | SKIP
                   | ProcedureCall
                   | CompoundStatement
                   | IF Guard {fprintf(output, "if (!_t%d) goto lbl%d;\n", tempStack[tempStackSize - 1].count, labelCount); labelCount++;} THEN Statement {fprintf(output, "goto lbl%d;\n", labelCount); labelStack[labelStackLength] = labelCount; labelStackLength++;} ELSE {fprintf(output, "lbl%d : ;\n", labelCount - 1); labelCount++;} Statement {fprintf(output, "lbl%d : ;\n", labelStack[labelStackLength - 1]); labelStackLength--;}
                   | WHILE {fprintf(output, "lbl%d : ;\n", labelCount); labelStack[labelStackLength] = labelCount; labelStackLength++; labelCount++;} Guard {fprintf(output, "if (!_t%d) goto lbl%d;\n", tempStack[tempStackSize - 1].count, labelCount); labelStack[labelStackLength] = labelCount; labelStackLength++; labelCount++;} DO Statement {fprintf(output, "goto lbl%d;\n", labelStack[labelStackLength - 2]); fprintf(output, "lbl%d : ;\n", labelStack[labelStackLength - 1]); labelStackLength -= 2; labelCount++;}
                   ;

LhsList            : Lhs {readingIdentifiersLength++;}
                   | LhsList ',' Lhs {readingIdentifiersLength++;}

Lhs                : IDENTIFIER {arrayLhsFlag = 0; checkUndeclaredIdentifier(0); checkLhsAssignment(); strcpy(lhsIdentifier, identifier); addReadingIdentifierToList(); $$ = getIdentifierReturnDataType();}
                   | IDENTIFIER {arrayLhsFlag = 1; arrayIndexFlag = 0; checkUndeclaredIdentifier(0); strcpy(lhsIdentifier, identifier); strcpy(arrayIdentifier, identifier); lhsArrayFlag = 1; checkLhsAssignment(); readingArrayFlag = 1; strcpy(readingIdentifier, identifier); addArrayIdentifierToList(); addReadingIdentifierToList(); readingArrayFlag = 0;} '[' ArithExpr ']' {arrayIndexFlag = 1; tempVariableFlag = 1; lhsArrayFlag = 0; checkUndeclaredIdentifier(1); checkArrayIndex($4); generateTempVariableArrayReading(); $$ = getArrayReturnDataType(arrayIdentifier);}
                   ;

ProcedureCall      : IDENTIFIER {checkUndeclaredIdentifier(0); checkIfFunction();}
                   | IDENTIFIER {checkUndeclaredIdentifier(0); addFunctionIdentifierToList();} '(' {passedParamsFlag = 1; isVar = 1; addTempVariableStartToList();} ArithExprList ')' {tempVariableFlag = 1; tempVariableFlagHelper = 1; passedParamsFlag = 0; functionIdentifierIndexesLength--; generateTempVariable(getFunctionReturnDataType(identifier), 3); checkFunctionParameters();}
                   | READLN '(' {readingFlag = 1;} LhsList ')' {readingFlag = 0; fprintf(output, "scanf(\""); generateReadingIdentifiers(); tempVariableFlagHelper = 1;}
                   | WRITELN '(' {tempVariableStart = tempStackSize;} ArithExprList ')' {tempVariableFlagHelper = 1; generateWriting();}
                   ;

Guard              : BoolAtom
                   | NOT Guard {generateTempVariableExpression('!');}
                   | Guard OR Guard {generateTempVariableExpression('|');}
                   | Guard AND Guard {generateTempVariableExpression('&');}
                   | '(' Guard ')'
                   ;

BoolAtom           : ArithExpr Relop ArithExpr {checkBoolAtom($1, $3); generateTempVariableExpression($2);}
                   ;

Relop              : RELOPLT {$$ = '0';}
                   | RELOPLEQ {$$ = '1';}
                   | RELOPEQ {$$ = '2';}
                   | RELOPNEQ {$$ = '3';}
                   | RELOPGEQ {$$ = '4';}
                   | RELOPGT {$$ = '5';}
                   ;

ArithExprList      : ArithExpr {addPassedParam($1);}
                   | ArithExprList ',' ArithExpr {addPassedParam($3);}
                   ;

ArithExpr          : IDENTIFIER {checkUndeclaredIdentifier(1); checkIfFunction(); generateTempVariable(getIdentifierReturnDataType(), 1); getArrayIndexIdentifier(); $$ = getIdentifierReturnDataType();}
                   | IdentifierLogic '[' ArithExpr ']' {tempVariableFlag = 1; arrayIndexFlag = 1; checkArrayIndex($3); generateTempVariableArray(); $$ = getArrayReturnDataType(arrayIdentifier);}
                   | IdentifierLogic '[' ArithExpr RANGE ArithExpr ']' {tempVariableFlag = 1; checkArrayRange($3, $5); isVar = isVarSwitch; $$ = ARRAY_TYPE;}
                   | IDENTIFIER {checkUndeclaredIdentifier(1); addFunctionIdentifierToList();} '(' {passedParamsFlag = 1; isVar = 1; addTempVariableStartToList();} ArithExprList ')' {functionIdentifierIndexesLength--; if (functionIdentifierIndexesLength == 0) {passedParamsFlag = 0;} checkFunctionParameters(); tempVariableFlagHelper = 1; generateTempVariable(getFunctionReturnDataType(), 3); symbolTableList[0][functionIdentifierIndexes[functionIdentifierIndexesLength]].passedParamListLength = 0; $$ = getFunctionReturnDataType();}
                   | INTNUMBER {$$ = 0; strcpy(currentIndex, yytext); getArrayIndex(); generateTempVariable(0, 0); if (passedParamsFlag == 1) {isVar = 0;}}
                   | REALNUMBER {$$ = 1; generateTempVariable(1, 0); if (passedParamsFlag == 1) {isVar = 0;}}
                   | ArithExpr '+' ArithExpr {if (passedParamsFlag == 1) {isVar = 0;}; checkBinaryArithTypes($1, $3); generateTempVariableExpression('+'); $$ = resolveArithExpr($1, $3);}
                   | ArithExpr '-' ArithExpr {if (passedParamsFlag == 1) {isVar = 0;}; checkBinaryArithTypes($1, $3); generateTempVariableExpression('-'); $$ = resolveArithExpr($1, $3);}
                   | ArithExpr '*' ArithExpr {if (passedParamsFlag == 1) {isVar = 0;}; checkBinaryArithTypes($1, $3); generateTempVariableExpression('*'); $$ = resolveArithExpr($1, $3);}
                   | ArithExpr '/' ArithExpr {if (passedParamsFlag == 1) {isVar = 0;}; checkBinaryArithTypes($1, $3); generateTempVariableExpression('/'); $$ = 1;}
                   | ArithExpr DIV ArithExpr {if (passedParamsFlag == 1) {isVar = 0;}; checkDivModArithTypes($1, $3); generateTempVariableExpression('d'); $$ = 0;}
                   | ArithExpr MOD ArithExpr {if (passedParamsFlag == 1) {isVar = 0;}; checkDivModArithTypes($1, $3); generateTempVariableExpression('m'); $$ = 0;}
                   | '-' {negativeTempFlag = 1;} ArithExpr {if (passedParamsFlag == 1) {isVar = 0;}; checkNegation($3); $$ = $3;}
                   | '(' ArithExpr ')' {$$ = $2;}
                   ;
IdentifierLogic    : IDENTIFIER {readingArrayFlag = 1; checkUndeclaredIdentifier(1); strcpy(arrayIdentifier, identifier); isVarSwitch = isVar; addArrayIdentifierToList(); addReadingIdentifierToList(); readingArrayFlag = 0;}
                   ;

%%

void generateConstants(int type) {
  fprintf(output, "const ");

  if (type == 0) {
    fprintf(output, "int ");
  } else if (type == 1) {
    fprintf(output, "double ");
  }

  fprintf(output, "%s = %s;\n\n", getString(indexes[0]), yytext);
  
  return;
}

void generateVariables(int type) {
  if (type == 0) {
    fprintf(output, "int ");
  } else if (type == 1) {
    fprintf(output, "double ");
  }

  for (int i = 0; i < count; i++) {
    if (i < count - 1) {
      fprintf(output, "%s, ", getString(indexes[i]));
    } else {
      fprintf(output, "%s;\n\n", getString(indexes[i]));
    }
  }
}

void generateArray(int type) {
  if (type == 0) {
    fprintf(output, "int ");
  } else if (type == 1) {
    fprintf(output, "double ");
  }

  for (int i = 0; i < generationCount; i++) {
    int size = symbolTableList[currentScope][indexes[i]].endRange - symbolTableList[currentScope][indexes[i]].startRange + 1;

    if (i < generationCount - 1) {
      fprintf(output, "%s[%d], ", getString(indexes[i]), size);
    } else {
      fprintf(output, "%s[%d];\n\n", getString(indexes[i]), size);
    }
  }
}

void generateFunction(int type) {
  if (type == 0) {
    fprintf(output, "int ");
  } else if (type == 1) {
    fprintf(output, "double ");
  } else if (type == 2) {
    fprintf(output, "void ");
  }

  fprintf(output, "%s(", functionIdentifier);

  for (int i = 0; i < paramLength; i++) {
    if (paramList[i].type == 0) {
      if (i < paramLength - 1) {
        fprintf(output, "int %s, ", paramList[i].name);
      } else {
        fprintf(output, "int %s", paramList[i].name);
      }
    } else if (paramList[i].type == 1) {
      if (i < paramLength - 1) {
        fprintf(output, "double %s, ", paramList[i].name);
      } else {
        fprintf(output, "double %s", paramList[i].name);
      }
    } else if (paramList[i].type == 5) {
      int idx = lookupStringTable(paramList[i].name);

      int size = symbolTableList[currentScope][idx].endRange - symbolTableList[currentScope][idx].startRange + 1;

      if (symbolTableList[currentScope][idx].dataType == 0) {
        if (i < paramLength - 1) {
          fprintf(output, "int %s[%d], ", paramList[i].name, size);
        } else {
          fprintf(output, "int %s[%d]", paramList[i].name, size);
        }
      } else  {
          if (i < paramLength - 1) {
          fprintf(output, "double %s[%d], ", paramList[i].name, size);
        } else {
          fprintf(output, "double %s[%d]", paramList[i].name, size);
        }
      }
    }
  }

  fprintf(output, ") {\n");
}

void generateTempVariable(int type, int identifierCheck) {
  if (tempVariableFlag && tempVariableFlagHelper && inArray == 0) {
    char dataType[10];
    int isArr = 0;

    if (type == 0) {
      strcpy(dataType, "int");
    } else if (type == 1) {
      strcpy(dataType, "double");
    } else if (type == 3) {
      strcpy(dataType, "int");
    } else if (type == 4) {
      strcpy(dataType, "double");
    } else if (type == 5) {
      isArr = 1;

      int idx = lookupStringTable(identifier);

      Identifier id;

      if (symbolTableList[currentScope][idx].created == 1) {
        id = symbolTableList[currentScope][idx];
      } else {
        id = symbolTableList[currentScope - 1][idx];
      }

      if (id.dataType == 0) {
        strcpy(dataType, "int");
      } else if (id.dataType == 1) {
        strcpy(dataType, "double");
      }
    } 

    if (identifierCheck == 1) {
      if (type == 5) {
        fprintf(output, "%s *_t%d = %s;\n", dataType, tempVariableCount, identifier);
      } else {
        if (negativeTempFlag) {
          fprintf(output, "%s _t%d = -%s;\n", dataType, tempVariableCount, identifier);
          negativeTempFlag = 0;
        } else {
          fprintf(output, "%s _t%d = %s;\n", dataType, tempVariableCount, identifier);
        }
      }
    } else if (identifierCheck == 0){
      if (negativeTempFlag) {
        fprintf(output, "%s _t%d = -%s;\n", dataType, tempVariableCount, yytext);
        negativeTempFlag = 0;
      } else {
        fprintf(output, "%s _t%d = %s;\n", dataType, tempVariableCount, yytext);
      }
    } else if (identifierCheck == 3) {
      int idxFunction = functionIdentifierIndexes[functionIdentifierIndexesLength];

      Identifier function;

      if (currentScope == 0) {
        function = symbolTableList[0][idxFunction];
      } else {
        if (symbolTableList[currentScope][idxFunction].created == 1) {
          function = symbolTableList[currentScope][idxFunction];
        } else {
          function = symbolTableList[0][idxFunction];
        }
      }

      if (type == 2) {
        fprintf(output, "%s(", function.name);
      } else {
        fprintf(output, "%s _t%d = %s(", dataType, tempVariableCount, function.name);
      }

      int count = 0;

      int start = tempStack[tempVariableStartList[tempVariableStartListLength - 1]].count;
      int index = tempVariableStartList[tempVariableStartListLength - 1];

      while (index < tempStackSize) {
        if (index < tempStackSize - 1) {
          fprintf(output, "_t%d, ", start);
        } else {
          fprintf(output, "_t%d);\n", start);
        }
        index++;
        start = tempStack[index].count;
        count++;
      }

      tempStackSize -= count;

      tempVariableStartListLength--;
    }

    tempStack[tempStackSize].count = tempVariableCount;
    tempStack[tempStackSize].type = type;
    tempStack[tempStackSize].isArr = isArr;
    tempStackSize++;
    tempVariableCount++;
  }
}

void generateTempVariableArrayReading() {
  if (readingFlag) {
    int type = getArrayReturnDataType(arrayIdentifierIndexes[arrayIdentifierIndexesLength - 1]);
    int idx = lookupStringTable(arrayIdentifierIndexes[arrayIdentifierIndexesLength - 1]);

    Identifier id;

    if (symbolTableList[currentScope][idx].created == 1) {
      id = symbolTableList[currentScope][idx];
    } else {
      id = symbolTableList[currentScope - 1][idx];
    }

    fprintf(output, "int _t%d = _t%d - %d;\n", tempVariableCount, tempVariableCount - 1, id.startRange);
    tempVariableCount++;
    tempStackSize--;

    if (type == 0) {
      fprintf(output, "int *_t%d = %s;\n", tempVariableCount, arrayIdentifierIndexes[arrayIdentifierIndexesLength - 1]);
      tempVariableCount++;

      fprintf(output, "int *_t%d = _t%d + _t%d;\n", tempVariableCount, tempVariableCount - 2, tempVariableCount - 1);
      tempVariableCount++;

    } else {
      fprintf(output, "double *_t%d = %s;\n", tempVariableCount, arrayIdentifierIndexes[arrayIdentifierIndexesLength - 1]);
      tempVariableCount++;

      fprintf(output, "double *_t%d = _t%d + _t%d;\n", tempVariableCount, tempVariableCount - 2, tempVariableCount - 1);
      tempVariableCount++;
    }

    tempStack[tempStackSize].count = tempVariableCount - 1;
    tempStack[tempStackSize].type = type;
    tempStack[tempStackSize].isArr = 1;
    tempStackSize++;

    arrayIdentifierIndexesLength--;
    readingIdentifierArrayCount++;
  }
}

void generateTempVariableArray() {
  int type = getArrayReturnDataType(arrayIdentifierIndexes[arrayIdentifierIndexesLength - 1]);
  int idx = lookupStringTable(arrayIdentifierIndexes[arrayIdentifierIndexesLength - 1]);
  
  Identifier id;

  if (symbolTableList[currentScope][idx].created == 1) {
    id = symbolTableList[currentScope][idx];
  } else {
    id = symbolTableList[currentScope - 1][idx];
  }

  fprintf(output, "int _t%d = _t%d - %d;\n", tempVariableCount, tempVariableCount - 1, id.startRange);
  tempVariableCount++;
  tempStackSize--;

  if (type == 0) {
    fprintf(output, "int *_t%d = %s;\n", tempVariableCount, arrayIdentifierIndexes[arrayIdentifierIndexesLength - 1]);
    tempVariableCount++;

    fprintf(output, "int *_t%d = _t%d + _t%d;\n", tempVariableCount, tempVariableCount - 2, tempVariableCount - 1);
    tempVariableCount++;

    fprintf(output, "int _t%d = *_t%d;\n", tempVariableCount, tempVariableCount - 1);
    tempVariableCount++;
  } else {
    fprintf(output, "double *_t%d = %s;\n", tempVariableCount, arrayIdentifierIndexes[arrayIdentifierIndexesLength - 1]);
    tempVariableCount++;

    fprintf(output, "double *_t%d = _t%d + _t%d;\n", tempVariableCount, tempVariableCount - 2, tempVariableCount - 1);
    tempVariableCount++;

    fprintf(output, "double _t%d = *_t%d;\n", tempVariableCount, tempVariableCount - 1);
    tempVariableCount++;
  }

  tempStack[tempStackSize].count = tempVariableCount - 1;
  tempStack[tempStackSize].type = type;
  tempStack[tempStackSize].isArr = 1;
  tempStackSize++;

  arrayIdentifierIndexesLength--;
}

void generateTempVariableRelop(char operator, int type) {
  if (operator == '|') {
    fprintf(output, "int _t%d = _t%d || _t%d;\n", tempVariableCount, tempStack[tempStackSize - 2].count, tempStack[tempStackSize - 1].count);
  } else if (operator == '&') {
    fprintf(output, "int _t%d = _t%d && _t%d;\n", tempVariableCount, tempStack[tempStackSize - 2].count, tempStack[tempStackSize - 1].count);
  } else if (operator == '0') {
    fprintf(output, "int _t%d = _t%d < _t%d;\n", tempVariableCount, tempStack[tempStackSize - 2].count, tempStack[tempStackSize - 1].count);
  } else if (operator == '1') {
    fprintf(output, "int _t%d = _t%d <= _t%d;\n", tempVariableCount, tempStack[tempStackSize - 2].count, tempStack[tempStackSize - 1].count);
  } else if (operator == '2') {
    fprintf(output, "int _t%d = _t%d == _t%d;\n", tempVariableCount, tempStack[tempStackSize - 2].count, tempStack[tempStackSize - 1].count);
  } else if (operator == '3') {
    fprintf(output, "int _t%d = _t%d != _t%d;\n", tempVariableCount, tempStack[tempStackSize - 2].count, tempStack[tempStackSize - 1].count);
  } else if (operator == '4') {
    fprintf(output, "int _t%d = _t%d >= _t%d;\n", tempVariableCount, tempStack[tempStackSize - 2].count, tempStack[tempStackSize - 1].count);
  } else if (operator == '5') {
    fprintf(output, "int _t%d = _t%d > _t%d;\n", tempVariableCount, tempStack[tempStackSize - 2].count, tempStack[tempStackSize - 1].count);
  } else if (operator == '!') {
    fprintf(output, "int _t%d = !_t%d;\n", tempVariableCount, tempStack[tempStackSize - 1].count);
    tempStackSize++;
  } else {
    if (type == 0) {
      fprintf(output, "int _t%d = _t%d %c _t%d;\n", tempVariableCount, tempStack[tempStackSize - 2].count, operator, tempStack[tempStackSize - 1].count);
    } else {
      fprintf(output, "double _t%d = _t%d %c _t%d;\n", tempVariableCount, tempStack[tempStackSize - 2].count, operator, tempStack[tempStackSize - 1].count);
    }
  }
}

void generateTempVariableExpression(char operator) {
  if (tempVariableFlag && tempVariableFlagHelper) {
    int type;

    if (tempStack[tempStackSize - 2].type == 1 || tempStack[tempStackSize - 1].type == 1) {
      type = 1;
    } else {
      type = 0;
    }

    if (type == 0) {
      if (operator == 'd') {
        fprintf(output, "int _t%d = _t%d / _t%d;\n", tempVariableCount, tempStack[tempStackSize - 2].count, tempStack[tempStackSize - 1].count);
      } else if (operator == 'm') {
        fprintf(output, "int _t%d = _t%d %% _t%d;\n", tempVariableCount, tempStack[tempStackSize - 2].count, tempStack[tempStackSize - 1].count);
      } else if (operator == '/') {
        type = 1;
        fprintf(output, "double _t%d = (double) _t%d %c _t%d;\n", tempVariableCount, tempStack[tempStackSize - 2].count, operator, tempStack[tempStackSize - 1].count);
      } else {
        generateTempVariableRelop(operator, 0);
      }
    } else {
      if (operator == 'd') {
        type = 0;
        fprintf(output, "int _t%d = _t%d / _t%d;\n", tempVariableCount, tempStack[tempStackSize - 2].count, tempStack[tempStackSize - 1].count);
      } else if (operator == 'm') {
        type = 0;
        fprintf(output, "int _t%d = _t%d %% _t%d;\n", tempVariableCount, tempStack[tempStackSize - 2].count, tempStack[tempStackSize - 1].count);
      } else if (operator == '/') {
        fprintf(output, "double _t%d = (double) _t%d %c _t%d;\n", tempVariableCount, tempStack[tempStackSize - 2].count, operator, tempStack[tempStackSize - 1].count);
      } else {
        generateTempVariableRelop(operator, 1);
      }
    }

    tempStackSize -= 2;
    tempStack[tempStackSize].count = tempVariableCount;
    tempStack[tempStackSize].type = type;
    tempStack[tempStackSize].isArr = 0;
    tempStackSize++;
    tempVariableCount++;
  };
}

void generateAssignment() {
  int idx = lookupStringTable(lhsIdentifier);

  Identifier id;
      
  if (symbolTableList[currentScope][idx].created == 1) {
    id = symbolTableList[currentScope][idx];
  } else {
    id = symbolTableList[currentScope - 1][idx];
  }

  if (arrayLhsFlag) {
    fprintf(output, "int _t%d = _t%d - %d;\n", tempVariableCount, tempStack[tempStackSize - 2].count, id.startRange);
    tempVariableCount++;

    if (id.dataType == 0) {
      fprintf(output, "int *_t%d = %s;\n", tempVariableCount, lhsIdentifier);
      tempVariableCount++;

      fprintf(output, "int *_t%d = _t%d + _t%d;\n", tempVariableCount, tempVariableCount - 2, tempVariableCount - 1);
      fprintf(output, "*_t%d = _t%d;\n", tempVariableCount, tempVariableCount - 3);
      tempVariableCount++;

    } else {
      fprintf(output, "double *_t%d = %s;\n", tempVariableCount, lhsIdentifier);
      tempVariableCount++;

      fprintf(output, "double *_t%d = _t%d + _t%d;\n", tempVariableCount, tempVariableCount - 2, tempVariableCount - 1);
      fprintf(output, "*_t%d = _t%d;\n", tempVariableCount, tempVariableCount - 3);
      tempVariableCount++;
    }
  } else {
    if (id.isFunction == 1) {
      fprintf(output, "return _t%d;\n", tempVariableCount - 1);
    } else {
      fprintf(output, "%s = _t%d;\n", lhsIdentifier, tempVariableCount - 1);
    }
  }
}

void getArrayIndex() {
  if (arrayIndexFlag == 0) {
    strcpy(arrayIndexLhs, yytext);
    if (readingFlag) {
      strcpy(readingIdentifiers[readingIdentifiersLength].index, yytext);
    }
  } else {
    arrayIndexRhs = atoi(yytext);
    if (readingFlag) {
      strcpy(readingIdentifiers[readingIdentifiersLength - 1].index, yytext);
    }
  }
}

void getArrayIndexIdentifier() {
  if (arrayIndexFlag == 0) {
    strcpy(arrayIndexLhs, identifier);
    if (readingFlag) {
      strcpy(readingIdentifiers[readingIdentifiersLength].index, yytext);
    }
  } else {
    arrayIndexRhs = atoi(yytext);
    if (readingFlag) {
      strcpy(readingIdentifiers[readingIdentifiersLength - 1].index, yytext);
    }
  }
}

void addTempVariableStartToList() {
  tempVariableStartList[tempVariableStartListLength] = tempStackSize;
  tempVariableStartListLength++;
}

void addReadingIdentifierToList() {
  if (readingFlag) {
    if (readingArrayFlag == 1) {
      strcpy(readingIdentifiers[readingIdentifiersLength].arrayIdentifierIndexes[readingIdentifiers[readingIdentifiersLength].arrayIdentifierIndexesLength], identifier);
      readingIdentifiers[readingIdentifiersLength].arrayIdentifierIndexesLength++;

      strcpy(readingIdentifiers[readingIdentifiersLength].name, readingIdentifier);

      strcpy(readingIdentifiers[readingIdentifiersLength].index, currentIndex);
    } else {
      strcpy(readingIdentifiers[readingIdentifiersLength].name, identifier);

      strcpy(readingIdentifiers[readingIdentifiersLength].index, "-1");
    }
  }
}

void generateReadingIdentifiers() {
  int count = readingIdentifierArrayCount;

  for (int i = readingIdentifiersLength; i > 0; i--) {
    int idx = lookupStringTable(readingIdentifiers[-(i - readingIdentifiersLength)].name);

    Identifier id;
      
    if (symbolTableList[currentScope][idx].created == 1) {
      id = symbolTableList[currentScope][idx];
    } else {
      id = symbolTableList[currentScope - 1][idx];
    }

    TempVariable tempVariable;

    if (id.type != 5) {
      tempVariable.type = id.type;
    } else {
      tempVariable = tempStack[tempStackSize - count];
      count--;
    }
    
    if (i > 1) {
      if (tempVariable.type == 0) {
        fprintf(output, "%%d ");
      } else if (tempVariable.type == 1) {
        fprintf(output, "%%lf ");
      }
    } else {
      if (tempVariable.type == 0) {
        fprintf(output, "%%d\", ");
      } else if (tempVariable.type == 1) {
        fprintf(output, "%%lf\", ");
      }
    }
  }

  count = readingIdentifierArrayCount;

  for (int i = readingIdentifiersLength; i > 0; i--) {
    int idx = lookupStringTable(readingIdentifiers[-(i - readingIdentifiersLength)].name);

    Identifier id;
      
    if (symbolTableList[currentScope][idx].created == 1) {
      id = symbolTableList[currentScope][idx];
    } else {
      id = symbolTableList[currentScope - 1][idx];
    }

    TempVariable tempVariable;

    if (id.type != 5) {
      tempVariable.isArr = 0;
    } else {
      tempVariable = tempStack[tempStackSize - count];
      count--;
    }

    if (i > 1) {
      if (tempVariable.isArr == 1) {
        fprintf(output, "_t%d, ", tempVariable.count);
      } else {
        fprintf(output, "&%s, ", readingIdentifiers[-(i - readingIdentifiersLength)].name);
      }
    } else {
      if (tempVariable.isArr == 1) {
        fprintf(output, "_t%d);\n", tempVariable.count);
      } else {
        fprintf(output, "&%s);\n", readingIdentifiers[-(i - readingIdentifiersLength)].name);
      }
    }
  }

  readingIdentifiersLength = 0;
  readingIdentifierArrayCount = 0;
}

void generateWriting() {
  fprintf(output, "printf(\"");
  int index = tempVariableStart;

  while (index != tempStackSize) {
    if (index < tempStackSize - 1) {
      if (tempStack[index].type == 0) {
        fprintf(output, "%%d ");
      } else if (tempStack[index].type == 1) {
        fprintf(output, "%%lf ");
      } else if (tempStack[index].type == 3) {
        fprintf(output, "%%d ");
      } else if (tempStack[index].type == 4) {
        fprintf(output, "%%lf ");
      }
    } else {
      if (tempStack[index].type == 0) {
        fprintf(output, "%%d\\n\", ");
      } else if (tempStack[index].type == 1) {
        fprintf(output, "%%lf\\n\", ");
      } else if (tempStack[index].type == 3) {
        fprintf(output, "%%d\\n\", ");
      } else if (tempStack[index].type == 4) {
        fprintf(output, "%%lf\\n\", ");
      }
    }

    index++;
  }

  index = tempVariableStart;

  while (index != tempStackSize) {
    if (index < tempStackSize - 1) {
      fprintf(output, "_t%d, ", tempStack[index].count);
    } else {
      fprintf(output, "_t%d);\n", tempStack[index].count);
    }

    index++;
  }
}

void addIndex() {
  checkRedeclaredIdentifier();

  int idx = insertOrRetrieveStringTable(identifier);
  indexes[count] = idx;
  count++;
}

void checkRedeclaredIdentifier() {
  int idx = lookupStringTable(identifier);

  if (idx == -1) {
    return;
  }

  if (symbolTableList[currentScope][idx].created == 1) {
    yyerror("YOU CAN NOT DECLARE THE SAME IDENTIFIER TWICE");
  }
}

void addPassedParam(int type) {
  if (!passedParamsFlag) {
    return;
  }

  PassedParam passedParam;

  passedParam.type = type;
  passedParam.isVar = isVar;

  int idx = functionIdentifierIndexes[functionIdentifierIndexesLength - 1];

  symbolTableList[0][idx].passedParamList[symbolTableList[0][idx].passedParamListLength] = passedParam;
  symbolTableList[0][idx].passedParamListLength = symbolTableList[0][idx].passedParamListLength + 1;

  isVar = 1;
}

void addIdentifierData(int type, int dataType) {
  for (int i = 0; i < count; i++) {
    Identifier id;

    id.dataType = dataType;
    id.location = linenr;
    id.type = type;
    id.created = 1;
    id.isVar = 0;
    id.isFunction = 0;

    symbolTableList[currentScope][indexes[i]] = id;
  }

  count = 0;
}

void addArrayData(int type, int dataType, int startRange, int endRange) {
  for (int i = 0; i < count; i++) {
    Identifier id;

    id.dataType = dataType;
    id.location = linenr;
    id.type = type;
    id.created = 1;
    id.startRange = startRange;
    id.endRange = endRange;
    id.isVar = 0;
    id.isFunction = 0;

    symbolTableList[currentScope][indexes[i]] = id;
  }
}

void prepareFunction() {
  strcpy(functionIdentifier, identifier);
  addIndex();
  currentScope++;
  count = 0;
}

void addFunctionIdentifierToList() {
  int idx = lookupStringTable(identifier);
  functionIdentifierIndexes[functionIdentifierIndexesLength] = idx;
  functionIdentifierIndexesLength++;
}

void addArrayIdentifierToList() {
  strcpy(arrayIdentifierIndexes[arrayIdentifierIndexesLength], identifier);
  arrayIdentifierIndexesLength++;
}

void addFunctionData(int type, int dataType) {
  int idx = insertOrRetrieveStringTable(functionIdentifier);

  Identifier id;

  id.dataType = dataType;
  id.location = linenr;
  id.type = type;
  id.created = 1;
  id.isVar = 0;

  if (type == VOID_DATA_TYPE) {
    id.isFunction = 0;
  } else {
    id.isFunction = 1;
  }

  id.params = malloc(paramLength * sizeof(Identifier));

  for (int i = 0; i < paramLength; i++) {
    id.params[i] = paramList[i];
  }

  id.paramsLength = paramLength;

  symbolTableList[currentScope - 1][idx] = id;

  strcpy(symbolTableList[currentScope - 1][idx].name, functionIdentifier);

  paramLength = 0;
  paramCount = 0;
  count = 0;
}

void updateParamList(int type, int dataType, int isVar) {
  for (int i = 0; i < paramCount; i++) {
    Identifier id;

    id.dataType = dataType;
    id.type = type;
    id.created = 1;
    id.location = linenr;
    id.isVar = isVar;
    strcpy(id.name, getString(indexes[i]));

    paramList[paramLength] = id;
    paramLength++;
  }
}

void popSymbolTableList() {
  free(symbolTableList[currentScope]);
  symbolTableList[currentScope] = malloc(100 * sizeof(Identifier));

  for (int i = 0; i < 100; i++) {
    symbolTableList[currentScope][i].created = 0;
    symbolTableList[currentScope][i].passedParamListLength = 0;
  }

  currentScope--;
}

void checkUndeclaredIdentifier(int rhsFlag) {
  int idx = lookupStringTable(identifier);

  if (idx == -1) {
    yyerror("UDECLARED IDENTIFIER");
  }

  if (symbolTableList[currentScope][idx].created == 1) {
    if (!rhsFlag) {
      checkRedeclaredConstant(currentScope, idx);
    }

    return;
  }

  if (currentScope - 1 < 0) {
    yyerror("UDECLARED IDENTIFIER");
  }

  if (symbolTableList[currentScope - 1][idx].created == 1) {
    if (!rhsFlag) {
      checkRedeclaredConstant(currentScope - 1, idx);
    }

    return;
  }

  yyerror("UDECLARED IDENTIFIER");
}

void checkRedeclaredConstant(int scope, int idx) {
  Type type = symbolTableList[scope][idx].type;

  if (type == CONST_INT_TYPE || type == CONST_REAL_TYPE) {
    yyerror("CONSTANTS CAN NOT BE REDECLARED");
  }
}

void checkFunctionParameters() {
  int idxFunction = functionIdentifierIndexes[functionIdentifierIndexesLength];

  Identifier function;

  if (currentScope == 0) {
    function = symbolTableList[0][idxFunction];
  } else {
    if (symbolTableList[currentScope][idxFunction].created == 1) {
      function = symbolTableList[currentScope][idxFunction];
    } else {
      function = symbolTableList[0][idxFunction];
    }
  }

  if (function.isFunction == 0 && function.type != 2) {
    yyerror("USING AN IDENTIFIER AS A FUNCTION WHEN IT IS NOT");
  }

  for (int i = 0; i < function.paramsLength; i++) {
    if (!((function.params[i].type == 0 && (function.passedParamList[i].type == 0 || function.passedParamList[i].type == 3)) || (function.params[i].type == 1 && (function.passedParamList[i].type == 1 || function.passedParamList[i].type == 4)) || (function.params[i].type == 1 && function.passedParamList[i].type == 0 || function.passedParamList[i].type == 3) || (function.params[i].type == 5 && function.passedParamList[i].type == 5))) {
      yyerror("INVALID PARAMETER TYPES");
    }

    if (function.params[i].isVar == 1 && (function.passedParamList[i].type == 3 || function.passedParamList[i].type == 4)) {
      yyerror("CONSTS CAN NOT BE PASSED BY REFERENCE");
    }

    if (function.params[i].isVar == 1 && function.params[i].isVar != function.passedParamList[i].isVar) {
      showStringTable();
      yyerror("PARAMETER HAS TO BE A VARIABLE");
    }

    if (function.params[i].isVar == 1 && function.params[i].isVar == function.passedParamList[i].isVar && (function.params[i].type == 1 && function.passedParamList[i].type == 0)) {
      yyerror("INVALID PARAMETER TYPES");
    }
  }
}

int getArrayReturnDataType(char *arrayIdentifier) {
  int idx = lookupStringTable(arrayIdentifier);

  isVar = 1;

  if (symbolTableList[currentScope][idx].created == 1) {
    return symbolTableList[currentScope][idx].dataType;
  }

  return symbolTableList[currentScope - 1][idx].dataType;
}

int getFunctionReturnDataType() {
  int idx = functionIdentifierIndexes[functionIdentifierIndexesLength];

  isVar = 0;

  return symbolTableList[0][idx].type;
}

int getIdentifierReturnDataType() {
  int idx = lookupStringTable(identifier);

  if (symbolTableList[currentScope][idx].created == 1) {
    return symbolTableList[currentScope][idx].type;
  }

  return symbolTableList[currentScope - 1][idx].type;
}

int resolveArithExpr(int expr1, int expr2) {
  if ((expr1 == 0 || expr1 == 3) && (expr2 == 1 || expr2 == 4)) {
    return 1;
  }

  if ((expr1 == 1 || expr1 == 4) && (expr2 == 0 || expr2 == 3)) {
    return 1;
  }

  if ((expr1 == 0 || expr1 == 3) && (expr2 == 0 || expr2 == 3)) {
    return 0;
  }

  if ((expr1 == 1 || expr1 == 4) && (expr2 == 1 || expr2 == 4)) {
    return 1;
  }

  yyerror("ARITHMETIC EXPRESSION WITH INCOMPATIBLE DATA TYPES");
}

void checkBinaryArithTypes(int expr1, int expr2) {
  if (expr1 != 0 && expr1 != 1 && expr1 != 3 && expr1 != 4) {
    yyerror("ARITHMETIC EXPRESSION WITH INCOMPATIBLE DATA TYPES");
  }

  if (expr2 != 0 && expr2 != 1 && expr2 != 3 && expr2 != 4) {
    yyerror("ARITHMETIC EXPRESSION WITH INCOMPATIBLE DATA TYPES");
  }
}

void checkDivModArithTypes(int expr1, int expr2) {
  if ((expr1 != 0 && expr1 != 3) || (expr2 != 0 && expr2 != 3)) {
    yyerror("ARITHMETIC EXPRESSION WITH INCOMPATIBLE DATA TYPES");
  }
}

void checkNegation(int expr) {
  if (expr != 0 && expr != 1 && expr != 3 && expr != 4) {
    yyerror("ARITHMETIC EXPRESSION WITH INCOMPATIBLE DATA TYPES");
  }
}

void checkIfFunction() {
  int idx = lookupStringTable(identifier);

  if (symbolTableList[currentScope][idx].created == 1) {
    if (symbolTableList[currentScope][idx].isFunction == 0) {
      return;
    }

    if (lhsArrayFlag) {
      yyerror("ARRAY INDEX MUST BE AN INTEGER");
    }

    yyerror("FUNCTION IS CALLED WITHOUT PARAMETERS");
  }

  if (symbolTableList[currentScope - 1][idx].created == 1) {
    if (symbolTableList[currentScope - 1][idx].isFunction == 0) {
      return;
    }

    if (lhsArrayFlag) {
      yyerror("ARRAY INDEX MUST BE AN INTEGER");
    }

    int idxFunction = lookupStringTable(functionIdentifier);

    if (idxFunction == idx) {
      return;
    }

    yyerror("FUNCTION IS CALLED WITHOUT PARAMETERS");
  }
}

void checkArrayIndex(int expr) {
  if (expr != 0 && expr != 3) {
    yyerror("ARRAY INDEX MUST BE AN INTEGER");
  }
}

void checkArrayRange(int expr1, int expr2) {
  if ((expr1 != 0 && expr1 != 3) || (expr2 != 0 && expr2 != 3)) {
    yyerror("ARRAY RANGE MUST CONSIST OF INTEGERS");
  }
}

void checkLhsAssignment() {
  int idx = lookupStringTable(identifier);

  if (symbolTableList[currentScope][idx].created == 1) {
    Identifier id = symbolTableList[currentScope][idx];

    if (id.isFunction == 1) {
      yyerror("VALUE CAN NOT BE ASSIGNED TO FUNCTIONS OUTSIDE OF THEIR SCOPE");
    }

    if (id.type == 2) {
      yyerror("VALUE CAN NOT BE ASSIGNED TO PROCEDURES");
    }

    return;
  }

  if (symbolTableList[currentScope - 1][idx].created == 1) {
    Identifier id = symbolTableList[currentScope - 1][idx];

    if (id.type == 2) {
      yyerror("VALUE CAN NOT BE ASSIGNED TO PROCEDURES");
    }

    int idxFunction = lookupStringTable(functionIdentifier);

    if (idxFunction != idx && id.isFunction == 1) {
      yyerror("VALUE CAN NOT BE ASSIGNED TO FUNCTIONS OUTSIDE OF THEIR SCOPE");
    }
  }
}

void checkAssignment(int expr1, int expr2) {
  if (expr1 == 1 && (expr2 == 0 || expr2 == 3)) {
    return;
  }

  if ((expr1 == 0 && expr2 == 3) || (expr1 == 1 && expr2 == 4)) {
    return;
  }

  if (expr1 == expr2) {
    if (expr1 == 5) {
      yyerror("ARRAYS CAN NOT BE ASSIGNED");
    }

    return;
  }

  yyerror("ASSIGNMENT WITH INCOMPATIBLE TYPES");
}

void checkBoolAtom(int expr1, int expr2) {
  if (expr1 != 0 && expr1 != 3 && expr1 != 1 && expr1 != 4) {
    yyerror("INCOMPATIBLE TYPES FOR COMPARISON");
  }

  if (expr2 != 0 && expr2 != 3 && expr2 != 1 && expr2 != 4) {
    yyerror("INCOMPATIBLE TYPES FOR COMPARISON");
  }
}

void printToken(int token, FILE *f) {
  /* single character tokens */
  if (token < 256) {
    if (token < 33) {
      /* non-printable character */
      fprintf(f, "chr(%d)", token);
    } else {
      fprintf(f, "'%c'", token);
    }
    return;
  }
  /* standard tokens (>255) */
  switch (token) {
    case PROGRAM   : fprintf(f, "PROGRAM"); break;
    case CONST     : fprintf(f, "CONST"); break;
    case IDENTIFIER: fprintf(f, "identifier<%s>", yytext); break;
    case VAR       : fprintf(f, "VAR"); break;
    case ARRAY     : fprintf(f, "ARRAY"); break;
    case RANGE     : fprintf(f, ".."); break;
    case INTNUMBER : fprintf(f, "Integer<%d>", yylval.ival); break;
    case REALNUMBER: fprintf(f, "Real<%lf>", yylval.dval); break;
    case OF        : fprintf(f, "OF"); break;
    case INTEGER   : fprintf(f, "INTEGER"); break;
    case REAL      : fprintf(f, "REAL"); break;
    case FUNCTION  : fprintf(f, "FUNCTION"); break;
    case PROCEDURE : fprintf(f, "PROCEDURE"); break;
    case BEGINTOK  : fprintf(f, "BEGIN"); break;
    case ENDTOK    : fprintf(f, "END"); break;
    case ASSIGN    : fprintf(f, ":="); break;
    case IF        : fprintf(f, "IF"); break;
    case THEN      : fprintf(f, "THEN"); break;
    case ELSE      : fprintf(f, "ELSE"); break;
    case WHILE     : fprintf(f, "WHILE"); break;
    case DO        : fprintf(f, "DO"); break;
    case SKIP      : fprintf(f, "SKIP"); break;
    case READLN    : fprintf(f, "READLN"); break;
    case WRITELN   : fprintf(f, "WRITELN"); break;
  }
}

void yyerror (char *msg) {
  showErrorLine();
  fprintf(stderr, "%s (detected at token=", msg);
  printToken(yychar, stderr);
  fprintf(stderr, ").\n");

  printf("ERRORS: 1\nREJECTED\n");
  exit(EXIT_SUCCESS);  /* EXIT_SUCCESS because we use Themis */
}

int main(int argc, char *argv[]) {
  symbolTableList = malloc(2 * sizeof(Identifier*));

  for (int i = 0; i < 2; i++) {
    symbolTableList[i] = malloc(100 * sizeof(Identifier));
    for (int j = 0; j < 100; j++) {
      symbolTableList[i][j].created = 0;
      symbolTableList[i][j].passedParamListLength = 0;
    }
  }

  functionIdentifier = malloc(100 * sizeof(char));
  arrayIdentifier = malloc(100 * sizeof(char));

  for (int i = 0; i < 100; i++) {
    readingIdentifiers[i].arrayIdentifierIndexesLength = 0;
  }
  
  FILE *input = (strcmp(argv[1], "-") == 0) ? stdin : fopen(argv[1], "r");
  if(input == NULL) {
    fprintf(stderr, "Failed to open input file!\n");
    exit(EXIT_FAILURE);
  }

  output = (strcmp(argv[2], "-") == 0) ? stdout : fopen(argv[2], "w");
  if (output == NULL) {
    fprintf(stderr, "Failed to open output file!\n");
    exit(EXIT_FAILURE);
  }

  initLexer(input);
  int result = yyparse();

  finalizeLexer();

#if 0
  showStringTable();
#endif

  fclose(input);

  for (int i = 0; i < 2; i++) {
    free(symbolTableList[i]->params);
    free(symbolTableList[i]);
  }

  free(symbolTableList);

  return EXIT_SUCCESS;
}