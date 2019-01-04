#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
//#include<graphics.h>
#include<windows.h>
#include<process.h>
#include<iomanip>
#include<time.h>
#include<math.h>
#include<iostream>
using namespace std;
clock_t start,end;
int m[9][9],def[9][9],i,so[81],j,t=0;char name[20],fname[24],caar[10][10];
int sudokuBoard[9][9];
int solvedBoard[9][9];
int possibleNums[9][9][10];
void load(int);
int check(int ,int);
bool Solve(int in[9][9], int possible[9][9][10], int out[9][9], int start);
bool CheckOne(int in[9][9], int pos);
int ValidSolution(int in[9][9]);
bool GeneratePossibleNums(int sudokuBoard[9][9], int possibleNums[9][9][10]);

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
 system("cls");
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
cout<<"1.New player Or \n2.Revisiting \n3.Solver? ";cin>>s;
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
else if(s==3)
{
    cout<<"Enter the 81 elements with 0 in which no clue is given: \n";
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            cin>> sudokuBoard[i][j];
    if(GeneratePossibleNums(sudokuBoard, possibleNums))
    {
        for(int i = 0; i < 9; i++)
            {
                for(int j = 0; j < 9; j++)
                    cout << sudokuBoard[i][j] << " ";
                cout << endl;
            }
        if(ValidSolution(sudokuBoard) == 0)
        {
            for(int i = 0; i < 9; i++)
            {
                for(int j = 0; j < 9; j++)
                    cout << sudokuBoard[i][j] << " ";
                cout << endl;
            }
            CheckOne(solvedBoard, 5);
        }
        else{
            double numPossible = 1;
            for(int i = 0; i < 9; i++)
            {
                for(int j = 0; j < 9; j++)
                {
                    cout << i << " " << j << ": ";
                    numPossible *= possibleNums[i][j][0];
                    for(int k = 1; k <= possibleNums[i][j][0]; k++)
                        cout << possibleNums[i][j][k] << " ";
                    cout << endl;
                }
            }
            cout << "Number of combinations:" << numPossible << endl;
            cout << "Non easy Board" << endl;
        }
    }
    else
        cout << "Impossible Board" << endl;
    Solve(sudokuBoard, possibleNums, solvedBoard, 0);
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
            cout << solvedBoard[i][j] << " ";
        cout << endl;
    }
getch();
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


bool Solve(int in[9][9], int possible[9][9][10], int out[9][9], int start)
{
    while(in[start / 9][start % 9] != 0 && start < 81)
        start++;
    if(start >= 81)
    {
        if(ValidSolution(in) == 0)
        {
            for(int k = 0; k < 9; k++)
                for(int l = 0; l < 9; l++)
                    out[k][l] = in[k][l];
            return true;
        }
        return false;
    }
    for(int k = 0; k < 9; k++)
            for(int l = 0; l < 9; l++)
                out[k][l] = in[k][l];
    //Try the possibilities generated previously.
    for( int i = 1; i <= possible[start / 9][start % 9][0]; i++)
    {
        out[start / 9][start % 9] = possible[start / 9][start % 9][i];
        if(CheckOne(out, start))
        {
            int newBoard[9][9];
            if(Solve(out, possible, newBoard, start + 1))
            {
                for(int k = 0; k < 9; k++)
                    for(int l = 0; l < 9; l++)
                        out[k][l] = newBoard[k][l];
                return true;
            }
        }
    }
    return false;
}

//-------------------------------------------------------------------------------------------------
// Check if the square at pos is invalid.
// params(in, in)
// in - the 9x9 Sudoku board
// pos - position to check
//-------------------------------------------------------------------------------------------------
bool CheckOne(int in[9][9], int pos)
{
    int row = pos / 9;
    int col = pos % 9;
    for(int i = 0; i < 9; i++)
    {
        if(i != col && in[row][col] == in[row][i])
            return false;
    }
    for(int i = 0; i < 9; i++)
    {
        if(i != row && in[row][col] == in[i][col])
            return false;
    }
    int squareRow = (row / 3) * 3;
    int squareCol = (col / 3) * 3;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
        {
            if( (i + squareRow) != row && (j + squareCol) != col && in[row][col] == in[i + squareRow][j + squareCol])
                return false;
        }
    return true;
}

//-------------------------------------------------------------------------------------------------
// Checks if the board is a valid solution.
// in - the 9x9 Sudoku board to check
//-------------------------------------------------------------------------------------------------
int ValidSolution(int in[9][9])
{
    int numErrors = 0;
    for(int i = 0; i < 81; i++)
        if(!CheckOne(in, i))
            numErrors++;
    return numErrors;
}


//-------------------------------------------------------------------------------------------------
// Takes in a 9x9 sudokuBoard with 0s in empty positions. This function will put any numbers in
// the board where there is only one choice. possibleNums will contain a list of numbers that work
// in each square. If the board has any squares with no choices, then it will return false.
// Otherwise true is returned
// params(inout, out)
// sudokuBoard - 9x9 array
// possibleNums - 9x9x10 array ([][][0] indicates number of possible nums, the rest is a list of
// nums that work)
//-------------------------------------------------------------------------------------------------
bool GeneratePossibleNums(int sudokuBoard[9][9], int possibleNums[9][9][10])
{
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
        {
            if(sudokuBoard[i][j] == 0)
            {
                possibleNums[i][j][0] = 0;
                for(int k = 1; k <= 9; k++)
                {
                    sudokuBoard[i][j] = k;//Try with k in the place
                    if(CheckOne(sudokuBoard, (i) * 9 + j )) //was it a valid number??
                    {
                        possibleNums[i][j][++possibleNums[i][j][0]] = k;//add to list of possibilities
                    }
                }
                if(possibleNums[i][j][0] == 0)
                    return false;
                else if(possibleNums[i][j][0] == 1) //only one choice, use it
                {
                    sudokuBoard[i][j] = possibleNums[i][j][1];
                    i = j = 0;//restart loop using new info
                }
                else
                    sudokuBoard[i][j] = 0; //can't replace it
            }
            else
            {
                possibleNums[i][j][0] = 1; //already known
                possibleNums[i][j][1] = sudokuBoard[i][j];
            }
        }
        return true;
}



