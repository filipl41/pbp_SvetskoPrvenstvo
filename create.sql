
drop database if exists SVETSKO_PRVENSTVO;
create database SVETSKO_PRVENSTVO;
use SVETSKO_PRVENSTVO;

create table Drzava (
	id int not null primary key,
	naziv varchar(45) not null
);

create table Reprezentacija (
	pozicijaNaFibaListi int not null,
	id int not null references Drzava(id),
	unique(pozicijaNaFibaListi)
);

create table Igrac (
	idIgraca int not null primary key,
	ime varchar(45) not null,
	prezime varchar(45) not null,
	datumRodjenja date not null,
	idDrzava int not null references Drzava(id)
);

create table Strucni_stab (
	id int not null primary key,
	ime varchar(45) not null,
	prezime varchar(45) not null,
	datumRodjenja date not null,
	idDrzava int not null references Drzava(id)
);

create table Statistika (
	brojPoena int not null default 0,
	brojAsistencija int not null default 0,
	brojBlokada int not null default 0,
	brojSkokova int not null default 0,
	brojPromasenihSuteva int not null default 0,
	brojIzgubljenihLopti int not null default 0,
	brojFaulova int not null default 0,
	indeksKorisnosti int as (brojPoena + brojAsistencija + brojBlokada + brojSkokova - brojPromasenihSuteva - brojIzgubljenihLopti - brojFaulova),
	id int not null references Igrac(idIgraca)
	);
	
create table Sudija (
	idSudije int not null primary key,
	ime varchar(45) not null,
	prezime varchar(45) not null,
	idDrzava int not null references Drzava(id)
);

create table Grad (
	idGrada int not null primary key,
	naziv varchar(45) not null
);

create table Grupa (
	id varchar(45) not null,
	bodovi int not null,
	odigranoUtakmica int not null,
	kosRazlika int not null,
	idReprezentacija int not null references Reprezentacija(id),
	idGrada int not null references Grad(idGrada)
);

create table Utakmica (
	id int not null primary key,
	ishod int not null,
	datum date not null,
	poeniGost int not null,
	poeniDomacin int not null,
	poeniUkupno int as (poeniDomacin + poeniGost),
	idSudije int not null references Sudija(idSudije),
	domacin int not null references Grupa(idReprezentacija),
	gost int not null references Grupa(idReprezentacija),
	faza varchar(45) default "grupa",
	check(ishod in (1, 2)),
	check (faza in ("finale", "polufinale", "cetvrtfinale", "osmina","sesnestina" "grupa"))

);

create table Nokaut_faza (
	idUtakmice int not null references Utakmica(id),
	idGrada int not null references Grad(idGrada)
);
