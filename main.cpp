#include <iostream>
#include "BigInt.h"

int main() {
    std::string inputA, inputB;

    // ユーザーから入力を受け取る
    std::cout << "a を入力してください: ";
    std::cin >> inputA;
    std::cout << "b を入力してください: ";
    std::cin >> inputB;

    BigInt a(inputA);
    BigInt b(inputB);

    std::cout << "a: " << a << "\n";
    std::cout << "b: " << b << "\n";

    // 加算テスト
    BigInt sum = a + b;
    std::cout << "a + b = " << sum << "\n";

    // 減算テスト
    BigInt diff = a - b;
    std::cout << "a - b = " << diff << "\n";

    // 乗算テスト
    BigInt product = a * b;
    std::cout << "a * b = " << product << "\n";

    // 除算テスト
    BigInt quotient = b / a;
    std::cout << "b / a = " << quotient << "\n";

    // 剰余テスト
    BigInt remainder = b % a;
    std::cout << "b % a = " << remainder << "\n";

    // 代入演算子テスト
    BigInt c = a;
    std::cout << "c = a: " << c << "\n";

    // 加算代入
    c += b;
    std::cout << "c += b: " << c << "\n";

    // 減算代入
    c -= a;
    std::cout << "c -= a: " << c << "\n";

    // 乗算代入
    c *= BigInt("2");
    std::cout << "c *= 2: " << c << "\n";

    // 除算代入
    c /= BigInt("3");
    std::cout << "c /= 3: " << c << "\n";

    // 比較演算子テスト
    std::cout << "a == b: " << (a == b) << "\n";
    std::cout << "a != b: " << (a != b) << "\n";
    std::cout << "a < b: " << (a < b) << "\n";
    std::cout << "a > b: " << (a > b) << "\n";
    std::cout << "a <= b: " << (a <= b) << "\n";
    std::cout << "a >= b: " << (a >= b) << "\n";

    return 0;
}
