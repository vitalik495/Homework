#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 
using namespace std;

enum Specialnist { KN, ME, IF, FI, TN }; 
string specialnistList[] = { "���� �����", "��� � ������", "������", "��� � ������", "���� ����" };
struct Student
{
	string prizv;
	int kurs;
	Specialnist spec;
	int fiz;
	int mat;
	union
	{
		int prog;
		int chis_metod;
		int pedagog;
		int mid;
	};
};
void Create(Student* p, const int N);
void Print(Student* p, const int N);
void Search(Student* p, const int N);
void Find(Student* p, const int N);

int main()
{ 
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	int N;
	cout << "������ ������� ��������: "; cin >> N;
	Student* p = new Student[N];
	Create(p, N);
	Print(p, N);
	Search(p, N);
	Find(p, N);
}
void Create(Student* p, const int N)
{
	int spec;
	for (int i = 0; i < N; i++)
	{
		cout << "C������ � " << i + 1 << ":" << endl;
		cin.get();
		cin.sync(); 
		cout << "�������: "; getline(cin, p[i].prizv);
		cout << "����: "; cin >> p[i].kurs;
		if (p[i].kurs <= 0) {
			p[i].kurs = 1;
			cout << endl;
			cout << "���� ���������, �� ������!" << endl;
			cout << endl;
		}
		if (p[i].kurs > 6) {
			p[i].kurs = 6;
			cout << endl;
			cout << "���� ���������, �� \"6\"!" << endl;
			cout << endl;
		}
		cout << "������ � ������: "; cin >> p[i].fiz;
		if (p[i].fiz > 5) {
			p[i].fiz = 5;
			cout << endl;
			cout << "������ ���������, �� �����������!" << endl;
			cout << endl;
		}
		if (p[i].fiz < 0) {
			p[i].fiz = 0;
			cout << endl;
			cout << "������ ���������, �� ��������!" << endl;
			cout << endl;
		}
		cout << "������ � ����������: "; cin >> p[i].mat;
		if (p[i].mat > 5) {
			p[i].mat = 5;
			cout << endl;
			cout << "������ ���������, �� �����������!" << endl;
			cout << endl;
		}
		if (p[i].mat < 0) {
			p[i].mat = 0;
			cout << endl;
			cout << "������ ���������, �� ��������!" << endl;
			cout << endl;
		}
		cout << "c����������� (0 - ����. �����, 1 - ��� � ������, 2 - ������, 3 - ��� � ������, 4 - ����. ����): ";  cin >> spec;
		if (spec > 4) {
			cout << endl;
			cout << "============================================================================================================" << endl;
			cout << endl;
			cout << "�����, �� ����� ����������� �������� ������������!" << endl;
			cout << "�������� ���������� ������ � ������������� �� ������������� - ����. �����!" << endl;
			cout << "������������ �������� ��� �������� ����������� ������ ������������." << endl;
			cout << endl;
			cout << "============================================================================================================" << endl;
			cout << endl;
			spec = 0;
		}
		p[i].spec = (Specialnist)spec;
		switch (p[i].spec)
		{
		case KN:
			cout << "������ � �������������: "; cin >> p[i].prog;
			if (p[i].prog > 5) {
				p[i].prog = 5;
				cout << endl;
				cout << "������ ���������, �� �����������!" << endl;
				cout << endl;
			}
			if (p[i].prog < 0) {
				p[i].prog = 0;
				cout << endl;
				cout << "������ ���������, �� ��������!" << endl;
				cout << endl;
			}
			p[i].mid = (p[i].mat + p[i].fiz + p[i].prog) / 3;
			break;
		case ME:
			cout << "������ � ���������: "; cin >> p[i].pedagog;
			if (p[i].pedagog > 5) {
				p[i].pedagog = 5;
				cout << endl;
				cout << "������ ���������, �� �����������!" << endl;
				cout << endl;
			}
			if (p[i].pedagog < 0) {
				p[i].pedagog = 0;
				cout << endl;
				cout << "������ ���������, �� ��������!" << endl;
				cout << endl;
			}
			p[i].mid = (p[i].mat + p[i].fiz + p[i].pedagog) / 3;
			break;
		case IF:
			cout << "������ � ��������� ������: "; cin >> p[i].chis_metod;
			if (p[i].chis_metod > 5) {
				p[i].chis_metod = 5;
				cout << endl;
				cout << "������ ���������, �� �����������!" << endl;
				cout << endl;
			}
			if (p[i].chis_metod < 0) {
				p[i].chis_metod = 0;
				cout << endl;
				cout << "������ ���������, �� ��������!" << endl;
				cout << endl;
			}
			p[i].mid = (p[i].mat + p[i].fiz + p[i].chis_metod) / 3;
			break;
		case FI:
			cout << "������ � ���������: "; cin >> p[i].pedagog;
			if (p[i].pedagog > 5) {
				p[i].pedagog = 5;
				cout << endl;
				cout << "������ ���������, �� �����������!" << endl;
				cout << endl;
			}
			if (p[i].pedagog < 0) {
				p[i].pedagog = 0;
				cout << endl;
				cout << "������ ���������, �� ��������!" << endl;
				cout << endl;
			}
			p[i].mid = (p[i].mat + p[i].fiz + p[i].pedagog) / 3;
			break;
		case TN:
			cout << "������ � ���������: "; cin >> p[i].pedagog;
			if (p[i].pedagog > 5) {
				p[i].pedagog = 5;
				cout << endl;
				cout << "������ ���������, �� �����������!" << endl;
				cout << endl;
			}
			if (p[i].pedagog < 0) {
				p[i].pedagog = 0;
				cout << endl;
				cout << "������ ���������, �� ��������!" << endl;
				cout << endl;
			}
			p[i].mid = (p[i].mat + p[i].fiz + p[i].pedagog) / 3;
			break;
		}
		cout << endl;
	}
}
void Print(Student* p, const int N)
{
	cout << "============================================================================================================"
		<< endl;
	cout << "| � | ������� | ���� | C����������� | Գ���� | ���������� | ������������� | ������� ������ | ��������� |"
		<< endl;
	cout << "------------------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "|" << setw(2) << right << i + 1 << " ";
		cout << "| " << setw(9) << left << p[i].prizv
			<< "| " << setw(2) << right << p[i].kurs << "  "
			<< " | " << setw(14) << left << specialnistList[p[i].spec]
			<< setw(4) << "| " << setw(3) << left << p[i].fiz << "  "
			<< setw(6) << "| " << setw(6) << left << p[i].mat << " ";
		switch (p[i].spec)
		{
		case KN:
			cout << setw(8) << "| " << setw(7) << left << p[i].prog << setw(19)
				<< " | " << setw(12) << left
				<< "| " << left << " |" << endl;
			break;
		case ME:
			cout << "" << setw(15) << "| " << " "
				<< "" << setw(18) << "| "
				<< setw(6) << "| " << setw(6) << left << p[i].pedagog << " |" << endl;
			break;
		case IF:
			cout << "" << setw(15) << "| " << setw(9) << " |" << " "
				<< setw(8) << p[i].chis_metod << " |" << " "
				<< setw(10) << "" << " |" << endl;
			break;
		case FI:
			cout << "" << setw(15) << "| " << " "
				<< "" << setw(18) << "| "
				<< setw(6) << "| " << setw(6) << left << p[i].pedagog << " |" << endl;
			break;
		case TN:
			cout << "" << setw(15) << "| " << " "
				<< "" << setw(18) << "| "
				<< setw(6) << "| " << setw(6) << left << p[i].pedagog << " |" << endl;
			break;
		}
	}
	cout << "============================================================================================================"
		<< endl;
	cout << endl;
}
void Search(Student* p, const int N)
{
	cout << "��������, �� ����� ���� � ������� '������' : ";
	int k = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].mat == 5) {
			k++;
		}
		if (p[i].fiz == 5) {
			k++;
		}
		switch (p[i].spec) {
		case KN:
			if (p[i].prog == 5) {
				k++;
			}
			break;
		case ME:
			if (p[i].pedagog == 5) {
				k++;
			}
			break;
		case IF:
			if (p[i].chis_metod == 5) {
				k++;
			}
			break;
		case TN:
			if (p[i].pedagog == 5) {
				k++;
			}
			break;
		case FI:
			if (p[i].pedagog == 5) {
				k++;
			}
			break;
		}
		if (k == 3) {
			cout << p->prizv;
		}
		k = 0;
	}
	cout << endl;
}

void Find(Student* p, const int N) {
	int k = 0;
	for (int i = 0; i < N; i++) {
		if (p[i].mid > 4.5) {
			k++;
		}
	}
	int proc = (k * 100) / N;
	cout << "³������ ��������, � ���� ������� ��� ������ �� 4,5: " << proc << endl;
}