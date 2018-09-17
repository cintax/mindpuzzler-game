#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>

#define ROW 3
#define COLUMN 3
#define TOTAL_CELL 9

void printMenu(void);
void menuChoice(void);
void showHighscores(void);
void showRules(void);
void exitGame(void);
void assignMatrix(int *);
void shuffleMatrix(int *);
void printMatrix(int *);
void gameStart(void);
void initializations(int *);
void searchLocationOfZeroAndSwapByCheckingRules(int *, int);
int isSortedArray(int *);
int askDirectionToSwap(void);

int main()
{
	printMenu();
	menuChoice();
}

void assignMatrix(int *first)
{
	int i;
	for(i = 1; i <= TOTAL_CELL; i++)
	{
		if(i == TOTAL_CELL)
			*first = 0;#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>

#define ROW 3
#define COLUMN 3
#define TOTAL_CELL 9

void printMenu(void);
void menuChoice(void);
void showHighscores(void);
void showRules(void);
void exitGame(void);
void assignMatrix(int *);
void shuffleMatrix(int *);
void printMatrix(int *);
void gameStart(void);
void initializations(int *);
void searchLocationOfZeroAndSwapByCheckingRules(int *, int);
int isSortedArray(int *);
int askDirectionToSwap(void);

int main()
{
	printMenu();
	menuChoice();
}

void assignMatrix(int *first)
{
	int i;
	for(i = 1; i <= TOTAL_CELL; i++)
	{
		if(i == TOTAL_CELL)
			*first = 0;
		else
		{		
			*first = i;
			first++;
		}
	}
}

void shuffleMatrix(int *first)
{
	int constant, temp, swapTemp, j, *firstRow, *firstColumn, *tpRow, *tpColumn, *reminder;
	
	reminder = first;

	for(constant=0; constant < 3; constant++)
	{	
		firstRow = reminder;						// Resets firstRow to argument value *first
		firstColumn = reminder;						// Resets firstColumn to argument value *first

		temp = rand() % 3;							// Prints value between 0 to 2
		tpRow = first + (temp*3);					// Bring pointer 'tpRow' to starting of the row
		tpColumn = first + temp;					// Bring pointer 'tpColumn' to starting of the column

		temp = rand() % 3;							// Prints value between 0 to 2
		firstRow = first + (temp*3);				// Bring pointer 'firstRow' to starting of the row
		firstColumn = first + temp;					// Bring pointer 'firstColumn' to starting of the column

		for(j = 0; j < 3; j++)	{					// Swapping rows & columns
			swapTemp = *firstRow;
			*firstRow = *tpRow;
			*tpRow = swapTemp;																
			
			swapTemp = *firstColumn;
			*firstColumn = *tpColumn;
			*tpColumn = swapTemp;
			
			firstRow++;																		
			tpRow++;

			firstColumn++;
			tpColumn++;
		}
	}	
}

void printMatrix(int *first)
{
	printf("\n----|----|----\n");
	for(int i = 0; i < 9; i++)
	{
		if(i%3==2)
		{
			printf("%-2d\n",*first);
			printf("----|----|----\n");
		}		
		else
			printf("%-4d|",*first);
		first++;
	}			
}

void printMenu()
{
	printf("\n\n\n");
	printf(" -==========================================================-\n");
	printf("-=================-GAME BY ADITYA SHAH-======================-\n");
	printf(" -==========================================================-\n");
	printf("             ____ ____                                      _ \n ");
	printf(" _____     |__  |__  |                 _____              | |\n ");
	printf("|  __ |_  _  / /  / / _   ___ ____    |   __|___ _____ ___| |\n ");
	printf("|  ___| || |/ /_ / /_| |_| -_|  _/    |  |  | _ |     | -_|_|\n ");
	printf("|_|   |____|____|____|___|___|_|      |_____|__,|_|_|_|___|_|\n\n");
	printf("==============================================================\n");	
	printf("-============================================================-\n");
	printf(" -==========================================================-\n");
    printf("\n\n");
	printf("              --PRESS 1 TO START--                            \n");
	printf("              --PRESS 2 TO VIEW HIGHSCORE--                   \n");
	printf("              --PRESS 3 TO READ RULES--                       \n");
	printf("              --PRESS 4 TO EXIT--                             \n");
	printf("\n\n");
	printf("==============================================================\n");	
	printf("-============================================================-\n");
	printf(" -==========================================================-\n");
}

void gameStart()
{
	int gameMatrix[3][3];
	srand(time(0));
	int i, temp;
	
	printf("==============================================================\n");	
	printf("-============================================================-\n");
	printf(" -==========================================================-\n");	
	assignMatrix(&gameMatrix[0][0]);
	shuffleMatrix(&gameMatrix[0][0]);
	initializations(&gameMatrix[0][0]);						// Swaps the shuffled array's last element and 0's location.	
	printMatrix(&gameMatrix[0][0]);

	while(isSortedArray(&gameMatrix[0][0])==0)
	{
		int directionCode = askDirectionToSwap();
		searchLocationOfZeroAndSwapByCheckingRules(&gameMatrix[0][0],directionCode);
		printMatrix(&gameMatrix[0][0]);
	}
}

int isSortedArray(int *first)
{
	int i;
	for(i = 1; i < TOTAL_CELL - 1; i++)
	{
		if(*first > *(first+1))
			return 0;
		else
			first++;
	}
	return 1;			
}

void initializations(int *first)
{
	int i, temp = *(first+8), *reminder;
	reminder = first;

	for(i = 0; i < TOTAL_CELL-1; i++)
	{
		if(*first == 0)
		{
			*first = temp;
		}
		else
			first++;
	}

	first = reminder;
	*(first+8) = 0;	
}

int askDirectionToSwap()
{	
	char direction[10];
	printf("\n\nEnter Direction for Swapping: ");
	scanf("%s",direction);
	if(strcmp(direction,"left") == 0)
		return 1;
	else if(strcmp(direction,"right") == 0)
		return 2;
	else if(strcmp(direction,"top") == 0)
		return 3;
	else if(strcmp(direction,"down") == 0)
		return 4;
	else
		return 0;
}

void searchLocationOfZeroAndSwapByCheckingRules(int *first,int directionCode)
{
	int i, *check,*reminder, temp;
	reminder = first;
	for(i = 0; i < TOTAL_CELL; i++)
	{
		if(*first == 0)
		{
			check = first;
			first = reminder;
			if(directionCode == 1)
			{
				if((check == first) || (check == first + 3) || (check == first + 6))
				{
					printf("Invalid Move");
					break;
				}
				else
				{
					temp = *check;
					*check = *(check - 1);
					*(check - 1) = temp;
					printf("Swapped");
					break;
				}
			}
			else if(directionCode == 2)
			{
				if((check == first + 2) || (check == first + 5) || (check == first + 8))
				{
					printf("Invalid Move");
					break;
				}
				else
				{
					temp = *check;
					*check = *(check + 1);
					*(check + 1) = temp;
					printf("Swapped");
					break;
				}
			}
			else if(directionCode == 3)
			{
				if((check == first) || (check == first + 1) || (check == first +2))
				{
					printf("Invalid Move");
					break;
				}
				else
				{
					temp = *check;
					*check = *(check - 3);
					*(check - 3) = temp;
					printf("Swapped");
					break;
				}
			}
			else if(directionCode == 4)
			{
				if((check == first + 6) || (check == first + 7) || (check == first + 8))
				{
					printf("Invalid Move");
					break;
				}
				else
				{
					temp = *check;
					*check = *(check + 3);
					*(check + 3) = temp;
					printf("Swapped");
					break;
				}
			}
			else if(directionCode == 0)
			{
				printf("Wrong Direction to Move");
				break;
			}	
		}
		else
			first++;
	}	
}

void menuChoice()
{
	int choice;
	printf("Enter your Choice: ");
	scanf("%d",&choice);
	if(choice == 1)
		gameStart();
	else if(choice == 2)
		showHighscores();
	else if(choice == 3)
		showRules();
	else
		exitGame();
}

void showHighscores()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf(" -==========================================================-\n");
	printf("-=================-    COMING SOON    -======================-\n");
	printf(" -==========================================================-\n");
	printf("\n\n\n\n\n\n\n\n\n\n");
}

void showRules()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf(" -==========================================================-\n");
	printf("-=====================-   RULES   -==========================-\n");
	printf(" -==========================================================-\n");
	printf("\n\n\n");
	printf(" (i) SORT THE MATRIX BY MOVING AROUND 0");
	printf(" \n(ii) SORT THE MATRIX TO WIN THE GAME");
	printf(" \n(iii) KEEP TRYING.");
	printf("\n\n\n");
	printf("==============================================================\n");	
	printf("-============================================================-\n");
	printf(" -==========================================================-\n");
	printf("\n\n\n\n\n");
}

