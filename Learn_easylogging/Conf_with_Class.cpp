#include "easylogging++.h"

INITIALIZE_EASYLOGGINGPP

int main(int argc, char* argv[])
{
    // declare a Configuration object
    el::Configurations defaultConf;

    // set default value
    defaultConf.setToDefault();
    
    // set INFO level format
    defaultConf.set(el::Level::Info,
                    el::ConfigurationType::Format,
                    "%datetime, %level %msg");

    // set INFO level output file
    defaultConf.set(el::Level::Info,
                    el::ConfigurationType::Filename,
                    "info.log");

    // output to file, not standard output
    defaultConf.set(el::Level::Info,
                    el::ConfigurationType::ToFile,
                    "true");
    defaultConf.set(el::Level::Info,
                    el::ConfigurationType::ToStandardOutput,
                    "false");

    // reconfigure default logger
    el::Loggers::reconfigureLogger("default", defaultConf);

    LOG(INFO) << "My first info log using default logger";

    return 0;
}
