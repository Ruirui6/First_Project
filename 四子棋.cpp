#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
 
//全局变量
const char fuhao[11][4] = { "┌", "┬", "┐", "├", "┼", "┤", "└", "┴", "┘", "○", "●" };  //画棋盘所用工具
int qipan[4][4];
int step = 1;
 
void draw(int a[4][4])
{
	cout << " 0 1 2 3" << endl;
	for (int i = 0; i <= 3; ++i)
	{
		if (i != 0) cout << endl;
		cout << i;
		for (int j = 0; j <= 3; ++j)
		{
			cout << fuhao[a[i][j]];
		}
	}
	cout << endl;
}
 
void move(int x,int y, char mov)
{
	if (qipan[x][y]!=step) cout << "请选择己方子进行移动！" << endl;
	else
	{
		if (mov == 'U')
		{
			if (x == 0) cout << "无法移动！" << endl;
			else
			{
				qipan[x][y] = 0;
				x--;
				qipan[x][y] = step;
 
			}
		}
		else if (mov == 'D')
		{
			if (x == 3) cout << "无法移动！" << endl;
			else
			{
				qipan[x][y] = 0;
				x++;
				qipan[x][y] = step;
			}
		}
		else if (mov == 'L')
		{
			if (y == 0) cout << "无法移动！" << endl;
			else
			{
				qipan[x][y] = 0;
				y--;
				qipan[x][y] = step;
			}
		}
		else if (mov == 'R')
		{
			if (y == 3) cout << "无法移动！" << endl;
			else 
			{
				qipan[x][y] = 0;
				y++;
				qipan[x][y] = step;
			}
		}
		else
		{
			cout << "请输入正确方向！" << endl;
		}
	}
}
 
void chizi(int qipan[4][4])
{
	for (int i = 0; i <= 3; i++)
	{
		if (qipan[i][0] == -step && qipan[i][1] == step && qipan[i][2] == step && qipan[i][3] == 0)
		{
			qipan[i][0] = 0;
		}
		else if (qipan[i][0] == 0 && qipan[i][1] == -step && qipan[i][2] == step && qipan[i][3] == step)
		{
			qipan[i][1] = 0;
		}
		else if (qipan[i][0] == step && qipan[i][1] == step && qipan[i][2] == -step && qipan[i][3] == 0)
		{
			qipan[i][2] = 0;
		}
		else if (qipan[i][0] == 0 && qipan[i][1] == step && qipan[i][2] == step && qipan[i][3] == -step)
		{
			qipan[i][3] = 0;
		}
	}
	for (int j = 0; j <= 3; j++)
	{
		if (qipan[0][j] == -step && qipan[1][j] == step && qipan[2][j] == step && qipan[3][j] == 0)
		{
			qipan[0][j] = 0;
		}
		if (qipan[0][j] == 0 && qipan[1][j] == -step && qipan[2][j] == step && qipan[3][j] == step)
		{
			qipan[1][j] = 0;
		}
		if (qipan[0][j] == step && qipan[1][j] == step && qipan[2][j] == -step && qipan[3][j] == 0)
		{
			qipan[2][j] = 0;
		}
		if (qipan[0][j] == 0 && qipan[1][j] == step && qipan[2][j] == step && qipan[3][j] == -step)
		{
			qipan[3][j] = 0;
		}
	}
	return;
}
 
int panduan(int qipan[4][4])
{
	int sum = 0;
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			if (qipan[i][j] == -step) sum++;
		}
	}
	if (sum <= 1) return 1;
	else return 0;
}
 
int main()
{
	system("color 2f");
	system("mode con cols=50 lines=25");
	int a[4][4] =
	{
		0, 1, 1, 2,
		3, 4, 4, 5,
		3, 4, 4, 5,
		6, 7, 7, 8
	};
	int x, y;
	char mov;
	memset(qipan, 0, sizeof(qipan));
	a[0][0] = a[0][1] = a[0][2] = a[0][3] = 9, a[3][0] = a[3][1] = a[3][2] = a[3][3] = 10;
	qipan[0][0] = qipan[0][1] = qipan[0][2] = qipan[0][3] = -1, qipan[3][0] = qipan[3][1] = qipan[3][2] = qipan[3][3] = 1;
	draw(a);
	cout << "请输入所移动棋子与移动方向(棋子为数字，方向为“U，D，L，R”):" << endl;
	while (cin >> x >> y >> mov)
	{
		system("cls");
		move(x, y, mov);
		chizi(qipan);
		if (panduan(qipan))
		{
			cout << "宝贝儿我赢了！" << endl;
			break;
		}
		int a[4][4] =
		{
			0, 1, 1, 2,
			3, 4, 4, 5,
			3, 4, 4, 5,
			6, 7, 7, 8
		};
		for (int i = 0; i <= 3; i++)
		{
			for (int j = 0; j <= 3; j++)
			{
				if (qipan[i][j] == 1)a[i][j] = 10;
				else if(qipan[i][j] == -1)a[i][j] = 9;
			}
		}
		draw(a);
		cout << "请输入所移动棋子与移动方向(棋子为数字，方向为“U，D，L，R”):" << endl;
		step = -step;
	}
	cout << "谢谢使用" << endl;
	system("Pause>nul");
	return 0;
}
