#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void MilletvekiliHesaplama(int milletvekili_kontenjani,int parti_sayisi,int parti_oy_sayisi[23],int hparti_vekil_sayisi[23]);
void Siralama(int gparti_oy_sayisi[23],char gparti_isim[23],int parti_sayisi,int gparti_vekil_sayisi[23]);
void IlBirincilik (int parti_oy_sayisi[23],int gparti_oy_sayisi[23],int parti_sayisi,int il_birincilik[23]);
void SifirVekil (int hparti_vekil_sayisi[23] , int parti_sayisi , int sifir_vekil[23]);

int main()
{
    char parti_isim[23] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','R','S','T','U','V','Y','Z'};
    int toplam_oy=0,milletvekili_kontenjani,toplam_milletvekili=0;
    int parti_sayisi,plaka_kodu;
    int parti_oy_sayisi[23];
    int parti_vekil_sayisi[23]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int parti_top_oy[23]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    char gparti_isim[23];
    int gparti_oy_sayisi[23],gparti_vekil_sayisi[23];
    int il_birincilik[23]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int sifir_vekil[23]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    for(int i=1;i>0;i++)
    {

        printf("Secime katilan parti sayisini giriniz:");
        scanf("%d",&parti_sayisi);
        if(parti_sayisi>0 && parti_sayisi<=23)
            break;
        else
            printf("1 ile 23 arasinda bir deger girmelisiniz.\n");
    }

    for(int i=1;i>0;i++)
        {
            baslangic:
            printf("\n\n\n");
            for (i=1;i>0;i++)
            {
                printf("Ilin plaka kodunu giriniz:");
                scanf("%d",&plaka_kodu);
                if(plaka_kodu>=0)
                    break;
                else
                    printf("Lutfen gecerli bir deger giriniz!\n");

            }

            if(plaka_kodu==0)
                {
                  break;
                }

            for (i=1;i>0;i++)
            {
                printf("Ilin milletvekili kontenjanini giriniz:");
                scanf("%d",&milletvekili_kontenjani);
                if(milletvekili_kontenjani>0)
                    break;
                else
                    printf("Lutfen gecerli bir deger giriniz!\n");

            }
            int gecerli_oy=0;
            for(i=0;i<parti_sayisi;i++)
               {
                  printf("%c Partisinin Oy Sayisini Giriniz:",parti_isim[i]);
                  scanf("%d",&parti_oy_sayisi[i]);
                  gecerli_oy+=parti_oy_sayisi[i];
                  parti_top_oy[i]=parti_top_oy[i]+parti_oy_sayisi[i];
               }
            toplam_oy+=gecerli_oy;
            toplam_milletvekili+=milletvekili_kontenjani;
            printf("\n\n\n");
            printf("Il Plaka Kodu:%d\n",plaka_kodu);
            printf("Milletvekili Kontenjani:%d\n",milletvekili_kontenjani);
            printf("Gecerli oy:%d\n",gecerli_oy);
            int  hparti_vekil_sayisi[23]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
            MilletvekiliHesaplama(milletvekili_kontenjani,parti_sayisi,parti_oy_sayisi,hparti_vekil_sayisi);
            for(int i=0;i<23;i++)
            {
                parti_vekil_sayisi[i]+=hparti_vekil_sayisi[i];
            }

            for(int i=0;i<23;i++)
            {
                 gparti_oy_sayisi[i]=parti_oy_sayisi[i];
                 gparti_vekil_sayisi[i]=hparti_vekil_sayisi[i];
                 gparti_isim[i]=parti_isim[i];
            }

            Siralama(gparti_oy_sayisi,gparti_isim,parti_sayisi,gparti_vekil_sayisi);
            IlBirincilik (parti_oy_sayisi,gparti_oy_sayisi,parti_sayisi,il_birincilik);
            SifirVekil (hparti_vekil_sayisi , parti_sayisi ,sifir_vekil);

            printf("\n         \t Oy Sayisi \tOy Yuzdesi\tMV Sayisi");
            printf("\n         \t --------- \t----------\t---------\n");
	        for(i=parti_sayisi-1;i>=0;i--)
                {
		            float oyyuzdesi = (100.00*gparti_oy_sayisi[i])/gecerli_oy;

		            printf("%c Partisi\t %d  \t\t %.2f \t\t   %d \n",gparti_isim[i],gparti_oy_sayisi[i],oyyuzdesi,gparti_vekil_sayisi[i]);

                }

            printf("\n\nDevam etmek icin bir tusa basiniz.");
            getch();
            goto baslangic;

        }
    printf("\nTurkiye Geneli\n");
    printf("Milletvekili Kontenjani:%d\n",toplam_milletvekili);
    printf("Gecerli Oy Sayisi:%d\n\n",toplam_oy);
    printf("\n         \t Oy Sayisi \tOy Yuzdesi\tMV Sayisi\tMV Yuzde\tIl 1.lik Say\t0 MV Il Say");
    printf("\n         \t --------- \t----------\t---------\t--------\t------------\t-----------\n");
    for(int i=0;i<parti_sayisi;i++)
    {
        float oyyuzdesi = (100.00*parti_top_oy[i])/toplam_oy;
        float mv_yuzde=(100.00*parti_vekil_sayisi[i])/toplam_milletvekili;
        printf("%c Partisi\t %d  \t\t %.2f \t\t   %d \t\t   %.2f  \t\t  %d\t\t  %d  \n",parti_isim[i],parti_top_oy[i],oyyuzdesi,parti_vekil_sayisi[i],mv_yuzde,il_birincilik[i],sifir_vekil[i]);


    }

    int iktidar=0;
    int muhalefet=0;
    int ey_iktidar=0;
    int ey_muhalefet=0;

    for(int i=0;i<parti_sayisi;i++)
        {
            if(parti_vekil_sayisi[i]>iktidar)
                {
                    iktidar=parti_vekil_sayisi[i];
                    ey_iktidar=i;
                }
        }
    for(int j=0;j<parti_sayisi;j++)
        {
           if(parti_vekil_sayisi[j]<iktidar)
           {
               if(parti_vekil_sayisi[j]>muhalefet)
               {
                   muhalefet=parti_vekil_sayisi[j];
                   ey_muhalefet=j;
               }
           }
        }

    printf("\nIktidar Partisi:%c\n",parti_isim[ey_iktidar]);
    printf("Ana Muhalefet Partisi:%c",parti_isim[ey_muhalefet]);
}
//FONKSIYONLAR
void MilletvekiliHesaplama(int milletvekili_kontenjani,int parti_sayisi,int parti_oy_sayisi[23],int hparti_vekil_sayisi[23])
{
    int eb_oy=0,eb_sira;
    int tempoysayi[parti_sayisi];
    for(int i=0;i<parti_sayisi;i++)
    {
        tempoysayi[i]=parti_oy_sayisi[i];
    }
    for(int i=0;i<milletvekili_kontenjani;i++)
    {
        for(int j=0;j<parti_sayisi;j++)
        {
            if(eb_oy<tempoysayi[j])
                eb_oy=tempoysayi[j];
        }
        for(int j=0;j<parti_sayisi;j++)
        {
            if(eb_oy==tempoysayi[j])
                eb_sira=j;
        }
        eb_oy=eb_oy/2;
        tempoysayi[eb_sira]=eb_oy;
        hparti_vekil_sayisi[eb_sira]++;

    }

}

