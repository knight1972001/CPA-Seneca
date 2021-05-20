CREATE TABLE emp(
    empno int NOT NULL,
    ename varchar(255) NOT NULL,
    job varchar(255) NOT NULL,
    mgr number(4),
    hiredate DATE NOT NULL,
    sal number(4),
    comm number(4),
    deptno number(2),
    PRIMARY KEY(empno)
);

SELECT empno, SUBSTR(ename,1,12) "Last Name", job, mgr,

       hiredate, sal, comm, deptno "Dept"       FROM   emp;

SELECT*from emp;

INSERT ALL
    INTO emp (empno, ename, job, mgr, hiredate, sal, comm, deptno)
    VALUES (7499,'ALLEN','SALESMAN',7698,TO_DATE('20/02/1981','DD/MM/YYYY'),1600,300,30)
    INTO emp (empno, ename, job, mgr, hiredate, sal, comm, deptno)
    VALUES (7521,'WARD','SALESMAN',7698,TO_DATE('22/02/1981','DD/MM/YYYY'),1250,500,30)
    INTO emp (empno, ename, job, mgr, hiredate, sal, comm, deptno)
    VALUES (7566,'JONES','MANAGER',7839,TO_DATE('03/04/1981','DD/MM/YYYY'),2975,NULL,20)
    INTO emp (empno, ename, job, mgr, hiredate, sal, comm, deptno)
    VALUES (7654,'MARTIN','SALESMAN',7692,TO_DATE('28/09/1981','DD/MM/YYYY'),1250,1400,30)
    INTO emp (empno, ename, job, mgr, hiredate, sal, comm, deptno)
    VALUES (1698,'BLAKE','MANAGER',7839,TO_DATE('01/05/1981','DD/MM/YYYY'),2850,NULL,30)
    INTO emp (empno, ename, job, mgr, hiredate, sal, comm, deptno)
    VALUES (7782,'CLARK','MANAGER',7839,TO_DATE('09/06/1981','DD/MM/YYYY'),2450,500,10)
    INTO emp (empno, ename, job, mgr, hiredate, sal, comm, deptno)
    VALUES (7788,'SCOTT','ANALYST',7566,TO_DATE('09/02/1982','DD/MM/YYYY'),3000,NULL,20)
    INTO emp (empno, ename, job, mgr, hiredate, sal, comm, deptno)
    VALUES (7839,'{KING','PRESIDENT',NULL,TO_DATE('17/11/1981','DD/MM/YYYY'),5000,NULL,10)
    INTO emp (empno, ename, job, mgr, hiredate, sal, comm, deptno)
    VALUES (7844,'TURNER','SALESMAN',7698,TO_DATE('08/09/1981','DD/MM/YYYY'),1500,0,30)
    INTO emp (empno, ename, job, mgr, hiredate, sal, comm, deptno)
    VALUES (7876,'ADAMS','CLERK',7788,TO_DATE('12/01/1983','DD/MM/YYYY'),1100,NULL,20)
    INTO emp (empno, ename, job, mgr, hiredate, sal, comm, deptno)
    VALUES (7900,'JAMES','CLERK',7698,TO_DATE('03/12/1981','DD/MM/YYYY'),950,NULL,30)
    INTO emp (empno, ename, job, mgr, hiredate, sal, comm, deptno)
    VALUES (7902,'FORD','ANALYST',7566,TO_DATE('05/12/1981','DD/MM/YYYY'),3000,NULL,20)
    INTO emp (empno, ename, job, mgr, hiredate, sal, comm, deptno)
    VALUES (7934,'MILLER','CLERK',7782,TO_DATE('23/01/1982','DD/MM/YYYY'),1300,NULL,10)
    INTO emp (empno, ename, job, mgr, hiredate, sal, comm, deptno)
    VALUES (7999,'Ivanov','Web-Dev',7788,TO_DATE('12/09/1996','DD/MM/YYYY'),2500,NULL,50)
    INTO emp (empno, ename, job, mgr, hiredate, sal, comm, deptno)
    VALUES (8000,'Loyd','Clerk',7788,TO_DATE('12/10/1997','DD/MM/YYYY'),1500,NULL,50)
    INTO emp (empno, ename, job, mgr, hiredate, sal, comm, deptno)
    VALUES (8001,'Dubois','Manager',7566,TO_DATE('23/01/2000','DD/MM/YYYY'),4500,NULL,60)
    INTO emp (empno, ename, job, mgr, hiredate, sal, comm, deptno)
    VALUES (8002,'Petit','Clerk',8000,TO_DATE('22/09/2000','DD/MM/YYYY'),1800,NULL,60)
    INTO emp (empno, ename, job, mgr, hiredate, sal, comm, deptno)
    VALUES (8003,'Dixon','Manager',7788,TO_DATE('24/10/2001','DD/MM/YYYY'),4400,NULL,50)
    INTO emp (empno, ename, job, mgr, hiredate, sal, comm, deptno)
    VALUES (8004,'Lopez','Analyst',8001,TO_DATE('08/09/2001','DD/MM/YYYY'),2200,400,60)
    SELECT * FROM dual;