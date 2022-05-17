#include <iostream>
#include <iomanip>
using namespace std;

#define RESET   "\033[0m"
#define DEFAULT   "\033[0m"        
#define DEBUG    "\033[31m"      /*DEBUG*/
#define GREEN   "\033[32m"      /*MENSAJES AL USUARIO*/ 
#define YELLOW  "\033[33m"      /*MENSAJE DE ERROR*/
#define BLUE    "\033[34m"      /*MENSAJE DE EXITO*/

bool debug=true;

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
class Artista{

    private:
        unsigned int idArtista;
        string nombre;
    public:
        /**
         * @brief Construct a new Artista object
         * 
         */
        Artista();
        /**
         * @brief Destroy the Artista object
         * 
         */
        ~Artista();
        /**
         * @brief Get the Id Artista object
         * 
         * @return unsigned int 
         */
        unsigned int getIdArtista() const ;

        /**
         * @brief Set the Id Artista object
         * 
         * @param nuevo 
         */
        void setIdArtista(const unsigned int nuevo);

        /**
         * @brief Get the Nombre Artista object
         * 
         * @return string 
         */
        string getNombreArtista() const ;
        /**
         * @brief 
         * 
         */
        void setNombreArtista(const string nuevo);
};
class Cancion{
    private:
        unsigned int idCancion;
        string nombre;  
        Artista** v_Artista;
        Tiempo duracion;
        int total_reproducciones;
        bool activo;


    public:

        /**
         * @brief Construct a new Cancion object
         * 
         */
        Cancion();

        /**
         * @brief Destroy the Cancion object
         * 
         */
        ~Cancion();
        /**
         * @brief Get the Id Cancion object
         * 
         * @return unsigned int 
         */
        unsigned int getIdCancion() const ;

        /**
         * @brief Set the Id Cancion object
         * 
         * @param nuevo 
         */
        void setIdCancion(const unsigned int nuevo );

        /**
         * @brief Get the Nombre Cancion object
         * 
         * @return string 
         */
        string getNombreCancion() const ;

        /**
         * @brief Set the Nombre Cancion object
         * 
         * @param nuevo 
         */
        void setNombreCancion(const string nuevo);

        /**
         * @brief Get the Artista object
         * 
         * @param i 
         * @return Artista 
         */
        Artista* getArtista(int i) const ;

        /**
         * @brief Set the Artista object
         * 
         * @param a 
         */
        void setArtista( Artista* a, int i);

        /**
         * @brief Get the Duracion object
         * 
         * @return Tiempo 
         */
        Tiempo getDuracion() const;

        /**
         * @brief Set the Duracion object
         * 
         * 
         * @param t 
         */
        void setDuracion(const Tiempo &t);

        /**
         * @brief Get the Total Repro object
         * 
         * @return int 
         */
        int getTotalRepro() const ;

        /**
         * @brief Set the Total Repro object
         * 
         * @param nuevo 
         */
        void setTotalRepro(const int nuevo); 

        bool getActivo()const ;

        void setActivo(const bool activo);
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
unsigned int Artista::getIdArtista()const {
    return this->idArtista;
}
void Artista::setIdArtista(const unsigned int nuevo){

    if(debug==true)
        cout << DEBUG << "Estableciendo idArtista" << "La dirección de this es: " << this << RESET << endl;


    this->idArtista=nuevo;
}
string Artista::getNombreArtista()const {
    return this->nombre;
}
void Artista::setNombreArtista(const string nuevo){

    if(debug==true)
        cout << DEBUG << "Estableciendo el nombre del artista" << "La dirección de this es: " << this << RESET << endl;

    this->nombre=nuevo;
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
Cancion (){
    cout << DEBUG <<  "Se invoca al Constructor Cancion."
         << "La dirección de this es: " << this << DEFAULT << endl;

         
}
int main (){

   
}
	

