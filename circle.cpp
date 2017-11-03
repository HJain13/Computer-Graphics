#include<STDIO.H>
#include<GRAPHICS.H>
#include<DOS.H>
void floodfill(int x,int y,int oldcolor,int newcolor){

	if(getpixel(x,y)==oldcolor){
		putpixel(x,y,newcolor);
		floodfill(x+1,y,oldcolor,newcolor);
		floodfill(x,y+1,oldcolor,newcolor);
		floodfill(x-1,y,oldcolor,newcolor);
		floodfill(x,y-1,oldcolor,newcolor);
		}
	}
void drawcircle(int xc,int yc,int x,int y)
{	putpixel(xc+x,yc+y,RED);
	putpixel(xc-x,yc+y,RED);
	putpixel(xc+x,yc-y,RED);
	putpixel(xc-x,yc-y,RED);
	putpixel(xc+y,yc+x,RED);
	putpixel(xc-y,yc+x,RED);
	putpixel(xc+y,yc-x,RED);
	putpixel(xc-y,yc-x,RED);

}
void circlebres(int xc,int yc,int r){
	int x=0,y=r;
	int d=3-2*r;
	while(y>=x){
		drawcircle(xc,yc,x,y);
		x++;

		if(d>0)
		{
			y--;
			d=d+4*(x-y)+10;
		}
		else
			d=d+4*x+6;
		 drawcircle(xc,yc,x,y);
		 delay(50);

	}


}


int main(){
	int gm,gd=DETECT,radius=10;
	int x=100,y=100;
	initgraph(&gd,&gm,"c:\\tc3\\winroot\\turboc3\\bgi");
	circlebres(x,y,radius);
	floodfill(x,y,0,4);
	delay(5000);
	closegraph();

	return 0;
	}








