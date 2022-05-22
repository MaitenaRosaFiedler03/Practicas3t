#include <iostream>
#include <iomanip>
#include "Cancion.h"
#include "Artista.h"
#include "vista.h"
#include <bits/stdc++.h>

using namespace std;

#define RESET   "\033[0m"
#define DEFAULT   "\033[0m"        
#define RED    "\033[31m"      /*RED*/
#define GREEN   "\033[32m"      /*MENSAJES AL USUARIO*/ 
#define YELLOW  "\033[33m"      /*MENSAJE DE ERROR*/
#define BLUE    "\033[34m"      /*MENSAJE DE EXITO*/


void Cancion::debugON(const bool nuevo){
    this->debug=nuevo;
}
void Cancion::operator=(const Cancion &c){
    if(this->debug==true){
        cout << RED <<  "Se invoca al operador= de Cancion."<< "La dirección de this es: " << this << DEFAULT << endl;
    }

    if(this->v_Artista==0){
        this->v_Artista = new Artista* [c.util_artista+1];
    
    
        if (this->v_Artista == 0){
            cerr << "NO hay memoria disponible... Cerrando programa" << endl;
            exit(-1);
        }
    
    }
   for(int i=0;i < this->util_artista;i++)
        this->v_Artista[i]=c.getArtista(i);

    
    this->nombre=c.getNombreCancion();
    this->util_artista=c.getUtil_artista();
    this->total_reproducciones=c.getTotalRepro();
    this->duracion=c.getDuracion();


    for(int i =0; i < this->getUtil_artista() +1; i++){
        this->v_Artista[i]= c.getArtista(i);
       
    }
}

int Cancion::getUtil_artista()const {
    return this->util_artista;
}
void Cancion::setUtil_artista(const int nueva){

    if(this->debug==true){
        cout << RED << "Estableciendo util artista" << "La dirección de this es: " << this << RESET << endl;
    }

    this->util_artista=nueva;
}

