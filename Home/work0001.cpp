#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

int WcsCat(const wchar_t* _pDest, const wchar_t* _sDest) {
    if (_pDest < _sDest) {
        return -1;
    } else if (_pDest == _sDest) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    int iRet = WcsCat(L"abc", L"abc");
    int iRef = WcsCat(L"cbc", L"abc");
    int iReg = WcsCat(L"abc", L"cbc");

    return 0;
}