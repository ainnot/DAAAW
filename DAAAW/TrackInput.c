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

	int mods = -1;
	printf("DAAAW에 오신 것을 환영합니다!\n모드 : \n1)파일 불러오기 \n2)파일 생성하기 \n3)종료\n\n>>");
	scanf_s("%d",&daww);
	forpoint = 0;

	switch (daww)
	{
	case 1:
		while (1)
		{
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

			
			fp = fopen(forserch, "r+");

			

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
				printf("악보 파일 열림\n");
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
				if ((i + 1) % 30 == 0)printf("\n");
				i++;
			}
			i = 0;

			//printf("파일저장    불러오기    파일생성\n");//띄어쓰기는 항상 4칸
			//printf("\n음악재생    음악멈춤    음악편집\n");//-> 음악재생 - 음악멈춤 은 성태꺼 가져와서 하고있음 
			//printf("\n프로그램 종료\n\n");
			

			while (mods != 6)
			{
				mods = SelectProcess();
				switch (mods)
				{
				case 0:
					//arr을 파일에 집어넣는다 

					//arr[300] = '\0';
					fseek(fp, 0, SEEK_SET);
					fputs(arr, fp);

					//fgets(arr, 301,fp);
					fclose(fp);
					//fwrite(arr, sizeof(char), 301, fp);
					//fflush(fp);
					//fgets(arr, 301, fp);
					//puts(arr);
					//성공 저장 
					break;
				case 1:
					printf("파일불러오기");
					break;
				case 2:
					printf("새로만들기");

					
					{
						goto_xy(0, 7);
						textcolor(WHITE);
						printf(">>                           ");
						goto_xy(2, 7);
						scanf("%s", titl);
						while (strlen(titl) > 10)
						{
							printf("다시 입력하세요>>");
							scanf("%s", titl);

						}
						strcpy(forserch, titl);
						forpoint = strlen(forserch);
						forserch[forpoint++] = '.';
						forserch[forpoint++] = 't';
						forserch[forpoint++] = 'x';
						forserch[forpoint++] = 't';
						forserch[forpoint] = '\0';
						fp = fopen(forserch, "w+");
						fseek(fp, 0, SEEK_SET);
						fputs("100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", fp);
					}
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
						printf("악보 파일 열림\n");
						textcolor(WHITE);
					}

					pStr = fgets(arr, 301, fp);
					textcolor(DarkGray);
					printf("악보 출력: \n");
					textcolor(WHITE);
					int i = 0;
					while (pStr[i] != NULL)
					{
						printf("%c", pStr[i]);
						if ((i + 1) % 30 == 0)printf("\n");
						i++;
					}
					i = 0;

					break;
				case 3:
					//여기에 성태 재생 넣기
					break;
					
				case 4:
					//여기에 ㅇㅁ악 멈춤 넣기
					break;
				case 5:
					//성공
					MusicEdit(arr);
					break;
				case 6:
					//성공
					printf("종료합니다. ");

					for (int j = 0; j < 300; j++)
						printf("%c", arr[j]);
					break;
				}
			}

			fclose(fp);


			/// <summary>
			/// arr에 악보가 저장되어어있음 이걸로 이제 옮겨야지 
			/// </summary>

			if (mods == 6)
				break;//종료
		}

	case 2:

		while (1)
		{
			textcolor(WHITE);
			printf("악보 이름 입력 : [최대 10자]\n>>");
			scanf("%s", titl);
			while (strlen(titl) > 10)
			{
				printf("다시 입력하세요>>");
				scanf("%s", titl);

			}
			strcpy(forserch, titl);
			forpoint = strlen(forserch);
			forserch[forpoint++] = '.';
			forserch[forpoint++] = 't';
			forserch[forpoint++] = 'x';
			forserch[forpoint++] = 't';
			forserch[forpoint] = '\0';
			fp = fopen(forserch, "w+");
			fseek(fp, 0, SEEK_SET);
			fputs("100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", fp);


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
				printf("악보 파일 열림\n");
				textcolor(WHITE);
			}


			char arr[304];
			char* pStr = fgets(arr, 301, fp);
			textcolor(DarkGray);
			printf("악보 출력: \n\n");
			textcolor(WHITE);
			int i = 0;
			while (pStr[i] != NULL)
			{
				printf("%c", pStr[i]);
				if ((i + 1) % 30 == 0)printf("\n");
				i++;
			}
			i = 0;

			//printf("파일저장    불러오기    파일생성\n");//띄어쓰기는 항상 4칸
			//printf("\n음악재생    음악멈춤    음악편집\n");//-> 음악재생 - 음악멈춤 은 성태꺼 가져와서 하고있음 
			//printf("\n프로그램 종료\n\n");


			while (mods != 6)
			{
				mods = SelectProcess();
				switch (mods)
				{
				case 0:
					//arr을 파일에 집어넣는다 

					//arr[300] = '\0';
					fseek(fp, 0, SEEK_SET);
					fputs(arr, fp);

					//fgets(arr, 301,fp);
					fclose(fp);
					//fwrite(arr, sizeof(char), 301, fp);
					//fflush(fp);
					//fgets(arr, 301, fp);
					//puts(arr);
					//성공 저장 
					break;
				case 1:
					printf("파일불러오기");
					break;
				case 2:
					printf("새로만들기");


					{
						goto_xy(0, 7);
						textcolor(WHITE);
						printf(">>                           ");
						goto_xy(2, 7);
						scanf("%s", titl);
						while (strlen(titl) > 10)
						{
							printf("다시 입력하세요>>");
							scanf("%s", titl);

						}
						strcpy(forserch, titl);
						forpoint = strlen(forserch);
						forserch[forpoint++] = '.';
						forserch[forpoint++] = 't';
						forserch[forpoint++] = 'x';
						forserch[forpoint++] = 't';
						forserch[forpoint] = '\0';
						fp = fopen(forserch, "w+");
						fseek(fp, 0, SEEK_SET);
						fputs("100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", fp);
					}
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
						printf("악보 파일 열림\n");
						textcolor(WHITE);
					}

					pStr = fgets(arr, 301, fp);
					textcolor(DarkGray);
					printf("악보 출력: \n\n");
					textcolor(WHITE);
					int i = 0;
					while (pStr[i] != NULL)
					{
						printf("%c", pStr[i]);
						if ((i + 1) % 30 == 0)printf("\n");
						i++;
					}
					i = 0;

					break;
				case 3:
					//여기에 성태 재생 넣기
					break;

				case 4:
					//여기에 ㅇㅁ악 멈춤 넣기
					break;
				case 5:
					//성공
					MusicEdit(arr);
					break;
				case 6:
					//성공
					printf("종료합니다. ");

					for (int j = 0; j < 300; j++)
						printf("%c", arr[j]);
					break;
				}
			}

			fclose(fp);


			/// <summary>
			/// arr에 악보가 저장되어어있음 이걸로 이제 옮겨야지 
			/// </summary>

			if (mods == 6)
				break;//종료
		}


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
	goto_xy(0,20);
	textcolor(darkSkyBlue);
	printf("[1:도] [2:레] [3:미] [4:파] [5:솔] [6:라] [7:시]");
	goto_xy(0, 21);
	printf("[8:옥타브 높이기] [9:옥타브 낮추기] [0:편집 완료하기] [q:음 길이 늘리기] [w:음 길이 짧게]");
	goto_xy(0, 22);
	printf("[방향키를 눌러 이동하세요]");

	//음악편집을 눌렀을 때
	//xy입력받기 호출
	//숫자입력으로 호출받은 위치로 가서 글자를 바꾼다
	//배열의 문자열을 바꾼다 
	
	//첫번째 자리로 이동 
	//
	goto_xy(x, y);

		arrPoint = ArrPoint(music);


	

}

int ArrPoint(char* music)
{
	static int Oc = 0, HowLong = 1;
	//첫번째 자리로 이동 
	// music [arrX+ (arrY-14)]
	int WhenEnds=11;

	


	
		textcolor(WHITE);

		 MusicCursor(music,&Oc,&HowLong);

	


}


