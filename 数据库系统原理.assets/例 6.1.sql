USE mysql_test;
CREATE TABLE orders
(
	order_id INT NOT NULL AUTO_INCREMENT,
    order_product CHAR(50) NOT NULL,
    order_product_type CHAR(50) NOT NULL,
    cust_id INT NOT NULL,
    order_date DATETIME NOT NULL,
    order_price DOUBLE NOT NULL,
    order_amount INT NOT NULL,
    PRIMARY KEY(order_id),
    FOREIGN KEY(cust_id)
		REFERENCES customers(cust_id)
        ON DELETE RESTRICT
        ON UPDATE RESTRICT
);