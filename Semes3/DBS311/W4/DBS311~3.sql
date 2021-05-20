SELECT COUNT(employee_id), department_id FROM employee GROUP BY department_id HAVING (COUNT(employee_id) < 3);
SELECT department_id, COUNT(employee_id) FROM department LEFT JOIN employee using (department_id) GROUP BY department_id ORDER BY department_id ;

