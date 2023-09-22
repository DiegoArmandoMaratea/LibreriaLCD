#include "Lcd.h"
#include "MKL25Z4.h"
    #define RS 1
    #define RW 2
    #define DB7 3
    #define DB6 4
    #define DB5 5
    #define DB4 6
    #define DB3 7
    #define DB2 8
    #define DB1 9
    #define DB0 10
//ptc0,ptc 3 4 5 6 7, ptc12 13 16 17
void lcd_init(){
    PORTE -> PCR[RS] = PORT_PCR_MUX(1);
    PORTE -> PCR[RW] = PORT_PCR_MUX(1);
    PORTE -> PCR[DB7] = PORT_PCR_MUX(1);
    PORTE -> PCR[DB6] = PORT_PCR_MUX(1);
    PORTE -> PCR[DB5] = PORT_PCR_MUX(1);
    PORTE -> PCR[DB4] = PORT_PCR_MUX(1);
    PORTE -> PCR[DB3] = PORT_PCR_MUX(1);
    PORTE -> PCR[DB2] = PORT_PCR_MUX(1);
    PORTE -> PCR[DB1] = PORT_PCR_MUX(1);
    PORTE -> PCR[DB0] = PORT_PCR_MUX(1);

}

void ClearDisplay(){
    PTE -> PSOR = (0u<<RS);
    PTE -> PSOR = (0u<<RW);
    PTE -> PSOR = (0u<<DB7);
    PTE -> PSOR = (0u<<DB6);
    PTE -> PSOR = (0u<<DB5);
    PTE -> PSOR = (0u<<DB4);
    PTE -> PSOR = (0u<<DB3);
    PTE -> PSOR = (0u<<DB2);
    PTE -> PSOR = (0u<<DB1);
    PTE -> PSOR = (1u<<DB0);

}

