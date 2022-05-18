#include <iostream>
using namespace std;

#define RESET   "\033[0m"
#define DEFAULT   "\033[0m"        
#define RED    "\033[31m"      /*RED*/
#define GREEN   "\033[32m"      /*MENSAJES AL USUARIO*/ 
#define YELLOW  "\033[33m"      /*MENSAJE DE ERROR*/
#define BLUE    "\033[34m"      /*MENSAJE DE EXITO*/

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

class Cancion{
    private:
        unsigned int idCancion;
        string nombre;  
        int util_artista;
        Tiempo duracion;
        int total_reproducciones;
        bool activo;
        Artista** v_Artista;

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
        /**
         * @brief Get the Activo object
         * 
         * @return true 
         * @return false 
         */
        bool getActivo()const ;

        /**
         * @brief Set the Activo object
         * 
         * @param activo 
         */
        void setActivo(const bool activo);

        /**
         * @brief Set the Util artista object
         * 
         * @param nueva 
         */
        void setUtil_artista(const int nueva);

        /**
         * @brief Get the Util artista object
         * 
         * @return int 
         */
        int getUtil_artista()const;

        /**
         * @brief 
         * 
         * @param p 
         */
         void operator=(const Cancion &c);

        void resize(int dim_nueva);
};
class Artista{

    private:
        unsigned int idArtista;
        bool activado;
        string nombre;
        int util_canciones;
        Cancion** canciones;

        /**
         * @brief Set the Util Canciones Creadas object
         * 
         * @param total 
         */
        void setUtilCancionesCreadas(const int &total);

        /**
         * @brief 
         * 
         * @param DIM_NUEV 
         */
        void resize(const int &DIM_NUEV);

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
         * @brief Construct a new Artista object
         * 
         */
        Artista(const Artista &a);

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

        /**
         * @brief Get the Activado object
         * 
         * @return true 
         * @return false 
         */
        bool getActivado()const;

        /**
         * @brief Set the Activado object
         * 
         * @param nuevo 
         */
        void setActivado(const bool nuevo);

        /**
         * @brief Get the Canciones Artista object
         * 
         * @return Cancion 
         */
        Cancion* getCancionesArtista()const ;

        /**
         * @brief Set the Canciones Artista object
         * 
         * @param nueva 
         */
        void setCancionesArtista(const Cancion* nueva, int i);

        /**
         * @brief 
         * 
         * @param Cancion 
         */
        void eliminarCancionDeArtista(const int &Cancion);

        /**
         * @brief Construct a new Artista object
         * 
         * @param i 
         * @param nuevo 
         * @param c 
         * @param i 
         */
        Artista(const int &i, const string &nuevo, Cancion** c, const int &a);

        /**
         * @brief Get the Util Canciones Creadas object
         * 
         * @return int 
         */
        int getUtilCancionesCreadas()const;

        /**
         * @brief 
         * 
         * @return Artista& 
         */
        Artista& operator=(const Artista&);

        /**
         * @brief 
         * 
         * @return ostream& 
         */
        friend ostream& operator<<(ostream&, const Artista&);

