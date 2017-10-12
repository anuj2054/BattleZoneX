
class player

{
protected :
   int x,y,maxx,maxy,tx,ty,count,bx,by,xinit,yinit,ang,ang1,plnum,hit,vel;
   char key1,key2,key3,key4,key5,key6,key7;int xlimit;
   int freq,i,j,k;//for vel display ahy bombs
   void far *tank;
   int bomb[MAX];int bx1,by1;
   float t;
public:
   player(){}
   player(int,char,char,char,char,char,char,char);
   void controls(char,player &);
   void movetankfor();
   void movetankback();
   void movenoseup();
   void movenosedown();
   void restoretank();
   void eatfire(int ,int );
   int fire(player a);
   void blast(int,int);
   void drawtank();
   void drawbombcount(int);
   void drawveldisplay();
   void drawscores(int,int);
   int incvel();
   int decvel();
   void checkformodes();
   void checkbackmodes();
   boolean chkwinframe();
   boolean chkenemyhit(player);
};

/////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////

player::player(int plno,char a,char b,char c,char d,char e,char f,char g)

{   freq=1000;//for sound
    plnum=plno;
   count=0;t=0;bx=0;by=0;xinit=0;yinit=0;ang1=0,hit=0;vel=0;i=MAX;j=MAX;
  key1=a; key2=b; key3=c; key4=d;  key5=e;key6=f;key7=g;k=0;
  char str3[34];
// maxx=window2.right;maxy=window2.bottom;
  setbkcolor(bkcolor);
  setlinestyle(0,3,3);//20=height of the tank


for(int i=0;i<MAX;i++) bomb[i]=0;
drawbombcount(plnum);
drawveldisplay();
  }
///////////////////////////////////////////////////////////////////

void player::drawveldisplay()  //static should be
{
setcolor(WHITE);
rectangle(window2.left+30-1,window2.top+10-2,
window2.left-1+width2/2,window2.top+20+2);
rectangle
(window2.right-30+1,window2.top+10-2,
window2.right+1-width2/2,window2.top+20+2);
setcolor(general);
}

void player::drawtank()
{ if(plnum==1) setfillstyle(1,tnk1color);
  if(plnum==2)  setfillstyle(1,tnk2color) ;
  setcolor(tnkcolor);
  rectangle(x+1,y,x+51,y+19);
  bar(x+2,y+1,x+50,y+18);
  circle(x+26,y-4,4);
  circle(x+26,y-4,3);
  int size=imagesize(x,y-8,x+52,y+20);
  tank=malloc(size);
  getimage(x,y-8,x+52,y+20,tank);
  line(x+26,y-4,tx,ty);
  line(x+25,y-4,tx-1,ty);
  line(x+27,y-4,tx+1,ty);
  circle(tx,ty,2);
  setcolor(general);
  setfillstyle(1,general);
}

////////////////////////////////////////////////////////


boolean player::chkenemyhit(player a)
   {
   if((yinit-by>=(a.y-2))&&((bx+xinit+4)>a.x)&&((bx+xinit)<=(a.x+52))
   &&(yinit-by<=a.y+19))
   {
   eatfire(bx1,by1);
   blast(xinit+bx-1,yinit-by-9);blast(xinit+bx+1,yinit-by-9);
   a.restoretank();
   drawscores(plnum,++hit);
   bomb[count]=2; count++;bx=0;by=0;t=0;
  nosound();sound(2222);nosound();
   return TRUE;
   }
   return FALSE;
   }

boolean player::chkwinframe()
   {
   if((bx+xinit>=window2.right-15)||(yinit-by>=window2.bottom-5)||
   (bx+xinit<=(window2.left+15))
   ||(yinit-by<=(window2.top+10)))
   {                           //the 30 may be varied
   eatfire(bx1,by1);
   blast(xinit+bx-1,yinit-by-9);blast(xinit+bx+1,yinit-by-9);
   bomb[count]=2; count++;bx=0;by=0;t=0;
   nosound();sound(2222);nosound();
   return TRUE;
    }
    return FALSE;
    }



