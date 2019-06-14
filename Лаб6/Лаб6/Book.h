#pragma once
#ifndef BOOK_H
#define BOOK_H
#include <cstring>
#include <iostream>
using namespace std;

class Book
{
	char* m_fio;//ФамилияИО автора
	char* m_title; //название
	int m_year; //год издания
	int m_amount; //кол-во экземпляров данной книги в библиотеке
public:
	//Конструкторы
	Book() : m_fio(0), m_title(0), m_year(0), m_amount(0) {}
	Book(const char *_fio, const char *_title, int _year, int _amount);
	Book(const Book &_b);

	//Декструктор
	~Book();

	//Методы для присваивания значений полям класса
	void setFio(const char *_fio);
	void setYear(int _year);
	void setAmount(int _amount);
	void setTitle(const char *_title);
	void setBook(const char *_fio, const char *_title, int _year, int _amount);

	//Перегрузка операций извлечения и вставки (ввод-вывод)
	void scan(istream &_in);
	void print(ostream &_out) const;

	//Методы для доступа к значениям полей класса
	char* getFio() const { return m_fio; };
	int getYear() const { return m_year; };
	int getAmount() const { return m_amount; };
	char* getTitle() const { return m_title; };


};
#endif
