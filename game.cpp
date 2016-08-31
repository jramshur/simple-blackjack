//*********************************************************************
//                          Course: 6272 Spring 2007
//                   John Ramshur and Deepika Konakanchi
//                          Project: Blackjack Game 
//*********************************************************************
//                   Methods of class Game and functions
//*********************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "game.h"

Game::Game(void){ }

char *Game::card[] = {NULL, 
	"A c","A d","A h","A s",
        "2 c","2 d","2 h","2 s",
        "3 c","3 d","3 h","3 s",
        "4 c","4 d","4 h","4 s",
        "5 c","5 d","5 h","5 s",
        "6 c","6 d","6 h","6 s",
        "7 c","7 d","7 h","7 s",
        "8 c","8 d","8 h","8 s",
        "9 c","9 d","9 h","9 s",
        "10c","10d","10h","10s",
        "J c","J d","J h","J s",
        "Q c","Q d","Q h","Q s",
        "K c","K d","K h","K s"};

int Game::N=52;

char *Game::handD[53];
char *Game::handP[53];

void Game::start(void)
{
	srand((unsigned int) time(NULL));
	shuffle();
	clearHand();
}	
	
int Game::getran(int n)  /* get random num between 1 & n */
{ 	
	double x;
    	static double y = (double) RAND_MAX + 1.0;
    	x = (double) rand()/y ;
     	return (int) n*x +1;
}

void Game::shuffle(void)
{
	Game::N=52;
}

void Game::swap(int i,int j)
{	
	char * temp;   temp=card[i];
        card[i] = card[j];
        card[j] = temp;
}
 
void Game::deal(int n, char opt)
{  
	int i;
	if (opt=='d')//if dealer
	{
		handD[hsize('d')+n] = NULL;
		while(n) 
		{ 
			handD[--n + hsize('d')] = card[i=getran(N)]; 
			swap(i,N--); 
		}
	}
	else //if player
	{	
		handP[hsize('p')+n] = NULL;
		while(n) 
		{ 
			handP[--n + hsize('p')] = card[i=getran(N)]; 
			swap(i,N--); 
		}
	}

}

int  Game::val(char opt)
{ 	
	char c; int tot=0, acount=0,i=0;
	
	if (opt=='d') //if dealer
	{
		while(handD[i++]) 
		{
			c = handD[i-1][0];
			if(c=='1'|| c=='J' || c=='Q' || c=='K') tot +=10; 
			if(c=='A') {tot +=11; ++acount;}
			if(isdigit(c) && (c != '1')) tot +=(c -'0'); 
		}
		while(acount--) if(tot > 21) tot -=10;
		return tot;
	}
	else //if player
	{
		i=0;acount=0;
		while(handP[i++]) 
		{
			c = handP[i-1][0];
			if(c=='1'|| c=='J' || c=='Q' || c=='K') tot +=10; 
			if(c=='A') {tot +=11; ++acount;}
			if(isdigit(c) && (c != '1')) tot +=(c -'0'); 
		}
		while(acount--) if(tot > 21) tot -=10;
		return tot;
	}
}

int Game::hsize(char opt)      // size of hand
{	
	int i=0;
	if(opt=='d') //if dealer
		while(handD[i]) i++;
	else //if player
		while(handP[i]) i++;
	return i;
}

void Game::hit(char opt) // adds card to hand
{	
	deal(1, opt);
}

void Game::phand(int flag, char opt)
{
	//Prints hand
	// opt = d --> For printing dealers hand. 
	// opt = p --> For printing players hand. 
	// flag= 1 --> Show All cards of dealer at end of round
	// flag= 0 --> Show only one card of dealer in intermediate steps

	int handCnt=0, showCnt=0, c=0;
	char *nill = "***", *name, *space="          ";
	char *score; char tmp[80];	

	handCnt=hsize(opt); //get # of cards in hand
	
	//Decide how many cards to show and
	//Get current val of hand to display
	if (!flag){showCnt=1;score="??";}
	else
	{
		showCnt=handCnt;sprintf(tmp,"%i",val(opt));
		if(val(opt)>=10) score=tmp;
		else score=strcat(tmp," ");
	}
	
	if (opt=='d')name="DEALER: ";
	else name="PLAYER: ";
	
	//print hand
	for(c=0;c<handCnt;c++){printf("%s ~~~~~~~ ",(c==0)?space:"");} printf("\n");c=handCnt;
	for(c=0;c<handCnt;c++){printf("%s |     | ",(c==0)?space:"");} printf("\n");c=handCnt;
	if(opt=='d') //if dealer
	{
		for(c=0;c<handCnt;c++){printf("%s%s | %3s | ",(c==0)?name:"", (c==0)?score:"",(c<showCnt)?handD[c]:nill);} printf("\n");c=handCnt;
	}
	else //if player
	{
		for(c=0;c<handCnt;c++){printf("%s%s | %3s | ",(c==0)?name:"",(c==0)?score:"",(c<showCnt)?handP[c]:nill);} printf("\n");c=handCnt;
	}
	for(c=0;c<handCnt;c++){printf("%s |     | ",(c==0)?space:"");} printf("\n");c=handCnt;
	for(c=0;c<handCnt;c++){printf("%s ~~~~~~~ ",(c==0)?space:"");} printf("\n");
}

void Game::pgame(int gameOverFlag){
	//Displays current cards for both players
	//if gameOverFlag is set the val of all the dealer's cards are shown
	system("clear");
	printf("\n");
	phand(gameOverFlag,'d'); //print dealer's hand
	printf("\n\n");
	phand(1,'p'); //print player's hand
	printf("\n\n");

}