void player::checkformodes()
{
if((x+52>=window2.right))                 {x-=4;tx-=4;}
if ((plnum==1)&&(x+52>xlimit))   {x-=4;tx-=4;}
if ((plnum==2)&&(x<xlimit))  {x+=4;tx+=4;}
}
void player::checkbackmodes()
{
if(x<=window2.left) {x+=4;tx+=4;}
if ((plnum==1)&&(x+52>xlimit))   {x-=4;tx-=4;}
if ((plnum==2)&&(x<xlimit))  {x+=4;tx+=4;}
}

////////////////////////////////////////////////////////////////////////

void player::movetankfor()
{setcolor(bkcolor);
 putimage(x,y-8,tank,XOR_PUT);
 line(x+26,y-4,tx,ty);
  line(x+25,y-4,tx-1,ty);
  line(x+27,y-4,tx+1,ty);
  circle(tx,ty,2);
 setcolor(tnkcolor);
 x+=4;tx+=4;
 checkformodes();
putimage(x,y-8,tank,XOR_PUT);
 line(x+26,y-4,tx,ty);
  line(x+25,y-4,tx,ty);
  line(x+27,y-4,tx,ty);
  circle(tx,ty,2);
  setcolor(general);
}

void player::movetankback()
{setcolor(bkcolor);
 putimage(x,y-8,tank,XOR_PUT);
 line(x+26,y-4,tx,ty);
  line(x+25,y-4,tx-1,ty);
  line(x+27,y-4,tx+1,ty);
  circle(tx,ty,2);
 setcolor(tnkcolor);
 x-=4;tx-=4;
 checkbackmodes();
 putimage(x,y-8,tank,XOR_PUT);
 line(x+26,y-4,tx,ty);
  line(x+25,y-4,tx-1,ty);
  line(x+27,y-4,tx+1,ty);
  circle(tx,ty,2);
  setcolor(general);
 }
void player::movenoseup()
{setcolor(bkcolor);
 putimage(x,y-8,tank,XOR_PUT);
 line(x+26,y-4,tx,ty);
  line(x+25,y-4,tx-1,ty);
  line(x+27,y-4,tx+1,ty);
  circle(tx,ty,2);
 ang+=5;
 if(ang>180) ang-=5;
 tx=(x+26)+40*cos(ang*3.14/180);ty=(y-4)-40*sin(ang*3.14/180);
 setcolor(tnkcolor);
  putimage(x,y-8,tank,XOR_PUT);
  line(x+26,y-4,tx,ty);
  line(x+25,y-4,tx,ty);
  line(x+27,y-4,tx,ty);
  circle(tx,ty,2);
  setcolor(general);
}
void player::movenosedown()
{ setcolor(bkcolor);
 putimage(x,y-8,tank,XOR_PUT);
 line(x+26,y-4,tx,ty);
  line(x+25,y-4,tx,ty);
  line(x+27,y-4,tx,ty);
  circle(tx,ty,2);
 ang-=5;
 if(ang<=0) ang+=5;
 tx=(x+26)+40*cos(ang*3.14/180),ty=(y-4)-40*sin(ang*3.14/180);
 setcolor(tnkcolor);
  putimage(x,y-8,tank,XOR_PUT);
  line(x+26,y-4,tx,ty);
  line(x+25,y-4,tx,ty);
  line(x+27,y-4,tx,ty);
  circle(tx,ty,2);
  setcolor(general);
}


void player::restoretank()
{setcolor(tnkcolor);
 putimage(x,y-8,tank,COPY_PUT);
 line(x+26,y-4,tx,ty);
  line(x+25,y-4,tx,ty);
  line(x+27,y-4,tx,ty);
  circle(tx,ty,2);
  setcolor(general);
}

void player::eatfire(int bx1,int by1)
{while(by1!=by)
	{ by1=(int)((vel*sin(ang1*3.14/180)*(t-.2))-(.5*9.8*(t-.2)*(t-.2)));
	  bx1=(int)(vel*cos(ang1*3.14/180)*(t-.2));
	 t+=.1;
	 setcolor(bkcolor);
	 circle(bx1+xinit,yinit-by1,5);
	 setcolor(general);
	}

   }

