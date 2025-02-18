#pragma once

#include <iostream>
#include <string>
#include <vector>

class BigInt {
    // ���l�����i�����Ȃ��j
    std::string value;
    // ���̐��Ȃ� true�A���̐��Ȃ� false
    bool isNegative;  

    /// <summary>
    /// �]���ȃ[�����폜���A�K�؂ȃt�H�[�}�b�g�ɐ�����
    /// </summary>
    void normalize();

public:
    /// <summary>
    /// �f�t�H���g�R���X�g���N�^
    /// </summary>
    /// <param name="val">������`���̐��l</param>
    BigInt(std::string val = "0");

    /// <summary> 
    /// ������Z�q
    /// </summary>
    BigInt& operator=(const BigInt& other);

    /// <summary> 
    /// ���Z���Z�q 
    /// </summary>
    BigInt operator+(const BigInt& other) const;
    /// <summary> 
    /// ���Z������Z�q
    /// </summary>
    BigInt& operator+=(const BigInt& other);

    /// <summary> 
    /// ���Z���Z�q
    /// </summary>
    BigInt operator-(const BigInt& other) const;
    /// <summary> 
    /// ���Z������Z�q
    /// </summary>
    BigInt& operator-=(const BigInt& other);

    /// <summary> 
    /// ��Z���Z�q 
    /// </summary>
    BigInt operator*(const BigInt& other) const;
    /// <summary> 
    /// ��Z������Z�q 
    /// </summary>
    BigInt& operator*=(const BigInt& other);

    /// <summary> 
    /// ���Z���Z�q 
    /// </summary>
    BigInt operator/(const BigInt& other) const;
    /// <summary> 
    /// ���Z������Z�q 
    /// </summary>
    BigInt& operator/=(const BigInt& other);

    /// <summary> 
    /// ��]���Z�q 
    /// </summary>
    BigInt operator%(const BigInt& other) const;
    /// <summary> 
    /// ��]������Z�q 
    /// </summary>
    BigInt& operator%=(const BigInt& other);

    /// <summary>
    /// ��r���Z�q�i�����j
    /// </summary>
    bool operator==(const BigInt& other) const;
    /// <summary>
    /// ��r���Z�q�i�񓙉��j
    /// </summary>
    bool operator!=(const BigInt& other) const;
    /// <summary>
    /// ��r���Z�q�i���Ȃ�j
    /// </summary>
    bool operator<(const BigInt& other) const;
    /// <summary>
    /// ��r���Z�q�i���Ȃ�C�R�[���j
    /// </summary>
    bool operator<=(const BigInt& other) const;
    /// <summary>
    /// ��r���Z�q�i��Ȃ�j
    /// </summary>
    bool operator>(const BigInt& other) const;
    /// <summary>
    /// ��r���Z�q�i��Ȃ�C�R�[���j
    /// </summary>
    bool operator>=(const BigInt& other) const;

    /// <summary> �X�g���[���o�͉��Z�q </summary>
    friend std::ostream& operator<<(std::ostream& os, const BigInt& num);
};