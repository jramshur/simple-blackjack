#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

//Game Class Definition
class Game {
 public:	Game (void);
		void start(void);
		int getran(int);
		void shuffle(void);
		void swap(int,int);
		void deal(int,char *hand[]);
		int val(char *p[]);
		int hsize(char *p[]);
		void hit(char *p[]);
		void phand(char *p[]);
 private:	static int N;
		static char *card[]= { NULL, 
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
                "K c","K d","K h","K s" };
};
