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

struct product
{
    string name[20];
    int id;
    string type;
    int count;
    float price;
};
         
// To do list
// 1. Określ rozmiar magazynu
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

void generateData(product magazyn[], int len);	
void generujPosortowane(product magazyn[], int countData);		
float generateFloat(float min, float max);
int generateInt(int min, int max);
void generujOdwrotniePosortowane(product magazyn[], int countData);	
void dodajTowar(product magazyn[], product nowy, int *countData);		
void wypisz(product towary[], int ile);									
float sumaWartosci(product magazyn[], int countData);
float sredniaCena(product magazyn[], int countData);
void wyszukajCena(product magazyn[], int ile_danych, product wyszukane[], int *ile_wyszukanych, float min, float max);
void minmaxCena(product magazyn[], int countData, float *min, float *max);
void przecena(product magazyn[], int countData, float procent);
void selectionsort(product magazyn[], int countData);



main()
{   
    srand(time(NULL));
    product *magazyn, *serchedmagazyn, nowy;
	float suma, srednia, minimum, maksimum, procent;	
    int lenght=0, countData=0, countSearched=0;
	int znak;
	cout<<"Magazyn czesci komputerowych"<<endl;
	
	do
	{
	    //fflush(stdin);
	    //system("CLS");


		cout<<"1. Określ rozmiar magazynu"<<endl;
		cout<<"2. losowe generowanie"<<endl;
	    cout<<"3. losowe generowanie sortowane by id"<<endl;
	   	cout<<"4. loswoe generowanie odwrotnie sortowane by id"<<endl;
	   	cout<<"4. Dopisanie towaru do magazynu"<<endl;
	    cout<<"5. Wypisanie elementow magazynlicy"<<endl;
	    cout<<"6. Suma wartosci w calym magazynie"<<endl;
	    cout<<"7. Srednia cena towaru"<<endl;
	    cout<<"8. Maksymalna i minimalna cena"<<endl;
		cout<<"9. Zmiana ceny o podany procent"<<endl;
		cout<<"10. Wyszukiwanie wedlug przedzialu cen"<<endl;
		cout<<"11. Sortowanie rosnace wedlug cen- proste wybieranie"<<endl;
	    cout<<"12. Zakończ"<<endl<<endl;
	    cin>>znak;
	    switch (znak)
	    {
	    	case 1:
                {
                    cout<<"Podaj wielkość?"<<endl;
	    			cin>>lenght;
                    if(lenght >= 0)
                    {
                        cout<<"Rozmiar mniejszy niż 0!!";
                        break;
                    }	
                    lenght++;				
	    			magazyn = new product[lenght];	
	    			serchedmagazyn =new product[lenght];	//potrzebne do funkcji szukania
	    			countData=0;
	    			countSearched=0;
	    			break;
                } 	
	      	case 2:
                {
			  			generateData(magazyn, lenght);
	      	            cout<<endl<<"Wykonano"<<endl;
	      	            break;                    
                }
			case 3: 	cout<<"Ile danych generowac? ";
	      				cin>>countData;
						generujPosortowane(magazyn, countData);
						cout<<endl;
	      	            cout<<endl<<"Wygenerowano"<<endl;
	      	            break;	    
	      	case 4: 	cout<<"Ile danych generowac? ";
	      				cin>>countData;
			  			generujOdwrotniePosortowane(magazyn, countData);
			  			cout<<endl<<"Wygenerowano"<<endl;
	                    break;
	        case 14:	cout<<"Nazwa: ";
	        			cin>>nowy.name  
						cout<<"Cena: ";
						cin>>nowy.price;
						cout<<"Sztuk: ";
						cin>>nowy.count;
                        cout<<"Rodzaj: ";
						cin>>nowy.type;
						cin.ignore();   
						dodajTowar(magazyn, nowy, &countData);    
						cout<<"Dopisany"<<endl;     
						break;
	        case 15:	wypisz(magazyn, countData);
	        			cout<<endl;
	        			break;
	        case 6: 	cout<<endl<<"Suma wartosci magazynu= "<<sumaWartosci(magazyn, countData)<<endl<<endl;  
			            break;  
			case 7:	cout<<"Srednia cena= "<<sredniaCena(magazyn, countData)<<endl<<endl;       
			        	break;
			case 8: 	minmaxCena(magazyn, countData, &minimum, &maksimum);
				        cout<<"Cena minimalna="<<minimum<<"  Cena maksymalna="<<maksimum<<endl;
				        break;
			case 9: 	cout<<"O jaki procent przeceniasz? (ujemny obniza) ";
						cin>>procent;
						przecena(magazyn, countData, procent);
						cout<<"Przecenione."<<endl;
			        	break;
			case 10:
                {
                    cout<<"Podaj przedzial szukany."<<endl<<"od wartosci: ";
					cin>>minimum;					//Bez zabezpieczeń!
					cout<<"do wartosci: ";
					cin>>maksimum;
					getchar();
					wyszukajCena(magazyn, countData, serchedmagazyn, &countSearched, minimum, maksimum);
					wypisz(serchedmagazyn, countSearched);
					cout<<endl;
					break;
                }
			case 157:                	
                {
                    selectionsort(magazyn, countData);
                    cout<<"POSORTOWANO"<<endl;
					break;
                }		
			case 12:
                {
                    break;
                }	
			default :
                {
                    cout<<"Brak opcji"<<endl;
                } 	
        }
	}
    while (znak!=12);
    
    cout<<endl<<"NACISNIJ KLAWISZ BY ZAKONCZYC"<<endl;
    delete [] magazyn;
    delete [] serchedmagazyn;
	system("PAUSE>>NULL");    
}

