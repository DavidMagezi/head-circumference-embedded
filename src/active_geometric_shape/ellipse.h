//Copyright (2023) Dr. David A. Magezi
#ifndef DEF_AGS_ELLIPSE
#define DEF_AGS_ELLIPSE

#include <vector>
///
///\brief Classes to fit predefined shapes to data
///
///Based on the article by Wang et al. (2012)
///
namespace ActiveGeomtericShape{
///
///\brief To find and fit an ellipse in 2D image data
///
///Based on Wang et al. (2012)
///
class Ellipse{
public:
    struct Image{
        size_t width;
        size_t height;
        std::vector<double> x;
    };
    void calculate_force_field(Ellipse::Image i);


private:
    Ellipse::Image force_field_;
};
}//namespace ActiveGeometricShape
#endif //DEF_AGS_ELLIPSE

