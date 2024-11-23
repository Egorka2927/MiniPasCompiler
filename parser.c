/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

  
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "strtab.h"

  void yyerror(char *msg);    /* forward declaration */
  /* exported by the lexer (made with flex) */
  extern int yylex(void);
  extern char *yytext;
  extern void showErrorLine();
  extern void initLexer(FILE *f);
  extern void finalizeLexer();

  extern char *identifier;
  extern int linenr;

  FILE *outputFile;

  int count = 0;
  int indexArr[1000];
  
  int globalIdIndex = 0;
  int isFunctionVariable = 0;
  char numericValue[100];
  int isLast = 0;
  char expressionValue[100];
  int tempVarCount = 0;
  char globalIdName[100];
  int globalArrayIndex = 0;
  int globalArrayStart = 0;
  int globalShowArrayIndex = 0;
  int isAssignmentArray = 0;
  int isShowAssignment = 0;
  int isShowAssignmentFunction = 0;
  int isLhsArr = 0;
  int isProcedureCall = 0;
  int isProcedureCallHelper = 0;
  int isFuncAssignment = 0;
  int isFuncAssignmentHelper = 0;
  int nestedArraysIdx = 0;
  char nestedArrays[100][100];

  int funcRangesIndexes[100];
  int procedureCallIndex = 0;

  int funcParamsRangesArr[100][100];
  int funcParamsRangesArrIdx = 0;
  int currentFuncParamsRangesArrIdx = 1;

  int isTempNegation = 0;

  typedef enum IdType {
    INTEGER_TYPE,
    REAL_TYPE,
    VOID_TYPE,
    CONST_INTEGER_TYPE,
    CONST_REAL_TYPE,
    ARRAY_TYPE
  } IdType;

  typedef struct PassedParameter {
    char name[100];
    IdType arrayType;
    IdType type;
    char nestedParams[100][100];
    int nestedParamsIdx;
    int variable;
    int passedArrayIdx;
    int isArrayWithIndex;
  } PassedParameter;

  typedef struct IdentifierInfo {
    char name[100];
    int variable;
    int start;
    int end;
    int created;
    int location;
    IdType type;
    IdType arrayType;
    struct IdentifierInfo *parameters;
    int paramsLength;
    PassedParameter passedParameters[100];
    int passedParametersLength;
    int readNestedArraysIdIndex;
  } IdentifierInfo;

  typedef struct ReadWriteInfo {
    int tempVarIdx;
    int tempVarType;
  } ReadWriteInfo;

  int isRead = 0;
  int isReadId = 0;
  int isReadArr = 0;
  int isReadArrFirst = 0;

  int readIdx = 0;

  int isWrite = 0;
  int writeIdx = 0;

  ReadWriteInfo writeArrIndexes[100];
  ReadWriteInfo readArrIndexes[100];

  int labelStack[100];
  int labelStackIdx = 0;
  int labelStackCount = 0;

  char firstReadArr[100];
  char readNestedArrays[100];
  int readNestedArraysIdx = 0;

  typedef struct TempVar {
    int tempCount;
    int tempType;
  } TempVar;

  int tempVarStackCount = 0;;
  TempVar tempVarStack[100];

  IdentifierInfo showArray;

  char functionId[100];
  char arrayId[100];

  int paramsListLength = 0;
  int paramsCount = 0;
  int start;
  int end;
  int variable = 1;
  int variable2 = 0;
  int hasPassedParams = 0;

  int funcIdIndexes[100];
  int funcIdIndexesLength = 0;

  IdentifierInfo *parametersList;
  IdentifierInfo *symbolTable;
  IdentifierInfo **scopeStack;

  void addIdInfo(IdType type);
  void addIdIndex();
  void removeFromScope();
  void addFunctionInfo(IdType type, IdType arrayType);
  void checkRedeclaration();
  void initializeFunction();
  void addToParamsList(IdType type, IdType arrayType, int variable);
  void checkConstRedeclaration(int scope, int i);
  void checkUndeclaredId(int isRhs);
  void addArrayInfo(IdType type, int arrayType, int start, int end);
  int returnFunctionType();
  void addToPassedParamsList(IdType type);
  int solveExpressionType(int expression1, int expression2);
  int returnArrayType();
  int returnFunctionType();
  int returnIdentifierType();
  void checkFuncParam();
  void addToFuncIndexes();
  void checkArithExprTypesRegular(int expression1, int expression2);
  void checkArithExprTypes(int expression1, int expression2);
  void checkAssignmentTypes(int expression1, int expression2);
  void checkLeftSide();
  void checkAssignmentTypes(int expression1, int expression2);
  void translateDeclarations(int index, int isFunction, int type, int isArray);
  void translateConstant(int type, char *name, char *numericValue);
  void translateDeclarationsTypes(int type);
  void translateFunction(int index, int type, IdentifierInfo *params, int paramsLength);
  void translateMain();
  void translateAssignment(char operator);
  void addNumberToTempStack(char *type);
  void addIdToTempStack();
  void addArrayToTempStack(int arrIndex);
  void showFinalTempAssignment();
  void getArrayInfoShow();
  void addFuncToTempStack();
  void resetFuncParamArrayTranslate();
  void getGlobalArrayStart();
  void printWriteStatement();
  void printReadStatement();
  void printReadNestedArraysBrackets(int index);
  void translateComparison(char operator);
  int arrayStartToString();

  int scopeLevel = 0;


