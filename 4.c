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
    
    char query[MAX_QUERY_LEN];
    
    printf("Unesite nazive reprezentacija koje su odigrale utakmice, broj poena domacina, broj poena gosta , ime i prezime sudije kao kao i datum odigravanja utakmice\n");
    
    char nazivDom[MAX_STRING_ATT_LEN];
    char nazivGost[MAX_STRING_ATT_LEN];
    int brojPoenaDomacin;
    int brojPoenaGost;
    char ime[MAX_STRING_ATT_LEN];
    char prezime[MAX_STRING_ATT_LEN];
    char datum[MAX_STRING_ATT_LEN];
    scanf("%s%s%d%d%s%s%s", nazivDom, nazivGost, &brojPoenaDomacin, &brojPoenaGost, ime, prezime, datum);
    int ishod;
    if (brojPoenaDomacin > brojPoenaGost)
        ishod = 1;
    else
        ishod = 2;
    
    sprintf(query, "select id from Drzava where naziv = \"%s\"", nazivDom);
    rezultat = executeQuery(konekcija, query);
    red = mysql_fetch_row(rezultat);
    int idDomacin = atoi(red[0]);
    mysql_free_result(rezultat);
    
    sprintf(query, "select id from Drzava where naziv = \"%s\"", nazivGost);
    rezultat = executeQuery(konekcija, query);
    red = mysql_fetch_row(rezultat);
    int idGost = atoi(red[0]);
    mysql_free_result(rezultat);
    
    sprintf(query, "select idSudije from Sudija where ime = \"%s\" and prezime = \"%s\"", ime, prezime);
    rezultat = executeQuery(konekcija, query);
  
    red = mysql_fetch_row(rezultat);
    int idSudija= atoi(red[0]);
    mysql_free_result(rezultat);
    
    sprintf(query, "select max(id) from Utakmica");
    rezultat = executeQuery(konekcija, query);
    int idUtakmice;
    red = mysql_fetch_row(rezultat);
    if (red == NULL)
	idUtakmice = 1;
    else 
      idUtakmice = atoi(red[0]) + 1;
    mysql_free_result(rezultat);
    
    sprintf(query, "insert into Utakmica(id, ishod, poeniDomacin, poeniGost, datum, idSudije, domacin, gost) values(%d, %d, %d, %d, DATE \"%s\", %d, %d, %d)", idUtakmice,ishod, brojPoenaDomacin, brojPoenaGost, datum, idSudija, idDomacin, idGost);
   // printf("%s\n", query);
    executeQuery(konekcija, query);
    
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
