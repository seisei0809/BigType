#pragma once

#include <iostream>
#include <string>
#include <vector>

class BigInt {
    // 数値部分（符号なし）
    std::string value;
    // 負の数なら true、正の数なら false
    bool isNegative;  

    /// <summary>
    /// 余分なゼロを削除し、適切なフォーマットに整える
    /// </summary>
    void normalize();

public:
    /// <summary>
    /// デフォルトコンストラクタ
    /// </summary>
    /// <param name="val">文字列形式の数値</param>
    BigInt(std::string val = "0");

    /// <summary> 
    /// 代入演算子
    /// </summary>
    BigInt& operator=(const BigInt& other);

    /// <summary> 
    /// 加算演算子 
    /// </summary>
    BigInt operator+(const BigInt& other) const;
    /// <summary> 
    /// 加算代入演算子
    /// </summary>
    BigInt& operator+=(const BigInt& other);

    /// <summary> 
    /// 減算演算子
    /// </summary>
    BigInt operator-(const BigInt& other) const;
    /// <summary> 
    /// 減算代入演算子
    /// </summary>
    BigInt& operator-=(const BigInt& other);

    /// <summary> 
    /// 乗算演算子 
    /// </summary>
    BigInt operator*(const BigInt& other) const;
    /// <summary> 
    /// 乗算代入演算子 
    /// </summary>
    BigInt& operator*=(const BigInt& other);

    /// <summary> 
    /// 除算演算子 
    /// </summary>
    BigInt operator/(const BigInt& other) const;
    /// <summary> 
    /// 除算代入演算子 
    /// </summary>
    BigInt& operator/=(const BigInt& other);

    /// <summary> 
    /// 剰余演算子 
    /// </summary>
    BigInt operator%(const BigInt& other) const;
    /// <summary> 
    /// 剰余代入演算子 
    /// </summary>
    BigInt& operator%=(const BigInt& other);

    /// <summary>
    /// 比較演算子（等価）
    /// </summary>
    bool operator==(const BigInt& other) const;
    /// <summary>
    /// 比較演算子（非等価）
    /// </summary>
    bool operator!=(const BigInt& other) const;
    /// <summary>
    /// 比較演算子（小なり）
    /// </summary>
    bool operator<(const BigInt& other) const;
    /// <summary>
    /// 比較演算子（小なりイコール）
    /// </summary>
    bool operator<=(const BigInt& other) const;
    /// <summary>
    /// 比較演算子（大なり）
    /// </summary>
    bool operator>(const BigInt& other) const;
    /// <summary>
    /// 比較演算子（大なりイコール）
    /// </summary>
    bool operator>=(const BigInt& other) const;

    /// <summary> ストリーム出力演算子 </summary>
    friend std::ostream& operator<<(std::ostream& os, const BigInt& num);
};