#include "TrackInput.h"
#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include "ForWindow.h"

enum ColorType {
	BLACK = 0,
	darkBLUE=1,	//1
	DarkGreen=2,	//2
	darkSkyBlue=3,    //3
	DarkRed=4,
	DarkPurple=5,	//5
	DarkYellow=6,	//6
	GRAY=7,		//7
	DarkGray=8,	//8
	BLUE=9,		//9
	GREEN=10,		//10
	SkyBlue=11,	//11
	RED=12,		//12
	PURPLE=13,		//13
	YELLOW=14,		//14
	WHITE=15		//15
} COLOR;

typedef struct  Tracks {
	char arr[1000];
	int num;
	char title[15]; //악보이름
	 
	//악보이름 처음 칸에느 항상 ^을 넣어서 나중에 자르게 할까 \0

};

void InputHelp()
{
	int daww = 0;
	char titl[15];
	char forserch[20];
	int forpoint=0;

	FILE* fp;


	printf("DAAAW에 오신 것을 환영합니다!\n모드 : \n1)파일 입력 \n2)직접 입력 \n4)파일 불러오기 \n5)종료\n\n>>");
	scanf_s("%d",&daww);
	forpoint = 0;

	switch (daww)
	{
	case 1:
		printf("악보 이름 입력 : [최대 10자]\n>>");
		scanf("%s", titl);
		while (strlen(titl) > 10)
		{
			printf("다시 입력하세요>>");
			scanf("%s", titl);
			
		}
		
		/*for (int i = 0; i < 20; i++)
		{
			if (titl[i] == "\0")
				forpoint = i;
			else forserch[i] = titl[i];
		}*/

		strcpy(forserch, titl);
		forpoint = strlen(forserch);
		forserch[forpoint++] = '.';
		forserch[forpoint++] = 't';
		forserch[forpoint++] = 'x';
		forserch[forpoint++] = 't';
		forserch[forpoint] = '\0';
		//문자열의 마지막에 .txt를 추가한다.

		fp = fopen(forserch, "r");

		if (fp == NULL) {
			printf("%d", forpoint);
			printf("%s", forserch);
			textcolor(DarkGray);
			printf("%s ", titl);
			printf("파일 열기 실패\n");
			textcolor(WHITE);
		}
		else {
			textcolor(DarkGray);
			printf("%s ", titl);
			printf("악보 파일 열림\n\n");
			textcolor(WHITE);
		}


		char arr[304];
		char* pStr = fgets(arr, 301, fp);
		textcolor(DarkGray);
		printf("악보 출력: \n");
		textcolor(WHITE);
		int i = 0;
		while (pStr[i] != NULL)
		{
			printf("%c", pStr[i]);
			if ((i+1) % 30==0)printf("\n");
			i++;
		}

		//printf("1)저장 - 2)파일 불러오기 - 3)새로 만들기 - 4)음악 재생하기 - 5)음악 멈추기- 6)종료하기");
		int mods;
		mods=SelectProcess();
		switch (mods)
		{
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			MusicEdit(arr);
			break;
		case 6:
			break;
		}



		/// <summary>
		/// arr에 악보가 저장되어어있음 이걸로 이제 옮겨야지 
		/// </summary>

		fclose(fp);
		break;
	default:
		break;

	}
}
//파일저장 불러오기 파일생성
//음악재생 음악멈춤 음악편집
//종료

void MusicEdit(char* music)
{
	int x=0, y=10;//논리오류
	int arrPoint = 1;
	goto_xy(0,24);
	textcolor(darkSkyBlue);
	printf("[1:도] [2:레] [3:미] [4:파] [5:솔] [6:라] [7:시]");
	goto_xy(0, 25);
	printf("[8:옥타브 높이기] [9:옥타브 낮추기] [0:편집 완료하기] [q:음 길이 늘리기] [w:음 길이 짧게]");
	goto_xy(0, 26);
	printf("[방향키를 눌러 이동하세요]");

	//음악편집을 눌렀을 때
	//xy입력받기 호출
	//숫자입력으로 호출받은 위치로 가서 글자를 바꾼다
	//배열의 문자열을 바꾼다 
	
	//첫번째 자리로 이동 
	//
	goto_xy(x, y);
	while (arrPoint != 0)
	{
		arrPoint = ArrPoint(music);
	}

	

}

int ArrPoint(char* music)
{
	static int Oc = 0, HowLong = 1;
	//첫번째 자리로 이동 
	// music [arrX+ (arrY-14)]
	int WhenEnds=11;

	

	while (WhenEnds != 0)
	{
		textcolor(WHITE);

		WhenEnds = MusicCursor(music,&Oc,&HowLong);

	}


}


