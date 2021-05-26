#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

typedef int Info;

struct Elem
{
    Elem* link;
    Info info;
};

void insert(Elem*& L, Info num);
void remove(Elem*& L);
Info Count(Elem*& T, Elem*& first, Info k);
void Print(Elem*& T, Elem*& first);
Elem* lastElem(Elem*& L, Elem*& T);

int main()
{
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251); 

    srand((unsigned)time(NULL));
    Elem* L = NULL;

    insert(L, 0);

    Elem* T = L;
    Elem* first = L;
    Print(T, first);

    cout << endl << endl;
    T = L;
  
    cout << "У списку наявно: " << Count(T, first, 0) << " парних елементів!" << endl << endl;

    remove(L);

    cout << endl;
}

void insert(Elem*& L, Info num) 
{
    Info value = 1 + rand() % 100;
    Elem* tmp = new Elem;
    tmp->info = value;
    if (L != NULL) 
    {
        Elem* T = L;
        T = lastElem(L, T);
        T->link = tmp;
    }
    else 
    {
        L = tmp;
    }
    tmp->link = L;

    if (num < 10) {
        num++;
        insert(L, num);
    }
}

Elem* lastElem(Elem*& L, Elem*& T) { 
    if (T->link != L) {
        T = T->link;
        return lastElem(L, T);
    }
    else {
        return T;
    }
}

void remove(Elem*& L) 
{
    Elem* T = L;
    T = lastElem(L, T);
    Info value = L->info;
    if (T != L)
    {
        Elem* tmp = L->link;
        delete L;
        L = tmp;
        T->link = L;
    }
    else
    {
        delete L;
        L = NULL;
    }

    cout << value << " ";

    if (L != NULL) {
        remove(L);
    }
}

void Print(Elem*& T, Elem*& first) {
    if (T == NULL)
        return;
    if (T->link != first)
    {
        cout << T->info << " ";
        T = T->link;
        Print(T, first);
    }
    else {
        cout << T->info << " ";
        return;
    }
}

Info Count(Elem*& T, Elem*& first, Info k)
{
    if (T == NULL)
        return 0;
    if (T->link != first)
    {
        if (T->info % 2 == 0)
            k++;
        T = T->link;
        Count(T, first, k);
    }
    else
    {
        if (T->info % 2 == 0)
            k++;
        return k;
    }
}