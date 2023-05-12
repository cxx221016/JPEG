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

unsigned char Serial::yhencode(std::fstream& fin,const std::string& filename)
{
    std::default_random_engine e(time(nullptr));
    std::uniform_int_distribution<int> u;
    unsigned char key=u(e)%(256-32)+32;
    if(keymap.count(filename)) 
    {
        std::cout<<"may demage the jpg"<<std::endl;
        std::string cmd;
        std::cout<<"Continue decoding(yes/no)"<<std::endl;
        std::cin>>cmd;
        if(cmd!="yes")
        {
            return 0;
        }
    }
    keymap[filename]=key;
    unsigned char ch;
    int curidx=fin.tellg();
    fin.seekg(0,std::ios::end);
    int endidx=fin.tellg();
    fin.seekg(curidx,std::ios::beg);
    unsigned int filesize=endidx-curidx-2;
    unsigned char filebuf[filesize];
    fin.read(reinterpret_cast<char*>(filebuf),filesize);
    for(unsigned int i=0;i<filesize;++i)
    {
        unsigned char tmp=filebuf[i];
        if(tmp==0xFF) continue;
        filebuf[i]^=key;
        if(filebuf[i]==0xFF)  filebuf[i]=tmp;
    }
    fin.seekg(curidx,std::ios::beg);
    fin.write(reinterpret_cast<char*>(filebuf),filesize);
    fin.seekg(curidx,std::ios::beg);
    return key;
}

unsigned char Serial::yhdecode(std::fstream& fin,const std::string& filename)
{
    //unsigned char key=keymap[filename];
    auto it=keymap.find(filename);
    if(it==keymap.end())
    {
        std::cout<<"can't find key"<<std::endl;
        exit(1);
    }
    unsigned char key=it->second;
    int curidx=fin.tellg();
    fin.seekg(0,std::ios::end);
    int endidx=fin.tellg();
    fin.seekg(curidx,std::ios::beg);
    unsigned int filesize=endidx-curidx-2;
    
    unsigned char filebuf[filesize];
    fin.read(reinterpret_cast<char*>(filebuf),filesize);
    for(unsigned int i=0;i<filesize;++i)
    {
        unsigned char tmp=filebuf[i];
        if(tmp==0xFF) continue;
        filebuf[i]^=key;
        if(filebuf[i]==0xFF)  filebuf[i]=tmp;
    }
    fin.seekg(curidx,std::ios::beg);
    fin.write(reinterpret_cast<char*>(filebuf),filesize);
    fin.seekg(curidx,std::ios::beg);
    return key;
}