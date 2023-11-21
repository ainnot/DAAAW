#include "TrackInput.h"
#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include "ForWindow.h"
#include<Mmsystem.h>
#pragma comment(lib, "Winmm.lib")

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
	char title[15]; //�Ǻ��̸�
	 
	//�Ǻ��̸� ó�� ĭ���� �׻� ^�� �־ ���߿� �ڸ��� �ұ� \0

};

int bpm;

void playNote(char note1, int length, char note2) {
	float timer = (60 / (float)bpm) * length * 1000;
	char note[10] = { note1, note2 };
	if (strcmp(note1, "R") == 0) {
		Sleep(timer);
	}
	else if (strcmp(note, "000") == 0) {
		return 0;
	}
	else {
		char wav[10] = ".wav";
		strcat(note, wav);
		PlaySoundA((note), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		Sleep(timer);
		PlaySoundA(NULL, 0, 0);
	}
}

void InputHelp()
{
	int daww = 0;
	char titl[15];
	char forserch[20];
	int forpoint=0;

	FILE* fp;

	int mods = -1;
	printf("DAAAW�� ���� ���� ȯ���մϴ�!\n��� : \n1)���� �ҷ����� \n2)���� �����ϱ� \n3)����\n\n>>");
	scanf_s("%d",&daww);
	forpoint = 0;

	switch (daww)
	{
	case 1:
		while (1)
		{
			printf("�Ǻ� �̸� �Է� : [�ִ� 10��]\n>>");
			scanf("%s", titl);
			while (strlen(titl) > 10)
			{
				printf("�ٽ� �Է��ϼ���>>");
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
			//���ڿ��� �������� .txt�� �߰��Ѵ�.

			
			fp = fopen(forserch, "r+");

			

			if (fp == NULL) {
				printf("%d", forpoint);
				printf("%s", forserch);
				textcolor(DarkGray);
				printf("%s ", titl);
				printf("���� ���� ����\n");
				textcolor(WHITE);
			}
			else {
				textcolor(DarkGray);
				printf("%s ", titl);
				printf("�Ǻ� ���� ����\n");
				textcolor(WHITE);
			}


			char arr[304];
			char* pStr = fgets(arr, 301, fp);
			textcolor(DarkGray);
			printf("�Ǻ� ���: \n");
			textcolor(WHITE);
			int i = 0;
			while (pStr[i] != NULL)
			{
				printf("%c", pStr[i]);
				if ((i + 1) % 30 == 0)printf("\n");
				i++;
			}
			i = 0;

			//printf("��������    �ҷ�����    ���ϻ���\n");//����� �׻� 4ĭ
			//printf("\n�������    ���Ǹ���    ��������\n");//-> ������� - ���Ǹ��� �� ���²� �����ͼ� �ϰ����� 
			//printf("\n���α׷� ����\n\n");
			

			while (mods != 6)
			{
				mods = SelectProcess();
				switch (mods)
				{
				case 0:
					//arr�� ���Ͽ� ����ִ´� 

					//arr[300] = '\0';
					fseek(fp, 0, SEEK_SET);
					fputs(arr, fp);

					//fgets(arr, 301,fp);
					fclose(fp);
					//fwrite(arr, sizeof(char), 301, fp);
					//fflush(fp);
					//fgets(arr, 301, fp);
					//puts(arr);
					//���� ���� 
					break;
				case 1:
					printf("���Ϻҷ�����");
					break;
				case 2:
					printf("���θ����");

					
					{
						goto_xy(0, 7);
						textcolor(WHITE);
						printf(">>                           ");
						goto_xy(2, 7);
						scanf("%s", titl);
						while (strlen(titl) > 10)
						{
							printf("�ٽ� �Է��ϼ���>>");
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
						printf("���� ���� ����\n");
						textcolor(WHITE);
					}
					else {
						textcolor(DarkGray);
						printf("%s ", titl);
						printf("�Ǻ� ���� ����\n");
						textcolor(WHITE);
					}

					pStr = fgets(arr, 301, fp);
					textcolor(DarkGray);
					printf("�Ǻ� ���: \n");
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
					while (1) {
						int i = 0;
						playNote(arr[i], arr[i + 1], arr[i + 2]);
						i += 3;
					}
					break;
				case 4:
					break;
				case 5:
					//����
					MusicEdit(arr);
					break;
				case 6:
					//����
					printf("�����մϴ�. ");

					for (int j = 0; j < 300; j++)
						printf("%c", arr[j]);
					break;
				}
			}

			fclose(fp);


			/// <summary>
			/// arr�� �Ǻ��� ����Ǿ������ �̰ɷ� ���� �Űܾ��� 
			/// </summary>

			if (mods == 6)
				break;//����
		}

	case 2:

		while (1)
		{
			textcolor(WHITE);
			printf("�Ǻ� �̸� �Է� : [�ִ� 10��]\n>>");
			scanf("%s", titl);
			while (strlen(titl) > 10)
			{
				printf("�ٽ� �Է��ϼ���>>");
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
				printf("���� ���� ����\n");
				textcolor(WHITE);
			}
			else {
				textcolor(DarkGray);
				printf("%s ", titl);
				printf("�Ǻ� ���� ����\n");
				textcolor(WHITE);
			}


			char arr[304];
			char* pStr = fgets(arr, 301, fp);
			textcolor(DarkGray);
			printf("�Ǻ� ���: \n\n");
			textcolor(WHITE);
			int i = 0;
			while (pStr[i] != NULL)
			{
				printf("%c", pStr[i]);
				if ((i + 1) % 30 == 0)printf("\n");
				i++;
			}
			i = 0;

			//printf("��������    �ҷ�����    ���ϻ���\n");//����� �׻� 4ĭ
			//printf("\n�������    ���Ǹ���    ��������\n");//-> ������� - ���Ǹ��� �� ���²� �����ͼ� �ϰ����� 
			//printf("\n���α׷� ����\n\n");


			while (mods != 6)
			{
				mods = SelectProcess();
				switch (mods)
				{
				case 0:
					//arr�� ���Ͽ� ����ִ´� 

					//arr[300] = '\0';
					fseek(fp, 0, SEEK_SET);
					fputs(arr, fp);

					//fgets(arr, 301,fp);
					fclose(fp);
					//fwrite(arr, sizeof(char), 301, fp);
					//fflush(fp);
					//fgets(arr, 301, fp);
					//puts(arr);
					//���� ���� 
					break;
				case 1:
					printf("���Ϻҷ�����");
					break;
				case 2:
					printf("���θ����");


					{
						goto_xy(0, 7);
						textcolor(WHITE);
						printf(">>                           ");
						goto_xy(2, 7);
						scanf("%s", titl);
						while (strlen(titl) > 10)
						{
							printf("�ٽ� �Է��ϼ���>>");
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
						printf("���� ���� ����\n");
						textcolor(WHITE);
					}
					else {
						textcolor(DarkGray);
						printf("%s ", titl);
						printf("�Ǻ� ���� ����\n");
						textcolor(WHITE);
					}

					pStr = fgets(arr, 301, fp);
					textcolor(DarkGray);
					printf("�Ǻ� ���: \n\n");
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
					while (1) {
						int i = 0;
						playNote(arr[i], arr[i + 1], arr[i + 2]);
						i += 3;
					}
					break;

				case 4:
					//���⿡ ������ ���� �ֱ�
					break;
				case 5:
					//����
					MusicEdit(arr);
					break;
				case 6:
					//����
					printf("�����մϴ�. ");

					for (int j = 0; j < 300; j++)
						printf("%c", arr[j]);
					break;
				}
			}

			fclose(fp);


			/// <summary>
			/// arr�� �Ǻ��� ����Ǿ������ �̰ɷ� ���� �Űܾ��� 
			/// </summary>

			if (mods == 6)
				break;//����
		}


		break;

	default:
		break;

	}
}
//�������� �ҷ����� ���ϻ���
//������� ���Ǹ��� ��������
//����

void MusicEdit(char* music)
{
	int x=0, y=10;//������
	int arrPoint = 1;
	goto_xy(0,20);
	textcolor(darkSkyBlue);
	printf("[1:��] [2:��] [3:��] [4:��] [5:��] [6:��] [7:��]");
	goto_xy(0, 21);
	printf("[8:��Ÿ�� ���̱�] [9:��Ÿ�� ���߱�] [0:���� �Ϸ��ϱ�] [q:�� ���� �ø���] [w:�� ���� ª��]");
	goto_xy(0, 22);
	printf("[����Ű�� ���� �̵��ϼ���]");

	//���������� ������ ��
	//xy�Է¹ޱ� ȣ��
	//�����Է����� ȣ����� ��ġ�� ���� ���ڸ� �ٲ۴�
	//�迭�� ���ڿ��� �ٲ۴� 
	
	//ù��° �ڸ��� �̵� 
	//
	goto_xy(x, y);

		arrPoint = ArrPoint(music);


	

}

int ArrPoint(char* music)
{
	static int Oc = 0, HowLong = 1;
	//ù��° �ڸ��� �̵� 
	// music [arrX+ (arrY-14)]
	int WhenEnds=11;

	


	
		textcolor(WHITE);

		 MusicCursor(music,&Oc,&HowLong);

	


}


