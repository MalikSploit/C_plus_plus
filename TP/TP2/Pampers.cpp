//
// Created by root on 11/30/23.
//

#include <iostream>

class Tableau{
    int *tab;
    int taille;

public:
    Tableau():tab(nullptr), taille(10)
    {
        tab = new int[taille];
    }

    ~Tableau()
    {
        delete [] tab;
    }

    void InitTab()
    {
        for (int i = 0; i < taille; i++)
        {
            tab[i] = 0;
        }
    }

    void afficher()
    {
        for (int i = 0; i < taille; i++)
        {
            std::cout << tab[i] << " ";
        }
    }
};

int main()
{
    Tableau t;
    t.InitTab();
    t.afficher();
    return 0;
}