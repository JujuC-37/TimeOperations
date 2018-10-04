#include <iostream>
#include "Duree.h"
#include "saisies.h"
#include "operations.h"


using namespace std;

int main()
{
    cout << "<--------------------------- Calculatrice de duree --------------------------->" << endl << endl;

    Duree duree2(1,1,1), duree1(1,1,1);

    //choix operation
    int choixOperation;
    choixOperation = saisieChoixOperation();

    //action selon le choix de l'operation
    switch (choixOperation)
    {
        case 1: duree1 = saisieDuree("Duree 1 :");
                ecritureCorrecte(duree1);
                break;

        case 2: duree1 = saisieDuree("Duree 1 :");
                duree2 = saisieDuree("Duree 2 :");
                addition(duree1, duree2);
                break;

        case 3: duree1 = saisieDuree("Duree 1 :");
                duree2 = saisieDuree("Duree 2 :");
                soustraction(duree1, duree2);
                break;
    }

    cout << "<---------------------------------------------------------------------------->"<< endl;
    cout << "                           Taper sur une touche pour arreter" << endl;
    cout << "<---------------------------------------------------------------------------->"<< endl;

    return 0;
}
