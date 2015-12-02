#include <cstdio>
#include <cstring>
#include <unistd.h>

#include <sqlite3.h>

#include "Sqlite3Error.h"

class Experiment
{
    private:

        sqlite3* _db;

        sqlite3_stmt* _stmtAppendGroup;
        sqlite3_stmt* _stmtAppendMicrograph;

    public:

        Experiment();

        Experiment(const char database[]);

        ~Experiment();

        void appendGroup(const char name[]);

        void appendMicrograph(const char name[],
                              const float voltage,
                              const float defocusU,
                              const float defocusV,
                              const float defocusAngle,
                              const float CA);

    private:

        void prepareStatement();

        void finalizeStatement();
};
