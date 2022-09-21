/*��Ÿ��� ���� �����ð��� �����ϴ� ���α׷�*/
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>

void practice_piano(void);
int calc_frequency(int octave, int inx);

int main(void)
{
    practice_piano();
    return 0;
}

/*��Ÿ��� ���� �����ð��� �����ϴ� �Լ� practice_piano*/
/*�������ļֶ�õ�*/
/*0 1 2 3 4 5 6 7 */
/*445544244221445544242120*/
void practice_piano(void)
{
    int index[] = {0, 2, 4, 5, 7, 9, 11, 12};
    int freq[8], code, i, j;
    int base_octave = 4, time_delay = 500;
    for (i = 0; i < 8; i++)
		freq[i] = calc_frequency(base_octave, index[i]);
    int ms[] = {4,4,5,5,4,4,2,4,4,2,2,1,4,4,5,5,4,4,2,4,2,1,2,0};
    for (j = 0; j < 23; j++)
    	Beep(freq[ms[j]], time_delay);
}
/*��Ÿ�꿡 ���� ���Ժ� ���ļ��� ����Ͽ� ��ȯ�ϴ� �Լ� calc_frequency*/
int calc_frequency(int octave, int inx)
{
    double do_scale = 32.7032;
    double ratio = pow(2., 1 / 12.), temp;
    int i;
    temp = do_scale * pow(2, octave - 1);
    for (i = 0; i < inx; i++)
    {
        temp = (int)(temp + 0.5);
        temp *= ratio;
    }
    return (int)temp;
}
