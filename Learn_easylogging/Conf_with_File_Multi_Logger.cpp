#include "easylogging++.h"

INITIALIZE_EASYLOGGINGPP

int main(int argc, char* argv[])
{
    el::Loggers::configureFromGlobal("easylogging_multi_logger.conf");

    CLOG(INFO, "LOGGER_A") << "Logging into LOGGER_A";
    CLOG(INFO, "LOGGER_B") << "Logging into LOGGER_B";

    return 0;
}
