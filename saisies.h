#ifndef SAISIES_H_INCLUDED
#define SAISIES_H_INCLUDED

#include <string>
#include "Duree.h"

bool saisieNbNegatifsConnus();
int saisieCorrecteEntier(std::string const& question);
int saisieChoixOperation();
Duree saisieDuree(std::string const& nomDuree);


#endif // SAISIES_H_INCLUDED
