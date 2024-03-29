#pragma once
#include <utility>

class Set
{
    struct Node
    {
        Node(int data = 0, Node* parent = nullptr, Node* left = nullptr, Node* right = nullptr);
        Node(const Node&) = delete;
        Node& operator=(const Node&) = delete;
        ~Node();

        bool    IsLeaf() const;

        int     Data    = 0;
        Node*   Parent  = nullptr;
        Node*   Left    = nullptr;
        Node*   Right   = nullptr;
    };

public:
    // 트리의 높이를 구한다.
    int                     height() const; // 큐를 이용한다.
    int                     height2() const; // 재귀를 이용한다.

    // 트리가 비었는지 확인한다.
    bool                    empty() const;

    // 트리의 크기를 반환한다.
    size_t                  size() const;

    // 트리를 비운다.
    void                    clear();

    // 트리에 값을 삽입한다.
    std::pair<Node*, bool>       insert(int value);

    // 트리에서 값을 삭제한다.
    void erase(Node* pos);
    size_t      erase(int value);

    // 트리에서 값을 찾는다.
    Node* find(int value);
    const Node* find(int value) const;

    // 순회
    void        traverseByPreorder() const;
    void        traverseByInorder() const;
    void        traverseByPostorder() const;
    void        traverseByLevelorder() const;

private:
    Node* _root = nullptr;
    size_t _size = 0;
};

