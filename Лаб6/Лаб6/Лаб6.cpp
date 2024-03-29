// Лаб6.cpp: определяет точку входа для консольного приложения.
/*Вариант 6 Написать программу учета книг в библиотеке. 
Сведения о книгах содержат: фамилию и инициалы автора, название, год издания, 
количество экземпляров данной книги в библиотеке. Программа должна обеспечивать выбор с помощью меню 
и выполнение одной из следующих функций: 
• добавление данных о книгах, вновь поступающих в библиотеку; 
• удаление данных о списываемых книгах; 
• выдача сведений о всех книгах, упорядоченных по фамилиям авторов; 
• выдача сведений о всех книгах, упорядоченных по годам издания. 
Хранение данных организовать с применением контейнерного класса multimap, 
в качестве ключа использовать «фамилию и инициалы автора».*/

#include <iostream>
#include "stdafx.h"
#include "Book.h"
#include "Windows.h"
#include <fstream>
#include <iterator>
#include <string>
#include <map>


int main()
{
	multimap<string, Book> library;//контейнер класса multimap для хранения данных, содержит пары ключ-значение
	bool work = 1;
	int choice = 0;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (work)
	{
		cout << "Что вы хотите сделать?" << endl;
		cout << "1. Добавить данные о книге." << endl;
		cout << "2. Удалить данные о книге." << endl;
		cout << "3. Вывести список книг, упорядоченный по авторам." << endl;
		cout << "4. Вывести список книг, упорядоченный по году издания." << endl;
		cout << "0. Выйти" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			Book b1;
			b1.scan(cin);//ввод данных о книге
			pair<string, Book> myPair(b1.getFio(), b1);//создание пары "ключ-значение", где ключ - ФИО автора, значение - данные о книге
			library.insert(myPair);//добавление пары в контейнер					
			cout << "Данные о книге добавлены!" << endl;
			break;
		}
		case 2:
		{
			if (library.size() == 0)
			{
				cout << "Удаление из пустой библиотеки невозможно!" << endl;
				break;
			}
			else
			{
				int pos = 0;
				int kol = 0;
				multimap <string, Book> ::iterator Iter;//создаем переменную-итератор, которая "пробегает" по всем членам контейнера
				
				cout << "Книгу под каким номером хотите списать?" << endl;
				for (Iter = library.begin(); Iter != library.end(); Iter++)
				{
					kol++;
					cout <<kol<< ". " <<Iter->first << " " << Iter->second.getTitle() << endl; "\n";
				}//first - ключ элемента, ФИО автора, second - значение элемента, данные о книге
				cin >> pos;
				if (pos > kol || pos < 1) cout << "Такого номера нет!";
				else
				{
					int kol2 = 0;
					for (Iter = library.begin(); Iter != library.end(); Iter++)
					{
						kol2++;//пробегаем по всем элементам контейнера, пока не доходим до нужного
						if (kol2 == pos)
						{
							library.erase(Iter);//удаляем его
							cout << "Информация о книге удалена." << endl;
							break;
						}
					}		
				}					
				break;
			}
		}
		case 3:
		{
			int kol = 0;
			multimap <string, Book> ::iterator Iter;
			//контейнер multimap по умолчанию упорядочен по ключам, поэтому
			//ничего делать не нужно, просто вывести его

			cout << "Список книг, упорядоченный по авторам" << endl;
			for (Iter = library.begin(); Iter != library.end(); Iter++)
			{
				kol++;
				cout << kol << ". " << Iter->first;
				Iter->second.print(cout);
			}
			break;
		}
		case 4:
		{
			multimap<int, Book> m;//отсортировать контейнер multimap по значению сложно, если вообще
			//возможно, да и смысл, поэтому создадим новый и сделаем там ключом год издания
			multimap <string, Book> ::iterator Iter1;//итератор для пробега по первому контейнеру
			multimap <int, Book> ::iterator Iter2;//итератор для пробега по новому контейнеру
			int kol = 0;
			for (Iter1 = library.begin(); Iter1 != library.end(); Iter1++)
			{
				pair<int, Book> myPair(Iter1->second.getYear(), Iter1->second);
				m.insert(myPair);
			}//перебираем все эл-ты 1го контейнера, формируем из них новые пары, где ключ - год издания,
			//а значение - информация о книге, и кладём эти новые пары во 2й контейнер

			cout << "Список книг, упорядоченный по году издания :" << endl;
			for (Iter2 = m.begin(); Iter2 != m.end(); Iter2++)
			{
				kol++;
				cout << kol << ". ";
				Iter2->second.print(cout);
				cout<< Iter2->first<<endl;
			}
			break;
		}
		case 0:
		{
			work = 0;
			break;
		}
		default:
		{
			cout << "Такого пункта в меню нет!" << endl;
			break;
		}
		}
	}
	
    return 0;
}

