# JPEG

## 目录
- [JPEG](#jpeg)
  - [目录](#目录)
  - [摘要](#摘要)
  - [MODULE](#module)
    - [predef.h](#predefh)
    - [APP0](#app0)
    - [APP1](#app1)
    - [DQT](#dqt)
    - [SOF](#sof)
    - [DHT](#dht)
    - [SOS](#sos)
    - [Serial](#serial)
    - [JpegParser](#jpegparser)
  - [UPDATA](#updata)
    - [VERSION 1.0](#version-10)
  - [CONFIG](#config)
    - [request](#request)
    - [config](#config-1)
  - [summary](#summary)
    - [2023 5.12](#2023-512)


## 摘要

> 我了解了一下jpeg文件格式的编码，并打算在此基础上获得其相应信息
> 目前实现了获取APP,DHT,DQT,SOF,SOS的功能并可以对图片进行颜色的修改和加密

## MODULE

### predef.h
定义了一系列内联函数，用于基本的跳过字符以及对unsigned char 的数字打印

### APP0

```cpp
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
};
```


### APP1

调用predef 中的passuntil直接忽略

### DQT

```cpp
struct DQT
{
    unsigned short length;
    unsigned char qt;
    unsigned char* table;

    friend std::ostream& operator<<(std::ostream& os,const DQT& dqt);
    void getqt()const;
    unsigned char* gettable();
};
```

### SOF

```cpp
struct component
{
    unsigned char id;
    unsigned char samplingfactors;
    unsigned char qt;
    friend std::ostream& operator<<(std::ostream& os,const component& c)
};

struct SOF
{
    unsigned short length;
    unsigned char precision;
    unsigned short height;
    unsigned short width;
    unsigned char componentnum;
    component* components;
    friend std::ostream& operator<<(std::ostream& os,const SOF& sof);
    void getprecision()const;
    void getheight()const;
    void getwidth()const;
    void getcomponentnum()const;
    component* getcomponents();
};
```

### DHT

```cpp
struct DHT
{
    unsigned short length;
    unsigned char tc_th;
    unsigned char tablesize;
    unsigned char* bitvaluetable;
    unsigned char* huffmancode;

    friend std::ostream& operator<<(std::ostream& os,const DHT& dht);
    void gettc_th()const;
    void gettablesize() const;
    unsigned char* getbitvaluetable();
    unsigned char* gethuffmancode();
};
```

### SOS

```cpp
struct componentinfo
{
    unsigned char id;
    unsigned char huffmantable;
    friend std::ostream& operator<<(std::ostream& os,const componentinfo& c)
};

struct SOS
{
    unsigned short length;
    unsigned char componentnum;
    componentinfo* componentinfos;
    unsigned char ss;
    unsigned char se;
    unsigned char ah_al;

    friend std::ostream& operator<<(std::ostream& os,const SOS& sos);
    void getcomponentnum()const;
    void getss()const;
    void getse()const;
    void getah_al()const;
    componentinfo* getcomponentinfos();
};
```

### Serial 

```cpp
struct Serial
{
    //inline static unsigned char key=0x64;
    inline static const std::string path=std::string("../data/log.txt");
    std::unordered_map<std::string,unsigned char> keymap;
    unsigned char yhencode(std::fstream& fin,const std::string& filename);
    unsigned char yhdecode(std::fstream& fin,const std::string& filename);
};

该模块可对照片进行随机加密，密钥存储与file下边的文件中
```

### JpegParser

```cpp
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
    bool Parser();
    static bool isjpeg(std::fstream& fin);
    std::shared_ptr<APP0> getapp0();
    std::vector<std::shared_ptr<DQT>> getdqts();
    std::vector<std::shared_ptr<SOF>> getsofs();
    std::vector<std::shared_ptr<DHT>> getdhts();
    std::shared_ptr<SOS> getsos();
    bool encode();
    bool decode();
};
```

该模块负责解析jpeg文件，同时向用户提供各个接口

## UPDATA

### VERSION 1.0
 实现了一部分jpeg的解析，同时能够对文件加密

## CONFIG

### request

> std=c++17

### config

* git clone git@github.com:cxx221016/JPEG.git
* cd OS
* for windows with mingw && cmake
   * rd /S build
   * md build
   * cd build
   * cmake -G cmake -G "MinGW Makefiles" ..
   * mingw32-make
   * cd ../bin
   * main.exe
* for windows with VS && cmake
   * rd /S build
   * md build
   * cd build
   * cmake ..
   * find *.sln
   * open *.sln
* for linux with g++ && cmake
   * rm -rf build
   * mkdir build
   * cd build
   * cmake ..
   * make 
   * cd ../bin
   * ./main

## summary

### 2023 5.12
本程序本不需要依赖winsock或者linux，但是需要htons函数，目前打算自行实现