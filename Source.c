#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
#include <time.h>//To make random numbers
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
void RdownFit(int col, int row, int length, char wordSearch[][C],char *temp);
void LdownFit(int col, int row, int length, char wordSearch[][C],char *temp);
void RupFit(int col, int row, int length, char wordSearch[][C],char *temp);
void LupFit(int col, int row, int length, char wordSearch[][C],char *temp);
void displayGame(char wordSearch[][C]);
void fillInTheBlank(char wordSearch[][C]);
char randomLetter();
void displayWords(char keyword[][KEYLEN]);
void sortAToZ(char keyword[][KEYLEN]);
void saveGame(char wordSearch[][C], char keyword[][KEYLEN]);
void displayMenu ();

main(){
	int a =0,b=0;
	char wordSearch[R][C] ={"\0"};
	char keyword[KEY][KEYLEN] ={"\0"};

	srand(time(NULL));
	system("mode CON: COLS=102");
	
	displayMenu ();
	getWords(keyword);
	fits(wordSearch, keyword);
	cls;
	fillInTheBlank(wordSearch);
	sortAToZ(keyword);
	displayGame(wordSearch);
	displayWords(keyword);					
	saveGame(wordSearch, keyword);
	pause;
}
void displayMenu (){//menu for looks

	printf("-||||||||||/||||||||||||||||||||||||||||||||||\||||||||||-\n");//feel free to change menu text
	printf("|-||||||||/||||||||||||||||||||||||||||||||||||\||||||||-|\n");
	printf("||-||||||/                                      \||||||-||\n");
	printf("|||-||||/|   Welcome to Random Word             |\||||-|||\n");
	printf("||||-||/||         Generator                    ||\||-||||\n");
	printf("|||||-/|||                                      |||\-|||||\n");
	printf("|||||/-|||                                      |||-\|||||\n");
	printf("||||/||-||     Best source for your crossword   ||-||\||||\n");
	printf("|||/||||-|        creation means                |-||||\|||\n");
	printf("||/||||||-                                v7.0  -||||||\||\n");
	printf("|/||||||||-||||||||||||||||||||||||||||||||||||-||||||||\|\n");
	printf("/||||||||||-||||||||||||||||||||||||||||||||||-||||||||||\\n\n");

	printf("Please input your words to be used:\n");

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
		}
	}

	pause;
	cls;
}//end of getWords
void fits(char wordSearch[][C],char keyword[][KEYLEN]){
	int a =0,b=0, count = 0, col=0, row=0, direct =0, length = 0;
	char *temp[8] ={'\0'};

	for(count= 0; count<KEY; count++)
	{
		length = strlen(keyword[count]);
		*temp = keyword[count];
		col = rand() % 50 + 0;//for COLUMNS 0-49
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
			RdownFit(col, row, length, wordSearch,*temp);
			break;
		case 6://left down
			LdownFit(col, row, length, wordSearch,*temp);
			break;
		case 7://right up
			RupFit(col, row, length, wordSearch,*temp);
			break;
		case 8://left up
			LupFit(col, row, length, wordSearch,*temp);
			break;
		}// end of switch

		//DISPLAY ANSWERS
	if (count == (KEY-1)){  //if all word has been added to the puzzle
		for(a=0; a<R;a++){  //display the current puzzle array
			for(b=0;b<C;b++){
				printf("%c", wordSearch[a][b]);
			}
		printf("\n");
		}
	pause;		
	}



	}// end of for loop

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
			while ((col + length) >C){  //while the column+array isnt out of bounds
				col= rand() % (50 + 0); //if it is, get a new column
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
	}
//	printf("left\n");
//	pause;
	for(t = 0; t<length;t++){
		test = temp[t];
		test = toupper(test);
		temp[t] = test;
		while(temp[t] != wordSearch[row][col] && wordSearch[row][col] != '\0'){
			t = 0;
			col= rand() % (50 + 0);//for COLUMNS 0-49
			while ((col-length)<0){
				col= rand() % (50 + 0);//for COLUMNS 0-49
			}
//			printf("%c %c %i %i\n", temp[i], wordSearch[row][col], row, col);
//			pause;
		}
		col--;
	}
	col = col + length;
	for(i=0; i<length;i++){
		wordSearch[row][col] = temp[i];
		col--;
	}

}
void downFit(int col, int row, int length, char wordSearch[][C],char *temp){
	int i =0;
	char test = ' ';
	int t= 0;
	while ((row + length)>R){
		row=  rand() % (25 + 0);//for Rows 0-24
	}
//	printf("down\n");
//	pause;
	for(t = 0; t<length;t++){
		test = temp[t];
		test = toupper(test);
		temp[t] = test;
		while(temp[t] != wordSearch[row][col] && wordSearch[row][col] != '\0'){
			t = 0;
			row=  rand() % (25 + 0);//for Rows 0-24
			while ((row + length)>R){
				row=  rand() % (25 + 0);//for Rows 0-24
			}
//			printf("%c %c %i %i\n", temp[i], wordSearch[row][col], row, col);
//			pause;
		}
		row++;
	}
	row = row - length;
	for(i=0; i<length;i++){
		wordSearch[row][col] = temp[i];
		row++;
	}

}
void upFit(int col, int row, int length, char wordSearch[][C],char *temp){
	int i =0;
	char test = ' ';
	int t= 0;
	while ((row-length)<0){
		row=  rand() % (25 + 0);//for Rows 0-24
	}
//	printf("up\n");
//	pause;
	for(t = 0; t<length;t++){
		test = temp[t];
		test = toupper(test);
		temp[t] = test;
		while(temp[t] != wordSearch[row][col] && wordSearch[row][col] != '\0'){
			t = 0;
			row=  rand() % (25 + 0);//for Rows 0-24
			while ((row-length)<0){
				row=  rand() % (25 + 0);//for Rows 0-24
			}
//				printf("%c %c %i %i\n", temp[i], wordSearch[row][col], row, col);
//			pause;
		}
		row--;
	}
	row = row + length;
	for(i=0; i<length;i++){
		wordSearch[row][col] = temp[i];
		row--;
	}
}
void RdownFit(int col, int row, int length, char wordSearch[][C],char *temp){
	int i =0;
	char test = ' ';
	int t= 0;
//	printf("%i, %i\n", length, (col+length));
//	printf("%i\n", (row+length));
//	pause;
	while ((col + length) >C){
		col= rand() % (50 + 0);//for COLUMNS 0-49
	}
	while ((row + length)>R){
		row=  rand() % (25 + 0);//for Rows 0-24
	}
//	printf("%i\n", (col+length));
//	printf("%i\n", (row+length));
//	printf("Right down\n");
//	pause;
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
			}
			while ((row + length)>R){
				row=  rand() % (25 + 0);//for Rows 0-24
			}
