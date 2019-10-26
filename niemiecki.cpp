#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>

using namespace std;

int lslowa;
string linia;
fstream karta1, karta2;

void open()
{
	karta1.open("karta1.txt");
	karta2.open("karta2.txt");
}

void licz()
{
	getline(karta1, linia);
	while (linia!="")
	{
		lslowa++;
		getline(karta1, linia);
	}
}

void los(string *slowa1,string *slowa2)
{
	for (int i=0; i<lslowa; i++)
	{
		getline(karta1, slowa1[i]);
		getline(karta2, slowa2[i]);
	}

	int n=lslowa, los;
	while (n>0)
	{
		karta1.seekg (0);
		karta2.seekg (0);

		srand( time( NULL ) );
		los=rand()%2;
		if (los==1)
		{
			srand( time( NULL ) );
			los=rand()%n;
			cout << slowa1[los] << endl;
			getchar();
			cout << slowa2[los] << endl;
			
			slowa1[los].swap(slowa1[n-1]);
			slowa2[los].swap(slowa2[n-1]);
		}
		else
		{
			srand( time( NULL ) );
			los=rand()%n;
			cout << slowa2[los] << endl;
			getchar();
			cout << slowa1[los] << endl;
			
			slowa1[los].swap(slowa1[n-1]);
			slowa2[los].swap(slowa2[n-1]);
		}
		n--;
	}

}

int main()
{	
	open();
	licz();

	karta1.seekg (0);
	string slowa1[lslowa-1], slowa2[lslowa-1];

	los(slowa1, slowa2);

	return 0;
}

