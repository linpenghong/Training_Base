import sqlite3

conn = sqlite3.connect('test.db')
print "Open database successfully"

conn.execute('''CREATE TABLE COMPANY
                (ID       INT      PRIMARY KEY   NOT NULL,
                 NAME     TEXT                   NOT NULL,
                 AGE      INT                    NOT NULL,
                 ADDRESS  CHAR(50),
                 SALARY   REAL);''')

print "Table created successfully"

conn.execute("INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY) \
              VALUES (1, 'Paul', 32, 'California', 2000.00);")

conn.execute("INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY) \
              VALUES (2, 'Allen', 25, 'Texas', 1500.00);")

conn.execute("INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY) \
              VALUES (3, 'Teddy', 23, 'Norway', 2000.00);")

conn.execute("INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY) \
              VALUES (4, 'Mark', 25, 'Rich-Mond', 6500.00);")

conn.commit()

print "Records Created Successfully"

cursor = conn.execute("SELECT ID, NAME, ADDRESS, SALARY FROM COMPANY;")

for row in cursor:
    print "ID = ", row[0]
    print "NAME = ", row[1]
    print "ADDRESS = ", row[2]
    print "SALARY = ", row[3], "\n"

print "Operation done successfully"

conn.close()
