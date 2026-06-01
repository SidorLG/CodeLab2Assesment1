# Resources

This folder contains files required for the file handling tasks in chapter 5 as well as some useful code snippets for common C++ tasks. 

&nbsp;
&nbsp;

## Invalid number input

```C++
#include <iostream>
using namespace std;

int main(){
  //Check if user enters valid input
  cout << "Enter a number: " << endl;
  int x;
  cin >> x;
  while (cin.fail()) {
    cout << "Invalid input" << endl;
    cin.clear(); //clear bad input flag
    cin.ignore(1000, '\n'); //ignore input
    cin >> x; //get number again
  }
  cout << "Input number: " << x << endl;

  return 0;
}
```

&nbsp;
&nbsp;

## Random Number generation

```C++
#include <iostream>
#include <random>
using namespace std;

int main() {
    
    random_device rd; // Create a random device to seed the generator
    mt19937 gen(rd()); // Use Mersenne Twister engine
    uniform_int_distribution<> dist(1, 100); // Define a distribution: uniform integers between 1 and 100
    
    int rand = dist(gen);//store random number
    cout << rand << endl;//output number
    
    return 0;
}
```

&nbsp;
&nbsp;

## Check for number in String

```C++
#include <iostream>
#include <string>
using namespace std;

int main() {

  //check if string contains digit
  string str1 = "Hello123";
  for (int i = 0; i < str1.length(); i++) {
    if (isdigit(str1[i])) {
      cout << "String contains a digit" << endl;
      break;
    }
  }

  return 0;
}
```

&nbsp;
&nbsp;

## Convert to upper / lower case

```C++
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){

  //upper case
  string str1 = "Hello123";
  for (int i = 0; i < str1.length(); i++) {
    str1[i] = toupper(str1[i]);
  }
  cout << str1 << endl;

  //alternative using transform method from algorithm library
  transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
  cout << str1 << endl;

  return 0;
}
```

&nbsp;
&nbsp;

## String Comparison

```C++
#include <iostream>
#include <string>
using namespace std;

int main(){

  //string comparison
  string str2 = "Code";
  string str3 = "Lab";
  if (str2.compare(str3) == 0) {
    cout << "Strings are the same" << endl;
  }
  else{
    cout << "Strings are not the same" << endl;
  }

  //string comparison alternative
  if (str2 == str3) {
    cout << "Strings are the same" << endl;
  }else {
    cout << "Strings are not the same" << endl;
  }

  return 0;
}
```
