#include "../include/parsejpeg.h"

DHT::DHT(std::ifstream& fin)
{
    //pass(fin,2);
    fin.read(reinterpret_cast<char*>(&length),sizeof(length));
    length=htons(length);
    fin.read(reinterpret_cast<char*>(&tc_th),sizeof(tc_th));
    unsigned int tc=tc_th>>4;
    unsigned int th=tc_th&0x0F;
    tc=0;
    unsigned int codesize=tc==0?16:256;
    bitvaluetable=new unsigned char[codesize];
    for(unsigned int i=0;i<codesize;++i)
    {
        fin.read(reinterpret_cast<char*>(&bitvaluetable[i]),sizeof(bitvaluetable[i]));
        tablesize+=bitvaluetable[i];
    }

    huffmancode=new unsigned char[tablesize];
    fin.read(reinterpret_cast<char*>(huffmancode),tablesize);
}

std::ostream& operator<<(std::ostream& os,const DHT& dht)
{
    os<<"length: "<<dht.length<<std::endl;
    os<<"tc_th: "<<printasnum(dht.tc_th)<<std::endl;
    os<<"tablesize: "<<printasnum(dht.tablesize)<<std::endl;
    return os;
}

void DHT::gettc_th()const
{
    std::cout<<"tc_ch: "<<printasnum(tc_th)<<std::endl;
}

void DHT::gettablesize() const
{
    std::cout<<"tablesize: "<<printasnum(tablesize)<<std::endl;
}

unsigned char* DHT::getbitvaluetable()
{
    return bitvaluetable;
}

unsigned char* DHT::gethuffmancode()
{
    return huffmancode;
}