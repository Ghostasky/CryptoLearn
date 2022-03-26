#include "DES.cpp"
#include <sstream>
#include <algorithm>
// bitset<64> charToBin(const char c[8])
// {
//     bitset<64> bit64;
//     for (int i = 0; i < 8; i++)
//         for (int j = 0; j < 8; j++)
//             bit64[i * 8 + j] = ((c[7 - i] >> j) & 1);
//     return bit64;
// }

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
string binTochar(const bitset<64> bin)
{
    char s[8];
    bitset<8> c;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            c[j] = bin[i * 8 + j];
        s[7 - i] = c.to_ulong();
    }
    string aa = s;

    return aa;
}
string binToHex(const bitset<64> bin)
{
    string ss = bin.to_string();
    // cout << hex << bin << endl;
    string hexa;
    stringstream sss;

    return ss;
}
int main()
{
    string p = "2222222222222222";
    string k = "2222222222222222";

    bitset<64> plain = charToBin(p.c_str());
    bitset<64> key = charToBin(k.c_str());
    cout << "key: " << key << endl;
    DES a;
    bitset<64> cipher = a.Encode(plain, key);

    cout << binToHex(cipher) << endl;

    return 0;
}
// 0001001100110100010101110111100110010010001000110100011001100001
// 0001001100110100010101110111100110011011101111001101111111110001