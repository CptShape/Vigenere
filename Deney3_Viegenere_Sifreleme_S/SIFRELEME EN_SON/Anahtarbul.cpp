#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 2000
char * cphrtxt=(char *)malloc(N*sizeof(char)); 
int * find_counter = (int *)malloc(N*sizeof(int));
int * allkeylength = (int *)malloc(N*sizeof(int));


char * BUYUKHARFECEVIR( char * metin )
{
	int i,j;
	i=0;
	j=0;
	char * buyuktext;
	buyuktext=(char *)malloc(N*sizeof(char));

	//Verilen metin büyük harfe cevrilir, 
	//Metindeki bosluklar ile noktalama iþaretleri ihmal edilir.
	for (i=0; i<strlen(metin); i++)
	{
		if (metin[i]>=65 && metin[i]<=90) // Büyük harf ise
		{
			buyuktext[j]=metin[i];
			j++;
		}
		else if (metin[i]>=97 && metin[i]<=122) // Küçük harf ise
		{
			buyuktext[j]=toupper(metin[i]);
			j++;
		}
	}
	buyuktext[j]='\0';

	return buyuktext;
}

//Verilen dizi içerisinde en yüksek aðýrlýða sahip olan elemanýn index numarasýna ait karakteri döndürür
char HARF_GETIR( double * dizi )
{
	int i,j;
	char c;
	i=0;
	j=0;
	double buyuk_sayi;
	buyuk_sayi=dizi[0];

	for(i=1; i<26; i++)
	{
		if (dizi[i]>buyuk_sayi)
		{
			buyuk_sayi=dizi[i];
		}
	}


	//indexi belirle
	for(i=0; i<26; i++)
	{
		if (dizi[i]==buyuk_sayi)
		{
			c=i+'a';
			printf("\n\n\t\tEn buyuk deger = %.4f\n",dizi[i]);
			printf("\t\tBu degerin dizideki indexi = %d\n",i);
			printf("\t\t%d. indexe karsilik gelen karakter = '%c'\n\n",i,c);
		}
	}
	printf("\n\n\t\t");
	system("pause");
	return c;
}





// Anahtar Uzunluðunun bulunmasý
int ANAHTARUZUNLUGU ()
{
	int i,j,k;

	char sfrlmetn[N];

	printf("Sifrelenmis bir metin giriniz...  : ");
	gets(sfrlmetn);

	cphrtxt=BUYUKHARFECEVIR(sfrlmetn);

	//Þifrelenmis metnin kopyasý alýnýr. 
	char cphrtxt_KOPYA[N];
	for (i=0; i<strlen(cphrtxt); i++)
	{
		cphrtxt_KOPYA[i]=cphrtxt[i];
	}
	cphrtxt_KOPYA[i]='\0';

	// Sayacý sýfýrla
	for(i=0; i<strlen(cphrtxt); i++)
    {
		find_counter[i] = 0;
	}
	find_counter[i]='\0';

	//Þifrelenmiþ metnin kaydýrýlabilmesi için en az 2 harfli olmasý gerekir.
	//Sifrelenmis metin ile kopyasýný kaydýrarak karþýlaþtýr.
	if(strlen(cphrtxt)>1)
	{
		for(i=0; i<(strlen(cphrtxt)-1); i++)   // i: Kaydýrma miktarý
		{
			for(j=0; j<(strlen(cphrtxt)-1); j++)
			{
				if (cphrtxt[j]==cphrtxt_KOPYA[i+j+1])
				{
					find_counter[i]++;
				}
			}
		}
		find_counter[i]='\0'; //ilk for dongusu 1'den basliyor

		printf("\n\tSifreli metni \n");
		for(i=0; i<10; i++)
		{
			printf("%3d karakter kaydirirsak %2d eslesme\t",i+1,find_counter[i]);
		}
		printf("\n\n");
		//system("pause");
	}
	else
	{
		printf("\nSifrelenmis metin kaydirilamayacak kadar kucuktur.\n");
	}

    
    //Anahtar uzunluðunun bulunmasý //ilk 10 sayiya bakilir
	int En_buyuk=0;
	int keylength;
	
	for (int i = 0; i < strlen(cphrtxt) - 1; i++) {
        allkeylength[i] = i+1;
    }
	
	
	
	for (i = 0; i < strlen(cphrtxt) - 1; i++) {
    	for (int j = i + 1; j < strlen(cphrtxt) - 1; j++) {
        	if ((find_counter[i] != NULL) && (find_counter[j] != NULL) && (find_counter[i] < find_counter[j])) {
           	 	int temp = find_counter[i];
           	 	int temp2 = allkeylength[i];
            	find_counter[i] = find_counter[j];
            	allkeylength[i] = allkeylength[j];
            	find_counter[j] = temp;
            	allkeylength[j] = temp2;
        	}
    	}
	}
	En_buyuk = find_counter[0];
	keylength = allkeylength[0];
	
	for(i = 0; i < 10; i++)
	{
		printf("%d - %d\n", find_counter[i], allkeylength[i]);
	}
	
	printf("\n\nSayý sec.");
	scanf("%d", &keylength);
	
	
	
	
	
	
	
	
	
	
	
	
	
    printf("\nEn fazla %d eslesme ile anahtar uzunlugu = %d dir.\n\n", En_buyuk, keylength);    

	system("pause");	

	return keylength;
}

