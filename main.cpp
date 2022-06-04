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

int * ustawianieWielkosciMag();
void menu(); //0
int wypelnianielosowe(int tab[], int len,bool gen); //2
float generateFloat(float min, float max);//2.3
int generateInt(int min, int max);//2.4
void append(int tab[],int len);
void read(int tab[],int len);
// To do list
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


int main()
{
    //settings
    srand(time(NULL));//random
    //varliables
    

    //start
    int lenght, magazyn[lenght];
    do
    {   
        
        cout<<"\n\nPodaj wielkość magazynu:\n";
        cin>>lenght;
        if(lenght>0){
            lenght++;
            magazyn[lenght];
            magazyn[0] = lenght;
        }else{
            cout<<"\nzła wielkość\n";
        } 
    }while(lenght < 0);
    //int * magZnacznik;
    //magZnacznik = * magazyn;
    int nextMove;
    do
    {
        menu(); //wyświetlanie menu  
        cin>>nextMove;

        switch (nextMove)
        {
        case 1:
            {   
                
                wypelnianielosowe(magazyn, lenght,false);// losowe generowanie
                cout<<"\nwygenerowano poprawnie\n";
                cout<<magazyn[0]<<endl;
                //cout<<magazyn[1].id;
            }
            break;
        case 2:
            {
                wypelnianielosowe(magazyn, lenght,false);// losowe generowanie by id
                cout<<"\nwygenerowano poprawnie";
            } 
            break;
        case 3:
            {
                //wypelnianielosoweOdw(lenght, true); // losowe generowane odwrócone by id 
            } 
            break;
        case 4:
            {
                //append(magazyn, lenght);
            } 
            break;
        case 5:
            {
                for (int i = 1; i < lenght; i++)
                {
                   // cout<<"ID."<<tab[i].id<<" Nazwa."<<tab[i].name<<" Rodzaj:"<<tab[i].type<<" Cena:"<<tab[i].price<<" Ilość:"<<tab[i].count<<endl;
                }
            }
            break;
        case 6:
            {
               
            }
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
    } while (nextMove != 16);
    
    
    
    
    return 0;
}
void menu()
{
    //menu
    cout<<"Magazyn części komputerowych\n";
    cout<<"1. Losowa zawartość magazynu\n";
    cout<<"2. Losowa zawartość posortowana wg. ID\n";
    cout<<"3. Losowa zawartość odwrotnie posortowana wg. ID\n";
    cout<<"4. Dopisywanie towaru\n";
    cout<<"5. Listowanie magazynu\n";
    cout<<"6. Suma wartości magazynu\n";
    cout<<"7. Średnia wartość całości\n";
    cout<<"8. Najwyższa i najniższa cena\n";
    cout<<"9. Zmiana ceny o %\n";
    cout<<"10. Wyszukanie wg. ceny przedział\n";
    cout<<"11. Sortowanie wg. ceny\n";
    cout<<"12. Sortowanie wg. Nazwy\n";
    cout<<"13. Import .sql\n";
    cout<<"14. Export .sql\n";
    cout<<"15. Read Me\n";
    cout<<"16. Exit\n";
    
    
    //return 0;
}
int * ustawianieWielkosciMag()
{
    int len;
    int * znaTab;
    do
    {   
        
        cout<<"\n\nPodaj wielkość magazynu:\n";
        cin>>len;
        if(len>0){
            len++;
            int tab[len];
            tab[0] = len;
            znaTab = tab;
        }else{
            cout<<"\nzła wielkość\n";
        } 
    }while(len < 0);
    return znaTab;
}

int wypelnianielosowe(int tab[], int len,bool gen)
{
    int slen = len;
    for(int i = 1; i >= len; i++)
    {   
        Produkt tab[i];
        int type = rand()%5+1;//1.cpu2.gpu3.ram4.mb5.power
        if(gen == false){
          tab[i].id = i;  
        }else{
            slen--;
            tab[i].id = slen;  
        }
        
        tab[i].count = generateInt(10,1000); 
        switch (type)
        {
        case 1:
            {
                tab[i].type = "CPU";
                int cpuName = rand()%2+1; //1.intel2.amd
                switch (cpuName)
                {
                    case 1:
                        {
                            tab[i].name = "Intel";
                        }
                        break;
                    case 2:
                        {
                            tab[i].name = "AMD";
                        }
                        break;    
                }
                tab[i].price = generateFloat(100,400);              
            }
            break;
        case 2:
            {
                tab[i].type = "GPU";
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
                                    tab[i].name = "Geforce GTX";
                                }
                                    break;
                                case 2:
                                {
                                    tab[i].name = "Geforce RTX";
                                }
                                    break;
                            }    
                        }
                        break;
                    case 2:
                        {
                            tab[i].name = "AMD Radeon";
                        }  
                        break;
                tab[i].price = generateFloat(150,2000);        
                }
            }
            break;
        case 3:
            {
                tab[i].type = "RAM";
                int sizeRam = rand()%4+1; //1.4gb2.8gb3.16gb4.32gb
                switch (sizeRam)
                {
                    case 1:
                    {
                        tab[i].name = "RAM 4GB";
                    } 
                        break;
                    case 2:
                    {
                        tab[i].name = "RAM 8GB";
                    }  
                        break;
                    case 3:
                    {
                        tab[i].name = "RAM 16GB";
                    }  
                        break;
                    case 4:
                    {
                        tab[i].name = "RAM 32GB";
                    }
                        break;
                }
                tab[i].price = generateFloat(125,300);
            } 
            break;
        case 4:
            {
                tab[i].type = "Motherboard";
                int mbName = rand()%5+1; //1.socket17002.12Moszynski003.11514.am45.2066
                switch (mbName)
                {
                    case 1:
                    {
                        tab[i].name = "Socket 1700";
                    }
                        break;
                    case 2:
                    {
                        tab[i].name = "Socket 1200";
                    }
                        break;
                    case 3:
                    {
                        tab[i].name = "Socket 1151";
                    }
                        break;
                    case 4:
                    {
                        tab[i].name = "Socket AM4";
                    }
                        break;
                    case 5:
                    {
                        tab[i].name = "Socket 2066";
                    }                  
                        break;
                }
                tab[i].price = generateFloat(50,150);
            }
            break;
        case 5:
            {
                tab[i].type = "PowerSupply";
                int psName = rand()%4+1; //1.bequiet2.crosair3.gigabJakubyte4.coolermaster
                switch (psName)
                {
                    case 1:
                    {
                        tab[i].name = "Be quiet!";
                    }
                        break;
                    case 2:
                    {
                        tab[i].name = "Crosair";
                    }
                        break;
                    case 3:
                    {
                        tab[i].name = "Gigabyte";
                    }
                        break;
                    case 4:
                    {
                        tab[i].name = "Cooler Master";
                    }                   
                        break;
                }
                tab[i].price = generateFloat(25,100);
            }
            break;
        }
        cout<<tab[i].name;
    }
    
    return tab;
}

