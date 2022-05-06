// 220412.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

/*
    제어문  데이터(타입) / 연산자 / <제어구조>

    1. 조건문 : 특정 조건에 따라서 실행문을 실행할지 안할지 제어 : if / switch
    2. 반복문 : 특정 조건에 따라서 실행문을 일정 횟수만큼 반복 실행 제어 : while / for

    조건문
    1_1. if 문

    if (조건식1)
    {
        실행문1;
    }
    else if (조건식2)
    {
        실행문2
    }
    else
    {
        실행문3
    }

    1_2. switch문

    switch (정수형 변수)
    {
        case 정수1:
            실행문1;
            break;
    }
        case 정수2:
            실행문2;
            break;
    }
        case 정수3:
            실행문3;
            break;
    }
        default:    // 해당하는 정수값이 없을 때
            실행문4;
            break;
    }

    반복문
    2_1. while문

    // 초기식
    while (조건식)
    {
        실행문;
        조건식을 바꾸는 실행문;   // while문을 중단시키는 첫번째 방법
        증감식;
        if (조건식)
        {
            break;              // while문을 중단시키는 두번째 방법
        }
    }

    do-while문

    do
    {
        실행문;
    }
    while (조건식);

    2_2. for문
    for ((1)초기식; (2)조건식; (3)증감식)
    {
        (4)실행문;
    }

    (1) -> (2) -> (4) -> (3) -> (2) -> (4) -> (3) -> ... 조건식의 결과값이 0 이 나올 때까지

    별찍기
    1)
    *
    **
    ***
    ****
    *****

    2)
        *
       **
      ***
     ****
    *****

    3)
    *****
    ****
    ***
    **
    *

    4)
    *****
     ****
      ***
       **
        *

    5)
            *
           ***
          *****
         *******
        *********

    6)
        *********
         *******
          *****
           ***
            *

    7)
            *
           ***
          *****
         *******
        *********
         *******
          *****
           ***
            *
*/

#include <iostream>
using namespace std;

int main()
{
    /*
        조건문 실습.
        정수 하나를 입력 받아서
        입력 받은 숫자가 10보다 크면 "입력된 숫자가 10보다 큽니다." 출력
        10 이하 9초과 이면 "9보다 큽니다." 출력
        9 이하 6초과 이면 "6보다 큽니다." 출력
        그 이외에는 "6보다 작거나 같습니다." 출력
    */

    int inputNum;

    cout << "정수를 입력하세요 : ";
    cin >> inputNum;

    if (inputNum > 10) {
        cout << "입력된 숫자가 10보다 큽니다." << endl;
    }
    else if (inputNum > 9) {
        cout << "9보다 큽니다." << endl;
    }
    else if (inputNum > 6) {
        cout << "6보다 큽니다." << endl;
    }
    else {
        cout << "6보다 작거나 같습니다." << endl;
    }

    /*
        switch문 실습.
        당신의 고향은 어디입니까?
        1. 서울 2. 양평 3. 경주 4. 대전 5. 제주도

        안녕하세요. 당신의 고향은 서울이군요.
        안녕하수꽝. 혼저옵서예.
        5개 중에 선택해 주세요.
    */

    cout << "당신의 고향은 어디입니까?" << endl;
    cout << "1. 서울 2. 양평 3. 광주 4. 대전 5. 제주도" << endl;

    cin >> inputNum;

    switch (inputNum) {
    case 1:
        cout << "안녕하세요. 당신의 고향은 서울이군요." << endl;
        break;
    case 2:
        cout << "안녕하세요. 당신의 고향은 양평이군요." << endl;
        break;
    case 3:
        cout << "안녕하세요. 당신의 고향은 광주군요." << endl;
        break;
    case 4:
        cout << "안녕하세요. 당신의 고향은 대전이군요." << endl;
        break;
    default:
        cout << "안녕하수꽝. 혼저옵서예." << endl;
    }

    int count = 0;

    while (1) {
        cout << "Hello World" << endl;
        count++;

        if (count == 5) {
            break;
        }
    }

    cout << endl;
    count = 0;

    do {
        cout << "Hello World" << endl;
        count++;

        if (count == 5) {
            break;
        }
    } while (1);

    // while문을 써서 정답을 맞출 때까지 반복되는 프로그램으로 수정해보자.

    srand(time(NULL));

    int correctNum = 0, userNum = 0;
    correctNum = rand() % 9 + 1;

    while (correctNum != userNum) {
        cout << "1 ~ 9 사이의 숫자를 맞춰보세요 : ";
        cin >> userNum;
        (correctNum == userNum) ? (cout << "TRUE") : (cout << "FALSE");
        cout << endl << endl;
    }

    cout << endl;
    for (int i = 0; i < 5; i++) {

        cout << "Hello World" << endl;
    }

    cout << endl;

    /*
        for문 실습1.
        10부터 1까지 차례대로 출력되는 코드를 작성해 보자.
    */

    for (int i = 10; i > 0; i--) {
        cout << i << endl;
    }

    cout << endl;

    /*
        실습2.
        100미만의 3의 배수를 차례대로 출력되는 코드를 작성해 보자.
    */

    for (int i = 1; i < 100; i++) {
        if (i % 3 == 0) {
            cout << i << endl;
        }
    }

    cout << endl;

    /*
        실습3.
        1000미만의 2의 승수를 차례대로 출력되는 코드를 작성해 보자.
    */

    for (int i = 1; i < 1000; i *= 2) {
        cout << i << endl;
    }

    cout << endl;

    /*
        실습4.
        구구단을 출력해보자.
        4_1. 구구단 2단을 차례대로 출력해보자.
        2 * 1 = 2
        2 * 2 = 4
        2 * 3 = 6
        2 * 4 = 8
        2 * 5 = 10
        2 * 6 = 12
        2 * 7 = 14
        2 * 8 = 16
        2 * 9 = 18

        4_2. 구구단 2단 ~ 9단을 차례대로 출력해보자.
        2단

        3단

        4단

        ~~

        8단

        9단

        4_3. 구구단 2단 ~ 9단을 다음과 같은 형태로 출력해 보자.
        2단 3단 4단

        5단 6단 7단

        8단 9단
    */

    for (int i = 1; i < 10; i++) {
        cout << "2 * " << i << " = " << 2 * i << endl;
    }

    cout << endl;

    for (int i = 2; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            cout << i << " * " << j << " = " << i * j << endl;
        }

        cout << endl;
    }

    for (int i = 2; i < 10; i += 3) {
        if (i < 8) {
            for (int j = 1; j < 10; j++) {
                cout << i << " * " << j << " = " << i * j << "  ";
                cout << i + 1 << " * " << j << " = " << (i + 1) * j << "  ";
                cout << i + 2 << " * " << j << " = " << (i + 2) * j << "   " << endl;
            }
        }
        else {
            for (int j = 1; j < 10; j++) {
                cout << i << " * " << j << " = " << i * j << "  ";
                cout << i + 1 << " * " << j << " = " << (i + 1) * j << "  " << endl;
            }
        }

        cout << endl;
    }
}