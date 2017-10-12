#include<string.h>
#include<dos.h>
#include<ctype.h>
#include<math.h>
#include<bios.h>
#include<graphics.h>
#include<conio.h>
#include<alloc.h>
#include<iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include<process.h>

const int MAX=10;
int winner;
int bkcolor2=3;
int tnkcolor=WHITE,txtcolor=RED,tnk1color=CYAN,tnk2color=GREEN,wallcolor=5;
struct viewport
{int right,left,top,bottom;}window1,window2;
const int wincolor=WHITE, bkcolor=9,general=0;
int length1=30,width1=520;
int length2=400,width2=520;
enum boolean{TRUE,FALSE};

class player;
class mode2player;
class mode1player;
class enterscreen;
class playscreen;
class exitscreen;
int main();
boolean checkgameend(mode2player,mode2player);
boolean checkgameend(mode1player,mode1player);
