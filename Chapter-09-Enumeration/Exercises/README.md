# Chapter 9 - Exercises

Use these exercises to put into practice the knowledge you have gained from chapter 9. You can save your solutions to the exercises to this repository and it is recommended that for each exercise you create a _**new project**_ with the name of the exercise and save it to the relevant exercise folder for the chapter you are working on. Once you have completed your solution you should make sure you commit and push the code to your remote repository on GitHub.

---
&nbsp;

### 1 - Set the Direction

Create an enum named Directions with the following enumerator values:

UP, DOWN, LEFT, RIGHT

Ask the user to enter a letter W, A, S, D and using an if or switch statement check which letter they entered, the switch cases should then set the enum variable accordingly (W = UP, A = LEFT, S = DOWN, D = RIGHT)

&nbsp;
&nbsp;

### 2 - Shop Opening Hours

Jake’s Beer Emporium is open Tuesday through Sunday. It opens at 11am each day and closes at 10pm, except on weekends (including Friday) when the shop is open until 11.30pm. Write a program that uses an **enum class** and switch statement to output the opening hours for the day of the week selected by the user.

&nbsp;
&nbsp;

### 3 - Game States

Write a program that manages different states of a game using enums

* MENU
* PLAYING
* PAUSED
* GAME OVER

From the MENU players should be able switch to PLAYING or quit the program
While PLAYING the user should be able to generate a random number, if they generate an odd number they lose a life and GAMEOVER should activate when lives have run out (3 lives in total).
Players can also switch to PAUSED during play. From here they should be able to continue PLAYING or go back to the menu
