#include<iostream>
#include<conio.h>  
#include<windows.h>
#include<time.h>
using namespace std;
int const rowSize = 20;
int const colSize = 20;
int score = 0;
char button = 'y';   //random button to stop snake when started
int moves=0;
//funcation for borders
void mapformation(char map[][colSize])
{
	for (int i = 0; i < colSize; i++)   //upper and lower boundry
	{
		map[0][i] = '-';
		map[rowSize - 1][i] = '-';
	}
	for (int j = 0; j < rowSize; j++)   //right and left boundry
	{
		map[j][0] = '|';
		map[j][colSize - 1] = '|';
	}
	for (int i = 1; i < rowSize-1; i++)   //giving space in between boundry
	{
		for (int j = 1; j < colSize-1; j++)
		{
			 map[i][j]=' ';
		}
	}
}
//funcation for random number
void ramdomnumber(char map[][colSize], int& a, int& b,int &x,int &y)
{
	while (x == a && y == b)
	{
		x = (rand() % (rowSize - 2)) + 1; //randomnumber in the range of height
		y = (rand() % (colSize - 2)) + 1; // ranomnumber in the range of width
			score++;
	}
	map[x][y] = 'o';     // print fruit
}
//funcation for movement
void movement(char map[][colSize],int &a,int &b)
{
	Sleep(200); // determine the speed of snake
	system("cls");  // to clear system
	if (_kbhit())   // to move snake continuously
	{
		button = _getch();
		cout << endl;
		moves++;
	}
	else
		cout << "enter w for up and s for down and a to left and d to move right" << endl;
		if (button == 'w' || button == 'W')  // to move snake up
		{
			map[a][b] = ' ';   //snake cannot cross the boundry
			a--;
			map[a][b] = '$'; 
	    }
		if (button == 's' || button == 'S')  //to mave down
		{
			map[a][b] = ' ';   //snake cannot cross the boutton
			a++;
			map[a][b] = '$';
		}
		if (button == 'a' || button == 'A')  //to move left
		{
			    map[a][b] = ' ';    //snake cannot cross boundry
				b--;
				map[a][b] = '$';
		}
		if (button == 'd' || button == 'D')   
		{
			    map[a][b] = ' ';    //to move snake right
				b++;
				map[a][b] = '$';
		}
}
//funcation formap printing
void mapprint(char map[][colSize])
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);  //to add colors in game 
	for (int i = 0; i < rowSize; i++)  //to print rows
	{
		for (int j = 0; j < colSize; j++)  //to print coloumbs
        {
			if (map[i][j] == '$')  //snake color
			{
				SetConsoleTextAttribute(color, 4);
			}
			else if (map[i][j] == 'o')  //fruit color
			{
				SetConsoleTextAttribute(color, 13);
			}
			else if ((map[i][j] == '-') || (map[i][j] == '|')) //boundry color
			{
				SetConsoleTextAttribute(color,1);
			}
			else 
			{
				SetConsoleTextAttribute(color, 7);
			}
			cout << map[i][j];
		}
        cout << endl;
	}
	SetConsoleTextAttribute(color, 7);  //text color
	cout <<"score = "<< score; //print score
}
int main()
{
	int n,p;
	cout << "       WELCOME TO MUAAZ (NOOB CODER GAME)   \n\n\n";
	cout << "GAME START \n ENTER W FOR UP \n ENTER S FOR DOWN \n ENTER A FOR LEFT \n ENTER D FOR RIGHT\n " << endl;
	cout << "DO NOT TOUCH THE BOUNDRY \n \n";
	cout << "ENJOY THE GAME " << endl;
	cout << "ENTER 1 to play according to you own limit and 0 to play infinity";
	p = _getch(); // to start game
	system("cls");  
	srand(time(0));  //give value to time funcation
	int a, b,i=0,x, y;
	bool flag = true;
	x = (rand() % (rowSize - 2)) + 1;  //random funcation in x
	y = (rand() % (colSize - 2)) + 1;   //random funcation in y
	a = rowSize / 2;     //making snake at center
	b = colSize / 2;
	if (p == '1')
	{
		cout << "enter the number of fruits to which you want to play game";
		cin >> n;
		//calling all funcation in one loop
		while (score != n)
		{
			char map[rowSize][colSize];
			mapformation(map);
			map[a][b] = '$';
			ramdomnumber(map, a, b, x, y);
			mapprint(map);
			movement(map, a, b);
			if (a == 0 || b == 0 || a == rowSize - 1 || b == colSize - 1)
			{
				flag = false;
				break;
			}
			i++;
		}
		system("cls");
		if (flag == true)  //if player won cong message
		{
			cout << "congragulation you won \n\n ";
			cout << "no of moves = " << moves;
		}
		if (flag == false)  //if snake touch boundry loss message
		{
			cout << "you loss\n\n\n";
			cout << "your score = " << score << endl << endl;
			cout << " no of moves = " << moves;
		}
	}
	else if (p == '0')
	{
		while (true)
		{
			char map[rowSize][colSize];
			mapformation(map);
			map[a][b] = '$';
			ramdomnumber(map, a, b, x, y);
			mapprint(map);
			movement(map, a, b);
			if (a == 0 || b == 0 || a == rowSize - 1 || b == colSize - 1)
			{
				flag = false;
				break;
			}
			i++;
		}
		system("cls");
		if (flag == true)  //if player won cong message
		{
			cout << "congragulation you won \n\n ";
			cout << "no of moves = " << moves << endl;
		}
		if (flag == false)  //if snake touch boundry loss message
		{
			cout << "you loss\n\n\n";
			cout << "your score = " << score << endl << endl;
			cout << "no of moves = " << moves << endl << endl;
		}
	}
	system("pause");
	return 0;
}