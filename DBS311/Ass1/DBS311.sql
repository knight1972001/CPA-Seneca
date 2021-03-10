-- 1. excluding Admin
SELECT employee_id AS "Emp Id", (first_name || ',' || last_name) AS "Full Name", job_title AS "Job", to_char(hire_date, 'fmMonth ddth "of "YYYY') AS "Start Date" FROM employees WHERE UPPER(job_title) NOT LIKE UPPER('Admin%') AND extract(month from hire_date)=extract(month from DATE '2020-09-01') ORDER BY hire_date DESC, last_name ASC;

-- 2. online Order ID is 0
SELECT COALESCE(employee_id, 0) AS "Employee Id", TO_CHAR(SUM(unit_price*quantity),'$999,999,999.99') AS "Total Sale" From (employees RIGHT JOIN orders ON (employees.employee_id=orders.salesman_id)) LEFT JOIN order_items USING (order_id) GROUP BY employee_id ORDER BY "Employee Id" ASC;

-- 3. total order less than 3
SELECT customer_id AS "CustId", name AS "Name", COUNT(order_id) AS "Total Orders" FROM customers LEFT JOIN orders USING(customer_id) WHERE (UPPER(name) LIKE UPPER('F%') OR UPPER(name) LIKE UPPER('J%')) GROUP BY customer_id, name HAVING (customer_id < 200 AND COUNT(order_id) < 3) ORDER BY "Total Orders" ASC, customers.name ASC;

-- 4. cusId 44
SELECT customer_id AS "Cust#", name AS "Name", order_id AS "Order Id", TO_CHAR(order_date, 'DD-MON-YY') AS "Order Dat", SUM(quantity) AS "Total Items", TO_CHAR(SUM(unit_price*quantity),'$999,999,999.99') AS "Total Amount" FROM (orders LEFT JOIN order_items USING (order_id)) JOIN customers USING(customer_id) WHERE order_id IN(SELECT order_id FROM orders  WHERE customer_id = 44) GROUP BY order_id,order_date,name,customer_id HAVING (SUM(unit_price*quantity) < 1000000) ORDER BY "Total Items"; 

-- 5. total
SELECT customer_id AS "Cust#", name AS "Name", COUNT(order_id) AS "# of Orders", SUM(quantity) "Total Items",TO_CHAR(SUM(unit_price*quantity),'$999,999,999.99') AS "Total Amount" FROM (orders LEFT JOIN order_items USING (order_id)) JOIN customers USING(customer_id) GROUP BY customer_id, name HAVING COUNT(order_id) > 30 ORDER BY "# of Orders";

-- 8
SELECT c.customer_id AS "CUSTOMER_ID", c.name AS "Customer Name", COUNT(t2.order_id) AS "# of Orders"
FROM (SELECT customer_id, order_id,
CASE
    WHEN ((order_id IS NULL) AND (salesman_id IS NULL))
        THEN COALESCE(salesman_id, 0)
    ELSE salesman_id
END AS "isHuman"
FROM customers LEFT JOIN orders USING (customer_id) WHERE (name LIKE 'General%' OR name LIKE '%Electric')) t2, customers c
WHERE (c.customer_id = t2.customer_id) AND t2."isHuman" IS NOT NULL GROUP BY c.customer_id, c.name ORDER BY "# of Orders" DESC;

