#include<stdio.h>
#include<stdlib.h>
#include<string.h>



static int const TRUE = 1;
static int const FALSE = 0;
static int const ERROR = -1;

//macrosss
#define EXIT_SUCCES TRUE
#define EXIT_FAILED ERROR

typedef struct {
	int hh;
	int mm;
}recOra;

typedef struct{
	int anno;
	int mese;
	int giorno;
}recData;

typedef struct {
	//data
	recData data;
	recOra ora;
	//destinatario
	char nome_destinatario[100];
	//mittente
	char nome_mittente[100];
	//message
	char message[1000];
}recMESSAGE;

int setOra(int, int, recMESSAGE*);
int setData(int, int, int, recMESSAGE*);
int setMittente(char [], recMESSAGE*);
int setDestinatario(char [], recMESSAGE*);
int setMessagio(char [], recMESSAGE*);

void OutPut(recMESSAGE*);

void errorExit();

void clearScreen();

void clearBuffer();

	/*! \fn main
	    \brief costructor
	    \param void
	*/
int main (void){
		

	recMESSAGE message1;

	//ORA
	int hh;
	int mm;	

	//DATA
	int anno;
	int mese;
	int giorno;

	//strings
	char mit[100];
	char des[100];
	char message[1000];

	//other
	char error;

	int boolean;

	//linker
	recMESSAGE *pn = &message1;	

	clearScreen(); 

	//INSERT DATA VALUES
	printf("\r\n Inserisci la data(anno) >>> \t ");
	scanf("%i",&anno);
	clearScreen();
	printf("\r\n Inserisci la data(mese) >>> \t");
	scanf("%i",&mese);
	clearScreen();
	printf("\r\n Inserisci la data(giorno) >>> \t");
	scanf("%i",&giorno);
	clearScreen();

	//SET DATA
	boolean = setData(anno, mese, giorno, pn);

	if (boolean==TRUE) printf("Data e' stata inserita correttamente \r\n");
	else errorExit();

	//clearing BOOLEAN
	boolean = FALSE;
	
	//INSERT TIME VALUES
	printf("Inserisci l'ora(ora) >>> \t");
	scanf("%i",&hh);
	clearScreen();
	printf("\r\n Inserisci l'ora(minuti) >>> ");
	scanf("%i",&mm);
	clearScreen();
	clearBuffer();
	
	

	//SET ORA
	boolean = setOra(hh, mm, pn);
	if (boolean==TRUE) printf("L'ora e' stata inserita correttamente \r\n");
	else errorExit();

	clearScreen();


	//SET MITTENTE
	printf("\r\n Inserisci il nome del Mittente >>> ");
	fgets(mit,100,stdin);

	boolean = setMittente(mit, pn);
	if (boolean==TRUE) printf("Il mittente e' stato inserito correttamente \r\n");
	else errorExit();

	//clearing BOOLEAN
	boolean = FALSE;
	
	
	clearScreen();
	clearBuffer();

	//SET DESTINATARIO
	printf("\r\n Inserisci il nome del Destinatario >>> ");
	fgets(des,100,stdin);
	
	boolean= setDestinatario(des, pn);
	if (boolean==TRUE) printf("Il destinatario e' stato inserito correttamente \r\n");
	else errorExit();	
	
	clearScreen();
	clearBuffer();
	clearScreen();

	//clearing BOOLEAN
	boolean = FALSE;
	
	//SET MESSAGIO
	
	printf("Inserisci il messagio\r\n");
	fgets(message,100,stdin);

	clearBuffer();

	boolean= setMessagio(message, pn);
	if (boolean==TRUE) printf("Il destinatario e' stato inserito correttamente \r\n");
	else errorExit();	
	
	//SHOW VALUES
		
	OutPut(pn);
	
	//SUCCES EXIT
	return 0;
}


	/*! \fn setData
	    \brief set using*pn 
	    \param anno:int
	    \param mese:int
	    \param giorno:int
	    \param *pn:recMESSAGE
	*/
int setData(int anno, int mese, int giorno, recMESSAGE *pn ){
	
	int anwser = 0;
	
	if((mese<12) && (mese>1)) (*pn).data.mese = mese;
	else return anwser;

	if((giorno<32) && (giorno>1))(*pn).data.giorno = giorno;
	else return anwser;
	
	(*pn).data.anno = anno;
	
	return (anwser=1);
}

	/*! \fn setOra
	    \brief set using *pn 
	    \brief boolean return and setting
	    \param hh:int
	    \param mm:int
	    \param *pn:recMESSAGE
	*/
int setOra(int hh, int mm, recMESSAGE *pn){
	
	int anwser = 0;
	
	if((hh<=24) && (hh>=1)) (*pn).ora.hh = hh;
	else return anwser;

	if((mm<=59) && (mm>=0)) (*pn).ora.mm = mm;
	else return anwser;

	return (anwser = 1);
}

	/*! \fn setMittente
	    \brief boolean return and setting
	    \param mit[]:char
	    \param *pn:recMESSAGE
	*/
int setMittente(char mit[], recMESSAGE *pn){
	if(strcpy((*pn).nome_mittente, mit)) return TRUE;
	else return FALSE;
}

	/*! \fn setDestinatario
	    \brief boolean return
	    \param hh:int
	    \param mm:int
	    \param *pn:recMESSAGE
	*/
int setDestinatario(char des[], recMESSAGE *pn){
	if(strcpy((*pn).nome_destinatario, des)) return TRUE;
	else return FALSE;
	
}
	  
	/*! \fn setMessagio

	    \param message[]:char
	    \param *pn:recMESSAGE
	*/
int setMessagio(char message[], recMESSAGE *pn){
	if(strcpy((*pn).message, message)) return TRUE;
	else return FALSE;
}


	/*! \fn OutPut
	    \brief out put message
	    \param *pn:recMESSAGE
	*/
void OutPut(recMESSAGE *pn){
		clearScreen();
		printf("-----------------------------------------\r\nLa data e' %i/%i/%i \r\nl'ora e' %i:%i \r\nNome mittente: %s\r\nNome destinatario : %s\r\nMessagio: %s\r\n-----------------------------------------\r\n",(*pn).data.anno, (*pn).data.mese, (*pn).data.giorno, (*pn).ora.hh, (*pn).ora.mm, (*pn).nome_mittente, (*pn).nome_destinatario, (*pn).message);
}

	/*! \fn errorExit
	    \brief control exiting with message
	    \param void
	*/
void errorExit(){
	perror("Programma verra sospeso \r\n");
	exit(EXIT_SUCCES);
}

	/*! \fn clearScreen
	    \brief clearing screen using system
	    \param void
	*/
void clearScreen(){
	system("clear");
}

	/*! \fn clearBuffer
	    \brief clearing buffer
	    \param void
	*/
void clearBuffer(){
	printf("Enter to continue\r\n");
	char error = getchar();
	fflush(stdin);	
}







