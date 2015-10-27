#include <iostream>

#include "chealpix.h"

#define NSIZE 8

void displayVec(double* vec)
{
    std::cout << vec[0] << " "
              << vec[1] << " "
              << vec[2] << std::endl;
}

int main()
{
    long npix = nside2npix(NSIZE);
    std::cout << "number of pixels = " << npix << std::endl;

    long ipnest = 500;
    std::cout << "NESTED index = " << ipnest << std::endl;

    double vec[3];
    pix2vec_nest(NSIZE, ipnest, vec);
    displayVec(vec);

    for (long i = ipnest * 4; i < (ipnest + 1) * 4; i++)
    {
        pix2vec_nest(2 * NSIZE, i, vec);
        displayVec(vec);
    }

    return 0;
}
