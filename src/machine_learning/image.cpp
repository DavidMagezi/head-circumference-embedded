//Copyright(2023) Dr. David A. Magezi 
//This code is inspired by dnn_introduction_ex.cpp of dlib

#include <algorithm>
#include <sstream>

#include <dlib/image_io.h>

#include "machine_learning/image.h"
#include "machine_learning/logger.h"

namespace MachineLearning{
Image::Image(std::string ultrasound_folder):
    test_status_(false),
    ultrasound_folder_(ultrasound_folder),
    current_subfolder_(test_status_ ? safe_append(ultrasound_folder,test_subfolder_) : safe_append(ultrasound_folder,training_subfolder_)),
    image_path_(current_subfolder_),
    mask_vec(0),
    us_image_vec(0){
}

Image::~Image(){
}

void Image::load_data(std::string filename){
    if (!image_path_.has_filename()){
        image_path_ /= filename;
    } else {
        image_path_.replace_filename(filename);
    }
    try{
        std::string loading_message("Loading image: " + std::string(image_path_)); 
        Logger::display_info_message(loading_message);
        dlib::array2d<dlib::rgb_pixel> us_image;
        dlib::load_png(us_image,image_path_);
        //std::copy(us_image.begin(),us_image.end(),std::back_inserter(us_image_vec));
        
        if (!test_status_){
            dlib::array2d<int> mask;
            Logger::display_info_message("Loading mask");
            dlib::load_png(mask,get_mask_path());
        }
    }
    catch(std::exception& e)
    {
        Logger::display_error_message(e.what());
    }
}


std::filesystem::path Image::safe_append(std::filesystem::path original, std::string addition){
    std::filesystem::path new_path(original);
    if (image_path_.has_filename()){
        std::stringstream ss;
        ss << std::filesystem::path::preferred_separator << std::endl; 
        new_path /= ss.str();
    }
    new_path /= addition;
    return new_path;
}

void Image::set_test_status(bool test_status){
    test_status_ = test_status;
}

// private functions

std::filesystem::path Image::get_mask_path(){
    std::string stem = image_path_.stem();
    std::string mask_filename(stem + mask_tail_);
    std::filesystem::path mask_path(image_path_.parent_path().append(mask_filename));
    Logger::display_info_message(image_path_.parent_path().append(mask_filename));
    return mask_path;
}
}//namespace MachineLearning
