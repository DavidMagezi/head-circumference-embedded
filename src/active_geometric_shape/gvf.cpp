//Copyright (2023) David A. Magezi
#include "active_geometric_shape/gvf.h"

namespace ActiveGeomtericShape{
GVF::GVF(double_vector f, int m, int n, double alpha, double mu, int iter):
    f_(f),
    m_(m),
    n_(n),
    gradient_length_((m_+2)*(n_+2)),
    alpha_(alpha),
    mu_(mu),
    iter_(iter){
    }

GVF::~GVF(){
}

pair_double_vector GVF::calculate(){

    //normalize
    double fmin,fmax;

    //use algorithm (or lambda function? to find maximum and minimum): std::max??
    if(fmax<=fmin){
        //Error Message about input
    }

    // gradient
    double_vector f2(bound_mirror_expand(f_));
    double_vector fx(gradient_length_);
    double_vector fy(gradient_length_);

    // initialization
    double_vector u1(gradient_length_);
    double_vector v1(gradient_length_);

    //copy matrix 
    //use std::copy []?
    //fx -> u1
    //fy -> v1

    // square of magnitude
    //use std::algorithm to square ech element []
    
    //bound_mirror_ensure
    //del2
    //use alpha and mu
    //bound_mirror_shrink
    

    //copyMatrix

    pair_double_vector u_v; 
    return u_v;
}

std::vector<double> GVF::bound_mirror_expand(std::vector<double> A) {
    double_vector B(gradient_length_);
    B[0+0*(m_+2)]=A[1+1*m_];
    B[(m_+1)+0*(m_+2)]=A[(m_-2)+1*m_];
    B[0+(n_+1)*(m_+2)]=A[1+(n_-2)*m_];
    B[(m_+1)+(n_+1)*(m_+2)]=A[(m_-2)+(n_-2)*m_];
    for(int i=1;i<n_+1;i++)
    {
        B[0+i*(m_+2)]=A[1+(i-1)*m_];
        B[m_+1+i*(m_+2)]=A[m_-2+(i-1)*m_];
    }
    for(int i=1;i<m_+1;i++)
    {
        B[i+0*(m_+2)]=A[(i-1)+1*m_];
        B[i+(n_+1)*(m_+2)]=A[i-1+(n_-2)*m_];
    }
    for(int i=1;i<m_+1;i++)
    {
        for(int j=1;j<n_+1;j++)
        {
            B[i+j*(m_+2)]=A[i-1+(j-1)*m_];
        }
    }
    return B;
}

void GVF::gradient(double_vector f2, double_vector fx, double_vector fy){
    for(int i=0;i<m_;i++)
    {
        for(int j=0;j<n_;j++)
        {
            // fx
            if(j==0)
            {
                fx[i+j*m_]=f2[i+(j+1)*m_]-f2[i+j*m_];
            }
            else if(j==n_-1)
            {
                fx[i+j*m_]=f2[i+j*m_]-f2[i+(j-1)*m_];
            }
            else
            {
                fx[i+j*m_]=(f2[i+(j+1)*m_]-f2[i+(j-1)*m_])/2;
            }
            
            // fy
            if(i==0)
            {
                fy[i+j*m_]=f2[i+1+j*m_]-f2[i+j*m_];
            }
            else if(i==m_-1)
            {
                fy[i+j*m_]=f2[i+j*m_]-f2[i-1+j*m_];
            }
            else
            {
                fy[i+j*m_]=(f2[i+1+j*m_]-f2[i-1+j*m_])/2;
            }
        }
    }
}

}//namespace ActiveGeometricShape
