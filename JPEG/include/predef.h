#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <string>
#include <sstream>
#include <cmath>
#include <map>
#include <queue>
#include <ctime>
#include <random>
#include <fstream>
#include <stack>
#include <memory>
typedef unsigned char obyte;
typedef unsigned short tbyte;
typedef unsigned int fbyte;

static union
{
    char   xct_order[4];
    uint32_t xut_order;
} xhost_order = { { 'L', '?', '?', 'B' } };

#define LITTLE_ENDIAN ('L' == (char)xhost_order.xut_order)
#define BIG_ENDIAN    ('B' == (char)xhost_order.xut_order)

inline unsigned short ntohs(unsigned short src)
{
    // std::cout << "local htons" << " ";
    if (LITTLE_ENDIAN)
        return ((src << 8) | (src >> 8));
    return src;
}
inline unsigned short htons(unsigned short src)
{
    // std::cout << "local htons" << " ";
    if (LITTLE_ENDIAN)
        return ((src << 8) | (src >> 8));
    return src;
}

inline unsigned int ntohl(unsigned int src)
{
    if (LITTLE_ENDIAN)
        return (((src) << 24) |
                ((src & 0x0000FF00) << 8) |
                ((src & 0x00FF0000) >> 8) |
                ((src) >> 24));
    return src;
}

inline unsigned int htonl(unsigned int src)
{
    if (LITTLE_ENDIAN)
        return (((src) << 24) |
                ((src & 0x0000FF00) << 8) |
                ((src & 0x00FF0000) >> 8) |
                ((src) >> 24));
    return src;
}

template <std::size_t N>
std::string printasnum(const unsigned char (&data)[N])
{
    std::stringstream ss;
    for (unsigned int i = 0; i < N; ++i)
    {
        ss << static_cast<unsigned int>(data[i]);
    }
    return ss.str();
}

inline std::string printasnum(const unsigned char &data)
{
    std::stringstream ss;
    ss << static_cast<unsigned int>(data);
    return ss.str();
}

inline unsigned short pass(std::fstream &fin, unsigned int pass)
{
    unsigned short tmp;
    if (fin.read(reinterpret_cast<char *>(&tmp), pass))
        return htons(tmp);
    return 0;
}

inline void passuntil(std::fstream &fin, unsigned char end = 0xFF)
{
    unsigned char pass;
    while (fin >> pass)
    {
        if (pass == end)
        {
            fin.putback(pass);
            return;
        }
    }
    return;
}

inline bool isjpeg(const std::string &filename)
{
    std::ifstream fin(filename, std::ios::binary);
    if (!fin)
    {
        std::cout << "can't open file" << std::endl;
        return false;
    }
    unsigned char c;
    fin >> c;
    if (c != 0xFF)
        return false;
    fin >> c;
    if (c != 0xD8)
        return false;
    return true;
}


