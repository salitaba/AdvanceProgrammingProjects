#ifndef PICTURE_CHANGER_H
#define PICTURE_CHANGER_H

#include<vector>
#include"RSDL/src/rsdl.hpp"

class PictureChanger{
public:
    PictureChanger();
    PictureChanger(std::vector<std::string> address, int _delyaTime);
    std::string getImageSource();
private:
    std::vector<std::string> sources;
    int delayTime;
    int startTime;
};

#endif