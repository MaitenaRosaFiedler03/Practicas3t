#include <iostream>
#include <string.h>
#include "Artista.h"
#include "Cancion.h"
using namespace std;

#define RESET   "\033[0m"
#define DEFAULT   "\033[0m"        
#define RED    "\033[31m"      /*RED*/
#define GREEN   "\033[32m"      /*MENSAJES AL USUARIO*/ 
#define YELLOW  "\033[33m"      /*MENSAJE DE ERROR*/
#define BLUE    "\033[34m"      /*MENSAJE DE EXITO*/


Artista::Artista(){
   if(this->debug==true)
    cout << RED <<  "Se invoca al Constructor Artista."
         << "La dirección de this es: " << this << DEFAULT << endl;

    this->setIdArtista(0);
    this->setNombreArtista("NULL");
    this->setUtilCancionesCreadas(0);
    this->canciones = new Cancion* [1];

    if (this->canciones== 0){
        cerr << "NO hay memoria disponible... Cerrando programa" << endl;
        exit(-1);
    }
}
Artista::~Artista(){

    Cancion *c= 0;
    
    if(this->debug==true){
         cout << RED <<  "Se invoca al Destructor Artista." << "La dirección de this es: " << this << DEFAULT << endl;
    }

    if(this!=0){
        this->setIdArtista(0);
        this->setNombreArtista("NULL");
        this->setUtilCancionesCreadas(0);
        this->setCancionesArtista(c,0);
        delete this->canciones;
    }

}
Artista::Artista(const Artista &a){

    if(this->debug==true){
        cout << RED <<  "Se invoca al Constructor por copia Artista."<< "La dirección de this es: " << this << DEFAULT << endl;
    }

    this->setIdArtista(a.getIdArtista());
    this->setNombreArtista(a.getNombreArtista());
    this->setUtilCancionesCreadas(a.getUtilCancionesCreadas());

    this->canciones = new Cancion*[a.getUtilCancionesCreadas()+1];

    if (this->canciones == 0){
        cerr << "NO hay memoria disponible... Cerrando programa" << endl;
        exit(-1);
    }

    for(int i=0; i <= this->getUtilCancionesCreadas() ; i++)
        this->canciones[i]=a.getCancionArtista(i);

}

unsigned int Artista::getIdArtista()const {
    return this->idArtista;
}
void Artista::setIdArtista(const unsigned int nuevo){

    if(this->debug==true){
        cout << RED << "Estableciendo idArtista" << "La dirección de this es: " << this << RESET << endl;
    }
    this->idArtista=nuevo;
}
string Artista::getNombreArtista()const {
    return this->nombre;
}
void Artista::setNombreArtista(const string nuevo){

   if(this->debug==true){
        cout << RED << "Estableciendo el nombre del artista" << "La dirección de this es: " << this << RESET << endl;
   }
    this->nombre=nuevo;
}
bool Artista::getActivado()const {
    return this->activado;
}
void Artista::setActivado(const bool nuevo){

    if(this->debug==true){
        cout << RED << "Estableciendo el activado" << "La dirección de this es: " << this << RESET << endl;
    }

    this->activado=nuevo;
}
void Artista::setUtilCancionesCreadas(const int total){
   
    if(this->debug==true){
        cout << RED << "Estableciendo la util de las canciones creadas" << "La dirección de this es: " << this << RESET << endl;
    }
    this->util_canciones=total;
}
int Artista::getUtilCancionesCreadas() const {
    return this->util_canciones;
}

