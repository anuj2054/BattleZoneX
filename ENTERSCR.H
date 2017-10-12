#define UP 72
#define DOWN 80
char name1[22],name2[22];
int entry=0;
unsigned char *buff;

int xmax = getmaxx();
int  ymax = getmaxy();

class splash_screen
{
 char txt_out[100];
 public:
 splash_screen();
 void at_start();
};
splash_screen::splash_screen()
{
 strcpy(txt_out,"G E T  R E A D Y  F O R  T H E  A C T I O N ! ! ! !");
}
void splash_screen::at_start()
{
  char ch[2];ch[1] = '\0';
  settextstyle( 10, HORIZ_DIR, 3);
  setcolor(GREEN);
  outtextxy(xmax/4.5,ymax/2.29,"BATTLE ZONE --X");
  settextstyle( 0, HORIZ_DIR,0);

/**********************************************/
for (int i = 0; i<strlen(txt_out); i++)
  {
	ch[0] = txt_out[i];
	outtextxy(xmax/12+8*i,ymax/5,ch);

 int	y=tan(i);
	sound((y+1)*1334);
	delay(60);
	//getch();
  }
  nosound();
  getch();
  cleardevice();
/************************************************************/
}



class box
{  protected:
		int option_no;
		char **option;
		int outcolor,incolor;
		int button_outcolor,button_incolor;
		int x,y;
	public:
		box()	{}
		box(int n);
		void make();
		int highlite();
		~box()	{};
};
box::box(int n)
{  option_no=n;
	*option=new char[n];
	outcolor=15;    incolor=RED;
	button_outcolor=DARKGRAY;	button_incolor=LIGHTGRAY;
	x=getmaxx()/2;		y=getmaxy()/2;
	option[0]="MODE 1"; option[1]="MODE 2"; option[2]="EXIT";
}
void box::make()
{  setcolor(outcolor);
	setlinestyle(0,0,1);
	setfillstyle(1,incolor);// y+10*(option_no)	BASE OF LAST BUTTON
	rectangle(x-90,y+10*(option_no)-30*(option_no),x+90,y+10*(option_no)+10);   //reference 220,160,400,300
	floodfill(x,y,outcolor);
	setcolor(button_outcolor);	setfillstyle(1,button_incolor);
	int option3[]={x-80,y+10*(option_no)-20, x+80,y+10*(option_no)-20, x+80,y+10*option_no, x-80,y+10*option_no};
	fillpoly(4,option3);
	if(entry==0)
	{	int siz=imagesize(x-80,y+10*(option_no)-20, x+80,y+10*(option_no));
		buff=new unsigned char[siz];
		getimage(x-80,y+10*(option_no)-20, x+80,y+10*(option_no), buff );
		entry=1;
	}
	setcolor(MAGENTA); settextjustify(CENTER_TEXT,CENTER_TEXT);
	outtextxy(x,y+10*(option_no)-10,option[option_no-1]);
	for(int i=1;i<option_no;i++)
		{	putimage(x-80,(y+10*option_no-20)-30*i, buff,(i!=option_no-1)?COPY_PUT:NOT_PUT);
			if(i==option_no-1)	setcolor(LIGHTGREEN);
			outtextxy(x,y+10*(option_no)-10-30*i,option[option_no-i-1]);
		}
}
int box::highlite()
{	char button;int check=1,state=option_no,i;
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	do
	{  button=getch();
		if( button==DOWN)
			{	if(state>1)
				{  setcolor(MAGENTA);
					putimage(x-80,y+10*(option_no)-20-30*(state-1),buff,COPY_PUT);
					outtextxy(x,y+10*(option_no)-10-30*(state-1),option[option_no-state]);
					state--;
					setcolor(LIGHTGREEN);
					putimage(x-80,y+10*(option_no)-20-30*(state-1),buff,NOT_PUT);
					outtextxy(x,y+10*(option_no)-10-30*(state-1),option[option_no-state]);
				}
			}
		else if(button==UP)
			{	if(state<option_no)
				{	setcolor(MAGENTA);
					putimage(x-80,y+10*(option_no)-20-30*(state-1),buff,COPY_PUT);
					outtextxy(x,y+10*(option_no)-10-30*(state-1),option[option_no-state]);
					state++;
					setcolor(LIGHTGREEN);
					putimage(x-80,y+10*(option_no)-20-30*(state-1),buff,NOT_PUT);
					outtextxy(x,y+10*(option_no)-10-30*(state-1),option[option_no-state]);
				}
			}
		else if(button=='\r')
				check=0;
	}while(check);
	setcolor(0);	setfillstyle(1,bkcolor);
	fillellipse(320,240,320,240);
	return state;
}
int menu(int menu1,int menu2)
{  int val=0,con=1;
	int retrn;
	setbkcolor(0);
	do
	{  settextjustify(1,1);    settextstyle(7,0,2);
		setcolor(RED);
		outtextxy(getmaxx()/2,25,"M A I N  M E N U");	setcolor(GREEN);
		outtextxy(getmaxx()/2-2,23,"M A I N  M E N U");
		settextstyle(0,0,0);
	{
		box dialogue(3);
		dialogue.make();
		val=dialogue.highlite();

	}
	con=0;
	}while(con);

	if(menu1==0||menu2==0)
	{return val;}
	return 0;
}

class enterscreen{
private:
public:
void setscreen()
{
setcolor(RED);
settextjustify(0,1);
settextstyle(0,0,4);
outtextxy(10,20,"ANSU AND ANUJ");
outtextxy(10,60,"PRESENT TO YOU ");
outtextxy(10,100,"BATTLE ZONE X");
settextstyle(0,0,0);
rectangle(0,200,500,448);
outtextxy(150,230,"CONTROLS :: ");
outtextxy(10,250+textheight("W"),"PLAYER 1: ");
outtextxy(10,250+2*textheight("W"),"Fire    : SPACE");
outtextxy(10,250+3*textheight("W"),"Move tank forward:D ");
outtextxy(10,250+4*textheight("W"),"Move Tank Backward:A ");
outtextxy(10,250+5*textheight("W"),"Move Gun Up:W ");
outtextxy(10,250+6*textheight("W"),"Move Gun Down:S");
outtextxy(10,250+7*textheight("W"),"Increase Power:E ");
outtextxy(10,250+8*textheight("W"),"Decrease Power:Q");
outtextxy(250,250+textheight("W"),"PLAYER 2: ");
outtextxy(250,250+2*textheight("W"),"Fire    :NUM 0");
outtextxy(250,250+3*textheight("W"),"Move tank forward:NUM 1 ");
outtextxy(250,250+4*textheight("W"),"Move Tank Backward:NUM 3 ");
outtextxy(250,250+5*textheight("W"),"Move Gun Up:NUM 5 ");
outtextxy(250,250+6*textheight("W"),"Move Gun Down:NUM 2");
outtextxy(250,250+7*textheight("W"),"Increase Power:NUM 4 ");
outtextxy(250,250+8*textheight("W"),"Decrease Power:NUM 6");

outtextxy(100,250+16*textheight("W")," A FREE SOFTWARE DESIGNED FOR");
outtextxy(40,250+20*textheight("W"),"THIRD SEMESTER ELECTONICS PROJECT OF PULCHOWK CAMPUS");


}
void getname();
char* givename1()
{return name1;}
char* givename2()
{return name2;}

};

void enterscreen::getname()
{
cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
cout<<"    ENTER PLAYER 1::";cin>>name1;
cout<<"    ENTER PLAYER 2::";cin>>name2;
}
///////////////////////////////////////////////////////////////////