void player::blast(int x,int y)
{ int r1=0;
   for(int r=1;r<8;r++,r1++)
   {delay(10);
   setcolor(YELLOW);
   circle(x,y,r);
	setcolor(bkcolor);
   circle(x,y,r1);}
   setcolor(BLACK);
   circle(x,y,r1);
   setcolor(general);
}


int player::fire(player a)
{
if(count==MAX)
{return 0;}

switch(bomb[count])
{case 1:
 {
   sound(freq);freq--;
   if((t>.1)&&(t<1))
   restoretank();
   by1=(int)((vel*sin(ang1*3.14/180)*(t-.2))-(.5*9.8*(t-.2)*(t-.2)));
   bx1=(int)(vel*cos(ang1*3.14/180)*(t-.2));
   setcolor(bkcolor);
   circle(bx1+xinit,yinit-by1,5);
   by=(int)((vel*sin(ang1*3.14/180)*t)-(.5*9.8*t*t));
   bx=(int)(vel*cos(ang1*3.14/180)*t);
   t+=.1;
   setcolor(YELLOW);circle(bx+xinit,yinit-by,5);setcolor(general);
   drawveldisplay();
   if(chkwinframe()==TRUE) return 0;
   if(chkenemyhit(a)==TRUE) return 0;
   return 0;
   }
 case 2:
      return 0;
 default:
   return 0;}
}

void player::drawbombcount(int plnum)
{//plnum and draws as value of j andi
// takes
// static int i=MAX,j=MAX;
 char str[34];
if(plnum==1)
	{  	settextjustify(0,2);
		settextstyle(0,0,2);
		setcolor(bkcolor);
		sprintf(str,"***%i***",j+1);
		outtextxy(window1.left+10,window1.top+10,str);
		setcolor(txtcolor);
		if((j==-1)||(j==0))
		{       settextstyle(0,0,1);
			outtextxy(window1.left+10,window1.top+10,"BOMBS FINISHED!!!");
			setcolor(general); return;
		}
		sprintf(str,"***%i***",j);
		outtextxy(window1.left+10,window1.top+10,str);
		j--;
	}
   if (plnum==2)
   {	settextjustify(2,2);
	setcolor(bkcolor);
	settextstyle(0,0,2);
	sprintf(str,"***%i***",i+1);
	outtextxy(window1.left+width1-10,window1.top+10,str);
	setcolor(txtcolor);
		if((i==-1)||(i==0))
       {
		settextstyle(0,0,1);
		outtextxy(window1.left+width1-10,window1.top+10,"BOMBS FINISHED!!!");
		setcolor(general); return;
	}
	settextstyle(0,0,2);
	sprintf(str,"***%i***",i);
	outtextxy(window1.left+width1-10,window1.top+10,str);
	i--;
	}
	setcolor(general);//settextstyle(0,0,0);
}

//only takes the plnum and hit as the variables
void player::drawscores(int plnum,int hit)
{
	char str2[45];
	settextstyle(0,0,1);
	settextjustify(1,1);
	if(plnum==1)
	{
	setcolor(bkcolor);
	sprintf(str2,"** player %s :: %d point ** ",name1,hit-1);
	outtextxy(window1.left+width1/2,window1.top+textheight("W"),str2);
	setcolor(txtcolor);
	sprintf(str2,"** player %s :: %d point ** ",name1,hit);
	outtextxy(window1.left+width1/2,window1.top+textheight("W"),str2);
	}
	if(plnum==2)
	{
	setcolor(bkcolor);
	sprintf(str2,"@@@ player %s :: %d point @@@ ",name2,hit-1);
	outtextxy(window1.left+width1/2,window1.top+3*textheight("W"),str2);
	setcolor(txtcolor);
	sprintf(str2,"@@@ player %s :: %d point @@@ ",name2,hit);
	outtextxy(window1.left+width1/2,window1.top+3*textheight("W"),str2);
	}
	setcolor(general);
}

