#ifndef LISTE_H_INCLUDED
#define LISTE_H_INCLUDED

// TP11

typedef struct point
{
    int x;
    int y;
} point;

typedef struct cellule
{
    cellule* prev;
    point p;
    cellule* next;
} cellule;

cellule* NouvCel (point p);
void cellule_next(cellule** p_liste);
void InsererCellule(int pl, cellule *cel, cellule *liste);
void SupprimeCellule(int pl , cellule *liste);
char* Afficher(cellule *liste);

// TP12

// compteur qui incrémente automatiquement le numéro du noeud

typedef struct Noeud
{
    char val;
    int num;
    struct Noeud* fg;
    struct Noeud* fd;
} Noeud;

Noeud* nouvNoeud(char carac);
Noeud* rechercheNoeud(Noeud* arbre, int num_noeud);
void insererFG(Noeud* new_noeud, Noeud* arbre, int num_noeud);
void insererFD(Noeud* new_noeud, Noeud* arbre, int num_noeud);
void parcoursPrefixe(Noeud* arbre);


#endif // LISTE_H_INCLUDED
