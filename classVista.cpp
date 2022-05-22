#include <iostream>
#include <iomanip>
#include "vista.h"

using namespace std;

#define RESET   "\033[0m"
#define DEFAULT   "\033[0m"        
#define RED    "\033[31m"      /*RED*/
#define GREEN   "\033[32m"      /*MENSAJES AL USUARIO*/ 
#define YELLOW  "\033[33m"      /*MENSAJE DE ERROR*/
#define BLUE    "\033[34m"      /*MENSAJE DE EXITO*/



Vista:: Vista(){

    //if(debug==true)
    cout << RED <<  "Se invoca al Constructor Vista."
         << "La dirección de this es: " << this << DEFAULT << endl;


    Usuario* s = new Usuario [1];
    if(s==0){
        cout << "No hay memoria en el sistema... cerrando programa " << endl;
        exit(-1);
    }
    Cancion* c = new Cancion[1];
    if(c==0){
        cout << "No hay memoria en el sistema... cerrando programa " << endl;
        exit(-1);
    }
    Artista* a = new Artista[1];
    if(a==0){
        cout << "No hay memoria en el sistema... cerrando programa " << endl;
        exit(-1);
    }

    this->usuarios_sistema= s;
    this->util_usuarios_sistema=0;
    this->canciones_sistema=c;
    this->util_canciones_sistema=0;
    this->artistas_sistema=a;
    this->util_artistas_sistema=0;

}
Vista::~Vista(){

   // if(debug==true)
    cout << RED <<  "Se invoca al Destructor Vista."
         << "La dirección de this es: " << this << DEFAULT << endl;


    delete this->usuarios_sistema;
    this->util_usuarios_sistema=0;
    delete this->canciones_sistema;
    this->util_canciones_sistema=0;
    delete this->artistas_sistema;
    this->util_artistas_sistema=0;

}
Usuario Vista::getUsuarios_sistema(int i)const{
    return this->usuarios_sistema[i];
}
void Vista::setUsuarios_sistema(const Usuario &user, int i){
    this->usuarios_sistema[i]=user;
}
int Vista::getUtil_usuarios_sistema()const{
    return this->util_usuarios_sistema;
}
void Vista::setUtil_usuarios_sistema(const int &usuarios){
    this->util_usuarios_sistema=usuarios;
}
Cancion Vista::getCancionesSistema(int i)const{
    return this->canciones_sistema[i];
}
void Vista::setCancionesSistema(const Cancion &c, int i){
    this->canciones_sistema[i]=c;
}
int Vista::getUtilCancionesSistema() const{
    return this->util_canciones_sistema;
}
void Vista::setUtilCancionesSistema(const int i){
    this->util_canciones_sistema=i;
}
Artista Vista::getArtistaSistema(int i )const{
    return this->artistas_sistema[i];
}
/*void Vista::setArtistaSistema(const Artista &a, int i){
    this->artistas_sistema[i]=a;
}*/
int Vista::getUtilArtistasSistema()const{
    return this->util_artistas_sistema;
}
void Vista::setUtilArtistasSistema(const int util){
     this->util_artistas_sistema=util;
}
void Vista::debugON(const bool nuevo){
    this->debug=nuevo;
}