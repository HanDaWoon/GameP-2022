#include <stdio.h>
// 1. C언어에서 사용할 수 있는 파라미터의 종류를 프로타입과 함께 기술하시오.
// int, float, double, pointer, char[], bool, char, ....
int f1(int a, int b);
double f2(int a, double b);
int *f3(int a);

// 2. 함수 포인터에 대해 예와 함께 기술하시오.
int main()
{
    int (*fp)(int, int);
    fp = f1;
    int a = fp(1, fp(2, 3));
    printf("%d", a);
    return 0;
}

int f1(int a, int b) { return a + b; }

// 3. C언어의 메모리 구조에 대해 기술하시오.
// |-------|
// | stack |
// |-------|
// |     |
// |------|
// |  c   |
// |------|
// |------|
// 4. 자신을 소개하는 간단한 html 파일을 작성하고, 그 문서에 해당하는 DOM을 그리시오.
// 5. CSS의 selector에 대해 간단한 예와 함께 기술하시오.