DECLARE
    p_description products.description%TYPE;
    status VARCHAR(45);
BEGIN
    FIND_PROD_PRICE(31, p_description, status);
    IF(status <> 'N/A')
    THEN
        DBMS_OUTPUT.PUT_LINE (p_description||' is '||status);
    END IF;
    
    EXCEPTION
        WHEN NO_DATA_FOUND THEN 
            DBMS_OUTPUT.PUT_LINE ('Invalid Id');
        WHEN OTHERS THEN
            DBMS_OUTPUT.PUT_LINE('SOME ERROR HAPPENED');  
END;

