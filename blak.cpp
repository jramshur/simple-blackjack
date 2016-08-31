#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

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
static int N = 52;

void start(void)
{srand( (unsigned int) time(NULL)  ) ; }

int getran(int n)  /* get random num between 1 & n */
  { double x;
    static double y = (double) RAND_MAX + 1.0;
    x = (double) rand()/y ;
     return (int) n*x +1;  
}
void shuffle(void)    { N = 52; }

void swap(int i,int j)
     {char * temp;   temp=card[i];
                     card[i] = card[j];
                     card[j] = temp;
     } 
void deal(int n, char *hand[])
   {  int i;
      hand[n] = NULL;
      while(n) { hand[--n] = card[i=getran(N)]; swap(i,N--); }
   }
#include <ctype.h>

int  val(char *p[])
   { char c; int tot=0, acount=0;
     while(*p) {  c = **p++;
                  if(c=='1'|| c=='J' || c=='Q' || c=='K') tot +=10; 
                  if(c=='A') {tot +=11; ++acount;}
                  if(isdigit(c) && (c != '1')) tot +=(c -'0'); }
     while(acount--) if(tot > 21) tot -=10;
     return tot; }       

int hsize(char *p[])      /** size of hand **/
      {int i=0; while(*p++) i++;   return i; }

void hit(char *p[]) /** adds card to hand **/
       {deal(1, &p[hsize(p)]); }

void phand( char *p[]) /** print hand **/
     { while(*p) printf("  %s  ",*p++);  printf(":\n"); }
    
