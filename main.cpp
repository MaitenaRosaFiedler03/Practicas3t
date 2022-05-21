#include <iostream>
#include <string>
#include "Cancion.h"
#include "Artista.h"
#include "vista.h"
#include "Usuarios.h"
#include "UsuarioNormal.h"
#include "Playlist.h"
using namespace std;

int main (){
    
    int opcion ; 
    Cancion c,b; 
    Artista a,e;

    do{
        cout << "Caso 1 (creacion, igualacion de artista)" << endl; 
        cout << "Caso 2 (creacion igualacion de cancion  )" << endl; 
        cin >> opcion ; 

        switch (opcion) {
            
            case 1: 
                    cout << "Artista " << endl; 
                    a.setActivado(true);
                    cin >> a;
                    cout << a << endl; 
                    e=a;
                    cout << "artista e " << endl; 
                    cout << e << endl;  

            break; 

            case 2: 
                cout << "Cancion---" << endl; 
                c.setActivo(true);
                c.setArtista(&a,0);
                cin >> c ;
                cout << c << endl; 

                b=c;
                cout << "cancion b----" << endl; 

                cout << b << endl; 

            break; 
        }
    }while(opcion != -1);

}