# Chapter 9 - Enumeration

In this chapter we will take a look at enumerations in C++. First we will take a look at traditional enums before exploring the newer enum classes.

* [What are Enumerations](#what-are-enumerations)
* [Traditional Enums](#traditional-enums)
  * [Declaring an Enum](#declaring-an-enum)
  * [Enum Variable Definition](#enum-variable-definition)
  * [Enumerator Values](#enumerator-values)
  * [Altering Enumerator Values](#altering-enumerator-values)
  * [Comparing Enumerators](#comparing-enumerators)
  * [Casting Integer Values to Enums](#casting-integer-values-to-enums)
  * [Printing Enumerators](#printing-enumerators)
  * [Error Codes Example](#error-codes-example)
  * [Problems with Traditional Enums](#problems-with-traditional-enums)
* [Enum Classes](#enum-classes)
  * [Declaring an Enum Class](#declaring-an-enum-class)
  * [Enum Class Variable Definition](#enum-class-variable-definition)
  * [Benefits of Enum Classes](#benefits-of-enum-classes)
  * [Casting Enums](#casting-enums)
* [Which should be used](#which-should-be-used)

&nbsp;
&nbsp;

## What are Enumerations

An enumeration is a complete, ordered listing of all the items in a collection. The term is commonly used in mathematics and computer science to refer to a listing of all of the elements of a set.

Enumerations are user-defined types made up of named constant values known as enumerators. In C++ there are two types of enumeration.

1. Traditional enum (or plain / old style enum)
2. Enum Classes (or scoped enum - these were introduced in C++11)

Enums can make you programs easier to read and maintain, and offer some safety as the values that can be assigned to an enum variable are limited to those defined in the enumeration list (as opposed to a standard integer value for example that can be assigned any numeric value).

&nbsp;
&nbsp;

## Traditional Enums

### Declaring an Enum

To declare a  traditional enum we use the keyword ```enum``` followed by a name for the enumeration (something descriptive which states what it does). Next we give the enumeration a set of values, known as enumerators. This is done via a comma separated list inside curly braces.

```C++
enum Dayofweek{
  SUNDAY,
  MONDAY,
  TUESDAY,
  WEDNESDAY,
  THURSDAY,
  FRIDAY,
  SATURDAY
};
```

By convention the enumeration name should start with a capital letter and the enumerator values are capitalised.

&nbsp;
&nbsp;

### Enum Variable Definition

To define an enum variable, we specify its type (e.g the name we gave it - Dayofweek), followed a name for the variable. We can then assign this variable one of the enumerator values we gave the enumeration when it was declared.

```C++
Dayofweek day = SUNDAY;
```
&nbsp;
&nbsp;

This is the same as working with a standard data type such as an int or char, we specify the type, give it a name and assign it a value. Thus enums can be viewed as a user defined data type.

### Enumerator Values

Each enumerator is automatically assigned an integer value based on its position in the enumeration list. These values start at `0` and go up in order. Therefore if we were to output the `enum` variable defined in the previous example the printed value would be` 0`.

```C++
Dayofweek day = SUNDAY;
cout << day << endl; // prints 0 to console
```

&nbsp;
&nbsp;

### Altering Enumerator Values

As noted above enum values start at `0`. However, we can change this by explicitly assigning values. For example, it would make more sense for our days of the week to run from `1` - `7`, rather than `0` - `6`. Therefore, I can explicitly assign these values to the enumerators.

```C++
enum Dayofweek {
  SUNDAY = 1,
  MONDAY = 2,
  TUESDAY = 3,
  WEDNESDAY = 4,
  THURSDAY = 5,
  FRIDAY = 6,
  SATURDAY = 7
};
```

In the above example values have explicitly been assigned to each of the value names. We could however only explicitly set the value for Sunday. All subsequent values will then increment in order. The below example is therefore the equivalent of the above.

```C++
enum Dayofweek {
  SUNDAY = 1,
  MONDAY,
  TUESDAY,
  WEDNESDAY,
  THURSDAY,
  FRIDAY,
  SATURDAY
};
```

In our previous examples the enumerator values have gone in ascending order, incrementing by one each time. However, we can alter these value. If a value is not explicitly defined it will take the increment of the previously defined value.

```C++
enum Dayofweek{
  SUNDAY = 55,
  MONDAY,
  TUESDAY,
  WEDNESDAY = 65,
  THURSDAY,
  FRIDAY,
  SATURDAY = 99
};
```

With the above declaration the name values would be as follows:

* Sunday (`55`)
* Monday (`56`)
* Tuesday (`57`)
* Wednesday (`65`)
* Thursday (`66`)
* Friday (`67`)
* Saturday (`99`)

&nbsp;
&nbsp;

### Comparing Enumerators

As enumerators evaluate to integer values a key benefit is that they can be used in a `switch` statement. This can offer much more clarity to the program. Take for instance the example below, which uses the `Dayofweek` `enum` in a switch statement to create a simple alarm system.

```C++
#include <iostream>
using namespace std;

int main() {
    enum Dayofweek {
      SUNDAY = 1,
      MONDAY,
      TUESDAY,
      WEDNESDAY,
      THURSDAY,
      FRIDAY,
      SATURDAY
    };

    Dayofweek day = SUNDAY;

    switch(day){//switch evaluates our enum variable
        case MONDAY:
        case TUESDAY:
        case WEDNESDAY:
        case THURSDAY:
        case FRIDAY:
            cout << "Alarm set for 7.00! Gotta get to Uni" << endl;
            break;
        case SATURDAY:
        case SUNDAY:
            cout << "It's the weekend. No alarm. Time for sleep" << endl;
            break;            
    }
    return 0;
}

```

Traditional enumerators can also be directly compared with integer values. This means we could modify the above example to get the day from the user and compare this value directly against the enumerators in a `switch` statement:

```C++
#include <iostream>
using namespace std;

int main() {
    enum Dayofweek {
      SUNDAY = 1,
      MONDAY,
      TUESDAY,
      WEDNESDAY,
      THURSDAY,
      FRIDAY,
      SATURDAY
    };

    int userInput;
    cout << "What day is it? (1 = Sunday, 2 = Monday etc...)" << endl;
    cin >> userInput;

    switch(userInput){//switch evaluates int variable against enumerators
        case MONDAY:
        case TUESDAY:
        case WEDNESDAY:
        case THURSDAY:
        case FRIDAY:
            cout << "Alarm set for 7.00! Gotta get to Uni" << endl;
            break;
        case SATURDAY:
        case SUNDAY:
            cout << "It's the weekend. No alarm. Time for sleep" << endl;
            break;            
    }
    return 0;
}
```

These previous examples which use the enumerator names in the `switch` statement are much more readable than an alternative version using integers (see below)

```C++
int day = 1;
switch(day){
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        cout << "Alarm set for 7.00! Gotta get to Uni" << endl;
        break;
    case 1:
    case 7:
        cout << "It's the weekend. No alarm. Time for sleep" << endl;
        break;            
}
```

Also, if we were just using integers it is easy assign an invalid value to our day integer variable (e.g. `88`), whilst our `enum` variable can only accept a value specified in the enumeration list

```C++
int day = 88; //this would be accepted

Dayofweek day1 = 88; //this would throw an error
Dayofweek day2 = Wedthursday; //this would throw an error
Dayofweek day3 = MONDAY; //this is accepted
```

&nbsp;
&nbsp;

### Casting Integer Values to Enums

Whilst you can compare enums directly against integer values, by default the compiler will not implicitly convert an `int` to an enumerated value. As noted above, this is useful as it prevents invalid values being assigned to the `enum`. Let's return to the `DayofWeek` example to see this in action.

```C++
Dayofweek day = 23; //this would throw an error
```

However, you can force it to do so by casting the int:

```C++
Dayofweek day = static_cast<Dayofweek>(3)//casting int to enumerator
```

*Note however this means an invalid value e.g. 88 could be assigned to the enumerated type, reducing the safety enumeration can afford. Thus, you should ensure only valid integers are assigned (e.g. ones that match the enumeration list).*

As ints are not implicitly converted you cannot input an `enum` using ```cin```. Again a workaround is to cast the integer value and force the compiler to assign the value to an enumerated type.

```C++
int inputDay;
cout << "What day is it?";
cin >> inputDay;

DayofWeek day = static_cast<dayofweek>(inputDay);
```

If using this workaround the user could easily enter an invalid number (e.g. `88), thus you should implement appropriate error checking to avoid this (the same issue is apparent in our earlier example where the enumerators are directly compared against an user entered int value).

This method also requires the user to know the range of values the enum can take (e.g. how does the user know 1 = Sunday?). An alternative solution is to accept a string value (which is a more obvious input value for the user), then compare the string value to assign the enum. For example:

```C++
enum Dayofweek{
  SUNDAY,
  MONDAY,
  TUESDAY,
  WEDNESDAY,
  THURSDAY,
  FRIDAY,
  SATURDAY
};

Dayofweek day;

string inputDay;

cout << "What day is it?"
cin >> inputDay;

if(inputDay == "Sunday"){
    day = SUNDAY;
}else if(inputDay == "Monday"){
    day = MONDAY;
}else if(inputDay == "Tuesday"){
    day = TUESDAY;
}else if(inputDay == "Wednesday"){
    day = WEDNESDAY;
}else if(inputDay == "Thursday"){
    day = THURSDAY;
}else if(inputDay == "Friday"){
    day = FRIDAY;
}else if(inputDay == "Saturday"){
    day = SATURDAY;
}
```

&nbsp;
&nbsp;

### Printing Enumerators

As shown in a previous example printing an enumerated value will output its corresponding integer value. To print the enumerator name itself one method is to use a function in combination with a `switch` statement to evaluates the `enum` and output its name.

```C++
#include <iostream>
using namespace std;

enum Dayofweek{
  SUNDAY,
  MONDAY,
  TUESDAY,
  WEDNESDAY,
  THURSDAY,
  FRIDAY,
  SATURDAY
};

void printDay(dayofweek d){
    switch(d){
        case SUNDAY:
            cout << "Sunday" << endl;
            break;
        case MONDAY:
            cout << "Monday" << endl;
           break;
        case TUESDAY:
            cout << "Tuesday" << endl;
            break;
        case WEDNESDAY:
            cout << "Wednesday" << endl;
            break;
        case THURSDAY:
            cout << "Thursday" << endl;
            break;
        case FRIDAY:
            cout << "Friday" << endl;
            break;
        case SATURDAY:
            cout << "Saturday" << endl;
            break;
    }
}

int main() {

    Dayofweek day = Monday;

    printDay(day); //outputs 'Monday'

    return 0;
}
```

&nbsp;
&nbsp;

#### Error Codes Example

In an earlier example we assigned random integer values to the `dayofweek` enumerator. Whilst possible, this is admittedly not very useful. However, imagine a program that needs to handle lots of different states represented by codes. In their numerical form these may be fairly random or difficult to remember. Such code could be returned to the main program by a function as shown in the example below:

```C++
int getCurrentLoginState(){
  if(loggedOut()){
    return 3101;
  }else if(emailError()){
    return 3121;
  }else if(passwordError()){
    return 3131;
  }else{
    return 3100;
  }
}
```
If we were then evaluating these codes in the main program we might have a `switch` statement like the below:

```C++
switch(getCurrentLoginState()){
   case 3101:
       cout << "You have been logged out" << endl;
       break;
   case 3100:
       cout << "Login successful. Welcome back!" << endl;
       break;
   case 3121:
       cout << "Email not recognised" << endl;
       break;
   case 3131:
       cout << "Password not recognised" << endl;
       break;      
}
```

The codes used here are not very descriptive and requires a lot of work and care on the part of the developer to remember what everything represents. To make the program easier to read and maintain we could create an enum to give these error codes names which makes things a lot more manageable and meaningful:

```C++
enum State {
   LOGGED_OUT = 3101,
   LOGGED_IN = 3100,
   LOGIN_ERROR_EMAIL = 3121,
   LOGIN_ERROR_PASSWORD = 3131,
};
```

This means we could then use the enumerator names in the switch statement that evaluates the code returned by our ```getCurrentLoginState()``` function.

```C++
switch(getCurrentLoginState()){
   case LOGGED_OUT:
       cout << "You have been logged out" << endl;
       break;
   case LOGGED_IN:
       cout << "Login successful. Welcome back!" << endl;
       break;
   case LOGIN_ERROR_EMAIL:
       cout << "Email not recognised" << endl;
       break;
   case LOGIN_ERROR_PASSWORD:
       cout << "Password not recognised" << endl;
       break;      
}
```

If using enums the ```getCurrentLoginState()``` function could either return an `int` value (e.g the actual error code) as shown before, or the enumerator value as shown below. In either case our switch would be able to evaluate the returned value.
```C++
//EXAMPLE RETURNING THE ENUMERATOR
State getCurrentLoginState(){
  if(loggedOut()){
    return LOGGED_OUT;
  }else if(emailError()){
    return LOGIN_ERROR_EMAIL;
  }else if(passwordError()){
    return LOGIN_ERROR_PASSWORD;
  }else{
    return LOGGED_IN;
  }
}
```

&nbsp;
&nbsp;


### Problems with Traditional Enums

#### Name Collisions

As traditional enums are essentially integers they do have some problems. The first of which is name collisions, a result of the enumerators being exported to the surrounding scope. This can lead to name redefinition errors if you attempt to have enumerations within the same scope that include the same enumerator names, as shown in the example below.

```C++
#include <iostream>
using namespace std;

int main() {

    // Declare a plain enum
    enum TrafficLight
    {
        GREEN,
        YELLOW,
        RED
    };

    //Declare another plain enum
    enum Colour
    {
        GREEN, //redefinition error
        YELLOW, //redefinition error
        RED //redefinition error
    };

    string RED; //this would also cause an error

    return 0;
}
```

The workaround when using traditional enums is to ensure all the names are unique by including a prefix, as shown below.

```C++
int main() {

    // Declare a plain enum
    enum TrafficLight
    {
        T_GREEN,
        T_YELLOW,
        T_RED
    };

    //Declare another plain enum
    enum Colour
    {
        C_GREEN,
        C_YELLOW,
        C_RED
    };

    return 0;
}
```

#### Type Safety

Traditional enums are also not type safe and enumerators from two different enumerations can be compared against each other and be considered equal as their integer values are what is evaluated. This allows you to do things that don't really make sense:

```C++
int main() {

    // Declare a plain enum
    enum Animal
    {
        DOG,
        CAT,
        RABBIT
    };

    //Declare another plain enum
    enum Colour
    {
        GREEN,
        YELLOW,
        RED
    };

    Colour colour = GREEN;
    Animal animal = DOG;

    if(colour == animal){
      cout << "colour is equal to animal" << endl;
    }


    return 0;
}
```

In this above example colour and animal would be considered equal as they share the same integer value.

&nbsp;
&nbsp;

## Enum Classes

To prevent the problems just described C++11 introduced enum classes. These function in the same way as traditional plain enums but are both strongly typed and strongly scoped. We will see what this means in the following examples.

&nbsp;
&nbsp;

### Declaring an Enum Class

To create an enum class we use the keyword ```class``` after the enum keyword:


```C++
enum class Dayofweek{
  SUNDAY,
  MONDAY,
  TUESDAY,
  WEDNESDAY,
  THURSDAY,
  FRIDAY,
  SATURDAY
};
```

&nbsp;
&nbsp;

### Enum Class Variable Definition

Defining a variable of the `enum class` is similar to traditional enums. First we created specify the type (e.g. the name we gave it - `Dayofweek`), followed a name for the variable. We can then assign this variable one of the values we gave the enum when it was declared. However, as enum classes are strongly scoped (meaning the enumerators are not exported to the surrounding scope), rather than being able to access the enumerator names directly (e.g. SUNDAY) we need to use the scope resolution operator ```::``` to access the enumerators. This is what is meant by enum classes being strongly typed and prevents the problem of name collision discussed previously with traditional enums.

```C++
Dayofweek day = DayofWeek::SUNDAY;
```

&nbsp;
&nbsp;

### Benefits of Enum Classes

As the enumerators are part of the `enum class` (strongly scoped) and not exported to the surrounding scope there is no need to prefix enumerator names when needing the same names across multiple enumerations.

```C++
#include <iostream>
using namespace std;

int main() {

    // Declare an enum class
    enum class TrafficLight
    {
        GREEN,
        YELLOW,
        RED
    };

    //Declare another plain enum
    enum class Colour
    {
        GREEN,
        YELLOW,
        RED
    };

    //The above no longer leads to redefinition errors as the enum classes are strongly typed
    TrafficLight light = TrafficLight::GREEN;
    Colour colour = Colour::YELLOW;

    return 0;
}
```

Also as enum classes are strongly typed, enumerators from different enumerations cannot be compared and attempting to do so will cause an error.

```C++
#include <iostream>
using namespace std;

int main() {

    // Declare an enum class
    enum class Animal
    {
        DOG,
        CAT,
        RABBIT
    };

    //Declare another enum class
    enum class Colour
    {
        GREEN,
        YELLOW,
        RED
    };

    Colour colour = Colour::GREEN;
    Animal animal = Animal::DOG;


    if(colour == animal){//this will now throw an error
      cout << "colour is equal to animal" << endl;
    }


    return 0;
}
```

Enumerators from within the same class can still be compared as they are the same type

```C++
#include <iostream>
using namespace std;

int main() {

    //Declare an enum class
    enum class Colour
    {
        GREEN,
        YELLOW,
        RED
    };

    Colour colour = Colour::GREEN;


    if(colour == Colour::GREEN){//this is fine
      cout << "colour is green" << endl;
    }else if(colour == Colour::YELLOW){
      cout << "colour is yellow" << endl;
    }else if(colour == Colour::RED){
      cout << "colour is red" << endl;
    }


    return 0;
}
```
&nbsp;
&nbsp;

### Casting Enums

With enum classes, enumerator values will no longer be implicitly converted to integers. This means you can no longer output an enumerators value as you could with traditional enums. In cases where you need to you can however explicitly convert by casting the enumerator.

```C++
#include <iostream>
using namespace std;

int main() {

    //Declare an enum class
    enum class Colour
    {
        GREEN,
        YELLOW,
        RED
    };

    Colour colour = Colour::GREEN;

    cout << colour << endl; //this won't work
    cout << static_cast<int>(color) << endl; // will print 0


    return 0;
}
```

You can also no longer compare an enumerator directly against integer values as you could with traditional enums, though you can cast an ```int``` to an enumerator. This is demonstrated in the examples below. The first uses a traditional `enum` and directly compares an ```int``` against the enumerators without casting (similar to the week day example shown earlier). The second example uses an `enum class` and requires the ```int``` value obtained from the user to be cast to an enumerator.

##### Using Traditional Enum

```C++
#include <iostream>
using namespace std;

int main() {

    //Declare a plain enum
    enum Colour
    {
        GREEN,
        YELLOW,
        RED
    };

    cout << "Pick a colour:\n";
    cout << "0: Green\n";
    cout << "1: Yellow\n";
    cout << "2: Red\n" << endl;
    int colourInput;
    cin >> colourInput;

    switch (colourInput) {//int value can be directly compared against the enumerators
        case GREEN:
            cout << "You picked Green" << endl;
            break;
        case YELLOW:
            cout << "You picked Yellow" << endl;
            break;
        case RED:
            cout << "You picked Red" << endl;
            break;
    }

    return 0;
}

```

##### Using Enum Class

```C++
#include <iostream>
using namespace std;

int main() {

    //Declare an enum class
    enum class Colour
    {
        GREEN,
        YELLOW,
        RED
    };

    cout << "Pick a colour:\n";
    cout << "0: Green\n";
    cout << "1: Yellow\n";
    cout << "2: Red\n" << endl;
    int colourInput;
    cin >> colourInput;

    switch (static_cast<Colour>(colourInput)) {//int must be cast to an enumerator
        case Colour::GREEN:
            cout << "You picked Green" << endl;
            break;
        case Colour::YELLOW:
            cout << "You picked Yellow" << endl;
            break;
        case Colour::RED:
            cout << "You picked Red" << endl;
            break;
    }

    return 0;
}
```

You can also still use an `enum` variable from an `enum class` within a switch expression as shown in the example below

```C++
#include <iostream>
using namespace std;

int main() {

    //Declare an enum class
    enum class Clan
    {
        WIZARD,
        OGRE,
        LORD
    };

    Clan clan = Clan::WIZARD;

    switch (clan) {//int must be cast to an enumerator
        case Clan::WIZARD:
            cout << "Starting the Wizard adventure..." << endl;
            break;
        case Clan::OGRE:
            cout << "Starting the Ogre adventure..." << endl;
            break;
        case Clan::LORD:
            cout << "Starting the Lord adventure..." << endl;
            break;
    }

    return 0;
}
```

## Which should be used?

Due to the benefits of the `enum class` their use is preferred over traditional enums.

&nbsp;
&nbsp;
