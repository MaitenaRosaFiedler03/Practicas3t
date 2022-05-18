#include <iostream>
#include "Artista.h"
#include "Tiempo.h"
using namespace std;
class Cancion{
    private:
        unsigned int idCancion;
        string nombre;  
        Artista** v_Artista[];
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

        /**
         * @brief 
         * 
         * @param p 
         */
         void operator=(const Cancion &c);
};