void exitGame()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf(" -==========================================================-\n");
	printf("-=================-THANKS FOR PLAYING -======================-\n");
	printf(" -==========================================================-\n");
	printf("             ____ ____                                      _ \n ");
	printf(" _____     |__  |__  |                 _____              | |\n ");
	printf("|  __ |_  _  / /  / / _   ___ ____    |   __|___ _____ ___| |\n ");
	printf("|  ___| || |/ /_ / /_| |_| -_|  _/    |  |  | _ |     | -_|_|\n ");
	printf("|_|   |____|____|____|___|___|_|      |_____|__,|_|_|_|___|_|\n\n");
	printf("==============================================================\n");	
	printf("-============================================================-\n");
	printf(" -==========================================================-\n");
	printf("\n\n\n\n\n");
}
		else
		{		
			*first = i;
			first++;
		}
	}
}

void shuffleMatrix(int *first)
{
	int constant, temp, swapTemp, j, *firstRow, *firstColumn, *tpRow, *tpColumn, *reminder;
	
	reminder = first;

	for(constant=0; constant < 3; constant++)
	{	
		firstRow = reminder;						// Resets firstRow to argument value *first
		firstColumn = reminder;						// Resets firstColumn to argument value *first

		temp = rand() % 3;							// Prints value between 0 to 2
		tpRow = first + (temp*3);					// Bring pointer 'tpRow' to starting of the row
		tpColumn = first + temp;					// Bring pointer 'tpColumn' to starting of the column

		temp = rand() % 3;							// Prints value between 0 to 2
		firstRow = first + (temp*3);				// Bring pointer 'firstRow' to starting of the row
		firstColumn = first + temp;					// Bring pointer 'firstColumn' to starting of the column

		for(j = 0; j < 3; j++)	{					// Swapping rows & columns
			swapTemp = *firstRow;
			*firstRow = *tpRow;
			*tpRow = swapTemp;																
			
			swapTemp = *firstColumn;
			*firstColumn = *tpColumn;
			*tpColumn = swapTemp;
			
			firstRow++;																		
			tpRow++;

			firstColumn++;
			tpColumn++;
		}
	}	
}

