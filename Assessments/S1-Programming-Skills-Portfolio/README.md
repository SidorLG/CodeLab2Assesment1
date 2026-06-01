# Programming Skills Portfolio

The programming skills portfolio assessment is designed to assess your understanding of the fundamental programming concepts covered in the module. It consists of two main components: a set of coding challenge and multiple-choice quizzes.

### Coding Challenges
You will be given three distinct coding challenges that will test your ability to apply pre-existing skills learned in CodeLab I alongside the techniques introduced in CodeLab II including file handling and object orientation. The challenges will progressively build in complexity, requiring the integration of multiple concepts. The exercises can be found below.

When writing your solutions you should focus on implementing the appropriate techniques from the concepts taught in the module. Code for these challenges should be saved to this folder in your CodeLab II GitHub repository. This repository should be kept neat and organised with clearly named folders for each challenge and effective use of commits when working on your solutions (e.g. regular commits on a per task basis with clear and descriptive messages).

Alongside the code you must provide a written explanation for each challenge of approximately 200 words. These code explanations should detail your approach to solving the problem and your design decisions. For further detail please refer to the full assessment brief on Ultra.


### Multiple Choice Quizzes
In addition to the coding challenges you are required to complete five multiple choice quizzes. Each quiz focuses on a specific set of foundational topics from the module. These quizzes will be released throughout the module, and you will have one week to complete each one from its release date.


## Deadlines

There are several deadlines for the different components of the programming skills portfolio assessment. These are detailed below:

### Coding Challenges
21 November, 11:59am

### Multiple Choice Quizzes
The deadline for each quiz is 5pm on the dates stated below. Each quiz will be accessible 1 week before the deadline

- Quiz 1 - Knowledge Refresher, 3rd Oct
- Quiz 2 - Furthering Functions & Vectors, 10th Oct
- Quiz 3 - Files & Structures, 17th Nov
- Quiz 4 - OOP, 31st Nov
- Quiz 5 - STL, Enumeration & Pointers, 14th Nov

## Marking

The programming skills portfolio assessment will be evaluated against the following criteria.

- **Technical Implementation (60%):** Successful selection and implementation of appropriate programming techniques to solve the coding challenges and adherence to coding conventions.
- **Code Explanation (15%):** Clear explanation of the problem-solving approach taken to solving each challenge and justification for the choice of programming techniques.
- **Repository Presentation (10%):** Organised repository and effective use of version control
- **Multiple Choice Quizzes (15%):** Performance across the multiple choice quizzes

**Please refer to Ultra for the full brief including submission instructions and marking criteria descriptors.**

---

## Challenge 1: CO₂ Calculator

> **Your solution must be no more than 100 lines of code.**

Develop a program that calculates that estimates the CO₂ emissions from a car journey based on the distance traveled and the type of fuel used. Your program should have a function to get distance travelled, a function to get fuel type, and a function to calculate the result.

The following assumptions are made regarding the calculations:

- **Fuel consumption**: 9.66 litres per 100 miles
- **CO₂ emissions per litre:**
  - Diesel: 2.68kg CO₂
  - Petrol: 2.31kg CO₂

&nbsp;

## Challenge 2 - Alexa tell me a Joke

> **Your solution must be no more than 100 lines of code.**

The ```randomJokes.txt``` file in the resources folder contains a dataset of random jokes. Each joke is on a new line and consists of a setup and punchline separated by a question mark. For example:

```
Why did the chicken cross the road?To get to the other side.
What happens if you boil a clown?You get a laughing stock.
```


Write a program that responds to the phrase *"Alexa, tell me a joke"* by selecting a random joke from the file provided. Display the setup first, then wait for user input before revealing the punchline. The program should allow the user to request new jokes using the specified prompt until they choose to quit. 


&nbsp;
&nbsp;


## Challenge 3 - Book Manager

> **Your solution must be no more than 200 lines of code.**

Develop a simple library management system that reads book data from the bookData.txt file (found in the resources folder) using appropriate file handling techniques and uses this data to instantiate a Book class with relevant attributes. The program should include a menu that allows users to view all books and view individual books. 

For an additional challenge, extend the functionality to support borrowing and returning books, ensuring that the system updates availability status accordingly.

The bookData.txt file contains the following information for each book: 

`Title, Autor, Pages, ID, Borrowed Status`
