#include <iostream>
#include "BigInt.h"

int main() {

    BigInt a("1000000000000000000000000000");
    BigInt b("-1000000000000000000000000000");

    std::cout << "a: " << a << "\n";
    std::cout << "b: " << b << "\n";

    // ���Z�e�X�g
    BigInt sum = a + b;
    std::cout << "a + b = " << sum << "\n";

    // ���Z�e�X�g
    BigInt diff = a - b;
    std::cout << "a - b = " << diff << "\n";

    // ��Z�e�X�g
    BigInt product = a * b;
    std::cout << "a * b = " << product << "\n";

    // ���Z�e�X�g
    BigInt quotient = b / a;
    std::cout << "b / a = " << quotient << "\n";

    // ��]�e�X�g
    BigInt remainder = b % a;
    std::cout << "b % a = " << remainder << "\n";

    // ������Z�q�e�X�g
    BigInt c = a;
    std::cout << "c = a: " << c << "\n";

    // ���Z���
    c += b;
    std::cout << "c += b: " << c << "\n";

    // ���Z���
    c -= a;
    std::cout << "c -= a: " << c << "\n";

    // ��Z���
    c *= BigInt("2");
    std::cout << "c *= 2: " << c << "\n";

    // ���Z���
    c /= BigInt("3");
    std::cout << "c /= 3: " << c << "\n";

    // ��r���Z�q�e�X�g
    std::cout << "a == b: " << (a == b) << "\n";
    std::cout << "a != b: " << (a != b) << "\n";
    std::cout << "a < b: " << (a < b) << "\n";
    std::cout << "a > b: " << (a > b) << "\n";
    std::cout << "a <= b: " << (a <= b) << "\n";
    std::cout << "a >= b: " << (a >= b) << "\n";

    return 0;
}
