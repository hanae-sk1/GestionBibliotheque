#pragma once
class Date
{
private:

	int jour;
	int mois;
	int annee;


public:

	Date();
	Date(int j, int m , int a );

	static bool estBissextile(int a);
	static bool estValide(int j, int m, int a);

	bool operator==(const Date& d) const;
	bool operator<(const Date& d) const;

	void afficherDate() const;

};

