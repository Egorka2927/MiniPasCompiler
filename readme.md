Implemented semantic checks

- Check if a variable is undeclared
- Check if a function is undeclared
- Check if a const is undeclared
- Can not redeclare a variable twice
- Can not redeclare a function twice
- Can not redeclare a const
- Can not assign anything to a const
- The types of passed parameters to the function have to match the ones in function declaration
- Consts can not be passed by reference
- Check if the parameters that have to be passed by reference are passed by reference
- If a function expects a real passed by reference, integer can not be passed as a parameter
- You can only add integers and reals
- You can only subtract integers and reals
- You can only multiply integers and reals
- You can only divide integers and reals
- You can only do integer division on integers
- You can only do modulo on integers
- You can only negate integers and reals
- You can only compare integers and reals
- You can not assign a real to an integer
- A function can only assign a value to itself inside its own scope
- Procedures can not assign a value to itself
- Array indexes have to be integers
- Array range boundaries have to be integers
- Function can not be called without parameters
- Arrays can not be assigned
- Identifier can not be used as a function if it is not a function
- You can not use procedures as functions

Code generation implementation choices:

- All arrays are passed by reference. No passing arrays by value implemented.
- All variables are passed by value. No passing variables by reference implemented.
- For while loops and if-else statements the stack approach is used to handle nested cases.
- Variable and function declaration happens "on the go".
- To keep track of the temporary variables, the stack approach is used. The stack stores TempVariable structs that store the count and the type of the temporary variable.
- Assigning to an array element is done using pointer arithmetic.
- Assigning an array element is also done using pointer arithmetic.
- Whenever a function is called, first all its parameters are loaded into temporary variables, then the function is called with those temporary variables as parameters.
- Whenever writeln is called, all its parameters are loaded into temporary variables, then writeln is called with those temporary variables as parameters.
- Whenever readln is called, the parameters that are variables are loaded directly and to handle array elements pointer arithmetic is used.
- Casting to double is used for division in order to save precision.
