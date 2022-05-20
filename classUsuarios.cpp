#include <iostream>
#include "Usuarios.h"
using namespace std;

#define RESET   "\033[0m"
#define DEFAULT   "\033[0m"        
#define RED    "\033[31m"      /*RED*/
#define GREEN   "\033[32m"      /*MENSAJES AL USUARIO*/ 
#define YELLOW  "\033[33m"      /*MENSAJE DE ERROR*/
#define BLUE    "\033[34m"      /*MENSAJE DE EXITO*/

Usuario::Usuario(){
    cout << RED <<  "Se invoca al Destructor Usuario."
         << "La dirección de this es: " << this << DEFAULT << endl;


    this->id=0;
    this->activado=true;
    this->login="NULL";
    this->password="NULL";

}

Usuario::~Usuario(){

      cout << RED <<  "Se invoca al Constructor Usuario."
         << "La dirección de this es: " << this << DEFAULT << endl;


    this->id=0;
    this->activado=true;
    this->login="NULL";
    this->password="NULL";
}
Usuario::Usuario(const Usuario &u){

    cout << RED <<  "Se invoca al Constructor por copia de Usuario."
         << "La dirección de this es: " << this << DEFAULT << endl;


    this->id = u.id;
    this->activado = u.activado;
    this->login = u.login;
    this->password = u.password;
}
Usuario::Usuario(const int id, const bool activo, const string login, const string contra){
    
     cout << RED <<  "Se invoca al Constructor por parametro de Usuario."
         << "La dirección de this es: " << this << DEFAULT << endl;


    this->id = id;
    this->activado = activo;
    this->login = login;
    this->password = contra;
}
       
void Usuario::setIDUsuario(const unsigned int id){
    this->id=id;
}

void Usuario::setActivado(const bool activado){
    this->activado=activado;
}
void Usuario::setLogin(const string login){
    this->login=login;
}
void Usuario::setPassword(const string nuevo){
    this->password=nuevo;
}
bool Usuario::getLogin() const {

}