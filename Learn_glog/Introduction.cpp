#include <iostream>

#include <glog/logging.h>

using namespace std;
using namespace google;

int main(int argc, char* argv[])
{
    InitGoogleLogging(argv[0]);

    int n = atoi(argv[1]);

    LOG(INFO) << "Found " << n << " 2 cookies";

    LOG_IF(INFO, n > 10) << "Got lots of cookies";

    for (int i = 0; i < 100; i++)
    {
        LOG_EVERY_N(INFO, 10) << "Got the " << COUNTER << "th cookie";
    }

    for (int i = 0; i < 100; i++)
    {
        LOG_FIRST_N(INFO, 5) << "Got the " << COUNTER << "th cookie";
    }

    return 0;
}
