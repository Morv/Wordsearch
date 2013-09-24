#include<stdio.h>
#include<stdlib.h>
#include <time.h>//To make random number wo
#define pause system ("pause")
#define cls system ("cls")
#define flush fflush(stdin)
#define COLUMNS 50
#define ROWS 25


//void display(int *Colums,int *Row,int *Direction);
//int fits(int *Colums,int *Row,int *Direction);
void getWords(char keywords[14][9]);

main(){
	int Colums=0;
	int Row=0;
	int Direction=0;
	int counter=0;
	char wordSearch[ROWS][COLUMNS]={'\0'};
	char keywords[14][9]={'\0'};

	getWords(keywords);

	/*do{

	//display(&Colums,&Row,&Direction);

	fits(&Colums,&Row,&Direction);

	counter++;
	}while(counter != 14);

	*/
	pause;
}//End of main



/*void display(int *Colums){
int i;

char array[ROWS][COLUMNS];


printf_s("Enter charactor (0-6) :");
scanf_s("%s",array[0]);

for(i=0;i<=*Colums;i++){

if(i == *Colums)
printf_s("%s",array[0]);

else
printf_s("\n");
}

pause;

}//End of display
*/
/*int fits(int *Colums,int *Row,int *Direction){

int fits=0;

*Colums= rand() % (50 + 0);//for COLUMNS 0-24
*Row=  rand() % (25 + 0);//for Rows 0-490
*Direction=  rand() % (8 + 0);//for directions 0-7


if(*Direction ==1){

rihgt();
}


}//end of fits

*/

void getWords(char keywords[14][9]){
	int i;

	for(i=0;i<14;i++){
		printf_s("Enter a word %i of 14 :",i+1);
		scanf_s("%s",keywords[i]);
		printf_s("%s",keywords[i]);
		pause;
	}//end of for


}//end of getWords

