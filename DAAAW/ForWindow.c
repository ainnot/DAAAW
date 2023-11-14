#include <Windows.h>
#include "ForWindow.h"
#include <stdio.h>
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#include <stdbool.h>
#include "TrackInput.h"

enum ColorType {
    BLACK = 0,
    darkBLUE = 1,	//1
    DarkGreen = 2,	//2
    darkSkyBlue = 3,    //3
    DarkRed = 4,
    DarkPurple = 5,	//5
    DarkYellow = 6,	//6
    GRAY = 7,		//7
    DarkGray = 8,	//8
    BLUE = 9,		//9
    GREEN = 10,		//10
    SkyBlue = 11,	//11
    RED = 12,		//12
    PURPLE = 13,		//13
    YELLOW = 14,		//14
    WHITE = 15		//15
} COLOR;

void goto_xy(int x, int y)
{
	COORD pos={ x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void textcolor(int colorNum) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}




int ModselectCursor()
{
    int x=0, y=23;

    int SelectNum=0;
	// 방향키 입력받기
    char c;
    while (1) {
        if (_kbhit()) {               // 2. while문안에서 키보드 눌렸을 시 if문이 실행된다.
            c = _getch();           // 3. 방향키가 입력됬을 때 224 00 이 버퍼에 있다. 224부터 빼준다. 
            if (c == -32) {           // 4. -32로 입력되면
                c = _getch();        // 5. 뒤의 값 00을 판별하여 좌우상하 출력
                switch (c) {        //27부터가 저장임
                case LEFT:
                    goto_xy(x, y);
                    PrintNotSelect(x, y);
                    if (x != 0&&y!=27)x -= 12;
                    else x = 24;
                    goto_xy(x, y);
                    SelectNum=PrintSelect(x, y);

                    break;
                case RIGHT:
                    goto_xy(x, y);
                    PrintNotSelect(x, y);
                    if (x != 24&&y!=27)x += 12;
                    else x = 0;
                    if (y == 27)x = 0;
                    goto_xy(x, y);
                    SelectNum = PrintSelect(x, y);

                    break;
                case UP:
                    goto_xy(x, y);
                    PrintNotSelect(x, y);
                    if (y != 23)y -= 2;
                    else y = 27;
                    if (y == 27)x = 0;
                    goto_xy(x, y);
                    SelectNum = PrintSelect(x, y);
                    break;
                case DOWN:
                    goto_xy(x, y);
                    PrintNotSelect(x, y);
                    if (y != 27)y += 2;
                    else
                    {
                        y = 23;
                        x = 0;
                    }
                    if (y == 27 && x != 0) x = 0;
                    goto_xy(x, y);
                    SelectNum = PrintSelect(x, y);
                    break;

                }
                
            }
           if (c == 32)
                break;
        }
    }

    return SelectNum;
}

int Selectshow()
{
    goto_xy(0, 23);
    int x = 0, y = 23;
    int SelectNum = 0;
    SelectNum=ModselectCursor();
    return SelectNum;


}
int PrintSelect(int x, int y)
{
    // 0 1 2 
    // 3 4 5 
    // 6

    textcolor(BLUE);
    switch (y)
    {
    case 23:

        if (x == 0) { printf("파일저장"); return 0; }
        else if (x == 12) { printf("불러오기"); return 1; }
        else {printf("파일생성"); return 2;}
        break;
    case 25: 
        if (x == 0) {printf("음악재생"); return 3; }
        else if (x == 12){ printf("음악멈춤"); return 4; }
        else {printf("음악편집"); return 5;
        }
        break;
    case 27:
        if (x == 0)
        {
            printf("프로그램 종료"); return 6;
        
        }
        break;
    }
}

int PrintNotSelect(int x, int y)
{
    textcolor(SkyBlue);
    switch (y)
    {
    case 23:

        if (x == 0) printf("파일저장");
        else if (x == 12) printf("불러오기");
        else printf("파일생성");
        break;
    case 25:
        if (x == 0) printf("음악재생");
        else if (x == 12) printf("음악멈춤");
        else printf("음악편집");
        break;
    case 27:
        if (x == 0)
            printf("프로그램 종료");
        break;
    }
}


int SelectProcess()
{
    printf("\n");

    int ModSelect = 0;
    //printf("1)저장 - 2)파일 불러오기 - 3)새로 만들기 - 4)음악 재생하기 - 5)음악 멈추기- 6)종료하기");
    // 저장 불러오기 만들기 재생하기 멈추기 종료하기
    // 저장하지 않고 불러오거나 새 파일을 생성할 시, 자동저장되지 않습니다.
    textcolor(SkyBlue);
    printf("\n\n파일저장    불러오기    파일생성\n");//띄어쓰기는 항상 4칸
    printf("\n음악재생    음악멈춤    음악편집\n");//-> 음악재생 - 음악멈춤 은 성태꺼 가져와서 하고있음 
    printf("\n프로그램 종료\n\n");
    textcolor(DarkGray);
    printf("SPACE 키로 선택하세요");
    textcolor(WHITE);

    ModSelect=Selectshow();

    goto_xy(0, 28);
    textcolor(DarkGray);
    switch (ModSelect)
    {
    case 0:

        printf("파일저장 선택됨");
        return 0;
        break;
    case 1:
        printf("불러오기 선택됨"); 
        return 1;
        break;
    case 2:
        printf("파일생성 선택됨");
        return 2;
        break;
    case 3:
        printf("음악재생 선택됨");
        return 3;
        break;
    case 4:
        printf("음악멈춤 선택됨");
        return 4;
        break;
    case 5:
        printf("프로그램을 종료합니다.");
        return 5;
        break;
    }

}


int MusicCursor(char* music, int* Oc, int* HowLong)
{

    int x = 0, y = 10;


    // 방향키 입력받기
    char c;
    while (1) {
        if (_kbhit()) {               // 2. while문안에서 키보드 눌렸을 시 if문이 실행된다.
            c = _getch();           // 3. 방향키가 입력됬을 때 224 00 이 버퍼에 있다. 224부터 빼준다. 
            if (c == -32) {           // 4. -32로 입력되면
                c = _getch();        // 5. 뒤의 값 00을 판별하여 좌우상하 출력
                switch (c) {        //27부터가 저장임
                case LEFT:
                    
                    
                    if (x - 1 > 0)
                        x--;

                    goto_xy(x,y);
                    printf("왼쪽");


                    break;
                case RIGHT:
                    printf("오른");
                    break;
                case UP:
                    printf("위쪽");
                    break;
                case DOWN:
                    printf("아래쪽");
                    break;

                }

            }
            else 
            {
                switch (c)
                {
                case 48:
                    //종료
                    return 0;
                    break;
                case 49:
                    //도
                    //music[*x + (*y - 14)] = "C";
                    return 1;
                    break;
                case 50:
                    //레
                    //music[*x + (*y - 14)] = "D";
                    return 2;
                    break;
                case 51:
                    //미
                    //music[*x + (*y - 14)] = "E";
                    return 3;
                    break;
                case 52:
                    //파
                    //music[*x + (*y - 14)] = "F";
                    return 4;
                    break;
                case 53:
                    //솔
                    //music[*x + (*y - 14)] = "G";
                    return 5;
                    break;
                case 54:
                    //라
                    //music[*x + (*y - 14)] = "A";
                    return 6;
                    break;
                case 55:
                    //시
                    //music[*x + (*y - 14)] = "B";
                    return 7;
                    break;
                case 56:
                    //옥타브 올리기
                    if (*Oc == 0) *Oc = 1;
                    else if (*Oc == 2) *Oc = 1;
                    return 8;
                    break;
                case 57:
                    //옥타브 내리기
                    if (*Oc == 0) *Oc = 2;
                    else if (*Oc == 1) *Oc = 2;
                    return 9;
                    break;
                case 81:
                    //음길이 길게
                    if (*HowLong != 4) *HowLong += 1;
                    else *HowLong = 1;
                    break;
                case 87:
                    if (*HowLong != 1) *HowLong -= 1;
                    else *HowLong = 4;
                    //음길이 짧게
                    break;
                }


                // if (*Oc == 0) music[*x + (*y - 12)] = '=';
               // else if (*Oc == 1)  music[*x + (*y - 12)] = '+';
               // else  music[*x + (*y - 12)] = '-';

                //if (*HowLong == 1) music[*x + (*y - 13)] = '1';
               // else if (*HowLong == 2)  music[*x + (*y - 13)] = '2';
               // else if(*HowLong==3) music[*x + (*y - 13)] = '3';
               // else  music[*x + (*y - 13)] = '4';

               // printf("%c%c%c", music[*x + (*y - 14)], music[*x + (*y - 13)], music[*x + (*y - 12)]);

            }
           
        }
    }

}

