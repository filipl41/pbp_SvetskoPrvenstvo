#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>

#define MAX_QUERY_LEN 1000
#define MAX_STRING_ATT_LEN 45

void error(char* s);
void executeQuery(MYSQL*, char*);



int main(){
  
  MYSQL* konekcija;
  
  konekcija = mysql_init(NULL);
  if (mysql_real_connect(konekcija, "localhost", "root", "root", "SVETSKO_PRVENSTVO", 0, NULL, 0) == NULL)
    error("connection failed");
  printf("Unesite zeljenu opciju:\n");
  printf("1 - Prikaz prvih 5 strelaca turnira\n");
  printf("2 - Prikaz prvih 5 lidera po broju asistencija turnira\n");
  printf("3 - Prikaz prvih 5 skakaca turnira\n");
  printf("4 - Prikaz prvih 5 najkorisnijih igraca turnira\n");
  printf("5 - Kraj\n");
  int opcija;
  scanf("%d", &opcija);
  char query[MAX_QUERY_LEN];
  if (opcija == 1){
    
    sprintf(query, "select ime,prezime,  brojPoena from Igrac i join Statistika s on i.idIgraca = s.id order by  brojPoena desc");
    executeQuery(konekcija, query);
     
  }
  
  else if (opcija == 2){
    
    sprintf(query, "select ime,prezime,  brojAsistencija from Igrac i join Statistika s on i.idIgraca = s.id order by  brojAsistencija desc");
    executeQuery(konekcija, query);
    
  }
  
  else if (opcija == 3){
    
    sprintf(query, "select ime,prezime,  brojSkokova from Igrac i join Statistika s on i.idIgraca = s.id order by  brojSkokova desc");
    executeQuery(konekcija, query);
    
  }
  
  else if (opcija == 4){
    
    sprintf(query, "select ime,prezime,  indeksKorisnosti from Igrac i join Statistika s on i.idIgraca = s.id order by  indeksKorisnosti desc");
    executeQuery(konekcija, query);
    
  }
  else if (opcija == 5)
    exit(EXIT_SUCCESS);
  else
    error("wrong option");
  
  return 1;
}




void error(char* s){
  perror(s);
  exit(EXIT_FAILURE);
}

void executeQuery(MYSQL* konekcija,char* query){
  
  MYSQL_RES* rezultat;
  MYSQL_ROW red;
  MYSQL_FIELD* polje;
  int i;
  
  if (mysql_query(konekcija, query) != 0)
    error("invalid query");
  rezultat = mysql_use_result(konekcija);
  polje = mysql_fetch_field(rezultat);
  printf("%s\t%s\t%s\n", polje[0].name, polje[1].name, polje[2].name);
  for (i = 0; i < 5; i++){
    red = mysql_fetch_row(rezultat);
    printf("%s\t%s\t%s\n", red[0], red[1], red[2]);
      
 }
 
 
}

