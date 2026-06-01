# Chapter 1 - C++ refresher

You should be familiar with the contents covered in this chapter, which serves as a refresher to the material covered in CodeLab I. If you find yourself struggling with any of the concepts and/or exercises included in this chapter you should make the time to revisit the materials from CodeLab I. A solid understanding of these concepts is essential in order to advance with the concepts introduced in CodeLab II. Don't hesitate to arrange a 1-2-1 tutorial if you are struggling to understand these fundamental programming techniques.

* [The Basics](#the-basics)
   * [Structure of a C++ Program](#structure-of-a-c-program)
   * [Coding Conventions](#coding-conventions)
   * [Variables and Data Types](#variables-and-data-types)
   * [Constants](#constants)
   * [Non-Primitive Data Types](#non-primitive-data-types)
   * [Input / Output Stream](#input--output-stream)
   * [Operators](#operators)
* [If Statements](#if-statements)
   * [Compound Conditions](#compound-conditions)
* [Switch Statements](#switch-statements)
* [Loops](#loops)
   * [While Loop](#while-loop)
   * [Do While](#do-while)
   * [For Loop](#for-loop)
* [Arrays](#arrays)
   * [Recapping the basics](#recapping-the-basics)
   * [Why use an Array?](#why-use-an-array)
   * [Declaring and Initialising an Array](#declaring-and-initialising-an-array)
   * [Accessing the Array](#accessing-the-array)
   * [Iterating Through the Array](#iterating-through-the-array)
* [Multidimensional Arrays](#multidimensional-arrays)
   * [Declaring a 2D Array](#declaring-a-2d-array)
   * [Initialising a 2D Array](#initialising-a-2d-array)
   * [Accessing a 2D Array](#accessing-a-2d-array)
   * [Iterating Through a 2D Arrayy](#iterating-through-a-2d-array)
* [Functions](#functions)
  * [Recapping the Basics](#recapping-the-basics-1)
  * [Function Structure](#function-structure)
  * [Invoking Functions](#invoking-functions)
  * [Declaring and Defining Functions](#declaring-and-defining-functions)
    * [Declaring](#declaring)
    * [Defining](#defining)
  * [Passing Values](#passing-values)
  * [Returning Values](#returning-values)
  * [Variable Scope](#variable-scope)
  * [Passing by Value vs Passing by Reference](#passing-by-value-vs-passing-by-reference)
    * [Passing by Value](#passing-by-value)
    * [Passing by Reference](#passing-by-reference)
    * [Const References](#const-references)

## The Basics

### Structure of a C++ Program

Every C++ program starts with the same main structure, including some preprocessor directives and the beginning of the program and importantly the main function. Hopefully this is all fresh in the memory from last year, but as a reminder refer to the comments and code breakdown for an explanation of the main elements of the program.

```C++
#include <iostream> // preprocessor directive - include iostream file
using namespace std; // declare use of the standard namespace

int main(){ // define main function
	cout << "Hello World" << endl; // output statement

	return 0; //return statement
}
```

&nbsp;
&nbsp;

#### Code breakdown

##### Preprocessor directive

```C++
#include <iostream> // preprocessor directive - include iostream file
```
Anything beginning with a ```#``` hash is a preprocessor directive that instructs the compiler to process this information before compiling of the rest of the code. The `#include` instruction acts like a copy and paste command and tells the compiler to copy and paste the contents of the ```iostream``` header file to the top of our program. The iostream header file contains the declarations for the standard input-output library in C++. We need this to gain access to things like ```cout``` which is the standard library output command for outputting content to the console.

&nbsp;
&nbsp;

##### Using Namespace Std

```C++
using namespace std; // declare use of the standard namespace
```
The contents of iostream that we’ve just added are part of the standard C++ library which includes lots of useful pre-declared functionality for C++ programs. All the elements of this library are declared within a namespace in this case the `std namespace`. To access its functionality we need to let the compiler know we are using this standard namespace. 

If the compiler encounters any undeclared identifiers in the code (e.g. ```cout```), it will check to see if they are present within the namespace. If it is the program will proceed, otherwise it will throw an error. Declaring the use of the standard namespace saves us having to explicitly declare its use every time we use functionality from the library. For example if without declaring use of the std namespace our ```cout``` statement in our Hello World program would need to be written like the example below with `std` explicitly declared before both ```cout``` and ```endl``` as the functionality for come from the standard library:

```C++
std::cout << "Hello, World!" << std::endl;
```

&nbsp;
&nbsp;
> **Advanced Note** When starting out with small programs declaring using namespace std at the beginning of our programs saves times as we can avoid the constant explicit declaration as described above. However, when you become more proficient and begin writing more advanced programs it is advised that you avoid its declaration at the start of the program and do explicitly declare the namespace before operations like cout each time. This helps avoid potential conflicts between different libraries you might be using that are using the same names for different operations.

&nbsp;
&nbsp;

##### The Main Function
```C++
int main(){ // define the main function
      cout << "Hello World" << endl; // output statement
	return 0; //return statement
}
```
All C++ programs start with the execution of a **main function**. It is essential to have a main function otherwise your program simply will not work, this is the first thing the compiler looks for when executing C++ code. The word main is followed by a pair of parentheses followed by the body of the main function which will be enclosed by curly braces. The function body includes all the code that we want our program to run. C++ programs are executed line by line in order. Each line is a statement which is an expression that can produce a result. Statements are always terminated by a semicolon. Omitting the semicolon is probably the most common error when writing code. Try removing the semicolon at the end of the hello world statement, a red line should appear on that line in the code editor to indicate an error. These red lines are useful for helping find errors when writing your code.


The first line in our main function is an output statement. ```cout```. Our ```cout``` statement is saying insert the sequence of characters for *"Hello world"* into the output stream. You will notice the two less than signs ```<<```  this is called the insertion operator. So we are inserting Hello World into the output stream.

We then insert something called ```endl```. This is an instruction to insert a newline then flush the contents of the output stream.

&nbsp;
&nbsp;
> **Advanced Note** - A new line can also be created by inserting the newline character ```\n``` within a string. The difference between ```endl``` and ```\n``` is ```endl``` flushes the output stream after adding the newline. Flushing the stream ensures the contents are outputted to the console in a timely manner. If you have several  ```cout``` statements one after the other, it may not be necessary to flush the stream at the end of each ```cout``` statement. Therefore you could use the newline character instead and then on the final line use ```endl``` to ensure the stream is flushed.
>```C++
> cout << "Hello, World! This is the first line \n";
> cout << "Here is a second line \n";
> cout << "Here is a third line \n";
> cout << "This fourth line will flush afterwards" << endl;
>```
>*Further Information:* https://www.geeksforgeeks.org/endl-vs-n-in-cpp/

&nbsp;
&nbsp;

##### Return Statement

The final line of the main function is the return statement. The return statement causes the main function to finish. Usually this is followed by a return code in our case `0`, which is generally interpreted as the program worked as expected without errors.

&nbsp;
&nbsp;


### Coding Conventions

The importance of Coding Conventions is crucial (*and not always followed last year in CodeLab!!*). Keeping your code neat and tidy not only helps you find your way around, but helps others understand your work when looking for help. Neat code can save you hours when trying to fix errors and its importance should not be underestimated (which is why its part of the marking criteria for the assessments!). As a reminder here are six tips that should help you keep your code organised so you can make sense of it when you return to it at a later date.


#### 1 - Program Descriptors

Add a couple of commented lines right at the very top of your programme that describes, in the simplest terms, what the program does.


#### 2 - Comments

Beginners should annotate their code with comments to remind them what certain commands do. For example, the first time you type

```C++
cout << "Hello World" << endl;
```

it wouldn’t hurt to place a comment next it that says…

```C++
// This is how you print to the console in C++.
```

As your programmes become more complex, you can use comments to make it easier to find certain code blocks, or remind you to finish certain coding tasks. Comments act like bookmarks in this sense.


#### 3 - Variable Names

Variable names should be unambiguous and where possible, short. For example if I was writing a programme that asks for a user's name, I would save their input in a variable called `usersName`. Seems obvious, but you’d be surprised how often variable names such as `a` or `x` are used. This is lazy and makes understanding what is happening in the program much harder.


#### 4 - CamelCase

If you use more than one word for a variable name (e.g. `myInteger`), make sure you capitalise each word. Most people only capitalise from the second word onwards (e.g. `myFavouriteFood`), this is known as camel case.

Other methods for variable naming exist such as PascalCase where the first letter of the variable is capitalised as well as the letters of subsequent words in the variable name. There is also snake_case, common in python where words are separated by underscores

```C++
int myNumber;//camelCase
string MyUserName;//PascalCase
string favourite_food;//snake_case
```


#### 5 - Whitespace

Write code as if you were writing an instruction manual. Keep everything in line (unless you have to indent - more on this later), and only break up code blocks with blank lines if it makes sense to do so. Think of code blocks as paragraphs with short sentences that should be kept together until the next sentence is clearly the beginning of a new set of instructions.


#### 6 - Indentation

Indentation helps identify where code blocks begin and end. Code blocks in C++ are wrapped in a pair of curly braces `{ }`, and the code inside the block should be indented by 1 tabbed space. If nesting a code block inside another this would be tabbed again. See the example below.

```C++
#include <iostream>
using namespace std;

int main() { // this is the start of the main program code block

    //code inside the block is indented by one tabbed space
    cout << "Hello, World!" << endl;
    cout << "This is a simple C++ program" << endl;

    if(6 < 7){//this is the start of a second code block
        //code inside this block is indented a further tabbed space
        cout << "6 is less than 7" << endl;
    }

    return 0;

} //this is the end of the main program code block
```

&nbsp;
&nbsp;
&nbsp;

### Variables and Data Types

Variables are a place where we store pieces of information for use in our programs. We provide variables with names we can recall later to either access or modify the values stored in the variable. By the nature of their name the information stored in a variable can change. However, whilst the value can change in C++ it must remain the same data type.

C++ has four main primitive data types

* `int` (whole numbers)
* `double` (decimal number)
* `char` (single character)
* `bool` (True or False)

C++ is known as a strongly typed language, this means that when creating variables in our program we must specify what type of data it will contain. This data type could be a whole number (`int`), single character (`char`) or a decimal number (`double`). A variable's data type determines the values it may contain, plus the operations that may be performed on it. In C++ (and other strongly typed languages) once a variables data type is declared it cannot be modified and can only hold values of this type for the duration of the program.

When declaring a variable as well as stating what type of data it will store we must give it a name. We can give variables (almost) any name, but do ensure you give it a sensible name that relates to the job it performs. When declaring a variable we can initialise its value by using the assignment operator (`=`), followed by the value we wish to assign.

```C++
//declare & initialise variables
int wholeNum = 6;
double decNum = 5.345;
char singleCharacter = 'd';
bool booleanValue = true;
```

Variables can be left uninitialised, simply by leaving out the value assignment. However, you must ensure it is initialised before accessing it later in the program

```C++
int myNum; //declare variable but don't initialise

//some code
//some more code

myNum = 6; //initialise variable later in the program
```

&nbsp;
&nbsp;
&nbsp;

### Constants

When we want to store some information in our program we create a variable. As their name suggests the values stored in a variable can change (they can vary!). If you have a value that shouldn’t be altered you can declare this as a constant by using the ```const``` keyword at the beginning of the variable declaration. Variables declared as a constant cannot have their value changed.


#### An Example

Let’s say we wanted to create a simple maths program and wanted to store the value of PI in a variable. The value of PI is the same so we don’t want this to change, else it could interfere with other calculations in our program. Therefore, it would make sense to declare our PI variable as a constant.

```C++
const int PIVALUE = 3.14159265359;
```

Constant variable names are typically written in all capital letters to easily identify them as constants in the program.

&nbsp;
&nbsp;
> **Advanced Note** - In C++11 the auto keyword was included to allow a variable data type to be inferred from the value its initialised with.
>
>  ```C++
>  int myFirstInt = 5; //explicitly declared integer variable
>  auto mySecondInt = 6; //variable data type automatically inferred from the value assigned
>  ```
> For the declaration of simple variables with one of the core data types (int, char, double), it is best to be explicit and you would not use auto. Auto is typically used when your programs become much more complex and you are using complex types available in C++.
>
>Further Information
>
>https://en.cppreference.com/w/cpp/language/auto  
>
>https://www.learncpp.com/cpp-tutorial/4-8-the-auto-keyword/
&nbsp;
&nbsp;

&nbsp;
&nbsp;
&nbsp;

### Non-Primitive Data Types

In C++ we also have access to non primitive data types. These non-primitive types usually contain enhanced functionality beyond primitive data types that allow them to be manipulated in various different ways.


#### Strings

Strings are one of the most widely used objects in programming. They hold a sequence of characters surrounded by double quotation marks `"` on both sides and can contain any characters.

```C++
string str1 = "Hello";
string str2 = "Hello World";
string str3 = "CodeLab";
```

When you want to begin manipulating strings in your program you will need to include the string header.

```C++
#include <string>
```

As noted above, as strings are an object stemming from the String Class they offer access to enhanced functionality that allows the objects to be manipulated or obtain information about them. For example:

```C++
string str1 = "Hello";
cout << str1.length() << endl; //will output 5

str1.append(" World"); //adds World to original string
cout << str1 << endl; //will output Hello World

//replace contents of string beginning a 6th character
str1.replace(6, 5, "CodeLab");
cout << str1 << endl; //will output Hello CodeLab
```

Further reading: http://www.cplusplus.com/reference/string/string/

Other non-primitive types we will use in future sessions are Arrays and Vectors, which act as containers for multiple variables/objects. We will also learn how to create our own data types and objects when begin explore Object Oriented Programming (OOP).

&nbsp;
&nbsp;
&nbsp;

### Input / Output stream

The  ```#include <iostream>``` directive written at the top of a C++ program provides us access to the C++ standard library input and output stream. This includes existing functionality to get user input from and output information to the console.

We use ```cin``` and the extraction operator ```>>``` to get user input from the console

We use ```cout``` and the insertion operator ```<<``` to output information to the console.

An easy way to remember the difference between ```cin``` and ```cout``` and the actions they perform is to refer to them as *console in* (cin to get information) and *console out* (cout to display information).

We have seen ```cout``` in some of our examples already. The ``cout`` command allows us to display information to the console. ```cin``` allows us to get information back from the console (e.g. receive input from the user). We typically use ```cout``` and ```cin``` in combination; ```cout``` to ask a question and ```cin``` to retrieve the answer. For example the code below asks the user to enter a number with ```cout``` and then uses ```cin``` to receive the answer and store this into the variable ```myNum```.

```C++
int main(){ // define the main function
    int myNum;//variable to store users number
    cout << "Enter a number:" << endl; // output statement
	cin >> myNum;//receive input and store in myNum
	cout << "The entered number is was: " << myNum << endl;
	return 0; //return statement
}
```

As you can see in the above example we can sequence the output of multiple pieces of information (and of different types) by using multiple insertions (```<<```) into the ```cout``` command.

> **Advanced Note**
>
>C++23 introduced a new ```<print>``` header for more convenient output to the console using the ```print``` or ```println``` commands. For example:
>
>```C++
>print("Hello, {}!\n", "world");//prints hello world
>
>int number = 42;
>
>print("The answer is: {}\n", number);//prints variable within formatted string
>```
>As this feature is still new, it is not widely adopted and is not yet supported by many C++ compilers. Therefore this approach is not yet used in CodeLab.

&nbsp;
&nbsp;
&nbsp;

### Operators

An operator in computer programming is a symbol that tells the compiler to perform specific mathematical, relational or logical operations.

#### Assignment Operator

The assignment operator is used to assign values to variables

```C++
string myString = "Hello World"; //assign value to myString
myString = "CodeLab"; //re-assign value to myString
```

#### Mathematical Operators

Used for performing mathematical calculations. These include the following operators:

```
	+ 	(additional)
	- 	(subtraction)
	/ 	(division)
	* 	(multiplication)
	% 	(modulus or ‘find remainder’)
```

```C++
int num1 = 5;
int num2 = 6;
int sum = num1 + num2;
cout << "Sum of numbers added: " << sum << endl; //should output 11

sum = num1 - num2;
cout << "Sum of numbers subtracted" << sum << endl; //should output -1
```

#### Relational Operators

Relational operators are used to create conditional expressions and will either evaluate to `TRUE` or `FALSE`. This means relational operators can be used to make decisions in computer programs, e.g. if something is true do this, otherwise if its false do that

The following example illustrates the use of the less than relational operator: `7 < 10`

This expression in words is saying "7 is smaller than 10". This is a `TRUE` statement.

There are a number of relational operators:

```
<	(less than)
> 	(greater than)
>= 	(greater than or equal to)
<=	(less than or equal to)
== 	(equality - is the same as)
!= 	(inequality - is not the same as)
```

```C++
string str1 = "Hello";
string str2 = "World";

/* if statement uses the equality operator to create a condition that checks if the two strings are the same length */
if(str1.length() == str2.length()){
    cout << "Strings are the same length" << endl;
}
```

&nbsp;
&nbsp;

## If Statements

The `IF` statement is the most common conditional statement and probably the most fundamental technique in computer programming. `IF` statements allow us to make decisions in our programs. In its most basic form the `IF` statement will execute a block of code if a condition is true, as seen in the previous string comparison example.

```
if(condition){
    //statements
}
```

We can extend the basic `IF` statement with an `ELSE` block, which will execute if the condition is `FALSE`.

```
if(condition){
    //statements
}else{
    //statements
}
```

We can see this branched decision making in the following flowchart diagram for the `IF` statement

<p align="center">
  <img src="https://jakehobbs.co.uk/markdown_images/IF-ELSE-Flowchart.png">
</p>

We can continue to extend the `IF` statement by using `ELSE IF` conditional checks. By using `ELSE IF` we add further conditions that will be evaluated if the previous ones are false. Take note that the conditions are evaluated in order and as soon as one evaluates to `TRUE` the corresponding code block will run and the `IF` statement will stop.

```C++
int x = 8;

if (x == 7){ //condition is FALSE corresponding code ignored
    cout << "x IS equal to 7" << endl;
}else if (x == 8){ //condition is TRUE run corresponding code
    cout << "x IS equal to 8" << endl;
    //execution ends here, all other conditions are ignored
}else if (x == 9){
    cout << "x IS equal to 9" << endl;
}
```

As shown above there may be multiple `ELSE IF` statements, each with their own conditional expression. Once one condition is met subsequent conditions are ignored. So beware of your ordering in some instances.

In the `IF` / `ELSE IF` structure either one (if a condition is `TRUE`) or no blocks of code (if all conditions are `FALSE`) will be executed. Terminating an `IF` / `ELSE IF` structure with an `ELSE` will ensure a statement is executed if no condition is met. For example:

```C++
int x = 9;

if (x == 7){
    cout << "x IS equal to 7" << endl;
}else if (x == 8){
    cout << "x IS equal to 8" << endl;
}else if (x == 9){
    cout << "x IS equal to 9" << endl;
}else{
    cout << "x IS NOT 7, 8 or 9" << endl;
}
```

&nbsp;
&nbsp;

### Compound Conditions

Each of the above examples only evaluate a single condition per `IF` (or `ELSE IF`) statement. Sometimes an `IF` statement needs more than one condition. For example, if two things have to be `TRUE` for some code to run. For this we need to make use of logical operators.


#### Logical Operators

Logical operators allow us to combine conditional expressions and create compound conditions. For example if we need two things to be `TRUE` to perform an action, or need at least one of two things to be `TRUE`.


#### Logical AND (&&)

If we need multiple things to all be `TRUE` we use logical AND (`&&`). When using logical AND all conditions need to be `TRUE` for the block to run. For example In the code below, if `zombieAttack` is `TRUE` AND `numBullets` is equal to `0` you should run!

```C++
bool zombieAttack = true;
int numBullets = 0;

if(zombieAttack == true && numBullets == 0){
    cout << "Run you fool!!!" << endl;
}
```


#### Logical OR (||)

If we need one OR another condition to be `TRUE` for a set of instructions to execute we use the logical OR operator (`||`). In a compound condition using logical OR the conditions will be evaluated until one results in `TRUE`. For example in our below example if the player has either armor or more than 5 bullets they can fight.

```C++
int numBullets = 0;
bool hasArmor = true;

if(hasArmor == true || numBullets > 5){
    cout << "Let's get ready to rumble!" << endl;
}
```


#### Multiple Logical operators

We can continue to extend our compound conditions with multiple logical operators. For example there is no point in entering into a fight unless there is something to attack. So our previous code has been extended to check three expressions. Now in order to fight there must be a zombie and the player must have either armour or more than five bullets.

```C++
bool zombieAttack = true;
int numBullets = 0;
bool hasArmor = true;

if( (zombieAttack == true) && (hasArmor == true || numBullets > 5) ){
    cout << "Prepare to feel my wrath!" << endl;
}
```

#### Logical NOT (!)

Logical NOT inverts the result of a condition. For example, if you put an exclamation mark in front of `TRUE`, it becomes `FALSE`. Below we have two if statements to check the weather. The first uses the shorthand to check if `isSunny` is `TRUE`. The second uses the logical NOT operator to invert this expression and checks if isSunny is NOT true.

```C++
bool isSunny = true;

if(isSunny){
    cout << "It's sunny, wear suncream" << endl;
}

if(!isSunny){
    cout << "It's not sunny, maybe take an umbrella" << endl;
}
```

&nbsp;
&nbsp;
> **Advanced Note** - In C++ there are alternative "spellings" for the logical operators, such as `and` for `&&`, `or` for `||`, and `not` for `!`.
>
>  ```C++
>  if(not isSunny){
>      cout << "It's not sunny, maybe take an umbrella" << endl;
>  }
>  
>  if( (zombieAttack == true) and (hasArmor == true or numBullets > 5) ){
>      cout << "Prepare to feel my wrath!" << endl;
>  }
>  ```
> These were originally provided for compatibility, and typically their usage is **not** recommended, due to additional visual complexity and verbosity. Despite this, some modern codebases and coding conventions nominate to use `and`, `or`, and `not` for reasons of accessibility and readability. This module will avoid their usage, but they may appear in C++ code elsewhere, depending on the applied conventions.
>
> Further Information
>
> https://en.cppreference.com/w/cpp/language/operator_alternative
&nbsp;
&nbsp;

&nbsp;
&nbsp;
&nbsp;

## Switch Statements

The switch statement offers similar functionality to the `IF` statement but instead of evaluating a condition it evaluates a single value expression. The switch statement will then execute the case that matches the expression. Note in C++ the switch can only accept single exact values (e.g. `int` or `char`).

```
switch (expression) {
    case Value1:
        //do something        	
        break;    
    case Value2:
        //do something        	
        break;   
    default:
       //do something   
}
```

Default cases can be included that will execute if the expression does not match any of the case values (like an `ELSE` in an `IF` statement).

The switch statement ends when it reaches a `break`. If no `break` is found the following case statements will also be executed until a `break` is reached. Therefore, beware of accidentally leaving out a `break` as this may lead to unexpected results. However, there may also be times where you purposely want to leave out the `break` in order to group case values together that should execute the same lines of code, rather than duplicating the code in the cases. For example the code below groups together cases for upper and lower case letter values.

```C++
cout << "Game Over!! Would you like to play again (Y/N)?" << endl;
char input;
cin >> input;

switch (input) {
    case 'Y':
    case 'y':
        cout << "Game Restarting..." << endl;
        break;    
    case 'N':
    case 'n':
        cout << "Game Quitting..." << endl;
        break;
    default:
        cout << "Input not recognised..." << endl;
}
```

&nbsp;
&nbsp;

### Why use a switch instead of an IF statements

When you have many options you need to check the switch statement can provide greater clarity and readability of code. It can also offer some minor performance improvements compared to a long `ELSE IF` statement. However, as the switch statement can only accept single exact values in the expression there will be instances where you will have to use an `ELSE IF` statement instead (e.g. for evaluating ranges). Ultimately the decision on which to use comes down to programmer preference. If you find one easier than the other, use it!

&nbsp;
&nbsp;
&nbsp;

## Loops

Loops are used when we want to execute a code statement or several code statements multiple times. This saves us from repeating code in our programs, which should always be a core aim; to be as efficient as possible and reduce duplication. We can chose to execute a loop a given number of times, or we can keep looping repeatedly until a certain condition is met. C++ has three loops to serve these purposes.

* While Loop
* Do While Loop
* For Loop

&nbsp;
&nbsp;

### While Loop

The `while` loop is useful when we don’t know how many times we want the loop to run and just want it to keep repeating as long as a condition is `TRUE`. Therefore, the `while` loop has similarities to the `IF` statement, but instead of just executing once if a condition is `TRUE` the `while` loop keeps going (or iterating) until the condition is `FALSE`.

```
while ( condition ) {
	// do something WHILE the condition is true;
}
```

The below example shows the `while` loop in action, making use of ```cin.fail( );``` in the condition, which is a great way of doing some simple error checking.

The input stream (```cin```), knows what type of data it is expecting when awaiting user input. If a letter is entered when it's expecting an ```int``` then an error flag will be placed on the input stream and the result of ```cin.fail( );``` will evaluate to `TRUE`. Therefore the `while` loop below will keep checking user input until valid data is entered.

```C++
cout << "Enter your age" << endl;
int age;
cin >> age;
while(cin.fail()){
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Invalid input.\nPlease enter a valid age:" << endl;
    cin >> age;
}
cout << "Your age is: " << age;
```

In the body of the `while` loop we then need to clear the error flag ```cin.clear( );``` and ignore what is left in the input stream as the invalid data will still be there. ```cin.ignore(1000, '\n');``` tells the input stream to ignore the next 1000 characters, or the first new line character it encounters (whichever comes first). As the user will have hit enter when inputting the data it should encounter the new line character first. Now you are safe to ask the user for new data.

&nbsp;
&nbsp;

### Do While

The `do while` loop is a variant of a `while` loop, which evaluates the condition at the bottom of the loop instead of the top. This guarantees the loops code will execute at least once. We can see the `do while` in comparison to the `while` loop below

```
while ( condition ) { //condition check at the top of loop
	// do something WHILE the condition is true;
}
```

vs

```
do {  
	// do something then check the condition;
} while ( condition ); //condition check at the bottom of loop
```

Note with the `do while` loop how the condition is included at the end of the loop after the code block to be executed which still appears within curly braces. Also note the semicolon at the end of the condition.

In our example below we know we always want the user to enter their password at least once, but if its invalid keep asking them. Therefore, with a `do while` loop we guarantee asking and receiving the users password before then checking to see if it matches the stored password.

```C++
string password = "1234password";
string userInput;

do{
    cout << "Enter your Password" << endl;
    cin >> userInput;
}while(password != userInput);

cout << "Welcome to the super secure banking area" << endl;
```

&nbsp;
&nbsp;

### For Loop

The `for` loop is very similar to the `while` loop, however its syntax means we can specify how many times we would like it to run for. When writing a for loop we have space for the *initialisation*, *condition* and *incrementation*.

```
for(initialisation; condition; incrementation){
	//statements
}
```

In the *initialisation* we declare a counting variable (typically named `i`) and set its value for use in the rest of the loop

In the *condition* we evaluate the counting variable against a certain condition. If it's `TRUE` we run the loop, otherwise we exit the loop. Typically this condition will check if the counting variable is less than the number of times we want it to run.

In the *incrementation* we increase the counting variable to ensure the condition will eventually evaluate to `FALSE` (e.g. it is no longer less than the number of times we want it to run).

For instance, if we want a `for` loop to run ten times we can create a variable called ```i``` in the *initialisation* and set it to ```0```, create a *condition* to check if ```i``` is less than ```10```, then use the *incrementation* to add 1 to ```i``` on each iteration. In the example below the statement inside the `for` loop simply outputs the value of i each time (e.g. 0 - 9).

```C++
for(int i = 0; i < 10; i++){
  cout << "I is" << i << "\n";
}
```

&nbsp;
&nbsp;

### Which loop when?

Each loop has unique traits that should make it easy to decide which to use in different scenarios. In simplest terms if you know how many times you want the loop to run you should use a `for` loop. This means `for` loops are typically used in combination arrays (or other container types) as we want to run the loop equal to the number of items stored in the array.

In opposition if you don’t know how many times you want the loop to run, make use of the while loop - picking the do while if you need to guarantee the execution of the code block once before checking the condition.

&nbsp;
&nbsp;

## Arrays

### Recapping the Basics

An array is a type of storage container that can hold a fixed set of values of a single type. While basic variables only store a single value an array stores a series of them. Just like variables, arrays must have a data type (`int`, `double`, `char`, etc), and can only store values of this type. Also once the size of an array has been set it cannot be changed.

### Why use an Array?

Arrays provide a more efficient solution for storing multiple pieces of data than variables.

Take for example this stack of variables that stores five student numbers:

```C++
int studentNumber1 = 323412;
int studentNumber2 = 373622;
int studentNumber3 = 387261;
int studentNumber4 = 318273;
int studentNumber5 = 362719;
```

Now consider we want to store the student number of every individual in Bath Spa University. Using variables alone, we would need over 7000 independent and unique variables! This is unmanageable.

Going back to our five student numbers, we could use one array to store each piece of data. The array could then be represented like this:

| <!-- -->    | <!-- -->    | <!-- -->    | <!-- -->    | <!-- -->    |
|-------------|-------------|-------------|-------------|-------------|
| 323412 | 373622 | 387261 | 318273 | 362719 |

&nbsp;
&nbsp;

### Declaring and Initialising an Array

The below code shows how to declare an array. An array’s dimension is the number of elements it will contain.

```
dataType arrayName[dimension];
```

Notice the only difference between declaring a normal variable and an array is the addition of square brackets to the end of the name, which are used to declare the array size.

Here is an actual example of an array declaration:

```C++
int ages[5];
```

This declares an array that can hold 5 integer values.

There are a few components here that we need to address:

* *Data Type:* The type of data we wish to store (e.g. `int`, `char`, `string` etc)
* *The ```[ ]``` symbols:* This states that what we wish to declare is an array
* *Number of Elements:*  We need to tell the array object how many values we want to store in it. This is so it can allocate computer memory to store the values

The above array has only been declared and is currently an empty array of integers with 5 placeholders for integers available:

| <!-- -->    | <!-- -->    | <!-- -->    | <!-- -->    | <!-- -->    | <!-- -->    |
|-------------|-------------|-------------|-------------|-------------|-------------|
| Index (position) | 0 | 1 | 2 | 3 | 4 |
| Value            |   |   |   |   |   |

*NB: The index (position) of elements in an array starts at 0 and not 1 as you might expect*

There are two ways we can initialise the array and assign values. The first is to access each array index and individually assign a value to each index using the assignment operator.

```C++
ages[0] = 19;
ages[1] = 23;
ages[2] = 22;
ages[3] = 30;
ages[4] = 18;
```

The second and more efficient method is to initialise the values at the same time as declaring the array. To do so we include a comma separated list of the values we wish to assign enclosed in curly braces after the array declaration.

```C++
int ages[] = { 19, 23, 22, 30, 18 };
```

When using the shorthand method the array size inside the square brackets is optional, as the program will simply workout how big the array should be based on the number of values assigned.

&nbsp;
&nbsp;

### Accessing the array

We can access an array in a similar way to accessing a variable, by supplying the name. However, the difference being we need to specify the index we wish to access inside square brackets (known as the subscript operator) after the array name. We did this in the longhand initialisation example above, where each index was accessed individually to assign a value. The below code shows an example of how we might output an array value

```C++
cout << "The age stored at index 2" is << ages[2] << endl;
```

Based on the array declared and initialised previously this should output the value `22`.

&nbsp;
&nbsp;

### Iterating Through the Array

If we wanted to access each array value we could of course do this one by one

```C++
cout << "The age stored at index 0" is << ages[0] << endl;
cout << "The age stored at index 1" is << ages[1] << endl;
cout << "The age stored at index 2" is << ages[2] << endl;
cout << "The age stored at index 3" is << ages[3] << endl;
cout << "The age stored at index 4" is << ages[4] << endl;
```

Yet, this creates duplicate code and as a programmer we want to strive for efficiency and reduce duplication as much as possible. We can make use of loops to reduce the need for repeating code, in particular `for` loops are typically used in combination with arrays.

This is because we use the `for` loop when we know how many times we want the loop to run, and in an array we know how many values there are. Therefore, we can limit the loop to the amount of values contained in the array.

Below we can see an example of how we can output all 5 values in the ages array more efficiently by using a `for` loop.

```C++
for (int i = 0; i < 5; i++){
      cout << ages[i] << endl;
}
```

Remember the `for` loop includes an *initialisation*, *condition* and *increment*. We use the *initialisation* to create a counting variable to run through our array indexes (this variable is typically named ```i``` to stand for index). The *condition* is used to set the limit of our array and the *increment* adds one to our counting variable each time so we can run through all the array indexes. Inside the `for` loop body we can then access each array value by using our ```i``` counting variable to set the index. As this ```i``` variable increases by `1` on each iteration we will be able to access each value.

In our above example we initialise the ```i``` variable at `0` as this is where array indexes starts. The condition is set to *not* go above `4` (runs as long as ```i``` is less than `5`), as the ages array has `5` values with indexes running from `0` to `4`.

Work through this `for` loop one iteration at a time until you fully understand how it works.

&nbsp;
&nbsp;

## Multidimensional Arrays

We can think of arrays as a row of data stored next to each other in columns:

```C++
int ages[] = { 19, 23, 22, 30, 18 };
```

| <!-- -->    | <!-- -->    | <!-- -->    | <!-- -->    | <!-- -->    | <!-- -->    |
|-------------|-------------|-------------|-------------|-------------|-------------|
| ages| 19 | 23 | 22 | 30 | 18 |

However, we can add further rows and columns through the use of multidimensional arrays. The most common is a 2D array which adds additional rows to the array.

&nbsp;
&nbsp;

### Declaring a 2D Array

To declare a 2D array we just need to add an additional set of square brackets when declaring the array. The value given inside the first square brackets defines the number of rows in the array and the value inside the second set defines the number of columns.

Some of you last year used a 2D array to store your vending machine snacks in the Utility App assignment. Below we have declared an empty 2D string array with space for three rows of four columns each

```C++
string snacks[3][4];
```

&nbsp;
&nbsp;

### Initialising a 2D Array

You can initialise a 2D array in a similar fashion to a standard one dimensional array, either individually accessing each index using the subscript operators:

```C++
string snacks[0][0] = "Mars Bar"; //add item in first row & column
string snacks[0][1] = "Snickers"; //add item in first row, second column
string snacks[0][2] = "Bounty"; //add item in first row, third column
string snacks[0][3] = "Wispa"; //add item in first row, fourth column
string snacks[1][0] = "Doritos"; //add item in second row, first column
//etc..
```

Or by using the shorthand method and initialising using a comma separated list immediately after declaration.

```C++
string snacks[3][4] = {
    {“Mars Bar”, “Snickers”,“Bounty”,“Wispa”},//first row
    {“Doritos”, “Wheat Crunchies”,“Nik Naks”,“Quavers”}, //second row
    {“Apple”, “Banana”,“Orange”,“Pear”} //third row
};
```

Note in the example above the use of additional curly braces to wrap each row, these are optional but make it easier to identify the start and end of each row.

&nbsp;
&nbsp;

### Accessing a 2D Array

To access the array we need to specify the array name and index we want to access using the subscript operators. As it's a 2D array we need to specify both the row and the column we want to access.  

```C++
cout << snacks[2][3] << endl; //will output orange based on prior example initialisation
```

&nbsp;
&nbsp;

### Iterating Through a 2D Array

In order to iterate through the entire array we can again make use of `for` loops. However as there are multiple rows we will need to use a nested `for` loop. The outer loop will iterate over the rows, whilst the inner loop iterates through the columns.

```C++
for(int i = 0; i < 3; i++){
    for(int j = 0; j < 4; j++){
        cout << snacks[i][j] << " ";
    }
    cout << endl;
}
```

In the above example, every time the outer loop iterates, the inner one will iterate four times to output each of the snacks in that row. Note the use of each of the counting variables inside the subscript operators to denote which position we wish to access, using ```i``` for the rows and ```j``` for the column.

&nbsp;
&nbsp;

## Functions

### Recapping the Basics

Functions allow us to break our programs down into specific tasks, which can be called again and again when needed. This makes our program easier to understand as larger problems can be broken down into its small logical component parts. Functions also make our programs more efficient as we reduce duplicate code; rather than writing out the same code over and over again, we can place the task in a function and call it when we need to.

Every C++ program has at least one function, which is the ```main()```. Our goal when programming should be to make the main function as simple as possible by passing control to other functions to perform their respective tasks.

&nbsp;
&nbsp;

### Function Structure

The structure of a function is as follows

```
return_type function_name( parameter list ) {
   //body of the function
}
```

**Return type:** specifies the type of data the function should return (e.g. `int`, `bool`, `double`, `string` etc) back to the main program. If the function does not return anything `void` can be used as the return type


**Function name:** Name of the function, this can be anything but usually we specify a name that relates to the task it performs. E.g. a function named `displayMenu` would be sensible for a function that displays a menu of options to the user.


**Parameter list:** When calling a function you can pass it some values that the function can then use to perform its task. We define the parameters a function can be passed in the parameter list. We can specify multiple parameters for use in a function in a comma separated list. For each one we must specify its data type (e.g. `int`, `double`, `string` etc). Parameters are optional, so the list can be left blank.


*Function body:* The function body is where we include our set of statements that define the functions task.

&nbsp;
&nbsp;

#### Simple example

```C++
void sayHello(){
    cout << "Hello World" << endl;
}
```

In our above example the structure of our function is as follows:

**Return type:** we specify `void` as our function doesn’t return a value

**Function name:** Name of the function, this can be anything but usually we specify a name that relates to the task the function performs. So in this example we use` sayHello()`. For a function that displays a menu we might use the name `displayMenu()`;

**Parameter list:** When calling a function you can pass values that the function can then use to perform its task. In this basic example aren’t passing in any values so we leave this parameter list blank.

**Function body:** The function body is where we include our set of statements that define the functions task. This functions task is to simply output Hello World to the console so we have a single output statement

&nbsp;
&nbsp;

### Invoking Functions

To pass control to a function it must be called, or *invoked*. We do this by specifying the function name immediately followed by the arguments to be sent to the function parameters enclosed in parentheses. Even if the function takes no arguments you must include the parentheses, but these can be left empty. For example to invoke our `sayHello()` function our full program would look like this:

```C++
#include <iostream>
using namespace std;

void sayHello(){
    cout << "Hello World" << endl;
}

int main(){
    sayHello();
    return 0;
}
```

&nbsp;
&nbsp;

### Declaring and Defining Functions

Functions should always be written outside of the ```main()``` function. If you have multiple functions, you should place them underneath one another in a logical order. The main function also needs to know that a function exists before it is called, otherwise it will throw an error. Therefore, you should place functions before the program's main function. You to keep your code organised and keep your main function towards the top you can declare and define the function separately.

#### Declaring

Declaring a function refers to letting the compiler know that a function exists within the program. When declaring a function we let the compiler know the return type, the name of the function and any parameters the function takes. Declaring should always be done ahead of the main function.


#### Defining

Defining a function means we specify the full task the function will perform, so alongside all the information included when we declare a function, we also include the function body with the code statements required for our function to perform its task. Defining is typically done after the main function.

Previously the ```sayHello();``` example was declared and defined at the same time. Below however, is an example of how we might declare our function ahead of the main, then define the function later on.

```C++
#include <iostream>
using namespace std;

void sayHello();

int main(){
    sayHello();
    return 0;
}

void sayHello(){
    cout << "Hello World" << endl;
}
```

Declaring and defining functions separately is the most basic form of code organisation we can perform when we first start using functions. Later in the module we will look at how we can further organise our code across multiple files by making use of header files.  

&nbsp;
&nbsp;

### Passing Values

Functions become really useful when you begin passing and returning values. This is what can make your programs more efficient as you can slightly alter the task being performed by the function without needing duplicate code.

For example, instead of a basic function that simply says Hello World all the time (which lets face it is fairly useless), instead we will create a function that takes a string and outputs the message passed to it.

```C++
#include <iostream>
using namespace std;

void logMessage(string msg);

int main(){
    logMessage("Hello CodeLab");
    return 0;
}

void logMessage(string msg){
    cout << msg << endl;
}
```

Our previous ```helloWorld()``` function has only been modified slightly in the above example:

* The function name has been altered to ```logMessage()``` as this is now more appropriate to describe the task being performed
* A parameter has been added to the parameter list (`string msg`), so that the function can accept values being passed to it. Note you can have as many parameters as you wish  and these can be of any data type. The only rules are you specify the data type and provide a variable name that can be used when referring to that parameter in the function (*Note: the name of the parameter does not need to match that of the value being passed in - remember we can pass any value of the parameters type to the function and reuse it multiple times).*
* When invoking the function we now need to include a value (or argument) in the parentheses after the function name as the function is expecting a parameter. When invoking functions with parameters you need to pass values to all the parameters included in the function declaration. In our above example the value “Hello CodeLab” will get passed to the string msg variable in the function
* The output statement in the function body now outputs the msg variable that gets passed in when the function is invoked.

As this function now accepts parameters we can change the value being passed in each time it is invoked and therefore change the message being displayed to the console. For instance take a look at the code below which now makes use of the ```logMessage()``` function three times. The first two times we pass in a string value directly and the program will output `"Hello CodeLab"` followed by `"I love programming"`.

Before we invoke the function a third time, we ask the user what they would like to say and store this input into the string variable userInput. The value the user inputs is then used to set the `msg` parameter. Therefore what the user enters will then get displayed back to the console.

```C++
#include <iostream>
using namespace std;

void logMessage(string msg);

int main(){
    logMessage("Hello CodeLab");
    logMessage("I love programming");

    cout << "What would you like to say" << endl;
    string userInput;
    getline(cin, userInput);
    logMessage(userInput);
    return 0;
}

void logMessage(string msg){
    cout << msg << endl;
}
```

&nbsp;
&nbsp;

### Returning Values

So far when invoking the functions above all the functionality has been performed within the function body and nothing has been returned from the function. This is why we have been using `void` as the function return type.

However there may be instances where we want the function to perform a task and return a value back to the main program (or back to another function it has been invoked from). The returned value may then be used to influence what happens next in the program.

&nbsp;
&nbsp;

#### Greetings Example

Take the example below, in it we have a greetings function that takes an integer parameter. This integer is used within the function to determine if it is morning or afternoon and return a `string` message back to where the function has been invoked. Note that ```string``` has been specified as the function return type as this is the type we want to return from the function

We make use of this function in the main program where we ask the user what the time is and pass the entered value when invoking the function. Notice the invoking of the function has been included within a ```cout``` statement as the value being returned is a `string` and can be directly inserted into the output stream. In essence the call to the ```greetings()``` function gets replaced by the returned value.

When running this program any values below `12` will output *Good Morning*, whilst values above `12` will output *Good Afternoon*

```C++
#include <iostream>
using namespace std;
// return type set to string as this function will return a string value back to main program
string greetings(int time){
    //evaluate int value passed in and set return message
    if(time < 12){
        return "Good Morning";
    }else{
        return "Good Afternoon";
    }
}
int main(){
    cout << "What time is it?" << endl; //ask the user for time
    int userInput; //variable to store user response
    cin >> userInput; //get user input

    //output string returned by function
    cout << greetings(userInput) << endl;     
    return 0;
}
```

&nbsp;
&nbsp;

#### Display Menu Example

This second example uses the returned value from the `displayMenu` function to then determine what happens next in the program. Note that the `displayMenu` function has ```int``` as its return type as this is the data type returned to the main program after the user has selected an option.

As the return type is an ```int``` you will notice the call to the function has been included in the switch statement expression. Remember this function call will get replaced by the returned value so ```displayMenu()``` will become either `1`, `2`, `3`, or `4` based on the user input.

This value can then be evaluated in the switch statement and the program will progress accordingly. Whilst only simple output statements have been used in the switch statement as an example it is easy to see how further functions could be called from here to control the program, e.g. ```displayHighscores()```.

```C++
#include <iostream>
#include <string>
using namespace std;
/* return type set to int as this function will return int value back to main program */
int displayMenu(){     
     //output menu options
    cout << "What would you like to do?" << endl;
    cout << "1: Play Game" << endl;
    cout << "2: View Highscores" << endl;
    cout << "3: Edit Options" << endl;
    cout << "4: Exit" << endl;
    int option; //variable for user input
    cin >> option; //get user input
    return option; //return value user enters back to main program
}
int main() {
    //switch statement to evaluate value returned from display menu function
    switch(displayMenu()){ //call to display menu will become value returned by function (e.g. 1, 2, 3, or 4)
        case 1://if displayMenu value matches case run the code inside case
            cout << "Playing Game" << endl;
            //loadGame(); ← example function that could be called next
            break;
        case 2:
            cout << "Viewing Highscores" << endl;
            //displayHighscores(); ← example function that could be called next
            break;
        case 3:
            cout << "Editing Options" << endl;
            break;
        case 4:
            cout << "Exiting" << endl;
            break;
    }
    return 0;
}
```

&nbsp;
&nbsp;

### Variable Scope

Not a programming technique itself, but an important concept to understand; scope relates to the visibility of the variables we declare in our programs. Where variables are declared influences which parts of the program can then access said variables. There are two types of scope:

* Local - declared inside a block of code `{ }` and only accessible to that block (and any nested blocks).
* Global - declared outside the `main` function and accessible to the entire program.

Last year a number of you declared lots of variables globally to make them easily accessible to the entirety of your program. However, you should aim to limit the amount of global variables you declare and instead make use of function parameters to pass values to different parts of your program. This helps aid the *security* of your code. Review the example code and comments below to understand the visibility of different local and global variables within the sample program.

```C++
#include <iostream>
using namespace std;

int globalVar = 10; //global variable available within rest of program;

void func1(){
    int localVar = 20; //local variable only available within this function
    localVar += globalVar; //notice the use of global variable here
    cout << "Func1: " << localVar << endl;
}

int main() {
    int localVar2 = 12; // local variable only available within whole main function
    localVar2 += globalVar; // notice can also use global variable here
    cout << "Main: " << localVar2 << endl;
    cout << localVar << endl;
    //above line will throw an error as localVar is only available in func1()

    func1(); // call to func1
    int num1 = 10; // num1 available within whole main function
    if(num1 > 9){
        num1++;
        cout << num1 << endl;
        int num2 = 20; // num2 available only with if statement block;
    }
    cout << num2 << endl;
    //above line will throw an error as num2 only available in block it was
    //declared.


    for(int i = 0; i < 20; i++){
        cout << i << endl; //i is declared in the loop so only accessible here      
    }
    cout << "i after loop is" << i << endl; //i is not accessible here            

    return 0;
}
```

&nbsp;
&nbsp;

### Passing by Value vs Passing by Reference

So far, when we have been passing parameters to functions we’ve been passing them by value. This means when a value is passed to the function, rather than passing the actual value itself, a *copy* is made. Any task performed on the value in the function is therefore performed on the *copy* rather than the value passed into the function.

In the majority of instances this is fine, especially with basic data types such as ```int``` and ```char```, which have a low memory footprint. However when using larger data types, or passing containers such as arrays, passing by value can result in unnecessary overhead as there will be two copies of the data in existence while the function is running. There may also be instances where you want modifications on the value passed into the function to persist after the function finished running (which won’t happen if passing by value as the modifications occur on a copy).

An alternative is to *pass by reference*, which means instead of making copies the function works directly on the original parameter values, reducing any potential overhead.

The syntax difference for passing by value versus passing by reference is subtle. To do so we use the address of operator (```&```) when specifying the parameters in the functions parameter list. For instance the address operator ahead of ```msg``` in the example below means any value passed to this function will now be *passed by reference* and not copied, but accessed directly.

```C++
void logMessage(string &msg);
```

So far the difference between passing by value and passing by reference may be confusing. However, take a look at the following code to see it in action.

&nbsp;
&nbsp;

### Passing by Value

```C++
#include <iostream>
using namespace std;

// pass-by-value
void increment(int num) {
    num = num + 1;
    cout << "num in increment " << num << endl; // num is altered here
}

int main() {
    int num = 3;
    increment(num);
    cout << "num in main " << num << endl; // num is not altered here

    return 0;
}
```

This above example *passes by value* just like we are currently used to. If you run the code you should find that num gets increased to `4` in the increment function, but num remains `3` in the main program. This is because a copy of num has been modified in the increment function.

&nbsp;
&nbsp;

### Passing by Reference

```C++
#include <iostream>
using namespace std;

// pass-by-reference
void increment(int &num) { // note the & operator appended before the parameter variable
    num = num + 1;
    cout << "q in increment " << num << endl; // num is altered here
}

int main() {
    int num = 3;
    increment(num);
    cout << "num in main " << num << endl; // num is altered here too

    return 0;
}
```

The only difference with this example and the previous one is the inclusion of the address of operator ahead of the num parameter in the increment function. This specifies the parameter will be *passed by reference* and the value passed to the function will be acted upon directly. Therefore, if you run this code you will notice that num is incremented to `4` in the function and this modification persists on num in the main program is this was the variable directly modified.

&nbsp;
&nbsp;

### Const References

There may be times where you want to pass by reference but don’t want these parameters to be modified. To ensure they don’t get modified in the function you can declare them as `const`.

For example, the below function takes two strings as parameters and returns the result of concatenating them (adding them together). Rather than make copies of the strings being passed in, we can reduce the overhead by passing by reference. However, we want to guarantee that the values passed in (`str1` and `str2` in this case), don’t get modified.

We can do this by declaring these parameters as `const` in the function declaration, which prevents the function from modifying them but offers direct access to them. Thus, `const` references function similar to passing by value, but with efficiency benefits for parameters of larger types.

```C++
#include <iostream>
using namespace std;

string concatenate (const string &s1, const string &s2){
    //any attempt to modify s1 and s2 in the function will cause an error
    //e.g. s1 = "Hello" <-- this won't work
    return s1+s2;
}
int main(){
    string str1 = "Code";
    string str2 = "Lab";
    cout << "Concatenated strings: " << concatenate(str1, str2) << endl;
    return 0;
}
```
&nbsp;
&nbsp;



