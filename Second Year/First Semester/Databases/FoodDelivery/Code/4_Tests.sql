use FoodDelivery

--creating the views
GO
CREATE VIEW VAdresses
AS
	SELECT DISTINCT R.town, A.street FROM Adress A
	INNER JOIN RestaurantAdress R on R.town = A.town

GO
CREATE VIEW VDrinks
AS
	SELECT * FROM Drinks

GO
CREATE VIEW VOrderedFoods
AS
	SELECT DISTINCT F.food_name FROM Food F 
	INNER JOIN FoodOrder FO on FO.food_name = F.food_name
	GROUP BY F.food_name
GO
INSERT INTO Views (Name) VALUES ('VAdresses'), ('VDrinks'), ('VOrderedFoods')

INSERT INTO Tests VALUES ('select_view')
INSERT INTO Tests VALUES ('delete_adresses')
INSERT INTO Tests VALUES ('insert_adresses')
INSERT INTO Tests VALUES ('delete_drinks')
INSERT INTO Tests VALUES ('insert_drinks')
INSERT INTO Tests VALUES ('delete_foods')
INSERT INTO Tests VALUES ('insert_foods')

INSERT INTO TestViews VALUES (1, 1), (1, 2), (1, 3)

INSERT INTO Tables(Name) VALUES ('RestaurantAdress'), ('Restaurant'),('Account')


INSERT INTO TestTables (TestId, TableID, NoOfRows, Position) VALUES (1, 1, 90, 1), 
																	(2, 2, 90, 2),
																	(3, 3, 90, 3)

--before test delete prev tests
delete from TestRunViews
delete from TestRuns
delete from TestRunTables

GO
CREATE PROC insert_restaurant_adresses AS
	DECLARE @counter int = 1;
	DECLARE @maxim_rows int
	SELECT @maxim_rows = NoOfRows FROM TestTables WHERE TestId = 1
	WHILE @counter < @maxim_rows
		BEGIN
			DECLARE @test_town VARCHAR(12) = 'TestTown'  + convert(varchar(4), @counter)
			DECLARE @test_street VARCHAR(12) = 'TestTown'  + convert(varchar(4), @counter)
			DECLARE @test_street_number int = @counter
			INSERT INTO RestaurantAdress VALUES(@test_town, @test_street, @test_street_number)
			SET @counter = @counter + 1
		END
GO

CREATE PROC delete_restaurant_adresses AS
	DELETE FROM RestaurantAdress WHERE town LIKE 'TestTown%'


GO
CREATE PROC insert_restaurants AS
	DECLARE @counter int = 1;
	DECLARE @maxim_rows int
	SELECT @maxim_rows = NoOfRows FROM TestTables WHERE TestId = 2
	WHILE @counter < @maxim_rows
		BEGIN
			DECLARE @test_name VARCHAR(12) = 'TestName'  + convert(varchar(4), @counter)
			INSERT INTO Restaurant VALUES(@test_name, @counter, @counter, @counter)
			SET @counter = @counter + 1
		END

GO
CREATE PROC delete_restaurants AS
	DELETE FROM Restaurant WHERE Restaurant.restaurant_name LIKE 'TestName%'

GO
CREATE PROC insert_accounts AS
	DECLARE @counter int = 1;
	DECLARE @maxim_rows int
	SELECT @maxim_rows = NoOfRows FROM TestTables WHERE TestId = 3
	WHILE @counter < @maxim_rows
		BEGIN
			DECLARE @test_name VARCHAR(12) = 'TestName'  + convert(varchar(4), @counter)
			INSERT INTO Accounts VALUES(@test_name,'EUNE')
			SET @counter = @counter + 1
		END
GO

CREATE PROC delete_accounts AS
	DELETE FROM Accounts
GO

