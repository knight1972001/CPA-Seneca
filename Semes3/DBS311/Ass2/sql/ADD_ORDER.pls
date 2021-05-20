create or replace PROCEDURE ADD_ORDER(customer_id IN NUMBER, new_order_id OUT NUMBER)
IS
    sysdate DATE;
BEGIN
    SELECT MAX(order_id) + 1 INTO new_order_id FROM orders;
    SELECT SYSDATE INTO sysdate FROM DUAL;
    INSERT INTO orders
    VALUES (new_order_id, customer_id, 'Shipped', 56, sysdate);
    
    EXCEPTION
        WHEN OTHERS THEN
            DBMS_OUTPUT.PUT_LINE('SOME ERROR HAPPENED');    
END ADD_ORDER;