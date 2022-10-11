#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <sys/time.h>

struct rec
{
	char name[10];
	double time;
	int trNum;
	int bmNum;
} sc[5];
void set_gameType(void);
void get_Number(void);
void start_game(void);
void display_rule(void);
void gotoxy(int x, int y);
void make_treasure(int tx[], int ty[]);
void display_map(int matrix[][11], int tx[], int ty[]);
void basic_map(void);
void read_rec(void);
void save_rec(void);
void display_rec(void);
void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b);
void game_control(int tx[], int ty[]);
void game_over(void);
void clear_stdin();
int getch();
int trNum, bmNum;
double pst;

int main(void)
{
	read_rec();
	set_gameType();
	return 0;
}

void set_gameType(void)
{
	system("clear");
	int gameType = 1;
	printf("보물찾기 게임에 오신것을 환영합니다!!\n");
	printf("게임을 시작하시려면 1 을 점수를 확인하시려면 2 를 입력해주세요!\n");
	scanf("%d", &gameType);
	if (gameType == 1)
	{
		get_Number();
		start_game();
	}
	else if (gameType == 2)
	{
		display_rec();
		printf("계속하시려면 아무키나 누르세요\n");
		clear_stdin();
		getch();
		set_gameType();
	}
	else
		printf("잘못된 입력입니다.");
}

void get_Number(void)
{
	while (1)
	{
		printf("보물의 개수를 입력해주세요(1~5) : ");
		if (scanf("%d", &trNum) == 0)
		{
			printf("숫자를 입력해야 합니다!(1~5)\n");
			clear_stdin();
		}
		else
		{
			if (trNum >= 1 && trNum <= 5)
				break;
			else
				printf("개수를 다시 입력하세요!(1~5)\n");
		}
	}
	while (1)
	{
		printf("지뢰의 개수를 입력해주세요(0~3) : ");
		if (scanf("%d", &bmNum) == 0)
		{
			printf("숫자를 입력해야 합니다!(0~3)\n");
			clear_stdin();
		}
		else
		{
			if (bmNum >= 0 && bmNum <= 3)
				break;
			else
				printf("개수를 다시 입력하세요!(0~3)\n");
		}
	}

	system("clear");
	clear_stdin();
}

void start_game(void)
{
	struct timeval start = {};
	struct timeval end = {};
	int tx[trNum + bmNum], ty[trNum + bmNum];
	int matrix[11][11] = {0};
	char y;

	make_treasure(tx, ty);
	display_rule();
	gettimeofday(&start, NULL);
	system("clear");
	game_control(tx, ty);
	gettimeofday(&end, NULL);
	pst = end.tv_sec + end.tv_usec / 1000000.0 - start.tv_sec - start.tv_usec / 1000000.0;
	gotoxy(1, 13);
	printf("경과 시간 : %.2lf 초", pst);
	gotoxy(1, 14);
	printf("모두 찾았습니다. 기록을 저장 하시겠습니까?(y/n) : ");
	while (1)
	{
		scanf(" %c", &y);
		if (y == 'y' || y == 'Y')
		{
			save_rec();
			break;
		}
		else if (y == 'n' || y == 'N')
		{
			printf("기록을 저장하지 않습니다.\n");
			printf("게임을 종료합니다.\n");
			exit(0);
		}
		else
		{
			printf("\n잘못된 입력입니다. y 또는 n을 입력해주세요 : ");
		}
	}

	printf("게임을 종료합니다.");
	exit(0);
}

void display_rule(void)
{
	gotoxy(1, 1);
	printf("보물찾기");
	gotoxy(1, 3);
	printf("아래의 바둑판 모양의 격자에는 보물이 \n");
	gotoxy(1, 4);
	printf("숨겨져 있습니다. \n");
	gotoxy(1, 5);
	printf("화살표(↑↓←→)키를 움직여서 찾습니다. \n");
	gotoxy(1, 7);
	basic_map();
	printf("\n아무키나 누르면 시작합니다. \n");
	getch();
	clear_stdin();
}

void basic_map(void)
{
	int i, j;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			printf("■");
			printf(" ");
		}
		printf("\n");
	}
}

void make_treasure(int tx[], int ty[])
{
	int i;
	for (i = 0; i < trNum + bmNum; i++)
	{
		do
		{
			tx[i] = rand() % 11;
			ty[i] = rand() % 11;
		} while ((tx[i] <= 1) || (ty[i] <= 1));
	}
}

void gotoxy(int x, int y)
{
	printf("%c[%d;%df", 0x1B, y, x);
}

void display_map(int matrix[][11], int tx[], int ty[])
{
	int i, j;
	basic_map();
	for (i = 1; i <= 10; i++)
		for (j = 1; j <= 10; j++)
			if (matrix[i][j] == 1)
			{
				gotoxy(2 * i - 1, j);
				printf("□");
			}
			else if (matrix[i][j] == 2)
			{
				gotoxy(2 * i - 1, j);
				printf("★");
			}
			else if (matrix[i][j] == 3)
			{
				gotoxy(2 * i - 1, j);
				printf("◎");
			}
}

