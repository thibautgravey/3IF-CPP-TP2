/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 19 NOVEMBRE 2019
    copyright            : (C) 2019 par BRANCHEREAU, GRAVEY
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "ListeTrajets.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

const int TAILLE_ENTREE_VILLE = 45;
const int TAILLE_ENTREE_MOYEN_TRANSPORT = 20;

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
//
//
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    void Presenter();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void AddTrajetSimple();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //void AddTrajetCompose();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void RechercheSimple(const char * vDepart, const char* vArrivee);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void RechercheComplexe(const char * vDepart, const char* vArrivee);
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

    Catalogue ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Catalogue ();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
   char * AskVilleArrivee() const;
   // Mode d'emploi :
   //
   // Contrat :
   //

   char * AskVilleDepart() const;
   // Mode d'emploi :
   //
   // Contrat :
   //

   char * AskMoyenTransport() const;
   // Mode d'emploi :
   //
   // Contrat :
   //
//----------------------------------------------------- Attributs protégés

   ListeTrajets listeTraj;
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE_H