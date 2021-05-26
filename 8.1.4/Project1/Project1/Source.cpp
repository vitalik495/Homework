#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>

using namespace std;

void Change(char* str, char* str2, int i, int j, const int d);

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    int d;

    char str2[50]; // допом≥жний масив

    d = strlen(str); // довжина р€дка str

    Change(str, str2, 0, 0, d);

    cout << str << endl;
}


void Change(char* str, char* str2, int i, int j, const int d) {
    if (i < d)
    {
        if ((str[i] == 'w' && str[i + 1] == 'h' && str[i + 2] == 'i' && str[i + 3] == 'l' && str[i + 4] == 'e'))
            // пров≥рка на одинаков≥ символи
        {
            str2[j++] = '*';
            str2[j++] = '*';
            str2[j++] = '*';


            Change(str, str2, i + 5, j, d);
        }
        else
        {
            str2[j++] = str[i]; // €кщо не проходить умова, то символ записуЇтьс€ в масив
            Change(str, str2, i + 1, j, d);
        }
    }
    else
    {
        str2[j] = '\0'; // додаЇ символ к≥нц€ р€дка
        strcpy(str, str2); // коп≥юЇ допом≥жний масив у вих≥дний
    }
}