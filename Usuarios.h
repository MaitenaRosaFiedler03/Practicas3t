
#ifndef Usuarios_H
#define Usuarios_H
#include <iostream>
#include <iomanip>
using namespace std;
class Usuario{
    private:

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
        Usuario(const Usuario&);

        /**
         * @brief Construct a new Usuario object
         * 
         */
        Usuario(const int&, const bool&, const string&, const string&);

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
        void setIDUsuario(const unsigned int&);

        /**
         * @brief Set the Activado object
         * 
         */
        void setActivado(const bool&);

        /**
         * @brief Set the Login object
         * 
         */
        void setLogin(const string&);

        /**
         * @brief 
         * 
         */
        void setPassword(const string&);

        /**
         * @brief 
         * 
         * @return int 
         */
        int getIDUsuario();

        /**
         * @brief Get the Activado object
         * 
         * @return true 
         * @return false 
         */
        bool getActivado();

        /**
         * @brief Get the Login object
         * 
         * @return string 
         */
        string getLogin();

        /**
         * @brief Get the Password object
         * 
         * @return string 
         */
        string getPassword();



};
#endif