void printMatrix(int *first)
{
	printf("\n----|----|----\n");
	for(int i = 0; i < 9; i++)
	{
		if(i%3==2)
		{
			printf("%-2d\n",*first);
			printf("----|----|----\n");
		}		
		else
			printf("%-4d|",*first);
		first++;
	}			
}

void printMenu()
{
	printf("\n\n\n");
	printf(" -==========================================================-\n");
	printf("-=================-GAME BY ADITYA SHAH-======================-\n");
	printf(" -==========================================================-\n");
	printf("             ____ ____                                      _ \n ");
	printf(" _____     |__  |__  |                 _____              | |\n ");
	printf("|  __ |_  _  / /  / / _   ___ ____    |   __|___ _____ ___| |\n ");
	printf("|  ___| || |/ /_ / /_| |_| -_|  _/    |  |  | _ |     | -_|_|\n ");
	printf("|_|   |____|____|____|___|___|_|      |_____|__,|_|_|_|___|_|\n\n");
	printf("==============================================================\n");	
	printf("-============================================================-\n");
	printf(" -==========================================================-\n");
    printf("\n\n");
	printf("              --PRESS 1 TO START--                            \n");
	printf("              --PRESS 2 TO VIEW HIGHSCORE--                   \n");
	printf("              --PRESS 3 TO READ RULES--                       \n");
	printf("              --PRESS 4 TO EXIT--                             \n");
	printf("\n\n");
	printf("==============================================================\n");	
	printf("-============================================================-\n");
	printf(" -==========================================================-\n");
}

void gameStart()
{
	int gameMatrix[3][3];
	srand(time(0));
	int i, temp;
	
	printf("==============================================================\n");	
	printf("-============================================================-\n");
	printf(" -==========================================================-\n");	
	assignMatrix(&gameMatrix[0][0]);
	shuffleMatrix(&gameMatrix[0][0]);
	initializations(&gameMatrix[0][0]);						// Swaps the shuffled array's last element and 0's location.	
	printMatrix(&gameMatrix[0][0]);

	while(isSortedArray(&gameMatrix[0][0])==0)
	{
		int directionCode = askDirectionToSwap();
		searchLocationOfZeroAndSwapByCheckingRules(&gameMatrix[0][0],directionCode);
		printMatrix(&gameMatrix[0][0]);
	}
}

