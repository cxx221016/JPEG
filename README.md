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