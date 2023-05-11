#include"../include/parsejpeg.h"

DQT::DQT(std::fstream& fin)
{
    //pass(fin,2);
    fin.read(reinterpret_cast<char*>(&length),sizeof(length));
    length=htons(length);
    fin.read(reinterpret_cast<char*>(&qt),sizeof(qt));
    unsigned int pq=qt>>4;
    unsigned int tablesize= pq==0?64:128;
    table=new unsigned char[tablesize];
    fin.read(reinterpret_cast<char*>(table),tablesize);
}

std::ostream& operator<<(std::ostream& os,const DQT& dqt)
{
    os<<"length: "<<dqt.length<<std::endl;
    os<<"qt: "<<printasnum(dqt.qt)<<std::endl;
    return os;
}

void DQT::getqt() const
{
    std::cout<<"qt: "<<printasnum(qt)<<std::endl;
}

unsigned char* DQT::gettable()
{
    return table;
}
