#include"../include/parsejpeg.h"

Serial::Serial()
{
    std::ifstream flog(path);
    if(!flog.is_open())
    {
        std::cout<<"open log file failed"<<std::endl;
        exit(1);
    }
    std::string filename;
    unsigned char key;
    while(flog>>filename>>key)
    {
        keymap[filename]=key;
    }
    flog.close();
}

Serial::~Serial()
{
    std::ofstream flog(path,std::ios::out);
    if(!flog.is_open())
    {
        std::cout<<"open log file failed"<<std::endl;
        exit(1);
    }
    for(auto& p:keymap)
    {
        flog<<p.first<<" "<<p.second<<std::endl;
    }
    flog.close();
}

unsigned char Serial::yhencode(std::ifstream& fin,const std::string& filename)
{
    std::default_random_engine e(time(nullptr));
    std::uniform_int_distribution<int> u;
    unsigned char key=u(e)%(256-32)+32;
    keymap[filename]=key;
    unsigned char ch;
    int curidx=fin.tellg();
    fin.seekg(0,std::ios::end);
    int endidx=fin.tellg();
    fin.seekg(curidx,std::ios::beg);
    unsigned int filesize=endidx-curidx-2;
    std::cout<<std::hex<<curidx<<" "<<endidx<<" "<<filesize<<std::endl;
    unsigned char filebuf[filesize];
    fin.read(reinterpret_cast<char*>(filebuf),filesize);
    for(unsigned int i=0;i<filesize;++i)
    {
        filebuf[i]^=key;
    }
    //fin.seekg(curidx,std::ios::beg);
    /*
    for(unsigned int i=0;i<filesize;++i)
    {
        fin.putback(filebuf[filesize-i-1]);
    }
    */
    fin.close();
    std::ofstream tmp(filename,std::ios::binary|std::ios::app);
    if(!tmp.is_open())
    {
        std::cout<<"open file failed"<<std::endl;
        exit(1);
    }
    tmp.seekp(curidx,std::ios::beg);
    tmp.write(reinterpret_cast<char*>(filebuf),filesize);
    tmp.close();
    fin.open(filename,std::ios::binary);
    fin.seekg(-2,std::ios::end);
    

    /*
    while(fin>>ch)
    {
        if(ch==0xFF)
        {
            fin.putback(ch);
            std::cout<<"encode over! key = "<<printasnum(key)<<std::endl;
            break;
        }
        ch^=key;
    }
    */
    return key;
}

unsigned char Serial::yhdecode(std::ifstream& fin,const std::string& filename)
{
    //unsigned char key=keymap[filename];
    auto it=keymap.find(filename);
    if(it==keymap.end())
    {
        std::cout<<"can't find key"<<std::endl;
        exit(1);
    }
    unsigned char key=it->second;
    unsigned char ch;
    while(fin>>ch)
    {
        if(ch==0xFF)
        {
            fin.putback(ch);
            std::cout<<"decode over! key = "<<printasnum(key)<<std::endl;
            break;
        }
        ch^=key;
    }
    return key;
}