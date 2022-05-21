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
    Cancion c; 
    Playlist p;
    Artista a;

   c.setActivo(true);
   a.setActivado(true);
    cin >> c;

    cin >> a;
    c.setArtista(&a,0);


    cout << c << endl;  


}