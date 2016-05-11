#include "easylogging++.h"

INITIALIZE_EASYLOGGINGPP

int main(int argc, char* argv[])
{
    el::Loggers::configureFromGlobal("easylogging_multi_logger.conf");

    CLOG(INFO, "LOGGER_A") << "My first info log using default logger";
    CLOG(INFO, "LOGGER_B") << "My first info log using default logger";

    return 0;
}