void lcd_ReturnHome(){
    PTE -> PSOR = (0u<<RS);
    PTE -> PSOR = (0u<<RW);
    PTE -> PSOR = (0u<<DB7);
    PTE -> PSOR = (0u<<DB6);
    PTE -> PSOR = (0u<<DB5);
    PTE -> PSOR = (0u<<DB4);
    PTE -> PSOR = (0u<<DB3);
    PTE -> PSOR = (0u<<DB2);
    PTE -> PSOR = (1u<<DB1);
    PTE -> PSOR = (0u<<DB0);

}
void lcd_EntryModSet(int ID, int S){

    PTE -> PSOR = (0u<<RS);
    PTE -> PSOR = (0u<<RW);
    PTE -> PSOR = (0u<<DB7);
    PTE -> PSOR = (0u<<DB6);
    PTE -> PSOR = (0u<<DB5);
    PTE -> PSOR = (0u<<DB4);
    PTE -> PSOR = (0u<<DB3);
    PTE -> PSOR = (1u<<DB2);
    PTE -> PSOR = (ID<<DB1);
    PTE -> PSOR = (S<<DB0);
}
void lcd_DisplayOnOffControl (int D, int B, int C){
    PTE -> PSOR = (0u<<RS);
    PTE -> PSOR = (0u<<RW);
    PTE -> PSOR = (0u<<DB7);
    PTE -> PSOR = (0u<<DB6);
    PTE -> PSOR = (0u<<DB5);
    PTE -> PSOR = (0u<<DB4);
    PTE -> PSOR = (1u<<DB3);
    PTE -> PSOR = (D<<DB2);
    PTE -> PSOR = (C<<DB1);
    PTE -> PSOR = (B<<DB0);
}
void lcd_CursorOrDisplayShift (int SC, int RL){
    PTE -> PSOR = (0u<<RS);
    PTE -> PSOR = (0u<<RW);
    PTE -> PSOR = (0u<<DB7);
    PTE -> PSOR = (0u<<DB6);
    PTE -> PSOR = (0u<<DB5);
    PTE -> PSOR = (1u<<DB4);
    PTE -> PSOR = (SC<<DB3);
    PTE -> PSOR = (RL<<DB2);
    PTE -> PSOR = (0u<<DB1);
    PTE -> PSOR = (0u<<DB0);
}
void lcd_FuctionSet (int DL, int N, int F){
    PTE -> PSOR = (0u<<RS);
    PTE -> PSOR = (0u<<RW);
    PTE -> PSOR = (0u<<DB7);
    PTE -> PSOR = (0u<<DB6);
    PTE -> PSOR = (1u<<DB5);
    PTE -> PSOR = (DL<<DB4);
    PTE -> PSOR = (N<<DB3);
    PTE -> PSOR = (F<<DB2);
    PTE -> PSOR = (0u<<DB1);
    PTE -> PSOR = (0u<<DB0);
}
void lcd_SetCGRAMAddress (int AC5, int AC4, int AC3, int AC2, int AC1, int AC0){
    PTE -> PSOR = (0u<<RS);
    PTE -> PSOR = (0u<<RW);
    PTE -> PSOR = (0u<<DB7);
    PTE -> PSOR = (1u<<DB6);
    PTE -> PSOR = (AC5<<DB5);
    PTE -> PSOR = (AC4<<DB4);
    PTE -> PSOR = (AC3<<DB3);
    PTE -> PSOR = (AC2<<DB2);
    PTE -> PSOR = (AC1<<DB1);
    PTE -> PSOR = (AC0<<DB0);
}
void lcd_ReadBusyFlag (int BF, int AC6, int AC5, int AC4, int AC3, int AC2, int AC1, int AC0){
    PTE -> PSOR = (0u<<RS);
    PTE -> PSOR = (1u<<RW);
    PTE -> PSOR = (BF<<DB7);
    PTE -> PSOR = (AC6<<DB6);
    PTE -> PSOR = (AC5<<DB5);
    PTE -> PSOR = (AC4<<DB4);
    PTE -> PSOR = (AC3<<DB3);
    PTE -> PSOR = (AC2<<DB2);
    PTE -> PSOR = (AC1<<DB1);
    PTE -> PSOR = (AC0<<DB0);
}
void lcd_WhiteDatatoRAM (int D7, int D6, int D5, int D4, int D3, int D2, int D1, int D0){
    PTE -> PSOR = (0u<<RS);
    PTE -> PSOR = (1u<<RW);
    PTE -> PSOR = (D7<<DB7);
    PTE -> PSOR = (D6<<DB6);
    PTE -> PSOR = (D5<<DB5);
    PTE -> PSOR = (D4<<DB4);
    PTE -> PSOR = (D3<<DB3);
    PTE -> PSOR = (D2<<DB2);
    PTE -> PSOR = (D1<<DB1);
    PTE -> PSOR = (D0<<DB0);
}
void lcd_ReadDatafromRAM (int D7, int D6, int D5, int D4, int D3, int D2, int D1, int D0){
    PTE -> PSOR = (1u<<RS);
    PTE -> PSOR = (1u<<RW);
    PTE -> PSOR = (D7<<DB7);
    PTE -> PSOR = (D6<<DB6);
    PTE -> PSOR = (D5<<DB5);
    PTE -> PSOR = (D4<<DB4);
    PTE -> PSOR = (D3<<DB3);
    PTE -> PSOR = (D2<<DB2);
    PTE -> PSOR = (D1<<DB1);
    PTE -> PSOR = (D0<<DB0);
}

void lcd_SendCommand(int command){
    
}

void lcd_scrollDisplayRight(){
    lcd_EntryModSet(0 , 1);
}

void lcd_scrollDisplayLeft(){
    lcd_EntryModSet(1 , 1);
}

void lcd_DisplayOnControl(){
    lcd_DisplayOnControl (1, 1, 1);
}

void lcd_DisplayOffControl(){
    lcd_DisplayOffControl (0, 0, 0);
}

void lcd_setCursor(int Fila, int PosColum){
    PosFila[]{0x00, 0x40, 0x14, 0x54};
}
