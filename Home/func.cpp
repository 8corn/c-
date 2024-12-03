#include <stdlib.h>
#include <stdio.h>

int main() {
// 문제 1

short sArr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int* pI = (int*)sArr;  // short 포인터를 강제로 int 포인터로 단위를 맞춤

int iData = *((short*)(pI + 2));   
// (pI + 2) = 8  -> 괄호 먼저 계산 -> int pI이기 때문에 8
// int로 가기전 일시적으로 short로 계산하고 다시 int로 바꿔주게끔 (short*)를 사용  -> int로 계산하게 되면 결과가 완전히 달라짐.
// short 배열은 하나의 메모리가 2바이트이므로 시작부터 8이 증가하면 5가 됨

printf("1번문제 정답 : %d\n", iData);

// 문제 2

char cArr[2] = {1, 1};

short* ps = (short*)cArr;

iData = *ps;

printf("2번 문제 정답 : %d\n", iData);

return 0;

}