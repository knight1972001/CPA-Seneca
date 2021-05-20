create or replace PROCEDURE FIND_CUSTOMER(customer_id IN NUMBER, found OUT NUMBER)
IS
BEGIN
    SELECT COUNT(*) INTO found FROM CUSTOMERS WHERE customer_id=FIND_CUSTOMER.customer_id;
    EXCEPTION
    WHEN no_data_found THEN
    	found := 0;
END FIND_CUSTOMER;