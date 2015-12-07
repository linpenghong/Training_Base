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
        sqlite3_stmt* _stmtAppendParticle;

    public:

        Experiment();

        Experiment(const char database[]);

        ~Experiment();

        void openDatabase(const char database[]);

        void saveDatabase(sqlite3* database);

        void saveDatabase(const char database[]);

        void createTableGroups();

        void createTableMicrographs();
        
        void createTableParticles();

        void appendGroup(const char name[],
                         const int id = -1);

        void appendMicrograph(const char name[],
                              const float voltage,
                              const float defocusU,
                              const float defocusV,
                              const float defocusAngle,
                              const float CA,
                              const int id = -1);

        void appendParticle(const char name[],
                            const int groupID,
                            const int micrographID);

        void mergeParticles(sqlite3* database);

        void mergeParticles(const char database[]);

    private:
        
        void setTempInMemory();
        /* store temp in memory */

        void finalizeStatement();
};
