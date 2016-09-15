#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a = "abcd.mrc";

    cout << a.rfind('.') << endl;

    cout << a.substr(0, a.rfind('.') - 1) << endl;

    cout << a.substr(0, a.rfind('.') - 1) + "_stack.mrc" << endl;

    string b = "000145@Particles/20150911/stack_0004_2x_SumCorr_particles.mrcs";

    cout << b.find('@') << endl;

    cout << b.substr(0, b.find('@')) << endl;

    cout << b.substr(b.find('@') + 1) << endl;

    int nSlc = atoi(b.substr(0, b.find('@')).c_str());

    cout << "nSlc = " << nSlc << endl;
    cout << "filename = " << b.substr(b.find('@') + 1) << endl;
}
