#include <iostream>
using namespace std;

class Tiempo{
    private: 
        int minutos; 
        int segundos; 

    public: 

    /**
     * @brief constructor de un objeto Tiempo 
     * 
     */
    Tiempo();

    /**
     * @brief Destructor de un objeto Tiempo 
     * 
     */
    ~Tiempo();

    /**
     * @brief Constructor por copia de un objeto tiempo
     * 
     * @param minutos , nuevo valor que tomarà el atributo minutos del objeto que llama al mètodo
     * @param segundos , nuevo valor que tomarà el atributo segundos del objeto que llama al mètodo
     */
    Tiempo(const int minutos, const int segundos);

    /**
     * @brief Establece el valor del atributo segundos del objeto que llama la funciòn 
     * 
     * @param segundos  nuevo valor que tomarà el atributo segundos del objeto que llama al mètodo
     */
    void setSegundos(const int segundos);

    /**
     * @brief Set the Minutos object
     * 
     * @param minutos 
     */
    void setMinutos(const int minutos);

    /**
     * @brief Get the Minutos object
     * 
     * @return int 
     */
    int getMinutos() const ;

    /**
     * @brief Get the Segundos object
     * 
     * @return int 
     */
    int getSegundos() const;

    /**
     * @brief Transforma lo valores de un objeto tiempo en formato de tiempo 00:00 , donde 
     * segundos < 60 && minutos < 60
     * 
     * @return Tiempo devuelve el tiempo en el formato 
     */
    void convertirTiempo();

    /**
     * @brief 
     * 
     * @param t 
     */
    void operator=(const Tiempo &t);

    /**
     * @brief 
     * 
     * @param flujo 
     * @param t 
     * @return istream& 
     */
    friend istream& operator>>(istream &flujo,  Tiempo &t);

    ostream& operator<<(ostream &flujo, const Tiempo &t)
};