        /**
         * @brief 
         * 
         * @return istream& 
         */
        friend istream& operator>>(istream&, const Artista&);

};

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
int Cancion::setUtil_artista(const int nueva){
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
Artista* Cancion::getArtista(int i) const{
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

    Artista* a=new Artista;
    Tiempo t;
    t.setMinutos(0);
    t.setSegundos(0);

    a->setIdArtista(0);
    a->setNombreArtista("NULL");

    if(debug==true)
    cout << RED <<  "Se invoca al Constructor Cancion."
         << "La dirección de this es: " << this << DEFAULT << endl;

    this->setIdCancion(0);
    this->setNombreCancion("NULL");
    this->setDuracion(t);

     this->v_Artista  =new Artista* [];

     for (int i=0; i< this->getUtil_artista();i++){
         this->v_Artista[i]=a;
     }
    this->setArtista(0,0);

void Cancion::resize(int dim_nueva){

    Artista *nuevo= 0;
     
    nuevo=  =new Artista* [];
    
    if(nuevo == 0){
        cerr << "No hay espacio suficiente. Se terminará la ejecución del programa." << endl;
        exit(-1);
    }
    else 
    cout << GREEN << "Vector creado correctamente.." << RESET << endl;
    
    //se inicializa el nuevo vector a cero 

    for(int i=0; i < dim_nueva +1; i++){
        nuevo[i]=0.0;
         
        //cout << "(resise(inicializaciòn))nuevo ["  <<  i << "]: "  << nuevo[i] << endl; 
    }
    
    //si la nueva dimensiòn es menor que la dimension actual -1 (el grado maximo del polinomio)
    if(dim_nueva < this ->getUtil_Artista()){
       
        for(int i=0; i < dim_nueva +1; i++){
            
            nuevo[i]= this->getArtista(i);
            // cout << "(resise(dim<gradoM))nuevo ["  <<  i << "]: "  << nuevo[i] << endl; 
           
        }        

    }

    //si la nueva dimensiòn es mayor que la dimensiòn -1 (el grado maximo del polinomio )
    else if(dim_nueva >= this->getUtil_artista()){
       // cout << "this->getMaxGrado() +1 " << this->getMaxGrado() << endl;
        //se copian los valores hasta el grado maximo (todos los valores del vector )
        for(int i=0; i < this->getMaxGrado() +1; i++){
            nuevo[i]= this-> getCoeficiente(i);
           //cout << "(resise(dim_nueva>grado max))nuevo ["  <<  i << "]: "  << nuevo[i] << endl;
        
        }
    }
    //se elimina el antiguo vector 
    delete [] this->v_Artistas; 

    //se establece el nuevo grado maximo 
    
    //se iguala la direcciòn de memoria del vector dinamico coef con el nuefvo vector  
    this-> v_Artista = nuevo;

}

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
Artista::Artista(){
    if(debug==true)
    cout << RED <<  "Se invoca al Constructor Artista."
         << "La dirección de this es: " << this << DEFAULT << endl;

    this->setIdArtista(0);
    this->setNombreArtista("NULL");
    this->setUtilCancionesCreadas(0);
    this->canciones = new* Cancion [1];

    if (this->canciones== 0){
        cerr << "NO hay memoria disponible... Cerrando programa" << endl;
        exit(-1);
    }

Artista:: ~Artista(){

    if(debug==true)
    cout << RED <<  "Se invoca al Destructor Artista."
         << "La dirección de this es: " << this << DEFAULT << endl;

    this->setIdArtista(0);
    this->setNombreArtista(0);
    this->setUtilCancionesCreadas(0);
    this->setCancionesArtista(0);
    delete this->canciones;

}
Artista::Artista(const Artista &a){
    if(debug==true)
    cout << RED <<  "Se invoca al Constructor por copia Artista."
         << "La dirección de this es: " << this << DEFAULT << endl;

    this->setIdArtista(a.getIdArtista());
    this->setNombreArtista(a.getNombreArtista());
    this->setUtilCancionesCreadas(a.getUtilCancionesCreadas);
    this->canciones = new* Cancion [a.getUtilCancionesCreadas+1];

    if (this->canciones == 0){
        cerr << "NO hay memoria disponible... Cerrando programa" << endl;
        exit(-1);
    }

    for(int i=0; i <= this->getUtilCancionesCreadas() ; i++)
       this->canciones[i]=a.getCancionesArtista(i);
}
unsigned int Artista::getIdArtista()const {
    return this->idArtista;
}
void Artista::setIdArtista(const unsigned int nuevo){

    if(debug==true)
        cout << RED << "Estableciendo idArtista" << "La dirección de this es: " << this << RESET << endl;

    this->idArtista=nuevo.;
}
string Artista::getNombreArtista()const {
    return this->nombre;
}
void Artista::setNombreArtista(const string nuevo){

    if(debug==true)
        cout << RED << "Estableciendo el nombre del artista" << "La dirección de this es: " << this << RESET << endl;

    this->nombre=nuevo;
}
bool Artista::getActivo()const {
    return this->activado;
}
void Artista::setActivo(const bool nuevo){

    if(debug==true)
        cout << RED << "Estableciendo el activado" << "La dirección de this es: " << this << RESET << endl;


    this->activado=nuevo;
}
void Artista::setUtilCancionesCreadas(const int &total){
   
    if(debug==true)
        cout << RED << "Estableciendo la util de las canciones creadas" << "La dirección de this es: " << this << RESET << endl;

    this->util_canciones=total;
}

Cancion* Artista::getCancionesArtista()const {
    return this->canciones;
}
void Artista::setCancionesArtista(const Cancion* nuevo, int i){

    if(debug==true)
        cout << RED << "Estableciendo la cancion en artista" << "La dirección de this es: " << this << RESET << endl;


    this->canciones[i]=nuevo;
}
void Artista::eliminarCancionDeArtista(const int &cancion){
    
}
Artista:: Artista(const int &id, const string &nuevo, Cancion** c, const int &a){
    if(debug==true)
    cout << RED <<  "Se invoca al Constructor por copia Artista."
         << "La dirección de this es: " << this << DEFAULT << endl;

    this->setIdArtista(id);
    this->setNombreArtista(nuevo);
    this->setUtilCancionesCreadas(a);
    this->canciones = new* Cancion [a+1];

    if (this->canciones == 0){
        cerr << "NO hay memoria disponible... Cerrando programa" << endl;
        exit(-1);
    }

    for(int i=0; i <= this->getUtilCancionesCreadas() ; i++)
       this->canciones[i]=c.getCancionesArtista(i);
}

