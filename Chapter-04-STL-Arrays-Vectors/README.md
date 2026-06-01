# Chapter 4 - STL Arrays & Vectors

This chapter expands our knowledge of containers beyond basic arrays by looking at STL Arrays and Vectors.

* [The STL](#the-stl)
* [Standard Library Arrays](#standard-library-arrays)
   * [Declaring the Array](#declaring-the-array)
   * [Accessing and Iterating Through the Array](#accessing-and-iterating-through-the-array)
   * [Standard Library Class Methods](#standard-library-array-class-methods)
   * [2D Standard Library Array](#2d-standard-library-array)
* [Vectors](#vectors)
  * [Declaring a Vector](#declaring-a-vector)
  * [Initialising a Vector](#initialising-a-vector)
  * [Accessing a Vector](#accessing-a-vector)
  * [Resizing a Vector](#resizing-a-vector)
  * [Vector Class Methods](#vector-class-methods)
  * [Multidimensional Vectors](#multidimensional-vectors)

&nbsp;
&nbsp;

## The STL

The C++ Standard Template Library provides access to a comprehensive set of ready made generic classes that can be used to implement data structures and algorithms. The STL has three core components; containers, iterators and algorithms. These components provide useful features for everyday programming applications. The full extent of which is too much to cover here (we could have an entire module on it), this chapter will focus on STL Arrays and Vectors. Further aspects of the STL are covered in [chapter 8](../Chapter-08-The-STL).

&nbsp;
&nbsp;

## Standard Library Arrays

The arrays we have been using so far are basic ‘inbuilt’ arrays. However, C++ also has an array class included in the standard library that offers additional functionality that can make handling arrays easier. To make use of the standard library arrays we must include the array header

```C++
#include <array>
```
&nbsp;
&nbsp;

### Declaring the Array

The syntax for declaring a standard library array is different to our basic arrays. To do so we must state we want to use the array class, followed by the data type and size of the array inside angle brackets ```< >```. We then name and initialise the array as we would the basic array. See the two examples below:

```C++
array<int, 5> ages = { 19, 23, 22, 18, 13 };//int array with 5 elements
array<string, 4> snacks = {"Mars Bar", "Snickers","Bounty","Wispa"}; //string array with four Elements
```

&nbsp;
&nbsp;

### Accessing and Iterating Through the array

Whilst declaring the array is different to basic arrays, accessing and iterating through a standard library array can be done in exactly the same way that we are used to.

```C++
cout << ages[0] << endl; // will output 19 based on array above

//standard for loop to output all snacks
for(int i = 0; i < 4; i++){
      cout << snacks[i] << endl;
}
//range based loop to output all snacks
for(string s : snacks){
     cout << s << endl;
}
```

&nbsp;
&nbsp;

### Standard Library Array Class Methods

As the standard library arrays are a class, they come with various methods that make working with them easier (similar to the `string` class). Key ones that you will likely make use of are

* **At:** Can be used to access elements in the array, the same as using the subscript operators [ ]. The difference with using at is that it will throw an error at runtime, whilst using the subscript operator will just use a garbage value.
* **Size:** Returns the size of the array, e.g. if five elements the method will return 5. This can be useful for setting for loop conditions
* **Front:** Provides access to the first element
* **Back:* *Provides access to the last element
* **Begin:** Returns an iterator pointing to the beginning of the array
* **End:** Returns an iterator pointing to the end of the array

#### An Example

```C++
array<string, 4> snacks = {"Mars Bar", "Snickers","Bounty","Wispa"};
cout << snacks.at(1) << endl;//returns value at index 1 e.g. snickers
cout << snacks[1] << endl; //does the same as the above

cout << snacks.front() << endl;//returns value at beginning of array (Mars Bar
cout << snacks.back() << endl;//returns value at end of array (Wispa)

// utilise a for loop to run through array
for(int i = 0; i < snacks.size(); i++){ //note use size() in condition
   cout << snacks[i] << ", ";
}
cout << endl;
```

*Further Reading:* http://en.cppreference.com/w/cpp/container/array

&nbsp;
&nbsp;

### 2D Standard Library Array

One slight disadvantage of the standard library array is the verbosity of declaring 2D arrays. The syntax for which is as follows:

```C++
array<array<int, 7>, 2> myArray;
```

This will create an array with two rows and 7 columns, which can be confusing as unlike the built in 2D array declaration the column number comes first due to it being included within the declaration of the row array.

Aside from this slightly awkward syntax for declaring the array, handling the array itself is exactly the same as 2D built in arrays.

&nbsp;
&nbsp;

## Vectors

Vectors are very similar to arrays and are a container that can store multiple values of the same type. The difference with vectors over arrays is that they can be resized, meaning we can add new values or delete existing ones. To access vector functionality we need to add the vector header file at the top of our program

```C++
#include <vector>
```

&nbsp;
&nbsp;

### Declaring a Vector

Declaring a vector is very similar to declaring a standard library array. We specify we want to access the vector class, then in angle brackets specify the type of data the vector will store, before finally providing a variable name for our vector

```C++
vector<int> myIntVector; //declares vector of integers
```

Note unlike declaring a standard library array we do not need to specify the size of the vector, due to the fact it can be resized.

&nbsp;
&nbsp;

### Initialising a Vector

There are different ways we can initialise the values inside a vector. We can use the initialisation list we are familiar with from arrays and include the values we wish to assign in a comma separated list wrapped in curly braces.

```C++
vector<int> myIntVector = { 1, 2, 4, 55, 66, 43 };
```

Or we can initialise a vector with the same value a specified number of times, or with just empty values that can be assigned later by accessing the vector indexes.

```C++
vector<int> myInts(10, 6);//creates a vector with 10 int values all set to 6
vector<int> myInts(10);//creates a vector with 10 int values all set to 0
vector<string> myString(10); //creates a vector with 10 empty string values
```

&nbsp;
&nbsp;

### Accessing a Vector

You can access the values in a vector, to retrieve or modify the data, in the same way you would a standard library array, either using the subscript operators:

```C++
vector<int> myIntVector = { 1, 2, 4, 55, 66, 43 };
cout << myIntVector[1] << endl; //outputs 2
```

Or by using the ```.at()``` method:

```C++
vector<int> myIntVector = { 1, 2, 4, 55, 66, 43 };
cout << myIntVector.at(4) << endl; //outputs 66
```

&nbsp;
&nbsp;

### Resizing a Vector

Adding values to a vector can be done in different ways. We could reassign values using the initialisation list and either increase or reduce the number of values in the vector:

```C++
vector<int> myIntVector = { 1, 2, 4, 55, 66, 43 };
myIntVector = { 1, 2, 4, 55, 66, 43, 8, 100, 22 }; //adds three more values
myIntVector = { 55, 4, 18 }; //alters values and shrinks vector
```

Alternatively we could use the ```.resize()``` method. When calling ```.resize()``` you specify the size you would like to alter the vector to in the method arguments. Specifying a value larger than the current size adds empty values to the end, whilst specifying a value smaller than the current size deletes values off the end.

```C++
vector<int> myIntVector = { 1, 2, 4, 55, 66, 43 };
myIntVector.resize(10); //adds 4 empty values to the end (e.g. 0's)
myIntVector.resize(2); //removes all values from end leaving only 1 and 2
```

Finally, we could utilise the ```.push_back()``` method to add a single value to the end of the vector, or ```.insert()``` method to add a value at the position specified.

```C++
vector<int> myIntVector = {100, 200, 300};
myIntVector.push_back(500); //add 500 to end of vector

//insert 400 at index 3 in myIntVector
myIntVector.insert(myIntVector.begin()+3, 400);

for(int i : myIntVector){
    cout << i << " ";
    //Expected output: 100 200 300 400 500
}
```

&nbsp;
&nbsp;

### Vector Class Methods

Like the standard library array, vectors contain various useful methods that we can utilise to manipulate and work with the vectors we create. We’ve already seen ```.at()``` (used to access the value at a particular index), ```.resize()``` (used to increase/decrease the size of the container), ```.push_back()``` (adds element to end of vector) and ```.insert()``` (adds element(s) at position specified), but there are several other methods that provide us with useful functionality:

* **Reserve:** reserves enough memory for the specified number of elements e.g. `.reserve(40)`; would reserve enough memory for 40 elements to be contained. This can be helpful if we know the size of our vector to prevent numerous reallocations of memory by the vector itself.
* **Capacity:** specifies the number of elements a vector can hold before memory will need to be reallocated.
* **Size:** returns the size of the vector
* **Push Back:** adds a new element to the end of the vector
* **Pop Back:** removes the last element from the vector and reduces size by one
* **Swap:** Swaps values of one vector with another vector.
* **Clear:** Clears all the elements from within the vector
* **Empty:** Returns true if the vector is empty, else it returns false.
* **Front:** Returns value of element at first position in vector
* **Back:** Returns value of element at last position in vector
* **Begin:** Returns iterator pointing to first element
* **End:** Returns iterator pointing to one past the last element
* **Erase:** Removes value at position pointed to by an iterator.

Vectors can also be used with many of the algorithm class methods.

Further Reading: https://en.cppreference.com/w/cpp/container/vector

&nbsp;
&nbsp;

### Multidimensional Vectors

Like arrays we can add additional rows and columns to create multidimensional vectors. The syntax is similar to declaring a multidimensional standard library array, minus the need to specify the row and column size. In this example we create a 2D int vector with three rows and three columns.

```C++
vector< vector<int> > v = {{1,2,3}, {4,5,6}, {7,8,9}};
```

In this more complex example we have a 2D string vector with three rows and four columns. The values stored in this vector list the ‘top teams’ in different European football leagues. We then insert a new row of values to the end of the list to now include teams from an additional country. These values are then output using a nested for loop; the outer loop iterates over the rows, while the inner loop iterates over the columns.

```C++
vector<string> country = {"England", "Spain", "Italy"};//store countries
vector< vector <string> > teamList = {
    {"Newcastle", "Man Utd", "Arsenal", "Chelsea"},
    {"Real Madrid", "Barcelona", "Athletico", "Deportivo"},
    {"Juventus", "Roma", "Inter", "Napoli"}
};
//Add new row of teams and insert at end of team list;
teamList.insert(teamList.end(), {"PSG" , "Nice" , "Monaco" , "Metz"} );
country.push_back("France"); //Push back new country value
for(int i = 0; i < country.size(); i++){
    cout << country[i] << ": ";
    for(int j = 0; j < teamList[0].size(); j++){
        cout << teamList[i][j] << " ";
        if(j == 3)
            cout << "\n============\n";
    }
}
```

&nbsp;
&nbsp;