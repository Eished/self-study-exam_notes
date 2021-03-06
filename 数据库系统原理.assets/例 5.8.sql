USE mysql_test;
DELIMITER $$
CREATE FUNCTION fn_search(cid INT)
	RETURNS CHAR(2)
    DETERMINISTIC
BEGIN
	DECLARE SEX CHAR(2);
	SELECT cust_sex INTO SEX FROM customers
		WHERE cust_id=cid;
	IF SEX IS NULL THEN
		RETURN(SELECT'没有该客户');
	ELSE IF SEX='F' THEN
		RETURN(SELECT'女');
		ELSE RETURN(SELECT'男');
        END IF;
	END IF;
END$$
DELIMITER ;

SELECT fn_search(904);

DROP FUNCTION IF EXISTS fn_search;
