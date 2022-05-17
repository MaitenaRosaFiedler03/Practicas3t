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
Artista::Artista(){
    if(debug==true)
    cout << DEBUG <<  "Se invoca al Constructor Artista."
         << "La dirección de this es: " << this << DEFAULT << endl;

    this->setIdArtista(0);
    this->setNombreArtista("NULL");
}
Artista:: ~Artista(){
    if(debug==true)
    cout << DEBUG <<  "Se invoca al Destructor Artista."
         << "La dirección de this es: " << this << DEFAULT << endl;

    this->setIdArtista(0);
    this->setNombreArtista("NULL");
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