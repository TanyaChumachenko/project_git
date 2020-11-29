#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1
#include <string>
#include <iostream>
using namespace std;
class Book
{
protected:
	char *m_avtor;
	char *m_title;
	char *m_edition;
	int m_year, m_UDK;
public:
	Book();
	Book(Book& ob);
	Book(int, char *, char *, char *, int);
	~Book();
	virtual  int GetUDK();
	void SetUDK(int);
	char * Getavtor();
	void Setavtor(char *);
	char * Gettitle();
	void Settitle(char *);
	char * Getedition();
	void Setedition(char *);
	int Getyear();
	void Setyear(int);
	Book operator()(int, char *, char *, char *, int);
	Book& operator= (Book&);
	friend ostream &operator<<(ostream&, Book&);
	friend istream &operator>>(istream&, Book&);
	virtual void Output() { cout << "ÓÄÊ:" << m_UDK << endl; }
};
