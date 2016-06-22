import sqlite3

conn = sqlite3.connect('test.db')
print "Open database successfully"

conn.execute('''create table company
                (ID       int      primary key   not null,
                 NAME     text                   not null,
                 AGE      int                    not null,
                 ADDRESS  char(50),
                 SALARY   REAL);''')

print "Table created successfully";

conn.close()
