#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int NAME_LEN = 20;  // 고객 이름 길이 (한글 한 문자는 2 바이트)
const int MAX_CUS_NUM = 100; // 최대 고객 수

void ShowMenu(void);            // 메뉴 출력을 위한 함수
void MakeAccount(void);         // 계좌 개설을 위한 함수 
void DepositMoney(void);        // 입금을 위한 함수
void WithdrawMoney(void);       // 출금을 위한 함수
void ShowAllAccInfo(void);      // 모든 계좌 정보 출력을 위한 함수

enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};  // 열거형 이름 생략 가능

typedef struct {   // 구조체 이름 생략 가능
    int accID;    // 계좌 번호
    int balance;  // 잔액
    char cusName[NAME_LEN];  // 고객 이름
} ACCOUNT;


ACCOUNT account[MAX_CUS_NUM];  // 계좌 처리를 위한 배열
int accNum = 0;  // 계좌 인덱스


int main(void) {
    int choice;

    while (1){
        ShowMenu();

        printf("선택: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice){
            case MAKE:
                MakeAccount();
                break;
            case DEPOSIT:
                DepositMoney();
                break;
            case WITHDRAW:
                WithdrawMoney();
                break;
            case INQUIRE:
                ShowAllAccInfo();
                break;
            case EXIT:
                return 0;
            default:
                printf("잘못된 입력 입니다.\n");
        }
    }

    return 0;
}


void ShowMenu(void){
    printf("\n------------------Menu------------------\n");
    printf("1. 계좌 개설\n");
    printf("2. 입금\n");
    printf("3. 출금\n");
    printf("4. 계좌 정보 전체 출력\n");
    printf("5. 프로그램 종료\n\n");
}

void MakeAccount(void){
    printf("\n[계좌 개설]\n");
    printf("계좌 ID: ");
    scanf("%d", &account[accNum].accID);
    printf("이름: ");
    scanf("%s", account[accNum].cusName);
    printf("입금액: ");
    scanf("%d", &account[accNum].balance);

    accNum++;
}

void DepositMoney(void) {
    int id;
    int money;

    printf("\n[입금]\n");
    printf("계좌 ID: ");
    scanf("%d", &id);

    for (int i = 0; i < accNum; i++) {
        if (account[i].accID == id) {
            printf("입금액: ");
            scanf("%d", &money);
            account[i].balance += money;
            printf("입금 완료\n");
            return;
        }
    }
    printf("잘못된 계좌 번호 입력.\n");
}

void WithdrawMoney(void) {
    int id;
    int money;

    printf("\n[출금]\n");
    printf("계좌 ID: ");
    scanf("%d", &id);

    for (int i = 0; i < accNum; i++) {
        if (account[i].accID == id) {
            printf("출금액: ");
            scanf("%d", &money);
            if (account[i].balance < money) {
                printf("잔액 부족.\n");
                return;
            } else {
                account[i].balance -= money;
                printf("출금 완료\n");
                return;
            }
        }
    }
    printf("잘못된 계좌 번호 입력.\n");
}

void ShowAllAccInfo(void) {
    printf("\n[계좌 정보]\n");

    for (int i = 0; i < accNum; i++) {
        printf("계좌 ID: %d\n", account[i].accID);
        printf("이름 : %s\n", account[i].cusName);
        printf("잔액: %d\n\n", account[i].balance);
    }
}
