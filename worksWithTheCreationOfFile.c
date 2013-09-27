// Totaram.... The damn bubble sort was HELL!!!!!
// also I got the keywords from example (1. BASEBALL to print out as 1. Baseball)
// You can use this code as the code if you want, all this code needs is a bunch of comments
// if you want to use it just email me and tell me you want comments on it and i would put it in.


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
#include <time.h>//To make random number
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
void displayPuzzle(char wordSearch[][C],char keyword[][KEYLEN]);
FILE *wordPuzzleFile;



main(){
	int a =0,b=0;
	char wordSearch[R][C] ={"\0"};
	char keyword[KEY][KEYLEN] ={"\0"};
	srand(time(NULL));
	getWords(keyword);
	fits(wordSearch, keyword);



	printf("\n");
	for(a=0; a<R;a++){
		for(b=0;b<C;b++){
			printf("%c", wordSearch[a][b]);
		}
		printf("\n");
	}
	printf("\n\n\n");

	pause;
	
	displayPuzzle(wordSearch, keyword);

	pause;
}

void displayPuzzle(char wordSearch[][C],char keyword[][KEYLEN]){
	int a =0,b=0,i=0,t=0;
	int ALPHA = 0;
	char temp[9] ={"\0"};
	char alphabet[27] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};


	for(i= 0; i<KEY; i++){
		for(t=0;t<KEYLEN;t++){
			if(t != 0){
				keyword[i][t]= tolower(keyword[i][t]);
			}
		}
	}

	for(a = 0; a < KEY; a++){
		for(b = 0; b < KEY-1; b++){
			if(strcmp(keyword[b], keyword[b+1]) > 0){
				//swap the two array elements
				strcpy(temp, keyword[b]);
				strcpy(keyword[b], keyword[b+1]);
				strcpy(keyword[b+1], temp);
			}
		}
	}


	printf("\n");
	for(a=0; a<R;a++){
		for(b=0;b<C;b++){
			while(wordSearch[a][b]== '\0'){
				ALPHA = rand()% 25 + 0;
				wordSearch[a][b] = alphabet[ALPHA];
			}
			printf("%c", wordSearch[a][b]);
		}
		printf("\n");
	}
	printf("\n\n\n");


	for (i=0; i < (KEY/2); i++){
		printf("%i. %s \t", i+1, keyword[i]);
			if ( (strlen(keyword[i])) < 4){ //if the word is 3 letters or less, 
				printf("\t");				//then add an extra tab to line up numbers
			}//end if
		printf("\t%i. %s\n", i+8, keyword[7+i]);
	}//end for loop

	printf("\n");

	wordPuzzleFile = fopen("c:\\wordPuzzleFile.txt", "a+");
		fprintf(wordPuzzleFile,"\n");
	for(a=0; a<R;a++){
		for(b=0;b<C;b++){
			while(wordSearch[a][b]== '\0'){
				ALPHA = rand()% 25 + 0;
				wordSearch[a][b] = alphabet[ALPHA];
			}
			fprintf(wordPuzzleFile,"%c", wordSearch[a][b]);
		}
		fprintf(wordPuzzleFile,"\n");
	}
	fprintf(wordPuzzleFile,"\n\n\n");


	for (i=0; i < (KEY/2); i++){
		fprintf(wordPuzzleFile,"%i. %s \t", i+1, keyword[i]);
			if ( (strlen(keyword[i])) < 4){ //if the word is 3 letters or less, 
				fprintf(wordPuzzleFile,"\t");				//then add an extra tab to line up numbers
			}//end if
		fprintf(wordPuzzleFile,"\t%i. %s\n", i+8, keyword[7+i]);	
	}//end for loop

	fprintf(wordPuzzleFile,"\n");

	fclose(wordPuzzleFile);

}

void getWords(char keyword[][KEYLEN]){
	int i = 0;
	for(i=0; i<KEY; i++){
		printf("Enter the %i word of 14: ", i+1);
		scanf("%s", keyword[i]);
		if(strlen(keyword[i])>8){
			printf("Input invalid!!!ReEnter the %i word of 14: ", i+1);
			flush;
			scanf("%s", keyword[i]);
		}
	}
	pause;
	cls;
}//end of getWords

void fits(char wordSearch[][C],char keyword[][KEYLEN]){
	int count = 0;
	int col=0;
	int row=0;
	int direct =0;
	int length = 0;
	char *temp[9] ={"\0"};
	for(count= 0; count<KEY; count++){
		length = strlen(keyword[count]);
		*temp = keyword[count];
		col= rand() % (50 + 0);//for COLUMNS 0-49
		row=  rand() % (25 + 0);//for Rows 0-24
		direct =  rand() % 8 + 1;//for directions 1-8

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

	}// end of for loop

}//end of fits


void rightFit(int col, int row, int length, char wordSearch[][C],char *temp){
	char x = ' ';
	int i =0;
	char test = ' ';
	int t= 0;
	while ((col + length) >C){
		col= rand() % (50 + 0);//for COLUMNS 0-49
	}
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
	char x = ' ';
	int i =0;
	char test = ' ';
	int t= 0;
	while ((col-length)<0){
		col= rand() % (50 + 0);//for COLUMNS 0-49
	}
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
	char x = ' ';
	int i =0;
	char test = ' ';
	int t= 0;
	while ((row + length)>R){
		row=  rand() % (25 + 0);//for Rows 0-24
	}
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
	char x = ' ';
	int i =0;
	char test = ' ';
	int t= 0;
	while ((row-length)<0){
		row=  rand() % (25 + 0);//for Rows 0-24
	}

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
	char x = ' ';
	int i =0;
	char test = ' ';
	int t= 0;

	while ((col + length) >C){
		col= rand() % (50 + 0);//for COLUMNS 0-49
	}
	while ((row + length)>R){
		row=  rand() % (25 + 0);//for Rows 0-24
	}
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
	char x = ' ';
	int i =0;
	char test = ' ';
	int t= 0;
	while ((col-length)<0){
		col= rand() % (50 + 0);//for COLUMNS 0-49
	}
	while ((row + length)>R){
		row=  rand() % (25 + 0);//for Rows 0-24
	}
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
	char x = ' ';
	int i =0;
	char test = ' ';
	int t= 0;
	while ((col + length) >C){
		col= rand() % (50 + 0);//for COLUMNS 0-49
	}
	while ((row-length)<0){
		row=  rand() % (25 + 0);//for Rows 0-24
	}
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
	char x = ' ';
	int i =0;
	char test = ' ';
	int t= 0;
	while ((col-length)<0){
		col= rand() % (50 + 0);//for COLUMNS 0-49
	}
	while ((row-length)<0){
		row=  rand() % (25 + 0);//for Rows 0-24
	}

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
