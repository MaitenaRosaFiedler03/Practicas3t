class Cancion{
    private:
        unsigned int idCancion;
        string nombre;  
        Artista** v_Artista;
        int util_artista;
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
};

void Cancion::getUtil_artista() const {
    this->getUtil_artista;
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
string Cancion::getNombreCancion(){
    return this->nombre;
}
void Cancion::
Cancion::Cancion(){
    if(debug==true)
    cout << DEBUG <<  "Se invoca al Constructor Cancion."
         << "La dirección de this es: " << this << DEFAULT << endl;

    this->setIdCancion(0);
    this->setNombreCancion("NULL");
    this->setDuracion(0);
    this->setArtista(0,0);

    for(int i=0; i < g)
}