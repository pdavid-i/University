use FoodDelivery

--a 

--									See al the things you can get for 16$ and less

SELECT * FROM Food where price BETWEEN 0 and 16 
UNION
SELECT * FROM Drinks where price BETWEEN 0 AND 16


--									Budget meal: see all the food you can get for under 15, or it has more 
--												than 600 calories

SELECT * FROM Food where price < 15  OR calories > 600


--b

--									All the clients that have a registered restaurant in their city
SELECT town
FROM Adress
INTERSECT
SELECT town
FROM RestaurantAdress

--									Get the top 5 client favourite restaurants in Cluj

SELECT TOP 5 restaurant_name, review_score from Restaurant where EXISTS (SELECT * FROM RestaurantAdress 
						where town = 'Cluj' and Restaurant.restaurant_adress_id = RestaurantAdress.adress_id)
						ORDER BY review_score DESC

--c


--									All the female clients that don't work at a restaurant

SELECT cnp, first_name FROM Clients where cnp LIKE '2%'
EXCEPT
SELECT employee_cnp, employee_first_name FROM Employees where employee_cnp LIKE '2%'

--									All the drinks ordered that aren't produced by Coca-Cola or PepsiCo

SELECT DISTINCT drink_name FROM DrinkOrder where drink_name NOT IN
								 ('Cola Cherry', 'Cola', 'Pepsi', 'Pepsi Max')


--d
--									The top 3 most payed employees that do not have to cook

SELECT TOP 3 employee_first_name, employee_last_name, salary, restaurant_name, town
 FROM Employees
LEFT JOIN Restaurant on Restaurant.restaurant_id = Employees.restaurant_id
INNER JOIN Adress on Restaurant.restaurant_adress_id = Adress.adress_id
WHERE position not in ('cook', 'chef', 'assistant')
		ORDER BY salary DESC


--									All registered restaurants and their supplier, ordered by supplier revenue

SELECT restaurant_name, supplier_name, supplier_revenue, contract_nr
FROM Suppliers 
INNER JOIN Contracts on Suppliers.supplier_id = Contracts.supplier_id
RIGHT JOIN Restaurant on Contracts.restaurant_id = Restaurant.restaurant_id
ORDER BY supplier_revenue DESC


--									The food order details where the price exceeded 100 $
SELECT Food.food_name, FoodOrder.order_id, FoodOrder.quantity
FROM Food
FULL JOIN FoodOrder on FoodOrder.food_name = Food.food_name
WHERE (FoodOrder.quantity * Food.price) > 100

--									 The drinks that have never been ordered

SELECT DrinkOrder.drink_name from DrinkOrder
EXCEPT
(SELECT DISTINCT Drinks.drink_name
FROM DrinkOrder
INNER JOIN Drinks on DrinkOrder.drink_name = Drinks.drink_name)

--e
--								     Show ordered foods and their calories expressed in kj

SELECT Food.food_name, Food.calories * 4.184 as 'Calories (kj)' FROM Food
WHERE Food.food_name IN (SELECT FoodOrder.food_name FROM FoodOrder WHERE FoodOrder.food_name = Food.food_name)

--									 Streets of clients that live in high paying cities 
--									(Restaurants have employees payed more than 2200) - could be useful in 
--									 configuring delivery rutes 

SELECT town, street From Adress where town in (
SELECT DISTINCT town FROM RestaurantAdress
INNER JOIN Restaurant on RestaurantAdress.adress_id = Restaurant.restaurant_adress_id
WHERE EXISTS (SELECT * FROM Employees where Restaurant.restaurant_id = Employees.restaurant_id and salary > 2200));

--f
--									Show all restaurants who have employees payed < 1500 $

SELECT Restaurant.restaurant_name
from Restaurant
WHERE EXISTS (SELECT * FROM Employees WHERE Employees.restaurant_id = Restaurant.restaurant_id AND Employees.salary < 1500)

--									The food that has been ordered until now
SELECT Food.food_name, Food.price FROM Food
WHERE EXISTS (SELECT * FROM FoodOrder WHERE FoodOrder.food_name = Food.food_name)

