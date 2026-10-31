// GestionBibliotheque.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Date.h"
#include "Livre.h"
#include "Bibliotheque.h"

using namespace std;

int main()
{
    Date d1(10, 5, 2024);
    Date d2(15, 8, 2005);

    Livre l1("random1", "Jack", d1);
    Livre l2("random2", "Lily", d2);

    l1.noterLivre(14);
    l1.noterLivre(12);
    l1.noterLivre(17);
    l2.noterLivre(18);
    l2.noterLivre(11);

    Bibliotheque b("Bibliotheque FSTM", 5);

	b.ajouterLivre(&l1);
	b.ajouterLivre(&l2);

	//recherche par titre

	Livre* livreRecherche = b.rechercherLivre("random1");
	if (livreRecherche != nullptr)
	{
		cout << "Livre trouve : " << endl;
		livreRecherche->afficherLivre();
	}
	else
	{
		cout << "Livre non trouve" << endl;
	}
	return 0;

	//recherche par id

    Livre* resultat2 = b.rechercherLivre(1);

    if (resultat2 != nullptr)
    {
        resultat2->afficherLivre();
    }
    else
    {
        cout << "Livre introuvable" << endl;
    }

    cout << endl;

    l1.afficherLivre();
	l2.afficherLivre();

    return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