int * KARAKTER_SAY(char * Metincik)
{
	int v;
	int * frequency_letters; 
	frequency_letters=(int *)malloc(26*sizeof(int));

	for(v=0; v<26; v++)
	{
		frequency_letters[v] = 0;
	}

	Metincik=BUYUKHARFECEVIR(Metincik);

	for(v=0; v<strlen(Metincik); v++)
	{
			switch (Metincik[v])
			{
				case 'A': 
					frequency_letters[0]++;
					break;
				case 'B': 
					frequency_letters[1]++;
					break;
				case 'C': 
					frequency_letters[2]++;
					break;
				case 'D': 
					frequency_letters[3]++;
					break;
				case 'E': 
					frequency_letters[4]++;
					break;
				case 'F': 
					frequency_letters[5]++;
					break;
				case 'G': 
					frequency_letters[6]++;
					break;
				case 'H': 
					frequency_letters[7]++;
					break;
				case 'I': 
					frequency_letters[8]++;
					break;
				case 'J': 
					frequency_letters[9]++;
					break;
				case 'K': 
					frequency_letters[10]++;
					break;
				case 'L': 
					frequency_letters[11]++;
					break;
				case 'M': 
					frequency_letters[12]++;
					break;
				case 'N': 
					frequency_letters[13]++;
					break;
				case 'O': 
					frequency_letters[14]++;
					break;
				case 'P': 
					frequency_letters[15]++;
					break;
				case 'Q': 
					frequency_letters[16]++;
					break;
				case 'R': 
					frequency_letters[17]++;
					break;
				case 'S': 
					frequency_letters[18]++;
					break;
				case 'T': 
					frequency_letters[19]++;
					break;
				case 'U': 
					frequency_letters[20]++;
					break;
				case 'V': 
					frequency_letters[21]++;
					break;
				case 'W': 
					frequency_letters[22]++;
					break;
				case 'X': 
					frequency_letters[23]++;
					break;
				case 'Y': 
					frequency_letters[24]++;
					break;
				case 'Z': 
					frequency_letters[25]++;
					break;
				default:
					printf("\n\n\t Bir Hata Olustu\n\n");
					break;
			
			}	
	}

	for(v=0; v<26; v++)
	{
		printf("\n\t\t%c harfinin verilen metin parcasi icindeki sayisi : %d",65+v,frequency_letters[v]);	
	}	

	printf("\n");

	//system("pause");

	return frequency_letters;
}


