#ifndef FORWINDOW
# define FORWINDOW
#define _CRT_SECURE_NO_WARNINGS


void textcolor(int colorNum);
int MusicCursor(char* music, int* Oc, int* HowLong);
int SelectProcess();
int PrintNotSelect(int x, int y);
int PrintSelect(int x, int y);
int Selectshow();
int ModselectCursor();
void goto_xy(int x, int y);
#endif
