#include <iostream>
#include "Cancion.h"
#include "Artista.h"
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
    this->setUtilCancionesCreadas(0);
    *this->canciones = new Cancion [1];

    if (this->canciones== 0){
        cerr << "NO hay memoria disponible... Cerrando programa" << endl;
        exit(-1);
    }

Artista:: ~Artista(){

    if(debug==true)
    cout << RED <<  "Se invoca al Destructor Artista."
         << "La dirección de this es: " << this << DEFAULT << endl;

    this->setIdArtista(0);
    this->setNombreArtista(0);
    this->setUtilCancionesCreadas(0);
    this->setCancionesArtista(0);
    delete this->canciones;

}
Artista::Artista(const Artista &a){
    if(debug==true)
    cout << RED <<  "Se invoca al Constructor por copia Artista."
         << "La dirección de this es: " << this << DEFAULT << endl;

    this->setIdArtista(a.getIdArtista());
    this->setNombreArtista(a.getNombreArtista());
    this->setUtilCancionesCreadas(a.getUtilCancionesCreadas);
    this->canciones = new* Cancion [a.getUtilCancionesCreadas+1];

    if (this->canciones == 0){
        cerr << "NO hay memoria disponible... Cerrando programa" << endl;
        exit(-1);
    }

    for(int i=0; i <= this->getUtilCancionesCreadas() ; i++)
       this->canciones[i]=a.getCancionesArtista(i);
}
unsigned int Artista::getIdArtista()const {
    return this->idArtista;
}
void Artista::setIdArtista(const unsigned int nuevo){

    if(debug==true)
        cout << RED << "Estableciendo idArtista" << "La dirección de this es: " << this << RESET << endl;

    this->idArtista=nuevo.;
}
string Artista::getNombreArtista()const {
    return this->nombre;
}
void Artista::setNombreArtista(const string nuevo){

    if(debug==true)
        cout << RED << "Estableciendo el nombre del artista" << "La dirección de this es: " << this << RESET << endl;

    this->nombre=nuevo;
}
bool Artista::getActivo()const {
    return this->activado;
}
void Artista::setActivo(const bool nuevo){

    if(debug==true)
        cout << RED << "Estableciendo el activado" << "La dirección de this es: " << this << RESET << endl;


    this->activado=nuevo;
}
void Artista::setUtilCancionesCreadas(const int &total){
   
    if(debug==true)
        cout << RED << "Estableciendo la util de las canciones creadas" << "La dirección de this es: " << this << RESET << endl;

    this->util_canciones=total;
}

Cancion* Artista::getCancionesArtista()const {
    return this->canciones;
}
void Artista::setCancionesArtista(const Cancion* nuevo, int i){

    if(debug==true)
        cout << RED << "Estableciendo la cancion en artista" << "La dirección de this es: " << this << RESET << endl;


    this->canciones[i]=nuevo;
}
void Artista::eliminarCancionDeArtista(const int &cancion){
    
}
Artista:: Artista(const int &id, const string &nuevo, Cancion** c, const int &a){
    if(debug==true)
    cout << RED <<  "Se invoca al Constructor por copia Artista."
         << "La dirección de this es: " << this << DEFAULT << endl;

    this->setIdArtista(id);
    this->setNombreArtista(nuevo);
    this->setUtilCancionesCreadas(a);
    this->canciones = new* Cancion [a+1];

    if (this->canciones == 0){
        cerr << "NO hay memoria disponible... Cerrando programa" << endl;
        exit(-1);
    }

    for(int i=0; i <= this->getUtilCancionesCreadas() ; i++)
       this->canciones[i]=c.getCancionesArtista(i);
}

