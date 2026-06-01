# Chapter 8 - The STL

This chapter builds upon the material introduced in [Chapter 4](../Chapter-04-STL-Arrays-Vectors) and covers further aspects of the Standard Template Library in C++.

* [The STL](#the-stl)
* [Iterators](#iterators)
* [Algorithms](#algorithms)
* [Lambda Expressions](#lambda-Expressions)
* [Other Containers](#other-containers)
  * [Pair](#pair)
    * [Using Auto to Declare a Pair](#using-auto-to-declare-a-pair)
    * [Example - Products](#example---products)
  * [Tuple](#tuple)
    * [Get](#get)
    * [Tie](#tie)
    * [Returning Multiple Values from Functions](#returning-multiple-values-from-functions)
  * [Maps](#maps)
    * [Declaring a map](#declaring-a-map)
    * [Initialising and Adding Map Elements](#initialising-and-adding-map-elements)
    * [Accessing Map Elements](#accessing-map-elements)
    * [Iterating Through a Map](#iterating-through-a-map)
    * [Erasing Elements from a Map](#erasing-elements-from-a-map)
    * [Finding Elements in a Map](#finding-elements-in-a-map)
* [Further STL Reading](#further-stl-reading)
* [Templates](#templates)
  * [Template Functions](#template-functions)
  * [Template Classes](#class-templates)

&nbsp;
&nbsp;

## The STL

As mentioned in [Chapter 4](../Chapter-04-STL-Arrays-Vectors), The C++ Standard Template Library provides access to a comprehensive set of ready made generic classes that can be used to implement data structures and algorithms. The STL has three core components; containers, iterators and algorithms. These components provide useful features for everyday programming applications. The most commons STL containers are arrays and vectors (covered in chapter 4). This chapter looks at iterators, algorithms and other useful containers such as maps.

&nbsp;
&nbsp;

## Iterators

Iterators provide a means for accessing data stored in containers such as arrays and vectors. However, rather than directly returning the value they return the address of the data in memory (like pointers covered in the previous chapter), this address can then be dereferenced (using the dereference operator ```*```) to obtain the value.

To declare an iterator variable you state which type of container we want to iterate upon (e.g. array), followed by the type of data stored in the container (e.g. string) and then scope to the iterator object using the scope resolution operator (```::```).

#### Vector Iterator Declaration

```C++
vector<string>::iterator itr;
```

#### Array Iterator Declaration

```C++
array<string, 4>::iterator itr;
```
*Note from the above example that if declaring an array iterator you also need to specify the array size after specifying the data type, just as you would when declaring a standard library array.*

As noted above the ```.begin()``` and ```.end()``` method calls return iterators pointing to the start or end of ranges such as arrays. Therefore we can use these calls to assign values to the iterator.

```C++
array<string, 4> snacks = {"Mars Bar", "Snickers","Bounty","Wispa"};
array<string, 4>::iterator itr = snacks.begin(); //points to Mars Bar
```

The syntax for declaring an iterator is fairly clunky, so this does offer a good use case for using auto. The iterator type will be automatically deduced from the value assigned.

```C++
array<string, 4> snacks = {"Mars Bar", "Snickers","Bounty","Wispa"};
auto itr = snacks.begin(); //points to Mars Bar
```

Using the increment and decrement operators we can then easily move the iterator through containers and access the elements.

```C++
array<string, 4> snacks = {"Mars Bar", "Snickers","Bounty","Wispa"};
auto itr = snacks.begin(); //iterator that points to Mars Bar
itr = snacks.begin() + 2 //reassigns the iterator to point to bounty
cout << itr << endl; //outputs the address of bounty
cout << *itr << endl; //dereferences the iterator to output bounty
```

Our above example declares a string array, then declares an iterator variable and assigns the address of the first value in the array using ```.begin()```. The iterator value is then reassigned to bounty by using ```.begin()``` but moving this along 2 by using basic math operators. We then output the address where bounty is stored in memory, followed by outputting bounty by dereferencing the iterator. Notice the difference on this last line is the use of the dereference operator (```*``` ).

Similar logic can be used to iterate through the entire array using an iterator instead of standard counting variables in the for loop as shown in the example below. Note the use of auto to easily infer that the ```itr``` variable will be an iterator. This iterator is given its start point using ```.begin()``` in the *initialisation*, the *condition* then checks to ensure the iterator does not go beyond the end, and the increment operators are used to move the iterator to the next address in memory each time the loop runs. This increment works as container values are always stored next to each other in memory.

```C++
array<string, 4> snacks = {"Mars Bar", "Snickers","Bounty","Wispa"};
for(auto itr = snacks.begin(); itr != snacks.end(); itr++){
        cout << *itr << endl; //dereference iterator to access value
}
```

Iterators are used with many of the algorithm library methods available within the STL. For instance the below example shows an iterator being used with the ```.find()``` method to see if an element is present in a string array. If the element is found before the end of the vector the IF statement dereferences the iterator to output the element in the ```cout``` statement.

```C++
vector<string> shoppingList = {"Milk", "Bread", "Coffee" , "Tea", "Sugar", "Bananas", "Apples"};
auto it = find(shoppingList.begin(), shoppingList.end(), "Coffee");
if (it != shoppingList.end()){
    cout << "Found " << *it << "In shopping list \n";
}else{
    cout << "Did not find " << *it << "In shopping list \n";
}
```

&nbsp;
&nbsp;

Further Reading:

* https://en.cppreference.com/w/cpp/iterator/iterator
* [Iterator overview from LinkedIn Learning](https://www.linkedin.com/learning/c-plus-plus-standard-template-library/iterators-overview)
* [Accessing Iterators from LinkedIn Learning](https://www.linkedin.com/learning/c-plus-plus-templates-and-the-stl/accessing-iterators?)

&nbsp;
&nbsp;

## Algorithims

As just discussed Iterators are used with many of the methods available within the algorithm library available within the STL. This library provides a range of methods for performing useful tasks on such as sort, reverse and shuffle.

To access the algorithm library you need to include the algorithm header

```C++
#include <algorithm>
```

Many of the algorithm methods make use of iterators to move through the container using calls to ```.begin()``` and ```.end()``` to define the begin and end points of the range.

Some useful examples of iterators being used in conjunction with containers and methods from the algorithm header are included below:

### Sort - sorts into ascending order

```C++
array<int, 5> numbers = {33, 5, 7, 99, 83};
sort(numbers.begin(), numbers.end()); // ← call to sort here
for(int num : numbers){
   cout << num << " ";
}
```

### Reverse - reverses the order of the array

```C++
array<string, 6> staff = {"Lee", "John", "Ron", "Jake", "Coral", "Sam"};
reverse(staff.begin(),staff.end());
for(string s : staff){
    cout << s << " ";
}
```

### Random_shuffle - shuffles order of elements

```C++
array<int, 10> myInts = {1,2,3,4,5,6,7,8,9,10};
random_shuffle(myInts.begin(), myInts.end());
for(int i : myInts){
    cout << i << " ";
}
```

### Count - counts the number of times an element appears

```C++
array<string, 8> shoppingList = {"Milk", "Bread", "Coffee" , "Tea", "Sugar", "Bananas", "Apples", "Milk"};
int mycount = count(shoppingList.begin(), shoppingList.end(), "Milk");
cout << "Milk appears " << mycount << " times.\n";
```

For the full list of available methods in the algorithm library, including usage examples see:
https://en.cppreference.com/w/cpp/algorithm

&nbsp;
&nbsp;

## Lambda Expressions

Lambda expressions were introduced in C++ to provide a means of creating what are known as inline, or anonymous functions. These are used for short code snippets that don’t require reuse and therefore makes little sense to declare globally as a normal function. 

Lambda expressions are useful for passing functions as arguments to other functions and a prime use case is with the algorithm methods such as sort. By passing the sort method a lambda expression we can specify how we want the data sorted. 

### Lambda Expression format

```C++
auto hello = []( ){
     cout << " Hello World " << endl;
};
```

* ```[]``` - **Capture Clause:** allows you to specify whether you wish to “capture” variables from the surrounding scope for use in the expression, as well as specifying how these should be captured (e.g. by value or by reference)
* ```( )``` - **Parameter list:** works like a normal function and is where you can specify values the lambda function can accept
* ```{ }``` - **Function body:** defines the task the function can perform

Notice that lambda functions have no name, so in this simple example we assign it to a variable called hello. You could then call this expression in the same way you would call a normal function

### Capturing Values

As noted in the previous section, lambda expressions can capture values from the surrounding scope. The capture clause can be used to specify what can be captured and how.

* ```[&]``` - **Capture by Reference** - Capture all surrounding values by reference, meaning it can modify the original value.
* ```[=]``` - **Capture by Value** - Capture all surrounding values by value, meaning the values are copied and modifications only exist on the copy.
* ```[foo,&bar]``` - **Mixed capture** - You can capture some variables by value and others by reference by listing them in the capture clause
* ```[ ]``` - **No captures** - If nothing is specified in the capture clause only values declared locally to the lambda can be used. 

### Lambda use cases

As mentioned in the introduction lambdas can be used for short code snippets that don’t require reuse and therefore makes little sense to declare globally as a normal function. 

A prime use case for lambda expressions is using them with algorithm methods from the STL. These algorithm methods can be customised by passing a function (or lambda expression) as an argument. This is demonstrated in the following examples which shows their use in the ```count_if``` method and ```sort``` method.


#### Example: Count_if

In this example a lambda expression is used in the third argument of the ```count_if``` function to specify what should be counted in the container. The expression will return true if the number in the container is even - therefore all the even numbers get counted.

```C++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    // initialize vector of integers
    vector<int> nums = { 1, 2, 3, 4, 5, 8, 10, 12 };
    
    //count_if with lambda used as third argument to define what should be counted
    int howManyEvens = count_if(nums.begin(), nums.end(), [](int num) {
        return num % 2 == 0;
    });

    cout << "There are " << howManyEvens << " even numbers.";

    return 0;
}
```

#### Example: Sort

In this example we are reading data from a file and storing this information into a vector of employee records. Once the data has been read from the file the ```sort``` method is used to sort the data based on the highest salary. Note the use of a lambda expression as the third argument of the sort method. This lambda expression customises how the sort operation is performed, specifying that the sort should compare the employee salary data member to arrange the records.

```C++
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//structure to store customer data
struct Employee {
    string name;
    int age;
    string pCode;
    double salary;
};

int main() {
    

    vector<Employee> employeeList;//vector of employees

    try {
        string data;//string to store data from file
        ifstream inFile{"employeeData.txt"};//open file
        if (inFile.is_open()) {
            while (getline(inFile, data)) {//read data from file until the end
                Employee e;//create employee
                
                stringstream ss{data};//store data into stringstream
                getline(ss, e.name, ',');//read name
                ss >> e.age;//read age
                ss.ignore(10, ',');//ignore comma
                getline(ss, e.pCode, ',');//read postcode
                ss >> e.salary;//read salary
                ss.ignore(10, '\n');//ingnore newline character
                employeeList.push_back(e);//store employee in vector
            }
        }

    }
    catch (...) {
        cout << "Error processing file" << endl;
    }

    //sort employees from begining to end of vector, and compare adjacent employees based on salary
    //if a is greater than b return true
    sort(employeeList.begin(), employeeList.end(), [](const Employee& a, const Employee& b) {
        return a.salary > b.salary;
    });

    for (Employee e : employeeList) {
        cout << "Name: " << e.name << "\n";
        cout << "Age: " << e.age << "\n";
        cout << "Postcode: " << e.pCode << "\n";
        cout << "Salary: $" << e.salary << "\n\n" << endl;
    }

    return 0;
}
```

### Further Reading

* [Using Lambdas - LinkedIn Learning](https://www.linkedin.com/learning/c-plus-plus-best-practices-for-developers/using-lambdas)
* [Lambda Expressions - LinkedIn Learning](https://www.linkedin.com/learning/c-plus-plus-development-advanced-concepts-lambda-expressions-and-best-practices/lambda-syntax-18745407)

&nbsp;
&nbsp;

## Other Containers

The STL Array and Vector (discussed in chapter 4) are the most common containers and serve most general purposes, with Vector recommended as the default container of choice in C++. There are however a range of other containers available such as pairs, tuples and maps which are discussed below. Beyond these containers the STL also includes container classes for lists, queues, stacks and more. These containers differ in terms of how elements are accessed (e.g random vs sequential access), which then determines how quickly certain tasks can be performed and makes some containers more suitable than others for particular tasks. If you want to delve deeper into the range of STL containers available take a look at the [further resources](#further-stl-reading) at the end of this chapter. 

### Pair

In C++ a pair can hold a pair of values of different types in a single named container. These values can then be accessed by using the access operator (```.```) on the named container followed by either first or second.

To declare a pair in our program we need to specify we want to use the pair template class, then in angle brackets specify the types the pair will hold. Finally we give the pair a name.

```C++
pair<int, string> person;
```

We can include the initialisation of the pair values alongside the declaration by including the values in parentheses after the pair name

```C++
pair<int, string> person(31, "Jake");
```

or by accessing the ```first``` and ```second``` positions after declaration.

```C++
pair<int, string> person;
person.first = 31;
person.second = "Jake";
```

Similarly to output pair values we would use first and second:

```C++
pair<int, string> person(31, "Jake");
cout << "Persons age is: " << person.first << endl;
cout << "Persons name is: " << person.second << endl;
```

Expected output:
```
Persons age is: 31
Persons name is: Jake
```

&nbsp;
&nbsp;

#### Using Auto to Declare a Pair

You could also use the auto keyword to declare your pair in combination with the make_pair() method. The auto keyword will automatically infer that the type your are creating is a pair based on the use of make_pair(). The make_pair() function accepts the values you wish to insert into the pair as values

```C++
auto person = make_pair(31, "Jake");
```

&nbsp;
&nbsp;

#### Example - Products

Think back to last year's vending machine problem. You needed to store the name and price of a series of products. One way of solving this is to store these in individual variables or two sets of arrays. However, with a pair we could group the product name and price values together in one named container.

```C++
pair<string, double> product("Pear", 0.59);
cout << "Product name: " << product.first << endl;
cout << "Product price: £" << product.second << endl;
```

We could extend this further by creating an array of pairs to store multiple products:

```C++
pair<string, double> choc[4] = {
    {"Twix", 0.69}, {"Mars", 0.59}, {"Snickers", 0.99}, {"Bounty", 0.69}
};
```

When initialising an array of pairs we wrap each individual set of pair values in their own curly braces within the initialisation list. We could then use a for loop to easily output these values

```C++
//range based for loop
for(auto &item : choc){
    cout << item.first << " £" << item.second << endl;
}

//standard for loop
for(int i = 0; i < 4; i++){
    cout << choc[i].first << " £" << choc[i].second << endl;
}
```

The example above provides an example of outputting each item in the choc pair array using a range based for loop and a standard for loop.

The above choc array could also be declared using the standard library array and specifying the pair as the type in the array declaration. Also note when initialising the values you need a double set of opening and closing curly braces wrapping the values.

```C++
array<pair<string, double>, 4> choc = {
   { {"Twix", 0.69}, {"Mars", 0.59}, {"Snickers", 0.99}, {"Bounty", 0.69} }
};
```

&nbsp;
&nbsp;

Full documentation on the pair can be found here:
https://en.cppreference.com/w/cpp/utility/pair

&nbsp;
&nbsp;

### Tuple

A tuple is similar to a pair in that it can hold differ types in a single named container. However it has the advantage that we can include more than just two different types. To use tuples we need to include the tuple header.

```C++
#include <tuple>
```

The declaration of a tuple is similar to a pair, with the type of each value to be included specified in the angle brackets after the tuple keyword

```C++
tuple<string, int, char> student("Joe Blogs", 1234, 'B');
```

The auto keyword can also be used in combination with make_tuple

```C++
auto student = make_tuple("Joe Blogs", 1234, 'B');
```

&nbsp;
&nbsp;

#### Get

In order to access the individual values in a tuple to either modify or outputting we need t use the ```get``` function. The syntax for the get function is slightly unusual in that the ```get``` keyword is followed by angle brackets ```<>```, inside which the index of the value you want to get is specified, this is then followed by parentheses () that includes which tuple you want to get this value from. For example the below would output Joe Blogs by getting this element from the student tuple that is declared in the previous example.

```C++
cout << get<0>(student) << endl;
```

&nbsp;
&nbsp;

#### Tie

We can unpack elements from a tuple by using the tie function, which enables us to get the values and immediately assign them to other variables.

```C++
auto student = make_tuple("Joe Blogs", 1234, 'B');
string name;
int id;
char grade;
tie(name, id, grade) = student;
cout << "Name: " << name << " ID: " << id << " Grade: " << grade << endl;
```

If you only want to unpack certain values from the tuple you can use the keyword ignore when calling tie(). For instance, unlike the previous example which unpacks each value from the student tuple, the below example ignores the first two and only unpacks the last

```C++
auto student = make_tuple("Joe Blogs", 1234, 'B');
char grade;
tie(ignore, ignore, grade) = student;
cout << " Grade: " << grade << endl;
```

&nbsp;
&nbsp;

Full documentation on the tuple can be found here:
https://en.cppreference.com/w/cpp/utility/tuple

&nbsp;
&nbsp;

#### Returning Multiple Values from Functions

The use of tie makes tuples useful for returning multiple values from functions. This can be done by specifying tuple as the function return type and then using tie to unpack the values from the tuple that gets returned. For example, below we can see a modified version of our previous code that demonstrates the tuple being returned from a function and unpacked to the individual variables with the use of tie.

```C++
tuple<string, int, char> returnStudent(){ //function to return tuple
    auto student = make_tuple("Joe Bloggs", 1234, 'A'); //make tuple
    return student; //return tuple
}

int main (){

    string name;
    int id;
    char grade;
    //unpack values from returned tuple and tie to variable declared above
    tie(name, id, grade) = returnStudent();
    //output values
    cout << "Name: " << name << " ID: " << id << " Grade: " << grade << endl;

    return 0;
}
```

The above example *‘hard codes’* the tuple that gets returned but this could easily be extended so the function returns a student found from a database of students (e.g. either from a file or within a container of data such as a vector).

If you just had two values you wanted to return from a function you could utilise a pair as the function return type.

```C++
pair<string, double> returnProduct(){ //function to return pair
    auto p = make_pair("Twix", 0.59); //create pair
    return p; //return pair
}

int main (){
    auto product = returnProduct(); //get pair from function
    string name = product.first; //assign name from first pair value
    double price = product.second; //assign price from second pair value
    cout << "Product: " << name << " Price: " << price << endl; //output info

    return 0;
}
```

&nbsp;
&nbsp;

### Maps

Maps are containers for pairs. The first value in the map is the key, which can be used to retrieve elements associated with that key from the map. To use maps we need to include the map header. Maps are similar to dictionaries that exist in other languages such as python.

```C++
#include <map>
```

&nbsp;
&nbsp;

#### Declaring a Map

Maps are declared by typing the ```map``` keyword followed angle brackets within which the types for the keys and associated elements are specified. We then provide a name for the map.

```C++
map<string, string> capitals;
```

&nbsp;
&nbsp;

#### Initialising and Adding Map Elements

Map elements can be initialised alongside declaration by wrapping each individual map pair in their own curly braces within the initialisation list.

```C++
map<string, string> capitals{
    { "Poland", "Warsaw"},
    { "USA", "Washington"},
    { "France", "Paris"},
    { "UK", "London"},
    { "Germany", "Berlin"}
 };
 ```

Map elements can also be initialised after declaration using the following syntax:

```C++
capitals["Spain"] = "Madrid";
capitals["Italy"] = "Rome";
```

The above would add two further elements to the map. The value in the square brackets is the key, which we assign the element to.

The ```insert()``` method can also be used on maps to add new elements. When calling the ```insert()``` method on the map you can use ```make_pair``` within the parameter brackets to add the key and associated element.

```C++
capitals.insert(make_pair("Wales", "Cardiff"));
```
The keys in maps must be unique, so adding an element with a duplicate key will be ignored. For maps with duplicate keys a [multimap](https://en.cppreference.com/w/cpp/container/multimap) can be used.

&nbsp;
&nbsp;

#### Accessing Map Elements

We can access elements in the map similar to how we access elements in an array. However, rather than specify the index of the element we wish to obtain, we specify the key.

```C++
cout << "The capital of Germany is " << capitals["Germany"] << endl;
```

The above will result in the following output:

```
The capital of Germany is Berlin
```

&nbsp;
&nbsp;

#### Iterating Through a Map

We can make use of a range based for loop to easily iterate through the map

```C++
for(auto &c: capitals){
    cout << c.first << " " << c.second << endl;
}
```

This will output all the elements in the map. In order to access the key and associated element of each map value we use first and second like on a pair. Note that map elements get sorted based on their key value. In the case of our capitals example this means the output of our above for loop would be as follows:

```
France Paris
Germany Berlin
Italy Rome
Poland Warsaw
Spain Madrid
UK London
USA Washington
Wales Cardiff
```

If you want an unsorted map, for example one that retains the order elements were initialised in, then you can use the ```unordered_map``` instead. This requires the unordered map header.

```C++
#include <unordered_map>
```

&nbsp;
&nbsp;

#### Erasing Elements from a Map

To erase map elements we can call the ```erase()``` method and specify the key of the element we wish to erase.

```C++
capitals.erase("France");
```

&nbsp;
&nbsp;

#### Finding Elements in a Map

To look for an element in a map we can use the ```find()``` method and specify the key of the element we wish to find. The ```find()``` method returns and iterator to the position where the element is found. We compare the value returned from find against the one returned from the end method (which gives us an iterator to the end of the map). If they are the same this means we have reached the end of the map without finding the element. Therefore, we want the ```.find()``` and ```.end()``` values to **NOT** be equal.  

```
auto finder = capitals.find("China");
if(finder != capitals.end()){
    cout << "The capital of China is" << finder->second << endl;
}else{
    cout << "Capital of China not yet in our database" << endl;
}
```

In the above example you will notice we assign the value returned from the ```.find()``` method to our own iterator called finder (declared using ```auto``` for brevity). We then access this element via the iterator hence the use of the arrow operator (```->second```) as we are not directly accessing the value and cannot use the dot notation like in previous examples.

&nbsp;
&nbsp;

Full documentation on maps can be found at: https://en.cppreference.com/w/cpp/container/map/

&nbsp;
&nbsp;

## Further STL Reading

As noted earlier, the features of the STL are extensive and there are many more container types, iterators and algorithm functions than can be covered here. A number of resources for further exploration have been included below

* [Quick STL Overview on LinkedIn Learning](https://www.linkedin.com/learning/c-plus-plus-essential-training-2/overview-of-the-stl)
* [Quick STL Overview on Study Tonight](https://www.studytonight.com/cpp/stl/stl-introduction)
* [C++ STL Course with exercises on LinkedIn Learning](https://www.linkedin.com/learning/c-plus-plus-standard-template-library/welcome)
* [C++ Templates and the STL course on LinkedIn Learning](https://www.linkedin.com/learning/c-plus-plus-templates-and-the-stl/)
* [Practice It C++: Common Data Structures](https://www.linkedin.com/learning/practice-it-c-plus-plus-common-data-structures/)

## Templates

The STL in C++ makes use of templates. Templates can be used to enable generic programming in C++ which is code that works independent of its type. As well as making use of the predefined templates provided in the STL, we can also create our own template functions and classes. 

### Template Functions

Let's say we wanted to print information of different data types in C++. One method of doing so is to use function overloading and create a different print function for each data type.

```C++
#include <iostream>
using namespace std;

void print(int n) {//int logging function
    cout << n << endl;
}
void print(string msg) {//string logging function
    cout << msg << endl;
}
void print(char l) {//char logging function
    cout << l << endl;
}

int main() {

    print(1);//print int
    print("Hello");//print string
    print('x'); //print char

    return 0;
}

```

With function overloading we need a separate function for each data type we want to log and the compiler determines which needs to be called based on the information passed to it. This is fine but does lead to code duplication. With template functions we can write a single template for the logging function that can accept data of multiple types.

To create a function template the function is preceded by the template keyword and a set of type identifies (specified in angle brackets ```<>```). The type identifier can then be used in the parameter list as placeholders which will  be replaced by the actual types when the program is compiled.

```C++
#include <iostream>
using namespace std;

template<typename T>
void print(T value) {//generic logging function
    cout << value << endl;
}

int main() {

    print(1);
    print("Hello");//print string
    print('x');

    return 0;
}
```

Now we have a program with exactly the same functionality but only requires a single 'generic' function that can accept data of different types. Our program could also be written as follows with the template type explicitly defined when invoking the function, however as shown in the prior example this can be left out if the compiler is able to determine the type from the value passed in (which is the case for our primitive data types).

```C++
#include <iostream>
using namespace std;

template<typename T>
void print(T value) {//generic logging function
    cout << value << endl;
}

int main() {

    print<int>(1);
    print<string>("Hello");//print string
    print<char>('x');

    return 0;
}
```

If we want to return a value from a template function we can use the type identifer as the return type

```C++
#include <iostream>
using namespace std;

template<typename T>
T add(T val1, T val2) {//generic adding function
    return val1 + val2;//return result from function
}

int main() {

    cout << add(5, 6) << endl;//add two ints
    cout << add<string>("Hello", "World") << endl;//concatenate two strings
    cout << add(3.4, 5.6) << endl;//add two doubles

    return 0;
}
```

In the example above we have a generic adding function that can add together values of different types. The result of the addition is returned by the function back to the point of invocation. Note when the ```string``` values are used ```string``` has been explicitly defined as the type when invoking the function, without doing so C++ would default to handling the strings a char pointer which cannot be addeded together and would result in an error. 

&nbsp;
&nbsp;

### Class Templates

Similar to function templates discussed in the previous section a class template in C++ is a blueprint for creating a family of classes, which can then operate on different data types. Class templates offer an additional means of implementing generic programming where code can be written independent of the data types used.

To create a class template the syntax is similar to function templates and the class definition is preceded by the ```template``` keyword and a list of template parameters:

```C++
template<parameters>
```

The parameters are placeholders for the data types used when the class template is instantiated. When instantiating objects from a class template we must specify the data types for the parameters in angle brackets:

```C++
Classname<datatype> objectName;
```

Take the following example of using class templates to create a generic calculator class

```C++
#include <iostream>
using namespace std;

template<typename T>//template specifier & parameter 
class Calculator{
    private:
        T n1, n2;//use template parameter for core data members
    public:
        Calculator(T n1, T n2){//use constructor to set data member
            this->n1 = n1;
            this->n2 = n2;
        }
        T add(){//add function that returns the template value
            return n1 + n2;
        }
        T subtract(){//subtract function that returns the template value
            return n1 - n2;
        }
        T multiply(){//multiply function that returns the template value
            return n1 * n2;
        }
        T divide(){//divide function that returns the template value
            return n1 / n2;
        }
};

int main(){
    Calculator<int> myIntCalc(10, 5);//instantiate an int version of the class

    //run calculations and output returned value
    cout << myIntCalc.add() << endl;
    cout << myIntCalc.subtract() << endl;
    cout << myIntCalc.multiply() << endl;
    cout << myIntCalc.divide() << endl;


    Calculator<double> myDblCalc(1.5, 56.8);//instantiate an double version of the class

    cout << myDblCalc.add() << endl;//run calculations and output returned value
    cout << myDblCalc.subtract() << endl;
    cout << myDblCalc.multiply() << endl;
    cout << myDblCalc.divide() << endl;

    return 0;
}
```

As we have created the calculator class as a template we can use it with numeric values of different datatypes by specifying the datatype instantiating an object from the class. As shown in the example above this means we can run the calculations with integers and doubles without needing two separate classes. Thus template classes can continue enhance the efficiency of our code and further enable code reuse. 

Here's a second example where class templates are used to create a generic array class (similar to the STL). Once implemented we can easily create arrays of different data types from this single blueprint. 

```C++
#include <iostream>
using namespace std;

template<typename T, int size>
class Array {
private:
    T arr[size];//create array of type T set to size
public:
    Array(T val) {//constructor to set initial values
        for (T& v : arr) {//loop the array
            v = val;//set each array value to constructor parameter value
        }
    }
    void printArray() {//printing function
        for (T& v : arr) {//loop the array
            cout << v << ", ";//output each value
        }
        cout << endl;
    }
    void setValue(int index, T val) {//get desired index and value
        arr[index] = val;//set index to given value
    }
    T getValue(int index) {//get index
        return arr[index];//return value at index
    }
};

int main() {
    
    Array<int, 5> intArray(5);//create int array with 5 as initial values

    intArray.printArray();//print whole array
    intArray.setValue(0, 10);//set value at index 0 to 10
    cout << intArray.getValue(0) << endl;//output value at index 0
    intArray.printArray();//print whole array

    Array<string, 5> stringArray("Hello");//create string array with 5 as initial values

    stringArray.printArray();//print whole array
    stringArray.setValue(1, "World");//set value at index 1 to World
    stringArray.setValue(3, "World");//set value at index 3 to World
    stringArray.printArray();//print whole array
}
```

In this example you might notice two template parameters are given when creating the template.

```C++
template<typename T, int size>
```

The first is the placeholder for the type we want the array to be. The second is an int value so we can specify the size of the array when we instantiate objects from the class. When instantiating objects of different types we just need to specify the data type we want to set the placeholder to and then provide a value for the int parameter:

```C++
Array<int, 5> intArray;//creates an int array
Array<string, 5> stringArray;//creates a string array
```

If you were to run the example code the expected output would be:

```
5, 5, 5, 5, 5,
10
10, 5, 5, 5, 5,
Hello, Hello, Hello, Hello, Hello,
Hello, World, Hello, World, Hello,
```

&nbsp;
&nbsp;

### Further Reading

For further information on templates please refer to the following sources:

* [What is a template - LinkedIn Learning](https://www.linkedin.com/learning/c-plus-plus-templates-and-the-stl/what-is-a-template)
* [Understanding templates - LinkedIn Learning](https://www.linkedin.com/learning/c-plus-plus-programming-essential-techniques-and-best-practices-for-developers/understanding-templates?)
* [Templates - cplusplus.com](https://cplusplus.com/doc/oldtutorial/templates/)
* [Function Templates - cppreference](https://en.cppreference.com/w/cpp/language/function_template)
* [Class templates - LinkedIn Learning](https://www.linkedin.com/learning/c-plus-plus-programming-essential-techniques-and-best-practices-for-developers/template-classes)

