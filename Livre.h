#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

class Livre
{
private:
    const int id;
    static int compteurid;

    string auteur;
    string titre;

    static int nbInstances;

    bool Disponible;

    double* notes;
    int nbnotes;

    Date parution;

public:

    Livre(string titre, string auteur, Date parution);

    Livre(const Livre& l);

    int getId() const;
    string getTitre() const;


    void noterLivre(double note);

    double moyenneNotes() const;

    void afficherLivre() const;

    Livre& operator=(const Livre& l);

    ~Livre();
};


