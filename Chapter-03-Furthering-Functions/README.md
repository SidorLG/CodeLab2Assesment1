# Chapter 3 - Furthering Functions

In this chapter we refresh and advance our knowledge of functions in C++. The use of functions is critical for any good programmer. Thus, getting to grips with functions and learning how to use them effectively should be seen as a key learning objective.

* [Recapping the Basics](#recapping-the-basics)
  * [Function Structure](#function-structure)
  * [Invoking Functions](#invoking-functions)
  * [Passing Values](#passing-values)
  * [Returning Values](#returning-values)
  
* [Advancing our knowledge](#advancing-our-knowledge)
  * [Passing by Value vs Passing by Reference](#passing-by-value-vs-passing-by-reference)
    * [Passing by Value](#passing-by-value)
    * [Passing by Reference](#passing-by-reference)
    * [Const References](#const-references)
  * [Default Parameters](#default-parameters)
  * [Function Overloading](#function-overloading)
  * [References](#references)
  * [Static Function Variables](#static-function-variables)
  * [Recursion](#recursion)

&nbsp;
&nbsp;

## Recapping the Basics

>*This section provides an abridged recap of key function related concepts covered in CodeLab I. For a longer recap on all the function concepts delivered in CodeLab I revisit the section on functions in [Chapter 1](../Chapter-01-C++-Refresher/#functions)*

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

**Return type:** specifies the type of data the function should return (e.g. int, bool, double, string etc) back to the main program. If the function does not return anything void can be used as the return type


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

**Return type:** we specify void as our function doesn’t return a value

**Function name:** Name of the function, this can be anything but usually we specify a name that relates to the task the function performs. So in this example we use `sayHello()`. For a function that displays a menu we might use the name `displayMenu()`;

**Parameter list:** When calling a function you can pass it some values that the function can then use to perform its task. In this basic example aren’t passing in any values so we leave this parameter list blank.

**Function body:** The function body is where we include our set of statements that define the functions task. This functions task is to simply output Hello World to the console so we have a single output statement

&nbsp;
&nbsp;

### Invoking Functions

To pass control to a function it must be called, or *“invoked”*. We do this by specifying the function name immediately followed by the arguments to be sent to the functions parameters enclosed in parentheses. Even if the function takes no arguments you must include the parameter list parentheses, but these can be left empty. For example to invoke our `sayHello()` function our full program would look like this:

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

### Passing Values

Functions become really useful when you begin passing and returning values. This is what can make your programs more efficient as you can slightly alter the task being performed by the function without needing duplicate code.

For example, instead of a basic function that simply says Hello World all the time (which lets face it is fairly useless), instead we will create a function that takes a `string` parameter and outputs the message passed to it.

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
* A parameter has been added to the parameter list (`string msg`), so that the function can accept values being passed to it. Note you can pass as many arguments as you wish into a function and these can be of any data type. The only rules are you specify the data type and provide a variable name that can be used when referring to that parameter in the function (*Note: the name of the parameter does not need to match that of the value being passed in - remember we can pass any value of the parameters type to the function and reuse it multiple times).*
* When invoking the function we now need to include the relevant arguments in parentheses of the function call. When invoking functions with arguments you need to pass values to all the parameters included in the function declaration. In our above example the value “Hello CodeLab” will get passed to the `string msg` variable in the function
* The output statement in the function body now outputs the msg variable that gets passed in when the function is invoked.

As this function now accepts arguments we can change the value being passed in each time it is invoked and therefore change the message being displayed to the console. For instance take a look at the code below which now makes use of the ```logMessage()``` function three times. The first two times we pass in a string value directly and the program will output `“Hello CodeLab”` followed by `“I love programming”`.

Before we invoke the function a third time, we ask the user what they would like to say and store this input into the string variable `userInput`. The value the user inputs is then used to set the `msg` parameter. Therefore what the user enters will then get displayed back to the console.

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

Take the example below, in it we have a greetings function that takes an integer parameter. This integer is used within the function to determine if it is morning or afternoon and return a `string` message back to where the function has been invoked accordingly. Note that ```string``` has been specified as the function return type as this is the type we want to return from the function.

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

## Advancing our knowledge

In the remainder of this chapter we will extend our knowledge of functions in C++ by looking at some new and more advanced concepts

### Passing by Value vs Passing by Reference

So far when we have been passing parameters to functions we’ve been passing these by value. This means that when a value is passed to the function, rather than passing the actual value itself a copy is made. Any task performed on the parameter in the function is therefore performed on a copy rather than the value passed to the function.

In the majority of instances this is fine, especially with basic data types such as ```int``` and ```char```, which have a low memory footprint. However when using larger data types, or passing containers such as arrays, passing by value can result in unnecessary overhead as there will be two copies of the parameter in existence while the function is running. There may also be instances where you want modifications on the value passed into the function to persist after the function finished running, which won’t happen if passing by value as the modifications occur on a copy.

Instead what we can do is pass by reference, which means instead of making copies the function works directly on the original parameter values. Therefore reducing any potential overhead.

The syntax difference for passing by value versus passing by reference is subtle. To pass by reference we use the address of operator (```&```) when specifying the parameters in the function declaration. For instance the address operator ahead of ```msg``` in the below example means any value passed to this function will now be passed by reference and not copied, but accessed directly

```C++
void logMessage(string &msg);
```

So far the difference between passing by value and passing by reference may be confusing. However, take a look at the following code to see it in action.

&nbsp;
&nbsp;

#### Passing by Value

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

This above example passes by value just like we are currently used to. If you run the code you should find that `num` gets increased to `4` in the increment function, but `num` remains `3 in the main program. This is because a copy of `num` has been modified in the increment function

&nbsp;
&nbsp;

#### Passing by Reference

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

The only difference with this example and the previous one is the inclusion of the address of operator ahead of the `num` parameter in the increment function. This specifies the parameter will be passed by reference instead of by value and the value passed to the function will be acted upon directly. Therefore, if you run this code you will notice that `num` is incremented to `4` in the function and this modification persists on `num` in the main program as this was the variable directly modified.

&nbsp;
&nbsp;

#### Const References

There may be times where you want to pass parameters by reference but don’t want these parameters to be modified. To ensure they don’t get modified in the function you can declare them as `const`.

For example the below function takes two strings as parameters and returns the result of concatenating them (adding them together). Rather than make copies of the strings being passed in, we can reduce the overhead by passing by reference. However, we want to guarantee that the values passed in (`str1` and `str2` in this case), don’t get modified.

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

### Default Parameters

In C++ we can include default values for function parameters. This means that if no values are specified when invoking the function the default values will be used. To include a default value for a parameter you can use the assignment operator and provide the desired value when declaring the function. Let's use our earlier `logMessage` function as an example.

Here you will see “Hello Word” has been assigned as the default value for the msg parameter. In the main program the function is then invoked twice. The first time “Hello CodeLab” is passed in as a value, therefore this will override the default and be output to the console. The second time the function is invoked no parameter is passed and therefore the default will be used.

```C++
#include <iostream>
using namespace std;

void logMessage(string msg = "Hello World"){ //default value included
    cout << msg << endl;
}
int main(){
    logMessage("Hello CodeLab");//passed in value, will override default

    logMessage(); //no parameter passed, default will be used

    return 0;
}
```

You can give some parameters default values and others not in the same function. However, if doing so defaults should be assigned right to left. For example in the program below we have a simple sum function, which has two parameters, both of which have been given defaults.

```C++
#include <iostream>
using namespace std;

int sum(int a = 10, int b = 5){ //function with default int values
    return a+b;
}

int main(){
    //passing in 20 here overrides first default value (e.g. 10)
    int result = sum(20);
    cout << result << endl; //will output 25
    return 0;
}
```

If we were to add another parameter to the sum function (e.g. ```int c```), we would have to specify a default argument as the preceding parameter has one. Similarly ```int b``` must have a default value in this example because ```int a``` has one. We could however not specify a default for ```a``` and keep the default on int ```b```.

This is shown in the example below where a third parameter is added and given a default value. The defaults are then assigned right to left, with the left most value not given a default. Therefore, when invoking the function at least one value must be passed in for int a, the others can be omitted and the defaults will be used.

```C++
#include <iostream>
using namespace std;

int sum(int a, int b = 5, int c = 40){ //function with some defaults
    return a+b+c;
}

int main(){
    /*
    - Have to pass first value for a as there is no default,
    - Second value passed in overrides b
    - No third value provided so default of 40 used
    */
    int result = sum(11, 10);
    cout << result << endl; //will output 61
    return 0;
}
```

&nbsp;
&nbsp;

### Function Overloading

C++ allows you to have two or more functions that use the same name. This is called function overloading. In order to do so the different functions must have either different parameter types or a different number of parameters. Functions cannot be overloaded by just changing the return type.

When invoking overloaded functions the compiler will determine which function to use based on the parameter values provided when calling the function. Overloading saves you from having to come up with multiple different names for functions that perform very similar tasks. For instance our example below includes 4 functions that all display information to the console. However each displays slightly different data. Rather than name them all slightly differently we can use the same function name and the compiler will work out which to use based on the data passed in.

```C++
#include <iostream>
#include <string>
using namespace std;
void display(int a){
    cout << "Integer value is: " << a << endl;
}
void display(double a){
    cout << "Double value is: " << a << endl;
}
void display(string a){
    cout << "String values is: " << a << endl;
}
void display(string name, int age){
    cout << "My Name is: " << name;
    cout << ", I am " << age << " years old." << endl;
}
int main(){
    display(10); //will use integer function (first one)
    display(5.435); //will use double function (second one)
    display("Hello World"); //will use string function (third one)
    display("Jake Hobbs", 30); //will use function with string and int
    return 0;
}
```
&nbsp;
&nbsp;

### References

We have already touched upon the concept of references in our exploration of functions and the different ways values can be passed. One of the methods for passing values is to pass by 'reference'. But what is a reference in C++?

References are variables in C++ that act as an alias for another variable. These references are declared using the ampersand operator (```&```).

```C++
int num = 10;
int& numRef = num;
```

In our above example we declare a reference variable ```numRef``` which refers to the variable ```num```. This means both ```num``` and ```numRef``` are essentially the same variable, we've just created another name through which we can access ```num```. Any changes we makes to ```num``` would be reflected in ```numRef``` and visa versa.

This is what is happening when we pass by reference. When we set function parameters to be a reference we turn them into an alias for the value being passed, thus avoiding the copying of the values and meaning any changes made on the alias in the function is reflected on the original value.

&nbsp;
&nbsp;

### Static Function Variables

The static keyword has different meanings in C++ depending where it's used. The first example we are going to look at is static variables inside functions.

When a variable is declared as static in a function, space for the variable gets allocated only once for the duration of the program. Therefore, even if the function is called multiple times the variable does not get reallocated and thus the value will persist through to subsequent function calls. You can think of declaring something static as saying that the variable sticks around, maintaining its value, until the program completely ends. Therefore the use of static can be useful for preserving information.

This is demonstrated in the following two simple programs. The first doesn’t declare the ```count``` variable in the ```demo()``` function as static. Therefore, every time the function gets called the count variable gets reallocated in memory and released as soon as the function ends. The resulting output is therefore:

```
0 0 0 0 0
```

```C++
#include <iostream>
using namespace std;

void demo()
{
    // standard int variable
    int count = 0;
    cout << count << " ";
    // value is incremented
    // however the value is released from memory at end of function
    count++;
}

int main(){
    for (int i=0; i<5; i++){
        demo();
    }
    return 0;
}
```

The second example declares count as static in the function. Therefore the variable gets allocated once for the duration of the program and its value persists through multiple calls. As the value gets incremented each time the function is called the output will therefore be:

```
0 1 2 3 4
```

```C++
#include <iostream>
using namespace std;

void demo()
{
    // static variable
    static int count = 0;
    cout << count << " ";

    // value is updated and
    // will be carried to next
    // function calls
    count++;
}

int main(){
    for (int i=0; i<5; i++){
        demo();
    }
    return 0;
}
```

Static function variables can be useful for keeping track of the number of times a function has been called or storing values that need to be shared by all instances of a function.

&nbsp;
&nbsp;

### Recursion

Recursion is programming technique where a function calls itself. The techniques is used as a means of solving problems by breaking down larger problems into smaller sub problems of itself. Recursion is useful for a variety of problems, most notably sorting, search and tree traversal algorithms. Recursion should be used carefully as it's possible to write a function that calls itself infinitely which would utilise excess memory and lead to a stack overflow. 

To avoid the issue of infinite recursion a recursive function should include a base condition. This is a terminating condition, which when met will stop any further recursive calls from happening (similar to conditions used in loops). Therefore, the basic structure of a recursive function is as follows:

```
functionName(...){
    if(base condition){
        //stop recursion
    }else{
        functionName(...)//recursive call
    }
}
```

When recursively calling the function you should make sure you are making progress towards the base case. Here's a simple example:

```C++
#include <iostream>
#include <string>
using namespace std;

void recurse(int num) {
	cout << "Hello" << endl;//output hello
	if (num == 0) {//base case
		return;//terminate the recursion
	}
	else {
		recurse(num-1); //recursive call which reduces num by one each time
	}
}

int main() {

	recurse(5);//invoke the recursive function

	return 0;
}
```

In this example we initally invoke our function with the value `5` by passing this value to the ```num``` parameter. Inside the function we output "Hello" then test our base case condition. If ```num``` is `0` we terminate the function, otherwise we call the function again and pass in ```num-1```. This recursive call moves us towards the base case by subtracting `1` from `num` each time the recursive call is made. Therefore the second time the function is called `4` gets passed to ```num```, then `3`, then `2`, then `1`, then `0`; at which point out base case condition is met and the recursion ends. If you were to run the above code without the base case the program would crash with a stackoverflow.

Let's look at a slightly more complex example which uses recursion to determine the factorial of a given number, which is the product of all postive integers less than or equal to the given number. The factorial of 5 for example would be `5 * 4 * 3 * 2 * 1`, which equals `120`. 

Recursion is useful here as with each recursive call we want to find the factorial of the number `1` less than the given number, thus with each call we are simplifying the problem and moving towards the base case. Here is the code to find the factorial of a given number using recursion...

```C++
#include <iostream>
using namespace std;

int factorial(int num) {
	if (num == 1) {//base case
		return 1;//return 1 (e.g. the factorial of 1)
	}
	else {
		return num * factorial(num-1); //recursive call which reduces num by one each time
	}
}

int main() {

	cout << "Enter a number" << endl;
	int input;
	cin >> input;
	cout << "The factorial of your number is: " << factorial(input) << endl;

	return 0;
}
```

Understanding how recursion works can be tricky... When each call to the function is made an instance of the function is created in the programs memory (e.g added to what is known as the stack). These are stacked on top of each other and don't get released from the programs memory until a return statement is met in the function, or the execution of the function reaches its terminating brace (```}```). Therefore, as recursion calls a function from within itself the function that gets added to the programs memory last will be the first one to be released (and in our factorial example the first to return a value).

To understand how the factorial example is working let's consider the program step by step by assuming the user enters the value `5`:

* Step 1: call `factorial(5)` - *call 1*
* Step 2: call `factorial(4)` - *call 2*
* Step 3: call `factorial(3)` - *call 3*
* Step 4: call `factorial(2)` - *call 4*
* Step 5: call `factorial(1)` - *call 5*
* Step 6: base case met return `1` to *call 4*
* Step 7: return` 2 * 1` to *call 3*
* Step 8: return `3 * 2` to *call 2*
* Step 9: return `4 * 6` to *call 1*
* Step 10: return `5 * 24 `to the main function
* Output resulting value to console (e.g. 120)

This can be visualsed as follows:

<p align="center">
  <img width="80%" src="https://jakehobbs.co.uk/markdown_images/recursion.png">
</p>

As explained above when a function is called recursively an entirely new instance of that function will be created in the programs memory, this memory footprint will include new copies of any variables declared locally in the function. Therefore recursion should be used with caution as it can quickly lead to high memory usage if not used appropriately. As shown in these examples a recursive function should include a base case that each recursive call works towards (e.g. the problem gets smaller each time). 

Recursion should not be used to just to make a process loop. This was witnessed many times when reviewing Utility App programs last year, where functions had been called from within themselves to make the program run again. Dependant on what subsequent options the user selected this could result in numerous instances of the function(s) in the programs stack and potentially result in a stackoverflow. If you are wanting to make the same process run again you should use the aptly named loops!

&nbsp;
&nbsp;

#### Further Reading

For further information on recursion see the following sources:

* https://www.w3schools.com/cpp/cpp_functions_recursion.asp
* https://www.youtube.com/watch?v=Mv9NEXX1VHc