#line 261 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PROGRAM = 3,                    /* PROGRAM  */
  YYSYMBOL_CONST = 4,                      /* CONST  */
  YYSYMBOL_IDENTIFIER = 5,                 /* IDENTIFIER  */
  YYSYMBOL_VAR = 6,                        /* VAR  */
  YYSYMBOL_ARRAY = 7,                      /* ARRAY  */
  YYSYMBOL_RANGE = 8,                      /* RANGE  */
  YYSYMBOL_INTNUMBER = 9,                  /* INTNUMBER  */
  YYSYMBOL_REALNUMBER = 10,                /* REALNUMBER  */
  YYSYMBOL_OF = 11,                        /* OF  */
  YYSYMBOL_FUNCTION = 12,                  /* FUNCTION  */
  YYSYMBOL_PROCEDURE = 13,                 /* PROCEDURE  */
  YYSYMBOL_BEGINTOK = 14,                  /* BEGINTOK  */
  YYSYMBOL_ENDTOK = 15,                    /* ENDTOK  */
  YYSYMBOL_ASSIGN = 16,                    /* ASSIGN  */
  YYSYMBOL_IF = 17,                        /* IF  */
  YYSYMBOL_THEN = 18,                      /* THEN  */
  YYSYMBOL_ELSE = 19,                      /* ELSE  */
  YYSYMBOL_WHILE = 20,                     /* WHILE  */
  YYSYMBOL_DO = 21,                        /* DO  */
  YYSYMBOL_RELOPLT = 22,                   /* RELOPLT  */
  YYSYMBOL_RELOPLEQ = 23,                  /* RELOPLEQ  */
  YYSYMBOL_RELOPEQ = 24,                   /* RELOPEQ  */
  YYSYMBOL_RELOPNEQ = 25,                  /* RELOPNEQ  */
  YYSYMBOL_RELOPGEQ = 26,                  /* RELOPGEQ  */
  YYSYMBOL_RELOPGT = 27,                   /* RELOPGT  */
  YYSYMBOL_INTEGER = 28,                   /* INTEGER  */
  YYSYMBOL_REAL = 29,                      /* REAL  */
  YYSYMBOL_AND = 30,                       /* AND  */
  YYSYMBOL_OR = 31,                        /* OR  */
  YYSYMBOL_NOT = 32,                       /* NOT  */
  YYSYMBOL_DIV = 33,                       /* DIV  */
  YYSYMBOL_MOD = 34,                       /* MOD  */
  YYSYMBOL_SKIP = 35,                      /* SKIP  */
  YYSYMBOL_READLN = 36,                    /* READLN  */
  YYSYMBOL_WRITELN = 37,                   /* WRITELN  */
  YYSYMBOL_38_ = 38,                       /* '+'  */
  YYSYMBOL_39_ = 39,                       /* '-'  */
  YYSYMBOL_40_ = 40,                       /* '*'  */
  YYSYMBOL_41_ = 41,                       /* '/'  */
  YYSYMBOL_42_ = 42,                       /* ';'  */
  YYSYMBOL_43_ = 43,                       /* '.'  */
  YYSYMBOL_44_ = 44,                       /* ':'  */
  YYSYMBOL_45_ = 45,                       /* ','  */
  YYSYMBOL_46_ = 46,                       /* '['  */
  YYSYMBOL_47_ = 47,                       /* ']'  */
  YYSYMBOL_48_ = 48,                       /* '('  */
  YYSYMBOL_49_ = 49,                       /* ')'  */
  YYSYMBOL_YYACCEPT = 50,                  /* $accept  */
  YYSYMBOL_program = 51,                   /* program  */
  YYSYMBOL_52_1 = 52,                      /* $@1  */
  YYSYMBOL_53_2 = 53,                      /* $@2  */
  YYSYMBOL_54_3 = 54,                      /* $@3  */
  YYSYMBOL_ConstDecl = 55,                 /* ConstDecl  */
  YYSYMBOL_56_4 = 56,                      /* $@4  */
  YYSYMBOL_57_5 = 57,                      /* $@5  */
  YYSYMBOL_NumericValue = 58,              /* NumericValue  */
  YYSYMBOL_VarDecl = 59,                   /* VarDecl  */
  YYSYMBOL_IdentifierList = 60,            /* IdentifierList  */
  YYSYMBOL_TypeSpec = 61,                  /* TypeSpec  */
  YYSYMBOL_62_6 = 62,                      /* $@6  */
  YYSYMBOL_63_7 = 63,                      /* $@7  */
  YYSYMBOL_BasicType = 64,                 /* BasicType  */
  YYSYMBOL_FuncProcDecl = 65,              /* FuncProcDecl  */
  YYSYMBOL_SubProgDecl = 66,               /* SubProgDecl  */
  YYSYMBOL_SubProgHeading = 67,            /* SubProgHeading  */
  YYSYMBOL_68_8 = 68,                      /* $@8  */
  YYSYMBOL_69_9 = 69,                      /* $@9  */
  YYSYMBOL_70_10 = 70,                     /* $@10  */
  YYSYMBOL_71_11 = 71,                     /* $@11  */
  YYSYMBOL_PossibleParameters = 72,        /* PossibleParameters  */
  YYSYMBOL_Parameters = 73,                /* Parameters  */
  YYSYMBOL_ParameterList = 74,             /* ParameterList  */
  YYSYMBOL_ParamList = 75,                 /* ParamList  */
  YYSYMBOL_76_12 = 76,                     /* $@12  */
  YYSYMBOL_77_13 = 77,                     /* $@13  */
  YYSYMBOL_CompoundStatement = 78,         /* CompoundStatement  */
  YYSYMBOL_OptionalStatements = 79,        /* OptionalStatements  */
  YYSYMBOL_StatementList = 80,             /* StatementList  */
  YYSYMBOL_Statement = 81,                 /* Statement  */
  YYSYMBOL_82_14 = 82,                     /* $@14  */
  YYSYMBOL_83_15 = 83,                     /* $@15  */
  YYSYMBOL_84_16 = 84,                     /* $@16  */
  YYSYMBOL_85_17 = 85,                     /* $@17  */
  YYSYMBOL_86_18 = 86,                     /* $@18  */
  YYSYMBOL_LhsList = 87,                   /* LhsList  */
  YYSYMBOL_Lhs = 88,                       /* Lhs  */
  YYSYMBOL_89_19 = 89,                     /* $@19  */
  YYSYMBOL_90_20 = 90,                     /* $@20  */
  YYSYMBOL_ProcedureCall = 91,             /* ProcedureCall  */
  YYSYMBOL_92_21 = 92,                     /* $@21  */
  YYSYMBOL_93_22 = 93,                     /* $@22  */
  YYSYMBOL_94_23 = 94,                     /* $@23  */
  YYSYMBOL_95_24 = 95,                     /* $@24  */
  YYSYMBOL_Guard = 96,                     /* Guard  */
  YYSYMBOL_BoolAtom = 97,                  /* BoolAtom  */
  YYSYMBOL_Relop = 98,                     /* Relop  */
  YYSYMBOL_ArithExprList = 99,             /* ArithExprList  */
  YYSYMBOL_ArithExpr = 100,                /* ArithExpr  */
  YYSYMBOL_101_25 = 101,                   /* $@25  */
  YYSYMBOL_102_26 = 102,                   /* $@26  */
  YYSYMBOL_103_27 = 103,                   /* $@27  */
  YYSYMBOL_IdArrayRule = 104               /* IdArrayRule  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   198

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  188

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      48,    49,    40,    38,    45,    39,    43,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    44,    42,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    46,     2,    47,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   215,   215,   219,   219,   215,   223,   223,   223,   224,
     227,   228,   231,   232,   235,   236,   239,   240,   240,   240,
     243,   244,   247,   248,   251,   254,   254,   254,   255,   255,
     255,   258,   259,   262,   265,   266,   269,   269,   270,   270,
     273,   276,   277,   280,   281,   284,   285,   286,   287,   288,
     288,   288,   288,   289,   289,   289,   292,   293,   295,   296,
     296,   296,   299,   300,   300,   300,   301,   301,   302,   302,
     305,   306,   307,   308,   309,   312,   315,   316,   317,   318,
     319,   320,   323,   324,   327,   328,   329,   330,   330,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   339,
     340,   343
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "PROGRAM", "CONST",
  "IDENTIFIER", "VAR", "ARRAY", "RANGE", "INTNUMBER", "REALNUMBER", "OF",
  "FUNCTION", "PROCEDURE", "BEGINTOK", "ENDTOK", "ASSIGN", "IF", "THEN",
  "ELSE", "WHILE", "DO", "RELOPLT", "RELOPLEQ", "RELOPEQ", "RELOPNEQ",
  "RELOPGEQ", "RELOPGT", "INTEGER", "REAL", "AND", "OR", "NOT", "DIV",
  "MOD", "SKIP", "READLN", "WRITELN", "'+'", "'-'", "'*'", "'/'", "';'",
  "'.'", "':'", "','", "'['", "']'", "'('", "')'", "$accept", "program",
  "$@1", "$@2", "$@3", "ConstDecl", "$@4", "$@5", "NumericValue",
  "VarDecl", "IdentifierList", "TypeSpec", "$@6", "$@7", "BasicType",
  "FuncProcDecl", "SubProgDecl", "SubProgHeading", "$@8", "$@9", "$@10",
  "$@11", "PossibleParameters", "Parameters", "ParameterList", "ParamList",
  "$@12", "$@13", "CompoundStatement", "OptionalStatements",
  "StatementList", "Statement", "$@14", "$@15", "$@16", "$@17", "$@18",
  "LhsList", "Lhs", "$@19", "$@20", "ProcedureCall", "$@21", "$@22",
  "$@23", "$@24", "Guard", "BoolAtom", "Relop", "ArithExprList",
  "ArithExpr", "$@25", "$@26", "$@27", "IdArrayRule", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-135)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-102)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,    27,    10,    13,  -135,  -135,  -135,    54,    71,    89,
    -135,   121,    57,    86,  -135,    40,   123,   128,   130,   100,
    -135,   105,    -1,   138,  -135,  -135,     0,  -135,  -135,    43,
    -135,  -135,  -135,   103,  -135,  -135,   108,  -135,  -135,   113,
     113,    15,    14,  -135,  -135,  -135,  -135,  -135,   136,   112,
    -135,   139,  -135,   122,  -135,   131,   155,  -135,   102,   127,
    -135,  -135,   126,   132,    50,  -135,  -135,    14,  -135,    14,
      99,  -135,    98,   133,    14,   134,   135,  -135,     0,    20,
    -135,  -135,  -135,   121,   140,    25,  -135,   106,   142,    20,
    -135,   141,  -135,    20,   -15,    78,    14,    14,   156,  -135,
    -135,  -135,  -135,  -135,  -135,    20,    20,    20,    20,    20,
      20,    20,    20,    99,   170,    20,  -135,    20,   129,   168,
     140,   137,   102,  -135,  -135,  -135,   129,    20,  -135,    48,
    -135,  -135,  -135,   147,     0,  -135,  -135,    48,    48,  -135,
    -135,   129,    39,   157,   144,   -38,  -135,   -36,   129,   107,
     177,   143,    -1,  -135,   146,   145,    42,    20,  -135,    20,
    -135,     0,   170,  -135,    20,  -135,  -135,    -1,  -135,  -135,
    -135,  -135,    64,   172,   119,  -135,  -135,   129,   148,  -135,
    -135,  -135,  -135,   182,     0,   106,  -135,  -135
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     2,     9,    13,     0,    23,
       6,     0,     3,     0,    14,     0,     0,     0,     0,     0,
      13,     0,     0,     0,    25,    28,    42,     4,    22,     0,
      10,    11,     7,     0,    20,    21,     0,    16,    15,     0,
      32,    62,     0,    53,    46,    66,    68,    48,     0,    41,
      43,     0,    47,     0,    24,     0,     0,    12,     0,     0,
      29,    31,     0,     0,    84,    90,    91,     0,    98,     0,
      49,    70,     0,     0,     0,     0,     0,    40,     0,     0,
       5,     8,    17,     0,    38,     0,    34,     0,     0,     0,
      64,     0,    71,     0,     0,     0,     0,     0,     0,    76,
      77,    78,    79,    80,    81,     0,     0,     0,     0,     0,
       0,     0,     0,    54,     0,     0,    44,     0,    45,     0,
      36,     0,     0,    33,    26,    30,    60,     0,    88,    99,
      74,   100,    73,    72,     0,    96,    97,    92,    93,    94,
      95,    75,     0,     0,    58,     0,    56,     0,    82,     0,
       0,     0,     0,    35,     0,     0,     0,     0,    50,     0,
      85,     0,     0,    67,     0,    69,    18,     0,    39,    27,
      61,    65,     0,     0,     0,    55,    57,    83,     0,    37,
      89,    51,    86,     0,     0,     0,    52,    19
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,   174,
      -8,  -134,  -135,  -135,   -86,  -135,  -135,  -135,  -135,  -135,
    -135,  -135,  -135,   158,  -135,    74,  -135,  -135,    36,  -135,
    -135,   -78,  -135,  -135,  -135,  -135,  -135,  -135,  -110,  -135,
    -135,  -135,  -135,  -135,  -135,  -135,    -3,  -135,  -135,  -106,
     -67,  -135,  -135,  -135,  -135
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     6,    18,    53,     7,    13,    55,    32,     9,
      84,    36,   119,   178,    37,    12,    19,    20,    39,   154,
      40,    88,    60,    59,    85,    86,   151,   121,    47,    48,
      49,    50,    98,   173,   184,    74,   143,   145,    51,    62,
     155,    52,    63,   127,    75,    76,    70,    71,   111,   147,
      72,    91,   157,    93,    73
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     116,   124,    95,    15,   146,    41,    33,   162,     1,   164,
       4,   163,   118,   165,    26,    96,    97,    42,   168,    64,
      43,   156,   126,    65,    66,    64,   129,    34,    35,    65,
      66,   -58,     3,   179,   130,    44,    45,    46,   135,   136,
     137,   138,   139,   140,   141,   142,    67,   159,   148,    11,
     149,   172,   176,    68,    27,     5,   158,    26,     8,    68,
     148,   -59,    69,   -63,    92,    54,    94,   122,   117,    16,
      17,   113,   105,   106,   123,   120,    10,   107,   108,   109,
     110,   105,   106,   175,    22,    23,   160,   164,   109,   110,
     148,   171,   174,   132,   133,    11,  -101,   177,   -87,   187,
      99,   100,   101,   102,   103,   104,   186,    14,    83,   164,
      21,   105,   106,   180,    30,    31,   107,   108,   109,   110,
      99,   100,   101,   102,   103,   104,    14,   131,    24,    96,
      97,   105,   106,    25,    34,    35,   107,   108,   109,   110,
     105,   106,    28,    38,    26,   107,   108,   109,   110,    56,
      57,    77,   105,   106,    78,    79,   131,   107,   108,   109,
     110,    58,   105,   106,    82,    80,   182,   107,   108,   109,
     110,    87,    89,    81,   134,   144,   150,    96,   161,   112,
      90,   152,   114,   115,   125,    23,   166,   167,   169,   128,
     -59,   181,   170,   185,    29,   183,   153,     0,    61
};

static const yytype_int16 yycheck[] =
{
      78,    87,    69,    11,   114,     5,     7,    45,     3,    45,
       0,    49,    79,    49,    14,    30,    31,    17,   152,     5,
      20,   127,    89,     9,    10,     5,    93,    28,    29,     9,
      10,    16,     5,   167,    49,    35,    36,    37,   105,   106,
     107,   108,   109,   110,   111,   112,    32,     8,   115,     6,
     117,   157,   162,    39,    18,    42,   134,    14,     4,    39,
     127,    46,    48,    48,    67,    29,    69,    42,    48,    12,
      13,    74,    33,    34,    49,    83,     5,    38,    39,    40,
      41,    33,    34,   161,    44,    45,    47,    45,    40,    41,
     157,    49,   159,    96,    97,     6,    46,   164,    48,   185,
      22,    23,    24,    25,    26,    27,   184,     5,     6,    45,
      24,    33,    34,    49,     9,    10,    38,    39,    40,    41,
      22,    23,    24,    25,    26,    27,     5,    49,     5,    30,
      31,    33,    34,     5,    28,    29,    38,    39,    40,    41,
      33,    34,    42,     5,    14,    38,    39,    40,    41,    46,
      42,    15,    33,    34,    42,    16,    49,    38,    39,    40,
      41,    48,    33,    34,     9,    43,    47,    38,    39,    40,
      41,    44,    46,    42,    18,     5,     8,    30,    21,    46,
      48,    44,    48,    48,    42,    45,     9,    44,    42,    48,
      46,    19,    47,    11,    20,    47,   122,    -1,    40
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    51,     5,     0,    42,    52,    55,     4,    59,
       5,     6,    65,    56,     5,    60,    12,    13,    53,    66,
      67,    24,    44,    45,     5,     5,    14,    78,    42,    59,
       9,    10,    58,     7,    28,    29,    61,    64,     5,    68,
      70,     5,    17,    20,    35,    36,    37,    78,    79,    80,
      81,    88,    91,    54,    78,    57,    46,    42,    48,    73,
      72,    73,    89,    92,     5,     9,    10,    32,    39,    48,
      96,    97,   100,   104,    85,    94,    95,    15,    42,    16,
      43,    42,     9,     6,    60,    74,    75,    44,    71,    46,
      48,   101,    96,   103,    96,   100,    30,    31,    82,    22,
      23,    24,    25,    26,    27,    33,    34,    38,    39,    40,
      41,    98,    46,    96,    48,    48,    81,    48,   100,    62,
      60,    77,    42,    49,    64,    42,   100,    93,    48,   100,
      49,    49,    96,    96,    18,   100,   100,   100,   100,   100,
     100,   100,   100,    86,     5,    87,    88,    99,   100,   100,
       8,    76,    44,    75,    69,    90,    99,   102,    81,     8,
      47,    21,    45,    49,    45,    49,     9,    44,    61,    42,
      47,    49,    99,    83,   100,    81,    88,   100,    63,    61,
      49,    19,    47,    47,    84,    11,    81,    64
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    52,    53,    54,    51,    56,    57,    55,    55,
      58,    58,    59,    59,    60,    60,    61,    62,    63,    61,
      64,    64,    65,    65,    66,    68,    69,    67,    70,    71,
      67,    72,    72,    73,    74,    74,    76,    75,    77,    75,
      78,    79,    79,    80,    80,    81,    81,    81,    81,    82,
      83,    84,    81,    85,    86,    81,    87,    87,    88,    89,
      90,    88,    91,    92,    93,    91,    94,    91,    95,    91,
      96,    96,    96,    96,    96,    97,    98,    98,    98,    98,
      98,    98,    99,    99,   100,   100,   100,   101,   102,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   103,   100,
     100,   104
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     0,    11,     0,     0,     8,     0,
       1,     1,     6,     0,     1,     3,     1,     0,     0,    10,
       1,     1,     3,     0,     3,     0,     0,     8,     0,     0,
       6,     1,     0,     3,     1,     3,     0,     5,     0,     4,
       3,     1,     0,     1,     3,     3,     1,     1,     1,     0,
       0,     0,     9,     0,     0,     6,     1,     3,     1,     0,
       0,     6,     1,     0,     0,     6,     0,     5,     0,     5,
       1,     2,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     4,     6,     0,     0,     6,
       1,     1,     3,     3,     3,     3,     3,     3,     0,     3,
       3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* $@1: %empty  */
