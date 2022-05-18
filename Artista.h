
#include <iostream>
#include <iomanip>
using namespace std;

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
        void setActivado(bool nuevo);

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
        void setCancionesArtista(const Cancion* nueva);

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
        Artista(const int &i, const string &nuevo, Cancion* c[], const int &a);

        /**
         * @brief Get the Util Canciones Creadas object
         * 
         * @return int 
         */
        int getUtilCancionesCreadas();

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

        friend istream& operator>>(istream&, const Artista&);

     

        

};
