#include<graphics.h>

class exitscreen
{
public:
boolean displayend(int plnum);
void setwindow();
void credits();
};

void exitscreen::setwindow()
{
setcolor(wincolor);
rectangle(window2.left,window2.top,window2.right,window2.bottom);
setcolor(general);
}


boolean exitscreen::displayend(int plnum)
{
 getch();
 cleardevice();
 setwindow();
 setcolor(txtcolor);
 settextjustify(1,1);
 settextstyle(0,0,3);
 outtextxy(window2.left+width2/2,window2.top+50,"GAME END");
 switch (plnum)
 {case 0:
	outtextxy(window2.left+width2/2,window2.top+50+2*textheight("W"),"DRAW");break;
  case 1:
	outtextxy(window2.left+width2/2,window2.top+50+2*textheight("W"),"PLAYER 1 :: WINS");break;
  case 2:
	outtextxy(window2.left+width2/2,window2.top+50+2*textheight("W"),"PLAYER 2 :: WINS");break;

  }
  outtextxy(window2.left+width2/2,window2.top+50+(6*textheight("W")),"PRESS ESC TO EXIT..");
 settextjustify(1,1); outtextxy(window2.left+width2/2,window2.top+50+(4*textheight("W")),"ANY KEY TO RESTART");

  char choice;
  choice=getch();
  if(choice==27)
	{  setcolor(general);
	  credits();
	  exit(1);}
  else {
   setcolor(general);
   getch();
    
    main();

	 }
return FALSE;
}
void exitscreen::credits()
{	randomize();
	cleardevice();
	setviewport(0,0,getmaxx(),getmaxy(),1);
	setbkcolor(0);
	setcolor(14);
	for(int i=-130;i<600&&!kbhit();i+=1)
	{	settextstyle(10,0,1);
		settextjustify(1,1);
		setcolor(LIGHTBLUE);
		outtextxy(getmaxx()/2,350-i,"D E V E L O P E D   B Y");
		setcolor(BLUE);
		outtextxy(getmaxx()/2+5,350-i+5,"D E V E L O P E D  B Y");
		settextstyle(8,0,3);
		settextjustify(2,1);
		setcolor(YELLOW);
		outtextxy(630,550-i,"-Anuj Guruacharya(060BEX404)");
		outtextxy(625,600-i,"-Ansu Man Singh(060BEX403)");		delay(15);
		cleardevice();
	}
	nosound();
	setcolor(10);
	for(i=getmaxx()/2;i>=0;i-=2)
	{  cleardevice();
		circle(getmaxx()/2,getmaxy()/2,i);	sound(200000/(i+1));
	}
	nosound();
}
