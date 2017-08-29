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

/*
    sqlite> .header on
    sqlite> .mode column
*/

DROP TABLE IF EXISTS stock;

CREATE TABLE stock (
    id INT PRIMARY KEY NOT NULL,
    name TEXT NOT NULL,
    category TEXT NOT NULL
);

/*
    INSERT INTO stock VALUES
        (1, "food", "fruit"),
        (2, "appliances", "refrigerators"),
        (3, "appliances", "cooking appliances"),
        (4, "appliances", "dishwashers"),
        (5, "furniture", "mattresses");
*/

/*
    sqlite> select * from stock;
    id          name        quantity
    ----------  ----------  ----------
    1           food        fruit
    2           appliances  refrigerat
    3           appliances  cooking ap
    4           appliances  dishwasher
    5           furniture   mattresses
*/

DROP TABLE IF EXISTS merchandise;

CREATE TABLE merchandise (
    id INT PRIMARY KEY NOT NULL,
    name TEXT NOT NULL,
    band TEXT NOT NULL,
    category INT NOT NULL,
    expiredate DATETIME NOT NULL,
    description TEXT NOT NULL,
    stockId INT NOT NULL
);

INSERT INTO merchandise VALUES
    (1, "apple", "apple NO. 1", 1, "2017/10/01", "", 1),
    (2, "watermelon", "watermelon US", 1, "2017/11/01", "", 1);

/*
    sqlite> select * from merchandise;
    id          name        band         category    expiredate  description  stockId
    ----------  ----------  -----------  ----------  ----------  -----------  ----------
    1           apple       apple NO. 1  1           2017/10/01               1
    2           watermelon  watermelon   1           2017/11/01               1
*/

DROP TABLE IF EXISTS member;

CREATE TABLE member (
    id INT PRIMARY KEY NOT NULL, 
    name TEXT NOT NULL, 
    address TEXT NOT NULL,
    type INT NOT NULL,
    membership INT NOT NULL,
    expiredate DATETIME NOT NULL
);

INSERT INTO member VALUES
    (1, "Mary", "1616 Pine St", 1, 1111111111, "2018/01/01"),
    (2, "Tom", "1617 Pine St", 2, 2222222222, "2018/01/02"),
    (3, "Tina", "1618 Pine St", 3, 33333333333, "2018/01/03"),
    (4, "Jack", "1619 Pine St", 1, 44444444444, "2018/01/04"),
    (5, "John", "1620 Pine St", 2, 55555555555, "2018/01/05"),
    (6, "Elan", "1621 Pine St", 3, 666666666666, "2018/01/06"),
    (7, "Lucy", "1622 Pine St", 2, 7777777777, "2018/01/07"),
    (8, "Dave", "1623 Pine St", 3, 8888888888, "2018/01/08"),
    (9, "Lucky", "1624 Pine St", 1, 9999999999, "2018/01/09"),
    (10, "Allen", "1625 Pine St", 2, 1000000000, "2018/01/11"),
    (11, "Mike", "1626 Pine St", 3, 200000000, "2018/01/12");

/*
    sqlite> select * from member;
    id          name        address       type        membership  expiredate
    ----------  ----------  ------------  ----------  ----------  ----------
    1           Mary        1616 Pine St  1           123456789   2018/01/01 
*/

DROP TABLE IF EXISTS memberTypeMap;

CREATE TABLE memberTypeMap (
    typeId INT PRIMARY KEY NOT NULL,
    typeName TEXT NOT NULL
);

INSERT INTO memberTypeMap VALUES
    (1, "Gold Star Membership"),
    (2, "Executive Membership"),
    (3, "Business Membership");

/*
    sqlite> select * from memberTypeMap;
    typeId      typeName
    ----------  --------------------
    1           Gold Star Membership
    2           Executive Membership
    3           Business Membership
*/

DROP TABLE IF EXISTS orders;

CREATE TABLE orders (
    id INT NOT NULL, 
    memberId INT NOT NULL, 
    date DATETIME NOT NULL, 
    merchandiseId INT NOT NULL, 
    price FLOAT NOT NULL, 
    discount FLOAT NOT NULL,
    PRIMARY KEY (id, merchandiseId)
);

INSERT INTO orders VALUES
    (1, 1, "2017/8/14", 1, 10.99, 0.99),
    (1, 1, "2017/8/14", 2, 11.99, 2.99),
    (2, 2, "2017/8/15", 1, 12.99, 1.99),
    (2, 2, "2017/8/15", 2, 13.99, 2.99),
    (3, 3, "2017/8/16", 1, 14.99, 1.99),
    (3, 3, "2017/8/16", 2, 15.99, 3.99),
    (4, 4, "2017/8/17", 1, 16.99, 4.99),
    (4, 4, "2017/8/17", 2, 17.99, 5.99),
    (5, 5, "2017/8/18", 1, 18.99, 2.99);

/*
    sqlite> select * from orders;
    id          memberId    date        merchandiseId  price       discount
    ----------  ----------  ----------  -------------  ----------  ----------
    1           1           2017/8/14   1              10.99       0.99
*/

DROP TABLE IF EXISTS employee;

CREATE TABLE employee(
   id INT PRIMARY KEY NOT NULL,
   name TEXT NOT NULL,
   age INT NOT NULL,
   address TEXT NOT NULL,
   salary FLOAT NOT NULL
);