#line 215 "parser.y"
                                            {fprintf(outputFile, "#include <stdio.h>\n");}
#line 1488 "parser.tab.c"
    break;

  case 3: /* $@2: %empty  */
#line 219 "parser.y"
                     {translateMain();}
#line 1494 "parser.tab.c"
    break;

  case 4: /* $@3: %empty  */
#line 219 "parser.y"
                                                          {fprintf(outputFile, "return 0;\n}\n");}
#line 1500 "parser.tab.c"
    break;

  case 6: /* $@4: %empty  */
#line 223 "parser.y"
                                                {addIdIndex();}
#line 1506 "parser.tab.c"
    break;

  case 7: /* $@5: %empty  */
#line 223 "parser.y"
                                                                                     {addIdInfo((yyvsp[0].type) + 3); fprintf(outputFile, ";\n");}
#line 1512 "parser.tab.c"
    break;

  case 10: /* NumericValue: INTNUMBER  */
#line 227 "parser.y"
                               {strcpy(numericValue, yytext); (yyval.type) = 0;}
#line 1518 "parser.tab.c"
    break;

  case 11: /* NumericValue: REALNUMBER  */
#line 228 "parser.y"
                                {strcpy(numericValue, yytext); (yyval.type) = 1;}
#line 1524 "parser.tab.c"
    break;

  case 14: /* IdentifierList: IDENTIFIER  */
#line 235 "parser.y"
                                {addIdIndex(); (yyval.type) = 1;}
#line 1530 "parser.tab.c"
    break;

  case 15: /* IdentifierList: IdentifierList ',' IDENTIFIER  */
#line 236 "parser.y"
                                                    {addIdIndex(); (yyval.type) = (yyvsp[-2].type) + 1;}
#line 1536 "parser.tab.c"
    break;

  case 16: /* TypeSpec: BasicType  */
#line 239 "parser.y"
                               {addIdInfo((yyvsp[0].type));}
#line 1542 "parser.tab.c"
    break;

  case 17: /* $@6: %empty  */
#line 240 "parser.y"
                                         {start = atoi(yytext);}
#line 1548 "parser.tab.c"
    break;

  case 18: /* $@7: %empty  */
#line 240 "parser.y"
                                                                                 {end = atoi(yytext);}
#line 1554 "parser.tab.c"
    break;

  case 19: /* TypeSpec: ARRAY '[' INTNUMBER $@6 RANGE INTNUMBER $@7 ']' OF BasicType  */
#line 240 "parser.y"
                                                                                                                        {addArrayInfo(ARRAY_TYPE, (yyvsp[0].type), start, end); (yyval.type) = 5;}
#line 1560 "parser.tab.c"
    break;

  case 20: /* BasicType: INTEGER  */
#line 243 "parser.y"
                             {(yyval.type) = 0;}
#line 1566 "parser.tab.c"
    break;

  case 21: /* BasicType: REAL  */
#line 244 "parser.y"
                          {(yyval.type) = 1;}
#line 1572 "parser.tab.c"
    break;

  case 24: /* SubProgDecl: SubProgHeading VarDecl CompoundStatement  */
#line 251 "parser.y"
                                                              {fprintf(outputFile, "}\n"); removeFromScope(); isShowAssignmentFunction = 0;}
#line 1578 "parser.tab.c"
    break;

  case 25: /* $@8: %empty  */
#line 254 "parser.y"
                                         {initializeFunction(); isFunctionVariable = 1; isShowAssignmentFunction = 1;}
#line 1584 "parser.tab.c"
    break;

  case 26: /* $@9: %empty  */
#line 254 "parser.y"
                                                                                                                                                 {addFunctionInfo((yyvsp[0].type), -1); isFunctionVariable = 0; resetFuncParamArrayTranslate();}
#line 1590 "parser.tab.c"
    break;

  case 28: /* $@10: %empty  */
#line 255 "parser.y"
                                          {initializeFunction(); isFunctionVariable = 1;}
#line 1596 "parser.tab.c"
    break;

  case 29: /* $@11: %empty  */
#line 255 "parser.y"
                                                                                                             {addFunctionInfo(VOID_TYPE, -1); isFunctionVariable = 0; resetFuncParamArrayTranslate();}
#line 1602 "parser.tab.c"
    break;

  case 36: /* $@12: %empty  */
#line 269 "parser.y"
                                        {paramsCount = (yyvsp[0].type);}
#line 1608 "parser.tab.c"
    break;

  case 37: /* ParamList: VAR IdentifierList $@12 ':' TypeSpec  */
#line 269 "parser.y"
                                                                         {addToParamsList((yyvsp[0].type), -1, 1);}
#line 1614 "parser.tab.c"
    break;

  case 38: /* $@13: %empty  */
#line 270 "parser.y"
                                    {paramsCount = (yyvsp[0].type);}
#line 1620 "parser.tab.c"
    break;

  case 39: /* ParamList: IdentifierList $@13 ':' TypeSpec  */
#line 270 "parser.y"
                                                                     {addToParamsList((yyvsp[0].type), -1, 0);}
#line 1626 "parser.tab.c"
    break;

  case 45: /* Statement: Lhs ASSIGN ArithExpr  */
#line 284 "parser.y"
                                          {checkAssignmentTypes((yyvsp[-2].type), (yyvsp[0].type)); showFinalTempAssignment(); isShowAssignment = 0;}
#line 1632 "parser.tab.c"
    break;

  case 49: /* $@14: %empty  */
#line 288 "parser.y"
                              {fprintf(outputFile, "if (!_t%d) goto lbl%d;\n", tempVarStack[tempVarStackCount - 1].tempCount, labelStackCount); labelStackCount++;}
#line 1638 "parser.tab.c"
    break;

  case 50: /* $@15: %empty  */
#line 288 "parser.y"
                                                                                                                                                                                   {fprintf(outputFile, "goto lbl%d;\n", labelStackCount); labelStack[labelStackIdx] = labelStackCount; labelStackIdx++;}
#line 1644 "parser.tab.c"
    break;

  case 51: /* $@16: %empty  */
#line 288 "parser.y"
                                                                                                                                                                                                                                                                                                               {fprintf(outputFile, "lbl%d : ;\n", labelStackCount - 1); labelStackCount++;}
#line 1650 "parser.tab.c"
    break;

  case 52: /* Statement: IF Guard $@14 THEN Statement $@15 ELSE $@16 Statement  */
#line 288 "parser.y"
                                                                                                                                                                                                                                                                                                                                                                                                       {fprintf(outputFile, "lbl%d : ;\n", labelStack[labelStackIdx - 1]); labelStackIdx--;}
#line 1656 "parser.tab.c"
    break;

  case 53: /* $@17: %empty  */
#line 289 "parser.y"
                           {fprintf(outputFile, "lbl%d : ;\n", labelStackCount); labelStack[labelStackIdx] = labelStackCount; labelStackIdx++; labelStackCount++;}
#line 1662 "parser.tab.c"
    break;

  case 54: /* $@18: %empty  */
#line 289 "parser.y"
                                                                                                                                                                         {fprintf(outputFile, "if (!_t%d) goto lbl%d;\n", tempVarStack[tempVarStackCount - 1].tempCount, labelStackCount); labelStack[labelStackIdx] = labelStackCount; labelStackIdx++; labelStackCount++;}
#line 1668 "parser.tab.c"
    break;

  case 55: /* Statement: WHILE $@17 Guard $@18 DO Statement  */
#line 289 "parser.y"
                                                                                                                                                                                                                                                                                                                                                                                          {fprintf(outputFile, "goto lbl%d;\n", labelStack[labelStackIdx - 2]); fprintf(outputFile, "lbl%d : ;\n", labelStack[labelStackIdx - 1]); labelStackIdx -= 2; labelStackCount++;}
#line 1674 "parser.tab.c"
    break;

  case 56: /* LhsList: Lhs  */
#line 292 "parser.y"
                         {if (isRead == 1) {readIdx++;}}
#line 1680 "parser.tab.c"
    break;

  case 57: /* LhsList: LhsList ',' Lhs  */
#line 293 "parser.y"
                                     {if (isRead == 1) {readIdx++;}}
#line 1686 "parser.tab.c"
    break;

  case 58: /* Lhs: IDENTIFIER  */
#line 295 "parser.y"
                                {checkUndeclaredId(0); checkLeftSide(); strcpy(globalIdName, identifier); if (isRead == 1) {isReadId = 1; addIdToTempStack(); isReadId = 0;} isShowAssignment = 0; (yyval.type) = returnIdentifierType();}
#line 1692 "parser.tab.c"
    break;

  case 59: /* $@19: %empty  */
#line 296 "parser.y"
                                {checkUndeclaredId(0); strcpy(arrayId, identifier); checkLeftSide(); getArrayInfoShow(); strcpy(globalIdName, identifier); if (isRead == 1) {strcpy(nestedArrays[nestedArraysIdx], arrayId); nestedArraysIdx++; strcpy(firstReadArr, identifier); readNestedArraysIdx++; isReadArrFirst = 1; isReadArr = 1; isReadArr = 0; isReadArrFirst = 0;} isLhsArr = 1; isAssignmentArray = 1;}
#line 1698 "parser.tab.c"
    break;

  case 60: /* $@20: %empty  */
#line 296 "parser.y"
                                                                                                                                                                                                                                                                                                                                                                                                                                    {isShowAssignment = 1;}
#line 1704 "parser.tab.c"
    break;

  case 61: /* Lhs: IDENTIFIER $@19 '[' ArithExpr $@20 ']'  */
#line 296 "parser.y"
                                                                                                                                                                                                                                                                                                                                                                                                                                                                {checkUndeclaredId(1); (yyval.type) = returnArrayType(); if (isRead == 1) {isReadArr = 1; addArrayToTempStack(globalArrayIndex); isReadArr = 0; readNestedArraysIdx = 0;} isLhsArr = 0; isAssignmentArray = 0;}
#line 1710 "parser.tab.c"
    break;

  case 62: /* ProcedureCall: IDENTIFIER  */
#line 299 "parser.y"
                                {checkUndeclaredId(0);}
#line 1716 "parser.tab.c"
    break;

  case 63: /* $@21: %empty  */
#line 300 "parser.y"
                                {checkUndeclaredId(0); addToFuncIndexes(); isFuncAssignmentHelper++; funcParamsRangesArrIdx++;}
#line 1722 "parser.tab.c"
    break;

  case 64: /* $@22: %empty  */
#line 300 "parser.y"
                                                                                                                                    {hasPassedParams = 1; variable = 1; isProcedureCall = 1;}
#line 1728 "parser.tab.c"
    break;

  case 65: /* ProcedureCall: IDENTIFIER $@21 '(' $@22 ArithExprList ')'  */
#line 300 "parser.y"
                                                                                                                                                                                                                {isFuncAssignmentHelper--; funcIdIndexesLength--; if (funcIdIndexesLength == 0) {hasPassedParams = 0;} isFuncAssignment = 1; isProcedureCallHelper = 1; addIdToTempStack(); isProcedureCallHelper = 0; isProcedureCall = 0; funcParamsRangesArrIdx--; isFuncAssignment = 0; checkFuncParam();}
#line 1734 "parser.tab.c"
    break;

  case 66: /* $@23: %empty  */
#line 301 "parser.y"
                            {isProcedureCall = 1; isRead = 1;}
#line 1740 "parser.tab.c"
    break;

  case 67: /* ProcedureCall: READLN $@23 '(' LhsList ')'  */
#line 301 "parser.y"
                                                                               {printReadStatement(); readIdx = 0; isProcedureCall = 0; isRead = 0;}
#line 1746 "parser.tab.c"
    break;

  case 68: /* $@24: %empty  */
