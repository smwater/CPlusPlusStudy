#include <iostream>
#include <string_view> // std::string�� ���� �ʹٸ� �� ����� �����ؾ� �Ѵ�.
#include <assert.h>

int main()
{
    std::string_view s = "Hello";
    std::cout << s << "\n";

    // empty()�� �� ���ڿ����� Ȯ���� �� �ִ�.
    if (s.empty())
    {
        std::cout << "�� ���ڿ��̴�.\n";
    }

    // length() / size()�� ���ڿ��� ���̸� �� �� �ִ�.
    std::cout << "�� ���ڿ��� ���̴� " << s.length() << "\n";
    // std::cout << "�� ���ڿ��� ���̴� " << s.size() << "\n";

    // [] �����ڷ� �� ���ڿ� ������ �� �ִ�.
    // front()�� ù ��° ���ڿ�, back()���� ������ ���ڿ� ������ �� �ִ�.
    std::cout << "�� ���ڿ��� 3��° ���ڴ� " << s[2] << "\n";
    std::cout << "�� ���ڿ��� 1��° ���ڴ� " << s.front() << "\n";
    std::cout << "�� ���ڿ��� ������ ���ڴ� " << s.back() << "\n";

    // clear()�� �� ���ڿ��� ���� �� �ִ�.
    s.clear();
    if (s.empty())
    {
        std::cout << "�� ���ڿ��̴�.\n";
    }

    // push_back() / append() / + �����ڷ� �� ���� ����(��)��(��) ������ �� �ִ�.
    s.push_back('H');   // "H"
    s.append("ello");   // "Hello"
    s += " World!";     // "Hello World!"
    std::cout << s << "\n";

    // insert()�� ����(��)��(��) �߰��� ������ �� �ִ�.
    s.insert(5, " Inserted"); // "Hello Inserted World!"
    std::cout << s << "\n";

    // pop_back()���� ������ ���ڸ� ������ �� �ִ�.
    s.pop_back(); // "Hello Inserted World"
    std::cout << s << "\n";

    // erase()�� ����(��)��(��) ������ �� �ִ�.
    s.erase(5, 9); // "Hello World"
    std::cout << s << "\n";

    // ==, !=, <, > �����ڷ� ���ڿ��� ���� �� �ִ�.
    if (s == "Hello World")
    {
        std::cout << "Hello World�� ����.\n";
    }

    if (s != "Hello")
    {
        std::cout << "Hello�� �ٸ���.\n";
    }

    if (s > "Hello")
    {
        std::cout << s << "�� Hello �ڿ� ���´�.\n";
    }

    if (s < "Idle")
    {
        std::cout << s << "�� Idle ���� ���´�.\n";
    }

    // substr()�� ���ڿ��� ������ �� �ִ�.
    std::cout << s.substr(6) << "\n";       // "World"
    std::cout << s.substr(0, 5) << "\n";    // "Hello"

    // ���ڿ� ���ڿ� �� ��ȯ�� �����ϴ�.
    s = "3.14";
    float f = std::stof(s); // f(3.14)
    s = "142";
    int i = std::stoi(s); // i(142)
    s = std::to_string(f); // s("3.14")

    // �Էµ� ���� �� �ִ�.
    std::cout << "�ܾ �Է����ּ���. : ";
    std::cin >> s;
    std::cout << "������ �Է����ּ���. : ";
    std::getline(std::cin, s);

    return 0;
}

