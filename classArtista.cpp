#include <iostream>
#include "Artista.h"
#include "Cancion.h"

using namespace std;

#define RESET   "\033[0m"
#define DEFAULT   "\033[0m"        
#define RED    "\033[31m"      /*RED*/
#define GREEN   "\033[32m"      /*MENSAJES AL USUARIO*/ 
#define YELLOW  "\033[33m"      /*MENSAJE DE ERROR*/
#define BLUE    "\033[34m"      /*MENSAJE DE EXITO*/

bool debug=true;

Artista::Artista(){
    if(debug==true)
    cout << RED <<  "Se invoca al Constructor Artista."
         << "La dirección de this es: " << this << DEFAULT << endl;

    this->setIdArtista(0);
    this->setNombreArtista("NULL");
}
Artista:: ~Artista(){
    if(debug==true)
    cout << RED <<  "Se invoca al Destructor Artista."
         << "La dirección de this es: " << this << DEFAULT << endl;

    this->setIdArtista(0);
    this->setNombreArtista("NULL");
}
unsigned int Artista::getIdArtista()const {
    return this->idArtista;
}
void Artista::setIdArtista(const unsigned int nuevo){

    if(debug==true)
        cout << RED << "Estableciendo idArtista" << "La dirección de this es: " << this << RESET << endl;


    this->idArtista=nuevo;
}
string Artista::getNombreArtista()const {
    return this->nombre;
}
void Artista::setNombreArtista(const string nuevo){

    if(debug==true)
        cout << RED << "Estableciendo el nombre del artista" << "La dirección de this es: " << this << RESET << endl;

    this->nombre=nuevo;
}

bool Artista::getActivado() const {
    return this->activado;
}

void Artista::setActivado(bool nuevo){
    this->activado=nuevo;
}

Cancion* Artista::getCancionArtista(){
    return this->canciones;
}
void Artista::setCancionesArtista(Cancion* nuevo, int i){
    this->canciones[i];
}