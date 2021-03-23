DECLARE
    l_city location.city%type;
    d_name department.department_name%TYPE;
    d_managerid department.manager_id%TYPE;
    status VARCHAR(45);
    CURSOR find_city_cursor(search VARCHAR)
        IS
        SELECT department_name, city, manager_id FROM location LEFT JOIN department USING(location_id) WHERE city LIKE search||'%' ORDER BY department_name;
BEGIN
    OPEN find_city_cursor('A');
    LOOP
        FETCH find_city_cursor INTO d_name, l_city, d_managerid;
        EXIT WHEN find_city_cursor%notfound;
        IF(d_managerid >= 100 AND d_managerid <= 200)
        THEN
            status:='managed by one of the Senior Managers.';
        ELSE
            IF(d_managerid IS NULL)
            THEN
                status:='without manager.';
            ELSE
                status:='NOT managed by one of the Senior Managers.';
            END IF;
        END IF;
        IF(d_name IS NOT NULL)
        THEN
            dbms_output.put_line('Department '||d_name||' in a city named '||l_city||' is '||status);
            dbms_output.put_line('');
        ELSE
            dbms_output.put_line('There is NO Department in a city named '||l_city);
            dbms_output.put_line('');
        END IF;
    END LOOP;
    CLOSE find_city_cursor;
END;
