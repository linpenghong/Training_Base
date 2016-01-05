#include <iostream>
#include <random>

#include <armadillo>

using namespace std;
using namespace arma;

int main()
{
    cout << "****** imbue ******" << endl;

    mt19937 engine;

    uniform_real_distribution<double> distr(0.0, 1.0);

    mat A(4, 5);
    A.imbue([&](){return distr(engine);});

    cout << A << endl;

    cout << "****** transform ******" << endl;

    mat B = ones<mat>(4, 5);
    B.transform([](double val){ return (val + 123); });

    cout << B << endl;

    cout << "****** for_each ******" << endl;

    mat C = ones<mat>(4, 5);
    C.for_each([](mat::elem_type& val){ val += 123.0; }); 

    cout << C << endl;

    cout << "****** each_col & each_row ******" << endl;

    mat X = ones<mat>(6, 5);
    vec v = linspace<vec>(10, 15, 6);
    cout << X << endl;
    cout << v << endl;

    X.each_col() += v;
    cout << X << endl;
    mat Y = X.each_col() + v;
    cout << Y << endl;
    
    // substract v from columns 0 through to 3 in X
    X.cols(0, 3).each_col() -= v;
    cout << X << endl;

    // lambda function of each_col
    X.each_col([](vec& a){ a.print(); });

    return 0;
}
