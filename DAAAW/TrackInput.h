#ifndef TRACKINPUT
# define TRACKINPUT
#define _CRT_SECURE_NO_WARNINGS
typedef struct  Tracks;

//외부파일입력
struct Tracks FileIn();

//직접입력 
struct Tracks TrackIn();
#endif

void InputHelp();
void textcolor(int colorNum);

void MusicEdit(char* music);
int ArrPoint(char* music);
// 
// 
//외부파일출력