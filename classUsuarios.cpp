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
    cout << RED <<  "Se invoca al Constructor Usuario."
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

    //if(debug==true)
        cout << RED << "Estableciendo id de usuario" << "La dirección de this es: " << this << RESET << endl;


    this->id=id;
}

void Usuario::setActivado(const bool activado){

  //  if(debug==true)
        cout << RED << "Estableciendo activo" << "La dirección de this es: " << this << RESET << endl;


    this->activado=activado;
}
void Usuario::setLogin(const string login){

    //if(debug==true)
        cout << RED << "Estableciendo el login" << "La dirección de this es: " << this << RESET << endl;


    this->login=login;
}
void Usuario::setPassword(const string nuevo){

    //if(debug==true)
        cout << RED << "Estableciendo la constraseña.." << "La dirección de this es: " << this << RESET << endl;


    this->password=nuevo;
}
string Usuario::getLogin() const {

    return this->login;
}
unsigned int Usuario::getIDUsuario() const{
    return this->id;
}
bool Usuario::getActivado()const{
    return this->activado;
}

string Usuario::getPassword()const {
    return this->password;
}

void Usuario::operator=(const Usuario &u){
    this->id=u.id;
    this->activado=u.activado;
    this->login=u.login;
    this->password=u.password;
    
}
void Usuario::printUsuario()const {

    cout << "Id usuario: ";
    cout << this->getIDUsuario() << endl; 

    cout << "Nombre de Usuario: " ; 
    cout << this->getLogin() << endl; 

}
istream& operator>>(istream &flujo,  Usuario &u){

    unsigned int id;
    string nombre;
    string password;

    cout << "Id usuario: ";
    
    
    while(!(flujo >> id)){
        cin.clear();
        cin.ignore();
        cout << "Ingrese numero positivo " << endl; 
    }

    cout << "Nombre de Usuario: " ; 
    
    while(!(flujo >> nombre)){
            cin.clear();
            cin.ignore();
            cout << "Ingrese valido " << endl; 
        }

    cout << "Contraseña: "; 
    
    while(!(flujo >> password)){
        cin.clear();
        cin.ignore();
        cout << "Ingrese una contraseña valida " << endl; 
    }
    
    u.setIDUsuario(id);
    u.setLogin(nombre);
    u.setPassword(password);

    return flujo;
    
}