#line 302 "parser.y"
                             {isFuncAssignmentHelper++; funcParamsRangesArrIdx++; isProcedureCall = 1; isWrite = 1;}
#line 1752 "parser.tab.c"
    break;

  case 69: /* ProcedureCall: WRITELN $@24 '(' ArithExprList ')'  */
#line 302 "parser.y"
                                                                                                                                           {printWriteStatement(); isProcedureCall = 0; writeIdx = 0; isWrite = 0;}
#line 1758 "parser.tab.c"
    break;

  case 71: /* Guard: NOT Guard  */
#line 306 "parser.y"
                               {translateComparison('!');}
#line 1764 "parser.tab.c"
    break;

  case 72: /* Guard: Guard OR Guard  */
#line 307 "parser.y"
                                    {translateComparison('|');}
#line 1770 "parser.tab.c"
    break;

  case 73: /* Guard: Guard AND Guard  */
#line 308 "parser.y"
                                     {translateComparison('&');}
#line 1776 "parser.tab.c"
    break;

  case 75: /* BoolAtom: ArithExpr Relop ArithExpr  */
#line 312 "parser.y"
                                               {translateComparison((yyvsp[-1].type));}
#line 1782 "parser.tab.c"
    break;

  case 76: /* Relop: RELOPLT  */
#line 315 "parser.y"
                             {(yyval.type) = '0';}
#line 1788 "parser.tab.c"
    break;

  case 77: /* Relop: RELOPLEQ  */
#line 316 "parser.y"
                              {(yyval.type) = '1';}
#line 1794 "parser.tab.c"
    break;

  case 78: /* Relop: RELOPEQ  */
#line 317 "parser.y"
                             {(yyval.type) = '2';}
#line 1800 "parser.tab.c"
    break;

  case 79: /* Relop: RELOPNEQ  */
#line 318 "parser.y"
                              {(yyval.type) = '3';}
#line 1806 "parser.tab.c"
    break;

  case 80: /* Relop: RELOPGEQ  */
#line 319 "parser.y"
                              {(yyval.type) = '4';}
#line 1812 "parser.tab.c"
    break;

  case 81: /* Relop: RELOPGT  */
#line 320 "parser.y"
                             {(yyval.type) = '5';}
#line 1818 "parser.tab.c"
    break;

  case 82: /* ArithExprList: ArithExpr  */
#line 323 "parser.y"
                               {if (isWrite == 1) {writeIdx++;} addToPassedParamsList((yyvsp[0].type));}
#line 1824 "parser.tab.c"
    break;

  case 83: /* ArithExprList: ArithExprList ',' ArithExpr  */
#line 324 "parser.y"
                                                 {if (isWrite == 1) {writeIdx++;} addToPassedParamsList((yyvsp[0].type));}
#line 1830 "parser.tab.c"
    break;

  case 84: /* ArithExpr: IDENTIFIER  */
#line 327 "parser.y"
                                {checkUndeclaredId(1); addIdToTempStack(); (yyval.type) = returnIdentifierType();}
#line 1836 "parser.tab.c"
    break;

  case 85: /* ArithExpr: IdArrayRule '[' ArithExpr ']'  */
#line 328 "parser.y"
                                                   {if (isAssignmentArray == 1) {addArrayToTempStack(globalArrayIndex); nestedArraysIdx = 0; isAssignmentArray = 0;} (yyval.type) = returnArrayType();}
#line 1842 "parser.tab.c"
    break;

  case 86: /* ArithExpr: IdArrayRule '[' ArithExpr RANGE ArithExpr ']'  */
#line 329 "parser.y"
                                                                   {variable = variable2; (yyval.type) = ARRAY_TYPE;}
#line 1848 "parser.tab.c"
    break;

  case 87: /* $@25: %empty  */
#line 330 "parser.y"
                                {checkUndeclaredId(1); addToFuncIndexes(); isFuncAssignmentHelper++; funcParamsRangesArrIdx++;}
#line 1854 "parser.tab.c"
    break;

  case 88: /* $@26: %empty  */
#line 330 "parser.y"
                                                                                                                                    {hasPassedParams = 1; variable = 1;}
#line 1860 "parser.tab.c"
    break;

  case 89: /* ArithExpr: IDENTIFIER $@25 '(' $@26 ArithExprList ')'  */
#line 330 "parser.y"
                                                                                                                                                                                           {isFuncAssignmentHelper--; funcIdIndexesLength--; if (funcIdIndexesLength == 0) {hasPassedParams = 0;} isFuncAssignment = 1; addIdToTempStack(); funcParamsRangesArrIdx--; isFuncAssignment = 0; checkFuncParam(); (yyval.type) = returnFunctionType();}
#line 1866 "parser.tab.c"
    break;

  case 90: /* ArithExpr: INTNUMBER  */
#line 331 "parser.y"
                               {if (isRead == 1) {int arrStart = arrayStartToString(); int readArrIndex = atoi(yytext) - arrStart; char stringArrIdx[100];} if (hasPassedParams) {variable = 0;} strcpy(expressionValue, yytext);  (yyval.type) = 0; if (isLhsArr) {globalShowArrayIndex = atoi(yytext);} addNumberToTempStack("int"); if (isAssignmentArray == 0) {} else {globalArrayIndex = atoi(yytext);}}
#line 1872 "parser.tab.c"
    break;

  case 91: /* ArithExpr: REALNUMBER  */
#line 332 "parser.y"
                                {if (hasPassedParams) {variable = 0;} strcpy(expressionValue, yytext);  (yyval.type) = 1; addNumberToTempStack("double");}
#line 1878 "parser.tab.c"
    break;

  case 92: /* ArithExpr: ArithExpr '+' ArithExpr  */
#line 333 "parser.y"
                                             {if (hasPassedParams) {variable = 0;}; checkArithExprTypesRegular((yyvsp[-2].type), (yyvsp[0].type)); (yyval.type) = solveExpressionType((yyvsp[-2].type), (yyvsp[0].type)); translateAssignment('+');}
#line 1884 "parser.tab.c"
    break;

  case 93: /* ArithExpr: ArithExpr '-' ArithExpr  */
#line 334 "parser.y"
                                             {if (hasPassedParams) {variable = 0;}; checkArithExprTypesRegular((yyvsp[-2].type), (yyvsp[0].type)); (yyval.type) = solveExpressionType((yyvsp[-2].type), (yyvsp[0].type)); translateAssignment('-');}
#line 1890 "parser.tab.c"
    break;

  case 94: /* ArithExpr: ArithExpr '*' ArithExpr  */
#line 335 "parser.y"
                                             {if (hasPassedParams) {variable = 0;}; checkArithExprTypesRegular((yyvsp[-2].type), (yyvsp[0].type)); (yyval.type) = solveExpressionType((yyvsp[-2].type), (yyvsp[0].type)); translateAssignment('*');}
#line 1896 "parser.tab.c"
    break;

  case 95: /* ArithExpr: ArithExpr '/' ArithExpr  */
#line 336 "parser.y"
                                             {if (hasPassedParams) {variable = 0;}; checkArithExprTypesRegular((yyvsp[-2].type), (yyvsp[0].type)); (yyval.type) = solveExpressionType((yyvsp[-2].type), (yyvsp[0].type)); translateAssignment('/');}
#line 1902 "parser.tab.c"
    break;

  case 96: /* ArithExpr: ArithExpr DIV ArithExpr  */
#line 337 "parser.y"
                                             {if (hasPassedParams) {variable = 0;}; checkArithExprTypes((yyvsp[-2].type), (yyvsp[0].type)); translateAssignment('d'); (yyval.type) = 0;}
#line 1908 "parser.tab.c"
    break;

  case 97: /* ArithExpr: ArithExpr MOD ArithExpr  */
#line 338 "parser.y"
                                             {if (hasPassedParams) {variable = 0;}; checkArithExprTypes((yyvsp[-2].type), (yyvsp[0].type)); translateAssignment('m'); (yyval.type) = 0;}
#line 1914 "parser.tab.c"
    break;

  case 98: /* $@27: %empty  */
#line 339 "parser.y"
                         {isTempNegation = 1;}
#line 1920 "parser.tab.c"
    break;

  case 99: /* ArithExpr: '-' $@27 ArithExpr  */
#line 339 "parser.y"
                                                         { isTempNegation = 0; (yyval.type) = (yyvsp[0].type);}
#line 1926 "parser.tab.c"
    break;

  case 100: /* ArithExpr: '(' ArithExpr ')'  */
#line 340 "parser.y"
                                       {(yyval.type) = (yyvsp[-1].type);}
#line 1932 "parser.tab.c"
    break;

  case 101: /* IdArrayRule: IDENTIFIER  */
#line 343 "parser.y"
                                {checkUndeclaredId(1); strcpy(arrayId, identifier); if (isRead == 1) {strcat(readNestedArrays, arrayId); strcat(readNestedArrays, "["); readNestedArraysIdx++;} strcpy(nestedArrays[nestedArraysIdx], arrayId); variable2 = variable; isAssignmentArray = 1; nestedArraysIdx++;}
#line 1938 "parser.tab.c"
    break;


#line 1942 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 346 "parser.y"


void removeFromScope() {
  free(scopeStack[scopeLevel]);
  scopeStack[scopeLevel] = malloc(1000 * sizeof(IdentifierInfo));

  for (int i = 0; i < 1000; i++) {
    scopeStack[scopeLevel][i].created = 0;
    scopeStack[scopeLevel][i].passedParametersLength = 0;
  }

  scopeLevel--;
}

void addIdIndex() {
  checkRedeclaration();

  int idx = insertOrRetrieveStringTable(identifier);

  // fprintf(outputFile, "%s\n", identifier);

  indexArr[count] = idx;
  count++;

  globalIdIndex = count;
}

void addIdInfo(IdType type) {
  IdentifierInfo idInfo;

  if (isFunctionVariable == 0) {
    translateDeclarationsTypes(type); 
  }

  for (int i = 0; i < count; i++) {

    strcpy(idInfo.name, identifier);
    idInfo.created = 1;
    idInfo.location = linenr;
    idInfo.type = type;

    scopeStack[scopeLevel][indexArr[i]] = idInfo;

    if (i == count - 1) {
      isLast = 1;
    }

    translateDeclarations(indexArr[i], 0, type, 0);
  }

  isLast = 0;
  count = 0;
}

void addArrayInfo(IdType type, int arrayType, int start, int end) {
  IdentifierInfo idInfo;

  translateDeclarationsTypes(arrayType);

  for (int i = 0; i < count; i++) {

    strcpy(idInfo.name, arrayId);
    idInfo.arrayType = arrayType;
    idInfo.type = type;
    idInfo.created = 1;
    idInfo.variable = 0;
    idInfo.location = linenr;
    idInfo.start = start;
    idInfo.end = end;
    idInfo.readNestedArraysIdIndex = 0;

    scopeStack[scopeLevel][indexArr[i]] = idInfo;

    if (i == count - 1) {
      isLast = 1;
    }

    translateDeclarations(indexArr[i], 0, arrayType, 1);
  }

  isLast = 0;
  count = 0;
}

void addToFuncIndexes() {
  int idx = lookupStringTable(identifier);
  funcIdIndexes[funcIdIndexesLength] = idx;

  funcIdIndexesLength++;
}

void initializeFunction() {
  strcpy(functionId, identifier);
  addIdIndex();
  scopeLevel++;
  count = 0;
}

void addFunctionInfo(IdType type, IdType arrayType) {

  int idx = insertOrRetrieveStringTable(functionId);

  IdentifierInfo id;

  strcpy(id.name, functionId);
  id.arrayType = arrayType;
  id.type = type;
  id.created = 1;
  id.variable = 0;

  id.parameters = malloc(paramsListLength * sizeof(IdentifierInfo));
  
  for (int i = 0; i < paramsListLength; i++) {    
    id.parameters[i] = parametersList[i];
  }

  id.paramsLength = paramsListLength;

  scopeStack[scopeLevel - 1][idx] = id;

  translateFunction(idx, type, parametersList, paramsListLength);

  count = 0;
  paramsListLength = 0;
  paramsCount = 0;
}

