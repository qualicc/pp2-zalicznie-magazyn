#include <iostream>
#include <string>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <bits/stdc++.h>
#include <fstream>
using namespace std;

struct Produkt
        {
            char name[20];
            int id;
            char type[20];
            int count;
            float price;
        };
         

void losuj(Produkt magazyn[], int liczba_danych);							//od 1 do liczba_danych
void generujPosortowane(Produkt magazyn[], int liczba_danych);			//od 1 do liczba_danych
void generujOdwrotniePosortowane(Produkt magazyn[], int liczba_danych);	//od 1 do liczba_danych
void dodajTowar(Produkt magazyn[], Produkt nowy, int *liczba_danych);		//dopisuje na koniec
void wypisz(Produkt towary[], int ile);									//od 1 do liczba_danych
float sumaWartosci(Produkt magazyn[], int liczba_danych);
float sredniaCena(Produkt magazyn[], int liczba_danych);
void wyszukajCena(Produkt magazyn[], int ile_danych, Produkt wyszukane[], int *ile_wyszukanych, float min, float max); //szukany przedział <min,max>
void minmaxCena(Produkt magazyn[], int liczba_danych, float *min, float *max);
void przecena(Produkt magazyn[], int liczba_danych, float procent);
void selectionsort(Produkt magazyn[], int liczba_danych);
bool minMaxVal(float min, float max);
void createSQL(Produkt towary[], int ile);
main()
{    
    Produkt *magazyn, *wyszukane, nowy;
	float suma, srednia, minimum, maksimum, procent;	
    int rozmiar=0, liczba_danych=0, liczba_wyszukanych=0;
	char znak;
	cout<<"OBSLUGA MAGAZYNU ver. 1"<<endl<<endl;
	srand(time(NULL));
    cout<<"Jaki rozmiar magazynu? ";
    do
    {
        cin>>rozmiar;
        if(rozmiar > 0)
        {
            magazyn  =new Produkt[rozmiar+1];
            wyszukane=new Produkt[rozmiar+1];
            liczba_danych=0;
            liczba_wyszukanych=0; 
            break;
        }
        else
        {
            cout<<"Zły rozmiar";
        }					 
    }while (true);
	
// To do list
// 2. losowe generowanie --
// 3. losowe generowanie sortowane --
// 4. loswoe generowanie odwrotnie sortowane --
// 5. dopisywanie towaru --
// 6. listowanie towaru --
// 7. suma wartości całego magazynu --
// 8. srednia cena towaru --
// 9. min i max cena --
// 10. zmiana ceny o % --
// 11. wyszukanie przedziału cen --
// 12. sortowanie wg cen -- 
// 13. sortowanie wg nazwy
// 14. czytanie z pliku sql
// 15. zapis do sql
// 16. readme
// 17. exoit
	do
	{
	    fflush(stdin);
		cout<<endl<<endl<<"NACISNIJ ENTER BY KONTYNUOWAĆ"<<endl;
		getchar();
	    system("CLS");
		cout<<"1. Losowanie calego magazynu"<<endl; //rep
	    cout<<"2. Generowanie calego magazynu posortowanego by ID"<<endl;//rep
	   	cout<<"3. Generowanie calego magazynu odwrotnie posortowanego by ID"<<endl;//rep
	   	cout<<"4. Dopisanie towaru do magazynu"<<endl; //rep
	    cout<<"5. Wypisanie elementow tablicy"<<endl; //rep
	    cout<<"6. Suma wartosci w calym magazynie"<<endl; //rep
	    cout<<"7. Srednia cena towaru"<<endl; //rep
	    cout<<"8. Maksymalna i minimalna cena"<<endl; //rep
		cout<<"9. Zmiana ceny o podany procent"<<endl; //rep
		cout<<"a. Wyszukiwanie wedlug przedzialu cen"<<endl; //rep
		cout<<"b. Sortowanie rosnace wedlug cen- proste wybieranie"<<endl; //rep
		cout<<"c. Sortowanie rosnace wedliug nazwy";
		cout<<"d. Zapis do sql";
		cout<<"e. Czytanie z sql";
		cout<<"f. README";
	    cout<<"ESC. ---KONIEC PRACY---"<<endl<<endl;
	    znak=getch();
	    switch (znak)
	    {
	      	case '1': 	cout<<"Ile danych losowac? ";
	      				do
                        {
                            cin>>liczba_danych;
                            if (liczba_danych <=0)
                            {
                                cout<<"Zła wartość";
                            }
                            
                        } while (liczba_danych <=0);
			  			losuj(magazyn, liczba_danych);
	      	            cout<<endl<<"Wylosowano"<<endl;
	      	            break;
			case '2': 	cout<<"Ile danych generowac? ";
	      				do
                        {
                            cin>>liczba_danych;
                            if (liczba_danych <=0)
                            {
                                cout<<"Zła wartość";
                            }
                            
                        } while (liczba_danych <=0);

			  			losuj(magazyn, liczba_danych);
	      	            cout<<endl<<"Wygenerowano"<<endl;
	      	            break;	    
	      	case '3': 	cout<<"Ile danych generowac? ";
	      				cin>>liczba_danych;
			  			generujOdwrotniePosortowane(magazyn, liczba_danych);
			  			cout<<endl<<"Wygenerowano"<<endl;
	                    break;
	        case '4':	cout<<"Nazwa: ";
	        			fflush(stdin);
						gets(nowy.name);
						cout<<"Rodzaj: ";
	        			fflush(stdin);
						gets(nowy.type);     
						cout<<"Cena: ";
						cin>>nowy.price;
						cout<<"Sztuk: ";
						cin>>nowy.count;
						cin.ignore();   
						dodajTowar(magazyn, nowy, &liczba_danych);    
						cout<<"Dopisany"<<endl;     
						break;
	        case '5':	wypisz(magazyn, liczba_danych);
	        			cout<<endl;
	        			break;
	        case '6': 	cout<<endl<<"Suma wartosci magazynu= "<<sumaWartosci(magazyn, liczba_danych)<<endl<<endl;  
			            break;  
			case '7':	cout<<"Srednia cena= "<<sredniaCena(magazyn, liczba_danych)<<endl<<endl;       
			        	break;
			case '8': 	minmaxCena(magazyn, liczba_danych, &minimum, &maksimum);
				        cout<<"Cena minimalna="<<minimum<<"  Cena maksymalna="<<maksimum<<endl;
				        break;
			case '9': 	cout<<"O jaki procent przeceniasz? (ujemny obniza) ";
						cin>>procent;
						przecena(magazyn, liczba_danych, procent);
						cout<<"Przecenione."<<endl;
			        	break;
			case 'a':	cout<<"Podaj przedzial szukany."<<endl;
						do
						{
							cout<<"od wartosci: ";
							cin>>minimum;					
							cout<<"do wartosci: ";
							cin>>maksimum;
						} while (minMaxVal(minimum, maksimum));
						getchar();
						wyszukajCena(magazyn, liczba_danych, wyszukane, &liczba_wyszukanych, minimum, maksimum);
						wypisz(wyszukane, liczba_wyszukanych);
						cout<<endl;
						break;
			case 'b':	selectionsort(magazyn, liczba_danych);
						cout<<"POSORTOWANO"<<endl;
						break;
			case 27: 	cout<<"DO WIDZENIA"<<endl;
			        	break;
			default : 	cout<<"ZLY WYBOR!"<<endl;
        }
	}
    while (znak!=27);
    
    cout<<endl<<"NACISNIJ KLAWISZ BY ZAKONCZYC"<<endl;
    delete [] magazyn;
    delete [] wyszukane;
	system("PAUSE>>NULL");    
}

