//*********************************************************************
//                          Course: 6272 Spring 2007
//                   John Ramshur and Deepika Konakanchi
//                          Project: Blackjack Game 
//*********************************************************************
//                             The game itself!
//*********************************************************************

#include <stdio.h>
#include <stdlib.h>
#include "game.h"

void hitorstand();
void roundover();
Game game1;
int pWinCnt=0,dWinCnt=0,tieCnt=0,gameCnt=0,roundCnt=0;	


main()
{	
	char input;	

	game1.start();

	//do while loop: lets the player keep playing till he decides to quit
	do
	{	roundCnt++;
		game1.clearHand();
		game1.deal(2,'d');
		game1.deal(2,'p');
		game1.pgame(0);
		
		//Check if either player has 21
		if((game1.val('d')>=21)||(game1.val('p')>=21))
		{
			roundover();
		}
		else
		{
			hitorstand();
		}
		
		//Shuffle deck after every 4 games
		if(roundCnt>4) 
		{
			game1.shuffle();
			roundCnt=0;
		}
		
		rePrompt: //returns here if invalid input

		printf("Do you want to play another game (y/n)?");
		scanf(" %c",&input);
		
		//check for valid inputs
		if ((input!='y') && (input!='n'))
		{printf("Invalid option!!!\n");goto rePrompt;}
		
	}while(input=='y');
	
	//Display Results
	system("clear");
	printf("************************\n");
	printf("Final Scores:\n");
	printf("************************\n");
	printf("Dealer: %d\n",dWinCnt);
	printf("Player: %d\n",pWinCnt);
	printf("Ties: %d\n\n",tieCnt);

	if (dWinCnt<pWinCnt)
		printf("Comments: Congratulations...\n");
	else if (dWinCnt>pWinCnt)
		printf("Comments: Stay at home...\n");
	else
		printf("Comments: Better luck next time...\n");
		
	printf("\nThanks for playing!!!\n\n");
}

void hitorstand()
{
	char opt;
	printf("Hit or Stand?(h/s)");
	scanf(" %c",&opt);
	if (opt=='h')
	{
		game1.hit('p');
		game1.pgame(0);
		if(game1.val('p')<21) hitorstand();
		else roundover();
	}
	else if (opt=='s')
	{
		while(game1.val('d')<17)
		{
			game1.hit('d');
		}
		roundover();	
	}
	else {printf("Invalid option!!!\n");hitorstand();}
}

void  roundover()
{
	game1.pgame(1);
	printf("Dealer=%d\n",game1.val('d'));
	printf("Player=%d\n",game1.val('p'));
	
	if((game1.val('p')>21)||((game1.val('d')>game1.val('p'))&&(game1.val('d')<=21)))
	{	printf("DEALER WINS !!!\n");
		dWinCnt++;
	}
	else if ((game1.val('d')>21)||((game1.val('p')>game1.val('d'))&&(game1.val('p')<=21)))
	{	
		printf("PLAYER WINS !!!\n");
		pWinCnt++;
	}
	else
	{	printf("TIE GAME !!!\n");
		tieCnt++;
	}		
}
