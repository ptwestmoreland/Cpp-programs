# Cpp-programs
This repository will hold various beginner to intermediate level C++ programs that I developed.
I am new to software development and these are my first c++ projects.

Projects contained within:

1. Grade calculator: 
This project reads input and classifies the input grade by category and score. The actual grading mechanism is described within the source code and there are various other rules which are also described within grade_calculator.cpp

2. Boolean functions:
This project contains several functions that output truth tables for common logical operations when called from main. The final two functions compute the true/false value of a boolean expression given three inputs and display the result.

3. Boolean expressions:
With a random truth table involving 3 variables I used the sum of products method to develop its logic function. I created a C++ function that takes as arguments 3 boolean variables and computes the value of the logic function's true/false given the three inputs. I did not reduce the logic function because I wanted more practice in working with boolean operators in C++. 

4. Mountains and Valleys:
This program takes in to numbers that represent the endpoints of an interval. This interval is {a, b}. It confirms that 10 <= a <= b < 10000. It then determines if each number in the interval is a "mountain" or a "valley". A mountain is defined as a number such that, in the 2 digit case, digit1 < digit2 and a valley is defined as digit1 > digit2. A number can be neither a mountain nor a valley. The program makes use of multiple functions to classify each number in the interval as a mountain/valley/neither and keeps track of how many mountains or valleys there are on {a,b}. The output is then displayed. This program works by number slicing and comparing digits. It works on up to four digit numbers as the endpoint of the valid interval range, b,  is a maximum of 9999. 

5. Random fahrenhiet number to celsius equivalent:
This file loads a vector with fahrenheit temperature values and stores the celsius equivalent in another vector. The maximum and minimum values are then found.

6. Password program:
This file takes in a user input password as a string, the string then has certain characters swapped to make an updated version. This string is then reversed. The two updated password strings are appended together and output to the screen. 

7. cstring.cpp
This program performs various tasks and operations on char arrays. One finds the size of the string without using the length function, another finds the index at which a character is first found and returns it, or it returns the size if the character isnt found. The third compares the equality of two input cstrings.

8. string calculator.cpp
This is my largest and most complex project to date. It, with the user interface, allows the user to multiply or add any two integers and get the result, no matter their size. Integer overflow issues with addition and multiplication operations are circumvented by using the string class to represent numbers. The UI prompts the user to enter two strings to operate on, with an operation string seperating them. Such as: 3 + 1. This will continue until q, quit, or ctrl+d is entered. This program has been tested with all sorts of test cases and has operated correctly for each one. The program, in a nutshell, performs addition/multiplication on each chararcter of a string by converting each character to a decimal number. Overflow is handled on a per digit basis. These numbers are then converted back to characters and placed in a string. This is repeated for the entire input strings. I compiled it on terminal with the most sensitive warning settings and recieved no warnings or errors.

8. Caesar Cipher

  This program defines a class called encode word. It then applies the caesar shift to some user input to shift the word by a hand set key of four. This key is easily set to some user input value but this was just for fun. Also, the class's public encode functions dont consider spaces in the input word but that is also easily ammenadable. Further, this doesn't need to be done utilizing OOP but I am new to programming and I wanted to get some practice in defining and working with classes/objects. 

9. Temperature Queries: 

This program uses reads user input from a file and validates the input. This valid input is added to a linked list of nodes. These nodes are inserted to the linked list in a specified order. Various other functions related to the linked list are defined within the code. 

10. Collatz sequence:

This program computes and displays the famous collatz sequence starting from some user input integer.

11. Coin Flip Simulation:

This program simulates a coin being flipped a set amount of times. The number of trials is determined by the user. It could also be done using the binomial theorem but this was more interesting.

12. Coin Flip Simulation with User Control:

The above simulation was redone. The user now chooses when to flip the coin and when to stop vs just choosing an amount of flips and letting the program execute.

13. Bulls and Cows

This program uses digit slicing and vectors to play the mathematical code breaking game bulls and cows. Error checking and input validation is extensive.

14. Swap 

Uses pointers and a function to swap two values. 

15. Decimal to Binary Converter: 

Converts an input number into a 32 bit binary number with the divide by 2 method. This unsigned binary number is represented as a 32 bit array.

16. Random Vector with No Repeats:

This program loads a random n digit vector with random values from 0 to 9. The loop structure forbids any repeated values from occuring in the vector. 

17. Complex Number Calculator: 

This program defines a class that can add or multiply two complex numbers and display the result. 

18. Tic Tac Toe 

This program allows the user to play tic tac toe with the computer on a 3x3 board. The computer does not make the best possible choice of where to place its "Os" but instead this is randomized. This leads to the computer being pretty bad at tic tac toe.  