void player::controls(char key,player &a)
{
if(key==key1)
  {for(int i=0;i<4;i++)
   a.fire(*this);
   movetankfor(); }
 else if(key==key2)
   {for(int i=0;i<4;i++)
	a.fire(*this);
	movetankback();}
 else if(key==key3)
   {for(int i=0;i<4;i++)
   a.fire(*this);
   movenoseup(); }

  else if(key==key6)

  { if(bomb[count]==1) return;
   vel=incvel();}
  else if(key==key7)
 { if(bomb[count]==1) return;
  vel=decvel();}
  else if (key==key4)
   {for(int i=0;i<4;i++)
   a.fire(*this);
   movenosedown();}
   else if((key==key5)&&(bomb[count]==0))
	{
	 movetankback();
	 movetankfor();
	 drawbombcount(plnum);
	 xinit=tx,yinit =ty,ang1=ang;//decdes the 3 varables
	 bomb[count] = 1;}

restoretank();
}
//////////////////////////////////////////////////////////////////
int player::incvel()//takes plnumber as argument and then goesto right
//or left as the value of j or k;
{
char ch;
if(plnum==1)
{
k++;
if((window2.left+30+k*10)>=(window2.left+width2/2-2))
		{k--;}
setfillstyle(1,bkcolor);
bar(window2.left+30,window2.top+10,window2.left+30+(k+1)*10,window2.top+20);
setfillstyle(1,wallcolor);
bar(window2.left+30,window2.top+10,window2.left+30+k*10,window2.top+20);
}
if(plnum==2)
{k++;
	if((window2.right-30-k*10)<=(window2.right-width2/2+2))
		{k--;}
setfillstyle(1,bkcolor);
bar(window2.right-30,window2.top+10,window2.right-30-(k+1)*10,window2.top+20);setfillstyle(1,wallcolor);
setfillstyle(1,wallcolor);
bar(window2.right-30,window2.top+10,window2.right-30-k*10,window2.top+20);
}
drawveldisplay();
setcolor(general);setfillstyle(1,general);
return k*10; }  //this -- is for the  little extra thyat remains

int player::decvel()
{
char ch;
if(plnum==1)
{k--;
if (k==-1) k++;
setfillstyle(1,bkcolor);
bar(window2.left+30,window2.top+10,window2.left+30+(k+1)*10,window2.top+20);
setfillstyle(1,wallcolor);
bar(window2.left+30,window2.top+10,window2.left+30+k*10,window2.top+20);
	if((window2.left+30+(k+1)*10)<(window2.left+30))
	//extra above middle
		{k++; }

}
if(plnum==2)
	{
k--;
if (k==-1) k++;

setfillstyle(1,bkcolor);
bar(window2.right-30,window2.top+10,window2.right-30-(k+1)*10,window2.top+20);
setfillstyle(1,wallcolor);
bar(window2.right-30,window2.top+10,window2.right-30-k*10,window2.top+20);
	if((window2.right-30-(k-1)*10)>(window2.right-30))
		{k++;}
      }
drawveldisplay();
setfillstyle(1,general);setcolor(general);
return k*10;
}


////////////////////////////////////////////////////////////////////////////

class mode1player:public player
{
private:
int wx1,wx2,wy1,wy2;
public:
mode1player(int plno,char a,char b,char c,char d,char e,char f,char g,int xpos);
friend boolean checkgameend(mode1player,mode1player);
boolean chkfiremodes();
void drawwall();
};

class mode2player:public player
{
private:
int cx1,cx2,cy1,cy2;
public:
mode2player(int plno,char a,char b,char c,char d,char e,char f,char g,int xpos);
boolean chkfiremodes(mode2player);
friend boolean checkgameend(mode2player,mode2player);
void drawcliff1();
void drawcliff2();
};

