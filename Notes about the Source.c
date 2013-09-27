//Totaram Ramrattan comment about what i think about the Source.c if that one is gonna be used

		col= rand() % (50 + 0);//for COLUMNS 0-49

		row=  rand() % (25 + 0);//for Rows 0-24

every time you do that col have the possiblity of being 50 and row have the possiblity of being 25
    remember when we inilized worrdSearch[R][C] : there R = 25 and C = 50
    now if you call on with R = 25 and C = 50
		wordSearch[row][col] = temp[i];
		you would basically saying that
		wordSearch[25][50] = temp[i];
Now that wont be accurate cause you are basically calling out of value
 
with R = 25

0 = Row 1, 1 = Row 2, 2 = Row 3 and so on till 23 = Row 24, 24, Row 25

with C = 50

0 = Col 1, 1 = Col 2, 2 = Col 3 and so on till 48 = Col 49,49 = COl 50

so 

col= rand() % (49 + 0);//for COLUMNS 0-49

row=  rand() % (24 + 0);//for Rows 0-24

direct = (rand() % (8 + 1 - 1)) + 1;//for directions 1-8

why all the plus and minus all unnecessary cause +1 - 1 = 0 and the + 1 = 1

basically direct = (rand() % (8 + 1));//for directions 1-8 will do the same with no worries.

and these col= (rand() % (49 + 1 - 0)) + 0;//for COLUMNS 0-49     line 80
		      row= (rand() % (24 + 1 - 0)) + 0;//for Rows 0-24        line 81
simply can be   col= (rand() % (49 + 0));//for COLUMNS 0-49
		            row= (rand() % (24 + 0));//for Rows 0-24	     
		            
that char *temp[8] ={'\0'}; on line 74 should be char *temp[9] ={'\0'};
		      
I dont know if all those functions to display was necessary cause it will be hard to get all the printf as fprintf- 
into the text file that has to be created. you are going to have to open the text file in everyone of the functions.

The random letter was pretty smart i didnt think. Good job guys.
