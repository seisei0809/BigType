#include "BigInt.h"
#include <algorithm>
#include <iostream>
#include <vector>

void BigInt::normalize() {
    while (value.length() > 1 && value[0] == '0') {
        value.erase(value.begin());
    }
    if (value == "0") {
        isNegative = false;
    }
}

BigInt::BigInt(std::string val) {
    if (val[0] == '-') {
        isNegative = true;
        val = val.substr(1);
    }
    else {
        isNegative = false;
    }
    value = val;
    normalize();
}

BigInt& BigInt::operator=(const BigInt& other) {
    if (this == &other) return *this;
    value = other.value;
    isNegative = other.isNegative;
    return *this;
}

BigInt BigInt::operator+(const BigInt& other) const {
    BigInt result = *this;
    result += other;
    return result;
}

BigInt& BigInt::operator+=(const BigInt& other) {
    if (isNegative != other.isNegative) {
        BigInt temp = other;
        temp.isNegative = !temp.isNegative;
        *this -= temp;
        return *this;
    }
    std::reverse(value.begin(), value.end());
    std::string otherValue = other.value;
    std::reverse(otherValue.begin(), otherValue.end());
    std::string result;
    int carry = 0;
    int maxLength = std::max(value.size(), otherValue.size());
    for (int i = 0; i < maxLength; i++) {
        int digit1 = (i < value.size()) ? (value[i] - '0') : 0;
        int digit2 = (i < otherValue.size()) ? (otherValue[i] - '0') : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result += (sum % 10) + '0';
    }
    if (carry) result += carry + '0';
    std::reverse(result.begin(), result.end());
    value = result;
    normalize();
    return *this;
}

BigInt BigInt::operator-(const BigInt& other) const {
    BigInt result = *this;
    result -= other;
    return result;
}

BigInt& BigInt::operator-=(const BigInt& other) {
    if (isNegative != other.isNegative) {
        BigInt temp = other;
        temp.isNegative = !temp.isNegative;
        *this += temp;
        return *this;
    }
    bool negateResult = isNegative;
    BigInt a = *this, b = other;
    if (a < b) {
        std::swap(a, b);
        negateResult = !negateResult;
    }
    std::reverse(a.value.begin(), a.value.end());
    std::reverse(b.value.begin(), b.value.end());
    std::string result;
    int borrow = 0;
    for (size_t i = 0; i < a.value.size(); i++) {
        int digit1 = a.value[i] - '0';
        int digit2 = (i < b.value.size()) ? (b.value[i] - '0') : 0;
        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        }
        else {
            borrow = 0;
        }
        result += (diff + '0');
    }
    std::reverse(result.begin(), result.end());
    value = result;
    isNegative = negateResult;
    normalize();
    return *this;
}

BigInt BigInt::operator*(const BigInt& other) const {
    BigInt result = *this;
    result *= other;
    return result;
}

BigInt& BigInt::operator*=(const BigInt& other) {
    bool resultNegative = (isNegative != other.isNegative);
    std::vector<int> result(value.size() + other.value.size(), 0);
    for (size_t i = 0; i < value.size(); i++) {
        for (size_t j = 0; j < other.value.size(); j++) {
            result[i + j] += (value[value.size() - 1 - i] - '0') * (other.value[other.value.size() - 1 - j] - '0');
            if (result[i + j] >= 10) {
                result[i + j + 1] += result[i + j] / 10;
                result[i + j] %= 10;
            }
        }
    }
    while (!result.empty() && result.back() == 0) {
        result.pop_back();
    }
    value.clear();
    for (auto it = result.rbegin(); it != result.rend(); ++it) {
        value += (*it + '0');
    }
    if (value.empty()) value = "0";
    isNegative = resultNegative;
    normalize();
    return *this;
}

BigInt BigInt::operator/(const BigInt& other) const {
    BigInt result = *this;
    result /= other;
    return result;
}

BigInt& BigInt::operator/=(const BigInt& other) {
    if (other == BigInt("0")) throw std::invalid_argument("œŽZ‚Íƒ[ƒ‚Ås‚¦‚Ü‚¹‚ñ");

    bool resultNegative = (isNegative != other.isNegative);

    BigInt absThis = *this;
    absThis.isNegative = false;
    BigInt absOther = other;
    absOther.isNegative = false;

    BigInt quotient("0");
    BigInt remainder("0");

    for (char digit : absThis.value) {
        remainder.value += digit;
        remainder.normalize();

        int count = 0;
        // ¤‚ðŒvŽZ
        while (remainder >= absOther) {
            remainder -= absOther;
            count++;
        }
        quotient.value += (count + '0');
    }

    quotient.normalize();

    quotient.isNegative = resultNegative;

    *this = quotient;
    return *this;
}


BigInt BigInt::operator%(const BigInt& other) const {
    BigInt result = *this;
    result %= other;
    return result;
}

BigInt& BigInt::operator%=(const BigInt& other) {
    if (other == BigInt("0")) throw std::invalid_argument("è—]‚Íƒ[ƒ‚Ås‚¦‚Ü‚¹‚ñ");

    bool otherNegative = other.isNegative;

    BigInt absThis = *this;
    BigInt absOther = other;

    absThis.isNegative = false;
    absOther.isNegative = false;

    BigInt remainder("0");

    for (char digit : absThis.value) {
        remainder.value += digit;
        remainder.normalize();

        while (remainder >= absOther) {
            remainder -= absOther;
        }
    }

        remainder.isNegative = false;

    *this = remainder;
    return *this;
}


bool BigInt::operator==(const BigInt& other) const {
    return (value == other.value && isNegative == other.isNegative);
}

bool BigInt::operator!=(const BigInt& other) const {
    return !(*this == other);
}

bool BigInt::operator<(const BigInt& other) const {
    if (isNegative != other.isNegative) return isNegative;

    if (value.size() != other.value.size()) {
        return value.size() < other.value.size();
    }

    return value < other.value;
}

bool BigInt::operator<=(const BigInt& other) const {
    return (*this < other || *this == other);
}

bool BigInt::operator>(const BigInt& other) const {
    return !(*this <= other);
}

bool BigInt::operator>=(const BigInt& other) const {
    return !(*this < other);
}

std::ostream& operator<<(std::ostream& os, const BigInt& num) {
    if (num.isNegative) os << "-";
    os << num.value;
    return os;
}
