#include <iostream>
#include <complex>
#include <cmath>

#include "mkl.h"

typedef std::complex<float> complex;

void displayVector(const MKL_INT n, const float* x)
{
    for (size_t i = 0; i < n; i++)
        std::cout << x[i] << " ";

    std::cout << std::endl;
};

void displayVector(const MKL_INT n, const complex* x)
{
    for (size_t i = 0; i < n; i++)
        std::cout << x[i] << " ";

    std::cout << std::endl;
};

int main(int argc, char* argv[])
{
    int n = 100;

    float* sx = new float[n];
    for (int i = 0; i < n; i++)
        sx[i] = i;

    complex* cx = new complex[n];
    for (int i = 0; i < n; i++)
        cx[i] = complex(i, i); 

    // s stands for single precision real
    // d stands for double precision real
    // c stands for single precision complex
    // z stands for double precision complex

    std::cout << "Maginitude Sum of Single Precision Real Vector: "
              << cblas_sasum(n, sx, 1) << std::endl;

    std::cout << "Maginitude Sum of Single Precision Complex Vector: "
              << cblas_scasum(n, cx, 1) << std::endl;

    float* sy = new float[n];
    complex* cy = new complex[n];

    std::cout << "Compute a Vector-Scalar Product and Adds the Result to a Vector" << std::endl;
    cblas_saxpy(n, 2.0, sx, 1, sy, 1);
    displayVector(n, sy);
    complex ratio(2.0, -1.0);
    cblas_caxpy(n, &ratio, cx, 1, cy, 1);
    displayVector(n, cy);

    std::cout << "Copy a Vector to Another Vector" << std::endl;
    cblas_scopy(n, sx, 1, sy, 1);
    displayVector(n, sy);
    cblas_ccopy(n, cx, 1, cy, 1);
    displayVector(n, cy);

    std::cout << "Perform Single Precision Real Vector-Vector Dot: "
              << cblas_sdot(n, sx, 1, sy, 1) << std::endl;

    complex cresult;
    std::cout << "Perform Conjugated Single Precision Complex Vector-Vector Dot: ";
    cblas_cdotc_sub(n, cx, 1, cy, 1, &cresult);
    std::cout << cresult << std::endl;

    std::cout << "Perform Unconjugated Single Precision Complex Vector-Vector Dot: ";
    cblas_cdotu_sub(n, cx, 1, cy, 1, &cresult);
    std::cout << cresult << std::endl;

    std::cout << "Euclidean Norm of Single Precision Real Vector: "
              << cblas_snrm2(n, sx, 1) << std::endl;

    std::cout << "Euclidean Norm of Single Precision Complex Vector: "
              << cblas_scnrm2(n, cx, 1) << std::endl;

    std::cout << "sx = " << std::endl;
    displayVector(n, sx);
    std::cout << "sy = " << std::endl;
    displayVector(n, sy);

    float* nsx = new float[n];
    float* nsy = new float[n];
    cblas_scopy(n, sx, 1, nsx, 1);
    cblas_scopy(n, sy, 1, nsy, 1);

    std::cout << "Perform Rotation of Points in the Plane" << std::endl;
    cblas_srot(n, nsx, 1, nsy, 1, sin(0.5), cos(0.5));
    std::cout << "nsx = " << std::endl;
    displayVector(n, nsx);
    std::cout << "nsy = " << std::endl;
    displayVector(n, nsy);

    std::cout << "sx = " << std::endl;
    displayVector(n, sx);
    std::cout << "sy = " << std::endl;
    displayVector(n, sy);
    std::cout << "Computes the PARAMETERS of a Givens Rotation" << std::endl;
    cblas_srotg(sx, sy, nsx, nsy);
    std::cout << "nsx = " << std::endl;
    displayVector(n, nsx);
    std::cout << "nsy = " << std::endl;
    displayVector(n, nsy);

    std::cout << "Compute the Product of a Vector by a Scalar" << std::endl;
    cblas_sscal(n, 2, sx, 1);
    cblas_cscal(n, &ratio, cx, 1);
    displayVector(n, sx);
    displayVector(n, cx);

    std::cout << "sx = " << std::endl;
    displayVector(n, sx);
    std::cout << "sy = " << std::endl;
    displayVector(n, sy);
    std::cout << "Swaps a Vector with Another Vector" << std::endl;
    cblas_sswap(n, sx, 1, sy, 1);
    std::cout << "sx = " << std::endl;
    displayVector(n, sx);
    std::cout << "sy = " << std::endl;
    displayVector(n, sy);

    // isamax -> i : index ; s : single prcesion real ; a : absolute
    std::cout << "The Index of the Element with Maximum Absolute Value: "
              << cblas_isamax(n, sx, 1)
              << std::endl;
    std::cout << "The Index of the Element with Minimum Absolute Value: "
              << cblas_isamin(n, sx, 1)
              << std::endl;

    delete[] sx;
    delete[] cx;
    delete[] sy;
    delete[] cy;

    delete[] nsx;
    delete[] nsy;

    return 0;
}
