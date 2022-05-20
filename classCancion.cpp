#include <iostream>
#include <iomanip>
#include "Cancion.h"

using namespace std;

#define RESET   "\033[0m"
#define DEFAULT   "\033[0m"        
#define RED    "\033[31m"      /*RED*/
#define GREEN   "\033[32m"      /*MENSAJES AL USUARIO*/ 
#define YELLOW  "\033[33m"      /*MENSAJE DE ERROR*/
#define BLUE    "\033[34m"      /*MENSAJE DE EXITO*/

bool debug=true;

void Cancion::operator=(const Cancion &c){

    cout << RED <<  "Se invoca al operador= de Cancion."
         << "La dirección de this es: " << this << DEFAULT << endl;

    if(this->v_Artista==0){
        this->v_Artista = new Artista* [c.util_artista+1];
    
    
        if (this->v_Artista == 0){
            cerr << "NO hay memoria disponible... Cerrando programa" << endl;
            exit(-1);
        }
    
    }
   for(int i=0;i < this->util_artista;i++)
        this->v_Artista[i]=c.getArtista(i);

    //se copian los valores de los grados
    this ->idCancion=c.getIdCancion();
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
    this->util_artista=nueva;
}

unsigned int Cancion::getIdCancion()const {
    return this->idCancion;
}
void Cancion::setIdCancion(const unsigned int nuevo){

    if(debug==true)
        cout << RED << "Estableciendo idCancion" << "La dirección de this es: " << this << RESET << endl;

    this->idCancion=nuevo;
}
Artista* Cancion::getArtista(int i)const{
   return this->v_Artista[i];
}
void Cancion::setArtista( Artista *nuevo, int i ){

    if(debug==true)
        cout << RED << "Estableciendo artista en la cancion" << "La dirección de this es: " << this << RESET << endl;

    this->v_Artista[i]=nuevo;
}
Tiempo Cancion::getDuracion() const {
    return this->duracion;
}
void Cancion::setDuracion(const Tiempo &t){

    if(debug==true)
        cout << RED << "Estableciendo la duracion de la cancion" << "La dirección de this es: " << this << RESET << endl;

    this->duracion=t;
}
int Cancion::getTotalRepro() const {
    return this->total_reproducciones;
}
void Cancion::setTotalRepro(int total){

    if(debug==true)
        cout << RED << "Estableciendo total reproducciones de la cancion " << "La dirección de this es: " << this << RESET << endl;

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
Cancion::~Cancion(){

    if(debug==true)
    cout << RED <<  "Se invoca al Destructor Cancion."
         << "La dirección de this es: " << this << DEFAULT << endl;

}
Cancion::Cancion(){

    if(debug==true)
    cout << RED <<  "Se invoca al Constructor Cancion."
         << "La dirección de this es: " << this << DEFAULT << endl;


    //creo una variable tipo puntero a puntero y digo que apuntarà a un vector de punteros 
    Artista** a= new Artista*[1];

    if(a==0){
        cout << "No hay memoria en el sistema... cerrando programa " << endl;
        exit(-1);
    }
    Tiempo t;
    
    t.setMinutos(0);
    t.setSegundos(0);

    //a->setIdArtista(0);
    //a->setNombreArtista("NULL");

    
    this->setIdCancion(0);
    this->setNombreCancion("NULL");
    this->setDuracion(t);

     this->v_Artista  =a;

    //accedo a la direcciòn de memoria de v_artista y digo que ahora v_apuntarà al vector de punteros al que apunta la variable a
    //ahora tantp v_artista como 'a' apuntaran al vector 'nuevo'
    *this->v_Artista = *a;
     
    this->setArtista(0,0);
}
void Cancion::resize(int dim_nueva){

    Artista** nuevo= 0;
     
    nuevo= new Artista*[dim_nueva+1];
    
    if(nuevo == 0){
        cerr << "No hay espacio suficiente. Se terminará la ejecución del programa." << endl;
        exit(-1);
    }
    else 
    cout << GREEN << "Vector creado correctamente.." << RESET << endl;
    
    //se inicializa el nuevo vector a cero 

   // for(int i=0; i < dim_nueva +1; i++){
        //nuevo[i]=;
         
        //cout << "(resise(inicializaciòn))nuevo ["  <<  i << "]: "  << nuevo[i] << endl; 
   // }
    
    //si la nueva dimensiòn es menor que la dimension actual -1 (el grado maximo del polinomio)
    if(dim_nueva < this->getUtil_artista()){
       
        for(int i=0; i < dim_nueva +1; i++){
            
            nuevo[i]= this->getArtista(i);
            // cout << "(resise(dim<gradoM))nuevo ["  <<  i << "]: "  << nuevo[i] << endl; 
           
        }        

    }

    //si la nueva dimensiòn es mayor que la dimensiòn -1 (el grado maximo del polinomio )
    else if(dim_nueva >= this->getUtil_artista()){
       // cout << "this->getMaxGrado() +1 " << this->getMaxGrado() << endl;
        //se copian los valores hasta el grado maximo (todos los valores del vector )
       // for(int i=0; i < this->getMaxGrado() +1; i++){
        //    nuevo[i]= this-> getCoeficiente(i);
           //cout << "(resise(dim_nueva>grado max))nuevo ["  <<  i << "]: "  << nuevo[i] << endl;
        
       // }
    }
    //se elimina el antiguo vector 
    delete [] this->v_Artista; 

    //se establece el nuevo grado maximo 
    
    //se iguala la direcciòn de memoria del vector dinamico coef con el nuefvo vector  
    this-> v_Artista = nuevo;

}
