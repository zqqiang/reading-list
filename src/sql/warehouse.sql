/*
   WHOLESALE MANAGEMENT SYSTEM DATABASE PROJECT

1. Maintain the details of stock like their id, name, quantity
2. Maintain the details of buyers from which manager has to buy stock like 
   buyer id, name, address, stock id to be bought
3. Details of customers i.e. name, address, id
4. Defaulters list of customers who have not paid their pending amount
5. List of payment paid or pending
6. The stock that is to buy if quantity goes less than a particular amount.
7. Profit calculation for a month.
8. Quantity cannot be sold to a customer if required amount is not present 
   in stock and date of delivery should be maintained up to which stock can be provided.
*/

/*
    $sqlite3 warehouse.db
    sqlite> .database
    seq  name             file                                                      
    ---  ---------------  ----------------------------------------------------------
    0    main             /Users/EllaFan/Downloads/softwares/sqlite3/warehouse.db   
*/

CREATE TABLE stock (
    id INT PRIMARY KEY NOT NULL,
    name TEXT NOT NULL,
    quantity INT NOT NULL
);

INSERT INTO stock VALUES(1, "food", 100);

/*
    sqlite> .header on
    sqlite> select * from stock;
    id|name|quantity
    1|food|100
    sqlite> .mode column
    sqlite> select * from stock;
    id          name        quantity  
    ----------  ----------  ----------
    1           food        100       
*/

CREATE TABLE merchandise (
    id INT PRIMARY KEY NOT NULL,
    name TEXT NOT NULL,
    band TEXT NOT NULL,
    category INT NOT NULL,
    expiredate DATETIME NOT NULL,
    description TEXT NOT NULL,
    stockId INT NOT NULL
);

INSERT INTO merchandise VALUES(1, "apple", "apple NO. 1", 1, "2017/10/01", "", 1);

/*
    sqlite> select * from merchandise;
    id          name        band         category    expiredate  description  stockId
    ----------  ----------  -----------  ----------  ----------  -----------  ----------
    1           apple       apple NO. 1  1           2017/10/01               1
*/

CREATE TABLE member (
    id INT PRIMARY KEY NOT NULL, 
    name TEXT NOT NULL, 
    address TEXT NOT NULL,
    type INT NOT NULL,
    membership INT NOT NULL,
    expiredate DATETIME NOT NULL
);

INSERT INTO member VALUES(1, "Mary", "1616 Pine St", 1, 123456789, "2018/01/01");

/*
    sqlite> select * from member;
    id          name        address       type        membership  expiredate
    ----------  ----------  ------------  ----------  ----------  ----------
    1           Mary        1616 Pine St  1           123456789   2018/01/01 
*/

CREATE TABLE memberTypeMap (
    typeId INT PRIMARY KEY NOT NULL,
    typeName TEXT NOT NULL
);

INSERT INTO memberTypeMap VALUES(1, "Gold Star Membership"),(2, "Executive Membership"),(3, "Business Membership");

/*
    sqlite> select * from memberTypeMap;
    typeId      typeName
    ----------  --------------------
    1           Gold Star Membership
    2           Executive Membership
    3           Business Membership
*/

CREATE TABLE orders (
    id INT PRIMARY KEY NOT NULL, 
    memberId INT NOT NULL, 
    date DATETIME NOT NULL, 
    item INT NOT NULL, 
    price FLOAT NOT NULL, 
    discount FLOAT NOT NULL
);

INSERT INTO orders VALUES(1, 1, "2017/8/14", 1, 10.99, 0.99);

/*
    sqlite> select * from orders;
    id          memberId    date        item        price       discount
    ----------  ----------  ----------  ----------  ----------  ----------
    1           1           2017/8/14   1           10.99       0.99
*/

