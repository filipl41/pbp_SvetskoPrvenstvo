USE SVETSKO_PRVENSTVO;

insert into Drzava values
(1, 'Serbia'),
(2, 'Spain'),
(3, 'USA'),
(4, 'Lithuania'),
(5, 'Turkey'),
(6, 'Greece'),
(7, 'Senegal'),
(8, 'France'),
(9, 'Slovenia'),
(10, 'Argentina'),
(11, 'Brazi'),
(12, 'China'),
(13, 'Australia'),
(14, 'Jamaica'),
(15, 'Japan'),
(16, 'Russia'),
(17, 'Puerto Rico'),
(18, 'Egypt'),
(19, 'Finland'),
(20, 'Italy'),
(21, 'Mexico'),
(22, 'Latvia'),
(23, 'New Zeland'),
(24, 'Nigeria'),
(25, 'Croatia'),
(26, 'South Korea'),
(27, 'Macedonia'),
(28, 'Estonia');


insert into Reprezentacija values
(2, 1),
(3, 2),
(1, 3),
(4, 4),
(12, 5),
(5, 6),
(28, 7),
(20, 8),
(6, 9),
(7, 10),
(10, 11),
(30, 12),
(11, 13),
(40, 14),
(22, 15),
(9, 16),
(23, 17),
(31, 18),
(19, 19),
(13, 20),
(29, 21),
(14, 22),
(37, 23),
(21, 24);


insert into Grad values 
(11, 'Bejing'),
(22, 'Guangzhou'),
(33, 'Shanghai'),
(44, 'Wuhan');


insert into Grupa values
('A', 0, 0, 0, 1, 11),
('A', 0, 0, 0, 8, 11),
('A', 0, 0, 0, 14, 11),
('A', 0, 0, 0, 20, 11),
('A', 0, 0, 0, 9, 11),
('A', 0, 0, 0, 23, 11),
('B', 0, 0, 0, 2, 22),
('B', 0, 0, 0, 7, 22),
('B', 0, 0, 0, 13, 22),
('B', 0, 0, 0, 24, 22),
('B', 0, 0, 0, 12, 22),
('B', 0, 0, 0, 22, 22),
('C', 0, 0, 0, 3, 33),
('C', 0, 0, 0, 6, 33),
('C', 0, 0, 0, 11, 33),
('C', 0, 0, 0, 21, 33),
('C', 0, 0, 0, 15, 33),
('C', 0, 0, 0, 16, 33),
('D', 0, 0, 0, 4, 44),
('D', 0, 0, 0, 5, 44),
('D', 0, 0, 0, 10, 44),
('D', 0, 0, 0, 19, 44),
('D', 0, 0, 0, 17, 44),
('D', 0, 0, 0, 18, 44);


insert into Sudija values
(1, 'Ilija', 'Belosevic', 1),
(2, 'Milija', 'Vojinovic', 1),
(3, 'Luigi', 'Lamonica', 20);


insert into Strucni_stab values
(1, 'Aleksandar', 'Djordjevic', DATE '1967-8-12', 1),
(2, 'Nebojsa', 'Ilic', DATE '1970-4-7', 1),
(3, 'Gregg', 'Popovich', DATE '1955-5-1', 3);


insert into Igrac values 
(1, 'Milos', 'Teodosic', DATE '1985-4-4', 1),
(2, 'Pau', 'Gasol', DATE '1980-2-7', 2),
(3, 'LeBron', 'James', DATE '1983-4-8', 3),
(4, 'Mingaugas', 'Kuzminsas', DATE '1988-12-11', 4),
(5, 'Omer', 'Asik', DATE '1990-3-8', 5),
(6, 'Jorgos', 'Printezis', DATE '1987-7-7', 6),
(7, 'Boris', 'Ndour', DATE '1991-11-8', 7),
(8, 'Mathias', 'Lessort', DATE '1995-7-4', 8),
(9, 'Luka', 'Doncic', DATE '1998-1-12', 9),
(10, 'Luis', 'Scola', DATE '1980-7-7', 10);


insert into Statistika(brojPoena, brojAsistencija, brojBlokada, brojSkokova, brojPromasenihSuteva, brojIzgubljenihLopti, brojFaulova,id)
			   values (12, 7, 0, 2, 4, 2, 1, 1),
					  (20, 2,3, 10, 7, 1, 2, 2 ),
					  (21, 6, 4, 9, 5, 1, 2, 3),
					  (7, 1, 1, 4, 1, 0, 4, 4),
					  (3, 0, 2, 8, 2, 2, 5, 5),
					  (11, 3, 1, 6, 4, 2, 2, 6),
					  (8, 0, 4, 9, 5, 2, 0, 7);