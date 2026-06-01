# Chapter 1 Exercises

Use these exercises to put into practice the knowledge you have gained from chapter 1. You can save your solutions to the exercises to this repository and it is recommended that for each exercise you create a _**new project**_ with the name of the exercise and save it to the relevant exercise folder for the chapter you are working on. Once you have completed your solution you should make sure you commit and push the code to your remote repository on GitHub.


---
&nbsp;

### 1 - Arrows

Write a C++ program to print the asterisk pattern shown below

```
     *
    ***
   *****
  *******
 *********
    ***  
    ***
    ***
```

&nbsp;
&nbsp;

### 2 - PI

Create a program to calculate the circumference and area of a circle from the radius. The program should ask the user to enter the desired radius of the circle.

PI is defined as: ```3.14159```
Area is defined as: ```PI * radius * radius```
Circumference is defined as: ```PI * Radius * 2```

&nbsp;
&nbsp;

### 3 - User Input / Output

Write a C++ program to prompt the user to input her/his name, age and hometown and print these details on the screen. The format of text should look like the sample output below but you can only use a **single cout** when outputting the information.

```
Your Name is: Jake Hobbs
Your Age is: 30
Your Hometown is: Bristol
```

&nbsp;
&nbsp;

### 4 - Is it a Triangle? 

Write a program that checks if 3 angles given can make a triangle (the angles should add up to 180). The program should ask the user to enter values for 3 angles then output appropriate feedback.

#### Extension Problem:

