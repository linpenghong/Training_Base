#include "Experiment.h"

Experiment::Experiment()
{
}

Experiment::Experiment(const char database[])
{
    // connect to the data base
    SQLITE3_HANDLE_ERROR(sqlite3_open(database, &_db));
    
    // store temp in RAM
    SQLITE3_HANDLE_ERROR(sqlite3_exec(_db,
                                      "pragma temp_store = memory",
                                      NULL,
                                      NULL,
                                      NULL));

    // create table groups
    SQLITE3_HANDLE_ERROR(
            sqlite3_exec(_db,
                         "create temp table groups(ID integer primary key, \
                                                   Name text);",
                         NULL,
                         NULL,
                         NULL)); 

    // create table micrographs
    SQLITE3_HANDLE_ERROR(
            sqlite3_exec(_db,
                         "create temp table micrographs(ID integer primary key, \
                                                        Name text, \
                                                        Voltage real, \
                                                        DefocusU real not null, \
                                                        DefocusV real not null, \
                                                        DefocusAngle real not null, \
                                                        CA real not null);",
                         NULL,
                         NULL,
                         NULL));

    // prepare all statements
    prepareStatement(); 
}

Experiment::~Experiment()
{
    // finalize all statements
    finalizeStatement();

    // disconnect the database
    SQLITE3_HANDLE_ERROR(sqlite3_close(_db));
}

void Experiment::appendGroup(const char name[])
{
    SQLITE3_HANDLE_ERROR(
            sqlite3_bind_text(_stmtAppendGroup,
                              1,
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
                                  const float CA)
{
    SQLITE3_HANDLE_ERROR(
            sqlite3_bind_text(_stmtAppendMicrograph,
                              1,
                              name,
                              strlen(name),
                              SQLITE_TRANSIENT));
    SQLITE3_HANDLE_ERROR(
            sqlite3_bind_double(_stmtAppendMicrograph,
                                2,
                                voltage));
}

void Experiment::prepareStatement()
{
    {
        const char sql[] = "insert into groups (Name) values (?)";
        SQLITE3_HANDLE_ERROR(
                sqlite3_prepare_v2(_db,
                                   sql,
                                   strlen(sql),
                                   &_stmtAppendGroup, NULL));
    }

    {
        const char sql[] = "insert into micrographs (Name, \
                                                     Voltage, \
                                                     DefocusU, \
                                                     DefocusV, \
                                                     DefocusAngle, \
                                                     CA) \
                            values (?, ?, ?, ?, ?, ?)";
        SQLITE3_HANDLE_ERROR(
                sqlite3_prepare_v2(_db,
                                   sql, strlen(sql),
                                   &_stmtAppendMicrograph,
                                   NULL));
    }
}

void Experiment::finalizeStatement()
{
    SQLITE3_HANDLE_ERROR(sqlite3_finalize(_stmtAppendGroup));
    SQLITE3_HANDLE_ERROR(sqlite3_finalize(_stmtAppendMicrograph));
}
