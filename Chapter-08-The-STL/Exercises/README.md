# Chapter 8 - Exercises

Use these exercises to put into practice the knowledge you have gained from chapter 8. You can save your solutions to the exercises to this repository and it is recommended that for each exercise you create a _**new project**_ with the name of the exercise and save it to the relevant exercise folder for the chapter you are working on. Once you have completed your solution you should make sure you commit and push the code to your remote repository on GitHub.

---
&nbsp;


### 1 - Pairs & Tuples

Create a program that declares, initialise and outputs the values stored in a pair and tuple.

* The pair should include the name of a football team (`string`) and their league position`(int).
* The tuple should include the name of a city (`string`), its temperature (`double`) and wind speed (`int`).

&nbsp;
&nbsp;

### 2 - Student Map

Create a map that stores at least 5 student numbers as the keys (`int`) and student names as the elements (`string`). The program should ask the user to enter a student number and then output the name of the student associated with that number. If no student is found you should output an error message.

&nbsp;
&nbsp;

### 3 - Weather Data

Write a program that takes temperature data for the last 7 days for two cities (e.g. Bath and Barcelona) and stores the data into a container. Once the data is inputted do the following:

* Output the data to the console
* Display the highest, lowest and average temperature for each city.
* Display the highest, lowest and average temperature for the **cities combined**

You can use any container you deem suitable for this task.

&nbsp;
&nbsp;

### 4 - Vending Machine Upgrade

Create a simple vending machine that makes use of either pairs or tuples to group together the product information. The program should:

* Present the available products to the user
* Allow them to select the product
* Ask them to input their money
* Handle change / Error message if not enough money entered.

&nbsp;
&nbsp;

### 5 - Map Quiz

Using a map create a quiz program. The key should contain the question and the element should include the answer. For example:

```C++
map<string, string> quiz{
    { "Q1: Who is the Chancellor of Bath Spa University", "Jeremy Irons"},
    { "Q2: Who created the C++ Programming Language", "Bjarne Stroustrup"},
 };
```

The program should allow the user to answer the questions and receive a score at the end.

&nbsp;
&nbsp;

### 6 - Template Min & Max

Write a program that uses template functions to find the min and max of two parameters of any type.

&nbsp;
&nbsp;

### 7 - Swapping Values

Write a template function named 'swapValues' that swaps two values of any type and output these values after the function as run. For example if I had the following variables in my main function:

```C++
int a = 5;
int b = 10;
```

The expected console output for the program would be:

```
A is 10 and B is 5
```
&nbsp;
&nbsp;

### 8 - Generic Container

Create a class template for a simple container that holds a single value. The container should provide methods to set and get the value, and to print it.

In the main function test the class template with different data types such as ```int```, ```double``` and ```string```.

&nbsp;
&nbsp;

### 9 - Employee Sorting

Using the ```employeeData.txt``` file found in the resources file write a program the reads the data and allows the user to do the following

* Sort the employee records by age
* Sort the employee records by salary
* Count the number of female / male employees
* Count the number of employees under 30
* Find out the average salary of the employees
