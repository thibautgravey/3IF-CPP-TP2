/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 19 NOVEMBRE 2019
    copyright            : (C) 2019 par BRANCHEREAU, GRAVEY
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Catalogue::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Catalogue::AddTrajetSimple()
// Algorithme :
//
{
   char * vDepart = askVilleDepart();
   char * vArrivee =askVilleArrivee();
   char * vMoyenTransport = askMoyenTransport();
   TrajetSimple * nouveauTrajet = new TrajetSimple(vDepart,vArrivee,vMoyenTransport);
   listeTraj.AddTrajet(nouveauTrajet);
} //----- Fin de addTrajetSimple

void Catalogue::AddTrajetCompose()
// Algorithme :
//
{
  int nbTrajets;
  ListeTrajets liste;
  cout<<"Nombre de trajets ?"<<endl;
  cin >> nbTrajets;
  while(cin.fail())
  {
      cout << "Erreur, veuillez entrer un entier" <<endl;
      cin.clear();          //on clear le buffer
      cin.ignore(256,'\n'); // on ignore les caractères jusqu'a obtenir un retour à la ligne
      cin >> nbTrajets;             //on redemande la valeur
  }

  char* vArriveePrecedent;
  char* vDepart=askVilleDepart();
  char* vArrivee=askVilleArrivee();
  char* mTransport=askMoyenTransport();
  TrajetSimple* tmpTrajet=new TrajetSimple(vDepart,vArrivee,mTransport);
  liste.AddTrajet(tmpTrajet);
  vArriveePrecedent=vArrivee;

  for(int i=1;i<nbTrajets;i++)
  {
    vDepart=askVilleDepart();
    vArrivee=askVilleArrivee();
    mTransport=askMoyenTransport();

    if(strcmp(vDepart,vArriveePrecedent)==0)
    {
      TrajetSimple* tmpTrajet=new TrajetSimple(vDepart,vArrivee,mTransport);
      liste.AddTrajet(tmpTrajet);
      vArriveePrecedent=vArrivee;
    }
    else
    {
      while(strcmp(vDepart,vArriveePrecedent)!=0)
      {
          cout << "Erreur, vous devez repartir de la ville d'étape précédente" <<endl;
          vDepart=askVilleDepart();
          vArrivee=askVilleArrivee();
          mTransport=askMoyenTransport();
      }
      TrajetSimple* tmpTrajet=new TrajetSimple(vDepart,vArrivee,mTransport);
      liste.AddTrajet(tmpTrajet);
      vArriveePrecedent=vArrivee;
    }

  }



} //----- Fin de AddTrajetCompose


void Catalogue::RechercheSimple(const char * vDepart, const char* vArrivee)
// Algorithme :
//
{

} //----- Fin de GetListeTraj

void Catalogue::RechercheComplexe(const char * vDepart, const char* vArrivee)
// Algorithme :
//
{

} //----- Fin de GetListeTraj

void Catalogue::Presenter()
// Algorithme :
//
{
   int nbTrajets = listeTraj.GetNbTrajets();
   cout << nbTrajets << endl;
   if(nbTrajets==0)
   {
      cout << "---------- CATALOGUE VIDE ----------" << endl;
   }
   else
   {
      Trajet ** traj = listeTraj.GetListe();
      cout << "---------- CONTENU DU CATALOGUE ----------" << endl;
      for(int i=0; i<nbTrajets;i++)
      {
         traj[i]->Affichage();
      }
   }
} //----- Fin de Presenter

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

Catalogue::Catalogue () : listeTraj()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

char * askVilleArrivee()
// Algorithme :
//
{
   char* ret=new char(TAILLE_ENTREE_VILLE);
   cout << "Saisir la ville de départ : " << endl;
   cin.getline(ret,TAILLE_ENTREE_VILLE);
   return ret;
} //----- Fin de AskVilleDepart

char * askVilleDepart()
// Algorithme :
//
{
  char* ret=new char(TAILLE_ENTREE_VILLE);
   cout << "Saisir la ville d'arrivée : " << endl;
   cin.getline(ret,TAILLE_ENTREE_VILLE);
   return ret;
} //----- Fin de AskVilleArrivee

char * askMoyenTransport()
// Algorithme :
//
{
   char* ret=new char(TAILLE_ENTREE_VILLE);
   cout << "Saisir le moyen de transport : " << endl;
   cin.getline(ret,TAILLE_ENTREE_VILLE);
   return ret;
} //----- Fin de AskMoyenTransport

//----------------------------------------------------- Méthodes protégées
