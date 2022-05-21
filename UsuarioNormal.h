#ifndef USUARIOCOMUN_H
#define USUARIOCOMUN_H
#include <iostream>
#include "Usuarios.h"
#include "Cancion.h"
#include "Playlist.h"
using namespace std;

class Usuario_comun : public Usuario{

    private:

        Cancion** canciones_usuario;
        int util_canciones_escuchadas;
        Playlist* playlists_usuario;
        int util_playlists_usuario;

        /**
         * @brief Construct a new resize Vector Canciones object
         * 
         * @param DIM_NUEVA 
         */
        resizeVectorCanciones(const int DIM_NUEVA);

        /**
         * @brief Construct a new resize Vector Playlist object
         * 
         * @param DIM_NUEVA 
         */
        resizeVectorPlaylist(const int DIM_NUEVA);

    public: 

        /**
         * @brief Construct a new Usuario_comun object
         * 
         */
        Usuario_comun();

        /**
         * @brief Construct a new Usuario_comun object
         * 
         * @param c 
         */
        Usuario_comun(const Usuario_comun &c);

        /**
         * @brief Destroy the Usuario_comun object
         * 
         */
        ~Usuario_comun();

        /**
         * @brief 
         * 
         */
        void agregarCancionAUsuario(Cancion* cancion);

        /**
         * @brief 
         * 
         */
        void eliminarCancionDeUsuario(const int cancion);

        /**
         * @brief 
         * 
         */
        void agregarPlaylistAUsuario(const Playlist &p);

        /**
         * @brief 
         * 
         * @param play 
         */
        void eliminarPlaylistDeUsuario(const int play);

        /**
         * @brief Set the Util Playlist Usuario object
         * 
         * 
         * @param util 
         */
        void setUtilPlaylistUsuario(const int util);

        /**
         * @brief Get the Cancion Usuario object
         * 
         * @param valor 
         * @return Cancion* 
         */
        Cancion* getCancionUsuario(const int valor) const;

        /**
         * @brief Get the Util Canciones Usuario object
         * 
         * @return int 
         */
        int getUtilCancionesUsuario() const ;

        /**
         * @brief Get the Playlist Usuario object
         * 
         * @param i 
         * @return Playlist 
         */
        Playlist getPlaylistUsuario(const int i)const ;

        /**
         * @brief Get the Util Playlist Usuario object
         * 
         * @return int 
         */
        int getUtilPlaylistUsuario()const;

        /**
         * @brief Get the Util Playlist Usuario object
         * 
         * @return int 
         */
        int getUtilPlaylistUsuario()const; 

        
};
#endif