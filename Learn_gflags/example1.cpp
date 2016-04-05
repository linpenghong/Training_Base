#include <string>
#include <cstdio>

#include <gflags/gflags.h>

// #include "server.h"

DEFINE_bool(memory_pool, false, "If use memory pool");
DEFINE_bool(daemon, true, "If started as daemon");
DEFINE_string(module_id, "", "Server module id");

DEFINE_int32(http_port, 80, "HTTP listen port");
DEFINE_int32(https_port, 443, "HTTPS listen port");

using namespace google;

int main(int argc, char* argv[])
{
    ParseCommandLineFlags(&argc, &argv, true);

    printf("Server module is: %s\n", FLAGS_module_id.c_str());

    if (FLAGS_daemon)
        printf("Run as daemon: %d\n", FLAGS_daemon);

    if (FLAGS_memory_pool)
        printf("Use memory pool: %d\n", FLAGS_daemon);

    // Server server;

    return 0;
}
