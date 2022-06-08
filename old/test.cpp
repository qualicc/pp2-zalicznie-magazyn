#include <iostream>
#include <string>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;
class Produkt
{
public:
    string name;
    int id;
    string type;
    int count;
    float price;

    public:
        void setData(string nazwa, int ID, string typ, int ilosc, float cena)
        {
            name = nazwa;
            id = ID;
            type = typ;
            count = ilosc;
            price = cena;
        }
        void list()
        {
            cout<<"ID."<<id<<" Nazwa."<<name<<" Rodzaj:"<<type<<" Cena:"<<price<<" Ilość:"<<count<<endl;
        }
};
// function to generate and retrun random numbers.
int * getRandom(int len ) {

    int  r[len];

   // set the seed
   srand( (unsigned)time( NULL ) );
   
   for (int i = 0; i < len; ++i) {
        //Produkt tab[i];
      r[i] = rand();
      cout << r[i] << endl;
   }

   return r;
}

// main function to call above defined function.
int main () {

   // a pointer to an int.
   int *p;
   int leng;
   cin>> leng;
   p = getRandom(leng);
   
   for ( int i = 0; i < 10; i++ ) {
      cout << "*(p + " << i << ") : ";
      cout << *(p + i) << endl;
   }
    Sleep(9999999);
   return 0;
}