#define _CRT_SECURE_NO_WARNINGS 
#include "StdAfx.h"
#include "Book.h"
#include <iostream>
#include <windows.h>
//#include "Error.h"
#include "Function.h"

#define size1 255

Book::Book() :m_UDK(0), m_avtor(NULL), m_title(NULL), m_edition(NULL), m_year(0)
{

}
Book::~Book() {}
Book::Book(Book &ob)
{
	m_UDK = ob.m_UDK;
	m_avtor = new char[strlen(ob.m_avtor) + 1];
	strcpy(m_avtor, ob.m_avtor);
	m_title = new char[strlen(ob.m_title) + 1];
	strcpy(m_title, ob.m_title);
	m_edition = new char[strlen(ob.m_edition) + 1];
	strcpy(m_edition, ob.m_edition);
	m_year = ob.m_year;
}

Book::Book(int UDK, char * avtor, char * title, char * edition, int year)
{
	m_UDK = UDK;;
	m_avtor = new char[strlen(avtor) + 1];
	m_title = new char[strlen(title) + 1];
	m_edition = new char[strlen(edition) + 1];
	m_year = year;
}


/* Get methods */
int Book::GetUDK()
{
	return m_UDK;
}

char * Book::Getavtor()
{
	return m_avtor;
}
char *  Book::Gettitle()
{
	return m_title;
}

char *  Book::Getedition()
{
	return m_edition;

}
int Book::Getyear()
{
	return m_year;
}

/* Set methods */
void Book::SetUDK(int UDK)
{
	m_UDK = UDK;

}

void Book::Setyear(int year)
{
	m_year = year;
}

void Book::Setavtor(char *  avtor)
{
	m_avtor = new char[strlen(avtor) + 1];
	strcpy(m_avtor, avtor);
}
void Book::Settitle(char *  title)
{
	m_title = new char[strlen(title) + 1];
	strcpy(m_title, title);
}
void Book::Setedition(char *  edition)
{
	m_edition = new char[strlen(edition) + 1];
	strcpy(m_edition, edition);
}


Book Book:: operator()(int UDK, char *  avtor, char *  title, char *  edition, int year)
{
	SetUDK(UDK);
	Setyear(year);
	m_avtor = new char[strlen(avtor) + 1];
	strcpy(m_avtor, avtor);
	m_title = new char[strlen(title) + 1];
	strcpy(m_title, title);
	m_edition = new char[strlen(edition) + 1];
	strcpy(m_edition, edition);
	return *this;
}

Book& Book::operator = (Book &book)
{
	// копіювання
	m_avtor = new char[strlen(book.m_avtor) + 1];
	strcpy(m_avtor, book.m_avtor);
	m_UDK = book.m_UDK;
	m_title = new char[strlen(book.m_title) + 1];
	strcpy(m_title, book.m_title);
	m_edition = new char[strlen(book.m_edition) + 1];
	strcpy(m_edition, book.m_edition);
	m_year = book.m_year;
	return *this;
}

ostream &operator<<(ostream &output, Book& c)
{
	output << "============================================" << endl;

	output << "Інформацiя про КНИГУ" << endl;
	output << "УДК: " << c.GetUDK() << endl;
	output << "Назва книги: " << c.Gettitle() << endl;
	output << "Автор: " << c.Getavtor() << endl;
	output << "Видавництво: " << c.Getedition() << endl;
	output << "Рік видання: " << c.Getyear() << endl;
	return output;
}

istream &operator>>(istream &input, Book& c)
{

	SetConsoleOutputCP(1251);
	cout << "Будь-ласка, ввдеіть інформацію про КНИГУ" << endl;
	char buffer[size1];
	//try
	//{
		cout << "УДК: ";
		c.SetUDK(GetInt(input));
		cout << "Назва: ";
		input.getline(buffer, size1, '\n');
		c.Settitle(buffer);
		cout << "Автор: ";
		input.getline(buffer, size1, '\n');
		c.Setavtor(buffer);
		cout << "Видавництво: ";
		input.getline(buffer, size1, '\n');
		c.Setedition(buffer);
		cout << "Рiк: ";
		c.Setyear(GetInt(input));
		input.clear();
	//}
	//catch (Error ex)
	//{
	//	cout << ex.what() << endl;
	//}
	return input;
}