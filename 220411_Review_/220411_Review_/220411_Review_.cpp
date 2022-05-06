// C++ 문법

// 주석 : 실행(컴파일) 되지 않고 설명만을 위해서 사용되는 문법

// 220411_Review_.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

/*
    C++ 문법을 사용할 때 주의해야 할 점
    1. 대/소문자를 구분해야 한다.

    main / Main / mAIN / maIN

    2. 띄어쓰기를 통해 요소를 구분한다.
    3. 실행문의 마무리는 세미콜론(;)로 한다.

    [변수] : 데이터를 저장할 메모리공간을 할당받는다.
    데이터타입 변수명;
    데이터타입 변수명 = 10;
    데이터타입 변수명 = 'a'
    데이터타입 변수명 = "Hello";

    데이터타입 크기? 표현할 수 있는 숫자의 범위?

    1. 정수형 (0, 1, 2, 3, ... , -1, -2, -3, ...)
    int
    short
    long
    long long
    __int8, __int16, __int32, __int64

    2. 실수형
    float
    double
    long double

    3. 문자형
    char

    4. 문자열
    string

    변수명 이름짓기 규칙 (표기법)
    1. 헝가리안 표기법
      - 데이터타입 약자를 접두어로 붙인다.
      int nMaxCount = 10;

    2. 카멜 표기법
      int maxCount = 10;

    3. 파스칼 표기법
      int MaxCount = 10;

      int token_max_count = 10;

      int nn = 10;
      int cmprs = 20;
      알 수 없는 축약어 사용 x

    1. 대소문자를 구분한다.
    2. 알파벳, 숫자, _(언더바)만 사용한다.
      2-1. 숫자는 가장 앞에 올 수 없다.

    4가지 속성
      1) 이름 : input_key    2) 크기(데이터 타입에 의해 결정) : 4byte    3) 값 : 10    4) 메모리주소 : 까봐야 안다

    연산자
    데이터를 가공(연산)하는 모든 명령에 필요한 것들
    1) 어떤 종류의 연산자인가
    2) 우선순위 : 어떤 순서로 연산이 되는가
    3) 결합순서 : 좌측부터 연산하는가, 우측부터 연산하는가

    1. 사칙연산 : 산술연산자 (좌측부터 연산된다)
    + : 더하기
    - : 빼기
    * : 곱하기
    / : 나누기     11 / 3 -> 3 (몫)
    % : 나머지     11 % 3 -> 2 (나머지)

    *, /, %, +, -

    2. 대입연산자 (우측부터 연산된다)
    = : 왼쪽 항에 오른쪽 항의 값을 대입(복사)한다.

    3. 복합대입연산자
    += : a += b;    -> a = a + b;
    -= : a -= b;    -> a = a - b;
    *= : a *= b;    -> a = a * b;
    /= : a /= b;    -> a = a / b; (b == 0, 런타임에러 발생)
    %= : a %= b;    -> a = a % b; (데이터 타입이 정수형이 아닐 때)

    4. 증감연산자
    특정 변수의 값ㅇ르 1씩 증가시키거나 감소시킬 때 사용하는 연산자.
    변수명 앞이나 뒤에 ++ / -- 를 붙여서 사용한다.

    5. 관게연산자
    두 항의 값을 비교한 결과가 참(1, true) 또는 거짓(0, false)으로 변환되는 연산자
    a < b
    a > b
    a <= b
    a >= b
    a == b
    a != b

    6. 논리연산자
    왼쪽 항과 오른쪽 항의 값을 각각 참과 거짓으로 연산해서 두 값을 비교해서 참과 거짓을 반환하는 연산자

    && : 논리곱(AND)
    a && b : a의 결과값이 참이고 b의 결과값이 참이면 1을 반환

    || : 논리합(OR)
    a || b : a의 결과값이 참이거나 b의 결과값이 참이면 1을 반환

    ! : 논리부정(NOT)
    !a : a의 결과값이 참이면 거짓을 반환, 거짓이면 참을 반환

    7. 삼항연산자
    a ? b : c;
    a의 결과값이 참이면 b실행문이 동작, 거짓이면 c실행문이 동작

    난수 (랜덤값)
    rand(); // 0 ~ 32767 사이의 랜덤한 값이 반환된다.
    함수 내부에 seed값이 있어서 이 값에 의해서 리턴값이 정해진다.
    기본적으로 seed : 1로 세팅되어 있다.

    srand(time(NULL));

    숙제 1. rand값의 데이터타입은 몇 byte인가?
*/

/*
    실습1. 3 ~ 7 사이의 랜덤한 숫자를 출력하는 프로그램을 작성하자.
    실습2. 가장 작은 값과 큰 값을 입력 받아서, 그 사이의 임의의 값을 출력하는 프로그램을 작성하자.
    실습3. 프로그램을 실행하면 내부적으로 1 ~ 9 사이의 숫자가 정답으로 정해진다.
    유저가 1 ~ 9 사이의 숫자를 입력하면 맞으면 true, 틀리면 false를 출력한다.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    srand(time(NULL));

    cout << "3 ~ 7 사이의 랜덤값 : " << rand() % 5 + 3 << endl;   // 실습1

    int min, max;
    cout << "작은 수를 입력하세요 : ";
    cin >> min;
    cout << "큰 수를 입력하세요 : ";
    cin >> max;

    cout << min << " ~ " << max << " 사이의 랜덤값 : " << rand() % (max - min + 1) + min << endl; // 실습2

    int correctNum = 0, userNum;
    correctNum = rand() % 9 + 1;

    cout << "1 ~ 9 사이의 숫자를 맞춰보세요 : ";
    cin >> userNum;
    (correctNum == userNum) ? (cout << "TRUE") : (cout << "FALSE");
    cout << endl;   // 실습3

    cout << rand() << endl;

    (10 < 5) ? cout << "10이 5보다 크다." : cout << "10이 5보다 작다.";
    cout << endl;

    cout << !- 300 << endl; // 0, 0 이외의 수는 무조건 참으로 보기 때문에...
    cout << (10 < 5) << endl; // 0

    int input_key = 10;
    cout << input_key++ << endl; // 10
    cout << ++input_key << endl; // 12
    cout << input_key-- << endl; // 12
    cout << --input_key << endl; // 10

    float testFloat = 5.3f;
    float testFloat2 = 5.3;
    char testCharacter = 'a';
    string testTsring = "Hello";

    cout << "Hello World!\n";
    cout << "Hello World!\n";
    cin >> input_key;
}