#include <iostream>

#include <glog/logging.h>

using namespace std;
using namespace google;

int main(int argc, char* argv[])
{
    InitGoogleLogging(argv[0]);

    LOG(INFO) << "INFO";
    LOG(WARNING) << "WARNING";
    LOG(ERROR) << "ERROR";
    LOG(FATAL) << "FATAL";

    return 0;
}
