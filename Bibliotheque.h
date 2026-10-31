#pragma once
#include"Livre.h"
#include <iostream>
using namespace std;
class Bibliotheque
{
private:
	string nom;
	int capacite;
	int nbLivres;
	Livre** livres;
	static int nbBibliotheques;
public:
	Bibliotheque();
	Bibliotheque(string nom, int capacite);

	Livre& ajouterLivre(Livre* livre);

	Livre* rechercherLivre(string titre);
	Livre* rechercherLivre(int id);

	~Bibliotheque();

};

