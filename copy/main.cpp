#include"./include/parsejpeg.h"

const std::string filename="..\\2.jpg";

int main()
{
    std::ifstream fin(filename,std::ios::binary);
    if(!fin) 
    {
        std::cout<<"can't open file"<<std::endl;
        return 0;
    }
    /*
    unsigned char tmp;
    fin>>tmp>>tmp>>tmp>>tmp;
    */
    JpegParser parser(filename);
    parser.Parser();
    parser.encode();
    /*
    std::shared_ptr<APP0> app0=parser.getapp0();
    if(!app0) return 0;
    std::cout<<*app0<<std::endl;
    app0->getidentifier();
    app0->getxthumbnail();
    app0->getythumbnail();
    */
    /*
    std::vector<std::shared_ptr<DQT>> dqts=parser.getdqts();
    for(auto& dqt:dqts)
    {
        auto table=dqt->gettable();
        for(unsigned int i=0;i<64;++i)
        {
            std::cout<<printasnum(table[i])<<" ";
            if((i+1)%8==0) std::cout<<std::endl;
        }
        std::cout<<std::endl;
    }
    */
   /*
    std::vector<std::shared_ptr<SOF>> sofs=parser.getsofs();
    for(auto& sof:sofs)
    {
        std::cout<<*sof<<std::endl;
        sof->getprecision();
        sof->getheight();
        sof->getwidth();
        sof->getcomponentnum();
        component* components=sof->getcomponents();
        for(unsigned int i=0;i<sof->componentnum;++i)
        {
            std::cout<<components[i]<<std::endl;
        }
    }*/
    /*
    std::vector<std::shared_ptr<DHT>> dhts=parser.getdhts();
    for(auto& dht:dhts)
    {
        //std::cout<<*dht<<std::endl;
        dht->gettc_th();
        dht->gettablesize();
        unsigned char* bitvaluetable=dht->getbitvaluetable();
        unsigned char* huffmancode=dht->gethuffmancode();
        for(unsigned int i=0;i<dht->tablesize;++i)
        {
            std::cout<<printasnum(bitvaluetable[i])<<" "<<printasnum(huffmancode[i])<<std::endl;
        }
    }
    */
   /*
    std::shared_ptr<SOS> sos=parser.getsos();
    if(!sos) return 0;
    std::cout<<*sos<<std::endl;
    auto componentinfos=sos->getcomponentinfos();
    for(unsigned int i=0;i<sos->componentnum;++i)
    {
        std::cout<<componentinfos[i]<<std::endl;
    }
    */
    return 0;
}