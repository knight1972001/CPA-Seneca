SPOOL C:\CPA_Code\DBS311\output.txt;
-- 1. After Tomorrow
SELECT TO_CHAR(to_date('01/20/21', 'MM/DD/YY')+2, 'fmMonth ddth "of year" YYYY') AS "After Tomorrow" FROM DUAL;

-- 2. Good Salary
SELECT last_name, first_name, salary, CAST((salary*1.07) AS int) AS "Good Salary", ((salary*1.07-salary)*12) AS "Annual Pay Increase" FROM employee;

-- 3. Person & Job
SELECT (last_name||', '||first_name||' is '|| job_id) AS "Person and Job" FROM employee WHERE last_name LIKE '%s' AND (first_name LIKE 'C%' OR first_name LIKE 'K%') ORDER BY last_name;

-- 4. Years Worked
SELECT last_name, salary, to_char(hire_date, 'DD-Mon-YYYY') AS "Hire Date", ROUND(months_between(sysdate, hire_date)/12) AS "Years Worked" FROM employee WHERE hire_date < to_date('01/01/92', 'MM/DD/RR') AND salary > 10000 ORDER BY salary DESC, "Years Worked" DESC;

-- 5. Unknown Province
SELECT city, postal_code, COALESCE(state_province, 'Unknown Province') AS "State Province" FROM location WHERE city LIKE 'S%' and LENGTH(city) >= 8;

-- 6. REVIEW DAY
SELECT last_name, hire_date, to_char(next_day(hire_date + 365, 'Tuesday'), 'fmDAY, Month" the "fmDdspth" of the year" YYYY') AS "Review Day" FROM employee WHERE hire_date > to_date('01/01/97', 'MM/DD/RR');
SPOOL OFF;