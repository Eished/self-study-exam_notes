SELECT MD5(456);
CREATE USER '张三'@'localhost' IDENTIFIED BY '123',
	 '李四'@'localhost' IDENTIFIED BY '250cf8b51c773f3f8dc8b4be867a9a02';

DROP USER '李四'@localhost;

RENAME USER '张三'@localhost TO '王五'@localhost;