void losuj(Produkt magazyn[], int liczba_danych)
{
 	char naz[20],typ[20], numer[13];
 	for (int i=1; i<=liczba_danych; i++)  
 	{
        int type = rand()%5+1;//1.cpu2.gpu3.ram4.mb5.power
        switch (type)
        {
            case 1:
                strcpy(typ, "CPU");
            break;
            case 2:
                strcpy(typ, "GPU");
            break;
            case 3:
                strcpy(typ, "RAM");
            break;
            case 4:
                strcpy(typ, "MotherBoard");
            break;
            case 5:
                strcpy(typ, "Power Supply");
            break;
        }
        strcpy(magazyn[i].type, typ);
        strcpy(naz, "Towar");
		itoa(i, numer, 10);
		strcat(naz, numer);
        strcpy(magazyn[i].name, naz);
        magazyn[i].id = i;
		magazyn[i].price=(rand()%100001) /100;		
        magazyn[i].count=rand()%101;
    }
}
        
void generujOdwrotniePosortowane(Produkt magazyn[], int liczba_danych)
{
	char naz[20], typ[20], numer[13];	
    int type = rand()%5+1;//1.cpu2.gpu3.ram4.mb5.power
    switch (type)
        {
            case 1:
                strcpy(typ, "CPU");
            break;
            case 2:
                strcpy(typ, "GPU");
            break;
            case 3:
                strcpy(typ, "RAM");
            break;
            case 4:
                strcpy(typ, "MotherBoard");
            break;
            case 5:
                strcpy(typ, "Power Supply");
            break;
        }
        
	for (int i=liczba_danych; i>=1; i--)  
 	{   
        strcpy(magazyn[i].type, typ);
 		strcpy(naz, "Towar");
        strcpy(magazyn[i].name, naz);
        magazyn[i].id = i;
		magazyn[i].price=liczba_danych*20 - i*10.11;	
        magazyn[i].count=liczba_danych - i + 1;
    }
}

