#include"../include/parsejpeg.h"

SOS::SOS(std::fstream& fin)
{
    //pass(fin,2);
    fin.read(reinterpret_cast<char*>(&length),sizeof(length));
    length=htons(length);
    fin.read(reinterpret_cast<char*>(&componentnum),sizeof(componentnum));
    componentinfos=new componentinfo[componentnum];
    for(unsigned int i=0;i<componentnum;++i)
    {
        fin.read(reinterpret_cast<char*>(&componentinfos[i].id),sizeof(componentinfos[i].id));
        fin.read(reinterpret_cast<char*>(&componentinfos[i].huffmantable),sizeof(componentinfos[i].huffmantable));
    }
    fin.read(reinterpret_cast<char*>(&ss),sizeof(ss));
    fin.read(reinterpret_cast<char*>(&se),sizeof(se));
    fin.read(reinterpret_cast<char*>(&ah_al),sizeof(ah_al));
}

std::ostream& operator<<(std::ostream& os,const SOS& sos)
{
    os<<"length: "<<sos.length<<std::endl;
    os<<"componentnum: "<<printasnum(sos.componentnum)<<std::endl;
    os<<"ss: "<<printasnum(sos.ss)<<std::endl;
    os<<"se: "<<printasnum(sos.se)<<std::endl;
    os<<"ah_al: "<<printasnum(sos.ah_al)<<std::endl;
    return os;
}

void SOS::getcomponentnum()const 
{
    std::cout<<"componentnum: "<<printasnum(componentnum)<<std::endl;
}

componentinfo* SOS::getcomponentinfos()
{
    return componentinfos;
}

void SOS::getss()const 
{
    std::cout<<"ss: "<<printasnum(ss)<<std::endl;
}

void SOS::getse()const 
{
    std::cout<<"se: "<<printasnum(se)<<std::endl;
}

void SOS::getah_al()const 
{
    std::cout<<"ah_al: "<<printasnum(ah_al)<<std::endl;
}