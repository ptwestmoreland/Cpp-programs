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
