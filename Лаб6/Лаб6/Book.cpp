#include "stdafx.h"
#include "Book.h"
#include "Windows.h"
using namespace std;


void Book::setBook(const char *_fio, const char *_title, int _year, int _amount)
{
	setFio(_fio);
	setTitle(_title);
	setYear(_year);
	setAmount(_amount);
}

Book::Book(const Book &b)
{
	setBook(b.m_fio, b.m_title, b.m_year, b.m_amount);
}
Book::Book(const char *_fio, const char *_title, int _year, int _amount)
{
	setBook(_fio, _title, _year, _amount);
}

Book::~Book()
{
	delete[] m_fio;
	delete[] m_title;
}

void Book::setFio(const char *_fio)
{
	// ������ - ��� ������ ��������, � ����� ������� ����������� ������ '\0'
	// ������� strlen ���������� ���������� �������� � ������ ��� ����� '\0'
	m_fio = new char[strlen(_fio) + 1];
	// ������� strcpy �������� � ������ ������ ������ �� ������
	strcpy(m_fio, _fio);
}

void Book::setYear(int _year)
{
	m_year = _year;
}

void Book::setAmount(int _amount)
{
	m_amount = _amount;
}

void Book::setTitle(const char *_title)
{
	// ������ - ��� ������ ��������, � ����� ������� ����������� ������ '\0'
	// ������� strlen ���������� ���������� �������� � ������ ��� ����� '\0'
	m_title = new char[strlen(_title) + 1];
	// ������� strcpy �������� � ������ ������ ������ �� ������
	strcpy(m_title, _title);
}

// ������ ������ � ������������� ����������,
// ����� ���� ������������� �������� ����� ����� ����������� � �����������
void Book::scan(istream &_in)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int y, k;
	char buf1[100];
	char buf2[100];
	char buf3[100];
	cout << "������� ������� � �������� ������ � ���� ���������: ";
	_in.getline(buf1, sizeof(buf1));
	
	_in.getline(buf3, sizeof(buf3));

	cout << "������� �������� �����: ";
	_in.getline(buf2, sizeof(buf2));
	cout << "������� ��� ������� �����: ";
	_in >> y;
	cout << "������� ���������� ����������� �����: ";
	_in >> k;
	setBook(buf3, buf2, y, k);
}
void Book::print(ostream &_out) const
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	_out << " '" << m_title << "' "
		<< m_year << "�. "<<m_amount<<" ��.\n";
}