void addToParamsList(IdType type, IdType arrayType, int variable) {
  IdentifierInfo paramIdInfo;

  for (int i = 0; i < paramsCount; i++) {

    strcpy(paramIdInfo.name, identifier);
    paramIdInfo.arrayType = arrayType;
    paramIdInfo.variable = variable;
    paramIdInfo.location = linenr;
    paramIdInfo.type = type;
    paramIdInfo.created = 1;

    parametersList[paramsListLength] = paramIdInfo;
    paramsListLength++;
  }
}

void addToPassedParamsList(IdType type) {
  if (hasPassedParams == 0) {
    return;
  }

  PassedParameter param;

  strcpy(param.name, identifier);
  param.type = type;
  param.variable = variable;
  param.isArrayWithIndex = 0;
  param.nestedParamsIdx = 0;

  if (type == 5) {
    param.nestedParamsIdx = nestedArraysIdx;
    param.isArrayWithIndex = 1;
    param.passedArrayIdx = globalArrayIndex;
  }

  int idx = funcIdIndexes[funcIdIndexesLength - 1];

  scopeStack[0][idx].passedParameters[scopeStack[0][idx].passedParametersLength] = param;
  scopeStack[0][idx].passedParametersLength++;

  variable = 1;
}

int returnFunctionType() {
  int idx = funcIdIndexes[funcIdIndexesLength];
  variable = 0;
  return scopeStack[0][idx].type;
}

int returnIdentifierType() {
  int idx = lookupStringTable(identifier);

  if (scopeStack[scopeLevel][idx].created == 1) {
    return scopeStack[scopeLevel][idx].type;
  }

  return scopeStack[scopeLevel - 1][idx].type;
}

int returnArrayType() {
  int idx = lookupStringTable(arrayId);

  variable = 1;

  if (scopeStack[scopeLevel][idx].created == 1) {
    return scopeStack[scopeLevel][idx].arrayType;
  }

  return scopeStack[scopeLevel - 1][idx].arrayType;
}

void checkArithExprTypesRegular(int expression1, int expression2) {
  if ((expression1 != 0 && expression1 != 1 && expression1 != 3 && expression1 != 4) || 
  (expression2 != 0 && expression2 != 1 && expression2 != 3 && expression2 != 4)) {
    // yyerror("ERROR: EXPRESSIONS HAVE DIFFERENT TYPES");
  }
}

int solveExpressionType(int expression1, int expression2) {
  if ((expression1 == 0 || expression1 == 3) && (expression2 == 0 || expression2 == 3)) {
    return 0;
  }

  if (((expression1 == 1 || expression1 == 4) && (expression2 == 0 || expression2 == 3)) ||
  ((expression1 == 0 || expression1 == 3) && (expression2 == 1 || expression2 == 4))) {
    return 1;
  }

  if ((expression1 == 1 || expression1 == 4) && (expression2 == 1 || expression2 == 4)) {
    return 1;
  }

//   yyerror("ERROR: EXPRESSIONS HAVE DIFFERENT TYPES");
}

void checkArithExprTypes(int expression1, int expression2) {
  if ((expression1 != 0 && expression1 != 3) || (expression2 != 0 && expression2 != 3)) {
    // yyerror("ERROR: EXPRESSIONS HAVE DIFFERENT TYPES");
  }
}

void checkRedeclaration() {
  int idx = lookupStringTable(identifier);

  if (idx == -1) {
    return;
  } 
    
  if (scopeStack[scopeLevel][idx].created == 1) {
    // yyerror("ERROR: IDENTIFIER ALREADY DECLARED");
  }
}

void checkUndeclaredId(int isRhs) {
  int idx = lookupStringTable(identifier);

  if (idx == -1) {
    // yyerror("ERROR: IDENTIFIER UNDECLARED");
  }

  if (scopeStack[scopeLevel][idx].created == 1) {
    if (!isRhs) {
      checkConstRedeclaration(scopeLevel, idx);
    }

    return;
  }

  if (scopeLevel - 1 < 0) {
    // yyerror("ERROR: IDENTIFIER UNDECLARED");
  }

  if (scopeStack[scopeLevel - 1][idx].created == 1) {
    if (!isRhs) {
      checkConstRedeclaration(scopeLevel - 1, idx);
    }

    return;
  }

//   yyerror("ERROR: IDENTIFIER UNDECLARED");
}

void checkConstRedeclaration(int scope, int i) {
  IdType type = scopeStack[scope][i].type;

  if (type == CONST_INTEGER_TYPE || type == CONST_REAL_TYPE) {
    // yyerror("ERROR: CONSTANT ALREADY DECLARED");
  }
}

void checkFuncParam() {
  int idx = funcIdIndexes[funcIdIndexesLength];
  
  IdentifierInfo functionIdInfo = scopeStack[0][idx];

  if (functionIdInfo.paramsLength != functionIdInfo.passedParametersLength) {

    // yyerror("ERROR: NOT ENOUGH PARAMETERS PASSED");
  }

  for (int i = 0; i < functionIdInfo.paramsLength; i++) {

    // fprintf(outputFile, "%d %d\n", functionIdInfo.parameters[i].variable, functionIdInfo.passedParameters[i].variable);
    
    if (!((functionIdInfo.parameters[i].type == 0 && (functionIdInfo.passedParameters[i].type == 0 || functionIdInfo.passedParameters[i].type == 3))
    || (functionIdInfo.parameters[i].type == 1 && (functionIdInfo.passedParameters[i].type == 1 || functionIdInfo.passedParameters[i].type == 4))
    || (functionIdInfo.parameters[i].type == 1 && functionIdInfo.passedParameters[i].type == 0 || functionIdInfo.passedParameters[i].type == 3) 
    || (functionIdInfo.parameters[i].type == 5 && functionIdInfo.passedParameters[i].type == 5))) {
      // yyerror("ERROR: PARAMETERS HAVE INVALID TYPE");
    }
  
    if (functionIdInfo.parameters[i].variable == 1 && functionIdInfo.parameters[i].variable != functionIdInfo.passedParameters[i].variable) {
    //   yyerror("ERROR: PASSED PARAMETER IS NOT A VARIABLE");
    }

    if (functionIdInfo.parameters[i].variable == 1 && (functionIdInfo.passedParameters[i].type == 3 || functionIdInfo.passedParameters[i].type == 4)) {
    //   yyerror("ERROR: CONSTANTS CAN ONLY BE PASSED BY VALUE");
    }
  }

  scopeStack[0][idx].passedParametersLength = 0;
}

void checkAssignmentTypes(int expression1, int expression2) {
  // fprintf(outputFile, "%d %d\n", expression1, expression2);
  if ((expression1 == 0 && expression2 == 3) || (expression1 == 1 && expression2 == 4)) {
    return;
  }

  if (expression1 == 1 && (expression2 == 0 || expression2 == 3)) {
    return;
  }

   if (expression1 == 0 && (expression2 == 1 || expression2 == 3)) {
    return;
  }

  if (expression1 == expression2) {
    if (expression1 == 5) {
    //   yyerror("ERROR: ARRAYS CANNOT BE ASSIGNED TO OTHER ARRAYS");
    }
    return;
  }
  
//   yyerror("ERROR: ASSIGNMENT WITH INCORRECT TYPES");
}

void checkLeftSide() {
  int idx = lookupStringTable(identifier);

  if (scopeStack[scopeLevel][idx].created == 1) {

    IdentifierInfo id = scopeStack[scopeLevel][idx];

    if (id.type == 2) {
    //   yyerror("ERROR: VALUES CANNOT BE ASSIGNED TO PROCEDURES");
    }

    return;
  }

  if (scopeStack[scopeLevel - 1][idx].created == 1) {

    IdentifierInfo id = scopeStack[scopeLevel - 1][idx];

    if (id.type == 2) {
    //   yyerror("ERROR: VALUES CANNOT BE ASSIGNED TO PROCEDURES");
    }
  }
}


void printReadNestedArraysBrackets(int index) {
  for (int i = 0; i < index; i++) {
    fprintf(outputFile, "]");
  }
}

void printReadStatement() {

  if (isRead == 1) {
    fprintf(outputFile, "scanf(\"");

    for (int i = 0; i < readIdx; i++) {

      if (i != readIdx - 1) {

        if (readArrIndexes[i].tempVarType == 0) {
          fprintf(outputFile, "%%d ");
        } else if (readArrIndexes[i].tempVarType == 1) {
          fprintf(outputFile, "%%lf ");
        }

      } else {

        if (readArrIndexes[i].tempVarType == 0) {
          fprintf(outputFile, "%%d\", ");
        } else if (readArrIndexes[i].tempVarType == 1) {
          fprintf(outputFile, "%%lf\", ");
        } 
      }
    }

    for (int i = 0; i < readIdx; i++) {
      if (i != readIdx - 1) {
        fprintf(outputFile, "_t%d, ", readArrIndexes[i].tempVarIdx);
      } else {
        fprintf(outputFile, "_t%d", readArrIndexes[i].tempVarIdx);
      }
    }


    fprintf(outputFile, ");\n");
  }
}

void printWriteStatement() {
  if (isWrite == 1) {

    fprintf(outputFile, "printf(\"");

    for (int i = 0; i < writeIdx; i++) {

      if (i != writeIdx - 1) {

        if (writeArrIndexes[i].tempVarType == 0) {
          fprintf(outputFile, "%%d ");
        } else if (writeArrIndexes[i].tempVarType == 1) {
          fprintf(outputFile, "%%lf ");
        }

      } else {

        if (writeArrIndexes[i].tempVarType == 0) {
          fprintf(outputFile, "%%d\\n\", ");
        } else if (writeArrIndexes[i].tempVarType == 1) {
          fprintf(outputFile, "%%lf\\n\", ");
        }
      }

    }

    for (int i = 0; i < writeIdx; i++) {
      if (i != writeIdx - 1) {
        fprintf(outputFile, "_t%d, ", writeArrIndexes[i].tempVarIdx);
      } else {
        fprintf(outputFile, "_t%d", writeArrIndexes[i].tempVarIdx);
      }
    }

    fprintf(outputFile, ");\n");
  }
}

int arrayStartToString() {
  int idx = lookupStringTable(arrayId);
  IdentifierInfo arrayIden;

  if (scopeStack[scopeLevel][idx].created == 1) {
    arrayIden = scopeStack[scopeLevel][idx];
  } else if (scopeStack[scopeLevel - 1][idx].created == 1) {
    arrayIden = scopeStack[scopeLevel - 1][idx];
  }

  return arrayIden.start;
}

void getGlobalArrayStart() {

  int idx = lookupStringTable(arrayId);
  IdentifierInfo arrayIden;

  if (scopeStack[scopeLevel][idx].created == 1) {
    arrayIden = scopeStack[scopeLevel][idx];
  } else if (scopeStack[scopeLevel - 1][idx].created == 1) {
    arrayIden = scopeStack[scopeLevel - 1][idx];
  }

  globalArrayStart = arrayIden.start;
}

void resetFuncParamArrayTranslate() {
  funcParamsRangesArrIdx = 0;
  currentFuncParamsRangesArrIdx = 0;

  for (int i = 0; i < 100; i++) {

    funcRangesIndexes[i] = 1;

    for (int j = 0; j < 100; j++) {
      funcParamsRangesArr[i][j] = 0;
    }
  }
}

