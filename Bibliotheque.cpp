#include "Bibliotheque.h"

int Bibliotheque::nbBibliotheques = 0;

Bibliotheque::Bibliotheque()
{
	this->nom = "";
    this->capacite = 0;
    this->nbLivres = 0;
    this->livres = nullptr;

    nbBibliotheques++;
	cout << "Constructeur par defaut de la classe Bibliotheque" << endl;
	
}

Bibliotheque::Bibliotheque(string nom, int capacite)
{
	this->nom = nom;
    this->capacite = capacite;
    this->nbLivres = 0;

    this->livres = new Livre*[capacite];

    nbBibliotheques++;
}
//le tableau livres contient des pointeurs vers des objets de type Livre.
//c pour cela on passe un pointeur vers un objet Livre en parametre de la fonction ajouterLivre
Livre& Bibliotheque::ajouterLivre(Livre* livre)
{

	if (this->nbLivres >= this->capacite) {
		cerr << "la bibliotheque est pleine";
		return *livres[0];

}
	else {
		// nbLivres représente le nombre de livres déjà ajoutés, 
		// mais comme les indices commencent à 0, 
		// cette valeur correspond aussi à l'indice de la prochaine case libre.
		livres[nbLivres] = new Livre(titre, auteur, parution);
		nbLivres++;
	}
	return *livre[nbLivres - 1];
}

Livre* Bibliotheque::rechercherLivre(string titre)
{
	for(int i=0;i<this->nbLivres;i++)
	{
		if(this->livres[i]->getTitre() == titre)
		{
			return this->livres[i];
		}
	}
	return nullptr;
}
Livre* Bibliotheque::rechercherLivre(int id)
{
	for (int i = 0; i < this->nbLivres; i++)
	{
		if (this->livres[i]->getId() == id)
		{
			return this->livres[i];
		}
	}

	return nullptr;
}
Bibliotheque::~Bibliotheque()
{
	 for (int i = 0; i < nbLivres; i++) {
        delete livres[i];
    }
	delete[] livres;

	nbBibliotheques--;

	cout << "Destruction de la bibliotheque" << endl;
}



