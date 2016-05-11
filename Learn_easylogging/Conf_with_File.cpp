#include "easylogging++.h"

INITIALIZE_EASYLOGGINGPP

int main(int argc, char* argv[])
{
    // load configuration from file
    el::Configurations conf("easylogging.conf");

    // reconfigure default logger
    el::Loggers::reconfigureLogger("default", conf);

    LOG(INFO) << "My first info log using default logger";

    return 0;
}
