//We just got to add comment and also fill up the grid to display,sort the words and display it to the screen.


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
#define KEYLEN 8


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
	printf("\n");

	pause;
}

void getWords(char keyword[][KEYLEN]){
	int i = 0;
	for(i=0; i<KEY; i++){
		printf("Enter the %i word of 14: ", i+1);
		scanf("%s", keyword[i]);
		while(strlen(keyword[i])>8){
			printf("Input invalid!!!ReEnter the %i word of 14: ", i+1);
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
	char *temp[8] ={" "};
	for(count= 0; count<KEY; count++){
		length = strlen(keyword[count]);
		*temp = keyword[count];
		col= rand() % (50 + 0);//for COLUMNS 0-49
		row=  rand() % (25 + 0);//for Rows 0-24
		direct =  rand() % 3 + 5;//for directions 1-8
		printf("%i\n",direct);

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
		printf("\n");
		printf("%s\n", keyword[count]);
		printf("\n");
	for(a=0; a<R;a++){
		for(b=0;b<C;b++){
			printf("%c", wordSearch[a][b]);
		}
		printf("\n");
	}
	printf("\n");

	pause;

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
	printf("right\n");
	pause;
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
			printf("%c %c %i %i\n", temp[i], wordSearch[row][col], row, col);
			pause;
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
	printf("left\n");
	pause;
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
			printf("%c %c %i %i\n", temp[i], wordSearch[row][col], row, col);
			pause;
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
	printf("down\n");
	pause;
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
			printf("%c %c %i %i\n", temp[i], wordSearch[row][col], row, col);
			pause;
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
	printf("up\n");
	pause;
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
				printf("%c %c %i %i\n", temp[i], wordSearch[row][col], row, col);
			pause;
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
	printf("%i, %i\n", length, (col+length));
	printf("%i\n", (row+length));
	pause;
	while ((col + length) >C){
		col= rand() % (50 + 0);//for COLUMNS 0-49
	}
	while ((row + length)>R){
		row=  rand() % (25 + 0);//for Rows 0-24
	}
	printf("%i\n", (col+length));
	printf("%i\n", (row+length));
	printf("Right down\n");
	pause;
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
			printf("%c %c %i %i\n", temp[i], wordSearch[row][col], row, col);
			pause;
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
	printf("%i, %i\n", length, (col-length));
	printf("%i\n", (row+length));
	pause;
	while ((col-length)<0){
		col= rand() % (50 + 0);//for COLUMNS 0-49
	}
	while ((row + length)>R){
		row=  rand() % (25 + 0);//for Rows 0-24
	}
	printf("%i\n", (col-length));
	printf("%i\n", (row+length));
	printf("Left down\n");
	pause;
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
			printf("%c %c %i %i\n", temp[i], wordSearch[row][col], row, col);
			pause;
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
	printf("%i, %i\n", length, (col+length));
	printf("%i\n", (row-length));
	pause;
	while ((col + length) >C){
		col= rand() % (50 + 0);//for COLUMNS 0-49
	}
	while ((row-length)<0){
		row=  rand() % (25 + 0);//for Rows 0-24
	}
	printf("%i\n", (col+length));
	printf("%i\n", (row-length));
	printf("Right up\n");
	pause;
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
			printf("%c %c %i %i\n", temp[i], wordSearch[row][col], row, col);
			pause;
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
	printf("%i, %i\n", length, (col-length));
	printf("%i\n", (row-length));
	pause;
	while ((col-length)<0){
		col= rand() % (50 + 0);//for COLUMNS 0-49
	}
	while ((row-length)<0){
		row=  rand() % (25 + 0);//for Rows 0-24
	}
	printf("%i\n", (col-length));
	printf("%i\n", (row-length));
	printf("Left up\n");
	pause;
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
			printf("%c %c %i %i\n", temp[i], wordSearch[row][col], row, col);
			pause;
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
