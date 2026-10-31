#include "Date.h"
#include <iostream>
using namespace std;

Date::Date()
{
	this->jour = 1;
	this->mois = 1;
	this->annee = 2000;
}

Date::Date(int j, int m, int a)
{
	if (!estValide(jour,mois,annee )){
		cerr<<"la date passee est invalide"<<endl;
		this->jour = 1;
		this->mois = 1;
		this->annee = 2000;


	}
	else  {
		this->jour=j;
		this->annee=a;
		this->mois=m;
	}
}

bool Date::estBissextile(int a)
{
	if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0) {

	return true;

	}
	return false;
}

bool Date::estValide(int j, int m, int a)
{
	if (j < 1 || m < 1 || a < 1 || m>12) 
		return false;
	if ((m == 4 || m == 6 || m == 9 || m == 11) && j > 30) {
		j = 1;m = 1;a = 2000;
		return false;
	}
	if (m == 2) {
		if (estBissextile(a)&&j>29) {
			return false;
		}
		else if (estBissextile(a) == false && j > 28) {
			return false;
	}

	}
	return true;
}

bool Date::operator==(const Date& d) const
{
	return (this->jour==d.jour && this->mois==d.mois && this->annee==d.annee);
}

bool Date::operator<(const Date& d) const
{
	if (this->annee < d.annee) {
		return true;
	}
	else if (this->annee == d.annee && this->mois < d.mois) {
		return true;
	}
	else if (this->annee == d.annee && this->mois == d.mois && this->jour < d.jour) {
		return true;
	}
	else {
		return false;
	}
}

void Date::afficherDate() const
{
	cout << this->jour << "/" << this->mois << "/" << this->annee << endl;
}
