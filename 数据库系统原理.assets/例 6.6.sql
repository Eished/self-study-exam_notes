SELECT MD5(456);
CREATE USER 'zhangsan'@'localhost' IDENTIFIED BY '123',
	 '李四'@'localhost' IDENTIFIED BY '250cf8b51c773f3f8dc8b4be867a9a02';

DROP USER '李四'@localhost;

RENAME USER '张三'@localhost TO '王五'@localhost;

SELECT MD5('hello');
SET PASSWORD FOR 'wangwu'@localhost
='456';

SHOW GRANTS FOR '王五'@localhost;
RENAME USER '王五'@localhost TO 'wangwu'@localhost;

GRANT SELECT (cust_id,cust_name)
	ON mysql_test.customers
		TO'wangwu'@localhost;
        
CREATE USER 'liming'@'localhost' IDENTIFIED BY '123',
	 'huang'@'localhost' IDENTIFIED BY '234';
GRANT SELECT,UPDATE
	ON mysql_test.customers
    TO 'liming'@'localhost',
    'huang'@'localhost';
    
GRANT ALL
	ON mysql_test.*
    TO 'wangwu'@'localhost';
GRANT ALL
	ON *.*
    TO 'wangwu'@'localhost';

CREATE USER 'zhou'@localhost IDENTIFIED BY'123';
GRANT SELECT,UPDATE
	ON mysql_test.customers
    TO 'zhou'@'localhost'
    WITH GRANT OPTION;

REVOKE SELECT
	ON mysql_test.customers
    FROM 'zhou'@localhost;
    
select *from mysql.user;
DROP USER 'huang'@localhost,'liming'@localhost,'zhou'@localhost,'李四'@localhost,'zhangsan'@localhost;

SHOW VARIABLES LIKE "secure_file_priv";

SELECT*FROM mysql_test.customers
	INTO OUTFILE 'D:/BACKUP/backupfile.txt'
    FIELDS TERMINATED BY ','
    OPTIONALLY ENCLOSED BY '"'
    LINES TERMINATED BY '?';
    
SELECT *FROM mysql_test.customers;
SELECT *FROM mysql_test.customers_copy;
alter table mysql_test.customers drop column cust_city;

CREATE TABLE customers_copy
(
cust_id INT NOT NULL AUTO_INCREMENT,
cust_name CHAR(50) NOT NULL,
cust_sex CHAR(1) NOT NULL DEFAULT 0,
cust_address CHAR(50) NULL,
cust_contact CHAR(50) NULL,
PRIMARY KEY(cust_id)
);

LOAD DATA INFILE 'D:/BACKUP/backupfile.txt'
	INTO TABLE mysql_test.customers_copy
    FIELDS TERMINATED BY ','
    OPTIONALLY ENCLOSED BY '"'
    LINES TERMINATED BY '?';