//need to add bubble sort


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
#include <time.h>//To make random number wo
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


main(){
	int a =0,b=0;
	char wordSearch[R][C] ={"\0"};
	char keyword[KEY][KEYLEN] ={"\0"};
	srand(time(NULL));
	system("mode CON: COLS=102");
	
	getWords(keyword);
	fits(wordSearch, keyword);
	cls;
	fillInTheBlank(wordSearch);
	displayGame(wordSearch);
	displayWords(keyword);

	pause;
}

void getWords(char keyword[][KEYLEN]){
	int i = 0;
	for(i=0; i<KEY; i++){
		printf("Enter the %i word of 14: ", i+1);
		scanf("%s", keyword[i]);
		while(strlen(keyword[i])>8){
			printf("ERROR: Word must be 8 letters or less\n!!!ReEnter the %i word of 14: ", i+1);
			flush;
			scanf("%s", keyword[i]);
		}
	}
	pause;
	cls;
}//end of getWords

void fits(char wordSearch[][C],char keyword[][KEYLEN]){
	int a =0,b=0;
	int count = 0;
	int col=0;
	int row=0;
	int direct =0;
	int length = 0;
	char *temp[8] ={'\0'};

	for(count= 0; count<KEY; count++)
	{
		length = strlen(keyword[count]);
		*temp = keyword[count];
		col= (rand() % (49 + 1 - 0)) + 0;//for COLUMNS 0-49
		row= (rand() % (24 + 1 - 0)) + 0;//for Rows 0-24
		direct = (rand() % (8 + 1 - 1)) + 1;//for directions 1-8
//		printf("Direction: %i\n",direct);

		switch(direct){
		case 1://right
			rightFit(col, row, length, wordSearch,*temp);
			break;
		case 2:
			leftFit(col, row, length, wordSearch,*temp);
			break;
		case 3:
			downFit(col, row, length, wordSearch,*temp);
			break;
		case 4: 
			upFit(col, row, length, wordSearch,*temp);
			break;
		case 5:
			RdownFit(col, row, length, wordSearch,*temp);
			break;
		case 6:
			LdownFit(col, row, length, wordSearch,*temp);
			break;
		case 7:
			RupFit(col, row, length, wordSearch,*temp);
			break;
		case 8:
			LupFit(col, row, length, wordSearch,*temp);
			break;
		}// end of switch
//		printf("\n");
//		printf("Keyword used %s\n", keyword[count]);
//		printf("\n");

		//DISPLAY ANSWERS
	if (count == (KEY-1)){  //if all word has been added to the puzzle
		for(a=0; a<R;a++){  //display the current puzzle (keywords only)
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
	while ((col + length) >C){
		col= rand() % (50 + 0);//for COLUMNS 0-49
	}
//	printf("right\n"); n
//	pause;
	for(t = 0; t<length;t++){
		test = temp[t];
		test = toupper(test);
		temp[t] = test;

		while(temp[t] != wordSearch[row][col] && wordSearch[row][col] != '\0'){
			t = 0;
			col= rand() % (50 + 0);//for COLUMNS 0-49
			while ((col + length) >C){
				col= rand() % (50 + 0);//for COLUMNS 0-49
			}
//			printf("%c %c %i %i\n", temp[i], wordSearch[row][col], row, col);
//			pause;
		}
		col++;
	}
	col = col - length;
	for(i=0; i<length;i++){
		wordSearch[row][col] = temp[i];
		col++;
	}
}

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
