//Copyright (2023) Dr. David A. Magezi
#ifndef DEF_AGS_GVF
#define DEF_AGS_GVF

#include <utility>
#include <vector>

namespace ActiveGeomtericShape{
///
///\brief To calcluate gradient vector flow
///
///Coded based on C++ version of Wang et al. (2012)
///Algorithm based on Xu and Prince (1998)
typedef std::pair<std::vector<double>,std::vector<double>> pair_double_vector;
typedef std::vector<double> double_vector;
class GVF{
public:
    GVF(double_vector f, int m, int n, double alpha, double mu, int iter);
    ~GVF();
    pair_double_vector calculate();

private:
    double_vector bound_mirror_expand(double_vector A);
    void gradient(double_vector f2, double_vector fx, double_vector fy);

    double alpha_, mu_;
    double_vector f_;
    size_t gradient_length_;
    int iter_, m_, n_;
};
}//namespace ActiveGeometricShape
#endif //DEF_AGS_GVF
