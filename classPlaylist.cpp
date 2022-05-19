#include <iostream>
#include <iomanip>
#include "Playlist.h"

using namespace std;

#define RESET   "\033[0m"
#define DEFAULT   "\033[0m"        
#define RED    "\033[31m"      /*RED*/
#define GREEN   "\033[32m"      /*MENSAJES AL USUARIO*/ 
#define YELLOW  "\033[33m"      /*MENSAJE DE ERROR*/
#define BLUE    "\033[34m"      /*MENSAJE DE EXITO*/

bool debug=true;

Playlist::Playlist(){

    if(debug==true)
    cout << RED <<  "Se invoca al Constructor Playlist."
         << "La dirección de this es: " << this << DEFAULT << endl;


    Cancion** c = new Cancion*[1];
    if(c==0){
        cout << "No hay memoria en el sistema... cerrando programa " << endl;
        exit(-1);
    }
 
    this->idPlaylist=0;
    this->nombre="NULL";
    this->canciones = c;
    this->util_v_canciones=0;
    this->duracion.setMinutos(0);
    this->duracion.setSegundos(0);
}

Playlist::~Playlist(){

    if(debug==true)
    cout << RED <<  "Se invoca al Deconstructor Cancion."
         << "La dirección de this es: " << this << DEFAULT << endl;


    this->idPlaylist=0;
    this->nombre="NULL";
    delete this->canciones;
    this->util_v_canciones=0;
    this->duracion.setMinutos(0);
    this->duracion.setSegundos(0);
}

Cancion* Playlist::getCancionPlaylist(const int &cancion){
    return this->canciones[cancion];
}
void Playlist::eliminarCancionDePlaylist(const int &cancion){

}
void Playlist::setUtilCancionesPlaylist(const int &nueva){
   this->util_v_canciones=nueva;
}
int Playlist::getUtilCancionesPlaylist(){
    return this->util_v_canciones;
}
Tiempo Playlist::getDuracionPlaylist(){
    return this->duracion;
}
void Playlist::setDuracionPlaylist(const Tiempo &t){
    this->duracion=t;
}
Playlist::Playlist( Playlist &p){

    if(debug==true)
    cout << RED <<  "Se invoca al Constructor por copia Playlist."
         << "La dirección de this es: " << this << DEFAULT << endl;

    Cancion** c = new Cancion*[1];
    if(c==0){
        cout << "No hay memoria en el sistema... cerrando programa " << endl;
        exit(-1);
    }
 
    this->idPlaylist=p.getIDPlaylist();
    this->nombre=p.getNombrePlaylist();
    this->util_v_canciones=p.getUtilCancionesPlaylist();
    for(int i=0 ;i < this->getUtilCancionesPlaylist();i++){
        *this->canciones = p.getCancionPlaylist(i);
    }
    this->util_v_canciones=0;
    this->duracion.setMinutos(0);
    this->duracion.setSegundos(0);
}

void Playlist::setIDPlaylist(const unsigned int i){
    this->idPlaylist=i;
}
unsigned int Playlist::getIDPlaylist()const {
    return this->idPlaylist;
}
void Playlist::setNombrePlaylist(const string nueva){
    this->nombre=nueva;
}
string Playlist::getNombrePlaylist() const {
    return this->nombre;
}
void Playlist::agregarCancionEnPlaylist(Cancion* c){

}
/*Playlist& Playlist::operator=(const Playlist &p){
    return ;
}*/
