#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>//for random number
#define pause system ("pause")
#define cls system ("cls")
#define flush fflush(stdin)
#define COL 50
#define ROW 25
#define KEYWORDS 14
#define MAXLENGTH 9


/*////////////////////////////////////////////

getWords  scanf()
 
 *////////////////////////////////////////////

//void displayGame(int *Colums,char keywords[14][9]);
//void fits(int *Colums,int *Row,int *Direction, int length);
void getWords(char keywords[KEYWORDS][MAXLENGTH]);
int fitsRight(int Col, int Row);
void displayGame(char a[][COL]);

void generateAnswers(char words[][MAXLENGTH], char puzzle[][COL]);
void displayWords(char keywords[KEYWORDS][MAXLENGTH]);
main(){
	int column=0, row=0, direction=0, counter=0, i = 0;
	char wordSearch[ROW][COL]={'\0'}, keywords[KEYWORDS][MAXLENGTH]={'\0'};

	getWords(keywords);
	generateAnswers(keywords, wordSearch);
	//fillInTheBlanks(keywords[KEYWORDS]);
	displayGame(wordSearch);
	displayWords(keywords);
	

	pause;


}//End of main


/*
void display(int *Colums,char keywords[KEYWORDS][MAXLENGTH]){
	int i=0, j=0;

	for(i=0;i<ROWS;i++)
	{
		for(j=0;j<*Colums;j++)
		{
			printf("%c",keywords[i][j]);
		}
	
	}

	pause;

}//End of display
*/
//add words to game board
void generateAnswers(char words[KEYWORDS][MAXLENGTH], char puzzle[ROW][COL]){
	int spotFound = 0, col = 0, row = 0, direction = 0, count = 0, i = 0, match = 0, matchInside = 0;
	
	while (i < KEYWORDS){
		matchInside=0, count = 0;
		col= rand() % (50 + 0);//for COLUMNS 0-49
		row=  rand() % (25 + 0);//for Rows 0-24
		direction=  rand() % (8 + 0);//for directions 0-7

		switch(2){ //change to switch(direction)

		case 1://right
			if ( (col+strlen(words[i])) < 50 ){
			
				for (count = 0; count < (strlen(words[i])); count++){

					if ( (words[0][0] == puzzle[row][col+count]) || (puzzle[row][col+count] == '\0')  ){

						puzzle[row][col+count] = words[i][count];
						matchInside++;
						printf("Placed a %c at %(%i,%i%)\n", puzzle[row][col+count], row, col+count);//TESTING~~~~~	
						
					}//end of if
					}//end of for 
				}//end of if 

			else {
						printf("\nmissed :(\n");
					}//end of else

			if (matchInside == strlen(words[i])){
					
						printf("%s added\n\n", words[i]);//TESTING~~~~~~~~~~~~~~~~~~
						i++;
					}//End of if 
					
				
				//add word to the right starting at [row][col] if there are blanks or matches
			
			break;
		case 2://left
			if ((col-strlen(words[i])) >= 0 ){


				for (count =(strlen(words[i])); count > 0; count--){

					if ( (words[i][count] == puzzle[row][col+count]) || (puzzle[row][col+count] == '\0')  ){

						puzzle[row][col+count] = words[i][count];
						matchInside++;
						printf("Placed a %c at %(%i,%i%)\n", puzzle[row][col+count], row, col+count);//TESTING~~~~~	
						
					}//end of if
					}//End of for
				}//End of if 
			else {
						printf("\nmissed :(\n");
					}//end of else

			if (matchInside == strlen(words[i])){
					
						printf("%s added\n\n", words[i]);//TESTING~~~~~~~~~~~~~~~~~~
						i++;
					}//End of if 
				

				//add word to the left starting at [row][col] if there are blanks or matches
			
			break;
		case 3://up
			if ((row-strlen(words[i])) >= 0 ){
			
				//add word upwards starting at [row][col] if there are blanks or matches
			};
			break;
		case 4://down
			if ((row+strlen(words[i])) < 25 )
			{
				//add word downwards starting at [row][col] if there are blanks or matches
			};
			break;
		case 5://up-right
			if (  ((row-strlen(words[i])) >= 0) && ((col+strlen(words[i])) < 50 ) )
			{
				//add word up and to the right starting at [row][col] if there are blanks or matches
			};
			break;
		case 6://up-left
			if (  ((row-strlen(words[i])) >= 0) && ((col-strlen(words[i])) >= 0 ) )
			{
				//add word up and to the left starting at [row][col] if there are blanks or matches
			};
			break;
		case 7://down-right
			if (  ((row+strlen(words[i])) < 25) && ((col+strlen(words[i])) < 50 ) )
			{
				//add word down and to the right starting at [row][col] if there are blanks or matches
			};
			break;
		case 8://down-left
			if (  ((row+strlen(words[i])) < 25) && ((col-strlen(words[i])) >= 0 ) )
			{
				//add word down and to the left starting at [row][col] if there are blanks or matches
			};
			break;
		default:
			printf("\nOops!\n");
			pause;
			break;
		}//end of fits
	}

}
//Create the array of words
void getWords(char keywords[KEYWORDS][MAXLENGTH]){
	int i=0;

	for (i=0; i < KEYWORDS; i++){

	printf_s("Enter a word %i of 14 :",i+1);
	scanf_s("%8s",keywords[i],KEYWORDS); //max of 8 characters are accepted.
	flush;						  //excess characters are removed from buffer.
	}
}//end of getWords
 
void displayGame(char puzzle[][COL]){

	int i = 0, j=0;

	for (i=0; i<ROW; i++){

		for (j=0; j<COL; j++)
		{
			printf("%c", puzzle[i][j]);
		}
		printf("\n");
	}


}

void displayWords(char keywords[KEYWORDS][MAXLENGTH])
{
	int i = 0, j=0;

	for (i=0; i<(KEYWORDS/2); i++){

	
			printf("%i:%8s \t\t%i:%8s ", i+1, keywords[i], i+8, keywords[i+7]);
			printf("\n");
	}

	pause;
}

