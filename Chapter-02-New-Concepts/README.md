# Chapter 2 - New Concepts

This chapter features some new nice to know concepts that will begin advancing your programming and C++ knowledge.

* [Ternary Operators](#ternary-operators)
* [Range Based For Loop](#range-based-for-loop)
* [Auto Keyword](#auto-keyword)
* [Try Catch](#try-catch)
  * [Simple Example](#simple-example)
  * [Using multiple catch blocks](#using-multiple-catch-blocks)
  * [Real world example](#real-world-example)
  * [Further reading](#further-reading)

&nbsp;
&nbsp;

## Ternary Operators

The ternary operator (or conditional operator as it is also known) offers a way of condensing IF ELSE statements.

```
condition ? trueValue : falseValue
```

It works by first evaluating the condition before the question mark operator. If the condition is TRUE then the first value (before the colon) is assigned as the result. Else, if the condition is FALSE the second (after the colon) value is assigned as the result.

This offers benefits over the IF statement whose results cannot be immediately assigned.

You will often see the ternary operator being used to assign max values, or set high scores among other tasks where you want to immediately assign the result of value comparisons.

Our example below demonstrates how a max value can be assigned more efficiently with the ternary operator than the equivalent IF statement.

```C++
int a = 10, b = 12;
int max = (a > b) ? a : b;
cout << max << endl;
```

vs

```C++
int a = 10, b = 12;
int max;
if(a > b){
    max = a;
}else if(a < b){
    max = b;
}
cout << max << endl
```

This second example shows how it might be used to set a high score. Imagine there are two variables in a game, one to store the players current score and another to store their previous high score. When the game is over we want to check if their current score is more than their high score. If it is we overwrite the previous high score with the current score, else it remains the same.

```C++
highScore = currentScore > highScore ? currentScore : highScore;
```

The results of the ternary operator don’t always need to be assigned, we could use the ternary operator to output messages based on the response. In the example below we use the ternary operator to output “Pass” if mark is more than 40, otherwise output fail.

```C++
int mark = 45;
(mark > 40) ? cout << "Pass" << endl : cout << "Fail" << endl;
```
&nbsp;
&nbsp;

## Range Based For Loop

In C++ the for loop has another syntax that we’ve not yet looked at. This syntax creates a for loop that is used exclusively with ranges. Ranges are sequences of elements such as arrays. The range based for loop is similar to for each loops which are present in other programming languages. The syntax for this type of loop is more condensed than the standard one we’ve been working with so far and includes a declaration and a range, which are separated by a colon.

```
for( declaration : range){
    //do something
}
```

The declaration is a variable that will store each value from the range as it iterates, and the range is the container you want to access (e.g. the name of an array). Therefore to create a range based loop for the ages array we were looking at previously the syntax would be as follows:

```C++
for(int i : ages){
      cout << i << endl;
}
```

Note in the declaration the variable has been given the data type int, as this is the type of data that is stored in the ages array. When using the range based for loop make sure the data type of the variable in the declaration matches that of the container you are accessing.

For example in the code below note how the declaration variable is specified as a string as this is what the array we wish to access contains.

```C++
string staff[] = {"Lee", "Sam", "John", "Ron", "Jake", "Coral"};
for(string name : staff){
    cout << name << " ";
}
```

&nbsp;
&nbsp;

## Auto Keyword

In C++11 the auto keyword was included to allow a variable data type to be inferred from the value it's initialised with.

```C++
int myFirstInt = 5; //explicitly declared integer variable
auto mySecondInt = 6; //variable data type automatically inferred from the value assigned
```

For the declaration of simple variables with one of the core data types (int, char, double), it is best to be explicit and you would not use auto. Auto is typically used when your programs become larger and it can help reduce the verbosity of complex data type names (we will see examples of this later in the module), or in some cases you may not know what type you are dealing with.

You may often seen the auto keyword used within the range based for loop as the declaration variable should have the same type as the range elements. By using the auto keyword you can let C++ deduce the type of the range elements.

```C++
char letters[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd'};
for(auto i : letters){
     cout << i;
}
```

**Further Information**

https://en.cppreference.com/w/cpp/language/auto
https://www.learncpp.com/cpp-tutorial/4-8-the-auto-keyword/

&nbsp;
&nbsp;

## Try-catch

A try-catch block is a programming feature that allows you to handle exceptions in your code. Exceptions are abnormal conditions (such as runtime errors) that occur during the programs execution. These abnormal conditions are events you cannot easily predict or account for with other programming concepts such as if conditions. Try-catch blocks are a great way of handling errors gracefully, as without them the program will just stop its execution.

A try catch block consists of three major elements

* ```try```: Identifies the block of code that might throw an exception
* ```throw```: Used to 'throw' an exception when an error occurs
* ```catch```: Identifies the block of code that will be executed if an exception is thrown in the try block

```C++
try{
    //code to try and run
    throw exception//throw an exception when a problem occurs
}catch(){
    //block to handle the error
}

```

### Simple Example

```C++
try{
    //try to get acceptable user input
    int age;
    cout << "Enter Age" << endl;
    cin >> age;
    if(age < 0 || age > 110){
        throw string("Not a valid age");//throw exception when error occurs
    }else{
        cout << "You are " << age << " years old." << endl;
    }
}catch(string e){//catch the error
    cout << "Error occured: " << e << endl; //output error
}
```

In this example we use the ```try``` block to test some code, which requests input from the user into the ```age``` variable and will ```throw``` an exception if the input is invalid. In the ```catch``` block we catch the error and inform the user an error occurred with an output statement. 

Notice the catch block takes a parameter, which in this example is set to ```string```. This is because the value thrown was a ```string```. The parameter stores the value that was thrown, thus by outputting the ```e``` parameter in the catch block the output of our example when the exception occurs should be:

```
Error occurred: Not a valid age
```

We can throw exceptions of different data types. For example if we wanted to throw an error code we might use an ```int```

```C++
try{
    //try to get acceptable user input
    int age;
    cout << "Enter Age" << endl;
    cin >> age;
    if(age < 0 || age > 110){
        throw 101;//throw exception when error occurs
    }else{
        cout << "You are " << age << " years old." << endl;
    }
}catch(int e){//catch the error
    cout << "Error " << e << " occurred" endl; //output error
}
```

The expected output when an exception occurs in this example would be:

```
Error 101 occurred
```

### Using multiple catch blocks

Our examples above demonstrate how exceptions of different types can be thrown and caught, yet in each instance we were only using a single catch block. It is possible to chain multiple catch blocks together in order to handle different exception types in a single try-catch statement.

```C++
try{
    //try to get acceptable user input
    int num;
    cout << "Enter positive integer" << endl;
    cin >> num;
    if(num < 0){
        throw 'x';//throw exception when error occurs
    }else{
        cout << "You number is " << num << endl;
    }
}catch(int e){//catch int exception
    cout << "Error with number code " << e << " occurred" << endl; //output error
}catch(char e){//catch char exception
    cout << "Error with letter code " << e << " occurred" << endl; //output error
}catch(string e){//catch string exception
    cout << "Error with message " << e << "occurred" << endl;
}catch(...){
    cout << "Unknown error occurred" << endl;
}
```

In the above example our try block requests a positive integer from the user. If a number less than 0 is entered an exception is thrown. Next we have a series of catch blocks linked together each with a different data type used for the parameter. Based on the above what is the expected output...?

...The code throws a ```char``` value when the exception occurs, therefore the output in this instance would be:

```
Error with letter code x occurred
```

You might have noticed the final block uses "three dot" syntax, this catch block will handle an exception of any type, therefore if the above code did not throw an ```int```, ```char``` or ```string``` the exception would be handled by this final catch block with the following expected output

```
Unknown error occurred
```

### Real world example

Earlier it was noted that try-catch blocks are useful for handling abnormal conditions in our code and events we cannot easily predict. Our examples so far don't quite fit this remit as they could easily be handled by an if statement alone:

```C++
int num;
cout << "Enter positive integer" << endl;
cin >> num;
if(num < 0){
    cout << "Please take time to read the instructions!" << endl;
}else{
    cout << "You number is " << num << endl;
}
```

The errors in the previous examples are not really 'exceptional'. We can easily predict the issues that might occur and handle them with if-else conditionals. Therefore rather than using try-catch as a replacement for if-else you should use try-catch to handle errors you cannot easily prevent. These types of errors are typically system generated errors such as a network going down, memory allocation issues, or file no longer being accessible. 

Last year we touched upon the topic of file handling and will revisit the topic in [Chapter 4](../Chapter-04-Files-and-Streams/). When demonstrating file handling last year it was recommended as good practice to check the file you are working with exists and is open before performing any actions on it. This event can be predicted and easily handled with an if statement...

```C++
    ofstream outputFile("program-data.txt"); //declare output file
    if(outputFile.is_open()){ //check file is good
        string userInput; //string variable to temp store user input
        cout << "What's your name?" << endl; //ask for user input
        getline(cin, userInput); //get user input
        outputFile << userInput << endl; //write name to file

        cout << "How old are you?" << endl;//ask for user input
        cin >> userInput;//get user input
        outputFile << userInput; //write age to file.

        outputFile.close();//close the file
    }else{
    cout << "File cannot be accessed. Terminating program" << endl;
    return -1; //exit program
}
```

...However this single if check does not account for any system errors that might occur during the subsequent process of writing to the file. It is feasible that the file might go missing, or might get corrupted during the read operation. Therefore a more robust solution would be to enclose the code in a try-catch block

```C++
    try {
        ofstream outputFile("program-data.txt"); //declare output file

        if (outputFile.is_open()) { //check file is good
            string userInput; //string variable to temp store user input
            cout << "What's your name?" << endl; //ask for user input
            getline(cin, userInput); //get user input
            outputFile << userInput << endl; //write name to file

            cout << "How old are you?" << endl;//ask for user input
            cin >> userInput;//get user input
            outputFile << userInput; //write age to file.

            outputFile.close();//close the file
        }
        else {
            cout << "File cannot be accessed. Terminating program" << endl;
            return -1; //exit program
        }
    }
    catch (...) {
        cout << "Error occurred during the file handling process" << endl;
    }
```

Notice in this try block an exception is not explicitly thrown within the code itself (e.g. there is no ```throw``` statement), instead we are anticipating the system might throw an exception at runtime. 

### Further Reading

For further information on exception handling take a look at the following sources:

* https://www.w3schools.com/cpp/cpp_exceptions.asp 
* https://cplusplus.com/doc/tutorial/exceptions/

