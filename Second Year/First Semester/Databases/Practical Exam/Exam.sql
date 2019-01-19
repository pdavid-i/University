--Create a database that allows the management of an Ocean exploration system. The entities in the system are:
--Teams, Oceans, Ships and Sensors. An Ocean has a name and an average depth. A Ship has a capacity, a name and
--belongs to only one team. A team has a name and can own multiple ships. Sensors have a serial id, the longitude
--and latitude of their location, the Ocean they were deployed in, and the Team that owns them. Sensors gather
--data about the ocean waves, such as height, propagation, period and propagation. You have to:
--a) Design a suiting database for this task
--b) Create a procedure that takes as parameters a serial Id, an ocean, a team name, a latitude and longitude
--   and adds a sensor to the database  
--c) Create a view of all the teams that have sensors in the Arctic Ocean but not in the Pacific
--d) Create a procedure that returns the oceans ordered based on their wavelength





--a) Design a suiting database for this task
create database OceanExplorer
use OceanExplorer

if OBJECT_ID('Records', 'U') is not null
  drop table Records
if OBJECT_ID('Sensors', 'U') is not null
  drop table Sensors
if OBJECT_ID('Oceans', 'U') is not null
  drop table Oceans
if OBJECT_ID('Ships', 'U') is not null
  drop table Ships
if OBJECT_ID('Teams', 'U') is not null
  drop table Teams


  create table Teams (
		name  varchar(20) primary key
)
  
create table Oceans (
	name  varchar(20) primary key,
	avg_dept float
)

create table Ships (
	team  varchar(20) foreign key references Teams(name),
	name  varchar(20) primary key,
	capacity float
)

create table Sensors (
	ocean varchar(20) foreign key references Oceans(name),
	sensor_id int primary key,
	team  varchar(20) foreign key references Teams(name),
	latitude float,
	longitude float
)

create table Records (
	record_id int primary key identity (1,1),
	sensor_id int foreign key references Sensors(sensor_id),
	wheight float,
	wlength float,
	wperiod float,
	wpropagation float
)

insert into Oceans values ('Pacific', 100.00),
                         ('Arctic', 500.00),
                         ('Indian', 300.00),
                         ('Atlantic', 800.00),
                         ('Antarctic', 120.00)

insert into Teams values ('Alfa'),
                         ('Beta'),
                         ('Gamma')
                   
insert into Sensors values ('Pacific',1,'Alfa',0,0 ),
                         ('Arctic',2, 'Beta',0,0),
                         ('Indian',3,'Alfa' ,0,0),
                         ('Atlantic',4, 'Beta',0,0),
                         ('Antarctic',5, 'Gamma',0,0)

						         
insert into Records values (1,1, 9,1,1 ),
                         (2,1, 8,1,1),
                         (3,1, 7,1,1 ),
                         (4,1, 6,1,1),
                         (5,1, 15,1,1)

--b) Create a procedure that takes as parameters a serial Id, an ocean, a team name, a latitude and longitude
--   and adds a sensor to the database  
go
create or alter proc AddSensor @ocean varchar(20), @team varchar(20), @serialnr int, @latitude float, @longitude float as
    declare @checkIfAlreadyExists int = (select Sensors.sensor_id from Sensors where Sensors.sensor_id = @serialnr)
    if @checkIfAlreadyExists is null
				insert into Sensors values (@ocean, @serialnr, @team, @latitude, @longitude)
  go

AddSensor 'Pacific', 'Alfa', 101, 23.5, 23.4;
SELECT * FROM Sensors

--c) Create a view of all the teams that have sensors in the Arctic Ocean but not in the Pacific
go
CREATE VIEW NordicTeams AS
SELECT DISTINCT Sensors.team FROM Sensors where Sensors.ocean = 'Arctic'
EXCEPT
SELECT DISTINCT Sensors.team FROM Sensors where Sensors.ocean = 'Pacific'
go

SELECT * FROM NordicTeams
go

--d) Create a procedure that returns the oceans ordered based on their wavelength
go
create or alter function OceansFrequencies() returns table
return
  select distinct Sensors.ocean, Records.wlength FROM Sensors
INNER JOIN Records on Records.sensor_id = Sensors.sensor_id

go
SELECT * FROM OceansFrequencies() as a ORDER BY a.wlength DESC





