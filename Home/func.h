#pragma once

// 정적 변수     -> 선언된 파일 안에 고정되어 다른 파일로 가져갈 수 없는 정적인 변수
static int g_iStatic = 0;


int Add(int a, int b);  //이런 함수가 있다하고 선언만 함 -> 실제로 실행은 없음
int Sub(int a, int b);
int Mul(int a, int b);
