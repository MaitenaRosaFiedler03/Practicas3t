
//clase tiempo, se utiliza para la duraciòn de las canciones 
class Tiempo{
    private: 
        int minutos; 
        int segundos; 

    public: 

    /**
     * @brief constructor de un objeto Tiempo 
     * 
     */
    Tiempo();

    /**
     * @brief Destructor de un objeto Tiempo 
     * 
     */
    ~Tiempo();

    /**
     * @brief Constructor por copia de un objeto tiempo
     * 
     * @param minutos , nuevo valor que tomarà el atributo minutos del objeto que llama al mètodo
     * @param segundos , nuevo valor que tomarà el atributo segundos del objeto que llama al mètodo
     */
    Tiempo(const int minutos, const int segundos);

    /**
     * @brief Establece el valor del atributo segundos del objeto que llama la funciòn 
     * 
     * @param segundos  nuevo valor que tomarà el atributo segundos del objeto que llama al mètodo
     */
    void setSegundos(const int segundos);

    /**
     * @brief Set the Minutos object
     * 
     * @param minutos 
     */
    void setMinutos(const int minutos);

    /**
     * @brief Get the Minutos object
     * 
     * @return int 
     */
    int getMinutos() const ;

    /**
     * @brief Get the Segundos object
     * 
     * @return int 
     */
    int getSegundos() const;

    /**
     * @brief Transforma lo valores de un objeto tiempo en formato de tiempo 00:00 , donde 
     * segundos < 60 && minutos < 60
     * 
     * @return Tiempo devuelve el tiempo en el formato 
     */
    void convertirTiempo();
  
};


Tiempo::Tiempo(){

    if(debug==true)
        cout << DEBUG <<  "Se invoca al Constructor Tiempo." << "La dirección de this es: " << this << DEFAULT << endl;

    this->segundos=0;
    this->minutos=0;
}
Tiempo::~Tiempo (){
    if(debug==true)
    cout << DEBUG <<  "Se invoca al Destructor del Tiempo." << "La dirección de this es: " << this << DEFAULT << endl;

}
Tiempo::Tiempo(const int minutos, const int segundos){

    if(debug==true)
     cout << DEBUG <<  "Se invoca al Constructor por copia Tiempo."
         << "La dirección de this es: " << this << DEFAULT << endl;

    this->segundos=segundos;
    this->minutos=minutos;
}
void Tiempo::setSegundos(const int segundos){

    if(debug==true)
        cout << DEBUG << "Estableciendo segundos"  << "La dirección de this es: " << this << RESET << endl;

    this->segundos=segundos;
}
int Tiempo::getSegundos()const{
    return this->segundos;
}
void Tiempo::setMinutos(const int minutos){

    if(debug==true)
        cout << DEBUG << "Estableciendo minutos" << "La dirección de this es: " << this << RESET << endl;


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