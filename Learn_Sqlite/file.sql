PRAGMA foreign_keys=OFF;
BEGIN TRANSACTION;
CREATE TABLE test (id integer primary key, value test);
INSERT INTO "test" VALUES(1,'eenie');
INSERT INTO "test" VALUES(2,'meenie');
INSERT INTO "test" VALUES(3,'miny');
INSERT INTO "test" VALUES(4,'mo');
CREATE INDEX test_idx on test (value);
CREATE VIEW schema as select * from sqlite_master;
COMMIT;
