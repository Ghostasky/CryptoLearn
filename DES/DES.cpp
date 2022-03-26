#include <bitset>
#include "DesTable.h"
#include <iostream>
#include <string>
using namespace std;
void Encode(bitset<64> plain, bitset<64> key);
void Decode();
bool key;        // 64位密钥
bool subKey[16]; // 存放16轮子密钥
void GeneratrSubKey(bitset<64> key);
void IPFun(bitset<64> plain);
void IP_1Fun(bitset<64> plain);
void Feistel(bitset<32> Right, bitset<48> subkey);
void leftShift(bitset<28> &bits, int shift); //秘钥生成的循环左移

// 循环左移
void leftShift(bitset<28> &bits, int shift)
{
    bitset<28> tmp = bits;

    for (int i = 0; i < 28; i++)
        bits[i] = tmp[(i - shift + 28) % 28];
}
// 生成子秘钥
void GeneratrSubKey(bitset<64> key)
{
    bitset<56> current;
    bitset<28> Left;
    bitset<28> Right;
    // step1: PC_1 :64 => 56
    for (int i = 0; i < 56; i++)
    {
        current[55 - i] = key[64 - PC_1[i]];
    }
    for (int i = 0; i < 28; i++)
        Left[i] = current[i + 28];
    for (int i = 0; i < 28; i++)
        Right[i] = current[i];

    // step2: 获得16个子秘钥
    for (int round = 0; round < 16; round++)
    {
        leftShift(Left, shiftBits[round]);
        leftShift(Right, shiftBits[round]);
        for (int i = 0; i < 28; i++)
        {
            current[i] = Right[i];
            current[i + 28] = Left[i];
        }
        // 使用PC_2: 56=>48
        for (int i = 0; i < 48; i++)
            subKey[round][47 - i] = current[56 - PC_2[i]];
    }
}

// 初始置换
bitset<64> IPFun(bitset<64> plain)
{
    bitset<64> test;
    for (int i = 0; i < 64; i++)
    {
        test[i] = plain[IP[i]]; // ip需要减一
    }
    return test;
}

//逆置换
bitset<64> IP_1Fun(bitset<64> plain)
{
    bitset<64> test;
    int ip_1[64];
    for (int i = 0; i < 64; i++)
    {
        test[i] = plain[IP_1[i] - 1];
    }
    return test;
}
// 轮函数
bitset<32> DESFeistel(bitset<32> Right, bitset<48> subkey)
{
    bitset<48> current;
    bitset<32> out;
    // E扩展
    for (int i = 0; i < 48; i++)
        current[47 - i] = Right[32 - E[i]];

    // 异或
    current ^= subkey;
    // S盒

    for (int i = 0; i < 8; i++)
    {
        // 一共8组，每组6位
        int head = 47 - i * 6;                           //每一组的第一位下标
        int row = current[head] * 2 + current[head - 5]; //行数
        int col = current[head - 1] * 8 + current[head - 2] * 4 + current[head - 3] * 2 + current[head - 4];
        bitset<4> res = S_BOX[i][row][col];
        for (int j = 0; j < 4; j++)
            out[31 - i * 4 - j] = res[3 - j];
    }

    // P置换
    bitset<32> tmp = out;
    for (int i = 0; i < 32; i++)
    {
        out[i] = tmp[P[i] - 1];
    }
    return out;
}

bitset<64> Encode(bitset<64> plain, bitset<64> key)
{
    bitset<32> Left;
    bitset<32> Right;
    bitset<32> nextLeft; // 16轮迭代的中间变量
    bitset<64> current;
    // cout << "key " << endl;
    // cout << key << endl;
    // cout << "IP " << endl;
    // step1 : IP
    current = IP_1Fun(plain);
    // cout << current << endl;

    for (int i = 0; i < 32; i++)
    {
        Left[i] = current[i + 32];
        Right[i] = current[i];
    }
    // step 2: 16轮
    GeneratrSubKey(key);
    for (int i = 0; i < 16; i++)
    {
        nextLeft = Right;
        Right = Left ^ DES::Feistel(Right, DES::subKey[i]);
        Left = nextLeft;
    }
    // step 3: 交换
    for (int i = 0; i < 32; i++)
    {
        current[i] = Right[i];
        current[i + 32] = Left[i];
    }

    // step 4: IP_1
    return IP_1Fun(current);
}
DES::~DES() {}

// class DES
// {
// public:
//     DES();
//     bitset<64> Encode(bitset<64> plain, bitset<64> key);
//     bitset<64> Decode();
//     ~DES();

