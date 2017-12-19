#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#define MAX_QUERY_LEN 1000
#define MAX_STRING_ATT_LEN 45


void error(char*);

MYSQL_RES* executeQuery(MYSQL*, char*);


int main(){
  MYSQL* konekcija;
  MYSQL_RES* rezultat;
  MYSQL_ROW red;
  MYSQL_FIELD* polje;
  
  konekcija = mysql_init(NULL);
  if (mysql_real_connect(konekcija, "localhost", "root", "root", "SVETSKO_PRVENSTVO", 0, NULL, 0) == NULL)
    error("mysql_real_connect failed");
  printf("Unesite naziv reprezentacije za koju zelite da dobijete informacije o igracima\n");
  
  char naziv[MAX_STRING_ATT_LEN];
  char query[MAX_QUERY_LEN];
  
  scanf("%s", naziv);
  sprintf(query, "select ime, prezime from Igrac i join Drzava d on d.id = i.idDrzava where naziv = \"%s\"", naziv);
  rezultat = executeQuery(konekcija, query);
  polje = mysql_fetch_field(rezultat);
  printf("%s\t%s\n", polje[0].name, polje[1].name);
  while(red = mysql_fetch_row(rezultat)){
    printf("%s\t%s\n", red[0], red[1]);
  }
  
  
  return 1;
}

void error(char* s){
  perror(s);
  exit(EXIT_FAILURE);
}

MYSQL_RES* executeQuery(MYSQL* konekcija, char* query){
  if (mysql_query(konekcija, query) != 0)
    error("invalid query");
  MYSQL_RES* rezultat = mysql_use_result(konekcija);
  return rezultat;
  
}