#include <stdio.h>

int main()
{
    char c;
    scanf("%c", &c);
    while (1)
    {
        if (c != '\n')
            break;
        printf("%c", c);
        scanf("%c\n", &c);
    }
    printf("Good Bye!\n");
    return 0;
}