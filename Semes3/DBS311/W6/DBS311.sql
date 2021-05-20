SET PAGESIZE 2000
SET LINESIZE 2000
SPOOL "C:\CPA_Code\output.txt"
-- 1 DEPARTMENT_ID list
SELECT department_id FROM department
UNION
SELECT department_id FROM employee WHERE job_id <> 'ST_CLERK'  AND department_id IS NOT NULL;

-- 2 employee, job ID
SELECT employee_id, job_id, SUBSTR(salary,1,20) AS "SALARY" FROM employee
        UNION
SELECT employee_id, job_id, COALESCE(TO_CHAR(null), '-1')  FROM job_history;

-- 3 WAREHOUSE
SELECT city FROM locations WHERE location_id IN 
(
    SELECT location_id FROM locations 
    MINUS
    SELECT location_id FROM warehouses
);

-- 4 categoryID ANY
SELECT
   prod_cat.category_id,
   prod_cat.category_name,
   COUNT(p.category_id) AS "COUNT" 
FROM
   product_categories prod_cat 
   JOIN
      products p 
      ON prod_cat.category_id = p.category_id 
WHERE
   prod_cat.category_id = 1 
   OR prod_cat.category_id = 2 
   OR prod_cat.category_id = 5 
GROUP BY
   prod_cat.category_id,
   prod_cat.category_name 
ORDER BY
   CASE
      WHEN
         category_id = '5' 
      THEN
         0 
      WHEN
         category_id = '1' 
      THEN
         1 
      WHEN
         category_id = '2' 
      THEN
         2 
   END
;

-- 5 prod_id greather
SELECT product_id FROM inventories WHERE quantity > 250 
UNION
SELECT product_id FROM inventories WHERE quantity > 250;

-- 6 no STATE
SELECT location_id AS "Loc#", city, COALESCE(state, 'No State') AS "State", COALESCE(TO_CHAR(null), ' ') AS "WareHouse" FROM locations
UNION
SELECT location_id, COALESCE(TO_CHAR(null), ' '), COALESCE(TO_CHAR(null), ' '), warehouse_name FROM warehouses
ORDER BY "Loc#", "WareHouse";
SPOOL OFF;