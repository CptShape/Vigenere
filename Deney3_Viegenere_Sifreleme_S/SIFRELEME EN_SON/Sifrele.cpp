#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 2000


char * KUCUKHARFECEVIR( char * metincik )
{
	int i,j;
	i=0;
	j=0;
	char * kucuktext;
	kucuktext=(char *)malloc(N*sizeof(char));

	//Verilen metin kücük harfe cevrilir, 
	//Metindeki bosluklar ile noktalama iþaretleri ihmal edilir.
	for (i=0; i<strlen(metincik); i++)
	{
		if (metincik[i]>=65 && metincik[i]<=90) // Büyük harf ise
		{
			kucuktext[j]=tolower(metincik[i]);
			j++;
		}
		else if (metincik[i]>=97 && metincik[i]<=122) // Küçük harf ise
		{
			kucuktext[j]=metincik[i];
			j++;
		}
	}
	kucuktext[j]='\0';

	return kucuktext;

}

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

char * SIFRELE( char * plaintext, char * key )
{
	int i,k;
	char sifrelimetin[N];
	char * ciphertext;
	ciphertext=(char *)malloc(N*sizeof(char));

	int anhtruzunlk=strlen(key);

	//Sifreleme isleminin gerceklestirilmesi
    for(k=0; k<strlen(plaintext); k++)
    {
		// her iki metinin karakterleri toplanýrken ASCII tablosunda 97+97 
		// yani 'a' + 'a' kadar geri gidilmesi gerekir.
		sifrelimetin[k]=((plaintext[k] + key[k%anhtruzunlk])-194); 
		if (sifrelimetin[k]>25)										 
			sifrelimetin[k]=(sifrelimetin[k]-26);
		// sýfýncý karakter 'a'ya denk geldiðinden 97 ile toplanmalý.
			sifrelimetin[k]=(sifrelimetin[k]+97); 
    }
	sifrelimetin[k]='\0';

	ciphertext=BUYUKHARFECEVIR(sifrelimetin);
	/*
	// Sifreli metin buyuk harfe çevrilir
	int fark='a'-'A';
	for (i=0; i<strlen(sifrelimetin); i++)
	{
			ciphertext[i]=sifrelimetin[i]-fark;
	}

	ciphertext[i]='\0';
	*/
	return ciphertext;
}


char * COZ( char * ciphertexta, char * key )
{
	char * ciphertext = KUCUKHARFECEVIR(ciphertexta);
	int i,k;
	char plaintext[N];
	char * decryptedtext;
	decryptedtext=(char *)malloc(N*sizeof(char));

	int anhtruzunlk=strlen(key);

	// Þifrelenmiþ metni geri döndürmek için
    for(k=0; k<strlen(ciphertext); k++)
    {
		plaintext[k]=((ciphertext[k] - key[k%anhtruzunlk]) + 97); // 97 den küçükse 26 ekle
		if(plaintext[k] < 97)
			plaintext[k] = (plaintext[k] + 26);
    }
	plaintext[k]='\0';

	decryptedtext=BUYUKHARFECEVIR(plaintext);

	return decryptedtext;
}




int sifreleFunc()
{
	system("cls");
	printf("\n\n\n\t\t\tViGENERE SiFRELEME SISTEMI\n\n\n");	
	printf("********************************************************************************\n");
		
	// Vigenere Þifreleme Yöntemi
	int i,j,k;

	char metin[N]; 
	char *plaintext;
	plaintext=(char *)malloc(N*sizeof(char));

	printf("Sifrelemek istediginiz metni giriniz...  : ");
	gets(metin);
	plaintext=KUCUKHARFECEVIR(metin);

	char anahtar[100];
	char *key;
	key=(char *)malloc(100*sizeof(char));

	printf("\nAnahtari giriniz...  : ");
	gets(anahtar);
	key=KUCUKHARFECEVIR(anahtar);

	int anahtaruzunlugu=strlen(key);

	printf("\n\n********************************************************************************\n");
	printf("\nSifrelenecek metin \t = %s\n",plaintext);
	printf("\nAnahtar \t\t = ");
	for (i=0; i<strlen(plaintext); i++)
	{
		printf("%c",key[i%anahtaruzunlugu]);
	}
	printf("\n");

	char *ciphertext;
	ciphertext=(char *)malloc(N*sizeof(char));
	ciphertext=SIFRELE(plaintext,key);

	printf("\nSifreli metin \t\t = %s\n",ciphertext);
	printf("\n\n********************************************************************************\n");


	//Metnin þifreli hali dosyaya yazýlýr.
	FILE *DosyaOku;
    	DosyaOku = fopen("METIN.txt","w");
	for (i=0; i<strlen(ciphertext); i++)
	{
		fputc(ciphertext[i],DosyaOku );
	}
	fclose(DosyaOku); 

	printf("\nSifrelenmis metin METIN.txt isimli dosyaya yazildi.\n\n");

	return 0;
}

int cozFunc()
{
	system("cls");
	printf("\n\n\n\t\t\tViGENERE SiFRE COZME\n\n\n");	
	printf("********************************************************************************\n");
		
	// Vigenere Þifreleme Yöntemi
	int i,j,k;

	char metin[N]; 
	char *plaintext;
	plaintext=(char *)malloc(N*sizeof(char));

	printf("Sifreli metni girin...  : ");
	gets(metin);

	char anahtar[100];
	char *key;
	key=(char *)malloc(100*sizeof(char));

	printf("\nAnahtari giriniz...  : ");
	gets(anahtar);
	
	char *result;
	result=(char *)malloc(N*sizeof(char));
	result=COZ(metin, anahtar);


	printf("\nMetin \t\t = %s\n",result);
	printf("\n\n********************************************************************************\n");


	//Metnin þifreli hali dosyaya yazýlýr.
	FILE *DosyaOku;
    	DosyaOku = fopen("METIN.txt","w");
	for (i=0; i<strlen(result); i++)
	{
		fputc(result[i],DosyaOku );
	}
	fclose(DosyaOku); 

	printf("\nMETIN.txt isimli dosyaya yazildi.\n\n");

	return 0;
}

int main()
{
	char secim;
    
    printf("Sifrelemek icin 'S', cozumlemek icin 'C' girin: ");
    scanf(" %c", &secim);
    
    // Eðer kullanýcý birden fazla karakter girdiyse diðer karakterleri atar.
    while (getchar() != '\n');
    
    switch (secim) {
        case 'S':
        case 's':
            sifreleFunc();
            break;
        case 'C':
        case 'c':
            cozFunc();
            break;
        default:
            printf("Gecerli bir secim yapmadiniz!\n");
    }
    
    return 0;
}
