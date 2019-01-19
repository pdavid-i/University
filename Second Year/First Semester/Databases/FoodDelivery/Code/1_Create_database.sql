--create database FoodDelivery
--drop database FoodDelivery
use FoodDelivery

drop table Contracts
drop table Suppliers
drop table Employees
drop table FoodOrder
drop table DrinkOrder
drop table Food
drop table Drinks
drop table Orders
drop table Restaurant
drop table Clients
drop table Adress
drop table RestaurantAdress
drop table Accounts
create table Adress
(
	adress_id int PRIMARY KEY identity(1,1), 
	town varchar(50),
	street varchar(50),
	number int,
	apartment int
);

create table Clients
(
	cnp bigint PRIMARY KEY, 
	first_name varchar(50),
	last_name varchar(50),
	adress_id int FOREIGN KEY REFERENCES Adress(adress_id),
);


create table Food
(
	food_name varchar(30) CONSTRAINT PK_Food PRIMARY KEY,
	price float,
	calories int
);

create table Drinks
(
	drink_name varchar(30) PRIMARY KEY,
	price float,
	calories int
);

create table Suppliers
(
	supplier_id int primary key identity(1,1),
	supplier_name varchar(30),
	supplier_revenue int
)

create table RestaurantAdress
(
	adress_id int PRIMARY KEY identity(1,1), 
	town varchar(50),
	street varchar(50),
	number int
	
)

create table Restaurant
(
	restaurant_id int primary key identity(1,1),
	restaurant_name varchar(30),
	restaurant_adress_id int FOREIGN KEY REFERENCES RestaurantAdress(adress_id),
	stars int,
	review_score float
);

create table Employees
(
	employee_cnp char(13) primary key,
	employee_first_name varchar(30),
	employee_last_name varchar(30),
	position varchar(10) NOT NULL CHECK (position IN('chef', 'cook', 'assistant', 'waiter', 'bartender', 'cleaner')),
	salary int, 
	restaurant_id int foreign key references Restaurant(restaurant_id)
)

create table Contracts
(
	starting_date datetime,
	end_date datetime,
	contract_nr int primary key identity(1,1),
	restaurant_id int foreign key references Restaurant(restaurant_id),
	supplier_id int foreign key references Suppliers(supplier_id)
)

create table Orders
(
	order_id int PRIMARY KEY identity(1,1),
	restaurant_id int foreign key references Restaurant(restaurant_id),
	cnp bigint foreign key references Clients(cnp),
	price int
)

create table FoodOrder
(
	food_order_id int PRIMARY KEY identity(1,1),
	order_id int CONSTRAINT FK_FoodOrder_Orders FOREIGN KEY references Orders(order_id),
	food_name varchar(30) CONSTRAINT FK_FoodOrder_Food FOREIGN KEY references FOOD(food_name),
	quantity int
);

create table DrinkOrder
(
	drink_order_id int PRIMARY KEY identity(1,1),
	order_id int FOREIGN KEY references Orders(order_id),
	drink_name varchar(30) references Drinks(drink_name),
	quantity int
);

create table Accounts
(
	username VARCHAR(40),
	server_region VARCHAR(10) NOT NULL CHECK (server_region IN ('EUNE', 'NA', 'EUW', 'ASIA', 'RUSSIA'))
	CONSTRAINT pk_userID PRIMARY KEY (username, server_region)
);
