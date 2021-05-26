//Варіант 21: Обчислити кількість елементів списку з непарними значеннями інформаційного поля.
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

void enqueue(Elem*& first, Elem*& last, Info k, Info numb);
void check(Elem* first, Info& n);
void dequeue(Elem*& first, Elem*& last);

int main()
{
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251); 
	srand((unsigned)time(NULL));
	Elem* first = NULL,
		* last = NULL;

	enqueue(first, last, 1, 10);

	Info n = 0;
	cout << "Непарні елементи: ";
	check(first, n); 
	cout << endl << endl;
	cout << "В цьому списку наявно: " << n << " непарних елементів";
	cout << endl << endl;
	cout << "Список: ";
	dequeue(first, last); 
	cout << endl;

	return 0;
}
void enqueue(Elem*& first, Elem*& last, Info n, Info numb)
{
	Info num = 1 + rand() % 10;
	Elem* tmp = new Elem;
	tmp->info = num;
	tmp->link = NULL;
	if (last != NULL)
		last->link = tmp;
	last = tmp;
	if (first == NULL)
		first = tmp;
	if (n < numb) {
		n++;
		enqueue(first, last, n, numb);
	}

}

void dequeue(Elem*& first, Elem*& last)
{
	Elem* tmp = first->link;
	Info value = first->info;
	delete first;
	first = tmp;
	if (first == NULL)
		last = NULL;
	cout << value << " ";
	if (last != NULL) {
		dequeue(first, last);
	}
}

void check(Elem* first, Info& n)
{
	if (first != NULL) {
		if (first->info % 2 != NULL) {
			cout << first->info << " ";
			n++;
		}
		first = first->link;
		check(first, n);
	}
}