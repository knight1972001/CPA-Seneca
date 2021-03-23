DECLARE
  d_name department.department_name%type;  
  d_location department.location_id%type;
  CURSOR d_cursor(find VARCHAR)
  IS
    SELECT department_name, location_id FROM department WHERE department_name LIKE find||'%';
BEGIN
    OPEN d_cursor('Z');
    LOOP
        FETCH d_cursor INTO d_name, d_location;
        IF(d_cursor%ROWCOUNT = 0)
        THEN
            dbms_output.put_line('No department starts with the letter Z');
        END IF;
        EXIT WHEN d_cursor%notfound;
        dbms_output.put_line(d_name || ' in location ' || d_location);
        
    END LOOP;
    CLOSE d_cursor;
END;
