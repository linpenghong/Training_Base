#include <iostream>
#include <Eigen/Dense>
#include <ctime>

using namespace Eigen;
using namespace std;

int main()
{
    MatrixXf mat = MatrixXf::Random(1000, 1000);
    
    time_t aTime = time(NULL); 
    cout << aTime << endl;

    mat = mat * mat;
    
    time_t bTime = time(NULL); 
    cout << bTime << endl;

    cout << "the result mat is:\n"
         << mat << endl;
    cout << "Using time: " << bTime - aTime << endl;
}