float generateFloat(float min, float max)
{
    float val;
    do
    {
        val = min + static_cast<float>(rand()) * static_cast<float>(max - min) / RAND_MAX;
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
void append(int tab[],int len)
{
    // if (tab[len].empty())
    // {
    //     string name;
    //     int id;
    //     string type;
    //     int count;
    //     float price;
    //     int i = len;

    //     cout<<"podaj dane do wprowadzenia"<<endl<<"nazwa: ";
    //     cin<<name;
    //     cout<<"\n rodzaj: ";
    //     cin<< type;
    //     cout<<"\n Cena: ";
    //     cin<< price;
    //     cout<<"\n Ilość: ";
    //     cin<< count;
    //     do
    //     {
    //         i--;
    //     } while (tab[i].empty());
    //     i++;
    //     tab[i].name = name;
    //     tab[i].id = i;
    //     tab[i].type = type;
    //     tab[i].count = count;
    //     tab[i].price = price;
    //     cout<<"dodane prawidłowo. id produktu = "<< i<<endl;
    // }else{
    //     cout<<"magazyn pełny"<<endl;
    // }
    
}
void read(int tab[],int len)
{
    // for (int i = 1; i < len; i++)
    // {
    //      cout<<"ID."<<tab[i].id<<" Nazwa."<<tab[i].name<<" Rodzaj:"<<tab[i].type<<" Cena:"<<tab[i].price<<" Ilość:"<<tab[i].count<<endl;
    // }
    
}