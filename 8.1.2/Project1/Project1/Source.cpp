#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
char* Change(char* s);

int main()
{
	char s[100];

	cout << "Enter string:" << endl;
	cin.getline(s, 100);

	cout << endl;
	cout << "New string : " << Change(s) << endl;

	return 1;
}

char* Change(char* s)
{
	size_t len = strlen(s);
	if (len < 2)
		return s;

	char* tmp = new char[len * 1.5 + 1];
	char* t = tmp;

	tmp[0] = '\0';
	int i = 0;

	while (i < len && s[i + 1] != 0)
	{
		if ((s[i] == 'w' && s[i + 1] == 'h' && s[i + 2] == 'i' && s[i + 3] == 'l' && s[i + 4] == 'e'))
		
		{
			strcat(t, "***");
			t += 3; // кількість зірочок
			i += 5; //кількість симолів які замінити на 3 зірочки
		}
		else
		{
			*t++ = s[i++];
			*t = '\0';
		}
	}
	*t++ = s[i++];
	*t++ = s[i++];
	*t = '\0';

	strcpy(s, tmp);
	return tmp;
}