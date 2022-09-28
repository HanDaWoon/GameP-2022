#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
void draw_horizontal_slide(int x, int y, int length, char *s);
void draw_vertical_slide(int x, int y, int length, char *s);void draw_rectangle(int c, int r);void draw_rectangle2(int c, int r, int y); //가로 슬라이드바를 위한 변형 사각형 함수
void draw_rectangle3(int c, int r); //슬라이드 바 안에 있는 사각형
void draw_line(int x, int y, int c, int r);
void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b);
void gotoxy(int x, int y);
int main(void)
{       
	char *slide = "■", key;
	int x = 1, y = 1;
	int h_slide_length,v_slide_length;
	printf("슬라이드바 표시\n\n");
	printf("수평 슬라이드바의 길이(최대 70)를\n");
	printf("입력하고 Enter>");
	scanf("%d",&h_slide_length);
	printf("수직 슬라이드바의 길이(최대 19)를\n");
	printf("입력하고 Enter>");
	scanf("%d",&v_slide_length);
	system("cls");
	do
	{
		system("cls");
		draw_vertical_slide(1,y, v_slide_length, slide);    
		draw_horizontal_slide(x,v_slide_length + 3, h_slide_length, slide);  
		gotoxy(8,1);          
		draw_rectangle3(h_slide_length/2+ 1, v_slide_length);   
		draw_line(x,y, h_slide_length/2 +1, v_slide_length);  
		key =getch();     
		move_arrow_key(key,&x, &y, h_slide_length, v_slide_length);   
		} while (key != 27);   
	return 0;
}
void draw_horizontal_slide(int x, int y, int length, char *s)
{    
	int real_length = length / 2;   
	gotoxy(8,y);
	draw_rectangle2(real_length+ 1, 1, y);
	gotoxy(x +9, y + 1);   
	printf("%s", s);   
	gotoxy(real_length* 2 + 16, y + 2); 
	printf("%2d", x);
}
void draw_vertical_slide(int x, int y, int length, char *s)
{     
	gotoxy(x,1);     
	draw_rectangle(1,length); 
	gotoxy(x +2, y + 1);  
	printf("%s", s);
	gotoxy(x +2, length + 3);     
	printf("%2d", y);
}
void draw_rectangle(int c, int r)
{    
	int i, j;  
	unsigned char a = 0xa6;   
	unsigned char b[7];    
	for (i = 1; i < 7;i++)     
		b[i]= 0xa0 + i;        
	printf("%c%c", a, b[3]);   
	for (i = 0; i < c;i++)   
		printf("%c%c", a, b[1]);  
	printf("%c%c", a, b[4]);     
	printf("\n");  
	for (i = 0; i < r;i++)    
	{
		printf("%c%c", a, b[2]);    
		for (j = 0; j < c;j++) 
			printf("  ");          
		printf("%c%c", a, b[2]);  
		printf("\n");   
	}       
	printf("%c%c", a, b[6]);  
	for (i = 0; i < c;i++)    
		printf("%c%c", a, b[1]); 
	printf("%c%c", a, b[5]);  
	printf("\n");
} 
void draw_rectangle2(int c, int r, int y)
{   
	int i, j;   
	unsigned char a = 0xa6; 
	unsigned char b[7];  
	for (i = 1; i < 7;i++)   
		b[i]= 0xa0 + i;        
	printf("%c%c", a, b[3]);  
	for (i = 0; i < c;i++)   
		printf("%c%c", a, b[1]);  
	printf("%c%c", a, b[4]); 
	printf("\n");    
	gotoxy(8, y+ 1);     
	for (i = 0; i < r;i++)  
	{            
		printf("%c%c", a, b[2]); 
		for (j = 0; j < c;j++)    
			printf("  ");           
		printf("%c%c", a, b[2]);   
		printf("\n");    
	}    
	gotoxy(8, y+ 2);   
	printf("%c%c", a, b[6]); 
	for (i = 0; i < c;i++)   
		printf("%c%c", a, b[1]); 
	printf("%c%c", a, b[5]); 
	printf("\n");
} 
void draw_rectangle3(int c, int r)
{    
	int i, j;
	int count = 2; 
	unsigned char a = 0xa6;  
	unsigned char b[7];  
	for (i = 1; i < 7;i++)     
		b[i]= 0xa0 + i;       
	printf("%c%c", a, b[3]);  
	for (i = 0; i < c;i++)   
		printf("%c%c", a, b[1]);  
	printf("%c%c", a, b[4]);  
	printf("\n");      
	for (i = 0; i < r;i++)    
	{          
		gotoxy(8,count++); 
		printf("%c%c", a, b[2]);    
		for (j = 0; j < c;j++)     
			printf("  ");            
		printf("%c%c", a, b[2]);   
		printf("\n");      
	}       
	gotoxy(8,count);    
	printf("%c%c", a, b[6]);  
	for (i = 0; i < c;i++)         
		printf("%c%c", a, b[1]);   
	printf("%c%c", a, b[5]);    
	printf("\n");
}
void draw_line(int x, int y, int c, int r)
{     
	int count1 = 0, count2= 2;  
	for (int i = 0; i < c; i++)   
	{         
		gotoxy(10+ count1, y + 1);   
		printf("─");    
		count1+= 2;     
	}     
	for (int i = 0; i < r; i++)  
	{           
		gotoxy(x + 9, count2); 
		printf("│");     
		count2++;      
	}     
	gotoxy(x + 9, y + 1);  
	printf("┼");    
	gotoxy(1,20);
}
void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b)
{    
	switch (key)
	{    
		case 72: 
			*y1 = *y1 - 1;        
			if (*y1 < 1)        
			*y1 = 1;          
			break;   
		case 75:        
			*x1 = *x1 - 1;   
			if (*x1 < 1)        
			*x1 = 1;        
			break; 
		case 77:        
			*x1 = *x1 + 1;       
			if (*x1 > x_b)       
			*x1 = x_b;           
			break;     
		case 80:        
			*y1 = *y1 + 1;      
			if (*y1 > y_b)       
			*y1 = y_b;            
			break;  
		default:        
			return;    
	}
}
void gotoxy(int x, int y)
{  
	COORD Pos = { x - 1, y - 1 };  
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}