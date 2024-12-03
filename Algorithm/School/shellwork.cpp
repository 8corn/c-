#include <stdio.h>
#include <stdlib.h>

void shellSort(int arr[], int n) {
    for (int i = n / 2; i > 0; i /= 2) {                        // 배열을 반으로 나누어서 비교할 간격을 점점 반으로 줄이기
        for (int j = i; j < n; j++) {                           // 비교할 간격이 가장 좁은 1이 되게끔 정렬 -> 삽입정렬로 만들기 위해
            int temp = arr[j];
            int k;
            for(k = j; k >= i && arr[k - i] > temp; k -= i) {   // 간격이 가장 좁은 1이 되면 삽입정렬처럼 작동함
                arr[k] = arr[k - i];
            }
            arr[k] = temp;
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
    int array[10] = {23, 34, 45, 56, 67 ,78 ,89 ,90, 12, 7};    // 임시 값
    int n = sizeof(array) / sizeof(array[0]);

    printf("선택정렬 \n");
    printf("정렬 전 배열: ");
    printArray(array, n);

    shellSort(array, n);

    printf("정렬 후 배열: ");
    printArray(array, n);

    return 0;    
}