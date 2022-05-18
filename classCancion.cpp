#include <iostream>
#include <iomanip>
#include "Cancion.h"
using namespace std;

#define RESET   "\033[0m"
#define DEFAULT   "\033[0m"        
#define DEBUG    "\033[31m"      /*DEBUG*/
#define GREEN   "\033[32m"      /*MENSAJES AL USUARIO*/ 
#define YELLOW  "\033[33m"      /*MENSAJE DE ERROR*/
#define BLUE    "\033[34m"      /*MENSAJE DE EXITO*/

bool debug=true;

void Cancion::operator=(const Cancion &c){

    cout << DEBUG <<  "Se invoca al operador= de Cancion."
         << "La dirección de this es: " << this << DEFAULT << endl;

    if(this->v_Artista==0){
        this->v_Artista = new float [c.util_artista+1];
    
    
        if (this->v_Artista == 0){
            cerr << "NO hay memoria disponible... Cerrando programa" << endl;
            exit(-1);
        }
    
    }
   for(int i=0;i < this->util_artista)
        this->v_Artista=0;
    //se copian los valores de los grados
    this ->idCancion=c.getIdCancion();
    this->nombre=c.getNombreCancion();
    this->util_artista=c.getUtil_artista;
    this->total_reproducciones=c.getTotalRepro();
    this->duracion=c.getDuracion();


    for(int i =0; i < this->getMaxGrado() +1; i++){
        this->v_Artista[i]= c.getArtista(i);
       
    }
}


int Cancion::getUtil_artista()const {
    return this->Util_artista;
}
int Cancion::setUtil_artista(const int nueva){
    this->util_artista=nueva;
}

unsigned int Cancion::getIdCancion()const {
    return this->idCancion;
}
void Cancion::setIdCancion(const unsigned int nuevo){

    if(debug==true)
        cout << DEBUG << "Estableciendo idCancion" << "La dirección de this es: " << this << RESET << endl;

    this->idCancion=nuevo;
}
Artista* Cancion::getArtista(int i) const{
    return this->v_Artista[i];
}
void Cancion::setArtista( Artista *nuevo, int i ){

    if(debug==true)
        cout << DEBUG << "Estableciendo artista en la cancion" << "La dirección de this es: " << this << RESET << endl;

    this->v_Artista[i]=nuevo;
}
Tiempo Cancion::getDuracion() const {
    return this->duracion;
}
void Cancion::setDuracion(const Tiempo &t){

    if(debug==true)
        cout << DEBUG << "Estableciendo la duracion de la cancion" << "La dirección de this es: " << this << RESET << endl;

    this->duracion=t;
}
int Cancion::getTotalRepro() const {
    return this->total_reproducciones;
}
void Cancion::setTotalRepro(int total){

    if(debug==true)
        cout << DEBUG << "Estableciendo total reproducciones de la cancion " << "La dirección de this es: " << this << RESET << endl;

    this->total_reproducciones=total;
}
bool Cancion::getActivo() const{
    return this->activo;
}
void Cancion::setActivo(const bool activo){
    this->activo=activo;
}
void Cancion::setNombreCancion(const string nuevo){
    this->nombre=nuevo;
}
string Cancion::getNombreCancion()const{
    return this->nombre;
}
void Cancion::~Cancion(){

    if(debug==true)
    cout << DEBUG <<  "Se invoca al Destructor Cancion."
         << "La dirección de this es: " << this << DEFAULT << endl;

}
Cancion::Cancion(){
    if(debug==true)
    cout << DEBUG <<  "Se invoca al Constructor Cancion."
         << "La dirección de this es: " << this << DEFAULT << endl;

    this->setIdCancion(0);
    this->setNombreCancion("NULL");
    this->setDuracion(0);

     this->v_Artista  =new Artista* [];

     for (int i=0; i< this->getUtil_artista();i++){
         this->v_Artista[i]=0;
     }
    this->setArtista(0,0);

   
}