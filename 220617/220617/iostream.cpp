#include <iostream> // ǥ�� ���� ������� �� ����� �����ؾ� �Ѵ�.
#include <iomanip>  // ����°� ���õ� ������ ���� �����.

int main()
{
    // ����� << �����ڸ� ����ϸ� �ȴ�.
    std::cout << "Hello World!\n";

    // �����õ� �����ϴ�.
    // 1. ���� ���� ����
    std::cout << 12 << "\n";     // "12"
    std::cout << std::hex;       // 16������ ����Ѵ�.
    std::cout << 12 << "\n";     // "c"
    std::cout << std::showbase;  // ������ ǥ���Ѵ�.
    std::cout << 12 << "\n";     // "0xc"
    // �ٽ� ������� �ǵ�����.
    std::cout << std::dec << std::noshowbase;

    // 2. �Ǽ� ���� ����
    std::cout << 12.34 << "\n";         // "12.34"
    std::cout << std::fixed;            // �Ҽ��� �ڸ��� �������� ǥ���Ѵ�.
    std::cout << 12.34 << "\n";         // "12.340000"
    std::cout << std::setprecision(12); // �Ҽ��� �ڸ��� 12�ڸ��� �����Ѵ�.
    std::cout << 12.34 << "\n";         // "12.340000000000"
    // �ٽ� ������� �ǵ�����.
    std::cout << std::defaultfloat << std::setprecision(6);

    // 3. �Ҹ��� ���� ����
    std::cout << std::boolalpha;    // �Ҹ��� ���� ����� �� ���� ��� ���ڷ� ����Ѵ�.
    std::cout << true << "\n";      // "true"
    // �ٽ� ������� �ǵ�����.
    std::cout << std::noboolalpha;

    // 4. ���� ���� ����
    std::cout << std::setfill('*'); // ������ *���
    std::cout << std::setw(12);     // ��� ���̸� �Ͻ������� 12�� �����Ѵ�.
    std::cout << std::left;         // ���� ����
    std::cout << std::hex << std::showbase;
    std::cout << 42 << "\n";        // "0x2a********"
    // ��� ���� ���̸� ����Ϸ��� width()�� ����Ѵ�.
    std::cout.width(12);
    std::cout << std::right; // ������ ����
    std::cout << 42 << "\n"; // "********0x2a"
    // �ٽ� ������� �ǵ�����.
    std::cout << std::setfill(' ');
    std::cout.width(0);

    // �Է��� >> �����ڸ� ����ϸ� �ȴ�.
    std::cout << "���ڸ� �Է��ϼ��� : ";
    int num;
    std::cin >> num;

    // good() / fail()�� ���� ���θ� �� �� �ִ�.
    if (std::cin.good())
    {
        std::cout << "���ڸ� �Է���.\n";
    }
    else if (std::cin.fail())
    {
        std::cout << "���ڰ� �ƴ� �ٸ� ���� �Է���.\n";
        std::cin.clear(); // clear()�� ����ϸ� ��ü�� ����ȭ�� �� �ִ�.
    }

    // bool Ÿ������ ��ȯ�� �����ϴ�.
    if (std::cin)
    {
        std::cout << "������ ����.\n";
    }
    else
    {
        std::cout << "���� �߻���.\n";
    }

    return 0;
}

