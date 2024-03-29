
#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <iostream>
#include <iomanip>
#include <string>
#include "Cancion.h"

class Cancion;


class Playlist{
    private:
        unsigned int idPlaylist;
        string nombre;
        Cancion** canciones;
        int util_v_canciones;
        Tiempo duracion;
        bool debug;


        void resize(const int NUEVA_DIM);

    public:
        /**
         * @brief Construct a new Playlist object
         * 
         */
        Playlist();

        /**
         * @brief Destroy the Playlist object
         * 
         */
        ~Playlist();

        /**
         * @brief Construct a new Playlist object
         * 
         */
        Playlist(Playlist &p);

        /**
         * @brief 
         * 
         * @param int 
         */
        void setIDPlaylist(const unsigned int i);

        /**
         * @brief 
         * 
         * @return unsigned int 
         */
        unsigned int getIDPlaylist()const ;

        /**
         * @brief Set the Nombre Playlist object
         * 
         */
        void setNombrePlaylist(const string nueva);

        /**
         * @brief Get the Nombre Playlist object
         * 
         * @return string 
         */
        string getNombrePlaylist() const ;

        /**
         * @brief 
         * 
         * @param c 
         */
        void agregarCancionEnPlaylist(Cancion* c);

        /**
         * @brief Get the Cancion Playlist object
         * 
         * @param cancion 
         * @return Cancion* 
         */
        Cancion* getCancionPlaylist(const int &cancion)const ;

        /**
         * @brief 
         * 
         * @param cancion 
         */
        void eliminarCancionDePlaylist(const int &cancion);

        /**
         * @brief Set the Util Canciones Playlist object
         * 
         * @param nueva 
         */
        void setUtilCancionesPlaylist(const int &nueva);

        /**
         * @brief Get the Util Canciones Playlist object
         * 
         * @return int 
         */
        int getUtilCancionesPlaylist()const;

        /**
         * @brief Get the Duracion Playlist object
         * 
         * @return Tiempo 
         */
        Tiempo getDuracionPlaylist() const ;


        /**
         * @brief 
         * 
         * @return Playlist& 
         */
         void operator=(const Playlist&);

        /**
         * @brief Set the Duracion Playlist object
         * 
         * @param t 
         */
        void setDuracionPlaylist(const Tiempo &t);

        /**
         * @brief 
         * 
         * @param flujo 
         * @param p 
         * @return ostream& 
         */
        friend ostream& operator<<(ostream &flujo, const Playlist &p);
        
        /**
         * @brief 
         * 
         * @param flujo 
         * @param p 
         * @return istream& 
         */
        friend istream& operator>>(istream &flujo,  Playlist &p);

        /**
         * @brief 
         * 
         * @return Tiempo 
         */
        Tiempo calcularDuracionPlaylist();

        /**
         * @brief deja ver los mensajes de debug del sistema 
         * 
         * @param nuevo 
         */
        void debugON(const bool nuevo); 
};      
#endif