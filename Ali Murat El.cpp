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
	printf("\n\t\t\t PERSONEL KAYIT VE BÝLGÝ SÝSTEMÝ\n\n");
	printf("\n\t Aþaðýdaki seçeneklerden bir iþlem seçiniz;\n");
	printf("\n\t1.Kayýt Eklemek Ýçin");
	printf("\n\t2.Personel Listesi Ýçin");
	printf("\n\t3.Kayýt Düzenlemek Ýçin");
	printf("\n\t4.TC Kimlik No ile Arama Ýçin");
	printf("\n\t5.Ýsim ile Aramak Ýçin");
	printf("\n\t6.Kayýt Silmek Ýçin");
	printf("\n\t0.Çýkýþ Ýçin");
	
	printf("\n\t Tercih Ettiðiniz Ýþlem Numarasýný Giriniz:");
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
	printf("\t\t\t Yeni Kayýt");
	
	printf("\n Ýsim:");
	scanf("%s",Yeni.Isim);
	
	printf("\n TC Kimlik No:");
	scanf("%ld",&Yeni.TCKimlikNo);
	
	printf("\n Telefon Numarasý:");
	scanf("%ld",&Yeni.Telefon);
	
	printf("\n Eposta:");
	scanf("%s",Yeni.Eposta);
	
	printf("\n Adres:");
	scanf("%s",Yeni.Adres);
	
	fprintf(dosya,"%s %ld %ld %s %s \n",Yeni.Isim,Yeni.TCKimlikNo,Yeni.Telefon,Yeni.Eposta,Yeni.Adres);
	fclose(dosya);
	
	printf("\n Kayýt Oluþturuldu.");
	Tercih1:
	
	printf("\n\n\n\t Yeni Kayýt Ýçin 0'a,Ana Menüye Dönmek Ýçin 1'e Basýnýz:");
	scanf("%d",&Cikis);
	
	if (Cikis==1)
	main();
	else if (Cikis==0)
	YeniKayit();
	else
	{
		printf("\n Hatalý Giriþ Yaptýnýz");
		goto Tercih1;
	}
}
	
	
	void Listele()
	{
		FILE * dosya;
		dosya = fopen ("Personel.txt","r");
		int test=0;
		printf("\n ÝSÝM \t\t TC \t\t TELEFON \t\t EPOSTA \t\t ADRES \n ");
		
		while (fscanf(dosya,"%s %ld %ld %s %s",Yeni.Isim,&Yeni.TCKimlikNo,&Yeni.Telefon,Yeni.Eposta,Yeni.Adres)!=EOF)
		{
			printf("\n %s \t\t %ld \t\t %ld \t\t %s \t\t %s",Yeni.Isim,Yeni.TCKimlikNo,Yeni.Telefon,Yeni.Eposta,Yeni.Adres);
			test++;
		}
		
		fclose(dosya);
		if (test==0)
		{
			printf("\n Böyle Bir Kayýt Bulunmamaktadýr \n");
			
		}
		
		Tercih2:
			
		printf("\n\n\\t Ana Menüye Dönmek Ýçin 1'e,Çýkmak Ýçin 0'a Basýnýz:");
		scanf("%d",&Cikis);
		if (Cikis==1)
		main();
		else if (Cikis==0)
		Close();
		else
		{
			printf("\n Hatalý Giriþ Yaptýnýz");
			goto Tercih2;
		}
		
	}
	void Duzenle(){
    int test=0;
    FILE *eski,*fark;
    eski=fopen("Personel.txt","r");
    fark=fopen("fark.txt","w");

    printf("\nPersonel Ýsmi:");
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
            printf("Deðiþiklik kaydedildi.");
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
        printf("\nÝsim Bulunamadý\a\a\a");

        Tercih3:
            printf("\nTekrar sorgulamak için 0'a,Ana Menüye dönmek için 1'e basýnýz:");
            scanf("%d",&Cikis);
            if (Cikis==1)
                main();
            else if(Cikis==0)
                Duzenle();
            else{
                printf("\nYanlýþ Giriþ Yaptýnýz\a");
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
                printf("\nÝsim:%s \nTC:%ld \nTelefon:%ld \nEposta:%s \nAdres:%s\n",Yeni.Isim,Yeni.TCKimlikNo,Yeni.Telefon,Yeni.Eposta,Yeni.Adres);
            }
    }
    fclose(dosya);
     if(test!=1)
        printf("\nKayýt Bulunamadý!\a\a\a");
    Tercih5:
        printf("\nTekrar aramak için 0'a, Ana Menüye dönmek için 1'e, Çýkmak için 2'ye basýnýz':");
        scanf("%d",&Cikis);
            if (Cikis==1)
                main();
            else if (Cikis==2)
                Close();
            else if(Cikis==0)
                TCArama();
            else{
                printf("\nYanlýþ Giriþ Yaptýnýz\a");
                goto Tercih5;
            }
}

