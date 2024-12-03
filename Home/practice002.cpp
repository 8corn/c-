#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <assert.h>  // 경고를 발생하는 헤더파일 -> 메크로

// 메모리 영역
// 1. 스택
// 2. 데이터
// 3. 힙
// 4. ROM(코드) -> Read Only Memory -> 실행되는 중에는 코드가 바뀌면 안됨

unsigned int GetLength(const wchar_t* _pStr) {  // 받아간 주소의 원본을 건들기 않겠다는 의미로 const를 사용
    _pStr[0];   // szName[0]에 접근
    _pStr[1];   // szName[1]에 접근
    // _pStr[0] = 100; -> 접근하여 값은 확인 할 수 있지만 값 변경은 불가능
    // 반복문에 횟수를 알 수 없기에 for보다는 while이 어울림

    // 문자 개수 체크 용도

    int i = 0;  // while 문 안에 있으면 계속 초기값을 설정해버리기에 반복문 밖에 설정

    while (true) {
        wchar_t c = *(_pStr + i);    // 주소가 1 증가시 wchar_t 타입이므로 2바이트씩 증가
        // _pStr + i == _pStr[i]

        if(0 == c) {    // '\0' == null  -> c = 0이라는 실수를 할 수 있으므로 상수를 왼쪽에 넣는 습관을 가짐
            break;  // 시작부터 0이면 문자가 없다는 뜻이므로 끝
        }
        ++i;
    }

    // while('\0' != _pStr[i]) {
    //     ++i;
    // }   -> 위 반복문을 줄인 방법  but 가독성이 떨어짐
    return i;
}
// 함수 오버로딩  -> ** 함수 오버라이딩과의 차이점 확인 (헷갈리지 말기)
void Test(int a) {}

void Test(int a, int b) {}   // 함수 이름이 같아도 인자 개수로 인해 스스로 함수를 선택 가능

void StrCat(wchar_t* _pDest, unsigned int _iBufferSize,const wchar_t* _pSrc) {  // 문자열 이어 붙이는 함수
    // 예외처리
    // 이어붙인 최종 문자열 길이가, 목적지 저장 공간을 넘어서려는 경우

    int iDestLen = GetLength(_pDest);  // 원본 문자열 길이
    int iSrcLen = GetLength(_pSrc);     // 소스 문자열 길이

    if (_iBufferSize < iDestLen + iSrcLen + 1) {  // Null 문자 공간까지 계산
        // #include <assert.h> 경고를 발생하는 헤더파일 -> 메크로

        assert(nullptr);  // if 조건을 걸어서 문제를 인식하게 할 수 있는 기능
        // 밑에 예시처럼 문자열 메모리 갯수랑 입력할 문자열의 크기가 다를 경우 경고를 발생시키기 위해 생성
    }
    // 문자열 이어붙이기
    // 1. Destination(목적지) 문자열의 끝을 확인 (문자열이 이어붙을 시작 위치)
    iDestLen;  // Dest 문자열의 끝 인덱스

    // 2. 반복적으로 Src 문자열을 Dest 끝 위치에 복사하기
    // 3. Src 문자열의 끝을 만나면 반복 종료 -> for문으로 인해 굳이 필요가 없어짐 (2번과 통합)
    for(int i = 0; i < iSrcLen + 1; ++i) {  // null문자 포함을 위해 + 1
        _pDest[iDestLen + i] = _pSrc[i];
        // 목적지의 끝부분에 반복횟수(i) 해당번째 인덱스에 소스를 복사시킴
    }
}
int main() {
    wchar_t szName[10] = L"Raimond";
    int iLen = GetLength(szName);

    Test(10);  // f12로 함수 체크
    Test(10, 20);

    // 문자열 이어 붙이기

    wchar_t szString[100] = L"abc";

    // wcscat_s(szString, 100, L"def"); -> 마이크로 소프트에서만 지원, 맥북은 밑에
    // 필요 인자개수 3개 -> Null종료 대상 문자열 버퍼(strDestination), 대상 문자열 버퍼의 크기(numberOfElements), null종료 소스 문자열 버퍼(strSource)
    wcscat(szString, L"def");
    wcscat(szString, L"ghi"); // 문자열 이어붙여서 "abcdefghi"로 나옴 -> 디버그로 확인

    wcscat(szString, L"dfghijklmnopqrstuvwxyz");  // 만약 자리가 부족하면 문제가 생김 -> 문자열을 10칸으로 했을 시

    wchar_t szStr[10] = L"abcd";
    StrCat(szStr, 10, L"efgh");

    // 과제!!
    // wcscmp(); -> 두 개의 문자열을 전달 받아서 두 문자열의 상태를 비교체크하는 함수 -> 두 문자열이 완벽하게 일치할 경우는 0이 나옴
    int iRet = wcscmp(L"abc", L"abc");  // -> 0
    int iRef = wcscmp(L"cbc", L"abc");  // -> 1
    int iReg = wcscmp(L"abc", L"cbc");  // -> -1
    // wcscmp : 저울 같은 존재(우열을 따짐 a < c) -> 같으면 0, 왼쪽이 더 크면 1, 오른쪽이 더 크면 -1


    return 0;
}