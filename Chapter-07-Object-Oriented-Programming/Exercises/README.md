# Chapter 7 - Exercises

Use these exercises to put into practice the knowledge you have gained from chapter 7. You can save your solutions to the exercises to this repository and it is recommended that for each exercise you create a _**new project**_ with the name of the exercise and save it to the relevant exercise folder for the chapter you are working on. Once you have completed your solution you should make sure you commit and push the code to your remote repository on GitHub.

---
&nbsp;

### 1 - Woof Woof

Write a program that declares a class which defines the characteristics of a dog. The program should instantiate two objects from this class and assign data to its members.

The program should then output the data from each object and compare the ages of the two objects to make the the oldest dog woof via an appropriate class method.

&nbsp;
&nbsp;

### 2 - Playing around in class

Use this exercise to play around with creating and accessing class members and methods. Your members and methods should be specified as public and you should try out the following:

* Create a class called Animal
  * Give the class at least the following members
    * Type
    * Name
    * Colour
    * Age
    * Weight
    * Noise
  * The class should have the following methods
    * sayHello (says its name via ```cout```)
    * makeNoise (make an appropriate noise via ```cout```)
    * animalDetails (output all the details of the animal object)
* Instantiate at least two objects from your animal class (e.g. Dog, Cow)
  * Set values for each of the variables
  * Invoke each of the class functions
* Add a default constructor (e.g. without parameters) that provides a message to say an animal has been created
* Add a destructor that provides a message to say when an animal is deleted
* Add a constructor with parameters to set initial values for at least two of your object's variables (e.g. name and noise)
* Instantiate an object from your class that makes use of the parameterized constructor to set some initial values
* Organise your class to make use of a .cpp and .h file

&nbsp;
&nbsp;

### 3 - Students Class

Create a class called students.

* The class should have the following members.
  * Name (string)
  * Mark1 (int)
  * Mark2 (int)
  * Mark3 (int)
* The class should have the following methods
  * calcGrade() - should return an average from the three marks
  * display() - should output the student name and calculated grade average
* The class should have a constructor that contains parameters to initialise all of the variables

With the class defined create an object from the class and assign the student name and marks via user input (```cin```). Then output this information via the appropriate class methods.

#### Extension Problem:

* Declare and define the class functions separately
* Organise your class to make use of a .cpp and .h file

&nbsp;
&nbsp;

### 4 - Data Class

Create a class called data. The class should contain two integer variables, a constructor that accepts values for these variables and a function that returns the sum of these variables.

With the class defined, ask the user of the program to input two numbers. Pass these values to the class constructor and show the result of the sum of the two numbers.

#### Extension Problem:

* Prevent invalid data being entered
* Declare and define the class functions and constructor separately
* Organise your class to make use of a .cpp and .h file

&nbsp;
&nbsp;

### 5 - This

Using your Dog class from the exercise 1 (or create a new one) create a constructor that has the parameter string ```name```. Use a this pointer to then assign the class data member name the value passed in by the constructor argument.

#### Extension Problem:

* Repeat the process so you constructor sets all of your class variables using the this pointer.

&nbsp;
&nbsp;

### 6 - Hide and Seek

Create a class called Student. Give this the variables name and number, but set these to private. Implement appropriate getter and setter functions within the class to initialise and then output these variables.

&nbsp;
&nbsp;

### 7 - Inheritance

Modify your animal class from exercise 2 (or create a new one) to allow subclasses to inherit from this parent class. Implement some appropriate subclasses that inherit the animal characteristics and extend these with their own variables and functions.

#### Extension Problem:

* Where appropriate implement polymorphism so subclasses override inherited functions.

&nbsp;
&nbsp;

### 8 - Playing with Polly

Create a parent class called shape. This should include variables for height and width and a basic method for calculating the area e.g:

```
height * width
```

Now create subclasses for a circle, rectangle and triangle. These should include an appropriate area method that will overload the area function in the shape class.

&nbsp;
&nbsp;

### 9 - Employee Data

Create an employee class with the following members:

* name, age, id, salary

Add the following methods:

* setData - should allow employee data to be set via user input
* getData - should output employee data to the console

Now create an array of 5 employees. You can create an array of objects in the following way, depending which type of array you are using.

```C++
ClassName arrayName[size];  
```

```C++
array<ClassName, size> arrayName;
```

E.g:

```C++
Cat cats[10] //creates 10 cat objects
```

In your main program set the data for each of the employees in this array. You should do this utilising the setData function from your class. Then output the details for each employee. You should do this via getData function in your class.

#### Extension Problem:

* Include appropriate error checking to handle incorrect input.
* Implement file handling to save inputted data