INSERT INTO employee VALUES
    (1, 'Paul', 32, 'California' , 20000.0),
    (2, 'Allen', 25, 'Texas' , 15000.0),
    (3, 'Teddy', 23, 'Norway' , 20000.0),
    (4, 'Mark', 25, 'Rich-Mond' , 65000.0),
    (5, 'David', 27, 'Texas' , 85000.0),
    (6, 'Kim', 22, 'South-Hall' , 45000.0),
    (7, 'James', 24, 'Houston' , 10000.0);

/*
    sqlite> select * from employee;
    id          name        age         address     salary
    ----------  ----------  ----------  ----------  ----------
    1           Paul        32          California  20000.0
    2           Allen       25          Texas       15000.0
    3           Teddy       23          Norway      20000.0
    4           Mark        25          Rich-Mond   65000.0
    5           David       27          Texas       85000.0
    6           Kim         22          South-Hall  45000.0
    7           James       24          Houston     10000.0
*/

DROP TABLE IF EXISTS department;

CREATE TABLE department(
   id INT PRIMARY KEY NOT NULL,
   dept CHAR(50) NOT NULL,
   emp_id INT NOT NULL
);

INSERT INTO department VALUES
    (1, 'IT Billing', 1),
    (2, 'Engineering', 2),
    (3, 'Finance', 7);

/*
    sqlite> select * from department;
    id          dept        emp_id
    ----------  ----------  ----------
    1           IT Billing  1
    2           Engineerin  2
    3           Finance     7
*/

/*
    step 1: get customer order details
*/

select m.name,m.address,good.name,o.price,o.discount,o.date from orders o 
    join member m on o.memberId = m.id 
    join merchandise good on good.id = o.merchandiseId;

/*
    sqlite> select m.name,m.address,good.name,o.price,o.discount,o.date from orders o
       ...>     join member m on o.memberId = m.id
       ...>     join merchandise good on good.id = o.merchandiseId;
    name        address       name        price       discount    date
    ----------  ------------  ----------  ----------  ----------  ----------
    Mary        1616 Pine St  apple       10.99       0.99        2017/8/14
    Mary        1616 Pine St  watermelon  11.99       2.99        2017/8/14
    Tom         1617 Pine St  apple       12.99       1.99        2017/8/15
    Tom         1617 Pine St  watermelon  13.99       2.99        2017/8/15
    Tina        1618 Pine St  apple       14.99       1.99        2017/8/16
    Tina        1618 Pine St  watermelon  15.99       3.99        2017/8/16
    Jack        1619 Pine St  apple       16.99       4.99        2017/8/17
    Jack        1619 Pine St  watermelon  17.99       5.99        2017/8/17
    John        1620 Pine St  apple       18.99       2.99        2017/8/18
*/

/*
    step 2: get customer order total summary by date
*/

select m.name, sum(o.price) as total, sum(o.discount) as discount, o.date from orders o 
    join member m on o.memberId = m.id 
    join merchandise me on me.id = o.merchandiseId
    group by m.name,o.date;

/*
    sqlite> select m.name, sum(o.price) as total, sum(o.discount) as discount, o.date from orders o
       ...>     join member m on o.memberId = m.id
       ...>     join merchandise me on me.id = o.merchandiseId
       ...>     group by m.name,o.date;
    name        total       discount    date
    ----------  ----------  ----------  ----------
    Jack        34.98       10.98       2017/8/17
    John        18.99       2.99        2017/8/18
    Mary        22.98       3.98        2017/8/14
    Tina        30.98       5.98        2017/8/16
    Tom         26.98       4.98        2017/8/15
*/

/*
    step 3: get customer order total summary order by total
*/

select m.name, sum(o.price) as total, sum(o.discount) as discount, o.date from orders o 
    join member m on o.memberId = m.id 
    join merchandise me on me.id = o.merchandiseId
    group by m.name,o.date
    order by total desc;

/*
    sqlite> select m.name, sum(o.price) as total, sum(o.discount) as discount, o.date from orders o
       ...>     join member m on o.memberId = m.id
       ...>     join merchandise me on me.id = o.merchandiseId
       ...>     group by m.name,o.date
       ...>     order by total desc;
    name        total       discount    date
    ----------  ----------  ----------  ----------
    Jack        34.98       10.98       2017/8/17
    Tina        30.98       5.98        2017/8/16
    Tom         26.98       4.98        2017/8/15
    Mary        22.98       3.98        2017/8/14
    John        18.99       2.99        2017/8/18
*/

/*
    requirement 1: list customers rewards
*/

select m.name, sum(o.price) as total, sum(o.discount) as discount, sum(o.price)*0.02 as rewards from orders o 
    join member m on o.memberId = m.id 
    join merchandise me on me.id = o.merchandiseId
    group by m.name
    order by total desc;

/*
    sqlite> select m.name, sum(o.price) as total, sum(o.discount) as discount, sum(o.price)*0.02 as rewards from orders o
       ...>     join member m on o.memberId = m.id
       ...>     join merchandise me on me.id = o.merchandiseId
       ...>     group by m.name
       ...>     order by total desc;
    name        total       discount    rewards
    ----------  ----------  ----------  ----------
    Jack        34.98       10.98       0.6996
    Tina        30.98       5.98        0.6196
    Tom         26.98       4.98        0.5396
    Mary        22.98       3.98        0.4596
    John        18.99       2.99        0.3798
*/


/*
    retuqirement 2: which merchandise is most popular. 
*/

