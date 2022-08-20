/*
Przykładowy program do obsługi danych magazynowych.
Wersja 1 - do rozwinięcia.
Tablica dynamiczna powiększona o 1 element,
gdzyż dane gromadzimy od indeku 1 (z uwagi na algorytm
sortowania przez wstawianie z wartownikiem i ułatwienia
w komunikacji interfejsowej)
*/

#include <conio.h>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string.h>
#include <stdio.h>

struct towar
         {
           char nazwa[20];
           float cena;
           int sztuk;
         };
         
using namespace std;

void losuj(towar magazyn[], int liczba_danych);							//od 1 do liczba_danych
void generujPosortowane(towar magazyn[], int liczba_danych);			//od 1 do liczba_danych
void generujOdwrotniePosortowane(towar magazyn[], int liczba_danych);	//od 1 do liczba_danych
void dodajTowar(towar magazyn[], towar nowy, int *liczba_danych);		//dopisuje na koniec
void wypisz(towar towary[], int ile);									//od 1 do liczba_danych
float sumaWartosci(towar magazyn[], int liczba_danych);
float sredniaCena(towar magazyn[], int liczba_danych);
void wyszukajCena(towar magazyn[], int ile_danych, towar wyszukane[], int *ile_wyszukanych, float min, float max); //szukany przedział <min,max>
void minmaxCena(towar magazyn[], int liczba_danych, float *min, float *max);
void przecena(towar magazyn[], int liczba_danych, float procent);
void selectionsort(towar magazyn[], int liczba_danych);
main()
{    
    towar *magazyn, *wyszukane, nowy;
	float suma, srednia, minimum, maksimum, procent;	
    int rozmiar=0, liczba_danych=0, liczba_wyszukanych=0;
	char znak;
	cout<<"OBSLUGA MAGAZYNU ver. 1"<<endl<<endl;
	srand(time(NULL));
	do
	{
	    fflush(stdin);
		cout<<endl<<endl<<"NACISNIJ ENTER"<<endl;
		getchar();
	    system("CLS");
		cout<<"0. Dynamiczne tworzenie magazynu"<<endl;
		cout<<"1. Losowanie calego magazynu"<<endl;
	    cout<<"2. Generowanie calego magazynu posortowanego"<<endl;
	   	cout<<"3. Generowanie calego magazynu odwrotnie posortowanego"<<endl;
	   	cout<<"4. Dopisanie towaru do magazynu"<<endl;
	    cout<<"5. Wypisanie elementow tablicy"<<endl;
	    cout<<"6. Suma wartosci w calym magazynie"<<endl;
	    cout<<"7. Srednia cena towaru"<<endl;
	    cout<<"8. Maksymalna i minimalna cena"<<endl;
		cout<<"9. Zmiana ceny o podany procent"<<endl;
		cout<<"a. Wyszukiwanie wedlug przedzialu cen"<<endl;
		cout<<"b. Sortowanie rosnace wedlug cen- proste wybieranie"<<endl;
	    cout<<"ESC. ---KONIEC PRACY---"<<endl<<endl;
	    znak=getch();
	    switch (znak)
	    {
	    	case '0': 	cout<<"Jaki rozmiar magazynu? ";
	    				cin>>rozmiar;					//Brak zabezpieczeń!!!
	    				magazyn  =new towar[rozmiar+1];	//POWIĘKSZONY O 1 - patrz górny komentarz
	    				wyszukane=new towar[rozmiar+1];	//Przygotowanie tablicy na towary wyszukane
	    				liczba_danych=0;
	    				liczba_wyszukanych=0;
	    				break;
	      	case '1': 	cout<<"Ile danych losowac? ";
	      				cin>>liczba_danych;				//Brak zabezpieczeń!!!
			  			losuj(magazyn, liczba_danych);
	      	            cout<<endl<<"Wylosowano"<<endl;
	      	            break;
			case '2': 	cout<<"Ile danych generowac? ";
	      				cin>>liczba_danych;
						generujPosortowane(magazyn, liczba_danych);
						cout<<endl;
	      	            cout<<endl<<"Wygenerowano"<<endl;
	      	            break;	    
	      	case '3': 	cout<<"Ile danych generowac? ";
	      				cin>>liczba_danych;
			  			generujOdwrotniePosortowane(magazyn, liczba_danych);
			  			cout<<endl<<"Wygenerowano"<<endl;
	                    break;
	        case '4':	cout<<"Nazwa: ";
	        			fflush(stdin);
						gets(nowy.nazwa);   
						cout<<"Cena: ";
						cin>>nowy.cena;
						cout<<"Sztuk: ";
						cin>>nowy.sztuk;
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
			case 'a':	cout<<"Podaj przedzial szukany."<<endl<<"od wartosci: ";
						cin>>minimum;					//Bez zabezpieczeń!
						cout<<"do wartosci: ";
						cin>>maksimum;
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

void losuj(towar magazyn[], int liczba_danych)
{
 	char naz[20], numer[13];
	//srand(time(NULL));			//gdyby uczynić funkcję niezależną od programu srand powinien tu być
 	for (int i=1; i<=liczba_danych; i++)  
 	{
        strcpy(naz, "Towar");
		itoa(i, numer, 10);
		strcat(naz, numer);
        strcpy(magazyn[i].nazwa, naz);
		magazyn[i].cena=(rand()%100001) /100;		
        magazyn[i].sztuk=rand()%101;
    }
}

void generujPosortowane(towar magazyn[], int liczba_danych)
{
	char naz[20], numer[13];
	for (int i=1; i<=liczba_danych; i++)  
 	{
 		strcpy(naz, "Towar");
		itoa(i, numer, 10);
		strcat(naz, numer);
        strcpy(magazyn[i].nazwa, naz);
		magazyn[i].cena=i*10.11;		
        magazyn[i].sztuk=i;
    }
}
        
void generujOdwrotniePosortowane(towar magazyn[], int liczba_danych)
{
	char naz[20], numer[13];	
	for (int i=1; i<=liczba_danych; i++)  
 	{
 		strcpy(naz, "Towar");
		itoa(i, numer, 10);		//Nazwy numeruję j.w. czyli rosnąco
		strcat(naz, numer);
        strcpy(magazyn[i].nazwa, naz);
		magazyn[i].cena=liczba_danych*20 - i*10.11;	
        magazyn[i].sztuk=liczba_danych - i + 1;
    }
}

void dodajTowar(towar magazyn[], towar nowy, int *liczba_danych)
{
	(*liczba_danych)++;
	magazyn[*liczba_danych]=nowy;
}
	
	
void wypisz(towar towary[], int ile)	
{
	for (int i=1; i<=ile; i++)    //od indeksu 1 do liczba_danych
   		 cout<<"Element "<<i<<" to "<<towary[i].nazwa<<"\t\t"<<towary[i].cena
		<<"\t"<<towary[i].sztuk<<endl;
}
    
float sumaWartosci(towar magazyn[], int liczba_danych)
{
	int i;
	float suma=0;
	for (i=1; i<=liczba_danych; i++)
	  suma+=magazyn[i].cena * magazyn[i].sztuk;
	return suma;
}
	
float sredniaCena(towar magazyn[], int liczba_danych)
{
	float srednia, suma=0;
	for (int i=1; i<=liczba_danych; i++)
	  suma+=magazyn[i].cena;
	srednia=suma/liczba_danych;
	return srednia;
}
	

void minmaxCena(towar magazyn[], int liczba_danych, float *min, float *max)
{
	*min=magazyn[1].cena;
	*max=magazyn[1].cena;
	for (int i=2; i<=liczba_danych; i++)
    	if (magazyn[i].cena<*min)
		  *min=magazyn[i].cena;  
		else
			if (magazyn[i].cena>*max)
			  *max=magazyn[i].cena;     
}

void wyszukajCena(towar magazyn[], int ile_danych, towar wyszukane[], int *ile_wyszukanych, float min, float max) //szukany przedział <min,max>
{
	int i;
	*ile_wyszukanych=0;	
	for (i=0; i<ile_danych; i++)
		if (magazyn[i].cena>=min && magazyn[i].cena<=max)
		{
			(*ile_wyszukanych)++;
			wyszukane[*ile_wyszukanych]=magazyn[i];
		}

}

void przecena(towar magazyn[], int liczba_danych, float procent)	//przecena wszystkich towarów
{
	for (int i=1; i<=liczba_danych; i++)
		magazyn[i].cena+=magazyn[i].cena * procent/100;
}


void selectionsort(towar magazyn[], int liczba_danych)
{	
	towar min;
	int indeks, i, nr;
	for (nr=1; nr<liczba_danych; nr++)
	{
		min=magazyn[nr];
		indeks=nr;
		for (i=nr+1; i<=liczba_danych; i++)		//UWAGA: elementy gromadzimy od indeksu 1
			if (magazyn[i].cena < min.cena)	
				{
					min=magazyn[i];
					indeks=i;
				}
		magazyn[indeks]=magazyn[nr];
		magazyn[nr]=min;
	}
}


	