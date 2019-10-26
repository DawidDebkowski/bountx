#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <stdlib.h>

using namespace std;

int lslowa;
string linia;
fstream karta1;
string *slowa1, *slowa2;

void open()
{
	karta1.open("karta1.txt");
}

void licz()
{
	getline(karta1, linia);
	while (linia!="")
	{
		lslowa++;
		getline(karta1, linia);
	}
	lslowa/=2;
}

void los()
{
	for (int i=0; i<lslowa; i++)
	{
		getline(karta1, slowa1[i]);
		getline(karta1, slowa2[i]);
	}

	int n=lslowa, los;
	while (n>0)
	{
		srand( time( NULL ) );
		los=rand()%2;	
		if (los==1)
		{	
			srand( time( NULL ) );
			los=rand()%n;
			cout << slowa1[los] << endl;
			while (cin.get() != '\n');
			cout << slowa2[los] << endl;

			slowa1[los].swap(slowa1[n-1]);
			slowa2[los].swap(slowa2[n-1]);	
		}
		else
		{
			srand( time( NULL ) );
			los=rand()%n;
			cout << slowa2[los] << endl;
			while (cin.get() != '\n');
			cout << slowa1[los] << endl;
			
			slowa1[los].swap(slowa1[n-1]);
			slowa2[los].swap(slowa2[n-1]);
		}
		system("CLS");
		n--;
	}

}

int main()
{	
	open();
	licz();
	
	karta1.clear();
	karta1.seekg (0, std::ios::beg);
	
	slowa1 = new string [lslowa];
	slowa2 = new string [lslowa];
	los();

	return 0;
}