int main()
{
    system("cls");
	printf("\n\n\n\t\t\tViGENERE SiFRELEME SISTEMI ANAHTAR BULMA\n\n\n");	
	printf("********************************************************************************\n");
	
    char anahtar_elemanlari[100];
	int i,j,k,k_index,a;
	char ufak_cipher[N];

	int * V_Matrisi;
	V_Matrisi=(int *)malloc(26*sizeof(int));

	double * W_Matrisi;
	W_Matrisi=(double *)malloc(51*sizeof(double));

	double A_Matrisi[51]={0.015, 0.028, 0.043, 0.127, 0.022, 0.020, 0.061, 0.070, 0.002, 0.008, 0.040, 0.024, 0.067, 0.075, 0.019, 0.001, 0.060, 0.063, 0.091, 0.028, 0.010, 0.023, 0.001, 0.020, 0.001, 0.082, 0.015, 0.028, 0.043, 0.127, 0.022, 0.020, 0.061, 0.070, 0.002, 0.008, 0.040, 0.024, 0.067, 0.075, 0.019, 0.001, 0.060, 0.063, 0.091, 0.028, 0.010, 0.023, 0.001, 0.020, 0.001};
	double kucuk_A_Matrisi[26]={0.082, 0.015, 0.028, 0.043, 0.127, 0.022, 0.020, 0.061, 0.070, 0.002, 0.008, 0.040, 0.024, 0.067, 0.075, 0.019, 0.001, 0.060, 0.063, 0.091, 0.028, 0.010, 0.023, 0.001, 0.020, 0.001};

	double * Carpim_Matrisi;
	Carpim_Matrisi=(double *)malloc(26*sizeof(double));

	double * TOTAL;
	TOTAL=(double *)malloc(26*sizeof(double));

	int anahtar_uzunlugu=ANAHTARUZUNLUGU();

	if (anahtar_uzunlugu==0)
	{
		printf("\nAnahtar uzunlugu sifir(0) olamaz...\n");
	}
	else
	{

		for (a=0; a<anahtar_uzunlugu;a++)
		{
			k_index=0; //Sifreli metnin kucultulmesi
			for (i=0+a ; i<strlen(cphrtxt); i+=anahtar_uzunlugu)
			{
				ufak_cipher[k_index]=cphrtxt[i];
				k_index++;
			}
			ufak_cipher[k_index]='\0';

			printf("\nGirilen Sifreli Metin\n%s",cphrtxt);
			printf("\n\nAnahtarin %d. karakterinin bulunabilmesi icin kullanilan metincik\n%s",a+1,ufak_cipher);

			printf("\n");

			V_Matrisi = KARAKTER_SAY(ufak_cipher);

			int toplam=0;

			for (i=0; i<26; i++)  
			{
				toplam=toplam + V_Matrisi[i];
			}

			printf("\nVerilen metincik icerisindeki toplam karakter sayisi = %d dir.\n\n",toplam);

			system("pause");


			for (j=0; j<26; j++)
			{
				W_Matrisi[j]=(double)((double)V_Matrisi[j]/(double)toplam);	//DÝKKAT
			}

			printf("\n\n\t\tV matrisi \tW_Matrisi \t A matrisi  \n");
			for (j=0; j<26; j++)
			{
				printf("\n\t\tV[%2d] = %d \tW[%2d] = %1.4f \t A = %1.4f ==> %c",j,V_Matrisi[j],j,W_Matrisi[j],kucuk_A_Matrisi[j],(j+'a'));	
			}
			printf("\n\n\t\t");
			system("pause");

			
			k=0;
			for (i=25; i>=0; i--)
			{
		
				for (j=0; j<26; j++)
				{
					Carpim_Matrisi[j]=(double)(W_Matrisi[j]*A_Matrisi[j+i]);	//DÝKKAT
				}

				TOTAL[k]=0;
				for (j=0; j<26; j++)
				{
					TOTAL[k]=TOTAL[k] + Carpim_Matrisi[j];	
				}
				k++;

			}

			
			printf("\n\nAnahtarin %d. karakterinin hesaplanabilmesi icin",a+1);
			printf("\n0<i<25 olmak kosulu ile (W * A[i])  Scaler carpimlarinin sonuclari \n");
			for (j=0; j<26; j++)
			{
				printf("\n\t\tW * A[%2d] = %1.4f",j,TOTAL[j]);	
				printf(" ==> %c",(j+'a')); 
			}
			printf("\n");	


			anahtar_elemanlari[a]=HARF_GETIR(TOTAL);

		}

		system("cls");
		printf("\n\n\t\t BULUNAN ANAHTAR\n\n");

		printf("********************************************************************************\n");
		printf("\n\t");
		for (a=0; a<anahtar_uzunlugu;a++)
		{
			printf("\t%c",anahtar_elemanlari[a]);	
		}
		printf("\n\n");
		printf("********************************************************************************\n");
		printf("\n\n\t\t");
    }
	return 0;
}