--g								
--									Employees that also order from the workplace
SELECT a.first_name, a.last_name FROM(
SELECT * FROM Employees
INNER JOIN Clients on employee_cnp = Clients.cnp
) as a

--									Show streets that have at least one 5 star restaurant on them
SELECT DISTINCT r.street, r.town FROM(
SELECT * FROM Restaurant
INNER JOIN RestaurantAdress on Restaurant.restaurant_adress_id = RestaurantAdress.adress_id) as r
WHERE r.stars = 5

--h									 
--									 The top cities ranked by the number of customers (at least 3 customers)
SELECT COUNT(adress_id) AS 'Numar de Clienti', a.town
FROM Adress a
GROUP BY town
HAVING COUNT(adress_id) >= 3
ORDER BY COUNT(adress_id) DESC

--									  Restaurant job positions ranked by average income on each position

SELECT position, AVG(salary) as 'Salariul mediu' FROM Employees
GROUP BY position
ORDER BY AVG(salary) DESC

--									  High skill cap job positions - jobs where the the max salary is at least
--																     twice the minimum salary

SELECT position, MAX(salary) FROM Employees
group by position
having MAX(salary) > 2*MIN(salary)

--									   Top restaurants with highest expenditure on salaries

SELECT Restaurant.restaurant_name, SUM(salary) as 'Banii dati pe salarii'  FROM Restaurant
LEFT JOIN Employees on Employees.restaurant_id = Restaurant.restaurant_id
GROUP by Restaurant.restaurant_name
ORDER BY SUM(SALARY) DESC

--i
--											All the restaurants that pay at least one employee more than 2000$
SELECT Restaurant.restaurant_name
FROM Restaurant
WHERE restaurant_name = ANY (SELECT restaurant_name FROM Restaurant AS r INNER JOIN Employees
								on r.restaurant_id = Employees.restaurant_id WHERE Employees.salary > 2000)

SELECT Restaurant.restaurant_name FROM Restaurant
LEFT JOIN Employees on Employees.restaurant_id = Restaurant.restaurant_id
GROUP by Restaurant.restaurant_name
HAVING MAX(salary) > 2000


--									All the drinks ordered that contain sugar
SELECT DISTINCT DrinkOrder.drink_name FROM DrinkOrder
WHERE DrinkOrder.drink_name = ANY (SELECT r.drink_name FROM Drinks AS r INNER JOIN DrinkOrder as o
								on r.drink_name = o.drink_name WHERE r.calories = 0)
 
SELECT DISTINCT drink_name FROM DrinkOrder where drink_name NOT IN
								 ('Cola Cherry', 'Cola', 'Pepsi', 'Fuze Tea', 'Sprite')

--									Restaurants and their score where the contract with the supplier
--									 is more than 8 years

SELECT Restaurant.restaurant_name, Restaurant.review_score FROM RESTAURANT
WHERE restaurant_name = ANY(
SELECT Restaurant.restaurant_name from Restaurant
INNER JOIN Contracts on Restaurant.restaurant_id = Contracts.restaurant_id
INNER JOIN Suppliers on Suppliers.supplier_id = Contracts.supplier_id
WHERE DATEDIFF(YEAR, Contracts.starting_date, Contracts.end_date) > 8)

SELECT Restaurant.restaurant_name,  Restaurant.review_score from Restaurant
INNER JOIN Contracts on Restaurant.restaurant_id = Contracts.restaurant_id
INNER JOIN Suppliers on Suppliers.supplier_id = Contracts.supplier_id
WHERE DATEDIFF(YEAR, Contracts.starting_date, Contracts.end_date) NOT IN (1, 2, 3, 4, 5, 6, 7)

--									The food that had at least 2 servings on the same order
--									(quantity >= 2)

SELECT DISTINCT food_name FROM FoodOrder
WHERE food_name = ANY (SELECT r.food_name FROM Food AS r INNER JOIN FoodOrder as o
								on r.food_name = o.food_name WHERE o.quantity >= 2)
 

SELECT DISTINCT food_name FROM FoodOrder where food_name IN
								 (SELECT r.food_name FROM Food AS r INNER JOIN FoodOrder as o
								on r.food_name = o.food_name WHERE o.quantity >=2 )
