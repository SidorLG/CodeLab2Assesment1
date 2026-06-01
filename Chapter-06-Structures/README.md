# Chapter 6 - Structures

* [What are Structures?](#what-are-structures)
    * [Declaring a Structure](#declaring-a-structure)
    * [Creating Structure Objects](#creating-structure-objects)
    * [Initialising Object Data Members](#initialising-object-data-members)
    * [Containers of Structure Objects](#containers-of-structure-objects)
    * [Structures as Function Parameters](#structures-as-function-parameters)
* [Combining File Handling and Structures](#combining-file-handling-and-structures)

## What are Structures?

Structures are user defined data types than can be used to group multiple pieces of data together. Unlike variables which only contain a single piece of information or containers such as arrays which can only hold data of the same type, structures can contain data of different types under one name.

Once a structure has been declared we can create multiple objects (variables) from this type and each one can have unique values for the data contained inside. Structures are useful for representing simple real world objects that contain multiple pieces of information such as products, books or films.

Imagine a library database that stores records of all the books the library has. Obviously each book has a title, so we could record all the books in a string array. However, books have much more information than just a title, including author (`string`), the number of pages (`int`), price (`double`), ISBN number (`int`), genre (`string`), etc…. We wouldn't want to create arrays for all these different pieces of information as it would be too difficult to keep all the records in sync.

Instead we can make use of a structure which can contain all of this information in a single type in what is known as its data members. The structure defines the characteristics of an object and from this we can create multiple objects (variables) each with unique data.

&nbsp;
&nbsp;

### Declaring a Structure

To declare a structure type we use the keyword ```struct```. We then give it a name and specify the required members (individual data) between curly braces. The terminating curly brace must be followed by a semi-colon. The structure should be declared outside the main function and convention is to start the structure name with a capital letter.

```C++
struct Books{ // declare book structure
    string title;
    string author;
    string subject;
    int book_id;
    int pages;
    double price;
};
```

Above we can see an example of the earlier described book structure. Here you can see how a single structure can hold data of different types inside a single named type. The data inside the structure are known as its members. We can include as many members as required to define the characteristics of the object we wish to represent in the program.

&nbsp;
&nbsp;

### Creating Structure Objects

There are two ways of creating individual objects (or variables) from a structure. The first is to declare them when the structure type is declared. To do this we include the variable names for the individual objects in a comma separated list after the terminating curly brace of the structure (but before the semi colon). For example the code below would create three individual book objects from the book structure

```C++
struct Books{ // declare book structure
    string title;
    string author;
    string subject;
    int book_id;
    int pages;
    double price;
} myBook, secondBook, finalBook;
```

The second method is to declare them in main just like other basic variables. For this you need to specify the structure type (e.g. Books), followed by the variable name for the individual objects. The code below demonstrates this method by again creating three individual book objects.

```C++
#include <iostream>
#include <string>
using namespace std;

struct Books{ // declare book structure
    string title;
    string author;
    string subject;
    int book_id;
    int pages;
    double price;
};

int main(){

    Books myBook, secondBook, thirdBook;

    return 0;
}
```

&nbsp;
&nbsp;

### Initialising Object Data Members

Currently the three books created in the previous example have no values assigned to their data members. There are two ways we can assign values. The first is via an initialisation list that can be included alongside the object declaration. When using the initialisation list the values should be provided in the same order as the data members are declared in the structure.

```C++
#include <iostream>
#include <string>
using namespace std;

struct Books{ // declare book structure
    string title;
    string author;
    string subject;
    int book_id;
    int pages;
    double price;
};

int main(){

    Books myBook{ "Lord of the Rings", "J.R.R. Tolkien", "Fantasy",
                   12345, 1454, 7.99 };

    Books mySecondBook{}

    return 0;
}
```

The above creates an object (`myBook`) from the Books structure and assigns the following values to its data members

```
Title:		Lord of the Rings
Author:		J.R.R Tolkien
Subject:	Fantasy
Book Id:	12345
Pages:		1454
Prices:		7.99
```

You will notice a second object (`mySecondBook`) has been created but with an empty set of braces. This is will assign default values to all of the data members (e.g. `0` for numeric types or an blank string for string values). Omitting the braces, as per the prior example, means the data members are completely uninitialised, which could cause errors if you attempt to access them before assigned a value. 

Another method for assigning values is to access each data member of the object individually using the member access operator ( ```.``` ). This method can be used to first initialise values, but would also be used if we need to reassign values (e.g. reduce the price). The below example uses this method, providing the same values as the previous example.

```C++
#include <iostream>
#include <string>
using namespace std;

struct Books{ // declare book structure
    string title;
    string author;
    string subject;
    int book_id;
    int pages;
    double price;
};

int main(){

    Books myBook;
    myBook.title = "Lord of the Rings";
    myBook.author = "J.R.R. Tolkien";
    myBook.subject = "Fantasy";
    myBook.book_id = 12345;
    myBook.pages = 1454;
    myBook.price = 7.99;
    return 0;
}
```

The member access operator would also be used if we wanted to access and output the values stored in an object. For example, continuing with our book structure below initialises the data members with an initialisation list, then outputs each value.

```C++
int main(){

    Books myBook{ "Lord of the Rings", "J.R.R. Tolkien", "Fantasy",
                   12345, 1454, 7.99 };

    cout << "Title: " << myBook.title << endl;
    cout << "Author: " << myBook.author << endl;
    cout << "Subject: " << myBook.subject << endl;
    cout << "ID: " << myBook.book_id << endl;
    cout << "Pages: " << myBook.pages << endl;
    cout << "Price: " << myBook.price << endl;

    return 0;
}
```

&nbsp;
&nbsp;

### Containers of Structure Objects

Just like a basic data types such as an `int`, we can create containers (e.g. arrays) of structure objects. This can make it easy to handle large sets of data and iterate through them using loops. Declaring a container of structures is the same as it would be for a basic data type, you just need to specify the structure name as the type of data you want the array to store.

```C++
Books library[5]; //array of books
```

We can initialise these books using an initialisation list with the container declaration. The below example demonstrates this with a standard library array:

```C++
Books library[5]{ {
  {"Lord of the Rings", "J.R.R. Tolkien", "Fantasy", 12345, 1454, 7.99},
  {"Harry Potter", "J.K. Rowling", "Fantasy", 12346, 323, 4.69},
  {"The Beach", "Alex Garland", "Travel", 12347, 435, 2.99},
  {"Veg", "Jamie Oliver", "Cookery", 12348, 249, 17.50},
  {"A Christmas Carol", "Charles Dickens", "Drama", 12349, 532, 2.48}
 } };
//Note the double curly braces before and after the initialisation of the structure values.
```

We could then use a for loop to iterate over the array and output the values of each book

```C++
for(int i = 0; i < 5; i++){
        cout << "Book " << i << endl;
        cout << "=======" << endl;
        cout << "Title: " << library[i].title << endl;
        cout << "Author: " << library[i].author << endl;
        cout << "Subject: " << library[i].subject << endl;
        cout << "ID: " << library[i].book_id << endl;
        cout << "Pages: " << library[i].pages << endl;
        cout << "Price: " << library[i].price << endl;
        cout << endl;
}
```

&nbsp;
&nbsp;

### Structures as Function Parameters

As structures are just user defined data types we can also pass them to functions like we would any other type of data. To do so we simply specify the structure name followed by a variable name in the parameter list of the function declaration.

For example, let’s modify our previous example that outputs the values of an array of books and move the printing task into its own function. We will then pass the book we want to print as an argument when invoking the function. It's usually a good idea to pass a structure by reference (`&`) to reduce potential overhead of passing by value and making a copy of the object being passed.

```C++
#include <iostream>
#include <array>
#include <string>
using namespace std;

struct Books{ // declare book structure
    string title;
    string author;
    string subject;
    int book_id;
    int pages;
    double price;
};

/* function which takes books object as parameter. Note the book is passed as const reference.This is because don’t want the expense of copying it, but want to ensure it doesn’t get modified. */
void printBook(const Books &b){     
    cout << "Requested Book" << endl;
    cout << "==============" << endl;
    cout << "Title: " << b.title << endl;
    cout << "Author: " << b.author << endl;
    cout << "Subject: " << b.subject << endl;
    cout << "ID: " << b.book_id << endl;
    cout << "Pages: " << b.pages << endl;
    cout << "Price: " << b.price << endl;
    cout << endl;
}
int main(){
    //initialise 5 books objects into array
    Books library[5] library{ {
      {"Lord of the Rings", "J.R.R. Tolkien", "Fantasy", 12345, 1454, 7.99},
      {"Harry Potter", "J.K. Rowling", "Fantasy", 12346, 323, 4.69},
      {"The Beach", "Alex Garland", "Travel", 12347, 435, 2.99},
      {"Veg", "Jamie Oliver", "Cookery", 12348, 249, 17.50},
      {"A Christmas Carol", "Charles Dickens", "Drama", 12349, 532, 2.48}
    } };

    printBook(library[1]);//print Harry Potter Book

    printBook(library[4]);//print A Christmas Carol

    return 0;
}
```
The above program will output the following:

```
Requested Book
==============
Title: Harry Potter
Author: J.K. Rowling
Subject: Fantasy
ID: 12346
Pages: 323
Price: 4.69

Requested Book
==============
Title: A Christmas Carol
Author: Charles Dickens
Subject: Drama
ID: 12349
Pages: 532
Price: 2.48
```


&nbsp;
&nbsp;

## Combining File Handling and Structures

As structures typical represent simple data objects they  work well in combination with file handling as they provide us with a method of storing records read from files efficiently. For example, in the File Handling chapter we had an example where we read in some customer information from a file:

```
Joe Bloggs	43	BS24CV
Karen Smith	23	EM15XY
Garry Jones	18	FG48NP
Phil Legg	54	BS15NE
```

The example program we created read this data into the program and stored it inside a multiple arrays. Whilst this program performed the task we wanted, it's not the most desirable approach as we need to manage multiple arrays to get the full set of information about individual customers. 

We can improve the program by reading the data on each line into a structure that has data members for the information included in the file:

```C++
struct customers{
    string name;
    int age;
    string postCode;
}
```


In the example below we move through the ```customers.txt``` file line by line amd assign the data to the respective structure data members. We do this following the same approach as before to read the data and make use of ```getline()``` and a ```stringstream``` to separate the data as it is read into the program.

Once all the data has been read we use a range based for loop to output each structure. In this for loop we access each element by const reference, else when each element is accessed a copy will be made (similar to passing by value vs passing by reference in functions).

The use of structures in this instance makes the code much cleaner and individual customers are easier to handle as their data is grouped together in a single named object. The entire code is included below, make sure you study the comments to understand what is happening at each step.

```C++
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct Customer{
    string name;
    int age;
    string pCode;
};

int main() {
    ifstream inFile{"customers.txt"};//create file stream
    Customer customers[4]
    string data;//variables to store data
    int i = 0;//counting variable
    if (inFile.is_open()) {//check file is open
        while (getline(inFile, data)) {//read each line from the file
	    stringstream ss{data};//create stringstream and assign data as its contents
			
	    getline(ss, customers[i].name, '\t');//get name from stringstream up to tab space
	    ss >> customers[i].age;//extract age from stringstream (getline can only be used with strings)
	    ss.ignore(10, '\t');//extraction will stop at the tab delimiter, so we manually ignore
	    getline(ss, customers[i].pCode);//get remaining contents of line and store into pCode variable
	    }
    }
    for(const auto& c : customers){
        cout << "Name: " << c.name << endl;
        cout << "Age: " << c.age << endl;
        cout << "Postcode: " << c.pCode << endl;
        cout << "--------------------" << endl;
    }
    return 0;
}
```