If valid, ask the user for the length of the sides and have the program correctly classify the type of triangle as either: Equilateral, Isosceles or Scalene ([see here](https://www.mathsisfun.com/triangle.html))

&nbsp;
&nbsp;

### 5 - Would you Like to Continue?

Write a program that implements a while loop. This program should ask the user if they would like to continue and use the while loop to keep looping as long as they enter the letter Y. Once the while loop has terminated output the number of times it executed.

&nbsp;
&nbsp;

### 6 - Multiplication fun

Write a program the users a for loop to output the multiplication table for a number enter by the user. For example if the user entered 3 the expected output would be as follows:

```C++
-------------
3 times table
-------------
1 x 3 = 3
2 x 3 = 6
3 x 3 = 9
4 x 3 = 12
5 x 3 = 15
6 x 3 = 18
7 x 3 = 21
8 x 3 = 24
9 x 3 = 27
10 x 3 = 30
11 x 3 = 33
12 x 3 = 36
```

&nbsp;
&nbsp;

### 7 - Simple Calculator

Write a C++ program that will display the following calculator menu:

1. Add
2. Subtract
3. Multiply
4. Divide
5. Modulus

The program will prompt the user to choose the operation choice (from 1 to 5) and then ask the user to input values for the calculation. Finally, the program outputs the results of the calculation.

#### Extension Problem:

* Allow the user to keep entering values until they enter Q to quit.
* Handle incorrect input

&nbsp;
&nbsp;

### 8 - Number Input / Output

Write a C++ program to prompt the user to input 3 integer values and print these values in forward and reversed order in a similar format to the below.

```
Please enter your 3 numbers: 12 45 78

Your numbers forward:
12
45
78


Your numbers reversed:
78
45
12
```

&nbsp;
&nbsp;

### 9 - Maths

Write a C++ program to produce a table in the output as shown below. You should use the maths operators on the x and/or y variable to achieve the results. One math operator should be used for each line in the following order: Addition, Subtraction, Multiplication, Division, Modulus.

| x value | y value | results |
| ------- | --------| ------- |
| 10      | 5       | 8       |
| 10      | 5       | 3       |
| 10      | 5       | 25      |
| 10      | 5       | 2       |


The tab escape character "\t" might be useful to format the console output table e.g:
```C++
cout << "x value" << "\t" etc...
```

&nbsp;
&nbsp;

### 10 - More Maths

Write a C++ program to produce a table in the output as shown below. You should use the maths operators on the x and/or y variable to achieve the results. One math operator should be used for each line in the following order: Addition, Subtraction, Multiplication, Division, Modulus.

| x value | y value | results |
| ------- | --------| ------- |
| 10      | 5       | 15      |
| 10      | 5       | 7       |
| 10      | 5       | 250     |
| 10      | 5       | 5       |
| 10      | 5       | 2       |

&nbsp;
&nbsp;


### 11 - So Much Maths

Write a program that evaluates the following calculations for two int numbers obtained from the user and outputs the results to the console:

Sum (+)  |  Diff (-)  |  Product (x) |  Quotient (/) |  Remainder (%)

&nbsp;
&nbsp;

### 12 - Days of the Week

Write a program that accepts a number (1-7) then using a switch statement outputs what day of the week it is (e.g. 1 = Monday).

#### Extension Problem:

Handle invalid input (e.g. letters and numbers outside specified range).

&nbsp;
&nbsp;


### 13 - Number Guessing Game

Create a number guessing game where the user must guess what the number is between 1-100. The game should allow the user to keep guessing until they get it right. After each guess the game should provide feedback informing the user how far away their guess is.

#### Extension Problem:

* Implement a scoring system based on the number of guesses the user takes to get the answer right
* Rank this scoring system so the user gets a grade or stars e.g. 1-3 guesses = A, 5-7 guesses = B etc..
* Set the original number randomly
* Implement different modes (e.g. easy and hard), For example in easy mode the game provides feedback on how far away the guess is, whilst in hard mode no feedback is provided.

&nbsp;
&nbsp;


### 14 - Fix This While You're Here

Fix and improve this while loop code so the user can only enter valid data.

```C++
#include <iostream"
using namespace;

int main() {
	int counter = 0;
	char Endnow = 'N';

	while (counter < 5 & endnow != 'Y')
	{
		counter-+
		cout < "counter" < counter  < " /n";
		cout < "Do you want to end the loop now, enter Y or N ?"
		cin > EndNow;
	}
	return 0;
}
```

&nbsp;
&nbsp;

### 15 - Case Switcher

Write a program that swaps the upper and lower case letters in the sentence below:

```
CoDeLaB iS gReAt. I lOvE c++
```

Desired result:
```
cOdElAb Is GrEaT. I LoVe C++
```

*Hint: Make use of [isupper](http://www.cplusplus.com/reference/cctype/isupper/) and [islower](http://www.cplusplus.com/reference/cctype/islower/) to achieve this*

&nbsp;
&nbsp;

### 16 - The Mad Hatter

The Mad Hatter likes to reverse words. Write a program that allows him to print out any given String in reverse. The user should be able to enter the word and the resulting output should say:

```
The Mad Hatter Says: word in reverse
```

&nbsp;
&nbsp;

### 17 - Input Arrays

Write a program that requests five numbers from the user and adds these into an array. Once the values have been inputted display them to the user is a nicely formatted list.

#### Extension Problem:

Prevent the user from entering invalid data.

&nbsp;
&nbsp;

### 18 - 2D Average

Write a program to find the average value of each column of a 2D array of type double

&nbsp;
&nbsp;

### 19 - Times Tables

* Write a program that declares an empty 12 x 12 multidimensional array.
* Next make use of a nested for loop to assign the values of the 12 times table into the multidimensional array.
* Now use a second nested for loop to output the values in the multidimensional array. You should aim to neatly format the outputted values

Example Output:

```
1 times table:
---------------

1 x 1 = 1
1 x 2 = 2
1 x 3 = 3
1 x 4 = 4
1 x 5 = 5
1 x 6 = 6
1 x 7 = 7
1 x 8 = 8
1 x 9 = 9
1 x 10 = 10
1 x 11 = 11
1 x 12 = 12

2 times table:
---------------

2 x 1 = 2
2 x 2 = 4
2 x 3 = 6
2 x 4 = 8
2 x 5 = 10
2 x 6 = 12
2 x 7 = 14
2 x 8 = 16
2 x 9 = 18
2 x 10 = 20
2 x 11 = 22
2 x 12 = 24

etc
```

&nbsp;
&nbsp;

### 20 - Max Values

Write a C++ program that will prompt the user to input ten integer values and store these values in an array. The program should then determine the smallest and greatest of those values and display these to the console.

&nbsp;
&nbsp;

### 21 - Array Search

Create an array containing the following student names:

*Jake, Jess, Jeff, Joe, Jenny, Jack, Jonny, Jasmine, Josh*

Next ask the user to enter a name and search the array to see if the name they have entered exists in the array.

If the name exists output "X has been found in the database", otherwise output "Sorry no X has been found in the database", with X being the name entered by the user.

&nbsp;
&nbsp;


### 22 - Mini Bio

Write a program that asks the user to enter their name and age. This information should be collected from the user within the main function then passed to a function called bio where it should be printed to the console.

You should declare and define your function separately

&nbsp;
&nbsp;

### 23 - Magic 8 Ball

Write a magic 8 ball program. You should allow the user to input a question to which the program will provide a cryptic response. E.g:

```
Q. Shall I go out tonight?
A. Outlook looks good
```

In your solution you should make use of arrays and functions where appropriate

&nbsp;
&nbsp;

### 24 - Give me the Product

Write a program that passes an array as an argument to a function. The function should then calculate the product (values multiplied) of the array values and return this value back to the main program.

&nbsp;
&nbsp;

### 25 - Shape Functions

Code a program to display a menu on the screen that asks if the user wants to

```
1: Calculate the area of a square,
2: Calculate the area of a circle,
3: Calculate the area of a triangle.  
```

Each of the 3 functions should ask for the necessary information (e.g. lengths and/or angles and output the answer).

#### Extension Problem:

Include error handling to prevent the user from entering invalid data.

&nbsp;
&nbsp;
