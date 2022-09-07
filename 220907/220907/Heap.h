#include <vector>

using namespace std;

class Heap
{
public:
    Heap() = default;
    ~Heap() = default;

    // ���� ���� ū ���Ҹ� ��ȯ�Ѵ�.
    const int& top() const;

    // ���� ������� üũ�Ѵ�.
    bool            empty() const;

    // ���� ũ�⸦ ��ȯ�Ѵ�.
    size_t          size() const;

    // ���� ���� �����Ѵ�.
    void            push(int value);

    // ������ ���� �����Ѵ�.
    void            pop();
private:
    vector<int>     _container;
};

