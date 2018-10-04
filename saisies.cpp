#include "saisies.h"

#include <iostream>
#include <limits> //numeric_limits<streamsize>::max()
#include <stdlib.h> //atoi

using namespace std;

/*bool saisieNbNegatifsConnus()
demande à l'utilisateur s'il connapit les nombres relatifs
retourne : true si oui, false sinon
*/
bool saisieNbNegatifsConnus()
{
    bool saisieCorrecte(false), nbNegatifsConnus (false);

    do
    {
        string reponse;
        cout << endl << "Connaissez-vous les nombres negatifs (o/n) ? ";
        cin >> reponse;

        if(cin.eof() || cin.bad()) //erreur interne au flux
        {
            cout << "Erreur interne..." << endl << endl;
            cin.clear();
        }
        else if (cin.fail()) //saisie incorrecte
        {
            cout << "Erreur de saisie..." << endl << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        else if (reponse=="o" || reponse=="O") //réponse "oui"
        {
            saisieCorrecte = true;
            nbNegatifsConnus = true;
        }
        else if (reponse=="n" || reponse=="N") // réponse "non"
        {
            saisieCorrecte = true;
            nbNegatifsConnus = false;
        }
        else //autre frappe
        {
            saisieCorrecte = false;
        }

    }while(!saisieCorrecte);


    return nbNegatifsConnus;
}

/*int saisieCorrecteEntier(string question)
contrôle la saisie d'un entier (int) par l'utilisateur
renvoie : l'entier saisi après validation
*/
int saisieCorrecteEntier(string const& question)
{
    string reponse;
    int entierSaisi;
    bool saisieCorrecte(false);

    do
    {
        cout << question;
        cin >> reponse;

        if(cin.eof() || cin.bad()) //erreur interne au flux
        {
            cout << "Erreur interne..." << endl << endl;
            cin.clear();
        }
        else if (cin.fail()) //saisie incorrecte
        {
            cout << "Erreur de saisie..." << endl << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        else
        {
            unsigned int i(0);
            bool bonChiffre(true);

            while(i<reponse.size() && bonChiffre)
            {
                if (reponse[i]>='0' && reponse[i]<='9')
                {
                    bonChiffre = true;
                }
                else
                {
                    bonChiffre = false;
                }
                i++;
            }

            if (bonChiffre)
            {
                saisieCorrecte = true;
                entierSaisi = atoi(reponse.c_str());
            }
            else
            {
                saisieCorrecte = false;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }
        }
    }while(!saisieCorrecte);

    return entierSaisi;
}

/*int saisieChoixOperation()
demande à l'utilisateur l'opération souhaitée
appelle la fonction saisieCorrecteEntier(string question)
renvoie : un entier (numéro de l'opération)
*/
int saisieChoixOperation()
{
    int choixOperation(0), nbOperations(3);
    string question("Choisissez l'action :\n \t 1. Ecriture correcte\n \t 2. Addition\n \t 3. Soustraction\n");

    do
    {
        choixOperation = saisieCorrecteEntier(question);
    }while(choixOperation<1 || choixOperation>nbOperations);

    return choixOperation;
}

/*

*/
Duree saisieDuree(std::string const& nomDuree)
{
    string question("\t ");

    //heure
    cout << endl << nomDuree << endl;
    question += "heures (sans virgule) : ";
    int heures = saisieCorrecteEntier(question);

    //minutes
    question = "\t minutes (sans virgule) : ";
    int minutes = saisieCorrecteEntier(question);

    //secondes
    question = "\t secondes (sans virgule) : ";
    int secondes = saisieCorrecteEntier(question);

    return Duree(heures, minutes, secondes);
}
