#include <iostream>

#include "chealpix.h"

#define NSIZE 8

int main()
{
    long npix = nside2npix(NSIZE);
    std::cout << "number of pixels = " << npix << std::endl;

    double vec[3];
    for (long i = 0; i < npix; i++)
    {
        pix2vec_nest(NSIZE, i, vec);
        std::cout << vec[0] << " "
                  << vec[1] << " "
                  << vec[2] << std::endl;
    }

    return 0;
}
