#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <windows.h>
#include <ctime>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void pos(int,int);
void point();
void food();
void loose ();
bool booltime;
using namespace std;
void start();
void raand(int &x, int &y);
time_t t1,t2;
int c,e,l=6,d,tt1,tt,tt2,a[200],b[200],x,y,x1,y1,t,p=-1,iw1[5],jw1[5],iw2[5],jw2[5];
char txt[30]="Your score is:   ";
int main() {
	
	int i,j,lw;
	cout<<"Choose your difficulty Level:\n1.Easy\t2.Medium  3.Hard\n";
	cin>>c;
	switch(c){
			  case 1: t=400;
			  d=2;
			  tt=15;
			  break;
			  case 2:
			  default:
 		      t=300;
 		      tt=10;
			  d=3;
			  break;
			  case 3: t=200;
			  d=4;
			  tt=7;
			  break;}
 cout<<"should it fail with hiting the chart?\n1.Yes\t2.No\n";
 cin>>c;
initwindow(850,600,"Snake Game");
setbkcolor(15);
cleardevice();
setcolor(0);
settextjustify(1,1);
settextstyle(3,0,1);
outtextxy(400,250,"loading...");
for (i=0;i<101;i++){
	rectangle (300,300,300+2*i+1,350);
	setfillstyle(1,0);
	floodfill(300+2*i,340,0);

	outtextxy(400,400,"Get ready");
	delay(20);
}
cleardevice();
settextjustify(1,1);
settextstyle(3,0,1);
line(801,0,801,600);

i=5;
for (j=10;j>=5;j--)
pos(i,j);
srand(time(0));
iw1[0]=rand()%5;
jw1[0]=rand()%4;
iw2[0]=rand()%4+10;
jw2[0]=rand()%6;
for (lw=0;lw<d;lw++)
{
 	iw1[lw+1]=iw1[lw]+1;
 	jw1[lw+1]=jw1[lw];
 	readimagefile ("W.jpg",iw1[lw]*50,jw1[lw]*50,iw1[lw]*50+50,jw1[lw]*50+50);
 	iw2[lw+1]=iw2[lw];
 	jw2[lw+1]=jw2[lw]+1;
 	readimagefile ("W.jpg",iw2[lw]*50,jw2[lw]*50,iw2[lw]*50+50,jw2[lw]*50+50);
}
food();
while(!kbhit()){}
start();
}

void start(void){
static int i=5,j=5;
static int n=1,h=0;

	delay (t);
if (GetAsyncKeyState(VK_ESCAPE))
exit (1);
	if (GetAsyncKeyState(VK_UP)){
	if (n!=2)
	n=1;}
	else if (GetAsyncKeyState(VK_DOWN)){
	if (n!=1)
	n=2;}
	else if (GetAsyncKeyState(VK_LEFT)){
	if (n!=4)
	n=3;}
	else if (GetAsyncKeyState(VK_RIGHT)){
	if (n!=3)
	n=4;}
	
	
	switch (n){
		case 1:
		if (j<1) if (c==2)
		{j=j+12;}
		else loose();
		j--;
	break;
	case 2: if (j>10) if (c==2) j=j-12;
	else loose();
	j++;
	break;
	case 3:
	if (i<1) if (c==2) i=i+16;
	else loose();
	 i--;
	break;
	case 4: 	if (i>14) if (c==2) i=i-16;
	else loose();
	i++;
	break;
	}
		for (e=0;e<l-1;e++)
			if (a[e]==i && b[e]==j)
	         	h++;
		
		for(e=0;e<d;e++)
					if (iw1[e]==i && jw1[e]==j)	h++;
					
		for(e=0;e<d;e++)
					if (iw2[e]==i && jw2[e]==j)	h++;
					
		if (h) loose();
		else{
			 	pos(i,j);
		if (x1==i && y1==j) {p+=5; point();}
		if (x==i && y==j) food();
	start();}
}

void pos(int c,int d){
		int i,j,z;
		tt2=time(&t2);
	for(i=l;i>0;i--){
	a[i]=a[i-1];
	b[i]=b[i-1];
		}
	a[0]=c;
	b[0]=d;
    std::cout<<a[0]<<" "<<b[0]<<"\n";
readimagefile ("N.jpg",a[l]*50,b[l]*50,a[l]*50+50,b[l]*50+50);
readimagefile ("M.jpg",a[0]*50,b[0]*50,a[0]*50+50,b[0]*50+50);
if(tt2-tt1>tt && booltime){
readimagefile ("N.jpg",x1*50,y1*50,x1*50+50,y1*50+50);
x1=-1;
y1=-1;
booltime=0;               }
}

void loose (){
	
	 
	 txt[16]=p%10+48;
	 p=p/10;
     if (p%10) txt[15]=p%10+48;
	 	closegraph();
initwindow(400,300,"OooPS..!");
setbkcolor(15);
cleardevice();
setcolor(0);
settextjustify(1,1);
settextstyle(6,0,3);
outtextxy(200,50,"Oh! Sorry!");
outtextxy(200,110,"You Loose :(");
outtextxy(200,200,txt);
Sleep(1000);
getch();
exit(1);
}

void food(){
	 int num=0,e;

	 p++;
     srand(time(0));
	 t=t-5;
	 point();     
	if (p%5==0&&p!=0){
	   		booltime=1;	
			   tt1=time(&t1);	
    do{num=0;
	 x1=rand()%15 ;
     y1=rand()%11 ;
     for (e=0;e<l;e++)
		if (a[e]==x1 && b[e]==y1) num++;
  	for(e=0;e<d;e++)
		if (iw1[e]==x1 && jw1[e]==y1)	num++;
	for(e=0;e<d;e++)
		if (iw2[e]==x1 && jw2[e]==y1)	num++;
		} while(num);
 
	 readimagefile ("F.jpg",x1*50,y1*50,x1*50+50,y1*50+50);
	 			   }
      
do{num=0;
	 x=rand()%15 ;
     y=rand()%11 ;
     for (e=0;e<l;e++)
		if (a[e]==x && b[e]==y) num++;
  	for(e=0;e<d;e++)
		if (iw1[e]==x && jw1[e]==y)	num++;
	for(e=0;e<d;e++)
		if (iw2[e]==x && jw2[e]==y)	num++;
		if (x==x1 && y==y1) num++;
		} while(num);
	 readimagefile ("F1.jpg",x*50,y*50,x*50+50,y*50+50);
	 l++;
	 

     
}

void point (){
 setfillstyle(1,2);
floodfill(815,500,0);
settextstyle(1,0,3);
txt[16]=p%10+48;
	 e=p/10;
     if (e) txt[15]=e+48;
     else txt[15]=' ';
     settextstyle(4,1,2);
     setcolor(4);
     outtextxy(825,300,txt);
	 }