// private:
//     bitset<64> key;        // 64位密钥
//     bitset<48> subKey[16]; // 存放16轮子密钥
//     void GeneratrSubKey(bitset<64> key);
//     bitset<64> IPFun(bitset<64> plain);
//     bitset<64> IP_1Fun(bitset<64> plain);
//     bitset<32> Feistel(bitset<32> Right, bitset<48> subkey);
//     void leftShift(bitset<28> &bits, int shift); //秘钥生成的循环左移
// };

// DES::DES()
// {
//     // Encode(plain, key);
// }

// // 循环左移
// void DES::leftShift(bitset<28> &bits, int shift)
// {
//     bitset<28> tmp = bits;

//     for (int i = 0; i < 28; i++)
//         bits[i] = tmp[(i - shift + 28) % 28];
// }
// // 生成子秘钥
// void DES::GeneratrSubKey(bitset<64> key)
// {
//     bitset<56> current;
//     bitset<28> Left;
//     bitset<28> Right;
//     // step1: PC_1 :64 => 56
//     for (int i = 0; i < 56; i++)
//     {
//         current[55 - i] = key[64 - PC_1[i]];
//     }
//     for (int i = 0; i < 28; i++)
//         Left[i] = current[i + 28];
//     for (int i = 0; i < 28; i++)
//         Right[i] = current[i];

//     // step2: 获得16个子秘钥
//     for (int round = 0; round < 16; round++)
//     {
//         leftShift(Left, shiftBits[round]);
//         leftShift(Right, shiftBits[round]);
//         for (int i = 0; i < 28; i++)
//         {
//             current[i] = Right[i];
//             current[i + 28] = Left[i];
//         }
//         // 使用PC_2: 56=>48
//         for (int i = 0; i < 48; i++)
//             subKey[round][47 - i] = current[56 - PC_2[i]];
//     }
// }

// // 初始置换
// bitset<64> DES::IPFun(bitset<64> plain)
// {
//     bitset<64> test;
//     for (int i = 0; i < 64; i++)
//     {
//         test[i] = plain[IP[i]]; // ip需要减一
//     }
//     return test;
// }

// //逆置换
// bitset<64> DES::IP_1Fun(bitset<64> plain)
// {
//     bitset<64> test;
//     int ip_1[64];
//     for (int i = 0; i < 64; i++)
//     {
//         test[i] = plain[IP_1[i] - 1];
//     }
//     return test;
// }
// // 轮函数
// bitset<32> DES::Feistel(bitset<32> Right, bitset<48> subkey)
// {
//     bitset<48> current;
//     bitset<32> out;
//     // E扩展
//     for (int i = 0; i < 48; i++)
//         current[47 - i] = Right[32 - E[i]];

//     // 异或
//     current ^= subkey;
//     // S盒

//     for (int i = 0; i < 8; i++)
//     {
//         // 一共8组，每组6位
//         int head = 47 - i * 6;                           //每一组的第一位下标
//         int row = current[head] * 2 + current[head - 5]; //行数
//         int col = current[head - 1] * 8 + current[head - 2] * 4 + current[head - 3] * 2 + current[head - 4];
//         bitset<4> res = S_BOX[i][row][col];
//         for (int j = 0; j < 4; j++)
//             out[31 - i * 4 - j] = res[3 - j];
//     }

//     // P置换
//     bitset<32> tmp = out;
//     for (int i = 0; i < 32; i++)
//     {
//         out[i] = tmp[P[i] - 1];
//     }
//     return out;
// }

// bitset<64> DES::Encode(bitset<64> plain, bitset<64> key)
// {
//     bitset<32> Left;
//     bitset<32> Right;
//     bitset<32> nextLeft; // 16轮迭代的中间变量
//     bitset<64> current;
//     // cout << "key " << endl;
//     // cout << key << endl;
//     // cout << "IP " << endl;
//     // step1 : IP
//     current = IP_1Fun(plain);
//     // cout << current << endl;

//     for (int i = 0; i < 32; i++)
//     {
//         Left[i] = current[i + 32];
//         Right[i] = current[i];
//     }
//     // step 2: 16轮
//     DES::GeneratrSubKey(key);
//     for (int i = 0; i < 16; i++)
//     {
//         nextLeft = Right;
//         Right = Left ^ DES::Feistel(Right, DES::subKey[i]);
//         Left = nextLeft;
//     }
//     // step 3: 交换
//     for (int i = 0; i < 32; i++)
//     {
//         current[i] = Right[i];
//         current[i + 32] = Left[i];
//     }

//     // step 4: IP_1
//     return IP_1Fun(current);
// }
// DES::~DES() {}
