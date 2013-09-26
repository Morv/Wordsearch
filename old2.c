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


//////////////////////////////////Totaram Ramrattan////////////////////////////////////////////
/// I got this program to run maybe you can either use my logic and up grade it and try to fill up my puzzle
/// they codes work pretty good but slight glitch is i dont know how to get words to over lap each other.




#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
	char *temp[8] ={" "};
	for(count= 0; count<KEY; count++){
		length = strlen(keyword[count]);
		*temp = keyword[count];
		col= rand() % (50 + 0);//for COLUMNS 0-49
		row=  rand() % (25 + 0);//for Rows 0-24
		direct =  rand() % 8 + 1;//for directions 1-8
		printf("%i\n",direct);

		switch(direct){;
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
		}// end of switch*/

	}// end of for loop

}//end of fits


void rightFit(int col, int row, int length, char wordSearch[][C],char *temp){
	char x = ' ';
	int i =0;
	while ((col + length) >C){
		col= rand() % (50 + 0);//for COLUMNS 0-49
	}
		printf("right\n");
		pause;
		for(i=0; i<KEYLEN; i++){
			x = temp[i];
			wordSearch[row][col] = x;
			col++;
		}

}

void leftFit(int col, int row, int length, char wordSearch[][C],char *temp){
	char x = ' ';
	int i =0;
	while ((col-length)<0){
		col= rand() % (50 + 0);//for COLUMNS 0-49
	}
		printf("left\n");
		pause;
		for(i=0; i<KEYLEN; i++){
			x = temp[i];
			wordSearch[row][col] = x;
			col--;
		}

}

void downFit(int col, int row, int length, char wordSearch[][C],char *temp){
	char x = ' ';
	int i =0;
	while ((row + length)>R){
		row=  rand() % (25 + 0);//for Rows 0-24
	}
		printf("down\n");
		pause;
		for(i=0; i<KEYLEN; i++){
			x = temp[i];
			wordSearch[row][col] = x;
			row++;
		}

}
void upFit(int col, int row, int length, char wordSearch[][C],char *temp){
	char x = ' ';
	int i =0;
	while ((row-length)<0){
		row=  rand() % (25 + 0);//for Rows 0-24
	}
		printf("up\n");
		pause;
		for(i=0; i<KEYLEN; i++){
			x = temp[i];
			wordSearch[row][col] = x;
			row--;
		}
}

void RdownFit(int col, int row, int length, char wordSearch[][C],char *temp){
	char x = ' ';
	int i =0;
	while ((col + length) >C){
		col= rand() % (50 + 0);//for COLUMNS 0-49
	}
	while ((row + length)>R){
		row=  rand() % (25 + 0);//for Rows 0-24
	}
		printf("Right down\n");
		pause;
		for(i=0; i<KEYLEN; i++){
			x = temp[i];
			wordSearch[row][col] = x;
			col++;
			row++;
		}


}
void LdownFit(int col, int row, int length, char wordSearch[][C],char *temp){
	char x = ' ';
	int i =0;
	while ((col-length)<0){
		col= rand() % (50 + 0);//for COLUMNS 0-49
	}
	while ((row + length)>R){
		row=  rand() % (25 + 0);//for Rows 0-24
	}
		printf("Left down\n");
		pause;
		for(i=0; i<KEYLEN; i++){
			x = temp[i];
			wordSearch[row][col] = x;
			col--;
			row++;
		}


}
void RupFit(int col, int row, int length, char wordSearch[][C],char *temp){
	char x = ' ';
	int i =0;
	while ((col + length) >C){
		col= rand() % (50 + 0);//for COLUMNS 0-49
	}
	while ((row-length)<0){
		row=  rand() % (25 + 0);//for Rows 0-24
	}
		printf("Right up\n");
		pause;
		for(i=0; i<KEYLEN; i++){
			x = temp[i];
			wordSearch[row][col] = x;
			col++;
			row--;
		}


}
void LupFit(int col, int row, int length, char wordSearch[][C],char *temp){
	char x = ' ';
	int i =0;
	while ((col-length)<0){
		col= rand() % (50 + 0);//for COLUMNS 0-49
	}
	while ((row-length)<0){
		row=  rand() % (25 + 0);//for Rows 0-24
	}
		printf("Left up\n");
		pause;
		for(i=0; i<KEYLEN; i++){
			x = temp[i];
			wordSearch[row][col] = x;
			col--;
			row--;
		}


}






