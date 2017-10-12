# BattleZoneX
A desktop game similar to Angry Birds built in C++

Table of contents





OBJECTIVE	2

INTRODUCTION…...……………………………………………………………………2
Entering the game	2
Selecting the mode	2
Playing the Game	2
Ending the game	2


IMPLEMENTATION	3
Algorithm of the main program function	3
Implementing the header files and classes	4

PROBLEM FACED AND SOLUTION………………….……………………………………………………………6

SCOPE AND LIMITATION……………………………………………………………...6

FUTURE ENHANCEMENT……………………………………………………………...7

CONCLUSION……………………………………………………………………………7
  





















OBJECTIVE
To plan, code, implement, and test a 2 player “Shoot And Win” software game called Battle Tanks ( or alternatively battle zone) .



INTRODUCTION 

There are 2 players in this game, each equipped with a “tank” that can drive forward or drive backward, a missile gun that can point within a 0 to 180 degree range,and a power bar that changes the missile velocity.
The objective of the game is to strike the opponents tank with your missile gun.(i.e matching the co-ordinates of your missile with the 4 co-ordinates of your opponents battleship) The accurate target is  to be achieved by either driving your tank , rotating your missile gun, or changing the missile velocity.
The process in which the programs (output) runs are given bellows:
Entering the game
In the first screen that appears the users enter their names. all thereof the actions described above have their own respective controls  that is displayed to the user before the game begins.
Selecting the mode
In the second screen that appears the user selects the mode of the game he/she wants to play. 
In a Mode 1 game the two players are separated by a partition wall that separates the 2 players ,not allowing them to cross over to the opponent’s territory. If the missile strikes  “the wall “ the missile disappears. The height of the wall  is a random function. 
In a Mode 2 game the two players are located in two “cliffs” . If the missile strikes either of the two cliffs, the missile disappears. The height of the two cliffs are a random function .
Randomizing the heights of the walls and cliffs helps avoiding  the game from getting monotonous and predictable.
Playing the Game 
Each “hit” on an opponent tank scores one point for the player. There are maximum ten points that can be attained since the maximum number of missiles that a player has is ten also. Fire outside the play screen window causes the missile to disappear.
Ending the game
As is obvious the player with the maximum points wins. There is also the facility of  restarting the game.

The program was designed, and the codes were written, implemented, and tested to attain the software as per the description given above. The steps undertaken are described in the following pages.



IMPLEMENTATION

Many concepts of the object oriented approach, such as  “this” pointer , friend functions, and inheritance  have been utilized in the design of this program. Without the use of these features of the C++ language, it would of course have been very difficult for us to complete the program. In this program the motion of the bomb was carried out using the trajectory formula as follows
y=u*sin*t + 0.5*g*t2              
x = u*cos*t   (Where t stand for time, stand for initial angle, u stand for initial velocity and g stand for acceleration due to gravity) 

Algorithm of the main program function

1. Start the function
2. Include the predefined header files
3. Include the user defined header files- enterscr.h, playscr1.h, playscr2.h, exitscr.h.
4. Start the main body function
5. Define variable to start 
6. Define 3 objects each from the enterscreen, playscreen, and exitscreen classes.
7. Call the getname( ) functions that is a member of  the enterscreen class
8. Call the menu ( ) mode function that is a member of the enterscreen class and store in a variable “response”
9. Call the setwindow1( ) and setwindow2( ) functions that are members of the playscreen class.
10. If response is “1” from the user mode1 of the game is executed. If the response is “2” mode 2 of the game is executed. If response is “3” the names of the game designers are shown and the program is terminated. 
11.  Execute  respective mode  by   the defining   two objects – player   1  and player 2    from the players  class .
12. Set the two windows for the playscreen
13. An initial check is done on whether the game has ended or not. This initial check may seem absurd but is required for further calls to the function which executes the statements within only when the restart value is true.
14. The keyboard hit function is called .
15. If the user enters a key, a control function is called which executes the respective statements.
16. If no key is entered, rather than staying idle the program checks whether a missile had been fired before. If it has, then the fire function keeps the missile moving in its trajectory. If during this movement of the missile the user enters some key (such as the opponent trying to escape being hit by the missile, or the attacker itself adjusting the angle of its gun in order to prepare for its next assult) the program execution is then shared between the fire function and the respective control function that occurs such as the tank movement, or the gun angle.
17.  In mode 1 of the game a common wall exists. If the missile strikes the wall, the missile is destroyed. In mode 2 of the game there are 2 cliffs or mountains on which the 2 players move their tanks. If the missile strikes the mountain, the missile is destroyed. Thus there is only one common object (i.e the wall) that needs to be checked by the fire function in a mode 1 game while there are two objects (i.e the two mountains) that needs to be checked in a mode 2  game.  This is why we need not pass any objects in a mode 1 game (the wall being common between the two players); and we pass the object of the opponent in a mode2 game (the co-ordinates of the two mountains being different).
18. the end of the game is checked. 
19. if false the loop is again executed. 
20. If true the prompt for restart is shown.
21. If restart is TRUE, the game is again restarted.
22. if restart is FALSE , the program is terminated.      

 
Implementing the header files and classes

