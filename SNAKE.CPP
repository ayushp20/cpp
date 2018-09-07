#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<process.h>
#include<ctime>
using namespace std;

const int height=20,width=77;
int x,y,fruitx,fruity,tailx[100],taily[100],ntail,score,gameover;
enum direction{stop=0,left_,right_,up,down}dir;

void drawLine(int n, char symbol)
{
    for(int i=0; i<n; i++)
	cout << symbol;
    cout << "\n" ;
}

void setup()
{	gameover=0;

	dir=stop;
	x=width/2;
	y=height/2;
	srand(time(NULL));
	fruitx=rand()%width;
	fruity=rand()%height;
	score=0;

}
void input()
{  if(kbhit())
	{	switch(getch())
			{   case 'a': dir=left_;break;
				case 'd': dir=right_;break;
				case 'w': dir=up;break;
				case 's': dir=down;break;
				case 'x': gameover=1;
			}


	}

}
void draw()
{   system("CLS");
	for(int i=0;i<width+2;i++)
	cout<<"~";
	cout<<endl;

	for (int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{if (j==0)
		 cout<<"|";
		 if(i==y&&j==x)
		cout<<"0" ;
		else if (i==fruity&&j==fruitx)
		cout<<"@";
		else
		{       int print=0;
			for(int k=0;k<ntail;k++)
			{

			    if(tailx[k]==j&&taily[k]==i)
				{cout<<"o";
				 print = 1;
				}
			}
			if(!print)
			cout<<" ";
		}
		 if (j==width-1)
		 cout<<"|";
		}

	cout<<endl;
	}

	for(int i=0;i<width+2;i++)
		cout<<"~";
	cout<<endl;
	cout<<"Score : "<<score<<endl;
	}

void logic()
{       int prevx=tailx[0],prevy=taily[0];
	int prev2x,prev2y;
	tailx[0]=x;
	taily[0]=y;


	for(int i=1;i<ntail;i++)
		{	prev2x=tailx[i];
			prev2y=taily[i];
			tailx[i]=prevx;
			taily[i]=prevy;
			prevx=prev2x;
			prevy=prev2y;

		}

	switch(dir)
	{	case left_: x--;break;
		case right_:x++;break;
		case up:   y--;break;
		case down: y++;break;
		}
	if(x>width||x<0||y>height||y<0)
		gameover=1;
	else if(x==fruitx&&y==fruity)
	{
	 score+=10;
	 srand(time(NULL));
	fruitx=rand()%width;
	fruity=rand()%height;
	 ntail++;
	}
		for(int i=0;i<ntail;i++)
		if(tailx[i]==x&&taily[i]==y)
			gameover=1;



}
void intro()
{   system("CLS");
	drawLine(77,'*');
	char ch;
	cout<<"\t\t\t\tWelcome To Game 2 \n\t\t\t\tSNAKES";
	cout<<"\n\t\t\t\t1.New Game";
	cout<<"\n\t\t\t\t1.Resume Game";
	cout<<"\n\t\t\t\t2.High Scores";
	cout<<"\n\t\t\t\t3.Exit";
	cin>>ch;
	switch(ch)
	{case '1': break;
	case '2' : break;
	case '3' : exit(0);

	}
}

int main()
{
intro();
setup();
while(!gameover)
{       draw();
	input();
	logic();
	for(long double i=0;i<400000;i++);

}
if(gameover)
{	system("CLS");
	cout<<"\n\n\n\n\t\t\t xxx  Game Over xxx" ;
	cout<<"\n\t\t\t     Your Score : "<<score;
	cout<<"\n\t\t\t     High scores: ";

}


getch();
}