void generateData(product magazyn[], int len)
{
 	// char naz[20], numer[13];
	// //srand(time(NULL));			//gdyby uczynić funkcję niezależną od programu srand powinien tu być
 	// for (int i=1; i<=countData; i++)  
 	// {
    //     strcpy(naz, "Towar");
	// 	itoa(i, numer, 10);
	// 	strcat(naz, numer);
    //     strcpy(magazyn[i].name, naz);
	// 	magazyn[i].price=(rand()%100001) /100;		
    //     magazyn[i].count=rand()%101;
    // }

    int slen = len;
    for(int i = 1; i <= len; i++)
    {   
        //produkt magazyn[i];
        int type = rand()%5+1;//1.cpu2.gpu3.ram4.mb5.power
        //if(gen == false){
          magazyn[i].id = i;  
        // }else{
        //     slen--;
        //     magazyn[i].id = slen;  
        // }
        
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
                int mbName = rand()%5+1; //1.socket17002.12Moszynski003.11514.am45.2066
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
                int psName = rand()%4+1; //1.bequiet2.crosair3.gigabJakubyte4.coolermaster
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
        cout<<magazyn[i].name;
    }
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

void generujPosortowane(product magazyn[], int countData)
{
	char naz[20], numer[13];
	for (int i=1; i<=countData; i++)  
 	{
 		strcpy(naz, "Towar");
		itoa(i, numer, 10);
		strcat(naz, numer);
        strcpy(magazyn[i].name, naz);
		magazyn[i].price=i*10.11;		
        magazyn[i].count=i;
    }
}
        
void generujOdwrotniePosortowane(product magazyn[], int countData)
{
	char naz[20], numer[13];	
	for (int i=1; i<=countData; i++)  
 	{
 		strcpy(naz, "Towar");
		itoa(i, numer, 10);		//Nazwy numeruję j.w. czyli rosnąco
		strcat(naz, numer);
        strcpy(magazyn[i].name, naz);
		magazyn[i].price=countData*20 - i*10.11;	
        magazyn[i].count=countData - i + 1;
    }
}

void dodajTowar(product magazyn[], product nowy, int *countData)
{
	(*countData)++;
	magazyn[*countData]=nowy;
}
	
	
void wypisz(product towary[], int ile)	
{
	for (int i=1; i<=ile; i++)    //od indeksu 1 do countData
   		 cout<<"Element "<<i<<" to "<<towary[i].name<<"\t\t"<<towary[i].price
		<<"\t"<<towary[i].count<<endl;
}
    
float sumaWartosci(product magazyn[], int countData)
{
	int i;
	float suma=0;
	for (i=1; i<=countData; i++)
	  suma+=magazyn[i].price * magazyn[i].count;
	return suma;
}
	
float sredniaCena(product magazyn[], int countData)
{
	float srednia, suma=0;
	for (int i=1; i<=countData; i++)
	  suma+=magazyn[i].price;
	srednia=suma/countData;
	return srednia;
}
	

void minmaxCena(product magazyn[], int countData, float *min, float *max)
{
	*min=magazyn[1].price;
	*max=magazyn[1].price;
	for (int i=2; i<=countData; i++)
    	if (magazyn[i].price<*min)
		  *min=magazyn[i].price;  
		else
			if (magazyn[i].price>*max)
			  *max=magazyn[i].price;     
}

void wyszukajCena(product magazyn[], int ile_danych, product wyszukane[], int *ile_wyszukanych, float min, float max) //szukany przedział <min,max>
{
	int i;
	*ile_wyszukanych=0;	
	for (i=0; i<ile_danych; i++)
		if (magazyn[i].price>=min && magazyn[i].price<=max)
		{
			(*ile_wyszukanych)++;
			serchedmagazyn[*ile_wyszukanych]=magazyn[i];
		}

}

void przecena(product magazyn[], int countData, float procent)	//przecena wszystkich towarów
{
	for (int i=1; i<=countData; i++)
		magazyn[i].price+=magazyn[i].price * procent/100;
}


void selectionsort(product magazyn[], int countData)
{	
	productmin;
	int indeks, i, nr, min;
	for (nr=1; nr<countData; nr++)
	{
		min = magazyn[nr];
		indeks = nr;
		for (i=nr+1; i<=countData; i++)		//UWAGA: elementy gromadzimy od indeksu 1
			if (magazyn[i].price < min.price)	
				{
					min = magazyn[i];
					indeks=i;
				}
		magazyn[indeks] = magazyn[nr];
		magazyn[nr] = min;
	}
}


	