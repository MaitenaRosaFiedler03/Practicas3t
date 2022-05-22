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
    Tiempo t,d;
    Vista v; 
    cout << "ahaha" << endl; 
    const bool debug=false;
    a.debugON(false);
    e.debugON(false);
    c.debugON(false);
    b.debugON(false);
    d.debugON(false);
    t.debugON(false);
    v.debugON(false);


    do{
        cout << "Caso 1 (creacion, igualacion de artista)" << endl; 
        cout << "Caso 2 (creacion igualacion de cancion  )" << endl; 
        cout << "Caso 3 (creacion igualacion y suma de Tiempo)" <<  endl; 
        cin >> opcion ; 

        switch (opcion) {
            
            case 1: 
                    cout << "Artista " << endl; 
                    cin >> a;
                    cout << a << endl; 
                    e=a;
                    cout << "artista e " << endl; 
                    cout << e << endl;  

            break; 

            case 2: 
                cout << "Cancion---" << endl; 
     
                c.setArtista(&a,0);
             
                cin >> c ;
                cout << c << endl; 

                b=c;
                cout << "cancion b----" << endl; 

                cout << b << endl; 

            break; 

            case 3: 
                cout << "Tiempo " << endl; 

                cin >> t; 

                cout << t << endl;

                cin >> d; 

                cout << d << endl; 

                t= t +d; 

                cout << "t +d = " << t << endl; 
            break; 
        }
    }while(opcion != -1);

}