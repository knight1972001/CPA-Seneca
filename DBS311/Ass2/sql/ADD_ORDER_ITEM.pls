create or replace PROCEDURE ADD_ORDER_ITEM( orderId IN order_items.order_id%type,
                                            itemId IN order_items.item_id%type, 
                                            productId IN order_items.product_id%type, 
                                            quantity IN order_items.quantity%type,
                                            price IN order_items.unit_price%type)
IS
BEGIN
    INSERT INTO order_items
    VALUES(orderId,itemId,productId,quantity,price);
    EXCEPTION
        WHEN OTHERS THEN
            DBMS_OUTPUT.PUT_LINE('SOME ERROR HAPPENED');    
END ADD_ORDER_ITEM;