// 220415.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>

#define SIZE 20

struct player {
    int stamina;
    int xPlayer;
    int yPlayer;
    char inputKey;
    int xPrev;
    int yPrev;
} pl1;

struct system {
    int map[SIZE][SIZE];
    int xExit;
    int yExit;
    int charPrev;
} sys;

using namespace std;
//여기에다!!!!
/*struct score
{
    int kor;
    int eng;
    int math;
};

struct student
{
    string name; // 클래스도 쓸 수 있고
    int age; // 기본 자료형도 쓸 수 있고
    string homeTown;
    int pride;
    int monthlyScore[12]; // 배열도 넣을 수 있고
    struct score myScore; // 앞에서 정의한 구조체도 넣을 수 있다.
}seoyeon, jaehyuk; // 중괄호의 끝과 세미콜론 사이에다 student의 변수를 미리 선언해 줄 수도 있다.
//name, age, homTown, pride라는 하위 변수를 가지고 있는 student라는 구조체를 정의한다.
*/
int main() // 지금 우리가 쓰고 있는 유일한 함수
{
    system("mode con: cols=60 lines=32");
    srand(time(NULL));
    //struct student minseop, hyunsoo;
    /*
    프로그래밍 기초 (메모리, CPU 디스크)
    getch()
    구조체
    1. 절차적
    2. 구조적
    3. 객체지향적
    ### 추상화 ##
    C언어에서 코드를 추상화하는 데 사용되는 삼총사 : 배열, 구조체, 함수
    추상화 : 실제 세계(현상)를 간략화/기호화/보편화 해서 표현한 것
    코드에서 추상화가 필요한 이유 : 결국 코드는 사람이 짜는 것이기 때문에
    다른 사람이 코드를 해석하기 편리해야 하고
    다른 사람이 인수인계받아서 유지보수하기 편리해야하고
    다른 사람들과 함께 공동으로 코드를 만들기 편리해야하고
    배열 : 속성이 동일한 여러 개의 데이터를 같은 이름과 순서를 지정한 연속된 번호로
    서로 연관되어 있음을 표시함으로써 추상화함
    - 구조체 : 데이터(자료형)을 실제로 쓰이는 데이터끼리 묶어서 추상화
    - 함수 : 프로세스(코드)를 특정 기능 단위로 묶어서 추상화
    최악의 추상화 -> 추상화 단계를 상승시키는 과정
    */

    /*
    string a, b, c; // <- 최악의 추상화
    string a[3]; // <- 위의 것보다는 좀 낫다
    string name1, name2, name3; // <- 아니면 이런 식으로든지
    string student[3]; // 위의 것보다 의도가 명료하게 드러나기 때문에 좋은 추상화
    */

    /*
    구조체란???
    - 변수를 모아 놓은 집합체
    - 특정 변수들이 무언가의 하위 개념으로 묶일 수 있을 때
    - studentName[10], studentAge[10], studentKorScor[10] ...
    - '학생'의 'XXX'
    - 이름, 나이, 국어점수, 석차 등등을 '학생'이라는 구조체로 묶어서 사용

    1. 구조체를 정의하는 위치 : 구조체가 사용되는 함수의 앞에 정의한다.
    (해당 함수의 바깥쪽 앞(위))

    2. 구조체 정의의 방법
    stract 구조체 변수명
    {
        구조체 안에 들어갈 하위 변수들
        (위의 예시에 따르면 이름, 나이, 국어점수, 석차같은 애들이 하위변수다)
    };
    구조체는 일종의 우리가 새롭게 만든 데이터형이다.

    구조체 안에 들어갈 수 있는 하위변수는 무엇이 있을까??????
    당연히 int/bool,float 같은 기분 자료형들은 모두 사용 가능
    string <- 클래스도 쓸 수 있고

    3. 구조체의 선언과 초기화
    기본적으로 구조체 변수의 개념은 배열 변수의 개념과 동일
    int a[3] = {50, 70, 80};
    구조체 변수도 다음과 같이 선언과 동시에 초기화할 수 있다.

    */
    /*int a;
    student; minseop; // 구조체 변수의 선언
    minseop.name = "심민섭"; // minseop의 name은 "심민섭"이다
    minseop.age = 34; // minseop의 age는 34이다.
    minseop.homeTown = "인천";
    minseop.pride = 100;
    minseop.myScore.eng = 79;
    minseop.myScore.kor = 95;
    minseop.monthlyScore[0] = 80;
    minseop.monthlyScore[1] = 95;
    score myScore = { 50,80,90 }; // 배열을 초기화하듯 구조체 변수도 초기화할 수 있다.
    //monser a = {"고블린", 79, 55.12f, true, 100};
    //초간단실습 : student 구조체를 사용해서 자기 자신의 정보를 입력하고 확인해 보자.
    cout << myScore.kor << myScore.eng << myScore.math << endl;

    student; hyunsoo;
    hyunsoo.name = "박현수";
    hyunsoo.age = 27;
    hyunsoo.homeTown = "서울";
    hyunsoo.pride = 50;
    cout << hyunsoo.name << endl;
    cout << hyunsoo.age << endl;
    cout << hyunsoo.homeTown << endl;
    cout << hyunsoo.pride << endl << endl;*/

    /* 과제 : 미궁탈출 게임의 업데이트
    사용할 수 있는 모든 요소에 구조체를 활용해서 소스 코드를 개선해 보세요.
    title : 지형 정보를 넣고(숲, 늪지, 평지)
    player : 피로도를 넣고
    플레이어가 어느 지형에 있는지, 플레이어 피로도가 얼마인지 (숲 -1, 늪 -3, 평지 0)
    표시되도록 수정해 봅시다.
    */

    pl1.xPlayer = 0;    // 플레이어 좌표 설정
    pl1.yPlayer = 0;

    pl1.stamina = 50;   // 플레이어 스테미너 설정

    pl1.xPrev = 0;  // 플레이어의 이전 좌표 설정
    pl1.yPrev = 0;

    sys.charPrev = 3; // 이전 좌표의 모양 설정

    while ((sys.xExit == 0) && (sys.yExit == 0)) {  // 출구 좌표 랜덤 설정
        sys.xExit = rand() % SIZE;
        sys.yExit = rand() % SIZE;
    }

    for (int y = 0;y < SIZE;y++) {        // 랜덤으로 지형 형성
        for (int x = 0;x < SIZE;x++) {
            switch (rand() % 3) {
            case 0:
                sys.map[y][x] = 1;  // 숲
                break;
            case 1:
                sys.map[y][x] = 2;  // 늪
                break;
            default:
                sys.map[y][x] = 3;  // 평지
                break;
            }
        }
    }

    sys.map[pl1.yPlayer][pl1.xPlayer] = 0;    // 플레이어 위치 세팅
    sys.map[sys.yExit][sys.xExit] = 5;        // 출구 위치 세팅

    while ((sys.map[sys.yExit][sys.xExit] != 0) && (pl1.stamina >= 0)) {    // 출구 좌표에 플레이어가 도달하거나 스테미너가 0 미만이 되면 종료
        cout << "                    현재 스테미너 : " << pl1.stamina << endl << endl;

        cout << "        ■■■■■■■■■■■■■■■■■■■■■■" << endl;
        for (int y = 0;y < SIZE; y++) {  // 화면에 세팅된 맵 출력
            cout << "        ■";
            for (int x = 0;x < SIZE; x++) {
                switch (sys.map[y][x]) {
                case 0:             // char에는 특수문자를 넣을 수 없다.
                    cout << "○";   // 고로 int 배열에 숫자를 넣고 특수문자로 변환하는 방식 사용
                    break;
                case 1:
                    cout << "♤";
                    break;
                case 2:
                    cout << "※";
                    break;
                case 3:
                    cout << "  ";
                    break;
                case 5:
                    cout << "Ｅ";
                    break;
                }
            }
            cout << "■" << endl;
        }
        cout << "        ■■■■■■■■■■■■■■■■■■■■■■" << endl << endl;

        cout << "      ○ : 플레이어 캐릭터    | Ｅ : 출구" << endl;
        cout << "      ♤ : 숲 (스테미너 -1)   | ※ : 늪 (스테미너 -3)" << endl;
        cout << "         : 평지 (스테미너 -0)" << endl << endl;
        cout << "  조작방법 : w(W) = ↑ / a(A) = ← / s(S) = ↓ / d(D) = →" << endl;

        pl1.inputKey = _getch();    // 방향키를 받는다

        if ((pl1.inputKey >= 65) && (pl1.inputKey <= 90)) { // 알파벳이 대문자일 경우 소문자로 변환
            pl1.inputKey += 32;
        }

        switch (pl1.inputKey) {     // 알파벳에 따라 이동방향이 바뀜
        case 'w':
            if (pl1.yPlayer > 0) {
                sys.map[pl1.yPrev][pl1.xPrev] = sys.charPrev;   // 이전 문양을 이전 좌표에 옮긴다
                pl1.yPlayer--;
                pl1.xPrev = pl1.xPlayer;
                pl1.yPrev = pl1.yPlayer;
                sys.charPrev = sys.map[pl1.yPlayer][pl1.xPlayer];   // 이동한 좌표의 문양을 저장
                if (sys.map[pl1.yPlayer][pl1.xPlayer] == 1) {   // 이동 지역에 따른 스테미너 감소
                    pl1.stamina--;
                }
                else if (sys.map[pl1.yPlayer][pl1.xPlayer] == 2) {
                    pl1.stamina -= 3;
                }
            }
            break;
        case 'a':
            if (pl1.xPlayer > 0) {
                sys.map[pl1.yPrev][pl1.xPrev] = sys.charPrev;
                pl1.xPlayer--;
                pl1.xPrev = pl1.xPlayer;
                pl1.yPrev = pl1.yPlayer;
                sys.charPrev = sys.map[pl1.yPlayer][pl1.xPlayer];
                if (sys.map[pl1.yPlayer][pl1.xPlayer] == 1) {
                    pl1.stamina--;
                }
                else if (sys.map[pl1.yPlayer][pl1.xPlayer] == 2) {
                    pl1.stamina -= 3;
                }
            }
            break;
        case 's':
            if (pl1.yPlayer < SIZE - 1) {
                sys.map[pl1.yPrev][pl1.xPrev] = sys.charPrev;
                pl1.yPlayer++;
                pl1.xPrev = pl1.xPlayer;
                pl1.yPrev = pl1.yPlayer;
                sys.charPrev = sys.map[pl1.yPlayer][pl1.xPlayer];
                if (sys.map[pl1.yPlayer][pl1.xPlayer] == 1) {
                    pl1.stamina--;
                }
                else if (sys.map[pl1.yPlayer][pl1.xPlayer] == 2) {
                    pl1.stamina -= 3;
                }
            }
            break;
        case 'd':
            if (pl1.xPlayer < SIZE - 1) {
                sys.map[pl1.yPrev][pl1.xPrev] = sys.charPrev;
                pl1.xPlayer++;
                pl1.xPrev = pl1.xPlayer;
                pl1.yPrev = pl1.yPlayer;
                sys.charPrev = sys.map[pl1.yPlayer][pl1.xPlayer];
                if (sys.map[pl1.yPlayer][pl1.xPlayer] == 1) {
                    pl1.stamina--;
                }
                else if (sys.map[pl1.yPlayer][pl1.xPlayer] == 2) {
                    pl1.stamina -= 3;
                }
            }
            break;
        }

        sys.map[pl1.yPlayer][pl1.xPlayer] = 0;

        system("cls");
    }

    cout << "                    현재 스테미너 : " << pl1.stamina << endl << endl; // 출구 좌표에 플레이어가 도달하면 결과를 출력하지 않고 바로 종료되므로 출력문을 한번 더 써준다

    cout << "        ■■■■■■■■■■■■■■■■■■■■■■" << endl;
    for (int y = 0;y < SIZE; y++) {  // 화면에 세팅된 맵 출력
        cout << "        ■";
        for (int x = 0;x < SIZE; x++) {
            switch (sys.map[y][x]) {
            case 0:             // char에는 특수문자를 넣을 수 없다.
                cout << "○";   // 고로 int 배열에 숫자를 넣고 특수문자로 변환하는 방식 사용
                break;
            case 1:
                cout << "♤";
                break;
            case 2:
                cout << "※";
                break;
            case 3:
                cout << "  ";
                break;
            case 5:
                cout << "Ｅ";
                break;
            }
        }
        cout << "■" << endl;
    }
    cout << "        ■■■■■■■■■■■■■■■■■■■■■■" << endl << endl;
            
    if (pl1.stamina >= 0) { // 남은 스테미너에 따라 엔딩 결정
        cout << "                     남은 스테미너는 " << pl1.stamina << "." << endl << endl;
        cout << "                  성공적으로 탈출했습니다!" << endl;
    }
    else {
        cout << "                   탈출에 실패했습니다. X(" << endl;
    }

    Sleep(5000);    // exe 파일 콘솔창 유지용
}