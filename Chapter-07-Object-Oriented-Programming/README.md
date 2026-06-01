# Chapter 7 - Object Oriented Programming

* [What is OOP?](#what-is-oop)
  * [Creating a Class](#creating-a-class)
  * [Class Access](#class-access)
  * [Example Class](#example-class)
  * [Creating Class Instances](#creating-class-instances)
  * [Accessing Object Data Members](#accessing-object-data-members)
  * [Classes Versus Structures](#classes-versus-structures)
  * [Class Methods](#class-methods)
  * [Class Constructors](#class-constructors)
  * [Overloading Class Methods](#overloading-class-methods)
  * [This Pointer](#this-pointer)
  * [Class Destructors](#class-destructors)
* [Organising Code](#organising-code)
  * [Adding Files In Visual Studio](#adding-files-in-visual-studio)
  * [Adding Files In Xcode](#adding-files-in-xcode)
* [Static Class Members](#static-class-members)
* [Static Class Methods](#static-class-methods)
* [Key OOP Concepts](#key-oop-concepts)
  * [Abstraction](#abstraction)
  * [Encapsulation](#encapsulation)
    * [An Example - Cars](#an-example---cars)
    * [Accessing Private Data](#accessing-private-data)
  * [Inheritance](#inheritance)
    * [Creating Subclasses](#creating-subclasses)
  * [Polymorphism](#polymorphism)
* [Class Templates](#class-templates)
* [Further Reading](#further-reading)

&nbsp;
&nbsp;

## What is OOP?

When the C++ language was created the main aim of its original author Bjarne Stroustrup was to add object orientation to the C language. Object oriented programming is based around the concept of objects which can be viewed as user defined data types. In opposition to primitive data types (`int`, `char`, `bool`, etc), which can only contain one piece of information, these object can contain multiple bits of data, and perform various actions (or methods).

We have already been working with different objects by accessing different Classes from the standard C++ library. Strings are one example; when we create a `string` variable we are creating an object from the `string` class, upon which we can perform any of the various methods declared in the `string` class. We have also made use of the file stream class, from which we can create input and output file objects. Furthermore, in the last chapter we looked at the concept of Structures; a user defined data-type that can contain multiple bits of data and has many similarities with Classes that are the focus of this chapter.

In object oriented programming objects are created from Classes, which define what information an object is made up of and what it can do. This information is stored in:

* **Data members** - e.g. variables
* **Methods** - e.g. functions

As we saw in the chapter on structures, different structure objects can store different values in their data members and this data can be modified just like standard variables. The same is true of class objects.

Classes can be used to mimic real world objects and define their characteristics for the purposes of our programs. For example, we might use a class to define a set of enemy robots in a game, or to define products in a shopping app.

The central principles of Object Oriented Programming are thus:

* **Classes** - Hold the definitions of the data (e.g. variables) and procedures (e.g. functions, also known as methods) available to objects of the class
* **Objects** - The name given to individual instances that can be created from the class.

Object Oriented Programming is extremely useful and important in being able to make our code much more efficient as classes create reusable code that we can instantiate multiple objects from. Whilst these objects will each be based off the same underlying code, we can store unique values in their data members which might change how they are used and what they can do in the program. For example, we might have a products class in a supermarket database which includes data for weight and price, objects created from this class would then have very different values dependant on what type of product it is (e.g. banana vs beef).

Let’s think about an example to help visualise what classes are and why they are useful. Imagine we are making a program where we need a database of cars (e.g. Autotrader), or a game where we need different cars to race against each other (e.g. Need for Speed). Typing out the data that defines each car individually would become tiresome, so we need a way of speeding up the process. This is where classes come in...

<p align="center">
  <img width="50%" src="https://jakehobbs.co.uk/markdown_images/car-class.png">
</p>

With a class we can define the main characteristics we want every car in our program to have. Then from this base class we can instantiate multiple objects and set unique values for the data members to create each individual car. For instance from our image above we might have a car class that defines the main characteristics for the cars in our program as Colour, Brand, Make and Fuel Type. From this class we can then begin creating many different types of car such as the three included above. The car class is then likely to include the functions a car can perform such as accelerate, brake, steer, check fuel and many more.

&nbsp;
&nbsp;

### Creating a Class

From our car example we can see that when we create classes we are defining the blueprint for user defined data types. Creating a class in C++ is very similar to creating a structure. We start with the keyword class followed by the class name (like with our variables and function names, we want to give the class a sensible and useful name). The class body is then wrapped in curly braces and the closing curly brace has a semicolon after it. One difference in comparison to creating a structure is that if we want to be able to access the data and methods of a class object elsewhere in our programs we need to specify it as being *“public”* (more on this shortly).

```C++
class ClassName{
    public:
        //data
        //methods
};
```

Classes should be declared outside of the main function and convention is to use a capital letter when naming the class. A class can have as many data members and methods as required.

&nbsp;
&nbsp;

### Class Access

Above it was noted that we need to specify class data and methods as being public if we want to access them in other areas of our program. This is done as by default class data and methods are private. This means the data and methods can only be accessed from within the class itself. There are different types of class access, which can be specified using the access specifier (like public is set in the example below).

* **Public:** Data and Procedures can be accessed in other parts of the program within the scope of the class
* **Private:** Data and Procedures can only be accessed from within the class
* **Protected:** Data and Procedures can only be accessed from within the class and child (or derived classes)

You can mix and match access specifiers in a single class and make certain data and methods public, whilst keeping others private

```C++
class ClassName{
    public:
        //data & methods here will be public

    private:
        //data & methods here will be private

};
```

&nbsp;
&nbsp;

### Example Class

```C++
class Cat{
    public:
       string name;
       string colour;
       int age;
       double weight;
};
```

Here we have an example of a simple class in C++. This class defines the basic characteristics in a blueprint for Cat objects. Each cat in a program using this class would be able to have a name, colour, age and weight.

&nbsp;
&nbsp;

### Creating Class Instances

Creating objects from a class is done in the same way as creating structure objects and can be done in two ways. The first is to create objects alongside the class definition, by including the names for the objects in a comma separated list between the closing curly braces and semi-colon at the end of the class definition. For example below we create four objects from our Cat class.

```C++
class Cat{
    public:
       string name;
       string colour;
       int age;
       double weight;
}felix, tom, bagpuss, simba;
```

The second method is to declare the objects in the main function by specifying the class type followed by the instance name (similar to declaring other variables). Notice the example demonstrates various ways the object members can be initialised, from uninitialised though to brace initialisation used to set each data member.   

```C++
int main() {
    Cat felix; // object created, but members uninitialised
    Cat tom; // object created, but members uninitialised
    Cat bagpuss{}; // default instantiation (e.g. numeric values will be 0, strings empty)
    Cat simba{"Simba","Yellow",3,5.67}; // instantiate members
    return 0;
}
```

&nbsp;
&nbsp;

### Accessing Object Data Members

To access the data members of class objects we use the access operator (again similar to with structures). This allows us to set or modify the values stores in the data members.

```C++
class Cat{
public:
    string name;
    string colour;
    int age;
    double weight;
};
int main() {
    Cat felix;
    felix.name = "Felix";
    felix.colour = "Black";
    felix.age = 14;
    felix.weight = 4.4;

    Cat bagpuss;
    bagpuss.name = "Bagpuss";
    bagpuss.colour = "Pink";
    bagpuss.age = 43;
    bagpuss.weight = 8.9;

    return 0;
}
```

In the above example we use the access operator ( ```.``` ) to set the data member values for two cat objects (felix and bagpuss).

&nbsp;
&nbsp;

### Classes Versus Structures

Currently you might be thinking classes look very similar to structures, and what is the difference between the two? The answer in C++ is very little. Classes can do all the things we did in previous chapter with structures including creating containers of class objects and passing classing objects to functions.

The only real difference is data access. By default class data is private by default, whilst structure data is public (which is why we didn’t need the access specifier), although we could specify that we want structure data to be private.

Classes can also have methods (functions), however in C++ so can structures. Thus, as mentioned the difference is minimal. Typically however it is common practice to use structures when the object just contains data, and use classes when the object is more complex and is required to perform actions and thus includes methods.

&nbsp;
&nbsp;

### Class Methods

Class methods define the tasks that a class object can perform. They are created and act in the same way as standard functions that we might include in our program. Methods in a class can access all of the data defined within the class and can also be passed data from other parts of the program via parameters. To make an object perform the method we use the access operator ( ```.``` ) and invoke the function on the object.

For instance, our below example adds a simple method to make our cat object say hello and its name. In the main program after creating the object we invoke the ```sayHello()``` method on the felix object instantiated from the Cat class.

```C++
class Cat{
public:
    string name;
    string colour;
    int age;
    double weight;

    void sayHello(){
        cout << "Hello my name is: " << name << endl;
    }
};
int main() {
    Cat felix;
    felix.name = "Felix";
    felix.colour = "Black";
    felix.age = 14;
    felix.weight = 4.4;

    felix.sayHello();

    return 0;
}
```

Just like standard functions we can declare then define class methods separately. When doing so we include the declaration inside the class body, then define the method outside of the class. When defining the method outside of the class we need to use the scope resolution operator ( ```::``` ) to prepend the Class name ahead of the method name. We do this to say this is the definition for the method declared within the scope of the respectively named class. Without prepending this the compiler would be looking for a standard function not declared within a class.

```C++
class Cat{
public:
    string name;
    string colour;
    int age;
    double weight;

    void sayHello();
};

void Cat::sayHello(){
    cout << "Hello my name is: " << name << endl;
}
```

&nbsp;
&nbsp;

### Class Constructors

Classes can be given special functions known as constructors that are automatically called when an object of the class is created. Constructors can be useful for initialising the data members of objects. For example it would be useful to have a constructor on our Cat class to initialise the values when it is first created. Constructors have no return type and are always named exactly the same as the class.

```C++
class Cat{
public:
    string name;
    string colour;
    int age;
    double weight;

    Cat();
    void sayHello();
};

Cat::Cat(){
    name = "Kitty";
    colour = "Black";
    age = 1;
    weight = 2.0;
}

void Cat::sayHello(){
    cout << "Hello my name is: " << name << endl;
}


int main() {
    Cat myCat{};//constructor will run when object created
    myCat.sayHello();
    return 0;
}
```

In the above example we have added a constructor to our cat class. This has been declared and defined separately just like the ```sayHello()``` method. In the constructor we initialise the data members of the class object default values. Therefore when the object ```myCat``` is created and the ```sayHello()``` method is called on it the expected output will be

```
Hello my name is: Kitty
```

&nbsp;
&nbsp;

### Overloading Class Methods

Class methods and constructors can be overloaded just like normal functions and the compiler will work out which one to use based on the parameters passed in. For example below we have added an additional constructor to our Cat class. This one has parameters which are used to set the data members of the class object with the values passed in when the object is created.

We can pass parameters to a constructor by including the values in parentheses after instantiating the class object e.g:

```C++
Cat myCat2{"Felix", "Brown", 12, 7.8};
```

```C++
class Cat{
public:
    string name;
    string colour;
    int age;
    double weight;

    Cat();
    Cat(string n, string c, int a, double w);
    void sayHello();
};

Cat::Cat(string n, string c, int a, double w){
    name = n;
    colour = c;
    age = a;
    weight = w;
}

Cat::Cat(){
    name = "Kitty";
    colour = "Black";
    age = 1;
    weight = 2.0;
}

void Cat::sayHello(){
    cout << "Hello my name is: " << name << endl;
}

int main() {
    Cat myCat{}; // uses default constructor
    myCat.sayHello();

    Cat myCat2{"Felix", "Brown", 12, 7.8}; // uses parameterised constructor
    myCat2.sayHello();
    return 0;
}
```

In this example we now have two cat objects being instantiated. This first uses the constructor with no parameters, as none are passed in when the object is created. Therefore this object uses the default values (e.g. Kitty etc). The second object uses the constructor with parameters, meaning the values passed in via the parentheses are used to set the object's data members when its created. The expected output for this example is therefore:

```
Hello my name is: Kitty
Hello my name is: Felix
```

&nbsp;
&nbsp;

### This Pointer

In the previous example the constructor parameters have just been named with a single letter. This isn’t great practice as it's not very revealing as to what the parameters do. It would be better if these constructor parameters were the names of the data members to which they will be assigned. When a class method or constructor has parameter arguments with the same name as a class data members we need to use the ```this``` pointer to explicitly refer to the class members. For example in a method ```this -> name```; would refer to the class member whilst ```name``` refers to the method parameter. Without the this pointer if we tried using ```name = name``` to set the class data member we would actually just be making the method parameter equal to itself. The below code updates our previous example to use the ```this``` pointer when the constructor parameters use the same names as the data members to which they will be assigned.

```C++
class Cat{
public:
    string name;
    string colour;
    int age;
    double weight;

    Cat();
    Cat(string name, string colour, int age, double width);
    void sayHello();
};
Cat::Cat(string name, string colour, int age, double width){
    this->name = name;
    this->colour = colour;
    this->age = age;
    this->weight = w;
}
Cat::Cat(){
    name = "Kitty";
    colour = "Black";
    age = 1;
    weight = 2.0;
}
void Cat::sayHello(){
    cout << "Hello my name is: " << name << endl;
}

int main() {
    Cat myCat{};
    myCat.sayHello();

    Cat myCat2{"Felix", "Brown", 12, 7.8};
    myCat2.sayHello();
    return 0;
}
```

&nbsp;
&nbsp;

### Class Destructors

As well as constructors, classes can be given destructors, which are special functions that are called automatically when a class object gets destroyed (e.g. goes out of scope). The look very similar to constructors as they must also have exactly the same name as the class, however to differentiate them a tilde character (`~`) is included at the beginning. Unlike constructors, destructors cannot accept parameters, therefore you can only have one destructor per class as they cannot be overloaded.

Our simple example program with the cat class has been updated to include a destructor, which includes a basic output message. This will be executed when the myCat object that is instantiated in this example goes out of scope, which in this case with when the program ends (e.g the return statement is reached).

```C++
class Cat{
public:
    string name;
    string colour;
    int age;
    double weight;

    Cat();
    Cat(string name, string colour, int age, double width);
    ~Cat();
    void sayHello();
};
Cat::Cat(string name, string colour, int age, double width){
    this->name = name;
    this->colour = colour;
    this->age = age;
    this->weight = width;
}
Cat::Cat(){
    name = "Kitty";
    colour = "Black";
    age = 1;
    weight = 2.0;
}
Cat::~Cat(){
    cout << name << " has been destroyed" << endl;
}
void Cat::sayHello(){
    cout << "Hello my name is: " << name << endl;
}
int main() {
    Cat myCat{}; // constructor runs
    myCat.sayHello();
    return 0; // destructor runs
}
```

Expected output:

```
Hello my name is: Kitty
Kitty has been destroyed
```

&nbsp;
&nbsp;

## Organising Code

With the addition of classes our programs are becoming more complex and add to the number of things declared outside of the main function. As we begin to add more classes and functions it is easy to see how this might become difficult to navigate. For that reason we want to be able to organise our code effectively.

In C++ it is common practice to include classes across two files.

* *Header (.h)* - includes all the declarations (the interface)
* *Cpp (.cpp)* - includes all the definitions (the implementation)

For our previous cat example the header file (```.h```) would include the class declaration including the data members and method declarations. Note on Xcode the header might have the ```.hpp``` extension

```C++
//CAT.H
#include <iostream>
using namespace std;

class Cat{
public:
    string name;
    string colour;
    int age;
    double weight;

    Cat();
    Cat(string name, string colour, int age, double width);
    ~Cat();
    void sayHello();
};
```

The cpp file (```.cpp```) would then include the definitions of any class methods, constructors and destructors. Note at the top of the file we need to link to the header file using an include statement (just like you do with ```iostream``` and ```string```). For user created files the include should specify the file name, which should be written inside double quotation marks

```C++
//CAT.CPP
#include "Cat.h" //include cat header file

Cat::Cat(string name, string colour, int age, double width){
    this->name = name;
    this->colour = colour;
    this->age = age;
    this->weight = width;
}

Cat::Cat(){
    name = "Kitty";
    colour = "Black";
    age = 1;
    weight = 2.0;
}

Cat::~Cat(){
    cout << name << " has been destroyed" << endl;
}
void Cat::sayHello(){
    cout << "Hello my name is: " << name << endl;
}
```

To gain access to these files in the main program we would then also need to link to the header file by using an include statement.

```C++
// MAIN.CPP
#include <iostream>
#include "Cat.h" //include cat header file
using namespace std;


int main() {
    Cat myCat{};
    myCat.sayHello();

    return 0;
}
```

Making use of header files and accompanying `.cpp` files is not just limited for when you begin adding classes to your programs. They can be used to organise programs that make use of lots of functions. In this case you would include the function declarations in the header file and the full definitions in the `.cpp` file.


&nbsp;
&nbsp;

## Static Class Members

[In an earlier chapter](../Chapter-03-Furthering-Functions#static-function-variables) we introduced the static keyword and discussed its meaning in relation to functions. Now we will take a look at its meaning when used within classes. Static variables in a class are initialised just once, this means they are shared by all objects of the class. Thus, rather than every instance of the class being able to have assigned a unique value for the data member, if the variable is static the value remains the same for all instances.

When using a static class member you must initialise its value outside of the class using the scope resolution operator (```::```).

In the example below we have a basic class with a single static data member. This is then initialised to the value one outside the class using the scope resolution operator. We then create an instance of this class and assign the value 2 to the static data member. A second instance is created and the value 3 assigned to the static data member. Finally we access the num value via each object to output its value. In both output statements this value will be three as the static data member is shared by all class objects. Thus, the final value that was assigned is the one that currently persists. If the data member was not declared as static then the values output would be 2 and 3. As the static data members are independent of any of the class objects they can be accessed directly via the scope resolution operator (`MyClass::num`).

```C++
class MyClass{
public:
    static int num; //declare static variable
};
int MyClass::num = 1; //init static variable

int main() {
    MyClass obj1{};
    obj1.num = 2; //assign 2 to static variable

    MyClass obj2{};
    obj2.num = 3; //assign 3 to static variable

    cout << obj1.num << endl; //outputs 3
    cout << obj2.num << endl; //also output three

    return 0;
}
```

&nbsp;
&nbsp;

## Static Class Methods

Similar to static data members in a class, static methods also do not depend on an instance of the class and the function is shared by all objects and can even be invoked if an object has not been instantiated. Static methods cannot access non static data members and whilst they can be invoked via a class object they are typically invoked via the class name and scope resolution operator ( ```::``` ).

The following example uses a static variable to keep track of the total number of dog objects created, incrementing the value via a constructor and then outputting the value via a static function.

```C++
class Dog{
public:
    static int totalDogs; //declare static variable

    Dog(){
        totalDogs++;
    }
    static void getNumDogs(){
        cout << "Total dogs in program " << totalDogs << endl;
    }
};
int Dog::totalDogs = 0;

int main() {

    Dog::getNumDogs();

    Dog fido{};
    Dog rex{};
    Dog colin{};

    Dog::getNumDogs();

    return 0;
}
```

The fact static functions operate independent of class objects is demonstrated by using the `getNumDogs()` method both before and after objects are instantiated. Thus the expected output of this program is:

```
Total dogs in program 0
Total dogs in program 3
```

&nbsp;
&nbsp;

## Key OOP Concepts

### Abstraction

Abstraction is the idea of how we characterise classes in our program and the information we decide to include in our blueprint. For example our earlier examples using a Cat class included data members for name, colour, age and weight. This is an abstract idea of what we’ve decided a cat is for the purposes of our program.

If we were to create this program on a different day we might have different purposes and therefore our abstract idea of a cat might change. This time we might need to include breed alongside name, colour, age and weight.

With abstraction in mind rather than including every possible characteristic of an object, we instead only define what is relevant to the purposes of our program at that time.

&nbsp;
&nbsp;

### Encapsulation

Encapsulation refers to the visibility or accessibility of data in our programs. Earlier in this chapter we looked at access specifiers and discussed how class data is private by default. By including the public access specifier we make the data and methods of classes accessible across other parts of our program.

However, the reason data is private by default is because it is common practice and advisable to encapsulate as much class information as possible. This makes your programs more secure as data can’t easily be modified by other parts of the program. Thus, you should only make public what really needs to be accessed by other parts of the program.

Take banking software as an example, you wouldn’t want to make the ```accountBalance``` data member public as this offers the potential for other parts of the program to directly access and modify this value. This might then result in an account losing all its money. Instead you would want to make ```accountBalance``` private and provide methods that allow the data to be read, but not necessarily written to.

If the rest of the program doesn’t need to utilise a variable in your class, but that variable is essential for other aspects of the class to function it should be private. This will also make it easier to alter your program, especially if other people are utilising your code (e.g if it’s distributed as a library), as you’ll be able to make modifications to private functions and variables without harming how other people may have implemented what is public. This is about interface (what others see) vs implementation (how actions are performed behind the scenes). If you make implementation alterations these should leave the interface intact.

&nbsp;
&nbsp;

#### An Example - Cars

```C++
class Car
{
  private:
    int vel;
    int travelTime;
    int mass;

  public:
    int getDistance()  {
       return (vel*travelTime);
    }
    int getMomentum()  {
        return (mass*vel);
    }
};
```

Take the above class as an example. This class has three data members which are declared as private. These data members are important to the functionality of a car but knowledge of them is not necessary in order to utilise the public methods ```getDistance();``` or ```getMomentum();``` or understand what they are going to do.

If we were creating objects of this car class in our program we do so knowing we can get information about the car’s distance and momentum, but without needing to know what’s being used to make those calculations. It also means if this class was part of a third-party library various people might be using, the developer of this class  could make alterations to these calculations (e.g. to improve them by adding other variables (the implementation), without altering how they are used (e.g. calling the function remains the same even if the calculation is returned by different variables (the interface)).

You will have seen this in action already throughout CodeLab. For example when using the algorithm or string class you will have used methods such as ```.find()```, ```.compare()```, or ```.sort()```. When using these methods you know what parameters these take and how to use them (the interface), but you most likely have no idea how the result is actually being calculated behind the scenes (the implementation). The likelihood is there may be private data members at work that you don’t know exist, or really need to know exist.

&nbsp;
&nbsp;

#### Accessing Private Data

With the above in mind it is good practice to keep your data members private when working with classes. However there will be times where you want to access and modify these values. Methods created for this purpose are known as getter (retrieve data) and setter (modify / assign data) methods.

Lets modify out earlier cat example so it now uses private data members and getter and setter methods to access the private data

```C++
#include <iostream>
using namespace std;

class Cat{
    //no access specifier so data will be private
    string name;
    string colour;
    int age;
    double weight;

public://make methods public
    //SETTERS - assign passed in value to data member
    // need this pointer as method parameter is the same name
    void setName(string name) { this->name = name; }
    // need this pointer as method parameter is the same name
    void setColour(string colour){ this->colour = colour; }
    //don't need this pointer as method parameter name differs
    void setAge(int yrs){ age = yrs;}
    //don't need this pointer as method parameter name differs
    void setWeight(double kg){ weight = kg;}

    //GETTERS - simply return data member back to program
    string getName(){ return name; }
    string getColour(){ return colour; }
    int getAge(){return age; };
    double getWeight(){ return weight; }

    //constructor
    Cat(string name, string colour, int age, double width);
    //destructor
    ~Cat();
    //say hello function declaration
    void sayHello();
};

void Cat::sayHello(){
    cout << "Hello my name is " << name << endl;
}

Cat::Cat(string name, string colour, int age, double width){
    // need this pointer as constructor parameters use same name
    this->name = name;
    this->colour = colour;
    this->age = age;
    this->weight = width;
}
Cat::~Cat(){
    cout << name << " has been destroyed" << endl;
}
int main() {
    //create cat object and use constructor initialisation
    Cat felix{"Felix", "Brown", 14, 8.5};

    //use setter methods to reassign values
    felix.setAge(15);
    felix.setColour("Grey");

    //use getter methods to retrieve and output data
    cout << "Cat is called " << felix.getName() << endl;
    cout << felix.getName() << " is " << felix.getAge() << " years old" << endl;
    cout << felix.getName() << " is " << felix.getColour() << " and weighs " << felix.getWeight() << endl;

    return 0;
}
```

&nbsp;
&nbsp;

### Inheritance

One of the benefits of OOP is code reuse, which as mentioned previously should be a general goal of programming; to make your code as efficient as possible and avoid writing the same thing twice where possible.

We can enhance reuse with classes through inheritance. With inheritance we can create a base class for an object that defines the key overarching characteristics every object should have. Then in addition to this we create subclasses that inherit the data and methods of the base class, but can also add their own to create more unique objects.

This is visualised below where we have an Animal class as the base that contains key characteristics that every animal might have. From this we have two subclasses (dog and cat), that inherit these characteristics, but also add their own which are unique to that species. For example cats and dogs make different noises when they ‘speak’.

<p align="center">
  <img width="50%" src="https://jakehobbs.co.uk/markdown_images/inheritance.png">
</p>

We could expand this example further and have subclasses of our Dog / Cat that contain specific attributes of different breeds. We can also easily add more animals (e.g human / bird etc), without having to rewrite all of the core data and methods that define the base Animal class.

In C++ you can have multiple layers of inheritance, where a subclass can inherit from multiple base classes. But this can quickly get confusing and it’s therefore common just to inherit from one base class. Languages like Java prevent multiple inheritance

&nbsp;
&nbsp;

#### Creating Subclasses

To create a subclass and inherit from another, we create our class as usual, but after the class name we append a semicolon, followed by the keyword `public` and then the class we wish to inherit from. This means we make the information from the parent class public (accessible) to the subclass. If we want to make data members available to subclasses they must either be made public, or protected. Public will make them available to the entire program, whilst protected will only make them available to the subclasses.

```C++
//PARENT BASE CLASS
class Animal{
    //protected data accessible to subclasses
protected:
    string name;
    int age;
    double weight;
public:
    // public methods
    void eat(){
        cout << "Nom Nom Nom!" << endl;
    }
    void die(){
        cout << "Oh no " << name << " died!" << endl;
    }
    void move(){
        cout << name << " is walking" << endl;
    }
};
//CHILD SUBCLASS
class Cat: public Animal{
    //private data
    string breed;
public:
    //public methods
    void meow(){
        cout << "Meow, my name is: " << name << endl;
    }
};
//CHILD SUBCLASS
class Dog: public Animal{
    //private data
    string breed;
    string skills[3];
public:
    //public methods
    void woof(){
        cout << "Woof Woof, my name is: " << name << endl;
    }
};
```

&nbsp;
&nbsp;

### Polymorphism

Polymorphism means many forms. In programming this means our program will automatically perform the correct behaviour when multiple options are available. We’ve already encountered this. Take the + sign. When working with integers the plus sign will add them together. Yet, when working with strings it will concatenate them (link them together). We don’t need to instruct our program to do that, it performs the correct behaviour automatically depending on the data type it's working with. We’ve also seen polymorphism when overloading functions. In this case we can have multiple functions of the same name and the compiler will determine which one to use based on the parameters passed to the function.

In OOP with classes, polymorphism means we can override core behaviour inherited from another class. We can see this in action if we expand our previous animal example and add a bird subclass. Let’s say the move function in our animal class accounts for animals that walk on the ground with 2 / 4 feet. Our bird subclass might therefore wish to override this move function to take into account that birds fly when they move. Similarly a fish subclass might override the move function to enable swimming.The appropriate move functionality will automatically be used dependant on what type of object is being used.

<p align="center">
  <img width="50%" src="https://jakehobbs.co.uk/markdown_images/polymorphism.png">
</p>

The above diagram is translated into the following code, to create the classes. If we were to then create some objects from these classes (e.g. A dog called Fido, a cat called Felix and a bird called Percy) and call the move method on each one our output would be as follows:

```
Fido is walking
Felix is walking
Percy is flying
```

This is because the dog and cat objects (Fido and Felix) inherit the move functionality from the Animal class, whilst the bird class overrides this behaviour with its own move function.

```C++
//PARENT BASE CLASS
class Animal{
    //protected data accessible to subclasses
protected:
    string name;
    int age;
    double weight;
public:
    // public methods
    void eat(){
        cout << "Nom Nom Nom!" << endl;
    }
    void die(){
        cout << "Oh no " << name << " died!" << endl;
    }
    virtual void move(){
        cout << name << " is walking" << endl;
    }
};

//CHILD SUBCLASS
class Cat: public Animal{
    //private data
    string breed;
public:
    //public methods
    void woof(){
        cout << "Meow, my name is: " << name << endl;
    }
};

//CHILD SUBCLASS
class Dog: public Animal{
    //private data
    string breed;
    string skills[3];
public:
    //public methods
    void woof(){
        cout << "Woof Woof, my name is: " << name << endl;
    }
};

//CHILD SUBCLASS
class Bird: public Animal{
    //private data
    string breed;
public:
    //public methods
    void squawk(){
        cout << "Squak, my name is: " << name << endl;
    }
    void move(){
        cout << name << " is flying" << endl;
    }
};
```

You might notice in the code above that the move method in the parent animal class is specified as being virtual (```virtual void move()```). This ensures the correct function is called if the child class is referred to via a pointer or reference of the parent class. For example, bird could be passed to a function parameter that has the type Animal) and if the move function was not virtual the compiler would shortcut to the Animal move function rather than the bird override. Virtual ensures this shortcut does not take place.

&nbsp;
&nbsp;

## Further Reading

* [Chapter 1 of Programming Foundations: Object-Oriented Design on LinkedIn Learning](https://www.linkedin.com/learning/programming-foundations-object-oriented-design-3/object-oriented-thinking?)

&nbsp;
&nbsp;