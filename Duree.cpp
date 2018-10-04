#include "Duree.h"

#include "saisies.h"
#include <iostream>
#include <cstdlib> //abs()

using namespace std;

/*Duree::Duree(int heures, int minutes, int secondes)
constructeur (mets les valeurs des min et s entre 0 et 59)
*/
Duree::Duree(int heures, int minutes, int secondes)
{
    m_heures = heures;
    m_minutes = minutes;
    m_secondes = secondes;

    //mettre des valeurs entre 0 et 59 pour les minutes et secondes
    m_minutes += m_secondes/60;
    m_secondes = m_secondes%60;

    m_heures += m_minutes/60;
    m_minutes = m_minutes%60;
}

/*void Duree::afficher() const
affiche la duree en indiquant les unit�s
*/
void Duree::afficher() const
{
    cout << m_heures << "h " << m_minutes << "min " << m_secondes << "s" << endl;
}

/*bool Duree::estEgalA(Duree const& b) const
compare une duree donn�e en param�tre � celle qui appelle la m�thode
retourne : true si les dur�es sont �gales et false sinon
*/
bool Duree::estEgalA(Duree const& b) const
{
    if (m_heures==b.m_heures && m_minutes==b.m_minutes && m_secondes==b.m_secondes)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*bool estStrictPlusPetitQue(Duree const& b) const
compare la duree pass�e en param�tre et celle qui appelle la methode en commen�ant par les h, puis min puis s
retourne : false si b est plus grand et true sinon
*/
bool Duree::estStrictPlusPetitQue(Duree const& b) const
{
    if (m_heures<b.m_heures)
    {
        return true;
    }
    else if (m_heures==b.m_heures && m_minutes<b.m_minutes)
    {
        return true;
    }
    else if (m_heures==b.m_heures && m_minutes==b.m_minutes && m_secondes<b.m_secondes)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*void Duree::operator+=(Duree const& a)
ajoute � la durr�e appelant la m�thode la dur�e pass�e en param�tre
*/
Duree& Duree::operator+=(Duree const& a)
{
    //addition
    m_secondes += a.m_secondes;
    m_minutes += a.m_minutes;
    m_heures += a.m_heures;

    //mettre des valeurs entre 0 et 59 pour les minutes et secondes
    m_minutes += m_secondes/60;
    m_secondes = m_secondes%60;

    m_heures += m_minutes/60;
    m_minutes = m_minutes%60;

    return *this;

}

/*Duree& Duree::operator-=(Duree const& a)
d�finit l'op�rateur -= qui soustrait la duree a � la duree qui appelle la m�thode
s�pare les cas : diff�rence positive et diff�rence n�gative
renvoie : la diff�rence avec minutes et secondes entre 0 et 59
*/
Duree& Duree::operator-=(Duree const& a)
{
    if (*this >= a) //diff�rence positive ou nulle
    {
       //soustraction
        m_secondes -= a.m_secondes;
        m_minutes -= a.m_minutes;
        m_heures -= a.m_heures;

        //mettre des vakeurs entre 0 et 59 pour les minutes et secondes
        if (m_secondes<0)
        {
            m_secondes += 60;
            m_minutes--;
        }

        if (m_minutes<0)
        {
            m_minutes += 60;
            m_heures--;
        }

        m_minutes += m_secondes/60;
        m_secondes = m_secondes%60;

        m_heures += m_minutes/60;
        m_minutes = m_minutes%60;
    }
    else //diff�rence n�gative
    {
        m_secondes = a.m_secondes - m_secondes;
        m_minutes = a.m_minutes - m_minutes;
        m_heures = a.m_heures - m_heures;

        //mettre des vakeurs entre 0 et 59 pour les minutes et secondes
        if (m_secondes<0)
        {
            m_secondes += 60;
            m_minutes--;
        }

        if (m_minutes<0)
        {
            m_minutes += 60;
            m_heures--;
        }

        m_minutes += m_secondes/60;
        m_secondes = m_secondes%60;

        m_heures += m_minutes/60;
        m_minutes = m_minutes%60;
    }

    return *this;
}

/*bool operator==(Duree const& a, Duree const& b)
op�rateur comparant deux dur�es, qui utilise la m�thode estEgalA
retourne : true si les deux dur�es sont �gales et false sinon
*/
bool Duree::operator==(Duree const& b) const
{
    return this->estEgalA(b);
}

/*bool operator!=(Duree const& a, Duree const& b)
op�rateur comparant deux durees, qui utilise l'op�rateur ==
retourne : true si les deux durees sont differentes et false sinon
*/
bool Duree::operator!=(Duree const& b) const
{
    return !(*this==b);
}

/*bool operator<(Duree const& a, Duree const& b)
op�rateur comparant deux durees, qui utilise la methode estStrictPlusPetitQue
retourne : true si a<b et false sinon
*/
bool Duree::operator<(Duree const& b) const
{
    return this->estStrictPlusPetitQue(b);
}

/*bool operator<=(Duree const& a, Duree const& b)
operateur comparant deux durees qui utilise les op�ratuer < et ==
retourne :true si a<=b et false sinon (a>b)
*/
bool Duree::operator<=(Duree const& b) const
{
    return (*this<b || *this==b);
}

/*bool operator>(Duree const& a, Duree const& b)
operateur comparant deux durees qui utilise l'operateur <=
retourne : true si a>b et false sinon (a<=b)
*/
bool Duree::operator>(Duree const& b) const
{
    return !(*this<=b);
}

/*bool operator>=(Duree const& a, Duree const& b)
operateur comparant deux durees qui utilise l'operateur <
retourne : true si a>=b et false sinon (a<b)
*/
bool Duree::operator>=(Duree const& b) const
{
    return !(*this<b);
}

/*Duree operator+(Duree const& a, Duree const& b)
operateur additionnaant 2 dur�es qui utilise la m�thode/op�rateur +=
retourne la somme
*/
Duree operator+(Duree const& a, Duree const& b)
{
    Duree copie(a);
    copie += b;
    return copie;
}

/*Duree operator-(Duree const& a, Duree const& b)
operateur retirant la 2�me dur�e de la 1�re, qui utilise la m�thode/op�rateur -=
retourne la diff�rence
*/
Duree operator-(Duree const& a, Duree const& b)
{
    Duree copie(a);
    copie -= b;
    return copie;
}
