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
    sqlite> 
    sqlite>
    sqlite> .mode column
    sqlite> select * from stock;
    id          name        quantity  
    ----------  ----------  ----------
    1           food        100       
*/

CREATE TABLE customer (
    id INT PRIMARY KEY NOT NULL, 
    name TEXT NOT NULL, 
    address TEXT NOT NULL, 
    stockId INT NOT NULL
);

INSERT INTO customer VALUES(1, "Mary", "1616 Pine St", 1);

/*
    sqlite> select * from customer;
    id          name        address       stockId   
    ----------  ----------  ------------  ----------
    1           Mary        1616 Pine St  1         
*/

CREATE TABLE order (
    id INT PRIMARY KEY NOT NULL,
    date DATETIME NOT NULL,
    item INT NOT NULL,
    price FLOAT NOT NULL,
    discount FLOAT NOT NULL
);





