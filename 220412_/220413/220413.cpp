/*
    boolean타입
    bool is_alive = 5 > 3;

    배열 (자료구조)
    같은 데이터타입의 여러 변수를 하나의 묶음으로 나타낸 것.

    배열의 데이터타입에 대한 동일한 크기로 메모리상에 연속된 공간이 할당된다.
    배열명이 메모리 시작 주소이다.

    ex) int a = 4byte 할당

    2차원배열 및 다차원배열
    배열이 (개념적으로) 2중으로, 다중으로 구성되어 있는 것.

    1차원 배열 : int student_names[5];
        -> 5명의 학생이 있다.
    2차원 배열 : int student_nums[3][5];
        -> 3개 반에 각각 5명의 학생이 있다.
    3차원 배열 : int student_nums[4][3][5];
        -> 4개 학년에 각각 3개 반이 존재, 각 반에 5명의 학생이 있다.

    (엔터 없이)문자 하나를 입력받는 방법
    _getch();
        
    형변환 : 데이터타입을 변환한다.
    묵시적 형변환
    명시적 형변환
*/

#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    //int input_key = _getch();
    /*char input_key_char = _getch();
    cout << input_key_char << endl;

    float test_flaot;*/

    /*
        실습3.
        A ~ Z 키 중에 하나를 정답으로 설정한다.
        유저는 한 개의 키를 입력해서 설정된 값을 맞춘다.
        유저가 입력한 키와 설정된 값이 맞으면 승리, 프로그램 종료
        틀리면 남은 기회를 보여주고,
        5번 틀리면 정답을 알려주고 게임오버.
    */
    
    /*char correctKey, userKey;
    int count = 5;

    srand(time(NULL));

    correctKey = rand() % 27 + 65;
    
    while (1) {
        cout << "\nA ~ Z 중 하나를 입력하세요 : ";
        userKey = _getch();
        while ((userKey < 65) || (userKey > 90)) {
            cout << "\nA ~ Z 중 하나를 입력하세요 : ";
            userKey = _getch();
        }

        cout << endl;
        if (correctKey == userKey) {
            cout << "정답입니다." << endl;
            break;
        }
        else {
            count--;
            cout << "틀렸습니다." << endl;
            if (count != 0) {
                cout << count << "번의 기회가 남았습니다." << endl;
            }
            else {
                cout << "남은 기회를 모두 소모하였습니다." << endl;
                cout << "정답은 " << correctKey << "입니다." << endl;
                break;
            }
        }      
    }*/
    
    
    /*
        틀릴 때마다 정답 알파벳이 입력된 알파벳 앞에 있는지, 뒤에 있는지 힌트를 준다.
    */

    /*char correctKey, userKey;
    int count = 5;

    srand(time(NULL));

    correctKey = rand() % 27 + 65;

    while (1) {
        cout << "\nA ~ Z 중 하나를 입력하세요 : ";
        userKey = _getch();
        while ((userKey < 65) || (userKey > 90)) {
            cout << "\nA ~ Z 중 하나를 입력하세요 : ";
            userKey = _getch();
        }

        cout << endl;
        if (correctKey == userKey) {
            cout << "정답입니다." << endl;
            break;
        }
        else if (correctKey > userKey) {
            count--;
            cout << "틀렸습니다." << endl;
            cout << "정답은  " << userKey << "보다 뒷 글자입니다." << endl;
            if (count != 0) {
                cout << count << "번의 기회가 남았습니다." << endl;
            }
            else {
                cout << "남은 기회를 모두 소모하였습니다." << endl;
                cout << "정답은 " << correctKey << "입니다." << endl;
                break;
            }
        }
        else {
            count--;
            cout << "틀렸습니다." << endl;
            cout << "정답  " << userKey << "보다 앞 글자입니다." << endl;
            if (count != 0) {
                cout << count << "번의 기회가 남았습니다." << endl;
            }
            else {
                cout << "남은 기회를 모두 소모하였습니다." << endl;
                cout << "정답은 " << correctKey << "입니다." << endl;
                break;
            }
        }
    }*/

    /*
        입력된 값이 대소문자 구분없이 처리될 수 있도록 수정 해보자.
    */

    /* char correctKey, userKey = 0;
    int count = 5;

    srand(time(NULL));

    correctKey = rand() % 27 + 65;

    while (1) {
        
        cout << "\nA ~ Z 중 하나를 입력하세요(소문자도 가능) : ";
        userKey = _getch();
        if ((userKey <= 122) && (userKey >= 97)) {
            userKey -= 32;
        }

        while ((userKey < 65) || (userKey > 90)) {
            cout << "\nA ~ Z 중 하나를 입력하세요(소문자도 가능) : ";
            userKey = _getch();
            if ((userKey <= 122) && (userKey >= 97)) {
                userKey -= 32;
            }
        }

        cout << endl;
        if (correctKey == userKey) {
            cout << "정답입니다." << endl;
            break;
        }
        else if (correctKey > userKey) {
            count--;
            cout << "틀렸습니다." << endl;
            cout << "정답은 " << userKey << "보다 뒷 글자입니다." << endl;
            if (count != 0) {
                cout << count << "번의 기회가 남았습니다." << endl;
            }
            else {
                cout << "남은 기회를 모두 소모하였습니다." << endl;
                cout << "정답은 " << correctKey << "입니다." << endl;
                break;
            }
        }
        else {
            count--;
            cout << "틀렸습니다." << endl;
            cout << "정답은 " << userKey << "보다 앞 글자입니다." << endl;
            if (count != 0) {
                cout << count << "번의 기회가 남았습니다." << endl;
            }
            else {
                cout << "남은 기회를 모두 소모하였습니다." << endl;
                cout << "정답은 " << correctKey << "입니다." << endl;
                break;
            }
        }
    } */

    /*
        콘솔용 탈출게임
        10 * 10 크기의 맵을 구성한다. (2차원 배열)
        플레이어가 존재한다.
        탈출지점이 존재한다.
        WASD 키입력을 통해 플레이어를 이동시킨다.
        탈출지점은 (0, 0)을 제외하고 랜덤 설정
        O가 E에 도달하면 "탈출에 성공했습니다." 프로그램 종료
        SYSTEM("cls");

        0#########
        ##########
        ##########
        ##########
        ##########
        ##########
        ##########
        #####E####
        ##########
        ##########

    */
    
    srand(time(NULL));
    char map[10][10] = { 0 };
    char inputKey = 0;
    int xExit = 0, yExit = 0, xPlayer = 0, yPlayer = 0;

    while ((xExit == 0) && (yExit == 0)) {
        xExit = rand() % 10;
        yExit = rand() % 10;
    }

    map[xPlayer][yPlayer] = '0';
    map[xExit][yExit] = 'E';

    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            if (map[x][y] == 0) {
                map[x][y] = '#';
            }
        }
    }  

    while (1) {
        cout << "플레이어 0은 wasd(WASD) 키로 이동합니다." << endl << endl;
        for (int x = 0; x < 10; x++) {
            for (int y = 0; y < 10; y++) {
                if (map[x][y] != 'E') {
                    map[x][y] = '#';
                }
            }
        }

        map[xPlayer][yPlayer] = '0';

        for (int x = 0; x < 10; x++) {
            for (int y = 0; y < 10; y++) {
                cout << map[x][y];
                if (map[x][y] == '0') {
                    xPlayer = x;
                    yPlayer = y;
                }
            }
            cout << endl;
        }

        inputKey = _getch();

        if ((inputKey >= 65) && (inputKey) <= 90) {
            inputKey += 32;
        }

        switch (inputKey) {
            case 'w':
                if (xPlayer > 0) {
                    xPlayer--;
                }
                break;
            case 'a':
                if (yPlayer > 0) {
                    yPlayer--;
                }
                break;
            case 's':
                if (xPlayer < 9) {
                    xPlayer++;
                }
                break;
            case 'd':
                if (yPlayer < 9) {
                    yPlayer++;
                }
                break;
        }

        map[xPlayer][yPlayer] = '0';

        system("cls");
        inputKey = 0;

        if (map[xExit][yExit] == '0') {
            break;
        }
    }

    cout << "탈출에 성공했습니다." << endl;

    /*
        실습2.
        구구단의 결과를 저장하는 2차원 배열을 하나 선언하고,
        2 * 1 = 2

        이중 for문을 이용해서 배열 변수에 구구단의 결과값을 저장하고,

        두 수를 입력 받아서 적합한 결과값을 출력해보자.

        예시)
            (결과 저장 완료)
            몇 단을 볼까요? : _
            몇을 곱할까요? : _

            4 * 7 = 28
    */
    
    /*int gugudan[8][9];
    int num1, num2;

    for (int i = 2; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            gugudan[i-2][j-1] = i * j;
        }
    }

    cout << "몇 단을 볼까요? : ";
    cin >> num1;

    cout << "몇을 곱할까요? : ";
    cin >> num2;

    cout << num1 << " * " << num2 << " = " << gugudan[num1-2][num2-1] << endl;

    int student_nums[3][5] = {{1, 2, 3, 4, 5},
                         { 6, 7, 8, 9, 10 },
                         { 11, 12, 13, 14, 15 }
};
    //  순서대로 출력하는 코드
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            cout << student_nums[i][j] << endl;
        }
    }
    int nums[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    cout << nums << endl;
    cout << &(nums[1]) << endl;
    cout << &(nums[2]) << endl;
    cout << &(nums[3]) << endl; */

/*
    실습1. string형 배열변수 5개짜리를 선언하고
    반복문을 통해 학생의 이름을 입력 받는다.

    입력을 다 받고나서 1 ` 5 사이의 값을 입력하면 해당학생의 이름이 출력된다.

    예시)
        1번째 학생의 이름을 입력하세요 : _
        2번째 학생의 이름을 입력하세요 : _
        3번째 학생의 이름을 입력하세요 : _
        4번째 학생의 이름을 입력하세요 : _
        5번째 학생의 이름을 입력하세요 : _

        1 ~ 5 사이의 번호를 입력하세요 : _ 3
        3번째 학생의 이름은 _ _ _ 입니다.
*/

    /*string studentName[5];
    int studentNum;

    for (int i = 0; i < 5; i++) {
        cout << i+1 << "번째 학생의 이름을 입력하세요 : ";
        cin >> studentName[i];
    }

    cout << "1 ~ 5 사이의 번호를 입력하세요 : ";
    cin >> studentNum;

    cout << studentNum - 1 << "번째 학생의 이름은 " << studentName[studentNum] << " 입니다." << endl; */


}