void IsimArama(){
    FILE *dosya;
    int test=0;
    dosya=fopen("Personel.txt","r");
    printf("Ýsim:");
    scanf("%s",&Ekleme.Isim);
    while(fscanf(dosya,"%s %ld %ld %s %s",Yeni.Isim,&Yeni.TCKimlikNo,&Yeni.Telefon, Yeni.Eposta, Yeni.Adres)!=EOF)
    {
            if(strcmp(Ekleme.Isim,Yeni.Isim) == 0)
			{
                test=1;
                printf("\nÝsim:%s \nTC:%ld \nTelefon:%ld \nEposta:%s \nAdres:%s\n",Yeni.Isim,Yeni.TCKimlikNo,Yeni.Telefon, Yeni.Eposta, Yeni.Adres);
            }
    }
    fclose(dosya);
    if(test!=1)
        printf("\nKayýt Bulunamadý\a\a\a");
    Tercih6:
        printf("\nTekrar aramak için 0'a, Ana Menüye dönmek için 1'e, Çýkmak için 2'ye basýnýz:");
        scanf("%d",&Cikis);
            if (Cikis==1)
                main();
            else if (Cikis==2)
                Close();
            else if(Cikis==0)
                IsimArama();
            else{
                printf("\nYanlýþ Giriþ Yaptýnýz\a");
                goto Tercih6;
            }
}

void Sil(){
    FILE *eski,*fark;
    int test=0;
    eski=fopen("Personel.txt","r");
    fark=fopen("fark.txt","w");
    printf("Silinecek kiþinin TC Kimlik Numarasý Giriniz:");
    scanf("%ld",&Ekleme.TCKimlikNo);
    while(fscanf(eski,"%s %ld %ld %s %s",Yeni.Isim,&Yeni.TCKimlikNo,&Yeni.Telefon, Yeni.Eposta, Yeni.Adres)!=EOF)
    {
        if(Ekleme.TCKimlikNo!=Yeni.TCKimlikNo)
            fprintf(fark,"%s %ld %ld %s %s\n",Yeni.Isim,Yeni.TCKimlikNo,Yeni.Telefon, Yeni.Eposta, Yeni.Adres);
        else{
            test++;
            printf("\nKayýt silindi.\n");
        }
   }
   fclose(eski);
   fclose(fark);
   remove("Personel.txt");
   rename("fark.txt","Personel.txt");
   if(test==0)
        printf("\nKayýt bulunamadý\a\a\a");
    Tercih7:
        printf("\nTekrar silme aramasý yapmak için 0'a, Ana Menüye dönmek için 1'e, Çýkmak için 2'ye basýnýz:");
        scanf("%d",&Cikis);
        if (Cikis==1)
            main();
        else if (Cikis==2)
            Close();
        else if(Cikis==0)
            Sil();
        else
		{
        printf("\nYanlýþ Giriþ Yaptýnýz\a");
        goto Tercih7;
        }
}


void Close()
{
    printf("\nAd:%s \nSoyad:%s \nOkul Numarasý:%ld \nEposta:%s\n","Ali Murat","El","172802069","ali_murat_el@hotmail.com");
}

