#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
void Change(char* str);

int main()
{
	char str[101]; // оголошується масив
	cout << "Enter string:" << endl;
	cin.getline(str, 100); // вводяться написані символи в масив

	Change(str); 
	cout << "Result: " << str << endl;

}

void Change(char* str)
{
	char* t = new char[strlen(str)];
	int d;
	int pos1 = 0;
	int pos2 = 0;
	*t = 0;
	d = strlen(str); // довжина  str
	int i = 0;
	while (i < strlen(str) - 3)
	{
		if ((str[i] == 'w' && str[i + 1] == 'h' && str[i + 2] == 'i' && str[i + 3] == 'l' )) // провірка на одинакові символи
		{
			pos2 = i + 4; 
			strncat(t, str + pos1, pos2 - pos1 - 4); 
			strcat(t, "***"); 
			pos1 = pos2;
			i += 4;
		}
		i++;
	}
	strcat(t, str + pos1); 
	strcpy(str, t); // копіюється строка t в str
}