void addNumberToTempStack(char *type) {
  if (isRead == 0) {

    if (isProcedureCall == 0) {

      if (isAssignmentArray == 0) {
        if (isTempNegation == 1) {
          fprintf(outputFile, "%s _t%d = -%s;\n", type, tempVarCount, expressionValue);
        } else {
          fprintf(outputFile, "%s _t%d = %s;\n", type, tempVarCount, expressionValue);
        }
        
      } else {

        getGlobalArrayStart();

        int val = atoi(expressionValue);
        fprintf(outputFile, "%s _t%d = %d;\n", type, tempVarCount, val - globalArrayStart);
      }
      

      tempVarStack[tempVarStackCount].tempCount = tempVarCount;

      if (isFuncAssignmentHelper > 0 && isAssignmentArray != 1) {

        currentFuncParamsRangesArrIdx = funcRangesIndexes[funcParamsRangesArrIdx - 1];

        funcParamsRangesArr[funcParamsRangesArrIdx - 1][currentFuncParamsRangesArrIdx - 1] = tempVarCount;

        currentFuncParamsRangesArrIdx++;
        funcRangesIndexes[funcParamsRangesArrIdx - 1] = currentFuncParamsRangesArrIdx;
      }

      if (strcmp(type, "int") == 0) {
        tempVarStack[tempVarStackCount].tempType = 0; 
      } else {
        tempVarStack[tempVarStackCount].tempType = 1;
      }
      
      tempVarCount++; 
      tempVarStackCount++;

    } else {

      if (isAssignmentArray == 0) {
        if (isTempNegation == 1) {
          fprintf(outputFile, "%s _t%d = -%s;\n", type, tempVarCount, expressionValue);
        } else {
          fprintf(outputFile, "%s _t%d = %s;\n", type, tempVarCount, expressionValue);
        }
      } else {

        getGlobalArrayStart();

        int val = atoi(expressionValue);
        fprintf(outputFile, "%s _t%d = %d;\n", type, tempVarCount, val - globalArrayStart);
      }
      

      tempVarStack[tempVarStackCount].tempCount = tempVarCount;

      if (isFuncAssignmentHelper > 0  && isAssignmentArray != 1) {

        currentFuncParamsRangesArrIdx = funcRangesIndexes[funcParamsRangesArrIdx - 1];

        funcParamsRangesArr[funcParamsRangesArrIdx - 1][currentFuncParamsRangesArrIdx - 1] = tempVarCount;

        currentFuncParamsRangesArrIdx++;
        funcRangesIndexes[funcParamsRangesArrIdx - 1] = currentFuncParamsRangesArrIdx;
      }

      if (strcmp(type, "int") == 0) {
        tempVarStack[tempVarStackCount].tempType = 0; 
      } else {
        tempVarStack[tempVarStackCount].tempType = 1;
      }
      
      tempVarCount++; 
      tempVarStackCount++;
    } 
  } else {

    if (isAssignmentArray == 0) {
      fprintf(outputFile, "%s _t%d = %s;\n", type, tempVarCount, expressionValue);
    } else {

      getGlobalArrayStart();

      int val = atoi(expressionValue);
      fprintf(outputFile, "%s _t%d = %d;\n", type, tempVarCount, val - globalArrayStart);
    }
    

    tempVarStack[tempVarStackCount].tempCount = tempVarCount;

    if (isFuncAssignmentHelper > 0 && isAssignmentArray != 1) {

      currentFuncParamsRangesArrIdx = funcRangesIndexes[funcParamsRangesArrIdx - 1];

      funcParamsRangesArr[funcParamsRangesArrIdx - 1][currentFuncParamsRangesArrIdx - 1] = tempVarCount;

      currentFuncParamsRangesArrIdx++;
      funcRangesIndexes[funcParamsRangesArrIdx - 1] = currentFuncParamsRangesArrIdx;
    }

    if (strcmp(type, "int") == 0) {
      tempVarStack[tempVarStackCount].tempType = 0; 
    } else {
      tempVarStack[tempVarStackCount].tempType = 1;
    }
    
    tempVarCount++; 
    tempVarStackCount++;
  }
}

void addIdToTempStack() {

  if (isRead == 0) {

    if (isFuncAssignment == 0) {

      if (isProcedureCall == 0) {

        int idx = lookupStringTable(identifier);
        IdentifierInfo id;

        if (scopeStack[scopeLevel][idx].created == 1) {
          id = scopeStack[scopeLevel][idx];
        } else if (scopeStack[scopeLevel - 1][idx].created == 1) {
          id = scopeStack[scopeLevel - 1][idx];
        }

        if (isFuncAssignmentHelper > 0) {
          currentFuncParamsRangesArrIdx = funcRangesIndexes[funcParamsRangesArrIdx - 1];

          funcParamsRangesArr[funcParamsRangesArrIdx - 1][currentFuncParamsRangesArrIdx - 1] = tempVarCount;

          currentFuncParamsRangesArrIdx++;
          funcRangesIndexes[funcParamsRangesArrIdx - 1] = currentFuncParamsRangesArrIdx;
        }

        int idType = id.type;

        if (idType == 0) {
          if (isTempNegation == 1) {
            fprintf(outputFile, "int _t%d = -%s;\n", tempVarCount, identifier); 
          } else {
            fprintf(outputFile, "int _t%d = %s;\n", tempVarCount, identifier); 
          }
          
        } else if (idType == 1) {
          if (isTempNegation == 1) {
            fprintf(outputFile, "double _t%d = -%s;\n", tempVarCount, identifier);
          } else {
            fprintf(outputFile, "double _t%d = %s;\n", tempVarCount, identifier);
          }
          
        } else if (idType == 3) {
          if (isTempNegation == 1) {
            fprintf(outputFile, "int _t%d = -%s;\n", tempVarCount, identifier);
          } else {
            fprintf(outputFile, "int _t%d = %s;\n", tempVarCount, identifier);
          }
          
        } else if (idType == 4) {
          if (isTempNegation == 1) {
            fprintf(outputFile, "double _t%d = -%s;\n", tempVarCount, identifier);
          } else {
            fprintf(outputFile, "double _t%d = %s;\n", tempVarCount, identifier);
          }
          
        } else if (idType == 5) {

          if (id.arrayType == 0) {
            fprintf(outputFile, "int *_t%d = %s;\n", tempVarCount, identifier);
          } else if (id.arrayType == 1) {
            fprintf(outputFile, "double *_t%d = %s;\n", tempVarCount, identifier);
          }
        }
        
        tempVarStack[tempVarStackCount].tempCount = tempVarCount;

        if (idType == 0) {
          tempVarStack[tempVarStackCount].tempType = 0; 
        } else if (idType == 1) {
          tempVarStack[tempVarStackCount].tempType = 1;
        } else if (idType == 5) {

          if (id.arrayType == 0) {
            tempVarStack[tempVarStackCount].tempType = 0;
          } else if (id.arrayType == 1) {
            tempVarStack[tempVarStackCount].tempType = 1;
          }
        }
        
        tempVarCount++; 
        tempVarStackCount++;                               
      } else {

        int idx = lookupStringTable(identifier);
        IdentifierInfo id;

        if (scopeStack[scopeLevel][idx].created == 1) {
          id = scopeStack[scopeLevel][idx];
        } else if (scopeStack[scopeLevel - 1][idx].created == 1) {
          id = scopeStack[scopeLevel - 1][idx];
        }

        if (isFuncAssignmentHelper > 0) {
          currentFuncParamsRangesArrIdx = funcRangesIndexes[funcParamsRangesArrIdx - 1];

          funcParamsRangesArr[funcParamsRangesArrIdx - 1][currentFuncParamsRangesArrIdx - 1] = tempVarCount;

          currentFuncParamsRangesArrIdx++;
          funcRangesIndexes[funcParamsRangesArrIdx - 1] = currentFuncParamsRangesArrIdx;
        }

        int idType = id.type;

        if (idType == 0) {
          if (isTempNegation == 1) {
            fprintf(outputFile, "int _t%d = -%s;\n", tempVarCount, identifier); 
          } else {
            fprintf(outputFile, "int _t%d = %s;\n", tempVarCount, identifier); 
          }
          
        } else if (idType == 1) {
          if (isTempNegation == 1) {
            fprintf(outputFile, "double _t%d = -%s;\n", tempVarCount, identifier);
          } else {
            fprintf(outputFile, "double _t%d = %s;\n", tempVarCount, identifier);
          }
          
        } else if (idType == 3) {
          if (isTempNegation == 1) {
            fprintf(outputFile, "int _t%d = -%s;\n", tempVarCount, identifier);
          } else {
            fprintf(outputFile, "int _t%d = %s;\n", tempVarCount, identifier);
          }
          
        } else if (idType == 4) {
          if (isTempNegation == 1) {
            fprintf(outputFile, "double _t%d = -%s;\n", tempVarCount, identifier);
          } else {
            fprintf(outputFile, "double _t%d = %s;\n", tempVarCount, identifier);
          }
          
        } else if (idType == 5) {

          if (id.arrayType == 0) {
            fprintf(outputFile, "int *_t%d = %s;\n", tempVarCount, identifier);
          } else if (id.arrayType == 1) {
            fprintf(outputFile, "double *_t%d = %s;\n", tempVarCount, identifier);
          }
        }
        
        tempVarStack[tempVarStackCount].tempCount = tempVarCount;

        if (idType == 0) {
          tempVarStack[tempVarStackCount].tempType = 0; 
        } else if (idType == 1) {
          tempVarStack[tempVarStackCount].tempType = 1;
        } else if (idType == 5) {

          if (id.arrayType == 0) {
            tempVarStack[tempVarStackCount].tempType = 0;
          } else if (id.arrayType == 1) {
            tempVarStack[tempVarStackCount].tempType = 1;
          }
        }
        
        tempVarCount++; 
        tempVarStackCount++;

        writeArrIndexes[writeIdx].tempVarType = tempVarStack[tempVarStackCount - 1].tempType;
        writeArrIndexes[writeIdx].tempVarIdx = tempVarCount - 1;
        
      }
    } else {

      if (isProcedureCall == 0) {

        int idx = funcIdIndexes[funcIdIndexesLength];
        IdentifierInfo id;

        if (scopeStack[scopeLevel][idx].created == 1) {
          id = scopeStack[scopeLevel][idx];
        } else if (scopeStack[scopeLevel - 1][idx].created == 1) {
          id = scopeStack[scopeLevel - 1][idx];
        }

        if (isFuncAssignmentHelper > 0) {

          currentFuncParamsRangesArrIdx = funcRangesIndexes[funcParamsRangesArrIdx - 2];

          funcParamsRangesArr[funcParamsRangesArrIdx - 2][currentFuncParamsRangesArrIdx - 1] = tempVarCount;

          currentFuncParamsRangesArrIdx++;
          funcRangesIndexes[funcParamsRangesArrIdx - 2] = currentFuncParamsRangesArrIdx;
        }

        int idType = id.type;

        if (idType == 0) {
          fprintf(outputFile, "int _t%d = %s(", tempVarCount, id.name); 
        } else if (idType == 1) {
          fprintf(outputFile, "double _t%d = %s(", tempVarCount, id.name);
        } else if (idType == 3) {
          fprintf(outputFile, "int _t%d = %s(", tempVarCount, id.name);
        } else if (idType == 4) {
          fprintf(outputFile, "double _t%d = %s(", tempVarCount, id.name);
        }

        procedureCallIndex = funcRangesIndexes[funcParamsRangesArrIdx - 1] - 1;

        for (int i = 0; i < funcRangesIndexes[funcParamsRangesArrIdx - 1] - 1; i++) {
          if (i != funcRangesIndexes[funcParamsRangesArrIdx - 1] - 2) {
            fprintf(outputFile, "_t%d, ", funcParamsRangesArr[funcParamsRangesArrIdx - 1][i]);
          } else {
            fprintf(outputFile, "_t%d);\n", funcParamsRangesArr[funcParamsRangesArrIdx - 1][i]);
          }
        }

        tempVarStack[tempVarStackCount].tempCount = tempVarCount;

        if (idType == 0) {
          tempVarStack[tempVarStackCount].tempType = 0;
        } else if (idType == 1) {
          tempVarStack[tempVarStackCount].tempType = 1;
        }

        tempVarCount++; 
        tempVarStackCount++;

      } else {

        int idx = funcIdIndexes[funcIdIndexesLength];
        IdentifierInfo id;

        if (scopeStack[scopeLevel][idx].created == 1) {
          id = scopeStack[scopeLevel][idx];
        } else if (scopeStack[scopeLevel - 1][idx].created == 1) {
          id = scopeStack[scopeLevel - 1][idx];
        }

        if (isFuncAssignmentHelper > 0) {

          currentFuncParamsRangesArrIdx = funcRangesIndexes[funcParamsRangesArrIdx - 2];

          funcParamsRangesArr[funcParamsRangesArrIdx - 2][currentFuncParamsRangesArrIdx - 1] = tempVarCount;

          currentFuncParamsRangesArrIdx++;
          funcRangesIndexes[funcParamsRangesArrIdx - 2] = currentFuncParamsRangesArrIdx;
        }

        int idType = id.type;

        if (isWrite == 1) {
          if (idType == 0) {
            fprintf(outputFile, "int _t%d = %s(", tempVarCount, id.name); 
          } else if (idType == 1) {
            fprintf(outputFile, "double _t%d = %s(", tempVarCount, id.name);
          } else if (idType == 3) {
            fprintf(outputFile, "int _t%d = %s(", tempVarCount, id.name);
          } else if (idType == 4) {
            fprintf(outputFile, "double _t%d = %s(", tempVarCount, id.name);
          }
        }

        if (isProcedureCallHelper == 1) {
          fprintf(outputFile, "%s(", id.name);

          for (int i = procedureCallIndex; i < funcRangesIndexes[funcParamsRangesArrIdx - 1] - 1; i++) {

            if (isWrite == 1) {
              writeIdx--;
            }

            if (i != funcRangesIndexes[funcParamsRangesArrIdx - 1] - 2) {
              fprintf(outputFile, "_t%d, ", funcParamsRangesArr[funcParamsRangesArrIdx - 1][i]);
            } else {
              fprintf(outputFile, "_t%d);\n", funcParamsRangesArr[funcParamsRangesArrIdx - 1][i]);
            }
          }

          procedureCallIndex = funcRangesIndexes[funcParamsRangesArrIdx - 1] - 1;

        } else {
          for (int i = 0; i < funcRangesIndexes[funcParamsRangesArrIdx - 1] - 1; i++) {

            if (isWrite == 1) {
              writeIdx--;
            }

            if (i != funcRangesIndexes[funcParamsRangesArrIdx - 1] - 2) {
              fprintf(outputFile, "_t%d, ", funcParamsRangesArr[funcParamsRangesArrIdx - 1][i]);
            } else {
              fprintf(outputFile, "_t%d);\n", funcParamsRangesArr[funcParamsRangesArrIdx - 1][i]);
            }
          }

          procedureCallIndex = funcRangesIndexes[funcParamsRangesArrIdx - 1] - 1;

          tempVarStack[tempVarStackCount].tempCount = tempVarCount;

          if (idType == 0) {
            tempVarStack[tempVarStackCount].tempType = 0;
          } else if (idType == 1) {
            tempVarStack[tempVarStackCount].tempType = 1;
          }

          tempVarCount++; 
          tempVarStackCount++;

          writeArrIndexes[writeIdx].tempVarType = tempVarStack[tempVarStackCount - 1].tempType;
          writeArrIndexes[writeIdx].tempVarIdx = tempVarCount - 1;
        }
      }
    }
  } else {
    int idx = lookupStringTable(identifier);
    IdentifierInfo id;

    if (scopeStack[scopeLevel][idx].created == 1) {
      id = scopeStack[scopeLevel][idx];
    } else if (scopeStack[scopeLevel - 1][idx].created == 1) {
      id = scopeStack[scopeLevel - 1][idx];
    }

    int idType = id.type;

    if (idType == 0) {
      fprintf(outputFile, "int *_t%d = &%s;\n", tempVarCount, identifier); 
    } else if (idType == 1) {
      fprintf(outputFile, "double *_t%d = &%s;\n", tempVarCount, identifier);
    }

    readArrIndexes[readIdx].tempVarIdx = tempVarCount;
    readArrIndexes[readIdx].tempVarType = idType;
    
    tempVarStack[tempVarStackCount].tempCount = tempVarCount;

    if (idType == 0) {
      tempVarStack[tempVarStackCount].tempType = 0; 
    } else if (idType == 1) {
      tempVarStack[tempVarStackCount].tempType = 1;
    }
    
    tempVarCount++; 
    tempVarStackCount++; 
  }
}

