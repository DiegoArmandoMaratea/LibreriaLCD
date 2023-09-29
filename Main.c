#include "Teclado.h"
#include "MKL25Z4.h"
#include "string.h"

#define LONGITUD 5
int i;
char Contraseña[LONGITUD]={'1','7','1','4'};
char ContraseñaRecibida[i];
 int main(){
    TecladoConf();
    while(1){
        char boton = TecladoLec();
        
        for(i=0; i<LONGITUD; i++){
            char ContraseñaRecibida[i]= boton;
        }
    strncmp(Contraseña, ContraRecibida,LONGITUD);
    }
}