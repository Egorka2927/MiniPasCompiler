Implementation choices:

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
