#ifndef GRADEBOOK_Н 
#define GRADEBOOK_Н 

#include <iostream>
#include <windows.h>
#include "Function.h"
#include "Error.h"
#include "Book.h" 
#include <map>
#include <string>
#define size1 255 

using  namespace  std;
/* клас Службовець */

class Gradebook : public Book
{
protected:
	map<string, int> RatingsOfSubjects;
	int  m_Kurs, m_number;
public:
	Gradebook();
	Gradebook(int, char *, char *, char *, int, int, int);
	Gradebook(Gradebook &);
	virtual ~Gradebook();

	int GetUDK();
	void SetUDK(int);

	void setKurs(int);
	int getKurs();
	int GetRatingsOfIndex(int index);
	string GetSubjectsOfIndex(int index);
	int GetRatingsOfSubject(string);
	int GetRatingsCount();
	void AddRatingsOfSubject(string, int);
	int SerBal();
	int GetMinRating();
	friend ostream& operator<<	(ostream &output, Gradebook&);
	friend istream& operator>> (istream &input, Gradebook&);
	virtual void Output() { cout << "Номер:" << m_number << endl; }
};
#endif 

