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



Playlist::Playlist(){

    if(this->debug==true){
        cout << RED <<  "Se invoca al Constructor Playlist." << "La dirección de this es: " << this << DEFAULT << endl;
    }

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

    if(this->debug==true){
     cout << RED <<  "Se invoca al Deconstructor Cancion." << "La dirección de this es: " << this << DEFAULT << endl;
    }

    if(this!=0){
        this->idPlaylist=0;
        this->nombre="NULL";
        delete this->canciones;
        this->util_v_canciones=0;
        this->duracion.setMinutos(0);
        this->duracion.setSegundos(0);
    }
}

Cancion* Playlist::getCancionPlaylist(const int &cancion)const{
    return this->canciones[cancion];
}
void Playlist::eliminarCancionDePlaylist(const int &cancion){

}
void Playlist::setUtilCancionesPlaylist(const int &nueva){
   
   if(this->debug==true){
        cout << RED << "Estableciendo util canciones playlist" << "La dirección de this es: " << this << RESET << endl;
   }
   this->util_v_canciones=nueva;
}
int Playlist::getUtilCancionesPlaylist() const {
    return this->util_v_canciones;
}
Tiempo Playlist::getDuracionPlaylist()const {
    return this->duracion;
}
void Playlist::setDuracionPlaylist(const Tiempo &t){

    if(debug==true){
        cout << RED << "Estableciendo la duracion de la playlist" << "La dirección de this es: " << this << RESET << endl;
    }

    this->duracion.setMinutos(t.getMinutos());
    this->duracion.setSegundos(t.getSegundos());
}
Playlist::Playlist( Playlist &p){

    if(this->debug==true){
        cout << RED <<  "Se invoca al Constructor por copia Playlist."<< "La dirección de this es: " << this << DEFAULT << endl;
    }

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

    if(debug==true){
        cout << RED << "Estableciendo id de la playlist" << "La dirección de this es: " << this << RESET << endl;
    }

    this->idPlaylist=i;
}
unsigned int Playlist::getIDPlaylist()const {
    return this->idPlaylist;
}
void Playlist::setNombrePlaylist(const string nueva){

    if(debug==true){
        cout << RED << "Estableciendo el nombre de la playlist" << "La dirección de this es: " << this << RESET << endl;
    }

    this->nombre=nueva;
}
string Playlist::getNombrePlaylist() const {
    return this->nombre;
}
void Playlist::agregarCancionEnPlaylist(Cancion* c){
//resize 
}

void Playlist::operator=(const Playlist &p){
   
   this->idPlaylist=p.idPlaylist;
   this->nombre=p.nombre;
   this->setDuracionPlaylist(p.duracion);
   
   for(int i; i < this->getUtilCancionesPlaylist(); i++){
       this->canciones[i]=p.canciones[i];
   }

 

   
}
istream& operator>>(istream &flujo,  Playlist &p){

    unsigned int idPlaylist;
    string nombre;
    int util_v_canciones;
    Tiempo duracion;
    Cancion c;

    cout << "-----------------------" << endl;
    cout << "Id Playlist: "; 
    while(!(flujo >> idPlaylist)){
        cin.clear();
        cin.ignore();
        cout << "Ingrese un numero positivo " << endl; 
    }
    
    cout << "Nombre : "; 
    cin.ignore();
    getline(cin,nombre);
    


    cout << "Duracion: ";
  
      while(!(flujo >> duracion)){
        cin.clear();
        cin.ignore();
        cout << "Ingrese un duracion valida " << endl; 
    }
    //agregar cancion en playlist
     cout << "-----------------------" << endl;

    p.setIDPlaylist(idPlaylist);
    p.setNombrePlaylist(nombre);
    p.setDuracionPlaylist(duracion);


    return flujo;
}
ostream& operator<<(ostream &flujo, const Playlist &p){
   
     cout << "-----------------------" << endl;
    cout << "Id Playlist: "; 
    flujo << p.getIDPlaylist() << endl;

    cout << "Nombre : "; 
    flujo << p.getNombrePlaylist() << endl;

    cout << "Duracion: ";
    flujo << p.getDuracionPlaylist() << endl;

     cout << "-----------------------" << endl;
    return flujo;
}
Tiempo Playlist::calcularDuracionPlaylist(){

    int seg=0;
    int min=0;
    Tiempo t;

    for (int i=0; this->getUtilCancionesPlaylist(); i++){
        seg+=this->duracion.getSegundos();
        min+=this->duracion.getMinutos();
    }

    t.setMinutos(min);
    t.setSegundos(seg);
    
    return t;
}
void Playlist::debugON(const bool nuevo){
    this->debug=nuevo;
}

void Playlist::resize(const int DIM_NUEVA){

    if(this->debug==true){
    cout << RED <<  "Se invoca al resize de Artistas en Canciòn ."
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

    if(DIM_NUEVA < this->getUtilCancionesPlaylist()){
       
        for(int i=0; i < DIM_NUEVA +1; i++){
            
            nuevo[i]= this->getCancionPlaylist(i);
            
        }        

    }

    else if(DIM_NUEVA >= this->getUtilCancionesPlaylist()){
 
        for(int i=0; i < this->getUtilCancionesPlaylist() +1; i++){
            nuevo[i]= this-> getCancionPlaylist(i);
        }
    }
    //se elimina el antiguo vector 
    delete [] this->canciones; 

    //se establece el nuevo grado maximo 
    
    //se iguala la direcciòn de memoria del vector dinamico coef con el nuefvo vector  
    this-> canciones = nuevo;

}