Cancion* Artista::getCancionArtista(const int i) const{

    return this->canciones[i];

}
void Artista::setCancionesArtista(Cancion* nueva, int i){

    if(this->debug==true){
        cout << RED << "Estableciendo la cancion en artista" << "La dirección de this es: " << this << RESET << endl;
    }

    this->canciones[i]=nueva;
}
void Artista::eliminarCancionDeArtista(const int cancion){
    
}
Artista:: Artista(const int id, const string nuevo, Cancion* c, const int a){

    if(this->debug==true){
        cout << RED <<  "Se invoca al Constructor por copia Artista." << "La dirección de this es: " << this << DEFAULT << endl;
    }   

    this->setIdArtista(id);
    this->setNombreArtista(nuevo);
    this->setUtilCancionesCreadas(a);
    this->canciones = new Cancion*[a+1];

    if (this->canciones == 0){
        cerr << "NO hay memoria disponible... Cerrando programa" << endl;
        exit(-1);
    }

    //se imprimen las canciones del sistema y se van eligiendo 
}
void Artista::operator=(const Artista &i){
    
    cout << RED <<  "Se invoca al operador=."
         << "La dirección de this es: " << this << DEFAULT << endl;

    if(this->canciones==0){
        this->canciones = new Cancion*[i.getUtilCancionesCreadas()] ;

    }

    if (this->canciones == 0){
            cerr << "NO hay memoria disponible... Cerrando programa" << endl;
            exit(-1);
    }
    this->activado=i.getActivado();
    this->idArtista=i.getIdArtista();
    this->nombre=i.getNombreArtista();
    this->util_canciones= i.getUtilCancionesCreadas();

    for(int b=0; b < this->getUtilCancionesCreadas();b++){
        this->canciones[b]=i.getCancionArtista(b);
    }
    

}
ostream& operator<<(ostream &flujo, const Artista &a){
  
    //if(a.getActivado()==true){
        cout << "-----------------------" << endl; 
    
        cout << "Id Artista: ";

        flujo << a.getIdArtista() << endl;

        cout << "Nombre artista: ";

        flujo << a.getNombreArtista() << endl;

        cout << "Canciones del artista : " << endl;

        for(int i=0; i < a.getUtilCancionesCreadas(); i++){
            flujo << a.getCancionArtista(i)->getNombreCancion() << endl; 
        }

        cout << "-----------------------" << endl; 
   // }

   return flujo;
}

istream& operator>>(istream &flujo,  Artista &a){
    
    unsigned int id;
    string nombre;

    if(a.getActivado()==true){

        cout << "Id Artista: ";

        while(!(flujo >> id)){

            cin.clear();
            cin.ignore();
            cout << "Ingrese numero positivo " << endl; 
        }

        cout << "Nombre artista: ";
    
        cin.ignore();
        getline(cin,nombre);

        cout << "Canciones del artista : " << endl;
        
            
        a.setIdArtista(id);
        a.setNombreArtista(nombre);
    }
    return flujo;
}

void Artista::debugON(const bool nuevo){
    this->debug=nuevo;
}
void Artista::resize(const int DIM_NUEVA){

    if(this->debug==true){
    cout << RED <<  "Se invoca al resize de Canciones de Artista."
         << "La dirección de this es: " << this << DEFAULT << endl;
    }

    Cancion** nuevo= new Cancion*[DIM_NUEVA+1];
    
    if(nuevo == 0){
        cerr << "No hay espacio suficiente. Se terminará la ejecución del programa." << endl;
        exit(-1);
    }
    else 
    cout << GREEN << "Vector creado correctamente.." << RESET << endl;
    
    //se inicializa el nuevo vector a cero 

    if(DIM_NUEVA < this->getUtilCancionesCreadas()){
       
        for(int i=0; i < DIM_NUEVA +1; i++){
            
            nuevo[i]= this->getCancionArtista(i);
            
        }        

    }

    else if(DIM_NUEVA >= this->getUtilCancionesCreadas()){
 
        for(int i=0; i < this->getUtilCancionesCreadas() +1; i++){
            nuevo[i]= this-> getCancionArtista(i);
        }
    }
    //se elimina el antiguo vector 
    delete [] this->canciones; 

    //se establece el nuevo grado maximo 
    
    //se iguala la direcciòn de memoria del vector dinamico coef con el nuefvo vector  
    this-> canciones = nuevo;

}