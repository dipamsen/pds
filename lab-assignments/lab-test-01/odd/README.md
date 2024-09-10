# PDS Lab Test 1 (Odd Roll Numbers)

Duration: 2 hrs

1. (30 Marks) Write a program to accept two binary numbers bl and b2 from the user and find the bitwise NAND of numbers (i.e., b1 NAND b2) without using bitwise operators. The program should accept the numbers (b1 and b2) in `long long int` data format, and check whether the numbers are really binary. In case if the entered number is not binary, keep throwing an error message and insist the user to re-enter the number, until user enters a valid input. For this purpose, you may define and use a function with the header `int isBinary(long long int)` After the successful entry of each binary number, the system should indicate the entry is successful and display the number of bits of the entered binary number. Finally, when the valid inputs are given, it computes b1 NAND b2 and returns the result. You may define and use a function with the header `long long int bitwise_nand(long long int, long long int)` to compute the result of the operation, The rules of bitwise NAND operations, which is commutative, are as follows: \
   0 NAND 0 = 1\
   0 NAND 1 = 1\
   1 NAND 0 = 1\
   1 NAND 1 = 0

   Note: Don't use arrays for solving this problem.

   Example 1:

   ```
   Enter the first binary number:
   1011001110
   The entered binary number is valid and it has 10 bits.
   Enter the second binary number:
   100100110101
   The entered binary number is valid and it has 12 bits.
   Bitwise NAND of 1011001110 and 100100110101 is 111111111011
   ```

   Example 2:

   ```
   Enter the first binary number:
   1014001110
   The entered binary number is not valid. Enter the correct one.
   Enter the first binary number:
   1011001110
   The entered binary number is valid and it has 10 bits.
   Enter the second binary number:
   100100110101
   The entered binary number is valid and it has 12 bits.
   Bitwise NAND of 1011001110 and 100100110101 is 111111111011
   ```

2. (70 Marks) Write a C program to perform the following:

   a) Consider an integer array A with size 100. User will enter array elements through keyboard during run time. The entry can be terminated either by reaching the count of number of entered elements to 100 or entry of a negative integer (i.e., < 0).

   b) Display the elements of an array A, after completing the data entry by the user.

   c) Write a C function `group_dup()`, to rearrange the elements of A such that duplicates of each element should be placed in consecutive locations (see example). Don't use any additional array.

   d) Write a C function `group_dup_freq()` to rearrange the resultant array from part (c) such that the sequences of duplicates are arranged in descending order based on their length (see example).

   e) Write the equivalent C recursive functions `rec_group_dup()` and `rec_group_dup_freq()` for performing the functionalities of part (c) and part (d) respectively.

   f) After writing all the above four functions, during runtime user has a choice to choose either `group_dup()` or `rec_group_dup()` at the first level, and `group_dup_freq()` or `rec_group_dup_freq()` at the second level to demonstrate the functionality of the above said four functions.

   Note: Displaying the desired output should be done only in `main()`. The four user defined functions should not display anything within them. Don't use any global variables, additional arrays and library functions (except `<stdio.h>`). Pass minimum number of arguments to the functions.

   Example 1:

   ```
   Input array by the user
   A[15] = 4 2 3 5 1 4 5 4 2 5 4 5 3 5 3
   User choice for grouping duplicates: 1
   Non-recursive function group_dup() is chosen
   A[15] = 4 4 4 4 2 2 3 3 3 5 5 5 5 5 1
   User choice for arranging sequences of duplicates: 2
   Recursive function rec_group_dup_freq() is chosen
   A[15] = 5 5 5 5 5 4 4 4 4 3 3 3 2 2 1
   ```

   Example 2:

   ```
   Input array by the user
   A[10] = 4 3 2 1 4 3 2 4 3 4
   User choice for grouping duplicates: 2
   Recursive function rec_group_dup() is chosen
   A[10] = 4 4 4 4 3 3 3 2 2 1
   User choice for arranging sequences of duplicates: 1
   Non-recursive function group_dup_freq() is chosen
   A[10] = 4 4 4 4 3 3 3 2 2 1
   ```
