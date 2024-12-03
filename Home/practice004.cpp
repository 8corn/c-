#include <iostream>
#include <vector>

int main() {
    // iostream -> i(nput), o(utput), stream
    // cin == c(onsole) in
    // cout == c(onsole) out
    // endl == end l(ine)

    // cout
    std::cout << "I love this lecture!\n "; // << std::endl;
    //  << : 아웃풋 오퍼레이터            endl : 줄을 마침과 동시에 줄을 바꿈
    int x = 1024;
    double pi = 3.141592;
    std::cout << "x is " << x << " pi is " << pi << std::endl;

    std::cout << "abc" << "\t" << "def" << std::endl;
    std::cout << "ab" << "\t" << "cdef" << std::endl;
    // \t : tab -> 빈 공간을 만들어 줌 (자동으로 줄 맞춤을 해줌) == 첫 칸을 맞춰줌 (a = a , d = c)

    using namespace std;
    // 이 문구가 나온 이후부터 이 함수 안은 std::를 입력하지 않아도 됨
    cout << "This is me" << endl;

    cout << "\a"; // 오디오 출력

    // cin
    int y;
    cin >> y;
    // >> : 인풋 오퍼레이터, 입력 연산자
    cout << "Your input is " << y << endl;

    int z = 1;
    cout << "Before your input, z was " << z << endl;

    cin >> z;
    cout << "Your input is " << z << endl;

    return 0;
}