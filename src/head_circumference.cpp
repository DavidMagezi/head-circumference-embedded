// Copyright (2023) David A. Magezi
#include <filesystem>
#include <string>

#include "active_geometric_shape/ellipse.h"
#include "active_geometric_shape/gvf.h"

#include "machine_learning/image.h"
#include "machine_learning/logger.h"
#include "machine_learning/unet.h"

namespace AGS = ActiveGeomtericShape;
namespace ML = MachineLearning;


int main(int argc, char** argv) {
    ML::Logger::set_levels(); // comment out to suppress output
    ML::Logger::display_test_message();
    if (argc != 2){
        ML::Logger::display_error_message(argv[0]);
        if (argc > 2){
            ML::Logger::display_error_message("Too many arguments");
        }
        ML::Logger::display_error_message("This program needs ULTRASOUND data");
        ML::Logger::display_error_message("Please obtain these from https://zenodo.org/record/1327317/files/");
        ML::Logger::display_error_message("Download, decompress the compressed files, and place them in a folder");
        ML::Logger::display_error_message("Then give that folder as input to this program");
        return 1;
    }

    ML::Image image(argv[1]);
    image.load_data("031_HC.png");
    image.load_data("030_HC.png");


    //debug start
    //consider 
    //1) convert from dlib to vector
    //2) use QT to visualize (or OpenGL?)
    AGS::double_vector f{0.1,0.2,0.3,0.4};
    int m(2);
    int n(2);
    //debug end

    double alpha(1.0);
    double mu(0.1);
    int iter(50);

    AGS::GVF g(f,m,n,alpha,mu,iter);
    //AGS::pair_double_vector u_v(g.calculate());

    AGS::Ellipse e;

    ML::Unet unet;

    return 0;
}
