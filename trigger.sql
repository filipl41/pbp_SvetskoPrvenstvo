delimiter $

create trigger utakmicaBI before insert on Utakmica 
for each row 
begin 
if (select g.id from grupa g where g.odigranoUtakmica <= 5 and g.idReprezentacija = new.domacin) != 
	(select g.id from grupa g where g.odigranoUtakmica <= 5 and g.idReprezentacija = new.gost) 
then SIGNAL SQLSTATE '45000' SET message_text = 'Utakmice u grupnoj fazi moraju biti odigrane izmedju timova iz iste grupe!'; 
end if; 
end $



create trigger utakmicaBI2 before insert on Utakmica 
for each row 
begin 
if new.gost = (select idDrzava from sudija s where s.idSudije = new.idSudije) or new.domacin = (select idDrzava from sudija s where s.idSudije = new.idSudije) 
then SIGNAL SQLSTATE '45000' SET message_text = 'Sudija ne moze biti iz iste zemlje kao reprezentacije kojima sudi!'; 
end if; 
end $



create trigger utakmicaAI after insert on Utakmica 
for each row 
begin 
if exists(select * from grupa g where g.idReprezentacija = new.domacin and g.odigranoUtakmica <= 5) 
then 
update Grupa 
set odigranoUtakmica = odigranoUtakmica + 1,
kosRazlika = kosRazlika + new.poeniDomacin - new.poeniGost  
where new.domacin = idReprezentacija; 

update Grupa
set odigranoUtakmica = odigranoUtakmica + 1,
kosRazlika = kosRazlika + new.poeniGost - new.poeniDomacin
where new.gost = idReprezentacija; 

update Grupa 
set bodovi = case when new.ishod = 1 then bodovi + 2 else bodovi + 1 end 
where new.domacin = idReprezentacija;

update Grupa
set bodovi = case when new.ishod = 2 then bodovi + 2 else bodovi + 1 end 
where new.gost = idReprezentacija;

end if; 
end $