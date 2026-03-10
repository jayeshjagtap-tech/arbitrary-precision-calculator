1) Arbitrary Precision Calculator

This project implements a command line calculator in C that can perform arithmetic operations on very large integers.

Normally in C, numbers are limited by the size of built in data types such as int or long long. When numbers become very large, these data types cannot store them correctly. To overcome this limitation, the calculator stores each digit of the number in a doubly linked list.

By storing digits in linked lists, the program can perform calculations on numbers with hundreds or even thousands of digits.

2) Operations Supported

The calculator supports the following operations:

- Addition
- Subtraction
- Multiplication
- Division
- Modulus

The program also handles positive and negative numbers and removes unnecessary leading zeros from the result.

3) How the Program Works

1. The user enters two numbers and an operator.
2. Each number is read as a string.
3. Every digit of the string is converted into a node of a doubly linked list.
4. Arithmetic operations are performed digit by digit.
5. The result is stored in another linked list and printed.

This approach avoids the limitations of standard integer data types.

4) Project Structure

The project is divided into multiple files to keep the code organized.

- main.c – handles user input and operation selection  
- utils.c – helper functions for linked list operations  
- addition.c – addition implementation  
- subtraction.c – subtraction implementation  
- multiplication.c – multiplication implementation  
- division.c – division implementation  
- modulus.c – modulus operation  
- apc.h – structure definitions and function declarations  
- Makefile – used to compile the project

5) Compile and Run

Compile the project using:
Make

Run the program:
./APC.exe

Then enter the numbers and operator when prompted.

6) Author

Jayesh Jagtap  
B.E. Electronics & Telecommunication Engineering (2025)  
Dr. D. Y. Patil Institute of Technology, Pune

