#include <iostream>
#include "UsuarioNormal.h"
using namespace std;

#define RESET   "\033[0m"
#define DEFAULT   "\033[0m"        
#define RED    "\033[31m"      /*RED*/
#define GREEN   "\033[32m"      /*MENSAJES AL USUARIO*/ 
#define YELLOW  "\033[33m"      /*MENSAJE DE ERROR*/
#define BLUE    "\033[34m"      /*MENSAJE DE EXITO*/

Usuario_comun::Usuario_comun(){

    cout << RED <<  "Se invoca al Constructor Usuario_comun."
         << "La dirección de this es: " << this << DEFAULT << endl;

    Cancion** c= new Cancion*[1];
    if(c==0){
         cout << "No hay memoria en el sistema... cerrando programa " << endl;
        exit(-1);        
    }

    this->canciones_usuario=c;

    delete c;
    c=0;

    this->util_canciones_escuchadas=0;

    Playlist* p = new Playlist[1];

    this->playlists_usuario=p;

    delete p;
    p=0;

    this->util_playlists_usuario=0;
}
Usuario_comun::Usuario_comun(const Usuario_comun &c){

     cout << RED <<  "Se invoca al Constructor por copia Usuario_comun."
         << "La dirección de this es: " << this << DEFAULT << endl;

    Cancion** nuevo= new Cancion*[1];
    if(nuevo==0){
         cout << "No hay memoria en el sistema... cerrando programa " << endl;
        exit(-1);        
    }

    this->canciones_usuario=nuevo;

    delete nuevo;
    nuevo=0;

    for(int i=0; i < c.getUtilCancionesUsuario();i++){
        this->canciones_usuario[i]=c.canciones_usuario[i];
    }

    this->util_canciones_escuchadas=c.getUtilCancionesUsuario();

    Playlist* p = new Playlist[1];

    this->playlists_usuario=p;

    delete p;
    p=0;

    for(int i=0; i < c.getUtilPlaylistUsuario(); i++){
        this->playlists_usuario[i]=c.playlists_usuario[i];
    }

    this->util_playlists_usuario=c.getUtilPlaylistUsuario();
}
Usuario_comun::~Usuario_comun(){

    if(this->debug==true){
        cout << RED <<  "Se invoca al Deconstructor Cancion."
         << "La dirección de this es: " << this << DEFAULT << endl;
    }

    if(this!= 0){
        this->activado=false;
        delete this->canciones_usuario;
        this->util_playlists_usuario=0;
        this->util_canciones_escuchadas=0;
        this->canciones_usuario=0;
        this->playlists_usuario=0;
    }

}
void Usuario_comun::agregarCancionAUsuario(Cancion* cancion){
        this->canciones_usuario[this->getUtilCancionesUsuario()-1]= cancion;
}
void Usuario_comun::eliminarCancionDeUsuario(const int cancion){

}
void Usuario_comun::agregarPlaylistAUsuario(const Playlist &p){
    //resize 
}
void Usuario_comun::eliminarPlaylistDeUsuario(const int play){

}
void Usuario_comun::setUtilPlaylistUsuario(const int util){

    if(this->debug==true){
        cout << RED <<  "Se establece la util de playlist usuario ."<< "La dirección de this es: " << this << DEFAULT << endl;
    }
    this->util_playlists_usuario=util;
}
Cancion* Usuario_comun::getCancionUsuario(const int valor) const{

    return this->canciones_usuario[valor];
}
int Usuario_comun::getUtilCancionesUsuario() const {
    return this->util_canciones_escuchadas;
}
Playlist Usuario_comun::getPlaylistUsuario(const int i)const {
    return this->playlists_usuario[i];
}
int Usuario_comun::getUtilPlaylistUsuario()const{
    return this->util_playlists_usuario;
}
ostream& operator<<(ostream &flujo, const Usuario_comun &u){

    u.printUsuario();

    for(int t=0; t < u.getUtilCancionesUsuario(); t++){
        flujo << u.getCancionUsuario(t);
    }

    return flujo;
}
void Usuario_comun::debugON(const bool nuevo){
    this->debug=nuevo;
}



