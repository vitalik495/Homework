#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>

using namespace std;

int Count(char* str);

int main()
{
    char str[100]; 
    cout << "Enter string:" << endl;
    cin.getline(str, 100); 

    cout << "Words, which have same first letter 'b': " << Count(str) << endl; 
}

int Count(char* str) {
    int k = 0;
    char* str2; 

    str2 = strtok(str, " "); 
    while (str2 != NULL) 
    {
        int d = strlen(str2); // визначення скільки символів у "слові"
        if (str2[0] == 'b') { // провірка \чи слова починаються з букви 'b'
            k++; 
        }
        str2 = strtok(NULL, " "); 
    }
    return k;
}