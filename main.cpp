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
int deklasracjaWielkosci(); //1
int wypelnianielosowe(int magazyn[], int len); //2
float generateFloat(float min, float max);//2.3
int generateInt(int min, int max);//2.4
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
// 14. czytanie z pliku sql
// 15. zapis do sql
// 16. readme
// 17. exoit
//start
class Produkt
{
public:
    string name;
    int id;
    string type;
    int count;
    float price;
};


int main()
{
    //settings
    srand(time(NULL));//random
    //varliables
    

    //start
    menu(); //wyświetlanie menu

    int lenght;
    int magazyn[lenght];
    int nextMove;
    
    cin>>nextMove;

    switch (nextMove)
    {
    case 1:
        do
        {
            cout<<"\n\nPodaj wielkość magazynu:\n";
            cin>>lenght;
            if(lenght>0){
                magazyn[lenght];
            }else{
                cout<<"\nzła wielkość\n";
            } 
        } while(lenght > 0);
        break;
    case 2:
        magazyn = wypelnianielosowe(magazyn , lenght);
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
    cout<<"14. Import .sql\n";
    cout<<"15. Export .sql\n";
    cout<<"16. Read Me\n";
    cout<<"17. Exit\n";
    
    
    //return 0;
}
int deklasracjaWielkosci()
{
    cout<<"\nPodaj wielkość magazynu:\n";
    int wielkosc;
    cin>>wielkosc;
    if(wielkosc > 0)
    {
        int magazyn[wielkosc]
        return magazyn; 
    }else{
        cout<<"\nzła wielkość\n";
        return deklasracjaWielkosci();
    }
    
}
int wypelnianielosowe(int magazyn[], int len)
{
    for(int i = 0; i >= len; i++)
    {
        Produkt magazyn[i];
        int type = rand()%5+1;//1.cpu2.gpu3.ram4.mb5.power
        magazyn[i].id = i;
        magazyn[i].count = generateInt(10,1000); 
        switch (type)
        {
        case 1:
            {
                magazyn[i].type = "CPU";
                int cpuName = rand()%2+1; //1.intel2.amd
                switch (cpuName)
                {
                    case 1:
                        {
                            magazyn[i].name = "Intel";
                        }
                        break;
                    case 2:
                        {
                            magazyn[i].name = "AMD";
                        }
                        break;    
                }
                magazyn[i].price = generateFloat(100,400);              
            }
            break;
        case 2:
            {
                magazyn[i].type = "GPU";
                int gpuName = rand()%2+1; //1.Geforce2.amd
                switch (gpuName)
                {
                    case 1:
                        {
                            int model = rand()%2+1; //1.GTX2.RTX
                            switch (model)
                            {
                                case 1:
                                {
                                    magazyn[i].name = "Geforce GTX";
                                }
                                    break;
                                case 2:
                                {
                                    magazyn[i].name = "Geforce RTX";
                                }
                                    break;
                            }    
                        }
                        break;
                    case 2:
                        {
                            magazyn[i].name = "AMD Radeon";
                        }  
                        break;
                magazyn[i].price = generateFloat(150,2000);        
                }
            }
            break;
        case 3:
            {
                magazyn[i].type = "RAM";
                int sizeRam = rand()%4+1; //1.4gb2.8gb3.16gb4.32gb
                switch (sizeRam)
                {
                    case 1:
                    {
                        magazyn[i].name = "RAM 4GB";
                    } 
                        break;
                    case 2:
                    {
                        magazyn[i].name = "RAM 8GB";
                    }  
                        break;
                    case 3:
                    {
                        magazyn[i].name = "RAM 16GB";
                    }  
                        break;
                    case 4:
                    {
                        magazyn[i].name = "RAM 32GB";
                    }
                        break;
                }
                magazyn[i].price = generateFloat(125,300);
            } 
            break;
        case 4:
            {
                magazyn[i].type = "Motherboard";
                int mbName = rand()%5+1; //1.socket17002.12003.11514.am45.2066
                switch (mbName)
                {
                    case 1:
                    {
                        magazyn[i].name = "Socket 1700";
                    }
                        break;
                    case 2:
                    {
                        magazyn[i].name = "Socket 1200";
                    }
                        break;
                    case 3:
                    {
                        magazyn[i].name = "Socket 1151";
                    }
                        break;
                    case 4:
                    {
                        magazyn[i].name = "Socket AM4";
                    }
                        break;
                    case 5:
                    {
                        magazyn[i].name = "Socket 2066";
                    }                  
                        break;
                }
                magazyn[i].price = generateFloat(50,150);
            }
            break;
        case 5:
            {
                magazyn[i].type = "PowerSupply";
                int psName = rand()%4+1; //1.bequiet2.crosair3.gigabyte4.coolermaster
                switch (psName)
                {
                    case 1:
                    {
                        magazyn[i].name = "Be quiet!";
                    }
                        break;
                    case 2:
                    {
                        magazyn[i].name = "Crosair";
                    }
                        break;
                    case 3:
                    {
                        magazyn[i].name = "Gigabyte";
                    }
                        break;
                    case 4:
                    {
                        magazyn[i].name = "Cooler Master";
                    }                   
                        break;
                }
                magazyn[i].price = generateFloat(25,100);
            }
            break;
        }
    }
    return 0;
}

float generateFloat(float min, float max)
{
    float val;
    do
    {
        val = rand()%max+1;
    }
    while(val < min);
    return val;
}
int generateInt(int min, int max)
{
    int val;
    do
    {
        val = rand()%max+1;
    }
    while(val < min);
    return val;
}