#include <iostream>
#include <string>
#include "Cancion.h"
#include "Artista.h"
#include "vista.h"
#include "Usuarios.h"
#include "UsuarioNormal.h"
#include "Playlist.h"
using namespace std;

void ArtistasPredeterminados(Vista &v){

    Artista a; 

    //Artista Luis Miguel 
    a.setIdArtista(12345); 
    a.setNombreArtista("Luis Miguel"); 
    v.setArtistaSistema(a, 0); 
    a.setIdArtista(67891);
    
    v.setArtistaSistema(a,0); 

    //Artista WOS 
    a.setIdArtista(67891);
    a.setNombreArtista("WOS");
   // 
    v.setArtistaSistema(a,1);

    v.setUtilArtistasSistema(2);

}
void CancionesPredeterminadas(Vista &v){

    Cancion c; 
    Tiempo t; 
    Artista a; 

    //cancion Luis Miguel
    t.setMinutos(3);
    t.setSegundos(11);
    c.setNombreCancion("Ahora Te Puedes Marchar"); 
    c.setDuracion(t);
    c.setTotalRepro(123456);
    c.setArtista(v.getArtistaSistema(0),0); 

    v.setCancionesSistema(c, 0); 
    a.setCancionesArtista(v.getCancionesSistema(0),0); 

    


    //Cancion WOS
    t.setMinutos(2);
    t.setSegundos(53);
    c.setNombreCancion("ALMA DINAMITA"); 
    c.setDuracion(t);
    c.setIdCancion(98765);
    c.setTotalRepro(213012);
    c.setArtista(v.getArtistaSistema(1),0); 
    
    c.setArtista(v.getArtistaSistema(0),1); 

    c.setUtil_artista(2);

    v.setCancionesSistema(c, 1); 

    a.setCancionesArtista(v.getCancionesSistema(1),0);

    v.setUtilCancionesSistema(2);

}

int main (){
    
    int opcion ; 
    Cancion c,b; 
    Artista a,e;
    Tiempo t,d;
    cout << "a" << endl;
    Vista v; 
    cout << "v" << endl;
  // Usuario* s; 
    Usuario_comun g;
    cout << "d" << endl;
    v.debugON(false);
    cout << "a" << endl;
    ArtistasPredeterminados(v);
    CancionesPredeterminadas(v);

   
    

    do{
        cout << "Caso 1 (creacion, igualacion de artista)" << endl; 
        cout << "Caso 2 (creacion igualacion de cancion  )" << endl; 
        cout << "Caso 3 (creacion igualacion y suma de Tiempo)" <<  endl; 
        cout << "caso 4: imprimir artistas y canciones de sitema " << endl; 
        cout << "caso 5: polimorfismo con usuario  " << endl;  

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

            case 4: 

                cout << "Artista" << endl; 
                a=*(v.getArtistaSistema(0));
                c=*(v.getCancionesSistema(0));
                 cout << a;
                 cout << c; 
            break;

            case 5: 



            break; 
        }
    }while(opcion != -1);

}