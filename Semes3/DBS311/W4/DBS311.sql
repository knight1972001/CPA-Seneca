SPOOL C:\CPA_Code\DBS311\W4\output.txt;
--1. High, Low, Avg
SELECT department_id, MAX(salary) AS "High", MIN(salary) AS "Low", ROUND(AVG(salary),0) AS "Avg" FROM employee GROUP BY department_id ORDER BY "Avg" DESC;

--2. Dept#, Job, HowMany
SELECT department_id AS "Dept#", job_id AS "Job", count(job_id) AS "HowMany" FROM employee GROUP BY job_id, department_id HAVING (count(job_id) > 1) ORDER BY "HowMany" DESC;

--3 Top Paid
SELECT job_id, SUM(salary) AS "totalSalary" FROM employee WHERE salary > 15000 AND job_id IN('AD_PRES','AD_VP') GROUP BY job_id ORDER BY "totalSalary" DESC;

--4 100,101,102num
SELECT manager_id, COUNT(employee_id) AS "numOfEmployees" FROM employee WHERE manager_id NOT IN (100, 101, 102) GROUP BY manager_id,department_id HAVING (count(employee_id) > 2) ORDER BY "numOfEmployees";

--5 hire-date
SELECT department_id, MIN(hire_date) AS "earliestHireDate", MAX(hire_date) AS "latestHireDate" FROM employee WHERE department_id NOT IN (10, 20) GROUP BY department_id HAVING MAX(hire_date) < to_date('01-01-2000', 'DD-MM-YYYY') ORDER BY MAX(hire_date) DESC;

--6 city
SELECT d.department_name, l.city, COUNT(e.employee_id) AS "numOfEmployee" FROM department d, location l, employee e WHERE d.department_name NOT LIKE 'S%' AND e.department_id = d.department_id AND l.location_id=d.location_id GROUP BY l.city, d.department_name HAVING(COUNT(e.employee_id) >= 3) ORDER BY d.department_name ASC;

--7 Bonus
SELECT department_name, city, COUNT(employee_id) AS "numOfEmployee" FROM department LEFT JOIN employee USING(department_id) LEFT JOIN location USING (location_id) WHERE department_name NOT LIKE 'A%' GROUP BY city, department_name HAVING(COUNT(employee_id) < 3) ORDER BY department_name ASC;

SPOOL OFF;