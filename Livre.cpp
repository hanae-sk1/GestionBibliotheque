
#include "Livre.h"

int Livre::nbInstances = 0;
int Livre::compteurid = 0;

Livre::Livre(string titre, string auteur, Date parution) : id(compteurid++), auteur(auteur),titre(titre),Disponible(true),notes(nullptr),nbnotes(0),parution(parution)
{
    nbInstances++;
}


Livre::Livre(const Livre& l): id(compteurid++){

	this->titre = l.titre;
	this->auteur = l.auteur;
	this->Disponible = l.Disponible;
	this->nbnotes = l.nbnotes;
	this->parution = l.parution;

    if (this->nbnotes > 0)
    {
        notes = new double[this->nbnotes];

        for (int i = 0; i < this->nbnotes; i++)
        {
            this->notes[i] = l.notes[i];
        }
    }
    else
    {
        this->notes = nullptr;
    }

    nbInstances++;
}
int Livre::getId() const
{ 
    return this->id;
}


string Livre::getTitre() const
{
    return this->titre;
}
    

void Livre::noterLivre(double note)
{
    if (note < 0 || note > 20)
    {
        cerr << "La note est invalide" << endl;
    }
    else
    {
        double* nouveau = new double[this->nbnotes + 1];

        for (int i = 0; i < this->nbnotes; i++)
        {
            nouveau[i] = this->notes[i];
        }

        nouveau[this->nbnotes] = note;

        delete[] notes;

        notes = nouveau;

        this->nbnotes++;
    }
}


double Livre::moyenneNotes() const
{
    if (this->nbnotes == 0)
    {
        return 0;
    }

    double somme = 0;

    for (int i = 0; i < this->nbnotes; i++)
    {
        somme += this->notes[i];
    }

    return somme / this->nbnotes;
}


void Livre::afficherLivre() const
{
    cout << "Affichage du livre :" << endl;

    cout << "ID : " << id << endl;
    cout << "Titre : " << titre << endl;
    cout << "Auteur : " << auteur << endl;

    cout << "Date de parution :";
    parution.afficherDate();

    cout << "Disponible : "
        << (this->Disponible ? "Oui" : "Non") << endl;

    cout << "Nombre d'instances : " << this->nbInstances << endl;
    cout << "Nombre de notes : " << this->nbnotes << endl;

    if (this->nbnotes == 0)
    {
        cout << "Aucune note enregistree" << endl;
    }
    else
    {
        cout << "Moyenne : " << this->moyenneNotes() << endl;
    }
}

Livre& Livre::operator=(const Livre& l)
{
    if (this == &l)
    {
        return *this;
    }

    double* nouveau = nullptr;

    if (l.nbnotes > 0)
    {
        nouveau = new double[l.nbnotes];

        for (int i = 0; i < l.nbnotes; i++)
        {
            nouveau[i] = l.notes[i];
        }
    }

    delete[] notes;

    notes = nouveau;

    this->titre = l.titre;
    this->auteur = l.auteur;
    this->parution = l.parution;
    this->Disponible = l.Disponible;
    this->nbnotes = l.nbnotes;

    return *this;
}

Livre::~Livre()
{
    delete[] notes;

    nbInstances--;

	cout << "Destruction du livre" << endl;
}
