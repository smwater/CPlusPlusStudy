// 220407.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int main()
{    
    /*
        연산자
        데이터를 가공(연산)하는 모든 명령에 필요한 것들
        1) 어떤 종류의 연산자들이 있는지?
        2) 우선 순위 : 어떤 순서로 연산이 진행되는지?
        3) 결합 순서 : 좌측부터 연산하는 연산자, 우측부터 연산하는 연산자

        1. 사칙연산 : 산술연산자
        + : 더하기
        - : 빼기
        * : 곱하기
        / : 나누기     11 / 3 => 3
        % : 나머지     11 % 3 => 2

        *, /, %, +, -
        
        2. 대입연산자 (우측부터 연산)
        = : 왼쪽 항에 오른쪽 항의 값을 대입한다.(복사한다)

        3. 복합대입연산자
        += : a += b; => a = a + b;
        -= : a -= b; => a = a - b;
        *= : a *= b; => a = a * b;
        /= : a /= b; => a = a / b;
        %= : a %= b; => a = a % b;  // 나머지 연산자는 정수에서만 가능

        4. 증감연산자
        특정 변수의 값을 1씩 증가시키거나 감소시킬 때 사용한다.
        변수의 앞이나 뒤에 ++ / -- 를 붙여서 사용한다.
        
        5. 관계연산자
        두 값을 비교한 결과가 참(1, true)인지 거짓(0, false)인지 반환하는 연산자
        
        < : a < b : 왼쪽 항의 값이 오른쪽 항의 값보다 작으면 참을 반환한다.
        > : a > b : 왼쪽 항의 값이 오른쪽 항의 값보다 크면 참을 반환한다.
        <= : a <= b : 왼쪽 항의 값이 오른쪽 항의 값보다 작거나 같으면 참을 반환한다.
        >= : a >= b : 왼쪽 항의 값이 오른쪽 항의 값보다 크거나 같으면 참을 반환한다.
        == : a == b : 왼쪽 항의 값과 오른쪽 항의 값이 같으면 참을 반환한다.
        != : a != b : 왼쪽 항의 값과 오른쪽 항의 값이 다르면 참을 반환한다.

    */

    int left_value = 11;
    int right_value = 3;    // 나누는 값이 0일 경우 /, % 연산에서 런타임 에러 발생

    // left_value++; // 12
    cout << left_value++ << endl; // 출력 : 12, 메모리 : 13
    // ++left_value; // 13
    cout << ++left_value << endl << endl; // 출력 : 14, 메모리 : 14

    left_value = 11;

    cout << "산술연산자" << endl;
    cout << "+ : " << left_value + right_value << endl;
    cout << "- : " << left_value - right_value << endl;
    cout << "* : " << left_value * right_value << endl;
    cout << "/ : " << left_value / right_value << endl;
    cout << "% : " << left_value % right_value << endl << endl;
    
    cout << "복합대입연산자" << endl;

    cout << "+= : " << (left_value += right_value) << endl;

    left_value = 11;
    cout << "-= : " << (left_value -= right_value) << endl;

    left_value = 11;
    cout << "*= : " << (left_value *= right_value) << endl;

    left_value = 11;
    cout << "/= : " << (left_value /= right_value) << endl;

    left_value = 11;
    cout << "%= : " << (left_value %= right_value) << endl;

    /*
        실습.
        고객의 나이를 입력받아서 미성년자(19세 이하)이면 true를 출력 성인이면 false를 출력.

        아까 입력 받은 나이를 기준으로, 주민등록증 발급대상(20살만)이면 true를 아니면 false를 출력.

        + 아홉수(1의 자리가 9인수)인지 확인해서 ture, false를 출력.
    */

    int age;

    cout << endl << "나이를 입력하세요 : ";
    cin >> age;

    cout << endl;
    cout << age << "세는 " << boolalpha << endl;  // boolalpha : bool 타입 변수를 true, false로 표현하게 함
    cout << "미성년자 : " << (age <= 19) << endl;
    cout << "주민등록증 발급대상 : " << (age == 20) << endl;
    cout << "아홉수 : " << (age % 10 == 9) << endl << endl;
    // cout << noboolalpha; // bool 타입 변수를 1, 0으로 표현하게 함

}