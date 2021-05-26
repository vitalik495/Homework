//������ 21: ��������� ������� �������� ������ � ��������� ���������� �������������� ����.
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

void enqueue(Elem*& first, Elem*& last, Info value);
Info check(Elem* first);
Info dequeue(Elem*& first, Elem*& last);

int main()
{
	srand((unsigned)time(NULL));
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);

	Elem* first = NULL,
		* last = NULL;
	Info num;
	for (int i = 1; i <= 10; i++) {
		num = 1 + rand() % 10;
		enqueue(first, last, num);
	}


	Info result = check(first);
	cout << "������ ";
	while (last != NULL) {
		cout << dequeue(first, last) << " ";
	}
	cout << endl;
	cout << "� ����� ������ ������: " << result << " �������� �����";
	cout << endl << endl;
	

	return 0;
}
void enqueue(Elem*& first, Elem*& last, Info value)
{
	Elem* tmp = new Elem;
	tmp->info = value;
	tmp->link = NULL;
	if (last != NULL)
		last->link = tmp;
	last = tmp;
	if (first == NULL)
		first = tmp;
}

Info dequeue(Elem*& first, Elem*& last)
{
	Elem* tmp = first->link;
	Info value = first->info;
	delete first;
	first = tmp;
	if (first == NULL)
		last = NULL;
	return value;
}


Info check(Elem* first)
{
	Info k = 0;
	cout << "������ �����: ";
	while (first != NULL) {
		if (first->info % 2 != 0) {
			cout << first->info << " ";
			k++;
		}
		first = first->link;
	}
	cout << endl << endl;
	return k;
}