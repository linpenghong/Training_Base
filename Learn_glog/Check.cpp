#include <iostream>

#include <glog/logging.h>

using namespace std;
using namespace google;

int main(int argc, char* argv[])
{
    InitGoogleLogging(argv[0]);

    CHECK_NE(1, 2) << "1 is not equal to 2";

    /* check. If not true, abort and log this information */
    CHECK_NE(1, 1) << "1 is equal to 1";

    return 0;
}
