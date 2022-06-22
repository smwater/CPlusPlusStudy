#include <stack> // std::stack�� ���� ���
#include <iostream>
#include <vector>
#include <forward_list>
#include <list>

int main()
{
    std::stack<int> s;

    // ���͸� ����ó�� ����ϴ� ��
    std::vector<int> st;
    st.push_back(1);
    st.pop_back();

    // ���� ���� ����Ʈ�� ����ó�� ����ϴ� ��
    std::forward_list<int> st2;
    st2.push_front(1);
    st2.pop_front();

    std::list<int> st3;
    st3.push_front(1); st3.push_back(2);
    st3.pop_front(); st3.pop_back();

    // ����
    for (int i = 1; i <= 5; ++i)
    {
        s.push(i); // push() : ���ÿ� �����͸� �����Ѵ�.
    }
    // s { 5, 4, 3, 2, 1 }

    // �����̳� ����ʹ� �ݺ��ڰ� �������� �ʴ´�.
    //  => ��ȸ �뵵�� ������� �ʱ� �����̴�.

    // ����
    s.pop(); // pop() : ������ ������ ���� ������.
    // s { 4, 3, 2, 1 }

    // �б�
    std::cout << "stack.top() : " << s.top() << "\n";
    // top() : ���� ���������� ���Ե� ���Ҹ� �����´�.

    // ũ��
    if (s.empty())
    {
        std::cout << "stack is empty\n";
    }
    std::cout << "stack.size() : " << s.size() << "\n";
    // size() : ���� ������ ������ ��ȯ�Ѵ�.
}