void read_rec(void)
{
	FILE *fp;
	int i = 0;
	fp = fopen("rec", "r");
	if (fp == NULL)
	{
		printf("파일을 열 수 없습니다.\n");
		exit(1);
	}
	while (!feof(fp))
	{
		fscanf(fp, "%s %lf %d %d", sc[i].name, &sc[i].time, &sc[i].trNum, &sc[i].bmNum);
		i++;
		if (i > 5)
			break;
	}
	fclose(fp);
}

void save_rec(void)
{
	FILE *fp;
	char name[10];
	fp = fopen("rec", "w");
	if (fp == NULL)
	{
		printf("파일을 열 수 없습니다.\n");
		exit(1);
	}
	else
	{
		printf("이름을 입력하세요 : ");
		clear_stdin();
		scanf("%s", name);
		fprintf(fp, "%s %.2lf %d %d", name, pst, trNum, bmNum);
		for (int i = 0; i < 4; i++)
			fprintf(fp, "%s %lf %d %d\n", sc[i].name, sc[i].time, sc[i].trNum, sc[i].bmNum);
	}
	printf("기록이 저장되었습니다.\n");
	fclose(fp);
	read_rec();
	display_rec();
}

void display_rec(void)
{
	int i;
	printf("이름\t시간\t보물\t폭탄\n");
	for (i = 0; i < 5; i++)
		printf("%s\t%.2lf\t%d\t%d\n", sc[i].name, sc[i].time, sc[i].trNum, sc[i].bmNum);
}

void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b)
{
	switch (key)
	{
	case 65: //위쪽(상) 방향의 화살표 키 입력
		*y1 = *y1 - 1;
		if (*y1 < 1)
			*y1 = 1; // y좌표의 최소값
		break;
	case 68:		   //왼쪽(좌) 방향의 화살표 키 입력
		*x1 = *x1 - 2; // x좌표의 감소값
		if (*x1 < 1)
			*x1 = 1; // x좌표의 최소값
		break;
	case 67:		   //오른쪽(우) 방향의 화살표 키 입력
		*x1 = *x1 + 2; // x좌표의 증가값
		if (*x1 > x_b)
			*x1 = x_b; // x좌표의 최대값
		break;
	case 66: //아래쪽(하) 방향의 화살표 키 입력
		*y1 = *y1 + 1;
		if (*y1 > y_b)
			*y1 = y_b; // y좌표의 최대값
		break;
	default:
		return;
	}
}

void game_control(int tx[], int ty[])
{
	char key;
	int i, j, count = 0;
	int x = 1, y = 1;
	int matrix[11][11] = {0};
	do
	{
		gotoxy(x, y);
		printf("□");
		matrix[(x + 1) / 2][y] = 1;

		for (i = 0; i < trNum; i++)
			if (((x + 1) / 2 == tx[i]) && (y == ty[i]))
				matrix[(x + 1) / 2][y] = 2;
		for (i = trNum; i < trNum + bmNum; i++)
			if (((x + 1) / 2 == tx[i]) && (y == ty[i]))
				matrix[(x + 1) / 2][y] = 3;

		gotoxy(1, 1);
		display_map(matrix, tx, ty);

		count = 0;
		for (i = 1; i <= 10; i++)
			for (j = 1; j <= 10; j++)
				if (matrix[i][j] == 2)
					count = count + 1;
				else if (matrix[i][j] == 3)
				{
					game_over();
					return;
				}
		gotoxy(1, 12);
		printf("찾은 보물(★)의 개수 : %d", count);
		key = getch();
		move_arrow_key(key, &x, &y, 19, 10);
	} while (count < trNum);
}

void game_over(void)
{
	int retry;
	system("clear");
	system("clear");
	system("clear");
	gotoxy(1, 1);
	display_rec();
	gotoxy(1, 10);
	printf("게임 오버! \n");
	gotoxy(1, 11);
	printf("다시 시도하시려면 1을 입력 해주세요. \n");
	scanf("%d", &retry);
	if (retry == 1)
	{
		system("clear");
		set_gameType();
	}
	else
		exit(0);
}

int getch()
{
	int c;
	struct termios oldattr, newattr;

	tcgetattr(STDIN_FILENO, &oldattr); // 현재 터미널 설정 읽음
	newattr = oldattr;
	newattr.c_lflag &= ~(ICANON | ECHO);		// CANONICAL과 ECHO 끔
	newattr.c_cc[VMIN] = 1;						// 최소 입력 문자 수를 1로 설정
	newattr.c_cc[VTIME] = 0;					// 최소 읽기 대기 시간을 0으로 설정
	tcsetattr(STDIN_FILENO, TCSANOW, &newattr); // 터미널에 설정 입력
	c = getchar();								// 키보드 입력 읽음
	tcsetattr(STDIN_FILENO, TCSANOW, &oldattr); // 원래의 설정으로 복구
	return c;
}

void clear_stdin(void)
{
	int c;
	do
	{
		c = getchar();
	} while (c != '\n' && c != EOF);
}