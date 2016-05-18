#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    cout << argv[0] << endl;

    cout << (string(argv[0]) + ".log").c_str() << endl;
}
