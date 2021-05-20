SELECT last_name, salary, commission_pct, job_id, salary*12*(1+NVL(commission_pct,0)) "Annual Salary"
    FROM employee WHERE job_id IN ('SA_REP', 'IT_PROG') ORDER BY 4, 1;
    
SELECT last_name, salary, commission_pct, job_id, salary*12*(1+commission_pct) "Annual Salary"
    FROM employee WHERE job_id IN ('SA_REP', 'IT_PROG') ORDER BY 4, 1;
    
    UPDATE employee SET salary = NULL WHERE last_name='Lorentz';
    ROLLBACK;
SELECT last_name, salary, commission_pct, job_id, COALESCE(12*salary*(1+commission_pct), 12*salary, 500) "Annual Salary" FROM employee WHERE job_id IN('SA_REP', 'IT_PROG') ORDER BY 4, 1;

SELECT last_name, salary,
DECODE (TRUNC(salary/2000, 0),
0, 0.00,
1, 0.09,
2, 0.20,
3, 0.30,
4, 0.40,
5, 0.42,
6, 0.44, 0.45) TAX_RATE FROM employee WHERE department_id=80;