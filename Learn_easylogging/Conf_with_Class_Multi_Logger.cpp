#include "easylogging++.h"

static el::Configurations loggerAConf;
static el::Configurations loggerBConf;

static void loggerInit(el::Configurations conf,
                       const char loggerName[],
                       const char loggerFile[])
{
    conf.setToDefault();

    conf.set(el::Level::Global,
             el::ConfigurationType::Filename,
             loggerFile);

    conf.set(el::Level::Info,
             el::ConfigurationType::ToFile,
             "true");

    conf.set(el::Level::Info,
             el::ConfigurationType::ToStandardOutput,
             "false");

    el::Loggers::reconfigureLogger(loggerName, conf);
}

static void loggerInit()
{
    loggerInit(loggerAConf, "LOGGER_A", "LOGGER_A.log");
    loggerInit(loggerBConf, "LOGGER_B", "LOGGER_B.log");
}

INITIALIZE_EASYLOGGINGPP

int main(int argc, char* argv[])
{
    loggerInit();

    CLOG(INFO, "LOGGER_A") << "Logging into LOGGER_A";
    CLOG(INFO, "LOGGER_B") << "Logging into LOGGER_B";

    return 0;
}
