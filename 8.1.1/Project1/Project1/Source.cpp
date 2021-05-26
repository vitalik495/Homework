#include <string.h>
#include <iostream>

using namespace std;

bool Include(const char* s, const char* cs);

int main()
{
	char s[101];
	char cs[] = "while";
	cout << "Enter string:" << endl;
	cin.getline(s, 100);
	if (Include(s, cs))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}


bool Include(const char* s, const char* cs)
{
	bool b, r = true;
	for (int i = 0; cs[i] != '\0'; i++)
	{
		b = false;
		for (int j = 0; s[j] != '\0'; j++)
			if (cs[i] == s[j])
			{
				b = true;
				break;
			}
		r = r && b;
	}
	return r;
}