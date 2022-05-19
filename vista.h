
#ifndef Vista_H
#define Vista_H
#include <iostream>
#include <iomanip>
#include "Usuarios.h"
#include "Cancion.h"
class Cancion;
class Artista;
class Usuario;

using namespace std;
class Vista{
    private:
        Usuario* usuarios_sistema;
        int util_usuarios_sistema;
        Cancion* canciones_sistema;
        int util_canciones_sistema;
        Artista* artistas_sistema;
        int util_artistas_sistema;

    public:
        /**
         * @brief Construct a new Vista object
         * 
         */
        Vista();

        /**
         * @brief Destroy the Vista object
         * 
         */
        ~Vista();
        /**
         * @brief Get the Usuarios sistema object
         * 
         * @return Usuario* 
         */
        Usuario getUsuarios_sistema(int i)const;

        /**
         * @brief Set the Usuarios sistema object
         * 
         */
        void setUsuarios_sistema(const Usuario &user, int i);

        /**
         * @brief Get the Util usuarios sistema object
         * 
         * @return int 
         */
        int getUtil_usuarios_sistema()const ;

        /**
         * @brief Set the Util usuarios sistema object
         * 
         * @param usuarios 
         */
        void setUtil_usuarios_sistema(const int &usuarios);

        /**
         * @brief Get the Canciones Sistema object
         * 
         * @return Cancion* 
         */
        Cancion getCancionesSistema(int i)const;

        /**
         * @brief Set the Canciones Sistema object
         * 
         * @param c 
         * @param i 
         */
        void setCancionesSistema(const Cancion &c, int i);

        /**
         * @brief Get the Util Canciones Sistema object
         * 
         * @return int 
         */
        int getUtilCancionesSistema() const ;

        /**
         * @brief Set the Util Canciones Sistema object
         * 
         * @param i 
         */
        void setUtilCancionesSistema(const int i);

        /**
         * @brief Get the Artista Sistema object
         * 
         * @return Artista* 
         */
        Artista getArtistaSistema(int i)const;

        /**
         * @brief Set the Artista Sistema object
         * 
         * @param a 
         * @param i 
         */
        void setArtistaSistema(const Artista &a, int i);

        /**
         * @brief Get the Util Artistas Sistema object
         * 
         * @return int 
         */
        int getUtilArtistasSistema()const ;

        /**
         * @brief Set the Util Artistas Sistema object
         * 
         */
        void setUtilArtistasSistema(const int util);


};
#endif