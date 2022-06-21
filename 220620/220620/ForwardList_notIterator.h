#pragma once

#include <stddef.h>

class ForwardList
{
public:
    // ���� ����Ʈ���� �����͸� �����ϱ� ���� Ÿ��
    // ��, ���� ����Ʈ�� �����͸� ���������� �ٷ�� ���� �ƴ϶�
    // Node��� ������ �ٷ�ϴ�.
    struct Node
    {
        Node(int data = 0, Node* next = nullptr);
        Node(const Node&) = delete;
        Node& operator=(const Node&) = delete;
        ~Node();

        int     Data = 0;
        Node* Next = nullptr;
    };

    // �⺻ ������
    ForwardList();

    // count��ŭ�� ��Ҹ� ���� �ִ� �����̳ʸ� ����� ������
    explicit ForwardList(size_t count);

    // ���� ������.
    ForwardList(const ForwardList& other);

    // �Ҵ� ������
    ForwardList& operator=(const ForwardList& rhs);

    // �Ҹ���
    ~ForwardList();

    // ù ��° ��Ҹ� ��ȯ�Ѵ�.
    int& front();
    const int& front() const;

    // ���� �� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    Node*            before_begin();
    const Node*      before_begin() const;

    // ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    Node* begin();
    const Node* begin() const;

    // �� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    Node*            end();
    const Node*      end() const;

    // pos ������ value�� �����Ѵ�.
    // ���Ե� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    Node*            insert_after(const Node* pos, int value);

    // pos ���� ��Ҹ� �����Ѵ�.
    // ������ ����� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    // �ƹ� ��ҵ� ������ end()�� ��ȯ�Ѵ�.
    Node*            erase_after(const Node* pos);

    // ���� ��ҿ� value�� �����Ѵ�.
    void                push_front(int value);

    // ���� ��Ҹ� �����Ѵ�.
    void                pop_front();

    // �����̳ʰ� ������� �Ǵ��Ѵ�.
    bool                empty() const;

    // �����̳ʸ� ���������.
    void                clear();

    // value�� �ִ��� �˻��Ѵ�.
    bool                contains(int value) const;
private:
    // ���� ���; ���� �����͸� ���� ����. ������ ������ ���Ǽ����� ���ؼ� ����
    Node* _head = new Node();   // before_begin()
    // ���� ���
    Node* _end = new Node();    // end()
};
