#include <stdlib.h>
#include <stdio.h>

void selectSort(int arr[], int n) {
    int Index;

    for(int i = 0; i < n - 1; i++) {            // 배율을 처음부터 순서대로 탐색
        int Index = i;
        for(int j = i + 1; j < n; j++) {        // 배열 끝까지 도는 중 가장 작은 값 찾기
            if(arr[j] < arr[Index]) {
                Index = j;                      // 가장 작은 값이 있는 인덱스 저장
            }
        }
        if (Index != i) {                       // 값의 크기를 비교해 현재 인덱스의 값과 교환
            int swap = arr[i];
            arr[i] = arr[Index];
            arr[Index] = swap;
        }
    }
}

void printArray(int arr[], int size) {          // 배열 출력
    for(int i = 0; i < size; i++) {
        printf("%d / ", arr[i]);
    }
    printf("\n");
}

int main() {
    int array[10] = {53, 18, 83, 10, 7, 37, 43, 62, 28, 92};    // 임시 값
    int n = sizeof(array) / sizeof(array[0]);

    printf("선택정렬 \n");
    printf("정렬 전 배열: ");
    printArray(array, n);

    selectSort(array, n);

    printf("정렬 후 배열: ");
    printArray(array, n);

    return 0;    
}