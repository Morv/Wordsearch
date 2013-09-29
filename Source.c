/***********************************************************************
************************************************************************
Team 1: Shin,Morvan,Totaram, Abbz, Ian
Date: 09/29/2013
Purpose: Exam2
	create a wordsearch from 14 words inputted by the user
	words are put in the puzzle randomly in 8 directions
	the puzzle is saved to a file for printing.

************************************************************************
************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
#include <time.h>
#define pause system ("pause")
#define cls system ("cls")
#define flush fflush(stdin)
#define C 50
#define R 25
#define KEY 14
#define KEYLEN 9

void getWords(char keyword[][KEYLEN]);
void fits(char wordSearch[][C],char keyword[][KEYLEN]);
void rightFit(int col, int row, int length, char wordSearch[][C],char *temp);
void leftFit(int col, int row, int length, char wordSearch[][C],char *temp);
void downFit(int col, int row, int length, char wordSearch[][C],char *temp);
void upFit(int col, int row, int length, char wordSearch[][C],char *temp);
void rDownFit(int col, int row, int length, char wordSearch[][C],char *temp);
void lDownFit(int col, int row, int length, char wordSearch[][C],char *temp);
void rUpFit(int col, int row, int length, char wordSearch[][C],char *temp);
void lUpFit(int col, int row, int length, char wordSearch[][C],char *temp);
void displayGame(char wordSearch[][C]);
void fillInTheBlank(char wordSearch[][C]);
char randomLetter();
void displayWords(char keyword[][KEYLEN]);
void sortAToZ(char keyword[][KEYLEN]);
void saveGame(char wordSearch[][C], char keyword[][KEYLEN]);
void displayIntro ();
void capitalize(char keyword[][KEYLEN]);

main(){
	int a =0,b=0;
	char wordSearch[R][C] ={"\0"};
	char keyword[KEY][KEYLEN] ={"\0"};

	srand(time(NULL));
	system("mode CON: COLS=102");
	
	displayIntro ();
	getWords(keyword);
	fits(wordSearch, keyword);
	capitalize(keyword);
	cls;
	fillInTheBlank(wordSearch);
	sortAToZ(keyword);
	displayGame(wordSearch);
	displayWords(keyword);					
	saveGame(wordSearch, keyword);
	pause;
}
void displayIntro (){//menu for looks

	printf("-||||||||||-||||||||||||||||||||||||||||||||||-||||||||||-\n");//feel free to change menu text
	printf("|-||||||||-||||||||||||||||||||||||||||||||||||-||||||||-|\n");
	printf("||-||||||-                                      -||||||-||\n");
	printf("|||-||||-|    Random Crossword Generator        |-||||-|||\n");
	printf("||||-||-||           Created by:                ||-||-||||\n");
	printf("|||||--|||               ABBZ                   |||--|||||\n");
	printf("|||||--|||               IAN                    |||--|||||\n");
	printf("||||-||-||              MORVAN                  ||-||-||||\n");
	printf("|||-||||-|               SHIN                   |-||||-|||\n");
	printf("||-||||||-              TOTARAM                 -||||||-||\n");
	printf("|-||||||||-||||||||||||||||||||||||||||||||||||-||||||||-|\n");
	printf("-||||||||||-||||||||||||||||||||||||||||||||||-||||||||||-\n\n");

	printf("Please input your words to begin:\n");

}// end of displayMenu
void getWords(char keyword[][KEYLEN]){
	int i = 0;

	for(i=0; i<KEY; i++){
		printf("Enter word %i of 14: ", i+1);
		scanf("%s", keyword[i]);
		while(strlen(keyword[i])>8){
			printf("ERROR: Word must be 8 letters or less\n!!!Re-Enter word %i of 14: ", i+1);
			flush;
			scanf("%s", keyword[i]);
		}//end of while
	}//end of for
	pause;
	cls;
}//end of getWords
void fits(char wordSearch[][C],char keyword[][KEYLEN]){
	int a =0,b=0, count = 0, col=0, row=0, direct =0, length = 0;
	char *temp[8] ={'\0'}; //temporary storage for keywords.

	for(count= 0; count<KEY; count++)
	{
		length = strlen(keyword[count]);
		*temp = keyword[count]; 
		col = rand() % 50 + 0;//for Columns 0-49
		row = rand() % 25 + 0;//for Rows 0-24
		direct = rand() % 8 + 1;//for directions 1-8

		switch(direct){

		case 1://right
			rightFit(col, row, length, wordSearch,*temp);
			break;
		case 2://left
			leftFit(col, row, length, wordSearch,*temp);
			break;
		case 3://down
			downFit(col, row, length, wordSearch,*temp);
			break;
		case 4://up
			upFit(col, row, length, wordSearch,*temp);
			break;
		case 5://right down
			rDownFit(col, row, length, wordSearch,*temp);
			break;
		case 6://left down
			lDownFit(col, row, length, wordSearch,*temp);
			break;
		case 7://right up
			rUpFit(col, row, length, wordSearch,*temp);
			break;
		case 8://left up
			lUpFit(col, row, length, wordSearch,*temp);
			break;
		}// end of switch

		//DISPLAY ANSWERS
	if (count == (KEY-1)){  //if all word has been added to the puzzle
		for(a=0; a<R;a++){  //display the current puzzle array
			for(b=0;b<C;b++){
				printf("%c", wordSearch[a][b]);
			}//end of for
		printf("\n");
		}//end of for
	pause;		
	}//end of if
	}// end of big for loop

}//end of fits
void rightFit(int col, int row, int length, char wordSearch[][C],char *temp){
	
	int i =0;
	char test = ' ';
	int t= 0;
	//WILL THE WORD FIT IN THE ARRAY?
	while ((col + length) > C){   //while the column + length of word is out of bounds
		col= rand() % (50 + 0);//get a new random column
	}//end while

	//WILL LETTERS ONLY OVERWRITE THEMSELVES OR NULL SPACES
	for(t = 0; t<length;t++){ //go through each letter of the word and...
		temp[t] = toupper(temp[t]);		//...make uppercase

		while(temp[t] != wordSearch[row][col] && wordSearch[row][col] != '\0'){ //if wordsearch =! letter and wordsearch isnt blank.... get a new location
			t = 0;//reset the letter back to the first...
			col= rand() % (50 + 0);//new column
			while ((col + length) >C){  //while the column+array is out of bounds
				col= rand() % (50 + 0);  // get a new column
			}//end inner while
		}//end while
		col++;//go to next letter
	}//end of for ( going through each letter of the word.)
	
	col = col - length; //go back to the initial location of col

	//PUT THE WORD IN THE ARRAY
	for(i=0; i<length;i++){
		wordSearch[row][col] = temp[i];
		col++;
	}
} //end of rightFit
void leftFit(int col, int row, int length, char wordSearch[][C],char *temp){
	int i =0;
	char test = ' ';
	int t= 0;
	while ((col-length)<0){
		col= rand() % (50 + 0);//for COLUMNS 0-49
	}//end while

	for(t = 0; t<length;t++){
		test = temp[t];
		test = toupper(test);
		temp[t] = test;
		while(temp[t] != wordSearch[row][col] && wordSearch[row][col] != '\0'){
			t = 0;
			col= rand() % (50 + 0);//for COLUMNS 0-49
			while ((col-length)<0){
				col= rand() % (50 + 0);//for COLUMNS 0-49
			}//end while

		}//end while
		col--;
	}//end for
	col = col + length;
	for(i=0; i<length;i++){
		wordSearch[row][col] = temp[i];
		col--;
	}//end for

}//end leftFit
void downFit(int col, int row, int length, char wordSearch[][C],char *temp){
	int i =0;
	char test = ' ';
	int t= 0;
	while ((row + length)>R){
		row=  rand() % (25 + 0);//for Rows 0-24
	}//end while

	for(t = 0; t<length;t++){
		test = temp[t];
		test = toupper(test);
		temp[t] = test;
		while(temp[t] != wordSearch[row][col] && wordSearch[row][col] != '\0'){
			t = 0;
			row=  rand() % (25 + 0);//for Rows 0-24
			while ((row + length)>R){
				row=  rand() % (25 + 0);//for Rows 0-24
			}//end while

		}//end while
		row++;
	}//end for
	row = row - length;
	for(i=0; i<length;i++){
		wordSearch[row][col] = temp[i];
		row++;
	}//end for

}//end downFit
void upFit(int col, int row, int length, char wordSearch[][C],char *temp){
	int i =0;
	char test = ' ';
	int t= 0;
	while ((row-length)<0){
		row=  rand() % (25 + 0);//for Rows 0-24
	}//end while

	for(t = 0; t<length;t++){
		test = temp[t];
		test = toupper(test);
		temp[t] = test;
		while(temp[t] != wordSearch[row][col] && wordSearch[row][col] != '\0'){
			t = 0;
			row=  rand() % (25 + 0);//for Rows 0-24
			while ((row-length)<0){
				row=  rand() % (25 + 0);//for Rows 0-24
			}//end while
		}//end while
		row--;
	}//end for
	row = row + length;
	for(i=0; i<length;i++){
		wordSearch[row][col] = temp[i];
		row--;
	}//end for
}//end upFit
void rDownFit(int col, int row, int length, char wordSearch[][C],char *temp){
	int i =0;
	char test = ' ';
	int t= 0;

	while ((col + length) >C){
		col= rand() % (50 + 0);//for COLUMNS 0-49
	}//end while
	while ((row + length)>R){
		row=  rand() % (25 + 0);//for Rows 0-24
	}//end while

	for(t = 0; t<length;t++){
		test = temp[t];
		test = toupper(test);
		temp[t] = test;
		while(temp[t] != wordSearch[row][col] && wordSearch[row][col] != '\0'){
			t = 0;
			col= rand() % (50 + 0);//for COLUMNS 0-49
			row=  rand() % (25 + 0);//for Rows 0-24
			while ((col + length) >C){
				col= rand() % (50 + 0);//for COLUMNS 0-49
			}//end for
			while ((row + length)>R){
				row=  rand() % (25 + 0);//for Rows 0-24
			}//end while
		}//end while
		col++;
		row++;
	}//end for
	col = col - length;
	row = row -length;
	for(i=0; i<length;i++){
		wordSearch[row][col] = temp[i];
		col++;
		row++;
	}//end for
}//end rDownFit
void lDownFit(int col, int row, int length, char wordSearch[][C],char *temp){
	int i =0;
	char test = ' ';
	int t= 0;

	while ((col-length)<0){
		col= rand() % (50 + 0);//for COLUMNS 0-49
	}//end while
	while ((row + length)>R){
		row=  rand() % (25 + 0);//for Rows 0-24
	}//end while

	for(t = 0; t<length;t++){
		test = temp[t];
		test = toupper(test);
		temp[t] = test;
		while(temp[t] != wordSearch[row][col] && wordSearch[row][col] != '\0'){
			t = 0;
			col= rand() % (50 + 0);//for COLUMNS 0-49
			row=  rand() % (25 + 0);//for Rows 0-24
			while ((col-length)<0){
				col= rand() % (50 + 0);//for COLUMNS 0-49
			}//end while
			while ((row + length)>R){
				row=  rand() % (25 + 0);//for Rows 0-24
			}//end while

		}//end while
		col--;
		row++;
	}//end for
	col = col + length;
	row = row -length;
	for(i=0; i<length;i++){
		wordSearch[row][col] = temp[i];
		col--;
		row++;
	}//end for
}//end lDownFit
void rUpFit(int col, int row, int length, char wordSearch[][C],char *temp){
	int i =0;
	char test = ' ';
	int t= 0;

	while ((col + length) >C){
		col= rand() % (50 + 0);//for COLUMNS 0-49
	}//end while
	while ((row-length)<0){
		row=  rand() % (25 + 0);//for Rows 0-24
	}//end while

	for(t = 0; t<length;t++){
		test = temp[t];
		test = toupper(test);
		temp[t] = test;
		while(temp[t] != wordSearch[row][col] && wordSearch[row][col] != '\0'){
			t = 0;
			col= rand() % (50 + 0);//for COLUMNS 0-49
			row=  rand() % (25 + 0);//for Rows 0-24
			while ((col + length) >C){
				col= rand() % (50 + 0);//for COLUMNS 0-49
			}//end while
			while ((row-length)<0){
				row=  rand() % (25 + 0);//for Rows 0-24
			}//end while

		}//end while
		col++;
		row--;
	}//end for
	col = col-length;
	row = row + length;
	for(i=0; i<length;i++){
		wordSearch[row][col] = temp[i];
		col++;
		row--;
	}//end for
}//end rUpFit
void lUpFit(int col, int row, int length, char wordSearch[][C],char *temp){
	int i =0;
	char test = ' ';
	int t= 0;

	while ((col-length)<0){
		col= rand() % (50 + 0);//for COLUMNS 0-49
	}//end while
	while ((row-length)<0){
		row=  rand() % (25 + 0);//for Rows 0-24
	}//end while

	for(t = 0; t<length;t++){
		test = temp[t];
		test = toupper(test);
		temp[t] = test;
		while(temp[t] != wordSearch[row][col] && wordSearch[row][col] != '\0'){
			t = 0;
			col= rand() % (50 + 0);//for COLUMNS 0-49
			row=  rand() % (25 + 0);//for Rows 0-24
			while ((col-length)<0){
				col= rand() % (50 + 0);//for COLUMNS 0-49
			}//end while
			while ((row-length)<0){
				row=  rand() % (25 + 0);//for Rows 0-24
			}//end while
		}//end while
		col--;
		row--;
	}//end for
	col= col+length;
	row =row+length;
	for(i=0; i<length;i++){
		wordSearch[row][col] = temp[i];
		col--;
		row--;
	}//end for
}//end lUpFit
void displayGame(char wordSearch[][C])
{
	int i = 0, j = 0;

	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			printf("%2c", wordSearch[i][j]);
		}//end for (cols)

		printf("\n\n"); //adds new line before the next row.	

	}//end for (rows)
}//end displayGame
void fillInTheBlank(char wordSearch[][C])
{
	int i = 0, j = 0;

	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			if (wordSearch[i][j] == '\0') //if the cell is null
			{
				wordSearch[i][j] = randomLetter(); //put a random capital letter in it
			}
		}//end for (cols)
	}//end for (rows)

}//end fill in the blank
char randomLetter()
{
  char randomLetter = ' ';

	randomLetter = (rand() % (90 + 1 - 65)) + 65;//generates random ascii number for letters A-Z
	 
	return randomLetter;
}//end of random letter
void displayWords(char keyword[][KEYLEN])
{
	int i=0, j=0;

      	for (i=0; i < (KEY/2); i++)
	{
		printf("%i.%s \t", i+1, keyword[i]);
			if ( (strlen(keyword[i])) < 5){ //if the word is 4 letters or less, 
				printf("\t");				//then add an extra tab to line up numbers
			}//end if
		printf("%i.%s\n", i+8, keyword[7+i]);
	}//end for loop

}//displays keywords in 2 columns
void sortAToZ(char keyword[][KEYLEN])
{
	char temp[KEYLEN] = {'\0'};
	int i=0, j=0;
	//BUBBLE SORT
	for(i = 0; i < KEY; i++){
		for(j = 0; j < KEY-1; j++){
			if(strcmp(keyword[j], keyword[j+1]) > 0){  //compare the 2 arrays
				//swap the two array elements
				strcpy(temp, keyword[j]);
				strcpy(keyword[j], keyword[j+1]);
				strcpy(keyword[j+1], temp);
			}
		}
	}
}//end of sort array
void saveGame(char wordSearch[][C], char keyword[][KEYLEN])
{
	int i=0, j=0;

	FILE *pWordPuzzleFile;
		pWordPuzzleFile = fopen("wordsearch.txt", "w");
	
	//ADD WORDSEARCH ARRAY TO THE FILE
	for (i=0; i<R; i++){
		for (j=0; j<C; j++){
			fprintf(pWordPuzzleFile, "%2c", wordSearch[i][j]);

		}//end inside for
		fprintf(pWordPuzzleFile, "\n");

	}//end big for
	fprintf(pWordPuzzleFile, "\n\n\n");

	//ADD KEYWORDS ARRAY TO THE FILE
	 for (i=0; i < (KEY/2); i++){
		fprintf(pWordPuzzleFile, "%i.%s \t", i+1, keyword[i]);
			if ( (strlen(keyword[i])) < 5){ //if the word is 4 letters or less, 
				fprintf(pWordPuzzleFile, "\t");	//then add an extra tab to line up numbers

			}//end if
		fprintf(pWordPuzzleFile, "%i.%s\n", i+8, keyword[7+i]);

	}//end for loop

	 fclose(pWordPuzzleFile);//close file
	 printf("\n\nWordsearch saved to file.\n");
}//end save game to file
void capitalize (char keyword[][KEYLEN])
{
	int i=0, j=0;

	for (i = 0; i < KEY; i++)
	{
		keyword[i][j] = toupper(keyword[i][j]);

		for (j = 1; j < KEYLEN-1; j++)
		{
		 keyword[i][j] = tolower(keyword[i][j]);
		}//end for 

	}//end for

}//end capitalize
