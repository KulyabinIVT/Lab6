#pragma once
#ifndef BOOK_H
#define BOOK_H
#include <cstring>
#include <iostream>
using namespace std;

class Book
{
	char* m_fio;//��������� ������
	char* m_title; //��������
	int m_year; //��� �������
	int m_amount; //���-�� ����������� ������ ����� � ����������
public:
	//������������
	Book() : m_fio(0), m_title(0), m_year(0), m_amount(0) {}
	Book(const char *_fio, const char *_title, int _year, int _amount);
	Book(const Book &_b);

	//�����������
	~Book();

	//������ ��� ������������ �������� ����� ������
	void setFio(const char *_fio);
	void setYear(int _year);
	void setAmount(int _amount);
	void setTitle(const char *_title);
	void setBook(const char *_fio, const char *_title, int _year, int _amount);

	//���������� �������� ���������� � ������� (����-�����)
	void scan(istream &_in);
	void print(ostream &_out) const;

	//������ ��� ������� � ��������� ����� ������
	char* getFio() const { return m_fio; };
	int getYear() const { return m_year; };
	int getAmount() const { return m_amount; };
	char* getTitle() const { return m_title; };


};
#endif
