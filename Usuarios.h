
#ifndef USUARIOS_H
#define USUARIOS_H
#include <iostream>
#include <iomanip>
using namespace std;
class Usuario{
    protected:

        unsigned int id;
        bool activado;
        string login;
        string password;

    public:

        /**
         * @brief Construct a new Usuario object
         * 
         */
        Usuario();

        /**
         * @brief Construct a new Usuario object
         * 
         */
        Usuario(const Usuario &u);

        /**
         * @brief Construct a new Usuario object
         * 
         */
        Usuario(const int id, const bool activo, const string login , const string contra);

        /**
         * @brief 
         * 
         */
        ~Usuario();

        /**
         * @brief 
         * 
         * @param int 
         */
        void setIDUsuario(const unsigned int id);

        /**
         * @brief Set the Activado object
         * 
         */
        void setActivado(const bool activado);

        /**
         * @brief Set the Login object
         * 
         */
        void setLogin(const string login);

        /**
         * @brief 
         * 
         */
        void setPassword(const string nuevo);

        /**
         * @brief 
         * 
         * @return int 
         */
        unsigned int getIDUsuario() const;

        /**
         * @brief Get the Activado object
         * 
         * @return true 
         * @return false 
         */
        bool getActivado()  const;

        /**
         * @brief Get the Login object
         * 
         * @return string 
         */
        string getLogin()const;

        /**
         * @brief Get the Password object
         * 
         * @return string 
         */
        string getPassword() const ;
        
       
};
#endif
