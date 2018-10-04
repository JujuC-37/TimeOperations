#include "operations.h"
#include "saisies.h"

#include <iostream>

using namespace std;

/*void ecritureCorrecte(Duree const& duree1)
affiche la duree avec des minutes et secondes entre 0 et 59
appelle la m�thode afficher() de la classe Duree
*/
void ecritureCorrecte(Duree const& duree1)
{
    duree1.afficher();
}

/*void addition(Duree const& duree1, Duree const& duree2)
additionne les deux dur�es donn�es en param�tres
appelle le m�thode afficher() et l'op�rateur + de la classe Duree
*/
void addition(Duree const& duree1, Duree const& duree2)
{
    Duree duree3;

    cout << endl << "  ";
    duree1.afficher();
    cout << "+ " ;
    duree2.afficher();

    duree3 = duree1 + duree2;
    cout << "--------------" <<endl;
    cout << "  ";
    duree3.afficher();
}

/*void soustraction(Duree const& duree1, Duree const& duree2)
calcule la diff�rence duree1 - duree2 en s�parant les cas o� duree1>=duree2 et o� duree1<duree2
demande � l'utilisateur s'il conna�t les nombres n�gatifs (appelle la fonction saisieNbNegatifsConnus()) et r�agit selon le cas
*/
void soustraction(Duree const& duree1, Duree const& duree2)
{
    bool nbNegatifsConnus(false);
    Duree duree3(0,0,0);

    if (duree1<duree2)
    {
        nbNegatifsConnus = saisieNbNegatifsConnus();
    }

    if (!nbNegatifsConnus && duree1<duree2)
    {
        cout << "Resultat negatif : la premiere valeur est plus grande que la seconde..." << endl << endl;
    }
    else
    {
        cout << "  ";
        duree1.afficher();
        cout << "- " ;
        duree2.afficher();

        duree3 = duree1 - duree2;
        cout << "--------------" <<endl;

        if (duree1>=duree2)
        {
            cout << "  ";
        }
        else
        {
            cout << " -";
        }

        duree3.afficher();
    }

}
