//Copyright(2023) Dr. David A. Magezi 
//This code is inspired by dnn_introduction_ex.cpp of dlib

#include <dlib/image_io.h>

#include "logger.h"
#include "image.h"

Image::Image(std::string ultrasound_folder):
    ultrasound_folder_(ultrasound_folder){
}

Image::~Image(){
}

void Image::load_data(std::string filename){
    try{
        Logger::display_info_message("Loading image");
        dlib::array2d<dlib::rgb_pixel> arr1;
        dlib::load_png(arr1,ultrasound_folder_+'/'+filename);
    }
    catch(std::exception& e)
    {
        Logger::display_error_message(e.what());
    }
}

