#include <iostream>

#include "tbb/blocked_range.h"
#include "tbb/parallel_scan.h"

using namespace tbb;

template<class T>
class Body
{
    public:

        T reduced_result;
        T* const y;
        const T* const x;

    public:

        Body(T y_[], const T x_[])
            : reduced_result(0),
              x(x_),
              y(y_) {}

        T get_reduced_result() const
        {
            return reduced_result;
        }

        template<typename Tag>
        void operator()(const blocked_range<int>& r, Tag)
        {
            T temp = reduced_result;
            for (int i = r.begin(); i < r.end(); i++)
            {
                temp += x[i];
                if (Tag::is_final_scan())
                    y[i] = temp;
            }
            reduced_result = temp;
        }

        Body(Body& b, split)
            : x(b.x),
              y(b.y),
              reduced_result(0) {}

        void reverse_join(Body& a)
        {
            reduced_result += a.reduced_result;
        }

        void assign(Body& b)
        {
            reduced_result = b.reduced_result;
        }
};

template<class T>
float doParallelScan(T y[], const T x[], int n)
{
    Body<T> body(y, x);
    parallel_scan(blocked_range<int>(0, n), body, auto_partitioner());
    return body.get_reduced_result();
};

int main(int argc, char* argv[])
{
    float a[100];
    float b[100];

    for (int i = 0; i < 100; i++)
    {
        a[i] = i;
        b[i] = 0;
    }

    std::cout << doParallelScan(b, a, 100) << std::endl;

    for (int i = 0; i < 100; i++)
        std::cout << b[i] << std::endl;
    
    return 0;
}
