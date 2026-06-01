# Chapter 5 - Files and Streams

* [File Handling](#file-handling)
  * [Declaring a File Stream Object](#declaring-a-file-stream-object)
  * [Writing Data to Files](#writing-data-to-files)
  * [Altering Default Writing Behaviour](#altering-default-writing-behaviour)
  * [Reading from Files](#reading-from-files)
  * [Separating the data](#separating-the-data)
* [Formatting with getline](#formatting-with-getline)
* [String Streams](#string-streams)
* [String Streams and File handling](#stringstreams-and-file-handling)
* [Further File Functionality](#further-file-functionality)
  * [Moving Around a File](#moving-around-a-file)
  * [Getting the Current Position](#getting-the-current-position)
* [Working with Strings](#working-with-strings)
  * [Append](#append)
  * [Find](#find)
  * [Replace](#replace)
  * [Insert](#insert)
  * [Erase](#erase)
  * [Substring](#substring)
  * [toupper and tolower](#toupper-and-tolower)

&nbsp;
&nbsp;

## File Handling

The ability to read and write data from files through file handling is useful to be able to load or save information to and from our programs. The use of file handling can make your programs much more dynamic as you have much more to work with than just the data that is *‘hard coded’* into your program.

To access the functionality we need for working with files we can use the C++ ```fstream``` library. This can be accessed by adding the following include to the top of the program:

```C++
#include <fstream>
```

To work with files we need to create a file stream object in our program. There are two file stream objects included in the ```fstream``` library. The first is ```ofstream``` (output file stream), which is used for outputting (writing data to files). The second is ```ifstream``` (input file stream), which is used for inputting (reading data from files) data from files into our program. ```ofstream``` works similar to ```cout``` and data can be output to the file using the same ```<<``` insertion operators. ```ifstream```, thus works similar to ```cin``` and data can be extracted from the file stream in the same way using the extraction operators ```>>```.

&nbsp;
&nbsp;

### Declaring a File Stream Object

Declaring a file stream object is similar to how we declare other variables in C++. First we specify the data type of the object (e.g. ```ofstream``` or ```ifstream```), next we give this object a variable name and immediately follow this with the file name we want to access in curly braces `{}`. The syntax looks like this:

```C++
ofstream myOutputFile{"program-data.txt"}; //output file stream
ifstream myInputFile{"program-data.txt"}; //input file stream
```

&nbsp;
&nbsp;

### Writing Data to Files

As noted above we use the output file stream to write data to files. When you declare an output file stream object and name the file you want to access in curly braces, the default behaviour is to overwrite this file if it already exists. If it doesn’t exist a new one will be created. Once the ```ofstream``` object has been declared it is good practice to check it has actually been created and can be accessed. We can do this by using the ```.is_open()``` method:

```C++
if(myOutputFile.is_open()){
   //do file handling stuff
}
```

After we have finished writing data to the file it is also good practice to ensure we always close the file. This can be done using the `.close()` method.

```C++
myOutputFile.close();
```

To actually write some data to the file we can use the insertion operators on the output file stream object, just like we would to output information to the console with ```cout```. For example, if we wanted to write “Hello World” to a file the syntax would be

```C++
myOutputFile << "Hello World" << endl;
```

Let’s see an example of a full program piecing together everything described above. In this program we include the ```fstream``` library at the top. In the main program we then declare an output file stream object and check its ready to be written to using ```.is_open()```. Once we know the file is ready to go we ask the user for their name and age (temporarily storing input into a string variable), and write this data to the file using the ```<<``` extraction operators. When we are finished writing the data we close the file stream object.

```C++
#include <iostream>
#include <fstream> //include the file stream library
#include <string>
using namespace std;

int main(){
    ofstream outputFile{"program-data.txt"}; //declare output file
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
    return 0;
}
```

&nbsp;
&nbsp;
> **Advanced Note** - XCode Note
>On XCode you need to get permission to read and write to the file in your project. To do this go to:
> ```Product →  Scheme →  Edit scheme```
> Make sure the Options tab is selected on the window that appear then locate the Working Directory option. Check this box and set the directory file path to the same folder as your main.cpp file is located.

<p align="center" width="60%">
  <img src="https://jakehobbs.co.uk/markdown_images/xcode-file.png">
</p>

&nbsp;
&nbsp;

### Altering Default Writing Behaviour

By default when writing to files it will be opened in truncate mode. This means all the contents in the existing file will be removed and replaced with the new data being written. We can change this behaviour by including an optional argument after after the filename specified when declaring the file stream object. Multiple modes can be selected by including a | between each one. The available modes for file stream objects are listed in the table below.

| Mode       | Behaviour                    |
|------------|------------------------------|
| ios::out   | Open file to write output    |
| ios::in  | Open file to read input    |
| ios::app   | Open a file and append output at the end of existing content. Data will always be appended to the end, even if seeking to different position   |
| ios::trunc  | Replace existing content when writing (default behaviour)    |
| ios::ate  | Open file and seek to end for writing new data. However in comparison to ios::app can seek anywhere in file to begin writing new content. To avoid truncating the file using in combination with ios::in.    |
| ios::binary | Treat the file as binary format rather than text so the data may be stored in non text format.   |

The most commonly specified mode is ```ios::app``` which ensures content is appended to the end rather than overwriting existing data. The syntax for opening a file in append mode would look like this:

```C++
ofstream myOutputFile{"program-data.txt", ios::app};
```

If we were to alter our previous example and specify the file be opened in append mode as above, each time the program runs the new content will be added to the end of the file.

&nbsp;
&nbsp;

### Reading From Files

The basic process for reading from files is not too dissimilar to writing. The main difference is that we need to use the input file stream (`ifstream`) and utilise extraction operators ( ```>>``` ) or ```getline()``` to get the data from the file into our programs.

Let's imagine we have the following data in a text file called `customers.txt` (included in the Resources folder):

```
Joe Bloggs	43	BS24CV
Karen Smith	23	EM15XY
Garry Jones	18	FG48NP
Phil Legg	54	BS15NE
```

To read it in we create an ```ifstream``` object, then check the file exists using the ```is_open()``` method.  Once we know the file is open we can then extract the data from the file. We can do this using ```getline()```, like we’ve done before when getting user input from the console. However, instead of specifying ```cin``` as the first argument of the ```getline()``` call, we specify we want to get the line from our input file stream and store this into a string variable. We can then output the string variable to the console.

```C++
#include <iostream>
#include <fstream> //include the file stream library
#include <string>
using namespace std;

int main(){

    ifstream inputFile{"customers.txt"}; //declare output file stream

    if(inputFile.is_open()){ //check file is open
        string data; //string variable to temp store data
        getline(inputFile, data);//get data from file into variable
        cout << data << endl; //output data to console
        inputFile.close();//close the file
    }else{
        cout << "File cannot be accessed. Terminating program" << endl;
        return -1; //exit program
    }

    return 0;
}
```

If you run the above code with the data in the text file you will notice it only outputs the first line:

```
Joe Bloggs	43	BS24CV
```

This is because the code to read in the data is only run once. By now we know that when we want to repeat code we should make use of loops. In this case a `while` loop is most appropriate as we don’t know how long the file might be. 

To read the entire contents of the file we can use our ```getline()``` instruction as the loop condition. This works as getline will return `TRUE` as long as it is successfully reading data from the file. When there is no more data to read ```getline()``` will return false and the loop will stop.

```C++
#include <iostream>
#include <fstream> //include the file stream library
#include <string>
using namespace std;

int main(){
    ifstream inputFile{"customers.txt"}; //declare output file stream
    string data;//variable to store the data
    if(inputFile.is_open()){ //check file is open
        while(getline(inputFile, data)){//while not at end of file
            cout << data << endl; //output data to console
        }
        inputFile.close();//close the file
    }else{
        cout << "File cannot be accessed. Terminating program" << endl;
        return -1; //exit program
    }

    return 0;
}
```

&nbsp;
&nbsp;

### Separating the data

The above method works ok for reading the file, but all the information is stored in a single variable. What if we wanted to read the different information such as the name, age and postcode separately? 

One approach is to use the extraction operators ```>>``` and sequentially read in the required data. This sequential extraction can be included as the loop condition in a similar way to how we used ```getline()``` in the previous example. The extraction operation can be used as a condition for the same reason, the operation will return `TRUE` as long as it is able to successfully read data from the file. 

We can see this in action in the following example. Note how the extractions are sequenced together to read the data following the format of the file. 

```C++
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

	ifstream inFile{"customers.txt"};
	string fName, lName, pCode;
	int age;
	if (inFile.is_open()) {
		while (inFile >> fName >> lName >> age >> pCode) {
			cout << fName << " " << lName << " " << age << " " << pCode << endl;
		}
	}

	return 0;
}
```

As the ```>>``` operator will stop at a whitespace you may notice the first name and last name are being read into their own variables. It is possible to overcome this problem by using ```getline()``` in combination with another stream in C++ known as stringstreams. Before we see an example let's understand some more about how `getline` can be used in different ways, as well as introducing stringstreams. 

&nbsp;
&nbsp;

## Formatting with getline

Our initial example using ```getline```  reads in each line and moves onto the next. However, we can add a third argument to the ```getline()``` call, which allows us to specify a point where ```getline``` should stop reading a line. This can be useful to separate text as it's read in for storage, or formatted for output purposes.

The third argument should be a character where you want ```getline``` to stop reading. Subsequent calls to ```getline``` will continue reading from after the character specified in the previous call. For example consider the code below:

```C++
cout << "Enter a sentence: " << endl;
string sentence;
getline(cin,sentence, ' ');
cout << sentence << endl;
```

If we run the above code and entered *“Hello Codelab”* as the sentence, the subsequent ```cout``` would only output *“Hello”* as ```getline``` has been instructed to read up to the white space character.

Here’s another example. Imagine we have the following sentence in a file:

*I want to separate this line of text into two,everything after that comma should be on a new line*

As instructed by the sentence we want to split it at the comma character. To do so our code would look like this:

```C++
#include <iostream>
#include <fstream> //include the file stream library
#include <string>
using namespace std;

int main(){

    ifstream inputFile{"program-data.txt"}; //declare output file stream

    if(inputFile.is_open()){ //check file is open
        string data; //string variable to temp store data

        getline(inputFile, data, ',');//get data up to comma
        cout << data << endl; //output to console

        getline(inputFile, data); //get rest of sentence
        cout << data << endl; //output to console

        inputFile.close();//close the file
    }else{
        cout << "File cannot be accessed. Terminating program" << endl;
        return -1; //exit program
    }

    return 0;
}
```

The first ```getline``` in this code would read the line up to the comma character, with the ```cout``` statement outputting that half of the sentence. The subsequent ```getline``` call will pick up from after the comma and get the rest of the line. Therefore our output would look like this:

```
I want to separate this line of text into two
everything after that comma should be on a new line
```

We can use this logic to read in and format the `customers.txt` data from our previous example. But first we need to know about stringstreams. 

## String Streams

Stringstreams are another type of stream available in C++ that function similar to the file and input/output streams when reading or outputting data.

Stringstreams can be particularly useful when handling data of different types and converting these from strings. One issue with a standard string variable is that they cannot easily be converted to other native data types such as ints through casting. Therefore imagine you had someone's age as a string value you could not cast this to an int to perform arithmetic operations such as incrementing the value.

The solution to this is the stringstream object, which can be used to convert string values to numeric values and visa versa. To access the string stream object we need to include the ```sstream``` library at the top of our program:

```C++
#include <sstream>
```

We declare a `stringstream` object in our program by specifying its type and then giving it a variable name

```C++
stringstream mystream;
```

Adding and extracting the data to the `stringstream` is done through the familiar insertion (```<<```) and extraction (```>>```) operators.

To reset the string stream to be used again it should be reset to its original state. This requires its contents to be set to empty and flags to be cleared

```C++
mystream.str(""); //set contents to empty
mystream.clear(); //clear flags
```

&nbsp;
&nbsp;

#### Example - int to string

The following shows the `stringstream` in action. At the beginning of the program we create a `string` and an `int` variable to store some biographical data we then want to output as a `string`. However, we cannot simply concatenate the `string` and `int` together and assign this to ```bioInfo```.

Instead we make use of a `stringstream` object and insert the desired data using the insertion operators. We can then access the contents of the `stringstream` using the ```.str()``` call (this returns the contents of the `stringstream` as a `string`) and assign this to ```bioInfo```, which is then output to the console.

```C++
#include <iostream>
#include <sstream> //include the string stream library
#include <string>
using namespace std;

int main(){
    string name = "Jake Hobbs";
    int age = 34;
    string bioInfo;
    //bioInfo = name+age; <-- this won't work

    stringstream mystream;
    mystream << "Name is: " << name << endl;//insert string into stream;
    myStream << "Age is: " << age;//insert numeric data into stream;
    bioInfo = myStream.str();//make bioInfo equal to the contents of stream;

    cout << bioInfo << endl;

    mystream.str(""); //set contents to empty
    mystream.clear(); //clear flags

    return 0;
}
```

&nbsp;
&nbsp;

#### Example - string to int

The above example loads numeric data into the stringstream so it can be converted to a `string`. The next example does the opposite and takes numeric information from a `string` and assigns it to an `int`.

The code starts with a `string` that contains a series of numerical values. What we want to do is to convert these into ints and store them in an array. We do this by inserting the `string` into the `stringstream` object. Next we have a for loop to extract each number into the array indexes. This works as the extraction operator knows what data it is expecting and reads until it encounters invalid data (just like on ```cin```). As it is expecting `int` values to place into the integer array, it accepts the numeric values but stops as soon as it reaches the space character. Therefore, on the next loop iteration it picks up where it left off and gets the next numeric value.

Finally we use a range based for loop to output the newly inserted numeric values stored in the array.

```C++
#include <iostream>
#include <sstream> //include the string stream library
#include <string>
using namespace std;

int main(){
    string numberString = "1 23 4 567 778";//string with numeric info
    stringstream ss{}; //stringstream object
    int myArray[5]; //array to store numeric values
    ss << numberString; //insert number string into stream

    //for loop to get numbers into array
    for(int i = 0; i<5; i++){ //for loop to run through array
        ss >> myArray[i]; //extracts numeric value up to white space
    }

    //for loop runs through and outputs each array value
    for(int num : myArray){
        cout << num << " ";
    }

    mystream.str(""); //set contents to empty
    mystream.clear(); //clear flags
    return 0;
}
```

&nbsp;
&nbsp;

## Stringstreams and File handling

Now we know more about ```getline``` and stringstreams lets return to our earlier file handling example using the customer data. So far we've seen examples of reading the data line by line using ```getline()``` and another example of extracting the data sequentially using the extraction operators (```>>```). 

When reading the data sequentially we encountered a problem where the first and last name was stored separately. Our desired solution is to store the first and last name in a single variable. To do so we need to return to the ```getline()``` method of reading the data line by line, then use a stringstream to extract the separate pieces of data in combination with further use of ```getline()```.

The following code demonstrates how this can be achieved:

```C++
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	ifstream inFile{"customers.txt"};//create file stream

	//variables to store data
	string data, name, pCode;
	int age;
	if (inFile.is_open()) {//check file is open
		while (getline(inFile, data)) {//read each line from the file
			stringstream ss{data};//create stringstream and assign data as its contents
			
			getline(ss, name, '\t');//get name from stringstream up to tab space
			ss >> age;//extract age from stringstream (getline won't work here as it can only be used with strings)
			ss.ignore(10, '\t');//extraction will stop at the tab delimiter, so we manually ignore
			getline(ss, pCode);//get remaining contents of line and store into pCode variable

			cout << "Name: " << name;
			cout << "\nAge: " << age;
			cout << "\nPostcode: " << pCode << "\n\n" << endl;//output the data
		}
	}
	return 0;
}
```

Take note of the code comments to fully understand what is happening. Here is a breakdown of the key elements:

* ```while (getline(inFile, data))```: reads the data line by line and stores contents into the ```data``` variable
* ```stringstream ss{data};```: creates a `stringstream` and on each loop iteration stores the next line of data as its contents
* ```getline(ss, name, '\t')```: extracts the contents of the `stringstream` up to the first tab space into the variable ```name```
* ```ss >> age```: extracts the age from the `stringstream` into the ```age``` variable
* ```ss.ignore(10,'\t')```: extraction will stop at the tab delimiter, therefore we need to manually ignore the next tab space in the `stringstream`
* ```getline(ss, pCode)```: get the remaining contents of the line and store into the ```pCode``` variable. No third argument needed as we are on the last piece of data on the line. 

The output from this program once the data is read in should be as follows:

```
Customers
=========

Name: Joe Bloggs
Age: 43
Postcode: BS2 4CV

Name: Karen Smith
Age: 23
Postcode: EM1 5XY

Name: Garry Jones
Age: 18
Postcode: FG4 8NP

Name: Phil Legg
Age: 54
Postcode: BS1 5NE
```

The solution could be enhanced even further. Currently we only output the data and on each iteration of the loop the previously read data is overwritten. To resolve we can make use of arrays, rather than single variables.

This is demonstrated in the following example. The changes are not major and the solution has simply been tweaked to include array notation:

```C++
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	ifstream inFile("customers.txt");//create file stream

	//arrays to store data
	string data, name[4], pCode[4];
	int age[4];

	int i = 0;//variable to track current index
	if (inFile.is_open()) {//check file is open
		while (getline(inFile, data)) {//read each line from the file
			stringstream ss{data};//create stringstream and assign data as its contents
			
			getline(ss, name[i], '\t');//get name from stringstream up to tab space
			ss >> age[i];//extract age from stringstream (getline won't work here as it can only be used with strings)
			ss.ignore(10, '\t');//extraction will stop at the tab delimiter, so we manually ignore
			getline(ss, pCode[i]);//get remaining contents of line and store into pCode variable

			i++;//increment index
		}
	}

	for (int i = 0; i < 4; i++) {
		cout << "Name: " << name[i];
		cout << "\nAge: " << age[i];
		cout << "\nPostcode: " << pCode[i] << "\n\n" << endl;//output the data
	}
	return 0;
}
```

&nbsp;
&nbsp;

## Further File Functionality

### Moving Around a File

There may be occasions where you want to move around a file in order to read or write data at a specific point, or to jump to the beginning or end of the file. There are two different method calls we can use dependent on whether we are reading or writing to the file.

```C++
seekp(pos); //used on ofstream objects
seekg(pos); //used on ifstream objects
```

In both cases ```pos``` relates to the number of characters from the beginning of the file you wish to seek. For example the following would move five characters from the beginning of an output filestream

```C++
seekp(5); //seek 5 characters from the beginning
```

By default seek will start from the beginning of the file. However, we can add further arguments to the ```seekp()``` or ```seekg()``` calls to explicitly specify whether we want the seek to start from the beginning, end or current position in file.

```C++
seekp(5, ios::beg); //seek 5 characters from the beginning
seekp(-10, ios::end); //seek 10 characters back from the end
seekp(8, ios::cur); //seek 8 characters from the current position
```

The above work for both ```seekp``` (ofstream objects) and ```seekg``` (ifstream objects).

Note if seeking a position in an output file and then writing new data, the new data will overwrite any existing content from that position. It will not insert the data into the middle of the file from that point. If you want to insert into the middle you should copy the contents of the file, insert the new data and rewrite back to the file.

&nbsp;
&nbsp;

### Getting the Current Position

Whilst ```seekp()``` / ```seekg()``` will move you to a particular position in a file ```tellp()``` / ```tellg()``` will let you know what position you are at.

```C++
int pos = oFile.tellp(); //get position in ofstream
cout << pos << endl; //output position
```

We can use a combination of ```seek``` and ```tell``` to determine if a file is empty, as if we seek to the end of the file and the current position is `0` then there cannot be any content in the file. See the example below which could be used to check if a file is empty before attempting to read from it.

```C++
ifstream iFile("myfile.txt" ); //declare input file stream
iFile.seekg(0, ios::end); //seek to end of file
int pos = iFile.tellg(); //get position
if(pos == 0){ //if position is 0 file must be empty
    cout << "File is Empty" << endl;
    iFile.close();
}else{
    cout << "File not empty" << endl;
}
```

Take a look at the C++ documentation for a full list of the methods that can be used on input and output file streams.

https://en.cppreference.com/w/cpp/io/basic_ofstream
https://en.cppreference.com/w/cpp/io/basic_ifstream

You can access similar methods such as ```seekg()``` and ```tellg()``` on stringstreams, which as a stream, operate in a similar way.

For full list of available methods see: https://en.cppreference.com/w/cpp/io/basic_stringstream


&nbsp;
&nbsp;



## Working with Strings

Alongside ```getline()``` which we've already discussed in this chapter, the string class in C++ has many methods that allow you to get information about, or modify string values. We’ve seen some of these already, including `.length()` to work out how many characters are in a string and `.compare()`, which can be used to check if two strings are equal.

Further examples of some of the main string methods you may find useful are included below

You can see the full list of available methods with examples here: https://en.cppreference.com/w/cpp/string/basic_string

&nbsp;
&nbsp;

### Append

The ```append()``` method will add additional characters to a string. In its simplest form the method takes a single string argument and will add these characters to a string. However, by including different sets of arguments to the method call alters the exact nature of the ```append()``` method. See the examples below:

```C++
string str1 = "Hello";

str1.append(" World"); //appends entire string to end
cout << str1 << endl; //outputs Hello World

str1.append(3, '!'); //appends specified character three times
cout << str1 << endl; //outputs Hello World!!!

str1.append("CodeLab", 0, 4); /* appends part of specified string
                     starting a position 0 for 4 characters e.g. Code */
cout << str1 << endl; //outputs Hello World!!!Code

str1.append("CodeLab", 4, 3); /* appends part of specified string
                    starting a position 4 for 3 characters e.g. Lab */
cout << str1 << endl; //outputs Hello World!!!CodeLab
```

More details: https://en.cppreference.com/w/cpp/string/basic_string/append

&nbsp;
&nbsp;

### Find

The ```find()``` method finds the first occurrence of the specified characters in a string. The method returns a ```size_t``` value, which is used to represent the size of an object. Therefore, when used with ```.find()``` it represents the size or length of the string at the point which the specified word is found.

We can compare the returned value against ```string::npos```, which represents the highest possible value for a ```size_t``` object. We can view ```npos``` as meaning no position or not found, as for the values to be equal we must have reached the end of the `string`. Therefore, when comparing the ```size_t``` value returned from ```.find()``` against ```string::npos``` we want to ensure it is *NOT EQUAL* as the position we get should be before the end if it IS found.

```C++
string str1 = "Hello World, Welcome to CodeLab";

size_t pos = str1.find("World");
if(pos != string::npos){
    cout << "Found 'World' at position " << pos << " in string" << endl;
}else{
    cout << "Could not find 'World'" << endl;
}
```

This first example demonstrates the use of find to search for the word *“World”* in the string *“Hello World, Welcome to Codelab”*. Note here that the value returned from the ```.find()``` call is assigned to a ```size_t``` variable called ```pos```. We then compare pos against ```string::npos``` to determine if the `string` is found. If it is we output a message that includes the position ‘World’ was found. This will output:

```
Found 'World' at position 6 in string
```

The above can be streamlined slightly by directly comparing the ```.find()``` call against ```string::npos``` in the IF statement and omitting the ```size_t``` variable assignment. This can be done if you do not need to know the position where the `string` is found

```C++
string str1 = "Hello World, Welcome to CodeLab";

if(str1.find("World") != string::npos){
    cout << "Found 'World' in string" << endl;
}
```

Just like ```.append()``` including different arguments in the ```.find()``` method call can alter its behaviour. For example we can specify where we want the search to start by providing a number after the word to be searched.

```C++
string str1 = "Hello World, Welcome to CodeLab";

if(str1.find("World", 10) != string::npos){
    cout << "Found 'World' in string" << endl;
}else{
    cout << "Can't find 'World'" << endl;
}
```

This example will output “Can’t find ‘World’” as the find has been started at character position `10` in the `string`, which is after the occurrence of World.

We can also specify that we only want to search for part of a string by providing two values after the string argument. These two values represent the starting position and the number of characters of the string specified. Therefore in the below example, whilst *“Hello Universe”* has been specified in the ```.find()``` call, this has been limited to `5` characters starting from position `0` (e.g. *“Hello”*). Therefore ```“Found ‘Hello’ in string”``` will be output.

```C++
string str1 = "Hello World, Welcome to CodeLab";
//just search for 5 characters in "Hello Universe" staring a position 0
if(str1.find("Hello Universe", 0, 5) != string::npos){
     cout << "Found 'Hello' in string" << endl;
}else{
    cout << "Can't find 'Hello'" << endl;
}
```

More Details: https://en.cppreference.com/w/cpp/string/basic_string/find

&nbsp;
&nbsp;

### Replace

Replace can be used to replace the contents of a string with another string value. The main arguments are the position to start the replacement, the number of characters to be replaced and the string to replace these characters with. For example the below code replaces *"World"* with *"Universe"* as World starts at position `6` in the original string and is `5` characters long.

```C++
string str1 = "Hello World, Welcome to CodeLab";
str1.replace(6, 5, "Universe");
cout << str1 << endl; //will output Hello Universe, Welcome to CodeLab
```

https://en.cppreference.com/w/cpp/string/basic_string/replace

&nbsp;
&nbsp;

### Insert

The insert method is used to insert a `string` at the position specified, with this position being the first argument and the `string` the second argument.

```C++
string str1 = "Bath University";
str1.insert(4, " Spa");
cout << str1 << endl; //will output Bath Spa University
```

Similar to ```.find()``` you can also specify partial strings to be inserted. See here for more details: https://en.cppreference.com/w/cpp/string/basic_string/insert

&nbsp;
&nbsp;

### Erase

Erase is used to remove parts of a `string`. The main arguments are the position to start erasing, followed by the number of characters to erase. For example the below code removes the word *“Hate”* which starts at position `14`, and also erases the the white space after the word hence `5` being specified as the length.

```C++
string str1 = "I have a love hate relationship with programming";
str1.erase(14, 5);
cout << str1 << endl; //I have a love relationship with programming
```

More Details: https://en.cppreference.com/w/cpp/string/basic_string/erase

&nbsp;
&nbsp;

### Substring

The ```.substr()``` method returns a new `string` from a portion of the `string` the method is used on. Two arguments can be provided to the ```.substr()``` method, the first is the position to begin taking the substring, the second is the number of characters to take. If only the position is specified the remainder of the string after the position will be returned.

For example in the following code, ```.substr()``` starts at character `13` and takes the remainder of `str1` to assign *“Welcome to CodeLab”* to the ```str2``` variable.

```C++
string str1 = "Hello World, Welcome to CodeLab";
string str2 = str1.substr(13);
cout << str2 << endl; //Outputs Welcome to CodeLab
```

Whilst this next example just assigns “Welcome” to `str2` as the number of characters to take is also specified.

```C++
string str1 = "Hello World, Welcome to CodeLab";
string str2 = str1.substr(13, 7);
cout << str2 << endl; //Outputs Welcome
```

More details: https://en.cppreference.com/w/cpp/string/basic_string/substr

&nbsp;
&nbsp;

### toupper and tolower

Whilst not part of the string class itself, ```toupper``` and ```tolower``` are useful methods to use if you need to convert a `string` to upper or lower case. There are two core methods to do this. The first is to use a for loop to run through the `string` and individually convert each letter. The second is to use the ```.transform()``` method from the algorithm library and include ```toupper``` or ```tolower``` as one of the arguments. Examples for each are included below

```C++
string str1 = "Hello World";

//for loop method
for(int i = 0; i < str1.length(); i++){
    str1[i] = toupper(str1[i]);
}
cout << str1 << endl; //outputs HELLO WORLD

//transform method
transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
cout << str1 << endl; //outputs hello world
```

As noted previously there are many more `string` methods than shown here. Explore the documentation to learn about more:

https://en.cppreference.com/w/cpp/string/basic_string
