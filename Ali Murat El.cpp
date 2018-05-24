#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>
int Cikis;

struct Personel
{
	char Isim[100];
	long int TCKimlikNo;
	long int Telefon;
	char Eposta[100];
	char Adres[100];
}Yeni,Ekleme;

void YeniKayit();
void Listele();
void Duzenle();
void TCArama();
void IsimArama();
void Sil();
void Close();

int main()
{
	setlocale(LC_ALL,"Turkish");
	int choice;
	printf("\n\t\t\t PERSONEL KAYIT VE B�LG� S�STEM�\n\n");
	printf("\n\t A�a��daki se�eneklerden bir i�lem se�iniz;\n");
	printf("\n\t1.Kay�t Eklemek ��in");
	printf("\n\t2.Personel Listesi ��in");
	printf("\n\t3.Kay�t D�zenlemek ��in");
	printf("\n\t4.TC Kimlik No ile Arama ��in");
	printf("\n\t5.�sim ile Aramak ��in");
	printf("\n\t6.Kay�t Silmek ��in");
	printf("\n\t0.��k�� ��in");
	
	printf("\n\t Tercih Etti�iniz ��lem Numaras�n� Giriniz:");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:YeniKayit();
		break;
		
		case 2:Listele();
		break;
		
		case 3:Duzenle();
		break;
		
		case 4:TCArama();
		break;
		
		case 5:IsimArama();
		break;
		
		case 6:Sil();
		break;
		
		case 7:Close();
		break;
	
	}
	return 0;
}

void YeniKayit()
{
	FILE * dosya;
	dosya = fopen("Personel.txt","a+");
	printf("\t\t\t Yeni Kay�t");
	
	printf("\n �sim:");
	scanf("%s",Yeni.Isim);
	
	printf("\n TC Kimlik No:");
	scanf("%ld",&Yeni.TCKimlikNo);
	
	printf("\n Telefon Numaras�:");
	scanf("%ld",&Yeni.Telefon);
	
	printf("\n Eposta:");
	scanf("%s",Yeni.Eposta);
	
	printf("\n Adres:");
	scanf("%s",Yeni.Adres);
	
	fprintf(dosya,"%s %ld %ld %s %s \n",Yeni.Isim,Yeni.TCKimlikNo,Yeni.Telefon,Yeni.Eposta,Yeni.Adres);
	fclose(dosya);
	
	printf("\n Kay�t Olu�turuldu.");
	Tercih1:
	
	printf("\n\n\n\t Yeni Kay�t ��in 0'a,Ana Men�ye D�nmek ��in 1'e Bas�n�z:");
	scanf("%d",&Cikis);
	
	if (Cikis==1)
	main();
	else if (Cikis==0)
	YeniKayit();
	else
	{
		printf("\n Hatal� Giri� Yapt�n�z");
		goto Tercih1;
	}
}
	
	
	void Listele()
	{
		FILE * dosya;
		dosya = fopen ("Personel.txt","r");
		int test=0;
		printf("\n �S�M \t\t TC \t\t TELEFON \t\t EPOSTA \t\t ADRES \n ");
		
		while (fscanf(dosya,"%s %ld %ld %s %s",Yeni.Isim,&Yeni.TCKimlikNo,&Yeni.Telefon,Yeni.Eposta,Yeni.Adres)!=EOF)
		{
			printf("\n %s \t\t %ld \t\t %ld \t\t %s \t\t %s",Yeni.Isim,Yeni.TCKimlikNo,Yeni.Telefon,Yeni.Eposta,Yeni.Adres);
			test++;
		}
		
		fclose(dosya);
		if (test==0)
		{
			printf("\n B�yle Bir Kay�t Bulunmamaktad�r \n");
			
		}
		
		Tercih2:
			
		printf("\n\n\\t Ana Men�ye D�nmek ��in 1'e,��kmak ��in 0'a Bas�n�z:");
		scanf("%d",&Cikis);
		if (Cikis==1)
		main();
		else if (Cikis==0)
		Close();
		else
		{
			printf("\n Hatal� Giri� Yapt�n�z");
			goto Tercih2;
		}
		
	}
	void Duzenle(){
    int test=0;
    FILE *eski,*fark;
    eski=fopen("Personel.txt","r");
    fark=fopen("fark.txt","w");

    printf("\nPersonel �smi:");
    scanf("%s",Ekleme.Isim);
    while(fscanf(eski,"%s %ld %ld %s %s",Yeni.Isim,&Yeni.TCKimlikNo,&Yeni.Telefon, Yeni.Eposta, Yeni.Adres)!=EOF)
    {
        if (strcmp(Ekleme.Isim,Yeni.Isim) == 0)
		{
            test=1;
            printf("Yeni TC:");
            scanf("%ld",&Ekleme.TCKimlikNo);
            printf("Yeni Telefon:");
            scanf("%ld",&Ekleme.Telefon);
            printf("Yeni Eposta:");
            scanf("%s",Ekleme.Eposta);
            printf("Yeni Adres:");
            scanf("%s",Ekleme.Adres);
            fprintf(fark,"%s %ld %ld %s %s\n",Ekleme.Isim,Ekleme.TCKimlikNo,Ekleme.Telefon,Ekleme.Eposta,Ekleme.Adres);
            printf("De�i�iklik kaydedildi.");
        }
        else{
            fprintf(fark,"%s %ld %ld %s %s\n",Yeni.Isim,Yeni.TCKimlikNo,Yeni.Telefon,Yeni.Eposta,Yeni.Adres);
        }
    }
    fclose(eski);
    fclose(fark);
    remove("Personel.txt");
    rename("fark.txt","Personel.txt");
    if(test!=1)
        printf("\n�sim Bulunamad�\a\a\a");

        Tercih3:
            printf("\nTekrar sorgulamak i�in 0'a,Ana Men�ye d�nmek i�in 1'e bas�n�z:");
            scanf("%d",&Cikis);
            if (Cikis==1)
                main();
            else if(Cikis==0)
                Duzenle();
            else{
                printf("\nYanl�� Giri� Yapt�n�z\a");
                goto Tercih3;
            }
}


