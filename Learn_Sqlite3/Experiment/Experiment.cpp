#include "Experiment.h"

Experiment::Experiment()
{
    // create an in-memory database
    SQLITE3_HANDLE_ERROR(sqlite3_open(":memory:", &_db));

    setTempInMemory();
}

Experiment::Experiment(const char database[])
{
    openDatabase(database);
}

Experiment::~Experiment()
{
    // finalize all statements
    finalizeStatement();

    // disconnect the database
    SQLITE3_HANDLE_ERROR(sqlite3_close(_db));
}

void Experiment::openDatabase(const char database[])
{
    // connect to the data base
    SQLITE3_HANDLE_ERROR(sqlite3_open(database, &_db));
    
    setTempInMemory();
}

void Experiment::saveDatabase(sqlite3* database)
{
    sqlite3_backup* backupDB = sqlite3_backup_init(database,
                                                   "main",
                                                   _db,
                                                   "main");

    if (backupDB)
    {
        SQLITE3_HANDLE_ERROR(sqlite3_backup_step(backupDB, -1));
        SQLITE3_HANDLE_ERROR(sqlite3_backup_finish(backupDB));
    }
}

void Experiment::saveDatabase(const char database[])
{
    // open dst database
    sqlite3* dstDB;
    SQLITE3_HANDLE_ERROR(sqlite3_open(database, &dstDB));

    // save to dst database
    saveDatabase(dstDB);
}

void Experiment::createTableGroups()
{
    // create table groups
    SQLITE3_HANDLE_ERROR(
            sqlite3_exec(_db,
                         "create table groups(ID integer primary key, \
                                              Name text);",
                         NULL,
                         NULL,
                         NULL)); 

    // prepare statement
    const char sql[] = "insert into groups values (?, ?)";
    SQLITE3_HANDLE_ERROR(
            sqlite3_prepare_v2(_db,
                               sql,
                               strlen(sql),
                               &_stmtAppendGroup,
                               NULL));
}

void Experiment::createTableMicrographs()
{
    // create table micrographs
    SQLITE3_HANDLE_ERROR(
            sqlite3_exec(_db,
                         "create table micrographs(ID integer primary key, \
                                                   Name text, \
                                                   Voltage real not null, \
                                                   DefocusU real not null, \
                                                   DefocusV real not null, \
                                                   DefocusAngle real not null, \
                                                   CA real not null);",
                         NULL,
                         NULL,
                         NULL));

    // prepare statement
    const char sql[] = "insert into micrographs \
                        values (?, ?, ?, ?, ?, ?, ?)";
    SQLITE3_HANDLE_ERROR(
            sqlite3_prepare_v2(_db,
                               sql,
                               strlen(sql),
                               &_stmtAppendMicrograph,
                               NULL));
}

void Experiment::createTableParticles()
{
    SQLITE3_HANDLE_ERROR(
            sqlite3_exec(_db,
                         "create table particles( \
                                  ID integer primary key, \
                                  Name text, \
                                  GroupID integer not null, \
                                  MicrographID integer not null, \
                                  IpCoarse integer, \
                                  IpFine integer, \
                                  Subset integer);",
                         NULL,
                         NULL,
                         NULL));
    
    // prepare statement
    const char sql[] = "insert into particles (Name, GroupID, MicrographID) \
                        values (?, ?, ?)";
    SQLITE3_HANDLE_ERROR(
            sqlite3_prepare_v2(_db,
                               sql,
                               strlen(sql),
                               &_stmtAppendParticle,
                               NULL));
}

void Experiment::appendGroup(const char name[],
                             const int id)
{
    if (id != -1)
        SQLITE3_HANDLE_ERROR(sqlite3_bind_int(_stmtAppendGroup, 1, id));
    else
        SQLITE3_HANDLE_ERROR(sqlite3_bind_null(_stmtAppendGroup, 1));

    SQLITE3_HANDLE_ERROR(
            sqlite3_bind_text(_stmtAppendGroup,
                              2,
                              name,
                              strlen(name),
                              SQLITE_TRANSIENT));
    SQLITE3_HANDLE_ERROR(sqlite3_step(_stmtAppendGroup));
    SQLITE3_HANDLE_ERROR(sqlite3_reset(_stmtAppendGroup));
}

void Experiment::appendMicrograph(const char name[],
                                  const float voltage,
                                  const float defocusU,
                                  const float defocusV,
                                  const float defocusAngle,
                                  const float CA,
                                  const int id)
{
    if (id != -1)
        SQLITE3_HANDLE_ERROR(sqlite3_bind_int(_stmtAppendMicrograph, 1, id));
    else
        SQLITE3_HANDLE_ERROR(sqlite3_bind_null(_stmtAppendMicrograph, 1));

    SQLITE3_HANDLE_ERROR(
            sqlite3_bind_text(_stmtAppendMicrograph,
                              2,
                              name,
                              strlen(name),
                              SQLITE_TRANSIENT));
    SQLITE3_HANDLE_ERROR(
            sqlite3_bind_double(_stmtAppendMicrograph,
                                3,
                                voltage));
    SQLITE3_HANDLE_ERROR(
            sqlite3_bind_double(_stmtAppendMicrograph,
                                4,
                                defocusU));
    SQLITE3_HANDLE_ERROR(
            sqlite3_bind_double(_stmtAppendMicrograph,
                                5,
                                defocusV));
    SQLITE3_HANDLE_ERROR(
            sqlite3_bind_double(_stmtAppendMicrograph,
                                6,
                                defocusAngle));
    SQLITE3_HANDLE_ERROR(
            sqlite3_bind_double(_stmtAppendMicrograph,
                                7,
                                CA));
    SQLITE3_HANDLE_ERROR(sqlite3_step(_stmtAppendMicrograph));
    SQLITE3_HANDLE_ERROR(sqlite3_reset(_stmtAppendMicrograph));
}

void Experiment::appendParticle(const char name[],
                                const int groupID,
                                const int micrographID)
{
    SQLITE3_HANDLE_ERROR(
            sqlite3_bind_text(_stmtAppendParticle,
                              1,
                              name,
                              strlen(name),
                              SQLITE_TRANSIENT));
    SQLITE3_HANDLE_ERROR(
            sqlite3_bind_int(_stmtAppendParticle,
                             2,
                             groupID));
    SQLITE3_HANDLE_ERROR(
            sqlite3_bind_int(_stmtAppendParticle,
                             3,
                             micrographID));
    SQLITE3_HANDLE_ERROR(sqlite3_step(_stmtAppendParticle));
    SQLITE3_HANDLE_ERROR(sqlite3_reset(_stmtAppendParticle));
}

void Experiment::mergeParticles(sqlite3* database)
{
}

void Experiment::mergeParticles(const char database[])
{
}

void Experiment::setTempInMemory()
{
    SQLITE3_HANDLE_ERROR(sqlite3_exec(_db,
                                      "pragma temp_store = memory",
                                      NULL,
                                      NULL,
                                      NULL));
}

void Experiment::finalizeStatement()
{
    SQLITE3_HANDLE_ERROR(sqlite3_finalize(_stmtAppendGroup));
    SQLITE3_HANDLE_ERROR(sqlite3_finalize(_stmtAppendMicrograph));
    SQLITE3_HANDLE_ERROR(sqlite3_finalize(_stmtAppendParticle));
}
