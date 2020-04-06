#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
 
//ȫ�ֱ���
const char fuhao[11][4] = { "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��" };  //���������ù���
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
	if (qipan[x][y]!=step) cout << "��ѡ�񼺷��ӽ����ƶ���" << endl;
	else
	{
		if (mov == 'U')
		{
			if (x == 0) cout << "�޷��ƶ���" << endl;
			else
			{
				qipan[x][y] = 0;
				x--;
				qipan[x][y] = step;
 
			}
		}
		else if (mov == 'D')
		{
			if (x == 3) cout << "�޷��ƶ���" << endl;
			else
			{
				qipan[x][y] = 0;
				x++;
				qipan[x][y] = step;
			}
		}
		else if (mov == 'L')
		{
			if (y == 0) cout << "�޷��ƶ���" << endl;
			else
			{
				qipan[x][y] = 0;
				y--;
				qipan[x][y] = step;
			}
		}
		else if (mov == 'R')
		{
			if (y == 3) cout << "�޷��ƶ���" << endl;
			else 
			{
				qipan[x][y] = 0;
				y++;
				qipan[x][y] = step;
			}
		}
		else
		{
			cout << "��������ȷ����" << endl;
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
	cout << "���������ƶ��������ƶ�����(����Ϊ���֣�����Ϊ��U��D��L��R��):" << endl;
	while (cin >> x >> y >> mov)
	{
		system("cls");
		move(x, y, mov);
		chizi(qipan);
		if (panduan(qipan))
		{
			cout << "��������Ӯ�ˣ�" << endl;
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
		cout << "���������ƶ��������ƶ�����(����Ϊ���֣�����Ϊ��U��D��L��R��):" << endl;
		step = -step;
	}
	cout << "ллʹ��" << endl;
	system("Pause>nul");
	return 0;
}
