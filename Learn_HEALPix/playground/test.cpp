#define PI 3.1415926

#include <iostream>

#include "chealpix.h"

void displayVec(double* vec)
{
    for (int i = 0; i < 3; i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
}

int main()
{
    std::cout << "****** ang2vec ******" << std::endl;
    double theta = PI / 2;
    double phi = PI / 2;
    double vec[3];
    ang2vec(theta, phi, vec);
    displayVec(vec);

    std::cout << "****** npix2nisde ******" << std::endl;
    long npix = 786432;
    std::cout << npix2nside(npix) << std::endl;

    std::cout << "****** nside2npix ******" << std::endl;
    long nside = 256;
    std::cout << nside2npix(nside) << std::endl;

    std::cout << "****** pix2ang ******" << std::endl;
    long ipring = 10000; // ipring -> Index_Pixel_Ring
    pix2ang_ring(nside, ipring, &theta, &phi);
    std::cout << "theta = " << theta << std::endl;
    std::cout << "phi = " << phi << std::endl;

    std::cout << "****** pix2vec ******" << std::endl;
    pix2vec_ring(nside, ipring, vec);
    displayVec(vec);

    std::cout << "****** ang2pix ******" << std::endl;
    ang2pix_ring(nside, theta, phi, &ipring);
    std::cout << "ipring = " << ipring << std::endl;
}