int isSortedArray(int *first)
{
	int i;
	for(i = 1; i < TOTAL_CELL - 1; i++)
	{
		if(*first > *(first+1))
			return 0;
		else
			first++;
	}
	return 1;			
}

void initializations(int *first)
{
	int i, temp = *(first+8), *reminder;
	reminder = first;

	for(i = 0; i < TOTAL_CELL-1; i++)
	{
		if(*first == 0)
		{
			*first = temp;
		}
		else
			first++;
	}

	first = reminder;
	*(first+8) = 0;	
}

int askDirectionToSwap()
{	
	char direction[10];
	printf("\n\nEnter Direction for Swapping: ");
	scanf("%s",direction);
	if(strcmp(direction,"left") == 0)
		return 1;
	else if(strcmp(direction,"right") == 0)
		return 2;
	else if(strcmp(direction,"top") == 0)
		return 3;
	else if(strcmp(direction,"down") == 0)
		return 4;
	else
		return 0;
}

void searchLocationOfZeroAndSwapByCheckingRules(int *first,int directionCode)
{
	int i, *check,*reminder, temp;
	reminder = first;
	for(i = 0; i < TOTAL_CELL; i++)
	{
		if(*first == 0)
		{
			check = first;
			first = reminder;
			if(directionCode == 1)
			{
				if((check == first) || (check == first + 3) || (check == first + 6))
				{
					printf("Invalid Move");
					break;
				}
				else
				{
					temp = *check;
					*check = *(check - 1);
					*(check - 1) = temp;
					printf("Swapped");
					break;
				}
			}
			else if(directionCode == 2)
			{
				if((check == first + 2) || (check == first + 5) || (check == first + 8))
				{
					printf("Invalid Move");
					break;
				}
				else
				{
					temp = *check;
					*check = *(check + 1);
					*(check + 1) = temp;
					printf("Swapped");
					break;
				}
			}
			else if(directionCode == 3)
			{
				if((check == first) || (check == first + 1) || (check == first +2))
				{
					printf("Invalid Move");
					break;
				}
				else
				{
					temp = *check;
					*check = *(check - 3);
					*(check - 3) = temp;
					printf("Swapped");
					break;
				}
			}
			else if(directionCode == 4)
			{
				if((check == first + 6) || (check == first + 7) || (check == first + 8))
				{
					printf("Invalid Move");
					break;
				}
				else
				{
					temp = *check;
					*check = *(check + 3);
					*(check + 3) = temp;
					printf("Swapped");
					break;
				}
			}
			else if(directionCode == 0)
			{
				printf("Wrong Direction to Move");
				break;
			}	
		}
		else
			first++;
	}	
}

void menuChoice()
{
	int choice;
	printf("Enter your Choice: ");
	scanf("%d",&choice);
	if(choice == 1)
		gameStart();
	else if(choice == 2)
		showHighscores();
	else if(choice == 3)
		showRules();
	else
		exitGame();
}

void showHighscores()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf(" -==========================================================-\n");
	printf("-=================-    COMING SOON    -======================-\n");
	printf(" -==========================================================-\n");
	printf("\n\n\n\n\n\n\n\n\n\n");
}

void showRules()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf(" -==========================================================-\n");
	printf("-=====================-   RULES   -==========================-\n");
	printf(" -==========================================================-\n");
	printf("\n\n\n");
	printf(" (i) SORT THE MATRIX BY MOVING AROUND 0");
	printf(" \n(ii) SORT THE MATRIX TO WIN THE GAME");
	printf(" \n(iii) KEEP TRYING.");
	printf("\n\n\n");
	printf("==============================================================\n");	
	printf("-============================================================-\n");
	printf(" -==========================================================-\n");
	printf("\n\n\n\n\n");
}

void exitGame()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf(" -==========================================================-\n");
	printf("-=================-THANKS FOR PLAYING -======================-\n");
	printf(" -==========================================================-\n");
	printf("             ____ ____                                      _ \n ");
	printf(" _____     |__  |__  |                 _____              | |\n ");
	printf("|  __ |_  _  / /  / / _   ___ ____    |   __|___ _____ ___| |\n ");
	printf("|  ___| || |/ /_ / /_| |_| -_|  _/    |  |  | _ |     | -_|_|\n ");
	printf("|_|   |____|____|____|___|___|_|      |_____|__,|_|_|_|___|_|\n\n");
	printf("==============================================================\n");	
	printf("-============================================================-\n");
	printf(" -==========================================================-\n");
	printf("\n\n\n\n\n");
}
