# PDS Lab Test 1 (Odd Roll Numbers)

1. (70 Marks) In an institute, a student record means (alphanumeric) roll number (max size 8), name of the student (max size 36), and CGPA (real number) of the student.\
   a. Define a structure to store student records.\
   b. Read the class teacher's input on the number of students (_n_).\
   c. Dynamically allocate the memort for _n_ students (array of structures).\
   d. Class teacher stores the student details on the first come first serve basis. Therefore, you need to write a function to sort the student details based on their roll number. Bonus (10 marks) will be given for the implementation of (quick/merge) sort algorithm.\
   e. Write another function to print the ordered (after sorting) student details (as pwe following format).

   ```
   Roll No      Student Name                             CGPA
   --------------------------------------------------------------
   23PDS167     Sarvelpalli Radhakrishnan                10.0
   24PDS156     A. P. J. Abdul Kalam                     10.0
   ```

   f. Write additional function(s) or statement(s) to complete your program.\
   g. DO NOT USE ANY GLOBAL VARIABLES.

2. (30 Marks) Given a singly linked list containing up to _N_ nodes, reverse every group of _k_ nodes in the list. It is possible that the number of nodes in the linked list is not a multiple of _k_, for such cases, the remaining nodes should reverse as a group.

   - First create the list by taking input from the user. Ask user the number of nodes in the linked list and take user inputs.
   - You can assume that the data stored in each node is a character.
   - The value of _k_ whivh is an integer should user input.
   - Output the input linked list and the reversed linked list.

   Example:
   If the given linked list is the following:

   ```
   a --> b --> c --> d --> e --> f --> g
   ```

   An output with different k is given below:

   ```
   For k = 1:
   a --> b --> c --> d --> e --> f --> g

   For k = 2:
   b --> a --> d --> c --> f --> e --> g

   For k = 3:
   c --> b --> a --> f --> e --> d --> g

   For k = 10:
   g --> f --> e --> d --> c --> b --> a
   ```
