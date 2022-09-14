#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int menu_display(void);
int sub_menu_display01(void); //�ܹ��ſ� ���� ���� �޴� ��°� ��ȣ �Է�
int sub_menu_display02(void); //���İ�Ƽ�� ���� ���� �޴� ��°� ��ȣ �Է�
void sub_main01(void);        //�ܹ��ſ� ���� ���� �޴� ����
void sub_main02(void);        //���İ�Ƽ�� ���� ���� �޴� ����
void chicken_burger(void);
void cheese_burger(void);
void tomato_spaghetti(void);
void cream_spaghetti(void);
void press_any_key(void); //�ƹ�Ű�� ������ ���� �޴���
int main(void)
{
    int c;
    while ((c = menu_display()) != 3)
    {
        switch (c)
        {
        case 1:
            sub_main01();
            break;
        case 2:
            sub_main02();
            break;
        default:
            break;
        }
    }
    return 0;
}
int menu_display(void)
{
    int select;
    system("cls");
    printf("���� �����\n\n");
    printf("1. �ܹ��� \n");
    printf("2. ���İ�Ƽ\n");
    printf("3. ���α׷� ����\n\n");
    printf("�޴���ȣ �Է�>");
    select = getch() - 48;
    return select;
}
void sub_main01(void)
{
    int c;
    while ((c = sub_menu_display01()) != 3)
    {
        switch (c)
        {
        case 1:
            chicken_burger();
            break;
        case 2:
            cheese_burger();
            break;
        default:
            break;
        }
    }
}
int sub_menu_display01(void)
{
    int select;
    system("cls");
    printf("�ܹ��� �����\n\n");
    printf("1. ġŲ����\n");
    printf("2. ġ�����\n");
    printf("3. ���� �޴��� �̵�\n\n");
    printf("�޴���ȣ �Է�>");
    select = getch() - 48;
    return select;
}
void chicken_burger(void)
{
    system("cls");
    printf("ġŲ���� ����� ���\n");
    printf("�߷�\n");
    press_any_key();
}
void cheese_burger(void)
{
    system("cls");
    printf("ġ����� ����� ���\n");
    printf("�߷�\n");
    press_any_key();
}
void sub_main02(void)
{
    int c;
    while ((c = sub_menu_display02()) != 3)
    {
        switch (c)
        {
        case 1:
            tomato_spaghetti();
            break;
        case 2:
            cream_spaghetti();
            break;
        default:
            break;
        }
    }
}
int sub_menu_display02(void)
{
    int select;
    system("cls");
    printf("���İ�Ƽ �����\n\n");
    printf("1. �丶�� ���İ�Ƽ \n");
    printf("2. ũ�� ���İ�Ƽ \n");
    printf("3. ���� �޴��� �̵�\n\n");
    printf("�޴���ȣ �Է�>");
    select = getch() - 48;
    return select;
}
void tomato_spaghetti(void)
{
    system("cls");
    printf("�丶�� ���İ�Ƽ ����� ���\n");
    printf("�߷�\n");
    press_any_key();
}
void cream_spaghetti(void)
{
    system("cls");
    printf("ũ�� ���İ�Ƽ ����� ���\n");
    printf("�߷�\n");
    press_any_key();
}
void press_any_key(void)
{
    printf("\n\n");
    printf("�ƹ�Ű�� ������ ���� �޴���...");
    getch();
}