void TCArama()
{
    FILE *dosya;
    int test=0;
    dosya=fopen("Personel.txt","r");
    printf("TC:");
    scanf("%ld",&Ekleme.TCKimlikNo);
    while(fscanf(dosya,"%s %ld %ld %s %s",Yeni.Isim,&Yeni.TCKimlikNo,&Yeni.Telefon, Yeni.Eposta, Yeni.Adres)!=EOF)
    {
            if(Ekleme.TCKimlikNo==Yeni.TCKimlikNo)
			{
                test=1;
                printf("\n�sim:%s \nTC:%ld \nTelefon:%ld \nEposta:%s \nAdres:%s\n",Yeni.Isim,Yeni.TCKimlikNo,Yeni.Telefon,Yeni.Eposta,Yeni.Adres);
            }
    }
    fclose(dosya);
     if(test!=1)
        printf("\nKay�t Bulunamad�!\a\a\a");
    Tercih5:
        printf("\nTekrar aramak i�in 0'a, Ana Men�ye d�nmek i�in 1'e, ��kmak i�in 2'ye bas�n�z':");
        scanf("%d",&Cikis);
            if (Cikis==1)
                main();
            else if (Cikis==2)
                Close();
            else if(Cikis==0)
                TCArama();
            else{
                printf("\nYanl�� Giri� Yapt�n�z\a");
                goto Tercih5;
            }
}

void IsimArama(){
    FILE *dosya;
    int test=0;
    dosya=fopen("Personel.txt","r");
    printf("�sim:");
    scanf("%s",&Ekleme.Isim);
    while(fscanf(dosya,"%s %ld %ld %s %s",Yeni.Isim,&Yeni.TCKimlikNo,&Yeni.Telefon, Yeni.Eposta, Yeni.Adres)!=EOF)
    {
            if(strcmp(Ekleme.Isim,Yeni.Isim) == 0)
			{
                test=1;
                printf("\n�sim:%s \nTC:%ld \nTelefon:%ld \nEposta:%s \nAdres:%s\n",Yeni.Isim,Yeni.TCKimlikNo,Yeni.Telefon, Yeni.Eposta, Yeni.Adres);
            }
    }
    fclose(dosya);
    if(test!=1)
        printf("\nKay�t Bulunamad�\a\a\a");
    Tercih6:
        printf("\nTekrar aramak i�in 0'a, Ana Men�ye d�nmek i�in 1'e, ��kmak i�in 2'ye bas�n�z:");
        scanf("%d",&Cikis);
            if (Cikis==1)
                main();
            else if (Cikis==2)
                Close();
            else if(Cikis==0)
                IsimArama();
            else{
                printf("\nYanl�� Giri� Yapt�n�z\a");
                goto Tercih6;
            }
}

void Sil(){
    FILE *eski,*fark;
    int test=0;
    eski=fopen("Personel.txt","r");
    fark=fopen("fark.txt","w");
    printf("Silinecek ki�inin TC Kimlik Numaras� Giriniz:");
    scanf("%ld",&Ekleme.TCKimlikNo);
    while(fscanf(eski,"%s %ld %ld %s %s",Yeni.Isim,&Yeni.TCKimlikNo,&Yeni.Telefon, Yeni.Eposta, Yeni.Adres)!=EOF)
    {
        if(Ekleme.TCKimlikNo!=Yeni.TCKimlikNo)
            fprintf(fark,"%s %ld %ld %s %s\n",Yeni.Isim,Yeni.TCKimlikNo,Yeni.Telefon, Yeni.Eposta, Yeni.Adres);
        else{
            test++;
            printf("\nKay�t silindi.\n");
        }
   }
   fclose(eski);
   fclose(fark);
   remove("Personel.txt");
   rename("fark.txt","Personel.txt");
   if(test==0)
        printf("\nKay�t bulunamad�\a\a\a");
    Tercih7:
        printf("\nTekrar silme aramas� yapmak i�in 0'a, Ana Men�ye d�nmek i�in 1'e, ��kmak i�in 2'ye bas�n�z:");
        scanf("%d",&Cikis);
        if (Cikis==1)
            main();
        else if (Cikis==2)
            Close();
        else if(Cikis==0)
            Sil();
        else
		{
        printf("\nYanl�� Giri� Yapt�n�z\a");
        goto Tercih7;
        }
}


void Close()
{
    printf("\nAd:%s \nSoyad:%s \nOkul Numaras�:%ld \nEposta:%s\n","Ali Murat","El","172802069","ali_murat_el@hotmail.com");
}

