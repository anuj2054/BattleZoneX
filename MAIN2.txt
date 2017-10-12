#include"data.h"
#include"enterscr.h"
#include"playscr1.h"
#include"playscr2.h"
#include"exitscr.h"
#include"friends.h"

int main()
{
clrscr();
int mode1=0,mode2=0,response=0;char ch;
boolean restart=FALSE;
int gd=DETECT,gm,key;
initgraph(&gd,&gm,"c:\\tc\\bgi");

enterscreen enterscreen;
playscreen playscreen;
exitscreen exitscreen;
splash_screen project;

project.at_start();
enterscreen.setscreen();
enterscreen.getname();
cleardevice();
response=menu(mode1,mode2);
cleardevice();
playscreen.getview1();
playscreen.getview2();
playscreen.setwindow1();
playscreen.setwindow2();


if (response==3)
	{
	mode1player a(1,'d','a','w','s',32,'e','q',window2.left+width2/5);
	mode1player b(2,'3','1','5','2','0','4','6',window2.left+width2/1.5);
	do
		{

		playscreen.setwindow1();
		playscreen.setwindow2();
		restart=(checkgameend(a,b)==TRUE)?exitscreen.displayend(winner):FALSE;
		if(kbhit())
			{
			ch=getch();
			a.controls(ch,b);
			b.controls(ch,a);
			}
		else
			{
			a.chkfiremodes();
			a.fire(b);
			b.chkfiremodes();
			b.fire(a);
			 }
	 }while((ch!=27));
}

else  if(response==2)
{

  mode2player a(1,'d','a','w','s',32,'e','q',window2.left+width2/5);
  mode2player b(2,'3','1','5','2','0','4','6',window2.left+width2/1.5);

	do
		{

		playscreen.setwindow1();
		playscreen.setwindow2();
		restart=(checkgameend(a,b)==TRUE)?exitscreen.displayend(winner):FALSE;
		if(kbhit())
			{
			ch=getch();
			a.controls(ch,b);
			b.controls(ch,a);
			}
		else
			{
			a.chkfiremodes(b);
			a.fire(b);
			b.chkfiremodes(a);
			b.fire(a);
			 }
	 }while((ch!=27));

 }

 else if(response==1)
	{
	exitscreen.credits();
	}

cleardevice();
closegraph();
if(restart==FALSE){restart=TRUE;}
return 0;
}




