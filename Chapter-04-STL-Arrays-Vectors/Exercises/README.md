# Chapter 4 - Exercises

Use these exercises to put into practice the knowledge you have gained from chapter 4. You can save your solutions to the exercises to this repository and it is recommended that for each exercise you create a _**new project**_ with the name of the exercise and save it to the relevant exercise folder for the chapter you are working on. Once you have completed your solution you should make sure you commit and push the code to your remote repository on GitHub.

---
&nbsp;

### 1 - Standard Library Array input

Write a program that puts 5 integer values provided by the user into a *standard library array*. Once the values have been inputted display them to the user is a nicely formatted list.

#### Extension Problem:

* Prevent the user from entering invalid data.
* Complete the exercise using a traditional for loop and a range based for loop

&nbsp;
&nbsp;

### 2 - 2D Array Sums 

Declare and initialise a 2D array to hold the following 5 x 3 table.

| <!-- -->    | <!-- -->    | <!-- -->    |
|-------------|-------------|-------------|
| 2 | 4 | 6 |
| 3 | 6 | 9 |
| 4 | 8 | 12 |
| 5 | 10 | 15 |
| 6 | 12 | 18 |

Now using a nested for loop calculate the following:

* The sum of the values stored in each row (e.g. row 0 should equal 12)
* The overall sum of the values stored in the entire array

&nbsp;
&nbsp;

### 3 - Input Vectors

Write a program that puts 5 integer values provided by the user into a vector then output the vector to the console.

&nbsp;
&nbsp;

### 4 - Vector Workout

Write a program that does the following:

* Create an int vector with 10 values
* Output the list using a for loop
* Output the highest and lowest value
* Resize the vector 20 elements
* Output the list
* Assign values to the ten new elements
* Output the list
* Push two new elements to the list
* Output the list
* Pop two elements off the list
* Output the first and last elements of the list
* Clear the vector
* Output the size of the vector
* Check if the vector is empty

You will need to make use of the vector class methods to complete this task. For reference:
https://en.cppreference.com/w/cpp/container/vector

&nbsp;
&nbsp;

### 5 - Shopping List

Write a program that does the following

* Create an empty string vector.
* Append the items, "eggs," "milk," "sugar," "chocolate," and "flour" to the list.
* Output the list.
* Sort the list into alphabetical order.
* Output the list
* Remove the first element from the list.
* Output the list.
* Insert the item, "coffee" at the beginning of the list.
* Output the list.
* Find the item, "sugar" and replace it with "honey."
* Output the list.
* Insert the item, "baking powder" before "milk" in the list.
* Output the list.

You will need to make use of the vector class methods to complete this task. For reference:  
https://en.cppreference.com/w/cpp/algorithm

&nbsp;
&nbsp;

### 6 - Duplicate Checker

The following shopping list was written in a rush and may contain duplicates. Using appropriate algorithm and vector methods write a program that finds and removes duplicate elements from the list. Once the duplicates have been removed output the new shopping list to the console.

```C++
vector<string> shoppingList = {"Milk", "Bread", "Coffee" , "Tea", "Sugar", "Bananas", "Apples", "Milk", "Coffee"};
```