The header files and classes that were made in this program follow a graphic oriented approach. As a graphic interface utilizes a clearly visible object oriented approach, we have made classes that mimic the objects that are seen on the screen.

User defined header files:

1. Enterscr.h
2. Playscr1.h
3. Playscr2.h
4. Exitscr.h

The “Enterscr.h” header file contains classes and functions that are called when the program is first executed.

The “Playscr1.h” header file contain classes and function that set the co-ordinates of the windows, and draw the borders inside which the game is to be played.

The “Playscr2.h” header file contain classes and functions that form the core part of the program. This is the most important of our header files since all the functions needed for the control and execution of the core game between 2 players are defined here. 

The “Exitscr.h” header file contain classes and functions that are called when the game is being ended, and the winners and the credits have to be displayed.


Classes and functions defined within the header files:

Menu function
Players
Mode1players: inherited from players
Mode2players: inherited from players
Splash_screen
Enterscreen
Player screen
Exitscreen
Friend function checkgameend (mode 1 player1, mode  1 players2)
Friend function checkgameend(mode2  player1, mode 2  player2)

Description of the functions and class used in this program:
The splash screen class displays the name of the game and the  catch phrase for the game “get ready for the action” in an appealing format.

The Enter screen class asks the user for the name of the two players nad also displays the controls.

The menu() function asks the user to input the mode of the that is to be played.

The playscreen() sets the outline of the screen and the two windows where the game is to be played and where the controls are to be displayed.


The players class contain functions such as movetankfor(), movetankback() ,movegunup(),movegundown(),fire() and controls(). These are the core functions that the game relies on. During the designing of the game we completed the codes of these functions first and then procedded to other minor functions.  

The movetankfor()  and movetankback()   as their name suggests to moves  the tank  either forwards or backwards.
The movegunup()  and movegundown() functions as their name suggests move the angle of  the gun within a 0 to 180 deegree range.
The restoretank() function restores the tank once it has been hit by a missile.
The blast() and eatfire() functions destroyes the missile when it strikes the tank, the window boundary, a wall , or the mountains.
The drawtank() functions draws the tank.
The drawbombcount() function displays the number of bombs that each player has left.
The drawvelocity() function draws the velocity bar that helps to change the velocity of the missile.
The draw scores() function displays the scores of each player.
The increasevelocity() and decreasevelocity() functions increase or decrease3 the velocity of the  missile and display the corresponding changes in the velocity that bar that explained before.
A function that requires special mentioning here is the fire() function. Since our program is a dynamic one we have to account for the fact that a player may want to move his/ her tank while a missile is being fired or both players may want to move their tanks simultaneously. To account for this the control functions and fire functions have to be continuously called. The operation of the fire function depends on the value of the bomb[count] variable. 
1. If value of bomb[count] = 0, the missile has not yet been fired.
2. If the value of bomb[count] =1, the missile is in the stage of being fired.
3. If the value of bomb[count] = 2, the missile has been fired and destroyed.  
Thus  when control passes to the fire function from the main body function, the                                value of the bomb[count] variable is checked  and depending on its value the respective operations are performed.
 
The mode 1 players class is inherited from the players class since most of the functions are utilized by the modee1 game which also adds functions of its own such as the construction of the wall.

The mode 2 players class is inherited from the players class since most of the functions are utilized by the mode 2 game which also adds functions of its own such as  construction of the two mountains.

The checkgameend() is overloaded friend functions to the mode 1 and mode 2 classes.  There exists two functions with the same name but different arguments passed to it. This is an example of overloaded functions. This function checks whether the game has ended. If the game has ended it returns a true value . if the game has not ended the function returns a false value. 

The exit screen class contain functions that display which player has won, and also functions that display the credits of the game. That is show the name of the designers of the game.




Problem Faced and Solution
     

In this project we faced a lot of problems in this projects, which are listed below:
1. We know that out program is dynamic game, in this game both user are activated at the same time so to give motion to both the player it’s a bit difficult task in single threaded program .Our compiler was also single threaded.
2. To solve problem 1 we made our program sequential where all the required function were performed sequentially, but this created new problem that is ,our program was a bit slow in term of speed and performance.
3. Due to limited time we were not able to add various mode in this program such as target mode.
4.  As this game is dynamic and due to the lack of colours in our compiler we were not able to give background of our program interesting and exciting.
Scope and limitation   

 This is the beginning of the one of the exciting game for future. This game has provided a door for one of the3d gaming in future. This game can be made more versatile in the future. In this game there are some limitation.   In this game, which are listed below
As our compiler supported single threaded this game looks a bit slow.
Various mode were not included in this game such as target mode, compute vs. player mode etc.
Because of the lack of  variety of colors background was a bit simple.

Future Enhancement
 
This game provides a lot of way for future advancement of this game. This game can be the beginning of  the  one of the exciting 3d shooting game. In the future various can be added which are listed below.
By the use of multi threading this game can be made more exciting and interesting
3d effect can be given this game such as in background.
Various extra mode can be added in this game such as target mode, computer vs player mode. 
This game can be made adventure game.
This game can be made more versatile and interesting.


Conclusion

This game has provided a lot knowledge about c++ object oriented . This project also provided us to program for the games.
Finally we would like to thank out computer department for providing us wonderful opportunity to do this exciting project.
