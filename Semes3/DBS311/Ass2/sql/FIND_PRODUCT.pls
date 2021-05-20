create or replace PROCEDURE FIND_PRODUCT(product_id IN NUMBER, price OUT products.list_price%TYPE) 
IS
BEGIN
  SELECT list_price INTO price FROM products WHERE product_id=FIND_PRODUCT.product_id;
          DBMS_OUTPUT.PUT_LINE(price);
  EXCEPTION
    WHEN no_data_found THEN
    	price := 0;
END FIND_PRODUCT;