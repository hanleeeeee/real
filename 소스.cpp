#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int compare(int x, int y);
int main()
{
	int x, y, w, h;
	int max = 0;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	int num1=compare(x, w);
	int num2=compare(y, h);
	if (num1 > num2)
	{
		max = num2;
	}
	else
	{
		max = num1;
	}
	printf("%d", max);
}
int compare(int x, int y)
{
	int result = 0;
	result = x - 0;
	//abs(result);
	int result2 = 0;
	result2 = y-x;
	//abs(result2);
	if (result > result2)
	{
		return result2;
	}
	else {
		return result;
	}

}
//나는 가장 가까이 있는 값을 찾기 위해서 이를 비교하는 함수를 만들어서 풀었어.