void dodajTowar(Produkt magazyn[], Produkt nowy, int *liczba_danych)
{
	(*liczba_danych)++;
	nowy.id = (*liczba_danych);
	magazyn[*liczba_danych]=nowy;
}
	
	
void wypisz(Produkt towary[], int ile)	
{
	for (int i=1; i<=ile; i++)    //od indeksu 1 do liczba_danych
   		 cout<<"ID: "<<i<<" Nazwa: "<<towary[i].name<<" Rodzaj: "<< towary[i].type<<"\tCena:\t"<<towary[i].price
		<<"\tIlosc:\t"<<towary[i].count<<endl;
}
    
float sumaWartosci(Produkt magazyn[], int liczba_danych)
{
	int i;
	float suma=0;
	for (i=1; i<=liczba_danych; i++)
	  suma+=magazyn[i].price * magazyn[i].count;
	return suma;
}
	
float sredniaCena(Produkt magazyn[], int liczba_danych)
{
	float srednia, suma=0;
	for (int i=1; i<=liczba_danych; i++)
	  suma+=magazyn[i].price;
	srednia=suma/liczba_danych;
	return srednia;
}
	

void minmaxCena(Produkt magazyn[], int liczba_danych, float *min, float *max)
{
	*min=magazyn[1].price;
	*max=magazyn[1].price;
	for (int i=2; i<=liczba_danych; i++)
    	if (magazyn[i].price<*min)
		  *min=magazyn[i].price;  
		else
			if (magazyn[i].price>*max)
			  *max=magazyn[i].price;     
}

void wyszukajCena(Produkt magazyn[], int ile_danych, Produkt wyszukane[], int *ile_wyszukanych, float min, float max) //szukany przedział <min,max>
{
	int i;
	*ile_wyszukanych=0;	
	for (i=0; i<ile_danych; i++)
		if (magazyn[i].price>=min && magazyn[i].price<=max)
		{
			(*ile_wyszukanych)++;
			wyszukane[*ile_wyszukanych]=magazyn[i];
		}

}

void przecena(Produkt magazyn[], int liczba_danych, float procent)	//przecena wszystkich towarów
{
	for (int i=1; i<=liczba_danych; i++)
		magazyn[i].price+=magazyn[i].price * procent/100;
}


void selectionsort(Produkt magazyn[], int liczba_danych)
{	
	Produkt min;
	int indeks, i, nr;
	for (nr=1; nr<liczba_danych; nr++)
	{
		min=magazyn[nr];
		indeks=nr;
		for (i=nr+1; i<=liczba_danych; i++)		//UWAGA: elementy gromadzimy od indeksu 1
			if (magazyn[i].price < min.price)	
				{
					min=magazyn[i];
					indeks=i;
				}
		magazyn[indeks]=magazyn[nr];
		magazyn[nr]=min;
	}
}

bool minMaxVal(float min, float max)
{
	if (min < max)
	{
		return false;
	}
	else
	{
		return true;
	}
		
}

void createSQL(Produkt towary[], int ile)
{
	ofstream newFileWDB("yourwarehouse.sql");

	newFileWDB<<"CREATE TABLE 'yourwarehouse' (
		'ID' int(11) NOT NULL,
		'name' varchar(20) COLLATE utf8_polish_ci NOT NULL,
		'type' varchar(20) COLLATE utf8_polish_ci NOT NULL,
		'count' int(11) NOT NULL,
		'price' float NOT NULL
		) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_polish_ci;

		ALTER TABLE `yourwarehouse`
		ADD PRIMARY KEY (`ID`);";
}
	