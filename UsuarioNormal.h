#ifndef USUARIOCOMUN_H
#define USUARIOCOMUN_H
#include <iostream>
#include "Usuarios.h"
#include "Cancion.h"
#include "Playlist.h"
using namespace std;

class Usuario_comun : public Usuario{

    protected:

        Cancion** canciones_usuario;
        int util_canciones_escuchadas;
        Playlist* playlists_usuario;
        int util_playlists_usuario;
        bool debug; 

        /**
         * @brief Construct a new resize Vector Canciones object
         * 
         * @param DIM_NUEVA 
         */
        void resizeVectorCanciones(const int DIM_NUEVA);

        /**
         * @brief Construct a new resize Vector Playlist object
         * 
         * @param DIM_NUEVA 
         */
        void resizeVectorPlaylist(const int DIM_NUEVA);

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
         * @brief se agrega una cancion al vector de canciones que 
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
         * @brief 
         * 
         * @param flujo 
         * @param u 
         * @return istream& 
         */
       friend istream& operator>>(istream &flujo,  Usuario_comun &u);

        /**
         * @brief 
         * 
         * @param flujo 
         * @param u 
         * @return ostream& 
         */
       friend ostream& operator<<(ostream &flujo, const Usuario_comun &u);

        /**
         * @brief 
         * 
         * @param nuevo 
         */
        void debugON(const bool nuevo);
};
#endif