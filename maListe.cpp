#include <iostream>
#include "liste.h"
#include "unittest.h"

// It is not possible to set a struct with NULL
//as it is declared.

// If you want to assign NULL to a struct,
//you must declare it as a pointer

using namespace std;

int main()
{

    // TP 11

    point p = {0, 0};
    point p2 = {1, 1};
    point p3 = {0, 1};
    point p4 = {-1, 1};

    // initialisation des cellules
    cellule* c_l = NouvCel(p);
    cellule* c_l2 = NouvCel(p2);
    cellule* c_l3 = NouvCel(p3);
    cellule* c_l4 = NouvCel(p4);
    cellule* c_n = NULL;


    InsererCellule(1, c_l2, c_l);
    InsererCellule(2, c_l3, c_l);

    assertEquals(c_l->next, c_l2, "Inserer Cellule c_l2");
    assertEquals(c_l2->next, c_l3, "InsererCellule c_l3");

    //SupprimeCellule(1, c_l);
    //assertEquals(c_l->next, c_l3, "SupprimerCellule c_l3");

    printf("%s", Afficher(c_l));


    // TP12

    Noeud* b = nouvNoeud('b');
    Noeud* o = nouvNoeud('o');
    Noeud* n = nouvNoeud('n');
    Noeud* j = nouvNoeud('j');
    Noeud* o2 = nouvNoeud('o');
    Noeud* u = nouvNoeud('u');
    Noeud* r = nouvNoeud('r');


    insererFG(o, b, 1);
    insererFG(n, b, 2);
    insererFG(j, b, 3);
    insererFD(o2, b, 1);
    insererFG(u, b, 5);
    insererFG(r, b, 6);

    parcoursPrefixe(b);


    return 0;
}
