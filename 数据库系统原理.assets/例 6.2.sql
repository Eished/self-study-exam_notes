CREATE TRIGGER mysql_test.customers_insert_trigger AFTER INSERT
	ON mysql_test.customers FOR EACH ROW SET @str='one customer added!';
INSERT INTO mysql_test.customers
	VALUES(NULL,'万华','F','长沙市','芙蓉区',NULL);
SELECT @str;
DROP TRIGGER IF EXISTS mysql_test.customers_insert_trigger;
#6.4
CREATE TRIGGER mysql_test.customers_insert_trigger AFTER INSERT
	ON mysql_test.customers FOR EACH ROW SET @str=NEW.cust_id;
INSERT INTO mysql_test.customers
	VALUES(NULL,'曾伟','F','长沙市','芙蓉区',NULL);
SELECT @str;
DROP TRIGGER IF EXISTS mysql_test.customers_insert_trigger;
#6.5
CREATE TRIGGER mysql_test.customers_update_trigger BEFORE UPDATE
	ON mysql_test.customers FOR EACH ROW 
    SET NEW.cust_address=OLD.cust_contact;
UPDATE mysql_test.customers SET cust_address='武汉市'
	WHERE cust_name='曾伟';
SELECT cust_address FROM mysql_test.customers
	WHERE cust_name='曾伟';