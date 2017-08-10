CREATE DATABASE warehouse;

USE warehouse;
/*
mysql> use warehouse
Database changed
*/

CREATE TABLE account (
    `oid` bigint(20) NOT NULL AUTO_INCREMENT,
    `accountId` varchar(50) DEFAULT NULL,
    `firstName` varchar(50) DEFAULT NULL,
    `email` varchar(255) DEFAULT NULL,
    `timezone` double NOT NULL DEFAULT '-8',
    `pwd` varchar(20) DEFAULT NULL,
    `timeCreated` timestamp NULL DEFAULT CURRENT_TIMESTAMP,
    `lastName` varchar(20) DEFAULT NULL,
    `companyName` varchar(255) DEFAULT NULL,
    `address` varchar(255) DEFAULT NULL,
    `city` varchar(20) DEFAULT NULL,
    `state` varchar(20) DEFAULT NULL,
    `countryCode` varchar(20) DEFAULT '-1',
    `postcode` varchar(20) DEFAULT NULL,
    `phone` varchar(20) DEFAULT NULL,
    `fax` varchar(20) DEFAULT NULL,
    PRIMARY KEY (`oid`),
    UNIQUE KEY `accountId` (`accountId`)
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;

/*
mysql> show tables;
+---------------------+
| Tables_in_warehouse |
+---------------------+
| account             |
+---------------------+
1 row in set (0.00 sec)
*/

INSERT INTO account VALUES (
    100, "billQiang@gmail.com", "Bill", "billQiang@hotmail.com", -8, "xxxabcdbc", "2015-07-23 17:17:33",
    "Qiang", "warehouse@company", "4058 Pine St", "Burnaby", "BC", 124, "V5G1Z5", "6041118888", NULL
);

/*
Query OK, 1 row affected (0.17 sec)
*/