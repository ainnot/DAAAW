#ifndef TRACKINPUT
# define TRACKINPUT
#define _CRT_SECURE_NO_WARNINGS
typedef struct  Tracks;

//�ܺ������Է�
struct Tracks FileIn();

//�����Է� 
struct Tracks TrackIn();
#endif

void InputHelp();
void textcolor(int colorNum);

void MusicEdit(char* music);
int ArrPoint(char* music);
// 
// 
//�ܺ��������