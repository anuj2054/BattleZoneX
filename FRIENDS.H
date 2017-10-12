#include<graphics.h>
boolean checkgameend(mode1player a,mode1player b)
{
if ((a.count==MAX)&&(b.count==MAX))
	{
	if (a.hit>b.hit) winner=1;
	if (b.hit>a.hit) winner=2;
	if(a.hit==b.hit) winner=0;
	return TRUE;
	}
return FALSE;
}

///////////////////////////////////////////////////////////////////////////

boolean checkgameend(mode2player a,mode2player b)
{
if ((a.count==MAX)&&(b.count==MAX))
	{
	if (a.hit>b.hit) winner=1;
	if (b.hit>a.hit) winner=2;
	if(a.hit==b.hit) winner=0;
	return TRUE;
	}
return FALSE;
}