//			printf("%c %c %i %i\n", temp[i], wordSearch[row][col], row, col);
//			pause;
		}
		col++;
		row++;
	}
	col = col - length;
	row = row -length;
	for(i=0; i<length;i++){
		wordSearch[row][col] = temp[i];
		col++;
		row++;
	}


}
void LdownFit(int col, int row, int length, char wordSearch[][C],char *temp){
	int i =0;
	char test = ' ';
	int t= 0;
//	printf("%i, %i\n", length, (col-length));
//	printf("%i\n", (row+length));
//	pause;
	while ((col-length)<0){
		col= rand() % (50 + 0);//for COLUMNS 0-49
	}
	while ((row + length)>R){
		row=  rand() % (25 + 0);//for Rows 0-24
	}
//	printf("%i\n", (col-length));
//	printf("%i\n", (row+length));
//	printf("Left down\n");
//	pause;
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
			}
			while ((row + length)>R){
				row=  rand() % (25 + 0);//for Rows 0-24
			}
//			printf("%c %c %i %i\n", temp[i], wordSearch[row][col], row, col);
//			pause;
		}
		col--;
		row++;
	}
	col = col + length;
	row = row -length;
	for(i=0; i<length;i++){
		wordSearch[row][col] = temp[i];
		col--;
		row++;
	}


}
void RupFit(int col, int row, int length, char wordSearch[][C],char *temp){
	int i =0;
	char test = ' ';
	int t= 0;
//	printf("%i, %i\n", length, (col+length));
//	printf("%i\n", (row-length));
//	pause;
	while ((col + length) >C){
		col= rand() % (50 + 0);//for COLUMNS 0-49
	}
	while ((row-length)<0){
		row=  rand() % (25 + 0);//for Rows 0-24
	}
//	printf("%i\n", (col+length));
//	printf("%i\n", (row-length));
//	printf("Right up\n");
//	pause;
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
			}
			while ((row-length)<0){
				row=  rand() % (25 + 0);//for Rows 0-24
			}
//			printf("%c %c %i %i\n", temp[i], wordSearch[row][col], row, col);
//			pause;
		}
		col++;
		row--;
	}
	col = col-length;
	row = row + length;
	for(i=0; i<length;i++){
		wordSearch[row][col] = temp[i];
		col++;
		row--;
	}


}
void LupFit(int col, int row, int length, char wordSearch[][C],char *temp){
	int i =0;
	char test = ' ';
	int t= 0;
//	printf("%i, %i\n", length, (col-length));
//	printf("%i\n", (row-length));
//	pause;
	while ((col-length)<0){
		col= rand() % (50 + 0);//for COLUMNS 0-49
	}
	while ((row-length)<0){
		row=  rand() % (25 + 0);//for Rows 0-24
	}
//	printf("%i\n", (col-length));
//	printf("%i\n", (row-length));
//	printf("Left up\n");
//	pause;
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
			}
			while ((row-length)<0){
				row=  rand() % (25 + 0);//for Rows 0-24
			}
//			printf("%c %c %i %i\n", temp[i], wordSearch[row][col], row, col);
//			pause;
		}
		col--;
		row--;
	}
	col= col+length;
	row =row+length;
	for(i=0; i<length;i++){
		wordSearch[row][col] = temp[i];
		col--;
		row--;
	}
}
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

}//game is displayed on screen.
void fillInTheBlank(char wordSearch[][C])
{
	int i = 0, j = 0;

	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			if (wordSearch[i][j] == '\0')
			{
				wordSearch[i][j] = randomLetter();
			}
			//what happens to each cell
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
	int i=0;

      	for (i=0; i < (KEY/2); i++)
	{
		printf("%i.%s \t", i+1, keyword[i]);
			if ( (strlen(keyword[i])) < 5){ //if the word is 4 letters or less, 
				printf("\t");				//then add an extra tab to line up numbers
			}//end if
		printf("%i.%s\n", i+8, keyword[7+i]);
	}//end for loop

}//displays words in 2 columns
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