void addArrayToTempStack(int arrIndex) {

  if (isRead == 0) {

    if (isFuncAssignment == 0) {

      if (isProcedureCall == 0) {

        if (nestedArraysIdx > 0) {

          int idx = lookupStringTable(nestedArrays[0]);
          IdentifierInfo firstId;

          if (scopeStack[scopeLevel][idx].created == 1) {
            firstId = scopeStack[scopeLevel][idx];
          } else if (scopeStack[scopeLevel - 1][idx].created == 1) {
            firstId = scopeStack[scopeLevel - 1][idx];
          }

          for (int i = 0; i < nestedArraysIdx; i++) {

            if (firstId.arrayType == 0) {
              fprintf(outputFile, "int *_t%d = ", tempVarCount); 
            } else if (firstId.arrayType  == 1) {
              fprintf(outputFile, "double *_t%d = ", tempVarCount);
            }

            fprintf(outputFile, "%s;\n", nestedArrays[0]);


            tempVarStack[tempVarStackCount].tempCount = tempVarCount;

            if (firstId.arrayType  == 0) {
              tempVarStack[tempVarStackCount].tempType = 0; 
            } else if (firstId.arrayType  == 1) {
              tempVarStack[tempVarStackCount].tempType = 1;
            }
            
            tempVarCount++; 
            tempVarStackCount++;


            fprintf(outputFile, "int _t%d = _t%d;\n", tempVarCount, tempVarCount - 2);

            tempVarStack[tempVarStackCount].tempCount = tempVarCount;

            if (firstId.arrayType  == 0) {
              tempVarStack[tempVarStackCount].tempType = 0; 
            } else if (firstId.arrayType  == 1) {
              tempVarStack[tempVarStackCount].tempType = 1;
            }
            
            tempVarCount++; 
            tempVarStackCount++;


            if (firstId.arrayType == 0) {
              fprintf(outputFile, "int *_t%d = _t%d + _t%d;\n", tempVarCount, tempVarCount - 2, tempVarCount - 1); 
            } else if (firstId.arrayType  == 1) {
              fprintf(outputFile, "double *_t%d = _t%d + _t%d;\n", tempVarCount, tempVarCount - 2, tempVarCount - 1);
            }


            tempVarStack[tempVarStackCount].tempCount = tempVarCount;

            if (firstId.arrayType  == 0) {
              tempVarStack[tempVarStackCount].tempType = 0; 
            } else if (firstId.arrayType  == 1) {
              tempVarStack[tempVarStackCount].tempType = 1;
            }
            
            tempVarCount++; 
            tempVarStackCount++;


            if (firstId.arrayType == 0) {
              fprintf(outputFile, "int _t%d = *_t%d;\n", tempVarCount, tempVarCount - 1); 
            } else if (firstId.arrayType  == 1) {
              fprintf(outputFile, "double _t%d = *_t%d;\n", tempVarCount, tempVarCount - 1);
            }

            tempVarStack[tempVarStackCount].tempCount = tempVarCount;

            if (firstId.arrayType  == 0) {
              tempVarStack[tempVarStackCount].tempType = 0; 
            } else if (firstId.arrayType  == 1) {
              tempVarStack[tempVarStackCount].tempType = 1;
            }
            
            tempVarCount++; 
            tempVarStackCount++;
          
          }

          if (isFuncAssignmentHelper > 0) {

            currentFuncParamsRangesArrIdx = funcRangesIndexes[funcParamsRangesArrIdx - 1];

            funcParamsRangesArr[funcParamsRangesArrIdx - 1][currentFuncParamsRangesArrIdx - 1] = tempVarCount - 1;

            currentFuncParamsRangesArrIdx++;
            funcRangesIndexes[funcParamsRangesArrIdx - 1] = currentFuncParamsRangesArrIdx;
          }

        }
      } else {
        if (nestedArraysIdx > 0) {

          int idx = lookupStringTable(nestedArrays[0]);
          IdentifierInfo firstId;

          if (scopeStack[scopeLevel][idx].created == 1) {
            firstId = scopeStack[scopeLevel][idx];
          } else if (scopeStack[scopeLevel - 1][idx].created == 1) {
            firstId = scopeStack[scopeLevel - 1][idx];
          }

          for (int i = 0; i < nestedArraysIdx; i++) {

            if (firstId.arrayType == 0) {
              fprintf(outputFile, "int *_t%d = ", tempVarCount); 
            } else if (firstId.arrayType  == 1) {
              fprintf(outputFile, "double *_t%d = ", tempVarCount);
            }

            fprintf(outputFile, "%s;\n", nestedArrays[0]);


            tempVarStack[tempVarStackCount].tempCount = tempVarCount;

            if (firstId.arrayType  == 0) {
              tempVarStack[tempVarStackCount].tempType = 0; 
            } else if (firstId.arrayType  == 1) {
              tempVarStack[tempVarStackCount].tempType = 1;
            }
            
            tempVarCount++; 
            tempVarStackCount++;


            fprintf(outputFile, "int _t%d = _t%d;\n", tempVarCount, tempVarCount - 2);

            tempVarStack[tempVarStackCount].tempCount = tempVarCount;

            if (firstId.arrayType  == 0) {
              tempVarStack[tempVarStackCount].tempType = 0; 
            } else if (firstId.arrayType  == 1) {
              tempVarStack[tempVarStackCount].tempType = 1;
            }
            
            tempVarCount++; 
            tempVarStackCount++;


            if (firstId.arrayType == 0) {
              fprintf(outputFile, "int *_t%d = _t%d + _t%d;\n", tempVarCount, tempVarCount - 2, tempVarCount - 1); 
            } else if (firstId.arrayType  == 1) {
              fprintf(outputFile, "double *_t%d = _t%d + _t%d;\n", tempVarCount, tempVarCount - 2, tempVarCount - 1);
            }


            tempVarStack[tempVarStackCount].tempCount = tempVarCount;

            if (firstId.arrayType  == 0) {
              tempVarStack[tempVarStackCount].tempType = 0; 
            } else if (firstId.arrayType  == 1) {
              tempVarStack[tempVarStackCount].tempType = 1;
            }
            
            tempVarCount++; 
            tempVarStackCount++;


            if (firstId.arrayType == 0) {
              fprintf(outputFile, "int _t%d = *_t%d;\n", tempVarCount, tempVarCount - 1); 
            } else if (firstId.arrayType  == 1) {
              fprintf(outputFile, "double _t%d = *_t%d;\n", tempVarCount, tempVarCount - 1);
            }

            tempVarStack[tempVarStackCount].tempCount = tempVarCount;

            if (firstId.arrayType  == 0) {
              tempVarStack[tempVarStackCount].tempType = 0; 
            } else if (firstId.arrayType  == 1) {
              tempVarStack[tempVarStackCount].tempType = 1;
            }
            
            tempVarCount++; 
            tempVarStackCount++;
          
          }

          if (isFuncAssignmentHelper > 0) {

            currentFuncParamsRangesArrIdx = funcRangesIndexes[funcParamsRangesArrIdx - 1];

            funcParamsRangesArr[funcParamsRangesArrIdx - 1][currentFuncParamsRangesArrIdx - 1] = tempVarCount - 1;

            currentFuncParamsRangesArrIdx++;
            funcRangesIndexes[funcParamsRangesArrIdx - 1] = currentFuncParamsRangesArrIdx;
          }
          
          writeArrIndexes[writeIdx].tempVarType = tempVarStack[tempVarStackCount - 1].tempType;
          writeArrIndexes[writeIdx].tempVarIdx = tempVarCount - 1;
        }
      }
    }
  } else {
    int idx = lookupStringTable(nestedArrays[0]);
    IdentifierInfo firstId;

    if (scopeStack[scopeLevel][idx].created == 1) {
      firstId = scopeStack[scopeLevel][idx];
    } else if (scopeStack[scopeLevel - 1][idx].created == 1) {
      firstId = scopeStack[scopeLevel - 1][idx];
    }

    for (int i = 0; i < nestedArraysIdx; i++) {

      if (firstId.arrayType == 0) {
        fprintf(outputFile, "int *_t%d = ", tempVarCount); 
      } else if (firstId.arrayType  == 1) {
        fprintf(outputFile, "double *_t%d = ", tempVarCount);
      }

      fprintf(outputFile, "%s;\n", nestedArrays[0]);


      tempVarStack[tempVarStackCount].tempCount = tempVarCount;

      if (firstId.arrayType  == 0) {
        tempVarStack[tempVarStackCount].tempType = 0; 
      } else if (firstId.arrayType  == 1) {
        tempVarStack[tempVarStackCount].tempType = 1;
      }
      
      tempVarCount++; 
      tempVarStackCount++;


      fprintf(outputFile, "int _t%d = _t%d;\n", tempVarCount, tempVarCount - 2);

      tempVarStack[tempVarStackCount].tempCount = tempVarCount;

      if (firstId.arrayType  == 0) {
        tempVarStack[tempVarStackCount].tempType = 0; 
      } else if (firstId.arrayType  == 1) {
        tempVarStack[tempVarStackCount].tempType = 1;
      }
      
      tempVarCount++; 
      tempVarStackCount++;


      if (firstId.arrayType == 0) {
        fprintf(outputFile, "int *_t%d = _t%d + _t%d;\n", tempVarCount, tempVarCount - 2, tempVarCount - 1); 
      } else if (firstId.arrayType  == 1) {
        fprintf(outputFile, "double *_t%d = _t%d + _t%d;\n", tempVarCount, tempVarCount - 2, tempVarCount - 1);
      }


      tempVarStack[tempVarStackCount].tempCount = tempVarCount;

      if (firstId.arrayType  == 0) {
        tempVarStack[tempVarStackCount].tempType = 0; 
      } else if (firstId.arrayType  == 1) {
        tempVarStack[tempVarStackCount].tempType = 1;
      }
      
      tempVarCount++; 
      tempVarStackCount++;

      if (i != nestedArraysIdx - 1) {
        if (firstId.arrayType == 0) {
          fprintf(outputFile, "int _t%d = *_t%d;\n", tempVarCount, tempVarCount - 1); 
        } else if (firstId.arrayType  == 1) {
          fprintf(outputFile, "double _t%d = *_t%d;\n", tempVarCount, tempVarCount - 1);
        }

        tempVarStack[tempVarStackCount].tempCount = tempVarCount;

        if (firstId.arrayType  == 0) {
          tempVarStack[tempVarStackCount].tempType = 0; 
        } else if (firstId.arrayType  == 1) {
          tempVarStack[tempVarStackCount].tempType = 1;
        }
        
        tempVarCount++; 
        tempVarStackCount++;
      }
    }
    
    readArrIndexes[readIdx].tempVarIdx = tempVarCount - 1;
    readArrIndexes[readIdx].tempVarType = tempVarStack[tempVarStackCount - 1].tempType;

  }
}

