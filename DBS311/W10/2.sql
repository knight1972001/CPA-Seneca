DECLARE
    isFound boolean :=false;
    CURSOR d_cursor(find VARCHAR)
    IS
        SELECT department_name, location_id FROM department WHERE department_name LIKE find||'%';
BEGIN
    FOR department IN d_cursor('Z')
    LOOP
        isFound:=true;
        dbms_output.put_line(department.department_name || ' in location ' || department.location_id);
    END LOOP;
    IF NOT(isFound)
        THEN
            dbms_output.put_line('No department starts with the letter Z');
        END IF;
END;
