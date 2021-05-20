/*
Name: LONG NGUYEN
Purpose: DBS211 Lab 6
*/

/* 1. Atomic,Consistent,Isolated,Durable  */
CREATE TABLE newEmployees(
    employeeNumber NUMBER(3) PRIMARY KEY,
    lastname CHAR(12),
    firstname CHAR(12),
    extension NUMBER(6),
    email CHAR(30),
    officeCode NUMBER(1),
    reportsTo NUMBER(3) NULL,
    jobtitle CHAR(12)
);
SET AUTOCOMMIT OFF;
SET TRANSACTION READ WRITE;

INSERT ALL
    INTO newEmployees VALUES(100,'Patel','Ralph',22333,'rpatel@mail.com',1,NULL,'Sales Rep')
    INTO newEmployees VALUES(101,'Denis','Betty',33444,'bdenis@mail.com',4,NULL,'Sales Rep')
    INTO newEmployees VALUES(102,'Biri','Ben',44555,'bbirir@mail.com',2,NULL,'Sales Rep')
    INTO newEmployees VALUES(103,'Newman','Chad',66777,'cnewman@mail.com',3,NULL,'Sales Rep')
    INTO newEmployees VALUES(104,'Ropeburn','Audrey',77888,'aropebur@mail.com',1,NULL,'Sales Rep')
    SELECT * FROM DUAL;
COMMIT;

SELECT COUNT (*) FROM newEmployees; -- 5 rows
ROLLBACK;
SELECT COUNT (*) FROM newEmployees; -- 0 rows

INSERT ALL
    INTO newEmployees VALUES(100,'Patel','Ralph',22333,'rpatel@mail.com',1,NULL,'Sales Rep')
    INTO newEmployees VALUES(101,'Denis','Betty',33444,'bdenis@mail.com',4,NULL,'Sales Rep')
    INTO newEmployees VALUES(102,'Biri','Ben',44555,'bbirir@mail.com',2,NULL,'Sales Rep')
    INTO newEmployees VALUES(103,'Newman','Chad',66777,'cnewman@mail.com',3,NULL,'Sales Rep')
    INTO newEmployees VALUES(104,'Ropeburn','Audrey',77888,'aropebur@mail.com',1,NULL,'Sales Rep')
    SELECT * FROM DUAL;
COMMIT;

SELECT COUNT (*) FROM newEmployees; -- 5 rows
UPDATE newEmployees SET jobtitle='unknown';
SELECT * FROM newemployees;
COMMIT;
ROLLBACK;
SELECT * FROM newemployees WHERE jobtitle='unknown'; --5 rows
-- the roolback command in not effective because we change permanent. COMMIT statement permanently makes the change on the server and starts a new transaction.
COMMIT;
DELETE FROM newemployees;
CREATE VIEW vwNewEmps AS 
    SELECT * FROM newemployees ORDER BY lastname,firstname;

ROLLBACK;
SELECT COUNT (*) FROM newEmployees; -- 0 rows
-- Itis not effective because a transaction is automatically commited when any DDL statement is executed.

COMMIT;
-- task14:
INSERT ALL
    INTO newEmployees VALUES(100,'Patel','Ralph',22333,'rpatel@mail.com',1,NULL,'Sales Rep')
    INTO newEmployees VALUES(101,'Denis','Betty',33444,'bdenis@mail.com',4,NULL,'Sales Rep')
    INTO newEmployees VALUES(102,'Biri','Ben',44555,'bbirir@mail.com',2,NULL,'Sales Rep')
    INTO newEmployees VALUES(103,'Newman','Chad',66777,'cnewman@mail.com',3,NULL,'Sales Rep')
    INTO newEmployees VALUES(104,'Ropeburn','Audrey',77888,'aropebur@mail.com',1,NULL,'Sales Rep')
    SELECT * FROM DUAL;
    
    SAVEPOINT insertion;

SELECT COUNT (*) FROM newEmployees; -- 5 rows
UPDATE newEmployees SET jobtitle='unknown';
SELECT * FROM newemployees;
COMMIT;
ROLLBACK;
SELECT * FROM newemployees WHERE jobtitle='unknown'; --5 rows
-- the roolback command in not effective because we change permanent. COMMIT statement permanently makes the change on the server and starts a new transaction.
COMMIT;
DELETE FROM newemployees;
CREATE VIEW vwNewEmps AS 
    SELECT * FROM newemployees ORDER BY lastname,firstname;

ROLLBACK;
SELECT COUNT (*) FROM newEmployees; -- 0 rows
-- Itis not effective because a transaction is automatically commited when any DDL statement is executed.

-- task16:
UPDATE newEmployees SET jobtitle='unknown';
SELECT * FROM newemployees;
COMMIT;
ROLLBACK;
SELECT * FROM newemployees WHERE jobtitle='unknown'; --5 rows
-- the roolback command in not effective because we change permanent. COMMIT statement permanently makes the change on the server and starts a new transaction.
COMMIT;
DELETE FROM newemployees;
CREATE VIEW vwNewEmps AS 
    SELECT * FROM newemployees ORDER BY lastname,firstname;

ROLLBACK;
SELECT COUNT (*) FROM newEmployees; -- 0 rows
ROLLBACK TO insertion; -- it has the error because we commit a new transaction again.
ROLLBACK;
SELECT * FROM newemployees;
-- NO DATA here because we DELETE the DATA in task 13 already.
 
DENY DELETE, INSERT, REFERENCES, SELECT, UPDATE ON "DBS211_202A23"."NEWEMPLOYEES"  TO DBS211_202A23;
GRANT SELECT ON "DBS211_202A23"."NEWEMPLOYEES"  TO master.sys.databases ;
GRANT INSERT,UPDATE,DELETE ON "DBS211_202A23"."NEWEMPLOYEES"  TO master.sys.databases ;
DROP TABLE newemployees;