////////////////////////////////////////////////////////////////////////
boolean mode2player::chkfiremodes(mode2player a)
{

if(
((x>a.x)&&(yinit-by>cy1)&&(bx+xinit>cx1))||
((x<a.x)&&(yinit-by>cy1)&&(bx+xinit<cx2)))
{
   eatfire(bx1,by1);
   blast(xinit+bx-1,yinit-by-9);blast(xinit+bx+1,yinit-by-9);
 //  a.restoretank();
   bomb[count]=2; count++;bx=0;by=0;t=0;
  nosound();sound(2222);nosound();
   return TRUE;
   }

if(((bx+xinit>a.cx1)&&(bx+xinit<a.cx2)&&(yinit-by>a.cy1)))
 {
   eatfire(bx1,by1);
   blast(xinit+bx-1,yinit-by-9);blast(xinit+bx+1,yinit-by-9);
 //  a.restoretank();
   bomb[count]=2; count++;bx=0;by=0;t=0;
  nosound();sound(2222);nosound();
   return TRUE;
   }
return FALSE;
 }

boolean mode1player::chkfiremodes()
{if((bx+xinit>wx1)&&(bx+xinit<wx2)&&(yinit-by>wy1))
 {
   eatfire(bx1,by1);
   blast(xinit+bx-1,yinit-by-9);blast(xinit+bx+1,yinit-by-9);
 //  a.restoretank();
   bomb[count]=2; count++;bx=0;by=0;t=0;
  nosound();sound(2222);nosound();
   return TRUE;
   }
return FALSE;
 }

mode1player::mode1player(int plno,char a,char b,char c,char d,char e,char f,char g,int xpos): player(plno,a,b,c,d,e,f,g)
{
       int plnum=plno;
	if(plnum==1)
       {
	ang=0;
	x=xpos;
	y=window2.bottom-22;//22 for above
	tx=(x+26)+40*cos(ang*3.14/180);ty=y-4-40*sin(ang*3.14/180);
	drawwall();
	drawtank();
	xlimit=wx1-25;

		}

else
{  ang=180;x=xpos;
 y=window2.bottom-22;
  tx=(x+26)+40*cos(ang*3.14/180);ty=y-4-40*sin(ang*3.14/180);
	drawwall();
	drawtank();
	xlimit=wx2+25;

  }
 }



void mode1player::drawwall()
{
 randomize();
 wy1=window2.bottom-random(width2/4);
 wy2=window2.bottom-5;
 wx1=(window2.left+(window2.right/2)-20);
 wx2=(window2.left+(window2.right/2)+20);
 setfillstyle(1,wallcolor);
 bar(wx1,wy1,wx2,wy2); setfillstyle(1,general);

}
//////////////////////////////////////////////////////////////////////////

void mode2player::drawcliff1()
{
	cx1=window2.left+5;cx2=width2/2+10;
	cy1=y+20;cy2=window2.bottom-5;
	setfillstyle(1,tnk2color);
	bar(cx1,cy1,cx2,cy2);
	setfillstyle(1,general);
}
void mode2player::drawcliff2()
{
	cx1=window2.left+width2/2-10;cx2=window2.right-5;
	cy1=y+20;cy2=window2.bottom-5;
	setfillstyle(1,tnk1color);
	bar(cx1,cy1,cx2,cy2);
	setfillstyle(1,general);
}


mode2player::mode2player(int plno,char a,char b,char c,char d,char e,char f,char g,int xpos): player(plno,a,b,c,d,e,f,g)
{
       int plnum=plno;
	if(plnum==1)
       {
	int heightaboveground1;
	ang=0;
	randomize();
	x=xpos;
	heightaboveground1=random(length2*0.65);
	y=window2.bottom-22-heightaboveground1;//22 for above
	tx=(x+26)+40*cos(ang*3.14/180);ty=y-4-40*sin(ang*3.14/180);
	drawcliff1();
	drawtank();
	xlimit=cx2;
	}
else
{

int heightaboveground2;
  ang=180;x=xpos;
  heightaboveground2=random(length2*0.75);
  y=window2.bottom-22-heightaboveground2;
  tx=(x+26)+40*cos(ang*3.14/180);ty=y-4-40*sin(ang*3.14/180);
	drawcliff2();
	drawtank();
	xlimit=cx1;

}

}


/////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
