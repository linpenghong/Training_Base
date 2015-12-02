#include <stdio.h>
#include <sqlite3.h>

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

    char** result;
    int nrows;
    int ncols;

    sql = "select * from episodes;";
    rc = sqlite3_get_table(db, sql, &result, &nrows, &ncols, &zErr);

    for (int i = 1; i <= nrows; i++)
    {
        for (int j = 0; j < ncols; j++)
            printf("%s ", result[i * ncols + j]);
        printf("\n");
    }

    sqlite3_free_table(result);

    return 0;
}
