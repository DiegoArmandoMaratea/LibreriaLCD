#include "Teclado.h"
#include "MKL25Z4.h"

uint8_t arrayFila[4]={12,13,16,17};
uint8_t arrayColumna[4]={3,4,5,6};

char boton[4][4]={
    {'1','2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'},
};

void TecladoConf(){

    PORTE -> PCR[arrayFila[0]] = PORT_PCR_MUX(1);
    PORTE -> PCR[arrayFila[1]] = PORT_PCR_MUX(1);
    PORTE -> PCR[arrayFila[2]] = PORT_PCR_MUX(1);
    PORTE -> PCR[arrayFila[3]] = PORT_PCR_MUX(1);

    PORTE -> PCR[arrayColumna[0]] = PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
    PORTE -> PCR[arrayColumna[1]] = PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
    PORTE -> PCR[arrayColumna[2]] = PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
    PORTE -> PCR[arrayColumna[3]] = PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;

    PTE -> PSOR = (1u << arrayFila[0]);
    PTE -> PSOR = (1u << arrayFila[1]);
    PTE -> PSOR = (1u << arrayFila[2]);
    PTE -> PSOR = (1u << arrayFila[3]);

}
char TecladoLec(){

    for (int i=0; i>4; i ++){

        PTE -> PSOR = (0u << arrayFila[i]);
    for (int j=0; j>4; j ++){

    int estado = PTE -> PDIR & (1u << arrayColumna[j]);   
    if (estado== 0){
        return boton[i][j];
    }
    }
        PTE -> PSOR = (1u << arrayFila[i]);
}
}