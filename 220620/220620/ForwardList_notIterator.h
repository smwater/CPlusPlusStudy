#pragma once

#include <stddef.h>

class ForwardList
{
public:
    // 연결 리스트에서 데이터를 저장하기 위한 타입
    // 즉, 연결 리스트는 데이터를 직접적으로 다루는 것이 아니라
    // Node라는 것으로 다룹니다.
    struct Node
    {
        Node(int data = 0, Node* next = nullptr);
        Node(const Node&) = delete;
        Node& operator=(const Node&) = delete;
        ~Node();

        int     Data = 0;
        Node* Next = nullptr;
    };

    // 기본 생성자
    ForwardList();

    // count만큼의 요소를 갖고 있는 컨테이너를 만드는 생성자
    explicit ForwardList(size_t count);

    // 복사 생성자.
    ForwardList(const ForwardList& other);

    // 할당 연산자
    ForwardList& operator=(const ForwardList& rhs);

    // 소멸자
    ~ForwardList();

    // 첫 번째 요소를 반환한다.
    int& front();
    const int& front() const;

    // 시작 전 요소를 가리키는 반복자를 반환한다.
    Node*            before_begin();
    const Node*      before_begin() const;

    // 시작 요소를 가리키는 반복자를 반환한다.
    Node* begin();
    const Node* begin() const;

    // 끝 다음 요소를 가리키는 반복자를 반환한다.
    Node*            end();
    const Node*      end() const;

    // pos 다음에 value를 삽입한다.
    // 삽입된 요소를 가리키는 반복자를 반환한다.
    Node*            insert_after(const Node* pos, int value);

    // pos 다음 요소를 삭제한다.
    // 삭제된 요소의 다음 요소를 가리키는 반복자를 반환한다.
    // 아무 요소도 없으면 end()를 반환한다.
    Node*            erase_after(const Node* pos);

    // 시작 요소에 value를 삽입한다.
    void                push_front(int value);

    // 시작 요소를 제거한다.
    void                pop_front();

    // 컨테이너가 비었는지 판단한다.
    bool                empty() const;

    // 컨테이너를 비워버린다.
    void                clear();

    // value가 있는지 검사한다.
    bool                contains(int value) const;
private:
    // 더미 노드; 실제 데이터를 담지 않음. 오로지 구현의 편의성만을 위해서 존재
    Node* _head = new Node();   // before_begin()
    // 더미 노드
    Node* _end = new Node();    // end()
};
