//Copyright (2023) Dr. David A. Magezi
#ifndef DEF_AGS_ELLIPSE
#define DEF_AGS_ELLIPSE

#include <vector>
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
#endif //DEF_AGS_ELLIPSE

