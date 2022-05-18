
//clase tiempo, se utiliza para la duraciòn de las canciones 
#include <iostream>
#include <iomanip>
#include "Tiempo.h"
using namespace std;

#define RESET   "\033[0m"
#define DEFAULT   "\033[0m"        
#define RED    "\033[31m"      /*RED*/
#define GREEN   "\033[32m"      /*MENSAJES AL USUARIO*/ 
#define YELLOW  "\033[33m"      /*MENSAJE DE ERROR*/
#define BLUE    "\033[34m"      /*MENSAJE DE EXITO*/

bool debug=true;


Tiempo::Tiempo(){

    if(debug==true)
        cout << RED <<  "Se invoca al Constructor Tiempo." << "La dirección de this es: " << this << DEFAULT << endl;

    this->segundos=0;
    this->minutos=0;
}
Tiempo::~Tiempo (){
    if(debug==true)
    cout << RED <<  "Se invoca al Destructor del Tiempo." << "La dirección de this es: " << this << DEFAULT << endl;

}
Tiempo::Tiempo(const int minutos, const int segundos){

    if(debug==true)
     cout << RED <<  "Se invoca al Constructor por copia Tiempo."
         << "La dirección de this es: " << this << DEFAULT << endl;

    this->segundos=segundos;
    this->minutos=minutos;
}
void Tiempo::setSegundos(const int segundos){

    if(debug==true)
        cout << RED << "Estableciendo segundos"  << "La dirección de this es: " << this << RESET << endl;

    this->segundos=segundos;
}
int Tiempo::getSegundos()const{
    return this->segundos;
}
void Tiempo::setMinutos(const int minutos){

    if(debug==true)
        cout << RED << "Estableciendo minutos" << "La dirección de this es: " << this << RESET << endl;


    this->minutos=minutos;
}
int Tiempo::getMinutos() const {
    return this->minutos;
}
void Tiempo::convertirTiempo(){

int  minutos=0, var=0, segundos; 
	
    var=this->getMinutos();
   
    var= var * 60;

    var+=this->getSegundos();
    
    minutos= (var % 3600) / 60;  // el resto de dividir los segundos ingresados por los segundos de una hora los divido por 60, que son los minutos que hay en una hora 
    
    segundos= (var % 60); //si divido los segundos totales por 60 me da el numero de minutos, el resto que queda de esa divisòn son los segundos 


    this->setMinutos(minutos);
    this->setSegundos(segundos);
    
    if(minutos <= 9){
        cout << "0" << minutos; 
    }
    
    if(segundos <= 9){ 
        cout << ":0" << segundos ; 
    }
    if(segundos > 9){ 
        cout << ":" << segundos ; 
    }
 
}