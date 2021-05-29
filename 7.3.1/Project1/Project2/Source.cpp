//ϳ��������� ������� ��������� ������ � void;
//���� ������ ��������, �� ���� ������� �������, � �-���� int;
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int rowCount, const int colCount);
void min(int** a, const int n, int& kilk);
void ab(int** a, int** b, const int n, const int max);

int main()
{
	srand((unsigned)time(NULL));
	int Low = -10;
	int High = 10;
	int n, kilk;

	cout << "Kilkist ryadiv v masuvi = "; cin >> n;

	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];

	int** b = new int* [n + 2];
	for (int i = 0; i < n + 2; i++)
		b[i] = new int[n + 2];

	Create(a, n, n, Low, High);

	Print(a, n, n);
	ab(a, b, n + 2, High + 1);
	Print(b, n + 2, n + 2);
	kilk = 0;
	min(b, n + 2, kilk);
	cout << "kilkist = " << kilk << endl;


	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void Input(int** a, const int rowCount, const int colCount)
{

	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
		cout << endl;
	}
}

void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

void ab(int** a, int** b, const int n, const int max)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			b[i][j] = max;

	for (int i = 1; i < n - 1; i++)
		for (int j = 1; j < n - 1; j++)
			b[i][j] = a[i - 1][j - 1];

}

void min(int** b, const int n, int& kilk)
{
	for (int i = 1; i < n - 1; i++)
		for (int j = 1; j < n - 1; j++)
			if (
				(b[i][j] < b[i][j - 1]) && (b[i][j] < b[i - 1][j]) && (b[i][j] < b[i][j + 1]) && (b[i][j] < b[i + 1][j]))
				
			{
				kilk++;
			}
}