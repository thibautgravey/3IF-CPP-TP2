/*************************************************************************
                           ListeTrajets  -  description
                             -------------------
    début                : 19 NOVEMBRE 2019
    copyright            : (C) 2019 par BRANCHEREAU, GRAVEY
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <ListeTrajets> (fichier ListeTrajets.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "ListeTrajets.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type ListeTrajets::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

Trajet ** ListeTrajets::GetListe() const
// Algorithme :
//
{
  return liste;
} //----- Fin de GetListe

int ListeTrajets::GetNbTrajets() const
// Algorithme :
//
{
  return nbTrajets;
} //----- Fin de getNbTrajets

void ListeTrajets::AddTrajet(Trajet* nouveauTrajet)
// Algorithme :
//
{
   if(nbTrajets==tailleMax)
   {
      augmenterTaille();
   }

   liste[nbTrajets] = nouveauTrajet;
   nbTrajets=nbTrajets+1;
} //----- Fin de addTrajet

int ListeTrajets::RetirerDernier()
// Algorithme :
//
{
    nbTrajets--;
    return 0;
} //----- Fin de Retirer

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

ListeTrajets::ListeTrajets (const ListeTrajets & unListeTrajets)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ListeTrajets>" << endl;
#endif

    liste = new Trajet * [unListeTrajets.tailleMax];
    tailleMax=unListeTrajets.tailleMax;
    nbTrajets=unListeTrajets.nbTrajets;
    for(int i=0;i<unListeTrajets.nbTrajets;i++)
    {
        liste[i] = unListeTrajets.GetListe()[i];
    }
} //----- Fin de ListeTrajets (constructeur de copie)


ListeTrajets::ListeTrajets (const int taille) : tailleMax(taille), nbTrajets(0)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ListeTrajets>" << endl;
#endif

   liste = new Trajet * [tailleMax];
} //----- Fin de ListeTrajets


ListeTrajets::~ListeTrajets ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ListeTrajets>" << endl;
#endif
    delete [] liste;
} //----- Fin de ~ListeTrajets


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

 void ListeTrajets::augmenterTaille()
 // Algorithme :
 //
{
   tailleMax+=NBAUGMENTATION;

   Trajet ** tmp = new Trajet * [tailleMax];

   for(int i = 0; i<nbTrajets;i++)
   {
      tmp[i]=liste[i];
   }

   delete [] liste;

   liste=tmp;
} //----- Fin de GetListe
