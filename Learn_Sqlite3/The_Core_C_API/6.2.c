#include <stdio.h>
#include <sqlite3.h>

int callback(void* data,
             int ncols,
             char** values,
             char** headers);

int main(int argc, char* argv[])
{
    sqlite3* db;
    int rc;
    char* sql;
    char* zErr;

    rc = sqlite3_open("test.db", &db);

    if (rc)
    {
        fprintf(stderr, "Can not open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 1;
    }

    char* data = "Callback function called";
    sql = "insert into episodes (id, name) values (11, 'Mackinaw Peaches');"
          "select * from episodes;";

    rc = sqlite3_exec(db, sql, callback, data, &zErr);
    
    if (rc != SQLITE_OK)
    {
        if (zErr != NULL)
        {
            fprintf(stderr, "SQL error: %s\n", zErr);
            sqlite3_free(zErr);
        }
    }

    sqlite3_close(db);

    return 0;
}

int callback(void* data,
             int ncols,
             char** values,
             char** headers)
{
    int i;
    printf("%s: ", (const char*)data);

    for (int i = 0; i < ncols; i++)
        printf("%s = %s ", headers[i], values[i]);

    printf("\n");

    return 0;
}
