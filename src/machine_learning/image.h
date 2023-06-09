//Copyright(2023) Dr. David A. Magezi 

#ifndef DEF_IMAGE
#define DEF_IMAGE

#include <string>
#include <vector>

class Image{
public:
    Image(std::string ultrasound_folder);
    ~Image();

    void load_data(std::string filename);

private:
    std::string ultrasound_folder_;
};

#endif //DEF_IMAGE
