#pragma once
#include"windows.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<unordered_set>
#include<unordered_map>
#include<set>
#include<string>
#include<sstream>
#include<cmath>
#include<map>
#include<queue>
#include<ctime>
#include<random>
#include<fstream>
#include<stack>
#include<memory>
typedef unsigned char obyte;
typedef unsigned short tbyte;
typedef unsigned int fbyte;

template<std::size_t N>
std::string printasnum(const unsigned char (&data)[N])
{
    std::stringstream ss;
    for(unsigned int i=0;i<N;++i)
    {
        ss<<static_cast<unsigned int>(data[i]);
    }
    return ss.str();
}


inline std::string printasnum(const unsigned char& data)
{
    std::stringstream ss;
    ss<<static_cast<unsigned int>(data);
    return ss.str();
}

inline unsigned short pass(std::ifstream& fin,unsigned int pass)
{
    unsigned short tmp;
    if(fin.read(reinterpret_cast<char*>(&tmp),pass)) return htons(tmp);
    return 0;
}

inline bool isjpeg(const std::string& filename)
{
    std::ifstream fin(filename,std::ios::binary);
    if(!fin) 
    {
        std::cout<<"can't open file"<<std::endl;
        return false;
    }
    unsigned char c;
    fin>>c;
    if(c!=0xFF) return false;
    fin>>c;
    if(c!=0xD8) return false;
    return true;
}

