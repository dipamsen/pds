# PDS Lab Test 1 (Even Roll Numbers)

Duration: 2 hrs

1. (30 Marks) Write a program to accept two binary numbers bl and b2 from the user and find the bitwise NOR of numbers (i.e., b1 NOR b2) without using bitwise operators. The program should accept the numbers (b1 and b2) in `long long int` data format, and check whether the numbers are really binary. In case if the entered number is not binary, keep throwing an error message and insist the user to re-enter the number, until user enters a valid input. For this purpose, you may define and use a function with the header `int isBinary(long long int)` After the successful entry of each binary number, the system should indicate the entry is successful and display the number of bits of the entered binary number. Finally, when the valid inputs are given, it computes b1 NOR b2 and returns the result. You may define and use a function with the header `long long int bitwise_nor(long long int, long long int)` to compute the result of the operation, The rules of bitwise NOR operations, which is commutative, are as follows: \
   0 NOR 0 = 1\
   0 NOR 1 = 0\
   1 NOR 0 = 0\
   1 NOR 1 = 0

   Note: Don't use arrays for solving this problem.

   Example 1:

   ```
   Enter the first binary number:
   11001110
   The entered binary number is valid and it has 8 bits.
   Enter the second binary number:
   1001001101
   The entered binary number is valid and it has 10 bits.
   Bitwise NOR of 11001110 and 1001001101 is 0100110000
   ```

   Example 2:

   ```
   Enter the first binary number:
   1014001110
   The entered binary number is not valid. Enter the correct one.
   Enter the first binary number:
   11001110
   The entered binary number is valid and it has 8 bits.
   Enter the second binary number:
   1001001101
   The entered binary number is valid and it has 10 bits.
   Bitwise NAND of 11001110 and 1001001101 is 0100110000
   ```

2. (70 Marks) Write a C program to perform the following:

   a) Consider an character array C with size 200. User will enter the string into the array C through keyboard during run time. The entry can be terminated either by reaching the count of number of entered characters to 200 or by pressing the ENTER key. For the sake of simplicity, assume the characters to be entered are limited to lower case alphabet only.

   b) Display the entered string C, after completing the data entry by the user.

   c) Write a C function `group_char()`, to rearrange the characters of string C such that same characters are grouped together and placed in consecutive locations (see example). Don't use any additional array.

   d) Write a C function `group_char_freq()` to rearrange the resultant string from part (c) such that the sequences of same characters are arranged in ascending order based on their length (see example).

   e) Write the equivalent C recursive functions `rec_group_char()` and `rec_group_char_freq()` for performing the functionalities of part (c) and part (d) respectively.

   f) After writing all the above four functions, during runtime user has a choice to choose either `group_char()` or `rec_group_char()` at the first level, and `group_char_freq()` or `rec_group_char_freq()` at the second level to demonstrate the functionality of the above said four functions.

   Note: Displaying the desired output should be done only in `main()`. The four user defined functions should not display anything within them. Don't use any global variables, additional arrays and library functions (except `<stdio.h>`). Pass minimum number of arguments to the functions.

   Example 1:

   ```
   Input string by the user : computerscience
   Input string = computerscience
   User choice for grouping same characters : 1
   Non-recursive function group_char() is chosen
   String after grouping based on character = cccomputeeersin
   User choice for arranging sequences of characters : 2
   Recursive function rec_group_char_freq() is chosen
   String after arranging the sequences in ascending order = omputersinccceee
   ```

   Example 2:

   ```
   Input string by the user : indianinstituteoftechnology
   Input string = indianinstituteoftechnology
   User choice for grouping same characters : 2
   Recursive function rec_group_char() is chosen
   String after grouping based on character = iiiinnnndasttttueeooofchlgy
   User choice for arranging sequences of characters : 1
   Non-recursive function group_char_freq() is chosen
   String after arranging the sequences in ascending order = dasufchlgyeeoooiiiinnnntttt
   ```
