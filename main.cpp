#include <iostream>
#include "BigInt.h"

int main() {

    BigInt a("1000000000000000000000000000");
    BigInt b("-1000000000000000000000000000");

    std::cout << "a: " << a << "\n";
    std::cout << "b: " << b << "\n";

    // ‰ÁŽZƒeƒXƒg
    BigInt sum = a + b;
    std::cout << "a + b = " << sum << "\n";

    // Œ¸ŽZƒeƒXƒg
    BigInt diff = a - b;
    std::cout << "a - b = " << diff << "\n";

    // æŽZƒeƒXƒg
    BigInt product = a * b;
    std::cout << "a * b = " << product << "\n";

    // œŽZƒeƒXƒg
    BigInt quotient = b / a;
    std::cout << "b / a = " << quotient << "\n";

    // è—]ƒeƒXƒg
    BigInt remainder = b % a;
    std::cout << "b % a = " << remainder << "\n";

    // ‘ã“ü‰‰ŽZŽqƒeƒXƒg
    BigInt c = a;
    std::cout << "c = a: " << c << "\n";

    // ‰ÁŽZ‘ã“ü
    c += b;
    std::cout << "c += b: " << c << "\n";

    // Œ¸ŽZ‘ã“ü
    c -= a;
    std::cout << "c -= a: " << c << "\n";

    // æŽZ‘ã“ü
    c *= BigInt("2");
    std::cout << "c *= 2: " << c << "\n";

    // œŽZ‘ã“ü
    c /= BigInt("3");
    std::cout << "c /= 3: " << c << "\n";

    // ”äŠr‰‰ŽZŽqƒeƒXƒg
    std::cout << "a == b: " << (a == b) << "\n";
    std::cout << "a != b: " << (a != b) << "\n";
    std::cout << "a < b: " << (a < b) << "\n";
    std::cout << "a > b: " << (a > b) << "\n";
    std::cout << "a <= b: " << (a <= b) << "\n";
    std::cout << "a >= b: " << (a >= b) << "\n";

    return 0;
}
