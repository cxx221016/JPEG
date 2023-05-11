#include "../include/parsejpeg.h"

SOF::SOF(std::ifstream& fin)
{
    fin.read(reinterpret_cast<char*>(&length),sizeof(length));
    length=htons(length);
    fin.read(reinterpret_cast<char*>(&precision),sizeof(precision));
    fin.read(reinterpret_cast<char*>(&height),sizeof(height));
    height=htons(height);
    fin.read(reinterpret_cast<char*>(&width),sizeof(width));
    width=htons(width);
    fin.read(reinterpret_cast<char*>(&componentnum),sizeof(componentnum));
    components=new component[componentnum];
    for(unsigned int i=0;i<componentnum;++i)
    {
        fin.read(reinterpret_cast<char*>(&components[i].id),sizeof(components[i].id));
        fin.read(reinterpret_cast<char*>(&components[i].samplingfactors),sizeof(components[i].samplingfactors));
        fin.read(reinterpret_cast<char*>(&components[i].qt),sizeof(components[i].qt));
    }
}

std::ostream& operator<<(std::ostream& os,const SOF& sof)
{
    os<<"length: "<<sof.length<<std::endl;
    os<<"precision: "<<printasnum(sof.precision)<<std::endl;
    os<<"height: "<<sof.height<<std::endl;
    os<<"width: "<<sof.width<<std::endl;
    os<<"componentnum: "<<printasnum(sof.componentnum)<<std::endl;
    return os;
}

void SOF::getprecision()const 
{
    std::cout<<"precision: "<<printasnum(precision)<<std::endl;
}

void SOF::getheight()const 
{
    std::cout<<"height: "<<height<<std::endl;
}

void SOF::getwidth()const 
{
    std::cout<<"width: "<<width<<std::endl;
}

void SOF::getcomponentnum()const 
{
    std::cout<<"componentnum: "<<printasnum(componentnum)<<std::endl;
}

component* SOF::getcomponents()
{
    return reinterpret_cast<component*>(components);
}