void Siralama(int gparti_oy_sayisi[23],char gparti_isim[23],int parti_sayisi,int gparti_vekil_sayisi[23])
{

   int temp_oy,temp_ek,temp_vekil;
   char temp_isim[1];


   for(int i=0;i<parti_sayisi-1;i++)
   {
       temp_ek=i;
       for(int j=i+1;j<parti_sayisi;j++)
       {
           if(gparti_oy_sayisi[j]<gparti_oy_sayisi[temp_ek])
             temp_ek=j;
       }
       temp_oy=gparti_oy_sayisi[i];
       gparti_oy_sayisi[i]=gparti_oy_sayisi[temp_ek]; // Oy Sıralama
       gparti_oy_sayisi[temp_ek]=temp_oy;

       temp_isim[1]=gparti_isim[i];
       gparti_isim[i]=gparti_isim[temp_ek]; // Parti isim sıralama
       gparti_isim[temp_ek]=temp_isim[1];

       temp_vekil=gparti_vekil_sayisi[i];
       gparti_vekil_sayisi[i]=gparti_vekil_sayisi[temp_ek];  //vekil sıralama
       gparti_vekil_sayisi[temp_ek]=temp_vekil;

   }
}

void IlBirincilik (int parti_oy_sayisi[23],int gparti_oy_sayisi[23],int parti_sayisi,int il_birincilik[23])
{
    for (int i=0;i<parti_sayisi;i++)
    {
        if(parti_oy_sayisi[i]==gparti_oy_sayisi[parti_sayisi-1])
        {
            il_birincilik[i]++;
        }
    }
}

void SifirVekil (int hparti_vekil_sayisi[23] , int parti_sayisi , int sifir_vekil[23])
{
    for (int i=0;i<parti_sayisi;i++)
    {
        if(hparti_vekil_sayisi[i]==0)
        {
            sifir_vekil[i]++;
        }
    }
}


