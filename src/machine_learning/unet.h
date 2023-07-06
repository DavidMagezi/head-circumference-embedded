//Copyright 2023 David A. Magezi
//Implementation of U-Net architecture by Ronneberger et al.

#ifndef DEF_ML_UNET
#define DEF_ML_UNET

#include <dlib/dnn.h>

namespace MachineLearning{
class Unet{
public:
    Unet();
    ~Unet();

    using net_type = dlib::loss_multiclass_log<
        dlib::fc<10, 
        dlib::relu<dlib::fc<120, 
        dlib::max_pool<2,2,2,2,dlib::relu<dlib::con<16,5,5,1,1,
        dlib::max_pool<2,2,2,2,dlib::relu<dlib::con<6,5,5,1,1,
        dlib::input<dlib::matrix<unsigned char>>
            >>>>>>>>>>;
};
}//namespace MachineLearning

#endif //DEF_ML_UNET
