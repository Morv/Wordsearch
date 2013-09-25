#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>//To make random number wo
#define pause system ("pause")
#define cls system ("cls")
#define flush fflush(stdin)
#define COLUMNS 50
#define ROWS 25


void display(int *Colums,char keywords[14][9]);
void fits(int *Colums,int *Row,int *Direction, int length);
void getWords(char keywords[14][9], int a);
int fitsRight(int Col, int Row);

main(){
	int a = 0;
	int Colums=0;
	int Row=0;
	int Direction=0;
	int counter=0;
	int length, i = 0;
	char wordSearch[ROWS][COLUMNS]={'\0'};
	char keywords[14][9]={'\0'};



	do{
		getWords(keywords, a);
		length = strlen(keywords[i]);
		fits(&Colums,&Row,&Direction, length);
		display(&Colums,keywords);
		//putInTheWord();


		counter++;
		i++;
		a++;//counter for keyword
	}while(counter != 14);

	pause;
}//End of main



void display(int *Colums,char keywords[14][9]){
	int i;
	int j;
	//char array[ROWS][COLUMNS];

	for(i=0;i<ROWS;i++){

		for(j=0;j<*Colums;j++){
printf("%c",keywords[ROWS][*Colums]);
		}
	
	}

	pause;

}//End of display


void fits(int *Colums,int *Row,int *Direction,int length){
	int end = 0; //to get out of the loop 
	while (end == 0){
		end = 0;
		*Colums= rand() % (50 + 0);//for COLUMNS 0-49
		*Row=  rand() % (25 + 0);//for Rows 0-24
		*Direction=  rand() % (8 + 0);//for directions 0-7

		switch(1){
		case 1://right
			if ((fitsRight(*Colums,length)) == 0)
			{
				end = 1;
			};

			break;
		case 2://leftfg

			break;

		}//end of fits
	}

}



void getWords(char keywords[14][9], int i){
	int length =0;


	printf_s("Enter a word %i of 14 :",i+1);
	scanf_s("%s",keywords[i],8);
}//end of getWords

int fitsRight(int Col, int length){

	int i=0;

	if (Col + length <=25){
		printf("Worked");
		return 1;
	}//end of if 

	return 0;
}//end of right
/////////////////////////////////////////////////////////////////////////////////////////////////////////

