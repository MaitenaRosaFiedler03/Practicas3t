
#include <iostream>
#include <iomanip>
#include <string>
#include "Cancion.h"
class Playlist{
    private:
        unsigned int idPlaylist;
        string nombre;
        Cancion** canciones;
        int util_v_canciones;
        Tiempo duracion;


        void resize(const int &NUEVA_DIM);

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
        Playlist(const Playlist&);

        /**
         * @brief 
         * 
         * @param int 
         */
        void setIDPlaylist(const unsigned int&);

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
        void setNombrePlaylist(const string&);

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
        Cancion* getCancionPlaylist(const int &cancion);

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
        int getUtilCancionesPlaylist();

        /**
         * @brief Get the Duracion Playlist object
         * 
         * @return Tiempo 
         */
        Tiempo getDuracionPlaylist();


        /**
         * @brief 
         * 
         * @return Playlist& 
         */
        Playlist& operator=(const Playlist&);

        /**
         * @brief Set the Duracion Playlist object
         * 
         * @param t 
         */
        void setDuracionPlaylist(const Tiempo &t);



};