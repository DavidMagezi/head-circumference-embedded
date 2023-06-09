//Copyright(2023) Dr. David A. Magezi 

#ifndef DEF_ML_IMAGE
#define DEF_ML_IMAGE

#include <filesystem>
#include <string>
#include <vector>

#include <opencv2/opencv.hpp>

namespace MachineLearning{
class Image{
public:
    Image(std::string ultrasound_folder);
    ~Image();

    void load_data(std::string filename);
    std::filesystem::path safe_append(std::filesystem::path original,std::string addition); 
    void set_test_status(bool test_status);

private:
    std::filesystem::path get_mask_path();

    bool test_status_;
    std::filesystem::path current_subfolder_, image_path_;
    inline static const std::string image_extension_ = "png";
    inline static const std::string mask_suffix_ = "_Annotation";
    inline static const std::string mask_tail_ = mask_suffix_ + "." + image_extension_;
    inline static const std::string test_subfolder_ = "test_set/";
    inline static const std::string training_subfolder_ = "training_set/";
    std::filesystem::path ultrasound_folder_;
    std::vector<int> mask_vec, us_image_vec;
    cv::Mat mask_cv, us_image_cv;
};
}//namespace MachineLearning

#endif //DEF_ML_IMAGE
