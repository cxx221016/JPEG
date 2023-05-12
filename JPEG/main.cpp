#include"./include/parsejpeg.h"

//const std::string filename="..\\1.jpg";

int main()
{
    while(true)
    {
        std::cout<<"please input the filename"<<std::endl;
        std::string filename;
        std::cin>>filename;
        std::cout<<"filename "<<filename<<std::endl;
        if(filename=="exit") break;
        std::ifstream fin(filename,std::ios::binary);
        if(!fin) 
        {
            std::cout<<"can't open file"<<std::endl;
            continue;
        }
        fin.close();
        JpegParser parser(filename);
        parser.Parser();
        while(true)
        {
            std::string cmd;
            std::cout<<"please input the command"<<std::endl;
            std::cin>>cmd;
            if(cmd=="chfile") break;
            else if(cmd=="encode")
            {
                parser.encode();
                continue;
            }
            else if(cmd=="decode")
            {
                parser.decode();
                continue;
            }
            else if(cmd=="APP0")
            {
                std::shared_ptr<APP0> app0=parser.getapp0();
                if(!app0) continue;
                //std::cout<<*app0<<std::endl;
                app0->getidentifier();
                app0->getxthumbnail();
                app0->getythumbnail();
                continue;
            }
            else if(cmd=="DQT")
            {
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
                continue;
            }
            else if(cmd=="SOF")
            {
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
                }
                continue;
            }
            else if(cmd=="DHT")
            {
                std::vector<std::shared_ptr<DHT>> dhts=parser.getdhts();
                for(auto& dht:dhts)
                {
                    std::cout<<*dht<<std::endl;
                }
                continue;
            }
            else if(cmd=="SOS")
            {
                std::shared_ptr<SOS> sos=parser.getsos();
                if(!sos) continue;
                std::cout<<*sos<<std::endl;
                //sos->getcomponentnum();
                continue;
            }
            else std::cout<<"wrong command"<<std::endl;
        }

    }
}