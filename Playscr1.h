class playscreen
{
public:
void getview1()
{
window1.left=20;window1.top=20;
window1.right=window1.left+width1;
window1.bottom=window1.top+length1;
}

void getview2()
{
window2.left=20;
window2.top=window1.top+length1;
window2.right=window2.left+width2;
window2.bottom=window1.top+length1+length2;
}
void setwindow1()
{
setcolor(wincolor);
rectangle(window1.left,window1.top,window1.right,window1.bottom);
setcolor(general);
}
void setwindow2()
{
setcolor(wincolor);
rectangle(window2.left,window2.top,window2.right,window2.bottom);
setcolor(general);
}
};
