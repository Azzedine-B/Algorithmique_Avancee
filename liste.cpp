#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "liste.h"


// TP11

cellule* NouvCel (point p)
{
    cellule* p_cel = (cellule*)malloc(sizeof(*p_cel));

    if(p_cel)
    {
        p_cel->p = p;
        p_cel->prev = NULL;
        p_cel->next = NULL;
    }
    else
    {
        fprintf(stderr, "Memoire insufissante\n");
        exit(EXIT_FAILURE);
    }

    return p_cel;
}


void InsererCellule(int pl, cellule *cel, cellule *liste)
{
    int cpt = 0;

    if(liste != NULL)
    {
        while(liste->next != NULL && cpt < pl)
        {
            liste = liste->next;
            ++cpt;
        }

        cellule* l_n = liste->next;

        cel->next = liste->next;

        if(l_n != NULL)
            l_n->prev = cel;

        liste->next = cel;
        cel->prev = liste;

    }
}


void SupprimeCellule(int pl , cellule *liste)
{
    int cpt = 0;

    if(liste != NULL)
    {
        while(liste->next != NULL && cpt < pl)
        {
            liste = liste->next;
            ++cpt;
        }

        cellule* l = liste;
        cellule* l_p = liste->prev;
        cellule* l_n = liste->next;

        if(l_p != NULL)
            l_p->next = l_n;

        if(l_n != NULL)
            l_n->prev = l_p;

        free(l);
        l = NULL;

    }

}

char* Afficher(cellule *liste)
{
    char* s = (char*)malloc(sizeof(char)*100);

        int cpt = 1;
        int lgt = 0;
        do
        {
            lgt += sprintf(s + lgt, "Point %d : %d, %d\n", cpt, liste->p.x, liste->p.y);
            liste = liste->next;
            ++cpt;
        } while(liste != NULL);

    return s;
}


// TP12

unsigned int cpt_noeud = 0;

Noeud* nouvNoeud(char carac)
{
    Noeud* n = (Noeud*)malloc(sizeof(n));

    if(n)
    {
        n->val = carac;
        n->num = ++cpt_noeud;
        n->fg = NULL;
        n->fd = NULL;
    }
    else
    {
        exit(EXIT_FAILURE);
    }

    return n;
}


Noeud* rechercheNoeud(Noeud* n, int num_noeud)
{
    // cas de base d'un appel récursif
    if(n == NULL)
        return NULL;
    if(n->num == num_noeud)
        return n;

    Noeud* fg = rechercheNoeud(n->fg, num_noeud); // le cas où n->fg est NULL est déjà traité, pas besoin de le tester à nouveau
    if(fg !=NULL)
        return fg;

    // si fg est NULL, alors le noeud est soit dans les fd ou abscent --> retour de recherNoeud
    return rechercheNoeud(n->fd, num_noeud);

}

 void insererFG(Noeud* new_noeud, Noeud* arbre, int num_noeud)
 {
     if(new_noeud != NULL)
     {
         Noeud* n = rechercheNoeud(arbre, num_noeud);

         if(n != NULL)
         {
             if(n->fg != NULL)
                 new_noeud->fg = n->fg;
            n->fg = new_noeud;
         }
     }
}

 void insererFD(Noeud* new_noeud, Noeud* arbre, int num_noeud)
 {
     if(new_noeud != NULL)
     {
         Noeud* n = rechercheNoeud(arbre, num_noeud);

         if(n != NULL)
         {
             if(n->fd != NULL)
                 new_noeud->fg = n->fg;
            n->fd = new_noeud;
         }
     }
}

void parcoursPrefixe(Noeud* arbre)
{
    // on doit afficher le caractère contenu dans chacun des noeuds visités
    // récursif ? :
    // cas de base
    // appel sur sous problème

    // cas de base
    if(arbre != NULL) // donc si arbre est NULL, on ne fait rien
    { // si on arrive ici, c'est que arbre != NULL
        // donc on peux afficher son caractère
        printf("%c", arbre->val);

        parcoursPrefixe(arbre->fg);
        parcoursPrefixe(arbre->fd);

    }

}


