#ifndef DUREE_H_INCLUDED
#define DUREE_H_INCLUDED


#include <string>

class Duree
{
    public:
        Duree(int heures=0, int minutes=0, int secondes=0);
        void afficher() const;
        bool estEgalA(Duree const& b) const;
        bool estStrictPlusPetitQue(Duree const& b) const;
        Duree& operator+=(Duree const& a);
        Duree& operator-=(Duree const& a);
        bool operator==(Duree const& b) const;
        bool operator!=(Duree const& b) const;
        bool operator<(Duree const& b) const;
        bool operator<=(Duree const& b) const;
        bool operator>(Duree const& b) const;
        bool operator>=(Duree const& b) const;

    private:
        int m_heures;
        int m_minutes;
        int m_secondes;
};



Duree operator+(Duree const& a, Duree const& b);
Duree operator-(Duree const& a, Duree const& b);


#endif // DUREE_H_INCLUDED
