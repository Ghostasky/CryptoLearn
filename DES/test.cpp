#include <bitset>
#include "DesTable.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <ostream>
using namespace std;
bitset<64> charToBin(const string c)
{
    bitset<64> bit64;
    for (int i = 0; i < 16; i++)
    {
        bitset<4> b4 = c[i];
        bit64[63 - i * 4] = c[i];
        // cout << c[i] << " " << b4 << endl;
        bit64[63 - i * 4] = b4[3];
        bit64[63 - i * 4 - 1] = b4[2];
        bit64[63 - i * 4 - 2] = b4[1];
        bit64[63 - i * 4 - 3] = b4[0];
    }
    return bit64;
}
int main()
{
    bitset<64> bit64;
    string p = "1111111111111111";

    bit64 = charToBin(p);
    cout << bit64 << endl;

    return 0;
}
// 0001 0011 0011 0100 0101 0111 0111 1001 1001 0010 0010 0011 0100 0110 0110 0001
// 0001 0011 0011 0100 0101 0111 0111 1001 1001 1011 1011 1100 1101 1111 1111 0001