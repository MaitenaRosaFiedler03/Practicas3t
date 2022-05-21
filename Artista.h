
#ifndef ARTISTA_H
#define ARTISTA_H
#include <iostream>
#include <iomanip>

using namespace std;
class Cancion;

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
        void setUtilCancionesCreadas(const int total);

        /**
         * @brief 
         * 
         * @param DIM_NUEV 
         */
        void resize(const int DIM_NUEV);

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
         * @param i 
         * @return Cancion* 
         */
        Cancion* getCancionArtista(const int i) const;
       
        /**
         * @brief Set the Canciones Artista object
         * 
         * @param nueva 
         */
        void setCancionesArtista(Cancion* nueva, int i);

        /**
         * @brief 
         * 
         * @param Cancion 
         */
        void eliminarCancionDeArtista(const int Cancion);

        /**
         * @brief Construct a new Artista object
         * 
         * @param i 
         * @param nuevo 
         * @param c 
         * @param i 
         */
        Artista(const int id, const string nuevo, Cancion* c, const int a);

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
        void operator=(const Artista &i);

        /**
         * @brief 
         * 
         * @return ostream& 
         */
        friend ostream& operator<<(ostream &flujo, const Artista &a);

        /**
         * @brief 
         * 
         * @return istream& 
         */
        friend istream& operator>>(istream &flujo,  Artista &a);   
        
        /**
         * @brief 
         * 
         */
        void printV_Canciones() const ;
};
#endif