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

void menu(); //0
int deklasracjaWielkosci() //1
// To do list
// 1. dynamiczny rozmiar X
// 2. losowe generowanie
// 3. losowe generowanie sortowane
// 4. loswoe generowanie odwrotnie sortowane
// 5. dopisywanie towaru
// 6. listowanie towaru
// 7. suma wartości całego magazynu
// 8. srednia cena towaru
// 9. min i max cena
// 10. zmiana ceny o %
// 11. wyszukanie przedziału cen
// 12. sortowanie wg cen
// 13. sortowanie wg nazwy
// 14. czytanie z pliku xml
// 15. zapis do xml
// 16. readme
// 17. exoit
//start
class produkt
{
public:
    string name;
    int id;
    int type;
    int count;
    float price;
};


int main()
{
    //settings
    srand(time(NULL));//random
    //varliables
    

    //start
    menu();
    return 0;
}
void menu()
{
    //menu
    cout<<"Magazyn części komputerowych\n";
    cout<<"1. Określ rozmiar magazynu\n";
    cout<<"2. Losowa zawartość magazynu\n";
    cout<<"3. Losowa zawartość posortowana wg. ID\n";
    cout<<"4. Losowa zawartość odwrotnie posortowana wg. ID\n";
    cout<<"5. Dopisywanie towaru\n";
    cout<<"6. Listowanie magazynu\n";
    cout<<"7. Suma wartości magazynu\n";
    cout<<"8. Średnia wartość całości\n";
    cout<<"9. Najwyższa i najniższa cena\n";
    cout<<"10. Zmiana ceny o %\n";
    cout<<"11. Wyszukanie wg. ceny przedział\n";
    cout<<"12. Sortowanie wg. ceny\n";
    cout<<"13. Sortowanie wg. Nazwy\n";
    cout<<"14. Import .xml\n";
    cout<<"15. Export .xml\n";
    cout<<"16. Read Me\n";
    cout<<"17. Exit\n";
    
    int magazyn[];
    int nextMove;
    int lenght;
    cin>>nextMove;

    switch (nextMove)
    {
    case 1:
        magazyn[] = deklasracjaWielkosci();
        lenght = my_sizeof(magazyn)/my_sizeof(magazyn[0])
        break;
    case 2:
        /* code */
        break;
    case 3:
        /* code */
        break;
    case 4:
        /* code */
        break;
    case 5:
        /* code */
        break;
    case 6:
        /* code */
        break;
    case 7:
        /* code */
        break;
    case 8:
        /* code */
        break;
    case 9:
        /* code */
        break;
    case 10:
        /* code */
        break;
    case 11:
        /* code */
        break;
    case 12:
        /* code */
        break;
    case 13:
        /* code */
        break;
    case 14:
        /* code */
        break;
    case 15:
        /* code */
        break;
    case 16:
        /* code */
        break;
    case 17:
        /* code */
        break;
    }
    //return 0;
}
int deklasracjaWielkosci()
{
    cout<<"\nPodaj wielkość magazynu:\n";
    int wielkosc;
    cin>>wielkosc;
    if(wielkość > 0)
    {
        int magazyn[wielkosc];
        return magazyn[]; 
    }else{
        cout<<"\nzła wielkość\n";
        int magazyn[] = deklasracjaWielkosci(int magazyn[]);
        return magazyn[];
    }
    
}
int wypelnianielosowe(int magazyn[])
{

}