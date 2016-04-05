#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
{
    mat A(3, 3, fill::randn);

    A.save("A.txt", raw_ascii);

    return 0;
}
