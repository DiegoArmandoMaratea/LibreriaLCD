#ifndef lcd_h
#define lcd_h

void lcd_init();
void ClearDisplay();
void lcd_ReturnHome();
void lcd_EntryModSet(int ID, int S);
void lcd_FuctionSet (int DL, int N, int F);
void lcd_CursorOrDisplayShift (int SC, int RL);
void lcd_DisplayOn/OffControl (int D, int B, int C);
void lcd_SetCGRAMAddress (int AC5, int AC4, int AC3, int AC2, int AC1, int AC0);
void lcd_WhiteDatatoRAM (int D7, int D6, int D5, int D4, int D3, int D2, int D1, int D0);
void lcd_ReadDatafromRAM (int D7, int D6, int D5, int D4, int D3, int D2, int D1, int D0);
void lcd_ReadBusyFlag (int BF, int AC6, int AC5, int AC4, int AC3, int AC2, int AC1, int AC0);