unsigned int Cancion::getIdCancion()const {
    return this->idCancion;
}
void Cancion::setIdCancion(const unsigned int nuevo){

    if(this->debug==true){
        cout << RED << "Estableciendo idCancion" << "La dirección de this es: " << this << RESET << endl;
    }
    this->idCancion=nuevo;
}
Artista* Cancion::getArtista(int i)const{
   return this->v_Artista[i];
}
void Cancion::setArtista( Artista *nuevo, int i ){

    if(this->debug==true){
        cout << RED << "Estableciendo artista en la cancion" << "La dirección de this es: " << this << RESET << endl;
    }

    this->v_Artista[i]=nuevo;
}
Tiempo Cancion::getDuracion() const {
    return this->duracion;
}
void Cancion::setDuracion(const Tiempo &t){

    if(this->debug==true){
        cout << RED << "Estableciendo la duracion de la cancion" << "La dirección de this es: " << this << RESET << endl;
    }


    this->duracion.setMinutos(t.getMinutos());
    this->duracion.setSegundos(t.getSegundos());
}
int Cancion::getTotalRepro() const {
    return this->total_reproducciones;
}
void Cancion::setTotalRepro(int total){

    if(this->debug==true){
        cout << RED << "Estableciendo total reproducciones de la cancion " << "La dirección de this es: " << this << RESET << endl;
    }
    this->total_reproducciones=total;
}
bool Cancion::getActivo() const{
    return this->activo;
}
void Cancion::setActivo(const bool activo){

    if(this->debug==true){
        cout << RED << "Estableciendo idCancion" << "La dirección de this es: " << this << RESET << endl;
    }
    this->activo=activo;
}
void Cancion::setNombreCancion(const string nuevo){

    if(this->debug==true){
        cout << RED << "Estableciendo nombre de la canciòn " << "La dirección de this es: " << this << RESET << endl;
    }
    this->nombre=nuevo;
}
string Cancion::getNombreCancion()const{
    return this->nombre;
}
Cancion::~Cancion(){

    if(this->debug==true){
        cout << RED <<  "Se invoca al Destructor Cancion." << "La dirección de this es: " << this << DEFAULT << endl;
    }

    if(this!= 0){
        this->activo=false;
        this->duracion.setMinutos(0);
        this->duracion.setSegundos(0);
        this->idCancion=0;
        this->nombre="NULL";
        this->util_artista=0;
        this->total_reproducciones=0;
        delete this->v_Artista ;
    }
    else 
        cout << RED <<  "El elemento con la dirección de this es: " << this << " ya fue eliminado previamente " << DEFAULT << endl;


}
Cancion::Cancion(){

    if(this->debug==true){
    cout << RED <<  "Se invoca al Constructor Cancion."
         << "La dirección de this es: " << this << DEFAULT << endl;
    }

    //creo una variable tipo puntero a puntero y digo que apuntarà a un vector de punteros 
    Artista** a= new Artista*[1];

    if(a==0){
        cout << "No hay memoria en el sistema... cerrando programa " << endl;
        exit(-1);
    }
    Tiempo t;
    
    t.setMinutos(0);
    t.setSegundos(0);
    this->setActivo(true);
    this->setIdCancion(0);
    this->setNombreCancion("NULL");
    this->setDuracion(t);
    this->setUtil_artista(1);
    this->debug=false;

     this->v_Artista  =a;

    //accedo a la direcciòn de memoria de v_artista y digo que ahora v_apuntarà al vector de punteros al que apunta la variable a
    //ahora tantp v_artista como 'a' apuntaran al vector 'nuevo'
    *this->v_Artista = *a;
     
}
void Cancion::resize(const int dim_nueva){

    if(this->debug==true){
    cout << RED <<  "Se invoca al resize de Artistas en Canciòn ."
         << "La dirección de this es: " << this << DEFAULT << endl;
    }

    Artista** nuevo= new Artista*[dim_nueva+1];
    
    if(nuevo == 0){
        cerr << "No hay espacio suficiente. Se terminará la ejecución del programa." << endl;
        exit(-1);
    }
    else 
    cout << GREEN << "Vector creado correctamente.." << RESET << endl;
    
    //se inicializa el nuevo vector a cero 

    if(dim_nueva < this->getUtil_artista()){
       
        for(int i=0; i < dim_nueva +1; i++){
            
            nuevo[i]= this->getArtista(i);
            
        }        

    }

    else if(dim_nueva >= this->getUtil_artista()){
 
        for(int i=0; i < this->getUtil_artista() +1; i++){
            nuevo[i]= this-> getArtista(i);
        }
    }
    //se elimina el antiguo vector 
    delete [] this->v_Artista; 

    //se establece el nuevo grado maximo 
    
    //se iguala la direcciòn de memoria del vector dinamico coef con el nuefvo vector  
    this-> v_Artista = nuevo;

}
Cancion::Cancion(bool activada,unsigned int id, Artista **a,string titulo, Tiempo duracion, unsigned int total_reproducciones){
  
    if(this->debug==true){
    cout << RED <<  "Se invoca al Constructor por parametro de Cancion."
         << "La dirección de this es: " << this << DEFAULT << endl;
    }

    if(a==0){
        cout << "No hay memoria en el sistema... cerrando programa " << endl;
        exit(-1);
    }

    
    this->setIdCancion(id);
    this->setNombreCancion(titulo);
    this->setDuracion(duracion);
    this->setTotalRepro(total_reproducciones);

    this->v_Artista  =a;

    //accedo a la direcciòn de memoria de v_artista y digo que ahora v_apuntarà al vector de punteros al que apunta la variable a
    //ahora tantp v_artista como 'a' apuntaran al vector 'nuevo'
    *this->v_Artista = *a;
    
}
ostream& operator<<(ostream &flujo, const Cancion &c){
    
    if(c.getActivo()==true){

        cout << "-----------------------" << endl; 

        cout << "Id Cancion: ";
        flujo << c.getIdCancion() << endl;

        cout << "Nombre Canciòn : ";
        flujo << c.getNombreCancion() << endl; 

        cout << "Reproducciones: ";
        flujo << c.getTotalRepro() << endl; 

        cout << "Duracion: ";
        flujo  << c.getDuracion() << endl; 

        cout << "Artistas :" << endl;

        
        for(int i=0; i < c.getUtil_artista(); i++){
            flujo << c.getArtista(i)->getNombreArtista() << endl; 
        }

        cout << "-----------------------" << endl;      
    }

    return flujo;
}
istream& operator>>(istream &flujo,  Cancion &c){

    unsigned int id; 
    string nombre; 
    int total;
    Tiempo duracion;
    int util=0;
    int artista=0;
    
        cout << "Id Cancion: ";
        while(!(flujo >> id)){
            cin.clear();
            cin.ignore();
            cout << "Ingrese numero positivo " << endl; 
        }

        cout << "Nombre Cancion: ";
        cin.ignore();
        getline(cin,nombre);


        cout << "Reproducciones: ";
        while(!(flujo >> total)){
            cin.clear();
            cin.ignore();
            cout << "Ingrese numero positivo " << endl; 
        }

        cout << "Duracion: " << endl;

        while(!(flujo >> duracion)){
            cin.clear();
            cin.ignore();
            cout << "Ingrese numero positivo " << endl; 
        }   

       // c.agregarArtista();
       

        c.setIdCancion(id);
        c.setNombreCancion(nombre);
        c.setUtil_artista(1);
        
        c.setTotalRepro(total);
        c.setDuracion(duracion);

    return flujo;
    
}
void Cancion::agregarArtista(){

    string artista;
    string artista2;
    Artista a; 
    
    int util= this->getUtil_artista();
    int lugar; 


  //  for(int i =0; i < v.getUtilArtistasSistema(); i++){
       // cout  << i << ".- " <<  v.getArtistaSistema(i)->getNombreArtista();
    //}

  /*  cout << "Ingrese el nombre del artista  ";
    cin.ignore();
    getline(cin,artista);

    //se pasa el nombre ingresado a minisculas 
    transform(artista.begin(), artista.end(),artista.begin(),::tolower);
    cout << "a " << endl;

    //cout << v.getUtilArtistasSistema() << endl; 

    //for(int i=0; i < v.getUtilArtistasSistema(); i++){

        artista2= v.getArtistaSistema(i)->getNombreArtista();
        cout << a << endl; 
        //se pasa el nombre del artista en minisculas 
        transform(artista2.begin(), artista2.end(),artista2.begin(),::tolower);

        //acceder a los artistas del sistema 

        if(artista.compare(artista2) == 0){
            
            util= this->getUtil_artista();
            
            resize(util +1); 

            this->setArtista(&a, util-1);  

            util++; 

            this->setUtil_artista(util);
        }
    }*/


  
    

   
}



