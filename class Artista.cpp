#include <iostream>
#include "Artista.h"
using namespacetd;

Artista::Artista(){
    if(debug==true)
    cout << DEBUG <<  "Se invoca al Constructor Artista."
         << "La dirección de this es: " << this << DEFAULT << endl;

    this->setIdArtista(0);
    this->setNombreArtista("NULL");
}
Artista:: ~Artista(){
    if(debug==true)
    cout << DEBUG <<  "Se invoca al Destructor Artista."
         << "La dirección de this es: " << this << DEFAULT << endl;

    this->setIdArtista(0);
    this->setNombreArtista("NULL");
}
unsigned int Artista::getIdArtista()const {
    return this->idArtista;
}
void Artista::setIdArtista(const unsigned int nuevo){

    if(debug==true)
        cout << DEBUG << "Estableciendo idArtista" << "La dirección de this es: " << this << RESET << endl;


    this->idArtista=nuevo;
}
string Artista::getNombreArtista()const {
    return this->nombre;
}
void Artista::setNombreArtista(const string nuevo){

    if(debug==true)
        cout << DEBUG << "Estableciendo el nombre del artista" << "La dirección de this es: " << this << RESET << endl;

    this->nombre=nuevo;
}