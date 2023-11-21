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
	// ����Ű �Է¹ޱ�
    char c;
    while (1) {
        if (_kbhit()) {               // 2. while���ȿ��� Ű���� ������ �� if���� ����ȴ�.
            c = _getch();           // 3. ����Ű�� �Է��� �� 224 00 �� ���ۿ� �ִ�. 224���� ���ش�. 
            if (c == -32) {           // 4. -32�� �ԷµǸ�
                c = _getch();        // 5. ���� �� 00�� �Ǻ��Ͽ� �¿���� ���
                switch (c) {        //27���Ͱ� ������
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

        if (x == 0) { printf("��������"); return 0; }
        else if (x == 12) { printf("�ҷ�����"); return 1; }
        else {printf("���ϻ���"); return 2;}
        break;
    case 25: 
        if (x == 0) {printf("�������"); return 3; }
        else if (x == 12){ printf("���Ǹ���"); return 4; }
        else {printf("��������"); return 5;
        }
        break;
    case 27:
        if (x == 0)
        {
            printf("���α׷� ����"); return 6;
        
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

        if (x == 0) printf("��������");
        else if (x == 12) printf("�ҷ�����");
        else printf("���ϻ���");
        break;
    case 25:
        if (x == 0) printf("�������");
        else if (x == 12) printf("���Ǹ���");
        else printf("��������");
        break;
    case 27:
        if (x == 0)
            printf("���α׷� ����");
        break;
    }
}


int SelectProcess()
{
    static int first = 0;
    printf("\n");

    int ModSelect = 0;
    //printf("1)���� - 2)���� �ҷ����� - 3)���� ����� - 4)���� ����ϱ� - 5)���� ���߱�- 6)�����ϱ�");
    // ���� �ҷ����� ����� ����ϱ� ���߱� �����ϱ�
    // �������� �ʰ� �ҷ����ų� �� ������ ������ ��, �ڵ�������� �ʽ��ϴ�.
    textcolor(SkyBlue);
    if (first++ == 0)
        goto_xy(0, 25);
    else goto_xy(0, 23);
    printf("��������    �ҷ�����    ���ϻ���\n");//����� �׻� 4ĭ
    printf("\n�������    ���Ǹ���    ��������\n");//-> ������� - ���Ǹ��� �� ���²� �����ͼ� �ϰ����� 
    printf("\n���α׷� ����\n\n");
    textcolor(DarkGray);
    printf("SPACE Ű�� �����ϼ���");
    textcolor(WHITE);

    ModSelect=Selectshow();

    goto_xy(0, 28);
    textcolor(DarkGray);
    switch (ModSelect)
    {
    case 0:

        printf("�������� ���õ�");
        return 0;
        break;
    case 1:
        printf("�ҷ����� ���õ�"); 
        return 1;
        break;
    case 2:
        printf("���ϻ��� ���õ�");
        return 2;
        break;
    case 3:
        printf("������� ���õ�");
        return 3;
        break;
    case 4:
        printf("���Ǹ��� ���õ�");
        return 4;
        break;
    case 5:
        printf("���α׷��� �����մϴ�.");
        return 5;
        break;
    }

}

//�Ϸ� 
int MusicCursor(char* music, int* Oc, int* HowLong)
{

    int x = 0, y = 10;
    printf("%c%c%c", music[0], music[1], music[2]);

    // ����Ű �Է¹ޱ�
    char c;
    while (1) {
        if (_kbhit()) {               // 2. while���ȿ��� Ű���� ������ �� if���� ����ȴ�.
            c = _getch();           // 3. ����Ű�� �Է��� �� 224 00 �� ���ۿ� �ִ�. 224���� ���ش�. 
            if (c == -32) {           // 4. -32�� �ԷµǸ�
                c = _getch();        // 5. ���� �� 00�� �Ǻ��Ͽ� �¿���� ���
                switch (c) {        //27���Ͱ� ������
                case LEFT:
                    
                    goto_xy(x, y);
                    textcolor(WHITE);
                    printf("%c%c%c", music[(y - 10) * 30 + x], music[(y - 10) * 30 + x + 1], music[(y - 10) * 30 + x + 2]);
                    if (x - 3 >= 0)
                        x-=3;

                    goto_xy(x,y);
                    textcolor(BLUE);
                    printf("%c%c%c", music[(y - 10) * 30 + x], music[(y - 10) * 30 + x + 1], music[(y - 10) * 30 + x + 2]);
                   // printf("%c%c%c", music[x + (10 * (y - 10))] , music[x+1 + (10 * (y - 10))], music[x + 2 + (10 * (y - 10))]);

                    //music[x+(10*(y-10))]����
                    break;



                case RIGHT:
                    goto_xy(x, y);
                    textcolor(WHITE);
                    printf("%c%c%c", music[(y - 10) * 30 + x], music[(y - 10) * 30 + x + 1], music[(y - 10) * 30 + x + 2]);
                    if (x + 3 <30)
                        x+=3;
                    

                    goto_xy(x, y);
                    textcolor(BLUE);
                    printf("%c%c%c", music[(y - 10) * 30 + x], music[(y - 10) * 30 + x + 1], music[(y - 10) * 30 + x + 2]);

                    // printf("%c%c%c", music[x + (10 * (y - 10))], music[x + 1 + (10 * (y - 10))], music[x + 2 + (10 * (y - 10))]);

                    break;
                case UP:
                    goto_xy(x, y);
                    textcolor(WHITE);
                    printf("%c%c%c", music[(y - 10) * 30 + x], music[(y - 10) * 30 + x + 1], music[(y - 10) * 30 + x + 2]);
                    if (y - 1 >= 10)
                        y -= 1;

                    goto_xy(x, y);
                    textcolor(BLUE);

                    printf("%c%c%c", music[(y - 10) * 30 + x], music[(y - 10) * 30 + x + 1], music[(y - 10) * 30 + x + 2]);
                    //printf("%c%c%c", music[x + (10 * (y - 10))], music[x + 1 + (10 * (y - 10))], music[x + 2 + (10 * (y - 10))]);

                    break;
                case DOWN:
                    goto_xy(x, y); textcolor(WHITE);
                    printf("%c%c%c", music[(y - 10) * 30 + x], music[(y - 10) * 30 + x + 1], music[(y - 10) * 30 + x + 2]);
                    if (y + 1 < 20)
                        y += 1;

                    goto_xy(x, y);
                    textcolor(BLUE);
                    printf("%c%c%c", music[(y - 10) * 30 + x], music[(y - 10) * 30 + x + 1], music[(y - 10) * 30 + x + 2]);
                    //printf("%c%c%c", music[x + (10 * (y - 10))], music[x + 1 + (10 * (y - 10))], music[x + 2 + (10 * (y - 10))]);

                    break;

                }

            }
            else 
            {
               // switch (c)
                
                if (c == 48)
                {
                 break;
                }
                else  if (c == 49)
                {     //��
                    music[(y - 10) * 30 + x] = 67;

                }
                else  if (c == 50)
                {   //��
                    music[(y - 10) * 30 + x] = 68;
                }
                else  if (c == 51)
                {   //��
                    music[(y - 10) * 30 + x] = 69;

                }
                else  if (c == 52)
                {    //��
                    music[(y - 10) * 30 + x] = 70;
                }
                else  if (c == 53)
                {    //��
                    music[(y - 10) * 30 + x] = 71;
                }
                else  if (c == 54)
                {   //��
                    music[(y - 10) * 30 + x] = 65;
                }
                else  if (c == 55)
                {   //��
                    music[(y - 10) * 30 + x] = 66;
                }
                else  if (c == 56)
                {    //��Ÿ�� �ø���
                    if (*Oc == 0) *Oc = 1;
                    else if (*Oc == 2) *Oc = 0;
                }
                else  if (c == 57)
                {    //��Ÿ�� ������
                    if (*Oc == 0) *Oc = 2;
                    else if (*Oc == 1) *Oc = 0;
                }
                else  if (c == 81|| c==113)
                {    //������ ���
                    if (*HowLong != 4) *HowLong += 1;
                    else *HowLong = 1;
                }
                else  if (c == 87||c== 119)
                {
                    if (*HowLong != 1) *HowLong -= 1;
                    else *HowLong = 4;
                    //������ ª��
                }
                

                if (*Oc == 0) music[(y - 10) * 30 + x + 2]= 61;//=
               else if (*Oc == 1)  music[(y - 10) * 30 + x + 2] = 43;//+
                else  music[(y - 10) * 30 + x + 2] = 45;//-

                if (*HowLong == 1) music[(y - 10) * 30 + x + 1] = 49;
                else if (*HowLong == 2) music[(y - 10) * 30 + x + 1] = 50;
                else if(*HowLong==3) music[(y - 10) * 30 + x + 1] = 51;
               else music[(y - 10) * 30 + x + 1] = 52;

                goto_xy(x, y);
                printf("%c%c%c", music[(y - 10) * 30 + x], music[(y - 10) * 30 + x + 1], music[(y - 10) * 30 + x + 2]);

            }
           
        }
    }

}

