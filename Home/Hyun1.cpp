#include <stdlib.h>
#include <stdio.h>

// 구조체와 포인터

typedef struct _tagMyST {
    int a;      // 멤버
    float f;
}MYST;

int main() {
    MYST s = {};        // s 는 변수

    s.a;                // a, f 는 변수 x -> 자료형 MYST의 파트를 지창하는 것 -> 멤버

    MYST* pST = &s;     // 이 포인터는 주소에 8비트짜리 자료형 있다고 생각함
    pST + 1;            // 8을 더한 것 -> 8바이트 자료형이기 때문

    *pST;               // 이것의 주소엔 변수 s가 있음
    (*pST).a = 100;     // 멤버 a파트에 100을 입력
    (*pST).f = 3.14f;   // 멤버 f파트에 3.14f를 입력
    // 만약 21열을 넣으려 할때 그 자리가 char로 선언되어있으면 다른 char 공간 뒤에 넣음 -> 실제 공간과는 상관이 없다는 뜻

    pST -> a = 100;     // 위 20, 21열을 편하게 표기하는 방법 -> 같은 방법
    pST -> f = 3.14f;   


    return 0;
}  