void getArrayInfoShow() {
  int idx = lookupStringTable(arrayId);

  if (scopeStack[scopeLevel][idx].created == 1) {
    showArray = scopeStack[scopeLevel][idx];
  } else if (scopeStack[scopeLevel - 1][idx].created == 1) {
    showArray = scopeStack[scopeLevel - 1][idx];
  }
}

void showFinalTempAssignment() {
  int arrayStart = showArray.start;

  if (isShowAssignmentFunction == 1) {
    fprintf(outputFile, "return _t%d;\n", tempVarStack[tempVarStackCount - 1].tempCount);
  } else if (isShowAssignment == 0) {
    fprintf(outputFile, "%s = _t%d;\n", globalIdName, tempVarStack[tempVarStackCount - 1].tempCount);
  } else if (isShowAssignment == 1) {
    fprintf(outputFile, "%s[%d] = _t%d;\n", globalIdName, globalShowArrayIndex - arrayStart, tempVarStack[tempVarStackCount - 1].tempCount);
  }
}

void translateComparison(char operator) {

  fprintf(outputFile, "int _t%d = ", tempVarCount);

  switch (operator) {
    case '0':
      fprintf(outputFile, "_t%d %c _t%d", tempVarStack[tempVarStackCount - 2].tempCount, '<', tempVarStack[tempVarStackCount - 1].tempCount);
      break;
    case '1':
      fprintf(outputFile, "_t%d %s _t%d", tempVarStack[tempVarStackCount - 2].tempCount, "<=", tempVarStack[tempVarStackCount - 1].tempCount);
      break;
    case '2':
      fprintf(outputFile, "_t%d %s _t%d", tempVarStack[tempVarStackCount - 2].tempCount, "==", tempVarStack[tempVarStackCount - 1].tempCount);
      break;
    case '3':
      fprintf(outputFile, "_t%d %s _t%d", tempVarStack[tempVarStackCount - 2].tempCount, "<>", tempVarStack[tempVarStackCount - 1].tempCount);
      break;
    case '4':
      fprintf(outputFile, "_t%d %s _t%d", tempVarStack[tempVarStackCount - 2].tempCount, ">=", tempVarStack[tempVarStackCount - 1].tempCount);
      break;
    case '5':
      fprintf(outputFile, "_t%d %c _t%d", tempVarStack[tempVarStackCount - 2].tempCount, '>', tempVarStack[tempVarStackCount - 1].tempCount);
      break;
    case '!':
      fprintf(outputFile, "_t%d %s _t%d", tempVarStack[tempVarStackCount - 2].tempCount, "not", tempVarStack[tempVarStackCount - 1].tempCount);
      break;
    case '|':
      fprintf(outputFile, "_t%d %s _t%d", tempVarStack[tempVarStackCount - 2].tempCount, "||", tempVarStack[tempVarStackCount - 1].tempCount);
      break;
    case '&':
      fprintf(outputFile, "_t%d %s _t%d", tempVarStack[tempVarStackCount - 2].tempCount, "&&", tempVarStack[tempVarStackCount - 1].tempCount);
      break;
  }

  tempVarStackCount -= 2; 
  tempVarStack[tempVarStackCount].tempCount = tempVarCount; 
  tempVarCount++; 
  tempVarStackCount += 1;

  fprintf(outputFile, ";\n");
}

void translateAssignment(char operator) {

  int type;

  if (operator == 'd') {
    fprintf(outputFile, "int _t%d = _t%d %c _t%d;\n", tempVarCount, tempVarStack[tempVarStackCount - 2].tempCount, '/', tempVarStack[tempVarStackCount - 1].tempCount);
    type = 0;
  } else if (operator == 'm') {
    fprintf(outputFile, "int _t%d = _t%d %c _t%d;\n", tempVarCount, tempVarStack[tempVarStackCount - 2].tempCount, '%', tempVarStack[tempVarStackCount - 1].tempCount);
    type = 0;
  } else if (operator == '/') {
    fprintf(outputFile, "double _t%d = (double) _t%d %c _t%d;\n", tempVarCount, tempVarStack[tempVarStackCount - 2].tempCount, operator, tempVarStack[tempVarStackCount - 1].tempCount);
    type = 1;
  } else {
    if (tempVarStack[tempVarStackCount - 2].tempType == 0 && tempVarStack[tempVarStackCount - 1].tempType == 0) {
      fprintf(outputFile, "int _t%d = _t%d %c _t%d;\n", tempVarCount, tempVarStack[tempVarStackCount - 2].tempCount, operator, tempVarStack[tempVarStackCount - 1].tempCount);
      type = 0;
    } else {
      fprintf(outputFile, "double _t%d = _t%d %c _t%d;\n", tempVarCount, tempVarStack[tempVarStackCount - 2].tempCount, operator, tempVarStack[tempVarStackCount - 1].tempCount);
      type = 1;
    }
  }

  tempVarStackCount -= 2; 
  tempVarStack[tempVarStackCount].tempCount = tempVarCount; 
  tempVarStack[tempVarStackCount].tempType = type;
  tempVarCount++; 
  tempVarStackCount += 1;
}

void translateMain() {
  fprintf(outputFile, "int main(int argc, char **argv) {\n");
}

void translateVariable(int type, char *name, int isArray) {
  if (isArray == 0) {

    if (type == 0 || type == 1) {

      if (isLast == 0) {
        fprintf(outputFile, "%s, ", name);
      } else {
        fprintf(outputFile, "%s;\n", name);
      }
    }
  } else {
    int range = end - start + 1;

    if (type == 0 || type == 1) {

      if (isLast == 0) {
        fprintf(outputFile, "%s[%d], ", name, range);
      } else {
        fprintf(outputFile, "%s[%d];\n", name, range);
      }
    }
  }
}

void translateConstant(int type, char *name, char *numericValue) {
  if (type == 3) {
    fprintf(outputFile, "const int %s = %s", name, numericValue);
  } else if (type == 4) {
    fprintf(outputFile, "const double %s = %s", name, numericValue);
  }
}

void translateFunction(int index, int type, IdentifierInfo *params, int paramsLength) {
  char name[100];
  strcpy(name, getString(index));

  if (type == 0) {
    fprintf(outputFile, "int %s(", name);
  } else if (type == 1) {
    fprintf(outputFile, "double %s(", name);
  } else if (type == 2) {
    fprintf(outputFile, "void %s(", name);
  }

  for (int i = 0; i < paramsLength; i++) {
    if (i != paramsLength - 1) {

      if (params[i].type != 5) {

        if (type == 0) {
          fprintf(outputFile, "int %s, ", params[i].name);
        } else if (type == 1) {
          fprintf(outputFile, "double %s, ", params[i].name);
        }

      } else if (params[i].type == 5) {

        int idx = lookupStringTable(params[i].name);
        int start = scopeStack[scopeLevel][idx].start;
        int end = scopeStack[scopeLevel][idx].end;

        int range = end - start + 1;

        if (scopeStack[scopeLevel][idx].arrayType == 0) {
          fprintf(outputFile, "int %s[%d], ", params[i].name, range);
        } else if (scopeStack[scopeLevel][idx].arrayType == 1) {
          fprintf(outputFile, "double %s[%d], ", params[i].name, range);
        }
      }
      
    } else {
      
      if (params[i].type != 5) {

        if (type == 0) {
          fprintf(outputFile, "int %s", params[i].name);
        } else if (type == 1) {
          fprintf(outputFile, "double %s", params[i].name);
        }

      } else if (params[i].type == 5) {

        int idx = lookupStringTable(params[i].name);
        int start = scopeStack[scopeLevel][idx].start;
        int end = scopeStack[scopeLevel][idx].end;

        int range = end - start + 1;

        if (scopeStack[scopeLevel][idx].arrayType == 0) {
          fprintf(outputFile, "int %s[%d]", params[i].name, range);
        } else if (scopeStack[scopeLevel][idx].arrayType == 1) {
          fprintf(outputFile, "double %s[%d]", params[i].name, range);
        }
      }
    }
  }

  fprintf(outputFile, ") {\n");
}

void translateDeclarationsTypes(int type) {
  if (isFunctionVariable == 0) {
    if (type == 0) {
      fprintf(outputFile, "int ");
    } else if (type == 1) {
      fprintf(outputFile, "double ");
    }
  }
}

void translateDeclarations(int index, int isFunction, int type, int isArray) {
  char name[100];
  strcpy(name, getString(index));

  if (!isFunctionVariable) {
    translateConstant(type, name, numericValue);
    translateVariable(type, name, isArray);
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
  // yydebug = 1;

  parametersList = malloc(100 * sizeof(IdentifierInfo));
  symbolTable = malloc(1000 * sizeof(IdentifierInfo));
  scopeStack = malloc(2 * sizeof(IdentifierInfo*));

  for (int i = 0; i < 2; i++) {
    scopeStack[i] = malloc(1000 * sizeof(IdentifierInfo));

    for (int j = 0; j < 1000; j++) {
      scopeStack[i][j].created = 0;
      scopeStack[i][j].passedParametersLength = 0;
    }
  }

  // if (argc != 3) {
  //   fprintf(stderr, "Usage: %s [pasfile]\n", argv[0]);
  //   return EXIT_FAILURE;
  // }
  
  FILE *input = (strcmp(argv[1], "-") == 0) ? stdin : fopen(argv[1], "r");
  if(input == NULL) {
    fprintf(stderr, "Failed to open input file!\n");
    exit(EXIT_FAILURE);
  }

  outputFile = (strcmp(argv[2], "-") == 0) ? stdout : fopen(argv[2], "w");
  if (outputFile == NULL) {
    fprintf(stderr, "Failed to open output file!\n");
    exit(EXIT_FAILURE);
  }

  initLexer(input);
  int result = yyparse();
  finalizeLexer();

#if 0
  showStringTable();
#endif

  // printf("ERRORS: %d\n", 0);
  // puts(result == 0 ? "ACCEPTED" : "REJECTED");

  free(parametersList);
  free(symbolTable);
  free(scopeStack[0]);
  free(scopeStack[1]);
  free(scopeStack);

  fclose(input);

  return EXIT_SUCCESS;
}
