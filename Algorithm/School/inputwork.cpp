#include <stdlib.h>
#include <stdio.h>

void inputSort(int array[], int n) {
    for (int i = 1; i < n; i++) {               // 0번째 인덱스는 이미 정해져 있는 상태로 생각하기 때문에 1부터 시작
        int key = array[i];                     // 현재 삽입될 숫자인 i번재 정수를 변수 key에 복사
        int j;
        
        for (j = i - 1; j >= 0 && array[j] > key; j--) { // 역순으로 확인해야하지만 j가 음수로 가면 안됨
            array[j + 1] = array[j];                     // 정렬된 배열에 있는 값이 key보다 크면 한 칸 뒤로 (j+1)로 이동
        }
        array[j + 1] = key;                     // j 루프가 끝나면 현재 빈 자리에 key를 삽입
    }
}

void printArray(int array[], int size) {        // 배열 출력
    for(int i = 0; i < size; i++) {
        printf("%d / ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[10] = {64, 45, 87, 92, 36, 74, 52, 16, 5, 49};    // 임시 값
    int n = sizeof(array) / sizeof(array[0]);

    printf("삽입정렬\n");
    printf("정렬 전 배열: \n");
    printArray(array, n);

    inputSort(array, n);

    printf("정렬 후 배열: \n");
    printArray(array, n);

    return 0;
}