#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <math.h>

// Prototypy
int* array (int *t,int n, int k);
int arraycheck(int*,int);
int print_hundreds(int *t);
void print(int *t);
int searching_k(int n);
int arraycheck(int* t, int n);
unsigned long long int ullipow(unsigned long long int n, unsigned long long int k);

int main(int argc, char *argv[])
{
	int n = atoi(argv[1]);
	int tab[6];
	int k = searching_k(n);
	printf("n = %i, k = %i, n * k = %i\n", 
		n, k, n * k);
	print(array( tab, k , 9 ));
}

// Funkcje
int print_hundreds(int *t)
{
	const char* units[9]={"jeden","dwa","trzy","cztery","pięć","sześć","siedem","osiem","dziewięć"};
	const char* tens[9]={"dziesięć","dwadzieścia","trzydzieści","czterdzieści","pięćdziesiąt","sześćdziesiąt","siedemdziesiąt","osiemdziesiąt","dziewiećdziesiąt"};
	const char* teens[9]={"jedenaście","dwanaście","trzynaście","czternaście","piętnaście","szesnaście","siedemnaście","osiemnaście","dziewiętnaście"};
	const char* hundreds[9]={"sto","dwieście","trzysta","czterysta","pięćset","sześćset","siedemset","osiemset","dziewięćset"};
	
	int n=0;
	if(*t)
		{printf("%s ",hundreds[*t-1]);n++;}
	if(*(t+1))
		{printf("%s ",*(t+1)==1&&*(t+2)?teens[*(t+1)-1]:tens[*(t+1)-1]);n++;}
	if(*(t+2)&&*(t+1)!=1)
		{printf("%s ",units[*(t+2)-1]);n++;}
	return n;
}

void print(int *t)
{
	if(print_hundreds(t))
	{
		if( *t == 0 && *( t + 1 ) == 0 && *( t + 2 ) == 1 )
			printf("milion ");
		else if( *( t + 2 ) != 1 && *( t + 2 ) < 5 && *( t + 1 ) != 1)
			printf("miliony ");
		else
			printf("milionów ");
	}

	if(print_hundreds(t+3))
	{
		if( *( t + 3 ) == 0 && *( t + 4 ) == 0 && *( t + 5 ) == 1 )
			printf("tysiąc ");
		else if( *( t + 5 ) != 1 && *( t + 5 ) < 5 &&*( t + 4 ) != 1 )
			printf("tysiące ");
		else
			printf("tysięcy ");
	}
	print_hundreds( t + 6 );
	printf("\n");
}

int* array(int *t, int n, int k)
{
	unsigned long long int i = ullipow( 10, k-2);
	for ( int j = 0; j < k; j++, i /= 10)
	{
		*( t + j ) = n / i;
		n %= i;
	}
	return t;	
}

int searching_k(int n)
{
	int k = 1, x = 1, j = 0;
	while( n % 10 == 0 ) n /= 10;
	while( n %   2 == 0 ) {	k *=   5;	n /=  2; }
	while( n %   5 == 0 ) {	k *=   2;	n /=  5; }

	for(; ( n / ( int ) pow( 10, j) ); j++)
		while( ( n*x / ( int ) pow( 10, j) ) %10 !=0 && ( n*x / ( int ) pow( 10, j)) %10!= 1 )
			x += ( int ) pow ( 10, j );
	
	
	int tab[12];
	while( arraycheck( array( tab, n * x, 12), 12) )
		x += (int) pow(10, j);
	k *= x;
	
	return k;
}

unsigned long long int ullipow(unsigned long long int n, unsigned long long int k)
{
	unsigned long long int result = n;
	while(k--) result *= n;
	return result;	
}

int arraycheck(int* t, int n)
{
	for( int i = 0 ; i < n ; i++)
		if( *( t + i )!= 0 && *( t + i ) != 1 ) return 1;
	return 0;
}