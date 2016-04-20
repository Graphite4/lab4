#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

void tablica (int *t, int n)
{
for (int i=100000,j=0; j<6; j++,i/=10)
	{
		
		*(t+j)=n/i;
		
		
		n%=i;
		
	}	
}
int drukuj_setki(int *t)
{
	const char* jednosci[9]={"jeden","dwa","trzy","cztery","pięć","sześć","siedem","osiem","dziewięć"};
	const char* dziesiatki[9]={"dziesięć","dwadzieścia","trzydzieści","czterdzieści","pięćdziesiąt","sześćdziesiąt","siedemdziesiąt","osiemdziesiąt","dziewiećdziesiąt"};
	const char* nascie[9]={"jedenaście","dwanaście","trzynaście","czternaście","piętnaście","szesnaście","siedemnaście","osiemnaście","dziewiętnaście"};
	const char* setki[9]={"sto","dwieście","trzysta","czterysta","pięćset","sześćset","siedemset","osiemset","dziewięćset"};
	
	int n=0;
	if(*t)
		{printf("%s ",setki[*t-1]);n++;}
	if(*(t+1))
		{printf("%s ",*(t+1)==1&&*(t+2)?nascie[*(t+1)-1]:dziesiatki[*(t+1)-1]);n++;}
	if(*(t+2)&&*(t+1)!=1)
		{printf("%s ",jednosci[*(t+2)-1]);n++;}
	return n;
}
void drukuj(int *t)
{
	const char* tysiace[3]={"tysiąc","tysiące","tysięcy"};
	if(drukuj_setki(t))
	{
		if(*t==0&&*(t+1)==0&&*(t+2)==1)
			printf("%s ",tysiace[0]);
		else if(*(t+2)<5&&*(t+1)!=1)
			printf("%s ",tysiace[1]);
		else
			printf("%s ",tysiace[2]);
	}
	drukuj_setki(t+3);
	printf("\n");



}
int main(int argc, char *argv[])
{
	int n = atoi(argv[1]);
	int tab[6];
	tablica (tab,n);
	drukuj(tab);

}