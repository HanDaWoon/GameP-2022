#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
void draw_horizontal_slide(int x, int y, int length, char *s);
void draw_vertical_slide(int x, int y, int length, char *s);
void draw_rectangle(int c, int r);
void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b);
void gotoxy(int x, int y);
int main(void)
{
char *slide="��", key;
int x=1, y=1;
int h_slide_length, v_slide_length;
printf("�����̵�� ǥ��\n\n");
printf("���� �����̵���� ����(�ִ� 70)�� \n");
printf("�Է��ϰ� Enter>");
scanf("%d", &h_slide_length);
printf("���� �����̵���� ����(�ִ� 19)�� \n");
printf("�Է��ϰ� Enter>");
scanf("%d", &v_slide_length);
system("cls");
do
{
draw_vertical_slide(1, y, v_slide_length, slide);
draw_horizontal_slide(x,v_slide_length+3,h_slide_length,slide);
key=getch();
move_arrow_key(key, &x, &y, h_slide_length, v_slide_length);
}while(key!=27);
return 0;
}
