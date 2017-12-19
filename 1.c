#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#define MAX_QUERY_LEN 1000
#define MAX_STRING_ATT_LEN 45

void error(char* s);
MYSQL_RES* executeQuery(MYSQL*,char*);


int main(){
  MYSQL* konekcija;
  MYSQL_ROW red;
  MYSQL_RES* rezultat;
  konekcija = mysql_init(NULL);
  if (mysql_real_connect(konekcija, "localhost", "root", "root", "SVETSKO_PRVENSTVO", 0, NULL, 0) == NULL)
    error("mysql_real_connect failed");
  printf("Unesite zeljenu opciju\n");
  printf("1 - Dodaj novog igraca\n");
  printf("2 - Izbrisi postojeceg igraca\n");
  printf("3 - Kraj\n");
  int opcija;
  char query[MAX_QUERY_LEN];
  scanf("%d", &opcija);
  if (opcija == 1){
    printf("unesite ime, prezime, datum rodjenja i reprezentaciju za koju nastupa igrac\n");
    char ime[MAX_STRING_ATT_LEN];
    char prezime[MAX_STRING_ATT_LEN];
    char datum_rodjenja[MAX_STRING_ATT_LEN];
    char reprezentacija[MAX_STRING_ATT_LEN];
    scanf("%s%s%s%s", ime, prezime, datum_rodjenja, reprezentacija);
    sprintf(query, "select max(idIgraca) from Igrac");
    rezultat = executeQuery(konekcija, query);
    red = mysql_fetch_row(rezultat);
    char* tmp = malloc(MAX_QUERY_LEN);
    tmp = red[0];
    int max_id = atoi(tmp) + 1;
    mysql_free_result (rezultat);
    sprintf(query, "select id from Drzava where naziv = \"%s\"", reprezentacija);
    rezultat = executeQuery(konekcija, query);
    red = mysql_fetch_row(rezultat);
    tmp = red[0];
    int id_drzave = atoi(tmp);
    mysql_free_result (rezultat);
    sprintf(query, "insert into Igrac values(%d, \"%s\", \"%s\", DATE \"%s\", \"%s\", %d)", max_id, ime, prezime, datum_rodjenja, reprezentacija, id_drzave);
    printf("%s\n", query);
    rezultat = executeQuery(konekcija, query);
    printf("Uspesno ste dodali igraca");
  }
  else if (opcija == 2){
    printf("Unesite ime i prezime igraca kog zelite da obrisete\n");
    char ime[MAX_STRING_ATT_LEN];
    char prezime[MAX_STRING_ATT_LEN];
    scanf("%s%s", ime, prezime);
    sprintf(query, "delete from Igrac where ime = \"%s\" and prezime = \"%s\" ", ime, prezime);
    rezultat = executeQuery(konekcija, query);
    printf("Uspesno ste obrisali igraca\n");
  }
  else if (opcija == 3)
    exit(EXIT_SUCCESS);
  else 
    error("invalid option");
  return 1;
}


void error( char* s){
  perror(s);
  exit(EXIT_FAILURE);
}
 
 
MYSQL_RES* executeQuery(MYSQL* konekcija,char* query){
  if (mysql_query(konekcija, query) != 0)
    error("invalid query");
  MYSQL_RES* rezultat = mysql_use_result(konekcija);
  return rezultat;
}
 