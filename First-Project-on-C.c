#include <stdio.h>
#include <stdlib.h>
int accountfunc(int a);
int menufunc();
int cayfunc();
int main() {
    //100 Tane hesap, [0] ID, [1] �ifre, [2] bakiyeyi tutuyor.
    int acc[100][3],x,i,sepet = 0, t = 0;
    cikis:
    do {
        // �lk Men� b�l�m� hesaba giri� veya hesap olu�tur.
        int menunumbr = menufunc();
        id:
        //Hesap olu�turma
        if (menunumbr == 1) {
            x = 0;
            for(i = 0; i < 2; i++) {
                acc[t][i]=accountfunc(i); //accountfunc(i) i 0 iken kullan� taraf�ndan girilen ID yi, 1 iken �ifreyi d�nd�r�yor.
                // Olu�turulan Hesab�n Bakiyesinin 0 Olmas� i�in.
                acc[t][2] = 0;
                //Her ID nin farkl� olmas� i�in girilen ID di�er hesaplarda var m� diye bak�yoruz.
                for(x = 0 ; x < t; x++) {
                    if(acc[t][0] == acc[x][0]) {
                        printf("Farkli Bir ID Giriniz.\n");
                        goto id;
                    }
                }
            }
            //Bir sonraki hesap olu�turma i�leminde farkl� bir hesap olu�mas� i�in.
            t++;
        }
        printf("\n");
        long int id,psswrd,abc;
        printf("ID: ");
        scanf("%ld",&id);
        printf("Password: ");
        scanf("%ld",&psswrd);
//Otomat Sahibi Program� Sonland�rmak isterse.
        if(id == 692116 && psswrd == 692116 ) {
            printf("ADMIN SHUTDOWN!\n");
            printf("Kazan�lan Miktar: %dTL\n",sepet);
            return 0;
        }
        // Girdi�i ID ve �ifrelerden her ikiside acc hesaplar�ndan birisiyle uyu�uyor mu diye bak�yoruz.
        for(abc = 0; abc < 100;) {
            //Uyu�uyorsa uyu�tu�u hesapla devam ediyoruz.
            if(acc[abc][0] == id && acc[abc][1] == psswrd) {
                printf("Giris yapildi\n\n");
                break;
            }
            else
                //T�m hesaplar aras�nda gezmek i�in.
                abc++;
            //Girilen ID ve Pswrd T�m hesaplar aras�nda uyu�mad�ysa
            if(abc == 100) {
                //Hesap yokken ��kmaza girmemesi i�in.
                if(t == 0) {
                    printf("Gecersiz Hesap Bilgileri.\n\n");
                    //115. sat�r.
                    goto hesapyok;
                }
                    //abc yi 0 a e�itleyip Tekrar ID ve Password girilmesini istiyoruz ve d�ng� tekrar en ba�a sar�yor.
                else {
                    abc = 0;
                    printf("ID or Password is wrong.\nID: ");
                    scanf("%d",&id);
                    printf("Password: ");
                    scanf("%d",&psswrd);
                }
            }
        }
        int atmmenu;
        parayok:
        do {
            printf("Bakiye Gor --->>> 1\n\nPara Yukle --->>> 2\n\nDevam Et --->>> 3\n\nHesaptan Cikis Yap --->>> 4\n\n ");
            scanf("%d", &atmmenu);
            if(atmmenu == 1) {
                printf("Bakiyeniz : %dTL\n", acc[abc][2]);
            }
            else if(atmmenu == 2) {
                int p;
                printf("Yuklemek Istediginiz Para Miktari: ");
                scanf("%d", &p);
                acc[abc][2] += p;
            }
            else if(atmmenu == 4)
//Hesaptan ��k�� i�lemi 7. Sat�ra gidiyor.
                goto cikis;

        }
        while(atmmenu != 3);
        int bac,sepetc = 0;
        do{
            int urunfiyat= cayfunc();
            sepetc += urunfiyat;
            sepet += urunfiyat;
            //Bakiye Yetiyor mu bak�yoruz.
            if(acc[abc][2]-urunfiyat < 0) {
                printf("Yetersiz Bakiye.\n\n");
                sepetc -= urunfiyat;
                sepet -= urunfiyat;
                //Para yetmiyor ise 71. sat�ra gidip para y�kleyebilir.
                goto parayok;
                break;
            }

            if (sepetc == 2){
                printf("Dolarin 8,1 Oldugu Devirde Zaten Anca Cay Kek Yaparsin.\n\n");
            }
            acc[abc][2] -= urunfiyat;
            printf("Alisverise devam et --->>> 1\nAlisverisi bitir --->>> 2\n");
            scanf("%d", &bac);
        }
        while(bac == 1);
        printf("Toplam Tutar: %dTL\nKalan Bakiye: %dTL\n\n",sepetc,acc[abc][2]);
        hesapyok:
        ;
    }
//Main fonk sonu ve en ba�a d�nmesi i�in.
    while(1);
}


//FONSK�YONLAR.


int accountfunc(int a) {
    int acc[1][2],i = 0;
    if(a == 0)
    {
        printf("Create ID:");
        scanf("%d",&acc[i][0]);
        return acc[i][0];
    }
    else if(a == 1)
    {
        printf("Create Password: ");
        scanf("%d",&acc[i][1]);
        return acc[i][1];
    }
}


int menufunc() {
    int a;
    printf("Hesap olusturmak icin ----->>>>> 1\nGiris yapmak icin ----->>>>> 2\n");
    do {
        printf("");
        scanf("%d", &a);
    }
    while(a != 1 && a != 2);
    return a;
}


int cayfunc() {
    int b,a,arr[10] = {1,1,3,150,800,0,1000,10000,7500,9000};
    printf("\n1-Cay -> 1TL\n2-Kek -> 1TL\n3-10lu maske -> 3TL\n4-Biontech asisi -> 150TL\n5-Iphone 12 -> 800TL\n6-Sinovac asisi -> BEDAVA\n7-Rastgele bir unlunun telefon numarasi -> 1000TL\n8-Salda Golunden bir plastik bardak kum -> 10000TL\n9-Ankapark icin dinocan -> 7500TL\n10-Laptop -> 9000TL\n\n");
    printf("Istediginiz Urunu Secin: ");
    scanf("%d", &a);
    if (a==1)
        printf("\nTavsan Kani Gibi \n\n");
    else if (a==2)
        printf("\nKekimi Ye Beni Yeme\n\n");
    else if (a==3)
        printf("\nBim den Daha ucuza\n\n");
    else if (a==4)
        printf ("\nAsya Ne Gerek Var Virus Yok Zaten\n\n");
    else if (a==5)
        printf("\nOtomattan da Iphone mu alinir? H.O. G.O.\n\n");
    else if (a==6)
        printf("\nSinovac Oluyon Korona Oluyon\n\n");
    else if (a==7)
        printf("\nAjdarinkiyse G.O.\n\n");
    else if (a==8)
        printf("\nTEBRIKLER!!! Salda'nin Berektli Kumu,Suyla Karistirip Ic\n\n");
    else if (a==9)
        printf("\nJurassic Park Heykeli\n\n");
    else if (a==10)
        printf("\nAcilirsa Sukret\n\n");
    b = arr[a-1];
    return b;
}





