#include<fstream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<dos.h>
//#include<graphics.h>
#include<process.h>
#include<iomanip>
#include<time.h>
#include<math.h>
#include<windows.h>
using namespace std;
clock_t start,end;
int m[9][9],def[9][9],i,so[81],j,t=0;char name[20],fname[24],caar[10][10];
void load(int);
int check(int ,int);
void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}
void screen()
{

gotoxy(1,1);cout<<"    1   2   3   4   5   6   7   8   9 ";
for(int z=1;z<=9;z++)
 { cout<<"\n    \n"<<z;
 }
gotoxy(50,13);cout<<"(x,y): x------>";
gotoxy(50,14);cout<<"      y ";
gotoxy(50,15);cout<<"      | ";
gotoxy(50,16);cout<<"      | ";
gotoxy(50,17);cout<<"      | ";
gotoxy(50,18);cout<<"      v ";
}
void board()
{

 for(i=1;i<=9;i++)
 {
    for(j=1;j<=9;j++)
     {
      gotoxy(4*i+1,2*j+1);

      cout<<m[i][j];
     }
 }
}
void save()
{
fstream f1;
f1.open(fname,ios::out);
for(i=1;i<=9;i++)
 {
  for(j=1;j<=9;j++)
   {
    f1<<m[i][j];
    }
  }
f1.close();
}
int check(int x,int y)
{
 if(caar[x][y]!='0')
  {
  return 0;
  }
 else
    return 1;
}
void player()
{
do{
l: system("cls");
 board();
 screen();
 int x,y,v;
 gotoxy(50,1);cout<<name<<"'s arena    (x=11=>exit)\n";
 gotoxy(50,2);cout<<"GOTO: (";cin>>x;
  if(x==11)
  {
end = clock();
gotoxy(50,9);cout<<"The time was: \n";
gotoxy(50,10);cout<<(end - start) / CLK_TCK<<"+"<<t<<"="<< (end - start) / CLK_TCK+t;
fstream f1;
f1.open(fname,ios::app);
f1<<'t';
f1<<(end-start)/CLK_TCK+t;
f1.close();
getch();
exit(0);
  }
 gotoxy(58,2);cout<<",";cin>>y;gotoxy(60,2);cout<<")"; cout<<"\n";
  if(check(x,y)==0)
  {
   gotoxy(50,4);cout<<"Sorry. This position contains";
   gotoxy(50,5);cout<<"       a defalt value";   getch();
  }
  if(x>9||y>9||x<1||y<1||check(x,y)==0){goto l;}
 m: gotoxy(4*x+1,2*y+1);
 cin>>v;
 if(v>9||v<1) goto m;
 m[x][y]=v;
 if(so[(x-1)*9+y]!=v)
 {
 gotoxy(50,4);cout<<"HINT:";
 gotoxy(50,5);cout<<"This no. doesn't come here";
 getch();
 }
 save();
 }while(1);
}

int main()
{
system("cls");//textcolor(WHITE);
/*cout<<"\n\n\t\t\t\tPlease wait while loading\n\n";
 char a=177, b=219;
 cout<<"\t\t\t\t";
 for (int i=0;i<=15;i++)
 cout<<a;
 cout<<"\r";
 cout<<"\t\t\t\t";
 for (i=0;i<=15;i++)
 {
  cout<<b;
  delay(50);
 }
 clrscr();
 closegraph();
 textcolor(WHITE);*/
 cout<<"\n\n\n\n\n\n\n";
 cout<<"     |||||||  ||     ||  ||||||    ||||||||  ||  ||  ||     ||  " <<endl;
 cout<<"     ||       ||     ||  ||    ||  ||    ||  || ||   ||     ||  " <<endl;
 cout<<"     |||||||  ||     ||  ||    ||  ||    ||  ||||    ||     ||  " <<endl;
 cout<<"          ||  ||     ||  ||    ||  ||    ||  || ||   ||     ||  " <<endl;
 cout<<"     |||||||  |||||||||  |||||||   ||||||||  ||  ||  |||||||||  " <<endl;
 cout<<"     Computer Science project by Shubham Dhiman and Meherdeep Thakur "<<endl;
 cout<<"\n\n";
int s;
cout<<"1.New player Or \n2.Revisiting...? ";cin>>s;
cout<<"Enter the name you wish to play with...";gets(name);
strcpy(fname,name);
strcat(fname,".txt");
load(s);
start=clock();
player();
getch();
}
void load(int s)
{     int c=1,ar[81],nar[81];char ch,car[82];

if(s==1)
{
ifstream a("sud9.txt");
for(i=1;i<=81;i++)
  {
 a.get(ch);
 ar[i]=ch-48;
  }
for(i=1;i<=9;i++)
  {
  for(j=1;j<=9;j++)
   {
    m[i][j]=ar[c];
    caar[i][j]=ar[c]+48;
    c++;
   }
  }

a.close();
}
else if(s==2)
{
ifstream b(fname);
for(i=1;i<=81;i++)
  {
 b.get(ch);
 ar[i]=ch-48;
  }
for(i=1;i<=9;i++)
  {
  for(j=1;j<=9;j++)
   {
    m[i][j]=ar[c];
    c++;
   }
  }
b.seekg(82);
b.get(ch);
for(;ch!='.';)
{
t=10*t+(ch-48);
b.get(ch);
}
cout<<"Your time was "<<t<<" seconds";
getch();
b.close();
}
else exit(0);

 { c=1;
ifstream a("sud9.txt");
for(i=1;i<=81;i++)
  {
 a.get(ch);
 nar[i]=ch-48;
  }
for(i=1;i<=9;i++)
  {
  for(j=1;j<=9;j++)
   {
    caar[i][j]=nar[c]+48;
    c++;
   }
  }
 a.close();
}
{ c=1;
ifstream soln("sud2sol.txt");
for(i=1;i<=81;i++)
  {
 soln.get(ch);
 so[i]=ch-48;
  }
soln.close();
}
}