-----------------------------------------------
--drop proc TestRunView
GO
create PROC TestRunView
as
  begin
    DECLARE @startTime1 DATETIME;
    DECLARE @endTime1 DATETIME;
    DECLARE @startTime2 DATETIME;
    DECLARE @endTime2 DATETIME;
    DECLARE @startTime3 DATETIME;
    DECLARE @endTime3 DATETIME;

    SET @startTime1 = GETDATE();
    EXEC ('select * from VAdresses');
    PRINT 'select * from VAdresses';
    SET @endTime1 = GETDATE();

    INSERT INTO TestRuns VALUES ('test_view', @startTime1, @endTime1)
    INSERT INTO FoodDelivery.dbo.TestRunViews(TestRunID, ViewID, StartAt, EndAt) values (@@IDENTITY, 1, @startTime1, @endTime1);

    SET @startTime2 = GETDATE();
    EXEC ('select * from VDrinks');
    PRINT 'select * from VDrinks';
    SET @endTime2 = GETDATE();
    INSERT INTO TestRuns VALUES ('test_view2', @startTime2, @endTime2)
    INSERT INTO FoodDelivery.dbo.TestRunViews(TestRunID, ViewID, StartAt, EndAt) values (@@identity, 2, @startTime2, @endTime2);

    SET @startTime3 = GETDATE();
    EXEC ('select * from VOrderedFoods');
    PRINT 'select * from VOrderedFoods';
    SET @endTime3 = GETDATE();
    INSERT INTO TestRuns VALUES ('test_view3', @startTime3, @endTime3)
    INSERT INTO FoodDelivery.dbo.TestRunViews(TestRunID, ViewID, StartAt, EndAt) values (@@identity, 3, @startTime3, @endTime3);
  end
GO


GO
--drop proc TestRunInsertRemove
CREATE PROC TestRunInsertRemove
  AS
    begin
      DECLARE @startTime1 DATETIME;
      DECLARE @endTime1 DATETIME;
	  DECLARE @startTime2 DATETIME;
      DECLARE @endTime2 DATETIME;

      DECLARE @startTime3 DATETIME;
      DECLARE @endTime3 DATETIME;
      DECLARE @startTime4 DATETIME;
      DECLARE @endTime4 DATETIME;
	  
      DECLARE @startTime5 DATETIME;
      DECLARE @endTime5 DATETIME;	  
      DECLARE @startTime6 DATETIME;
      DECLARE @endTime6 DATETIME;

      SET @startTime1 = GETDATE()
      EXEC insert_restaurant_adresses
      PRINT ('inserted restaurant adresses')
      SET @endTime1 = GETDATE()
      INSERT INTO TestRuns VALUES ('test_insert_restaurant_adresses', @startTime1, @endTime1)
      INSERT INTO TestRunTables VALUES (@@IDENTITY, 1, @startTime1, @endTime1)

      SET @startTime3 = GETDATE()
      exec insert_restaurants
      print ('inserted restaurants')
      SET @endTime3 = GETDATE()
      INSERT INTO TestRuns values ('test_insert_restaurants', @startTime3, @endTime3)
      INSERT INTO TestRunTables VALUES (@@IDENTITY, 2, @startTime3, @endTime3)

      SET @startTime4 = GETDATE()
      exec delete_restaurants
      print ('deleted restaurants')
      SET @endTime4 = GETDATE()
      INSERT INTO TestRuns values ('test_delete_restaurants', @startTime4, @endTime4)
      INSERT INTO TestRunTables VALUES (@@IDENTITY, 2, @startTime4, @endTime4)
	  SELECT * FROM Restaurant

	  SET @startTime2 = GETDATE()
      EXEC delete_restaurant_adresses
      PRINT ('deleted restaurant adresses')
      SET @endTime2 = GETDATE()
      INSERT INTO TestRuns VALUES ('test_delete_restaurant_adresses', @startTime2, @endTime2)
      INSERT INTO TestRunTables VALUES (@@IDENTITY, 1, @startTime1, @endTime1)

      SET @startTime5 = GETDATE()
      EXEC insert_accounts
      PRINT ('inserted accounts')
      SET @endTime5 = GETDATE()
      INSERT INTO TestRuns VALUES ('test_insert_accounts', @startTime5, @endTime5)
      INSERT INTO TestRunTables VALUES (@@IDENTITY, 3, @startTime5, @endTime5)

      SET @startTime6 = GETDATE()
      EXEC delete_restaurant_adresses
      PRINT ('deleted restaurant adresses')
      SET @endTime6 = GETDATE()
      INSERT INTO TestRuns VALUES ('test_delete_accounts', @startTime6, @endTime6)
      INSERT INTO TestRunTables VALUES (@@IDENTITY, 3, @startTime6, @endTime6)

    end
  GO
exec TestRunView
exec TestRunInsertRemove
SELECT * FROM TestRunViews