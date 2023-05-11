#include"../include/parsejpeg.h"

bool JpegParser::Parser()
{
    if(!isjpeg(fin)) return false ;//SOI
    //app0=std::make_shared<APP0>(fin); //APP0
    unsigned short cmd=0;
    while((cmd=pass(fin,2))!=0)
    {
        //std::cout<<std::hex<<cmd<<std::endl;
        if(cmd==0xFFE0) app0=std::make_shared<APP0>(fin);
        else if(cmd==0xFFE1)  passuntil(fin);
        else if(cmd==0xFFDB) dqts.push_back(std::make_shared<DQT>(fin));
        else if(cmd==0XFFC0) sofs.push_back(std::make_shared<SOF>(fin));
        else if(cmd==0xFFC4) dhts.push_back(std::make_shared<DHT>(fin) );
        else if(cmd==0xFFDA) sos=std::make_shared<SOS>(fin);
        else if(cmd==0xFFD9) break;
        else break;
    }
    flag=true;
    //std::cout<<fin.tellg()<<std::endl;
    return true;
}

bool JpegParser::isjpeg(std::fstream& fin)
{
    unsigned char c;
    fin>>c;
    if(c!=0xFF) return false;
    fin>>c;
    if(c!=0xD8) return false;
    return true;
}

std::shared_ptr<APP0> JpegParser::getapp0()
{
    if(flag) return app0;
    return nullptr;
}

std::vector<std::shared_ptr<DQT>> JpegParser::getdqts()
{
    if(flag) return dqts;
    return std::vector<std::shared_ptr<DQT>>();
}

std::vector<std::shared_ptr<SOF>> JpegParser::getsofs()
{
    if(flag) return sofs;
    return std::vector<std::shared_ptr<SOF>>();
}

std::vector<std::shared_ptr<DHT>> JpegParser::getdhts()
{
    if(flag) return dhts;
    return std::vector<std::shared_ptr<DHT>>();
}

std::shared_ptr<SOS> JpegParser::getsos()
{
    if(flag) return sos;
    return nullptr;
}

bool JpegParser::encode()
{
    Serial serial;
    serial.yhencode(fin,filename);
    return true;
}

bool JpegParser::decode()
{
    Serial serial;
    serial.yhdecode(fin,filename);
    return true;
}