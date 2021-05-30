#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 
using namespace std;

enum Specialnist { KN, ME, IF, FI, TN }; 
string specialnistList[] = { "комп науки", "мат і економ", "інформ", "фіз і інформ", "труд навч" };
struct Student
{
	string prizv;
	int kurs;
	Specialnist spec;
	int fiz;
	int mat;
	int avarage;
	union
	{
		int prog;
		int chis_metod;
		int pedagog;
	};
};
void Create(Student* p, const int N);
void Print(Student* p, const int N);
void Sort(Student* p, const int N);
int* IndexSort(Student* p, const int N);
void PrintIndexSorted(Student* p, int* I, const int N);
int BinSearch(Student* p, const int N, const string prizv, const Specialnist special, const int kurs);
int main()
{ 
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N;
	int ispec;
	Specialnist special;
	string prizv;
	int found;
	int kurs;
	cout << "Введіть кількість студентів: "; cin >> N;
	Student* p = new Student[N];
	double proc;
	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - ввід даних з клавіатури" << endl;
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [3] -  cортування" << endl;
		cout << " [4] - Індексне сортування та його вивід" << endl;
		cout << " [5] - Бінарний пошук" << endl;
		cout << " [0] - вихід з програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			Create(p, N);
			break;
		case 2:
			Print(p, N);
			break;
		case 3:
			Sort(p, N);
			cout << "Таблиця була відсортована!";
			break;
		case 4:
			PrintIndexSorted(p, IndexSort(p, N), N);
			break;
		case 5:
			Sort(p, N);
			cout << "Введіть ключі пошуку:" << endl;
			cout << "cпеціальність (0 - комп. науки, 1 - мат і економ, 2 - інформ, 3 - фіз і інформ, 4 - труд. навч): ";
			cin >> ispec;
			special = (Specialnist)ispec;
			cin.get();
			cin.sync();
			cout << " прізвище: ";
			getline(cin, prizv);
			cout << " Курс:"; cin >> kurs;
			cout << endl;
			if ((found = BinSearch(p, N, prizv, special, kurs)) != -1)
				cout << "Знайдено студента в позиції " << found + 1 << endl;
			else
				cout << "Шуканого студента не знайдено" << endl;
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели помилкове значення! "
				"Слід ввести число - номер вибраного пункту меню" << endl;
		}
	} while (menuItem != 0);
	return 0;
}
void Create(Student* p, const int N)
{
	int spec;
	for (int i = 0; i < N; i++)
	{
		cout << "Cтудент № " << i + 1 << ":" << endl;
		cin.get(); 
		cin.sync(); 
		cout << "прізвище: "; getline(cin, p[i].prizv);
		cout << "курс: "; cin >> p[i].kurs;
		if (p[i].kurs <= 0) {
			p[i].kurs = 1;
			cout << endl;
			cout << "Курс розпізнано, як перший!" << endl;
			cout << endl;
		}
		if (p[i].kurs > 6) {
			p[i].kurs = 6;
			cout << endl;
			cout << "Курс розпізнано, як \"6\"!" << endl;
			cout << endl;
		}
		cout << "оцінка з фізики: "; cin >> p[i].fiz;
		if (p[i].fiz > 5) {
			p[i].fiz = 5;
			cout << endl;
			cout << "Оцінка розпізнана, як максимальна!" << endl;
			cout << endl;
		}
		if (p[i].fiz < 0) {
			p[i].fiz = 0;
			cout << endl;
			cout << "Оцінка розпізнана, як мінімальна!" << endl;
			cout << endl;
		}
		cout << "оцінка з математики: "; cin >> p[i].mat;
		if (p[i].mat > 5) {
			p[i].mat = 5;
			cout << endl;
			cout << "Оцінка розпізнана, як максимальна!" << endl;
			cout << endl;
		}
		if (p[i].mat < 0) {
			p[i].mat = 0;
			cout << endl;
			cout << "Оцінка розпізнана, як мінімальна!" << endl;
			cout << endl;
		}
		cout << "cпеціальність (0 - комп. науки, 1 - мат і економ, 2 - інформ, 3 - фіз і інформ, 4 - труд. навч): ";  cin >> spec;
		if (spec > 4) {
			cout << endl;
			cout << "============================================================================================================" << endl;
			cout << endl;
			cout << "Схоже, ви ввели неправильне значення спеціальності!" << endl;
			cout << "Програма продовжить роботу з спеціальностю за замовчуванням - комп. науки!" << endl;
			cout << "Перезапустіть програму для введення правильного номера спеціальності." << endl;
			cout << endl;
			cout << "============================================================================================================" << endl;
			cout << endl;
			spec = 0;
		}
		p[i].spec = (Specialnist)spec;
		switch (p[i].spec)
		{
		case KN:
			cout << "оцінка з програмування: "; cin >> p[i].prog;
			if (p[i].prog > 5) {
				p[i].prog = 5;
				cout << endl;
				cout << "Оцінка розпізнана, як максимальна!" << endl;
				cout << endl;
			}
			if (p[i].prog < 0) {
				p[i].prog = 0;
				cout << endl;
				cout << "Оцінка розпізнана, як мінімальна!" << endl;
				cout << endl;
			}
			p[i].avarage = (p[i].mat + p[i].fiz + p[i].prog) / 3.0;
			break;
		case ME:
			cout << "оцінка з педагогіки: "; cin >> p[i].pedagog;
			if (p[i].pedagog > 5) {
				p[i].pedagog = 5;
				cout << endl;
				cout << "Оцінка розпізнана, як максимальна!" << endl;
				cout << endl;
			}
			if (p[i].pedagog < 0) {
				p[i].pedagog = 0;
				cout << endl;
				cout << "Оцінка розпізнана, як мінімальна!" << endl;
				cout << endl;
			}
			p[i].avarage = (p[i].mat + p[i].fiz + p[i].pedagog) / 3.0;
			break;
		case IF:
			cout << "оцінка з чисельних методів: "; cin >> p[i].chis_metod;
			if (p[i].chis_metod > 5) {
				p[i].chis_metod = 5;
				cout << endl;
				cout << "Оцінка розпізнана, як максимальна!" << endl;
				cout << endl;
			}
			if (p[i].chis_metod < 0) {
				p[i].chis_metod = 0;
				cout << endl;
				cout << "Оцінка розпізнана, як мінімальна!" << endl;
				cout << endl;
			}
			p[i].avarage = (p[i].mat + p[i].fiz + p[i].chis_metod) / 3.0;
			break;
		case FI:
			cout << "оцінка з педагогіки: "; cin >> p[i].pedagog;
			if (p[i].pedagog > 5) {
				p[i].pedagog = 5;
				cout << endl;
				cout << "Оцінка розпізнана, як максимальна!" << endl;
				cout << endl;
			}
			if (p[i].pedagog < 0) {
				p[i].pedagog = 0;
				cout << endl;
				cout << "Оцінка розпізнана, як мінімальна!" << endl;
				cout << endl;
			}
			p[i].avarage = (p[i].mat + p[i].fiz + p[i].pedagog) / 3.0;
			break;
		case TN:
			cout << "оцінка з педагогіки: "; cin >> p[i].pedagog;
			if (p[i].pedagog > 5) {
				p[i].pedagog = 5;
				cout << endl;
				cout << "Оцінка розпізнана, як максимальна!" << endl;
				cout << endl;
			}
			if (p[i].pedagog < 0) {
				p[i].pedagog = 0;
				cout << endl;
				cout << "Оцінка розпізнана, як мінімальна!" << endl;
				cout << endl;
			}
			p[i].avarage = (p[i].mat + p[i].fiz + p[i].pedagog) / 3.0;
			break;
		}
		cout << endl;
	}
}
void Print(Student* p, const int N)
{
	cout << "============================================================================================================"
		<< endl;
	cout << "| № | Прізвище | Курс | Cпеціальність | Фізика | Математика | Програмування | Чисельні методи | Педагогіка |"
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
void Sort(Student* p, const int N)
{
	Student tmp;
	for (int i0 = 0; i0 < N - 1; i0++) {
		for (int i1 = 0; i1 < N - i0 - 1; i1++) {
			if ((p[i1].spec > p[i1].spec)
				||
				(p[i1].spec == p[i1].spec &&
					p[i1].kurs > p[i1 + 1].kurs)
				||
				(p[i1].spec == p[i1].spec &&
					p[i1].kurs == p[i1 + 1].kurs &&
					p[i1].prizv > p[i1 + 1].prizv))
			{
				tmp = p[i1];
				p[i1] = p[i1 + 1];
				p[i1 + 1] = tmp;
			}
		}
	}
}

int* IndexSort(Student* p, const int N)
{
	int* I = new int[N];
	for (int i = 0; i < N; i++)
		I[i] = i;
	int i, j, value; 
	for (i = 1; i < N; i++)
	{
		value = I[i];
		for (j = i - 1;
			j >= 0 && ((p[I[j]].spec > p[value].spec)
				||
				(p[I[j]].spec == p[value].spec &&
					p[I[j]].kurs > p[value].kurs)
				||
				(p[I[j]].spec == p[value].spec &&
					p[I[j]].kurs == p[value].kurs &&
					p[I[j]].prizv > p[I[j]].prizv));
			j--)
		{
			I[j + 1] = I[j];
		}
		I[j + 1] = value;
	}
	return I;
}

void PrintIndexSorted(Student* p, int* I, const int N)
{
	cout << "============================================================================================================"
		<< endl;
	cout << "| № | Прізвище | Курс | Cпеціальність | Фізика | Математика | Програмування | Чисельні методи | Педагогіка |"
		<< endl;
	cout << "------------------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "|" << setw(2) << right << i + 1 << " ";
		cout << "| " << setw(9) << left << p[I[i]].prizv
			<< "| " << setw(2) << right << p[I[i]].kurs << "  "
			<< " | " << setw(14) << left << specialnistList[p[I[i]].spec]
			<< setw(4) << "| " << setw(3) << left << p[I[i]].fiz << "  "
			<< setw(6) << "| " << setw(6) << left << p[I[i]].mat << " ";
		switch (p[I[i]].spec)
		{
		case KN:
			cout << setw(8) << "| " << setw(7) << left << p[I[i]].prog << setw(19)
				<< " | " << setw(12) << left
				<< "| " << left << " |" << endl;
			break;
		case ME:
			cout << "" << setw(15) << "| " << " "
				<< "" << setw(18) << "| "
				<< setw(6) << "| " << setw(6) << left << p[I[i]].pedagog << " |" << endl;
			break;
		case IF:
			cout << "" << setw(15) << "| " << setw(9) << " |" << " "
				<< setw(8) << p[I[i]].chis_metod << " |" << " "
				<< setw(10) << "" << " |" << endl;
			break;
		case FI:
			cout << "" << setw(15) << "| " << " "
				<< "" << setw(18) << "| "
				<< setw(6) << "| " << setw(6) << left << p[I[i]].pedagog << " |" << endl;
			break;
		case TN:
			cout << "" << setw(15) << "| " << " "
				<< "" << setw(18) << "| "
				<< setw(6) << "| " << setw(6) << left << p[I[i]].pedagog << " |" << endl;
			break;
		}
	}
	cout << "============================================================================================================"
		<< endl;
	cout << endl;
}
int BinSearch(Student* p, const int N, const string prizv, const Specialnist special, const int kurs)
{ 
	int L = 0, R = N - 1, m;
	do {
		m = (L + R) / 2;
		if (p[m].prizv == prizv && p[m].spec == special && p[m].kurs == kurs)
			return m;
		if ((p[m].spec < special)
			||
			(p[m].spec == special &&
				p[m].prizv < prizv)
			||
			(p[m].spec == special &&
				p[m].prizv == prizv &&
				p[m].kurs < kurs))
		{
			L = m + 1;
		}
		else
		{
			R = m - 1;
		}
	} while (L <= R);
	return -1;
}