#pragma once
#include"predef.h"

struct APP0
{
    unsigned short length;
    unsigned char identifier[5];
    unsigned char version[2];
    unsigned char units;
    unsigned short xdensity;
    unsigned short ydensity;
    unsigned char xthumbnail;
    unsigned char ythumbnail;
    unsigned char* thumbnail;
    APP0():length(0),units(0),xdensity(0),ydensity(0),xthumbnail(0),ythumbnail(0),thumbnail(nullptr){}
    APP0(std::fstream& fin);
    ~APP0(){if(thumbnail) delete[] thumbnail;}
    APP0(const APP0&)=delete;
    APP0& operator=(const APP0&)=delete;
    APP0(APP0&&)=delete;
    APP0& operator=(APP0&&)=delete;

    friend std::ostream& operator<<(std::ostream& os,const APP0& app0);
    void getidentifier()const;
    void getxthumbnail()const;
    void getythumbnail()const;
};

struct DQT
{
    unsigned short length;
    unsigned char qt;
    unsigned char* table;
    DQT():length(0),qt(0),table(nullptr){}
    DQT(std::fstream& fin);
    ~DQT(){if(table) delete[] table;}
    DQT(const DQT&)=delete;
    DQT& operator=(const DQT&)=delete;
    DQT(DQT&&)=delete;
    DQT& operator=(DQT&&)=delete;

    friend std::ostream& operator<<(std::ostream& os,const DQT& dqt);
    void getqt()const;
    unsigned char* gettable();
};

struct component
{
    unsigned char id;
    unsigned char samplingfactors;
    unsigned char qt;
    friend std::ostream& operator<<(std::ostream& os,const component& c)
    {
        os<<"id: "<<printasnum(c.id)<<std::endl;
        os<<"samplingfactors: "<<printasnum(c.samplingfactors)<<std::endl;
        os<<"qt: "<<printasnum(c.qt)<<std::endl;
        return os;
    }
};

struct SOF
{
    unsigned short length;
    unsigned char precision;
    unsigned short height;
    unsigned short width;
    unsigned char componentnum;

    component* components;
    SOF():length(0),precision(0),height(0),width(0),componentnum(0),components(nullptr){}
    SOF(std::fstream& fin);
    ~SOF(){if(components) delete[] components;}
    SOF(const SOF&)=delete;
    SOF& operator=(const SOF&)=delete;
    SOF(SOF&&)=delete;
    SOF& operator=(SOF&&)=delete;

    friend std::ostream& operator<<(std::ostream& os,const SOF& sof);
    void getprecision()const;
    void getheight()const;
    void getwidth()const;
    void getcomponentnum()const;
    component* getcomponents();
};



struct DHT
{
    unsigned short length;
    unsigned char tc_th;
    unsigned char tablesize;
    unsigned char* bitvaluetable;
    unsigned char* huffmancode;
    DHT():length(0),tc_th(0),tablesize(0),huffmancode(nullptr),bitvaluetable(nullptr){}
    DHT(std::fstream& fin);
    ~DHT(){if(huffmancode) delete[] huffmancode;}
    DHT(const DHT&)=delete;
    DHT& operator=(const DHT&)=delete;
    DHT(DHT&&)=delete;
    DHT& operator=(DHT&&)=delete;

    friend std::ostream& operator<<(std::ostream& os,const DHT& dht);
    void gettc_th()const;
    void gettablesize() const;
    unsigned char* getbitvaluetable();
    unsigned char* gethuffmancode();
};

struct componentinfo
{
    unsigned char id;
    unsigned char huffmantable;
    friend std::ostream& operator<<(std::ostream& os,const componentinfo& c)
    {
        os<<"id: "<<printasnum(c.id)<<std::endl;
        os<<"huffmantable: "<<printasnum(c.huffmantable)<<std::endl;
        return os;
    }
};

struct SOS
{
    unsigned short length;
    unsigned char componentnum;
    componentinfo* componentinfos;
    unsigned char ss;
    unsigned char se;
    unsigned char ah_al;
    SOS():length(0),componentnum(0),componentinfos(nullptr),ss(0),se(0),ah_al(0){}
    SOS(std::fstream& fin);
    ~SOS(){}
    SOS(const SOS&)=delete;
    SOS& operator=(const SOS&)=delete;
    SOS(SOS&&)=delete;
    SOS& operator=(SOS&&)=delete;

    friend std::ostream& operator<<(std::ostream& os,const SOS& sos);
    void getcomponentnum()const;
    void getss()const;
    void getse()const;
    void getah_al()const;
    componentinfo* getcomponentinfos();
};

struct Serial
{
    //inline static unsigned char key=0x64;
    inline static const std::string path=std::string("../data/log.txt");
    std::unordered_map<std::string,unsigned char> keymap;
    unsigned char yhencode(std::fstream& fin,const std::string& filename);
    unsigned char yhdecode(std::fstream& fin,const std::string& filename);
    Serial();
    ~Serial();
    Serial(const Serial&)=delete;
    Serial& operator=(const Serial&)=delete;
    Serial(Serial&&)=delete;
    Serial& operator=(Serial&&)=delete;
};


class JpegParser
{
private:
    std::shared_ptr<APP0> app0;
    std::vector<std::shared_ptr<DQT>> dqts;
    std::vector<std::shared_ptr<SOF>> sofs;
    std::vector<std::shared_ptr<DHT>> dhts;
    std::shared_ptr<SOS> sos;
    std::fstream fin;
    bool flag;
    std::string filename;
public:
    JpegParser(const std::string& filename,bool flag=false):filename(filename),flag(flag),fin(filename,std::ios::binary|std::ios::in|std::ios::out){}
    ~JpegParser(){fin.close();}
    bool Parser();
    static bool isjpeg(std::fstream& fin);
    std::shared_ptr<APP0> getapp0();
    std::vector<std::shared_ptr<DQT>> getdqts();
    std::vector<std::shared_ptr<SOF>> getsofs();
    std::vector<std::shared_ptr<DHT>> getdhts();
    std::shared_ptr<SOS> getsos();
    bool encode();
    bool decode();
    JpegParser(const JpegParser&)=delete;
    JpegParser& operator=(const JpegParser&)=delete;
    JpegParser(JpegParser&&)=delete;
    JpegParser& operator=(JpegParser&&)=delete;
};






