use FoodDelivery

drop proc change_no1
drop proc revert_change_no1
drop proc change_no2
drop proc revert_change_no2
drop proc change_no3
drop proc revert_change_no3
drop proc change_no4
drop proc revert_change_no4
drop proc change_no5
drop proc revert_change_no5
drop proc change_no6
drop proc revert_change_no6
drop proc change_no7
drop proc revert_change_no7
drop proc setVersion
drop table Version


-- modify the type of a column;
GO
CREATE PROC change_no1
    AS
		ALTER TABLE Adress ALTER COLUMN town VARCHAR(40)
GO


CREATE PROC revert_change_no1
    AS
		ALTER TABLE Adress ALTER COLUMN town VARCHAR(50);
GO


--add/remove column
CREATE PROC change_no2
    AS
    ALTER TABLE Adress ADD Country VARCHAR(50)
GO

CREATE PROC revert_change_no2
    AS
    ALTER TABLE Adress DROP COLUMN Country
GO

--add/remove default constraint
CREATE PROC change_no3
    AS
    ALTER TABLE Adress ADD CONSTRAINT town_constraint  DEFAULT 'null' FOR town
GO

CREATE PROC revert_change_no3
    AS
    ALTER TABLE Adress DROP CONSTRAINT town_constraint
GO


--remove/add primary key
CREATE PROC change_no4
    AS
		--We must first remove the Foreign key that references the Primary key
		ALTER TABLE FoodOrder DROP CONSTRAINT FK_FoodOrder_Food
		--Now we can remove the primary key
	 	ALTER TABLE Food DROP CONSTRAINT PK_Food
GO

CREATE PROC revert_change_no4
    AS
	  --We must first create the Primary key and only after the Foreign key that references it
	  ALTER TABLE Food ADD CONSTRAINT PK_Food PRIMARY KEY (food_name)
	  ALTER TABLE FoodOrder ADD CONSTRAINT FK_FoodOrder_Food FOREIGN KEY (food_name) REFERENCES Food(food_name)
GO

--add/remove a candidate key
CREATE PROC change_no5
	AS
		ALTER TABLE Clients ADD CONSTRAINT CK_name UNIQUE (first_name, last_name)
GO

CREATE PROC revert_change_no5
	AS
			ALTER TABLE Clients DROP CONSTRAINT CK_name 
GO

--remove/create foreign key
CREATE PROC change_no6
	AS
		ALTER TABLE FoodOrder DROP CONSTRAINT FK_FoodOrder_Orders
GO

CREATE PROC revert_change_no6
	AS
		ALTER TABLE FoodOrder ADD CONSTRAINT FK_FoodOrder_Orders FOREIGN KEY(order_id) references Orders(order_id)
GO

--create / remove a table
CREATE PROC change_no7
    AS
    CREATE TABLE NewTable (
        name1 VARCHAR(30),
        age TINYINT,
        id INT
    );
GO

CREATE PROC revert_change_no7
    AS
    DROP TABLE NewTable
GO


CREATE TABLE Version ( version INT );
delete FROM Version
INSERT INTO Version values(0);

GO

CREATE PROCEDURE setVersion @versionTo INT
  AS
  IF @versionTo < 0 OR @versionTo > 7
      PRINT 'Versions are between 0 and 7'
  ELSE
    BEGIN
      DECLARE @currentVersion INT
      DECLARE @procedureName VARCHAR(20)
      SET @currentVersion=(SELECT version from Version)
      WHILE @currentVersion < @versionTo
      BEGIN
        SET @currentVersion = @currentVersion + 1
        SET @procedureName = 'change_no' + convert(VARCHAR(15), @currentVersion)
        PRINT @procedureName
        EXECUTE @procedureName
      END
      WHILE @currentVersion > @versionTo
      BEGIN
        SET @currentVersion = @currentVersion - 1
        SET @procedureName = 'revert_change_no' + convert(VARCHAR(15), @currentVersion+1)
        PRINT @procedureName
        EXECUTE @procedureName
      END
    END
    IF @versionTo >= 0 AND @versionTo < 8
	  UPDATE Version SET version = @versionTo
GO

EXEC setVersion 2