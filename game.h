//*********************************************************************
//                          Course: 6272 Spring 2007
//                   John Ramshur and Deepika Konakanchi
//                          Project: Blackjack Game 
//*********************************************************************
//                          Header file
//*********************************************************************


//Game Class Definition
class Game 
{
public:		Game(void);		//Constructor
		void start(void);	//Seeds the random number generator
		void shuffle(void);	//Shuffle cards & reset deck
		void deal(int n,char opt);//Deal n cards based on opt
		int val(char opt);	//Calculates value of hand
		void hit(char opt);	//Add card to hand 
		void pgame(int gameOverFlag);//Print Game
		void clearHand(void){handP[0]=NULL;handD[0]=NULL;};//clear hand

private:	int hsize(char opt);	//returns number of cards in hand
		void swap(int,int);	
		int getran(int);	//generates random number
		void phand(int flag, char opt);//Print hand
		static char *card[53];	//deck of cards	
		static char *handD[53];	//Dealer's hand
		static char *handP[53];	//Player's hand
		static int N;		//Number of cards in deck
};
