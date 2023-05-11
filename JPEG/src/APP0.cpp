#include "../include/parsejpeg.h"

APP0::APP0(std::fstream &fin)
{
    //pass(fin, 2);
    fin.read(reinterpret_cast<char *>(&length), sizeof(length));
    length = htons(length);
    fin.read(reinterpret_cast<char *>(identifier), sizeof(identifier));
    fin.read(reinterpret_cast<char *>(version), sizeof(version));
    fin.read(reinterpret_cast<char *>(&units), sizeof(units));
    fin.read(reinterpret_cast<char *>(&xdensity), sizeof(xdensity));
    xdensity = htons(xdensity);
    fin.read(reinterpret_cast<char *>(&ydensity), sizeof(ydensity));
    ydensity = htons(ydensity);
    fin.read(reinterpret_cast<char *>(&xthumbnail), sizeof(xthumbnail));
    fin.read(reinterpret_cast<char *>(&ythumbnail), sizeof(ythumbnail));
    unsigned int thumbnailsize = xthumbnail * ythumbnail * 3;
    thumbnail = new unsigned char[thumbnailsize];
    fin.read(reinterpret_cast<char *>(thumbnail), thumbnailsize);
}

std::ostream &operator<<(std::ostream &os, const APP0 &app0)
{
    os << "length: " << app0.length << std::endl;
    os << "identifier: " << app0.identifier << std::endl;
    os << "version: " << printasnum(app0.version) << std::endl;
    os << "units: " << printasnum(app0.units) << std::endl;
    os << "xdensity: " << app0.xdensity << std::endl;
    os << "ydensity: " << app0.ydensity << std::endl;
    os << "xthumbnail: " << printasnum(app0.xthumbnail) << std::endl;
    os << "ythumbnail: " << printasnum(app0.ythumbnail) << std::endl;
    return os;
}

void APP0::getidentifier() const
{
    std::cout << "identifier: " << identifier << std::endl;
}
void APP0::getxthumbnail() const
{
    std::cout << "xthumbnail: " << static_cast<unsigned int>(xthumbnail) << std::endl;
}
void APP0::getythumbnail() const
{
    std::cout << "ythumbnail: " << static_cast<unsigned int>(ythumbnail) << std::endl;
}