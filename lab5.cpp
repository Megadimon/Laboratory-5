#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string> 
#include <conio.h>
using namespace std;


double sum ( float a, float b )
{
return a+b; 
}

double sub (float a, float b)

{ 
return a-b;
}

double mult (float a, float b)
{
	if (a==0 || b==0)
		return 0;
		else return a*b;
}

double div (float a, float b, int* c)
{
	if (b != 0 && a != 0) return (float)a/b;
		else if (a == 0 && b != 0) return 0;
			else if (b == 0) *c = 1;
}

float pow (float a, float b, int* c)
{
	float a2 = a;
	
	if (a != 0)
	{
		*c = 0;
		if (b < 0 && b!=0)
		{
	    	for (unsigned int i = 1; i <-b ; ++i)
		 	{
		 	a*=a2;
		 	}
			a=(float)1/a;
			}
				else if (b>0 && b!=0)
				{
					for (unsigned int i = 1; i < b; ++i)
					{
						a*=a2;
					}
				}
		else a = 1.0;
		return (double) a;
		}
		else if ( a == 0 && b < 0 ) *c = 1;
			else if ( a == 0 && b > 0 ) return 0;
				else if ( a == 0 && b == 0 ) return 1;
	}


double sq (float a, int* c)
{	
	float n = 1.0;  
	float t = 2.0;
	
	if ( a >= 0 )
	{
		*c = 0;
		if ( a != 1 && a != 0 )
		{
			while ( (t - n) > 0.000001 || (t - n) < -0.000001  )
			{
		 		n = t;
		 		t = (float)(n + (float)a/n)/2;
			}	

		}
			else if ( a == 1 ) t = 1;
				else if ( a == 0 ) t = 0;
				return t;
	}
		else *c = 1;
		
}
int main( int argc, char *argv[])
{
float a = 0.0;
float b = 0.0;
int* c = (int*)malloc(sizeof(int));
*c = 0;

if (argc < 3)
 {
 	cout << "An error in the command line parameters is not enough to define the source data. Press ane key to end..." << endl;
 	_getch();
 	return 1;
 }
a = stod(argv[1]);
 b = stod(argv[2]);
cout << "************Welcome to the Calculator vol 2.0************" << endl;
cout << "a = ";
cout << endl << "b = ";
cout <<"a+b = " << sum(a,b) << endl;
cout <<"a-b = " << sub(a,b) << endl;
cout <<"a*b = " << mult(a,b) << endl;
div(a,b,c);
if (*c == 0 ) cout <<"a/b = " << div(a,b,c) << endl;
	else cout << " a/b = Error" << endl;
pow (a,b,c);
if (*c == 0) cout <<"a^b = " << pow(a,b,c) << endl;
	else cout << " a^b = Error" << endl;
sq(a,c);	
if (*c == 0) cout <<"sqrt a = " << sq(a,c) << endl;
	else cout << " sqrt a = Error" << endl;
_getch();
return 0;
 }