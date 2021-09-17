#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <stdbool.h>
#define SATIR 20000
#define SUTUN 400

struct depo{

	char kutular[SATIR][SUTUN];
	int kutuda_soru_sayisi[5];
	int satir_sonu;
}erisim;

void veri_alma(void);
void menu(void);
void menu_kutu(void);
void yardim(void);
void kutular(void);
void bilgi_ekle(void);
void bilgi_sil(void);
void test(int);
void veri_isle(void);
void ayarlar(void);
void verileri_duzenle(char, const char *);
char kontrol_char(char cevap);
char tr_ceviri(char);
int kontrol(int,int,int);
void elek(int);


int main(void){
	setlocale(LC_ALL,"Turkish");
	veri_alma();

	return 0;
}

void veri_alma(void){   /*Metin dosyas�nda bulunan verileri diziye al�r.*/
	FILE *fptr;
	char read,read_list,read_row;
    int satir,sutun,counter1;
    fptr = fopen("depo.txt","rb");
    
	if(fptr == NULL){
	    printf("Hi�bir veri bulunamad�. ");
	    elek(0);
	    fclose(fptr);
    }
    satir = 0;
    sutun = 0;

    while( fscanf(fptr,"%c",&read) != EOF ){
    	erisim.kutular[satir][sutun] = read;  /*Dizinin ba��nda olmas� gereken say�y� al�r(Sorunun hangi seviyede oldu�unu belirlemek i�in).*/
    	++erisim.kutuda_soru_sayisi[read - 49];  /*Hangi seviye sorudan ka� tane oldu�unu depolar.*/
    	++sutun;
    	counter1 = 0;
    	
    	while(counter1 != 7){
    		fscanf(fptr,"%c",&read_row);
    		if(read_row == '#'){          /*Soru ve cevaplar birbirinden # i�areti ile ayr�l�r.�lk #'den sonra ��klar gelir.*/
    		    ++counter1;               /*Son #'den �nce do�ru cevab�n hangisi olldu�u yaz�l�d�r.*/
    		}
    		erisim.kutular[satir][sutun] = read_row;
    		++sutun;                      /*7. #'den sonra di�er soru gelir.*/
		}
		++satir;
		sutun = 0;
		counter1 = 0;
	}
	erisim.satir_sonu = satir;
	system("cls");
	menu();
	
}

void menu(void){
	int girdi1;

	printf("\n\n\t\t\t\tEZBER PROGRAMI\n\n");
	printf("\t\t\t\t1. Kutu Men�s�ne Git\
	        \n\t\t\t\t2. Yard�m\
			\n\t\t\t\t3. ��k�� \t ");

	switch( kontrol(girdi1,1,3) ){
		case 1:
			elek(1);
			menu_kutu();
			break;
		case 2:
			elek(1);
			yardim();
			break;
		case 3:
			exit(1);
			break;
	}
}

void menu_kutu(void){
	int girdi1;
	printf("\n\n\t\t\t\t1. Kutulara git\
	        \n\t\t\t\t2. Kutuya bilgi ekle\
		    \n\t\t\t\t3. Ayarlar\
			\n\t\t\t\t4. Geri\n\t\t\t\t\t");
	switch( kontrol(girdi1,1,4) ){
		case 1:
			elek(1);
			kutular();
			break;
		case 2:
			elek(1);
			bilgi_ekle();
			break;
		case 3:
			elek(1);
			ayarlar();
			break;
		case 4:
			elek(1);
			menu();
			break;
	}
}

void ayarlar(void){
	int girdi1;
	printf("\n\n\t\t\t\t1. Kutulardan sil\
	         \n\t\t\t\t2. Hepsini ilk kutuya ta��\
	        \n\t\t\t\t3. T�m veriyi sil\
			\n\t\t\t\t4. Geri\n\t\t\t\t\t");
	switch( kontrol(girdi1,1,4) ){
		case 1:
			elek(1);
			bilgi_sil();
			break;
		case 2:
			elek(1);
			verileri_duzenle('1',"T�m sorular� ilk kutuya ta��mak istedi�inizden emin misiniz?");
			break;
		case 3:
			elek(1);
			verileri_duzenle('\0',"T�m verileri silmek istedi�inizden emin misiniz?");
			break;
		case 4:
			elek(1);
			menu_kutu();
			break;
	}
}

void verileri_duzenle(char duzen,const char *metin){
	int girdi,i;
	printf("\n\n\n\t\t\t%s\n\
	\t\t\t\t1. Evet      2.Hay�r\n\n\t\t\t\t",metin);
	switch( kontrol(girdi,1,2) ){
		case 1:
			for(i = 0 ; i < erisim.satir_sonu ; ++i){
				erisim.kutular[i][0] = duzen;
			}
			veri_isle();
			system("cls");
			elek(1);
			printf("\n\n\n\t\t\tTamamland�.");
			elek(1);
			ayarlar();
			break;
		case 2:
			elek(1);
			ayarlar();
			break;
	}
}


void yardim(void){
	int girdi;
	printf("Be� adet kutunuz oldu�unu var say�n. Ba�ta sizden ilk kutu i�in bilgiler girmeniz istenecek.\
Bir soru ve 5 se�enek\ngirmelisiniz. Girdi�iniz bilgiler ilk kutuda depolan�r. Teste ba�larsan�z, size, \
sizin girdi�iniz sorular sorulacak.\nE�er do�ru se�ene�i se�erseniz bilgi bir sonraki kutuya ta��nacak.\
E�er oradayken de bilirseniz di�erine ve bu �ekilde \nson kutuya kadar gidecek.Eger son kutuya geldi�inizde de\
 soruyu bilirseniz, bu bilgiyi art�k ��renmi�siniz demektir.\nAncak e�er soruyu bilemezseniz, bilgi bir �nceki\
kutuya geri d�necek. T�m bilgileri son kutuya getirmelisiniz.\n");
	printf("\nGeri d�nmek i�in 1 girin: ");
	kontrol(girdi,1,1);
	elek(1);
	menu();
}

void kutular(void){
	int girdi1,tut;
	printf("\n\n\t\t\t\t1. Kutu  3. Kutu\n\t\t\t\t2. Kutu  4. Kutu\n\t\t\t\t5. Kutu  \t\t6.Geri\n\n\t\t\t\t");
	tut = kontrol(girdi1,1,6);
	if(tut == 6){
		elek(1);
	    menu_kutu();
	}
	else{
		elek(1);
	    test(tut);
	}
	    
}
void test(int n){                                /*Hangi seviye se�ilmi�se o seviyenin sorular� kullan�c�ya sorulur.*/
	int sayac1,sayac2,sayac3,secenek;
	short asagi;
	char girdi,dogru_cevap,cevap,seviye = (48 + n);    /*48 say�sal olarak '0'�n yerini tutar.*/
	bool kutu_bos = true;
	sayac3 = 1;
	for(sayac1 = 0 ; sayac1 < erisim.satir_sonu ; sayac1++){
		if(erisim.kutular[sayac1][0] == seviye){
			kutu_bos = false;
			secenek = 65;
			asagi = 0;
			printf("%d. kutu soru %d/%d \t", n ,sayac3++, erisim.kutuda_soru_sayisi[n - 1]);
		for(sayac2 = 1 ; erisim.kutular[sayac1][sayac2] != '\0' ; ++sayac2){
			if(erisim.kutular[sayac1][sayac2] == '#'){
				++asagi;
				if(asagi == 1)
			        printf("\n\n");
			    else if(asagi == 6){
			    	dogru_cevap = erisim.kutular[sayac1][sayac2 + 1];
			        break;
			    }
			    else
			        putchar('\n');
			    printf("\t\t\t  %c) ",secenek++);
			}
			else
		        printf("%c",erisim.kutular[sayac1][sayac2]);
		}
		printf("\n\n\t\t");
	    cevap = toupper(kontrol_char(girdi));
	    elek(0);
		   
	    if(cevap == dogru_cevap){
		    printf("Cevap do�ru. ");
		    if( erisim.kutular[sayac1][0] != 53){
		        erisim.kutular[sayac1][0] = erisim.kutular[sayac1][0] + 1;
		        ++erisim.kutuda_soru_sayisi[n];
		    }
		    veri_isle();
		    elek(1);
	    }
	else{
		printf("Cevap yanl��. Do�ru cevap: %c  ",dogru_cevap);
		if( erisim.kutular[sayac1][0] != 49){
		    erisim.kutular[sayac1][0] = erisim.kutular[sayac1][0] - 1;
		    --erisim.kutuda_soru_sayisi[n];
		}
		veri_isle();
		elek(1);
	}
	    }
	else
	    continue;
	
	system("cls");
	}
	printf("\n\n\t\t\t");
	if(kutu_bos == true)
	    printf("Kutu bo�.");
	else{
		veri_isle();
	    printf("Test bitti.  ");
	}
	elek(1);
	
	kutular();
}

void bilgi_ekle(void){ /*�lk kutuya bilgi eklenir.*/
	char girdi,cevap;
	int sayac,sayac2,sayac3;
	int karar;
	
	while(1){
		sayac = 0;
		erisim.kutular[erisim.satir_sonu][sayac++] = '1';
	    erisim.kutular[erisim.satir_sonu][sayac++] = ' ';
	printf("Soruyu yaz�n: ");
	while( ( girdi=getchar() ) != '\n'){
		erisim.kutular[erisim.satir_sonu][sayac] = tr_ceviri(girdi);
		++sayac;
	}
	erisim.kutular[erisim.satir_sonu][sayac] = '#';
	++sayac;
	printf("\n");
	
	for(sayac2 = 0 ; sayac2 < 5 ; ++sayac2){
		printf("%c se�ene�ini yazin: ",65 + sayac2);
		while( (girdi = getchar() ) != '\n'){
		    erisim.kutular[erisim.satir_sonu][sayac++] = tr_ceviri(girdi);
		}
		erisim.kutular[erisim.satir_sonu][sayac++] = '#';
		
	}
	printf("\nDogru se�ene�i yaz�n: ");
	
	erisim.kutular[erisim.satir_sonu][sayac++] = toupper( kontrol_char(cevap) );
	erisim.kutular[erisim.satir_sonu][sayac] = '#';
	++erisim.satir_sonu;
	++erisim.kutuda_soru_sayisi[0];
	
	printf("\n1. Devam et\n2. Geri\n\t\t");
	
	switch(kontrol(karar,1,2)){
		case 1:
			veri_isle();
			elek(1);
			break;
		case 2:
			veri_isle();
			elek(1);
			menu_kutu();
			break;
	}
    }
}

void veri_isle(void){ /*Listedeki veriler text dosyas�na i�lenir. */
	FILE *fptr;
	fptr = fopen("depo.txt","wb");
	
	int sayac1,sayac2;
	for(sayac1 = 0 ; sayac1 < erisim.satir_sonu + 1 ; ++sayac1){
		for(sayac2 = 0 ; erisim.kutular[sayac1][sayac2] != '\0' ; ++sayac2){
		    fprintf(fptr,"%c",erisim.kutular[sayac1][sayac2]);
		}
	}
	fclose(fptr);
}

void bilgi_sil(void){
	int sayac1,sayac2,sayac3,sayac4;
	int cevap,sira_sayi[erisim.satir_sonu],silme_sirasi;
	char secenek,cevap2;
	sayac1 = 0;
	sayac4 = 1;
	while(sayac1 < 5){ /*Kutular 1'den 5'e s�ralan�r.*/
		bool empty = false;  /*Kutu bo�sa false olarak kal�r.*/
		sayac3 = 0;
		printf("KUTU %d\n---------------------------\n",sayac1 + 1);
		while(sayac3 < erisim.satir_sonu){ /*T�m sorular�n �zerinden ge�ilir.*/
		    if(erisim.kutular[sayac3][0] == 49 + sayac1){  /*E�er soru istenilen kutunun i�inde ise, o kutunun i�inde g�sterilir.*/
		    	empty = true ;
		    	sira_sayi[sayac4 - 1]=sayac3;   /*G�sterilecek karakter dizisinin listedeki konumunu tutar.*/
		    	printf("%d - ",sayac4++);       /*Sorulara numaralar verilir.*/
		    	
		        for(sayac2 = 2 ; erisim.kutular[sayac3][sayac2] != '#' ; ++sayac2){ /*Soru yaz�l�r.*/
			    putchar( erisim.kutular[sayac3][sayac2] );
		        }
			    printf("\n");
	        }
	        ++sayac3;
	    }
	    if(!empty)
	        printf("Kutu bo�\n");
	    printf("---------------------------\n\n");
	    ++sayac1;
	}
	printf("q. Geri\t\t");
	
	while( scanf("%d",&cevap) != 1 && cevap < 1 || cevap > sayac4 - 1 ){/*Kullan�c�n�n cevab� integer de�ilse veya istenilen aral�kta de�ilse*/
		if( scanf("%c",&cevap2) == 1 && cevap2 == 'Q' || cevap2 == 'q' ){ /*Girdi karakter ise ve q ise fonksiyondan ��k�l�r.*/
		    elek(1);
			ayarlar();
		}
		printf("Yanl�� girdi.L�tfen tekrar deneyin: ");
		elek(0);
	}
	for(silme_sirasi = sira_sayi[cevap - 1] ; silme_sirasi < erisim.satir_sonu ; ++silme_sirasi){ /*Soruya verilen numara girildi�inde*/
	    strcpy(erisim.kutular[silme_sirasi],erisim.kutular[silme_sirasi + 1]);                    /*sira_sayi dizisinde depolanm�� olan*/
    }                               															  /*Listedeki yeriyle sorunun �st�ne,*/
    elek(1);																				      /*Bir sonraki soru kopyalan�r ve b�ylece*/
    printf("\n\n\n\t\t\t\tSoru silindi.");                                       			      /*Soru silinir.*/
    elek(1);
    veri_isle();
    --erisim.satir_sonu;
    bilgi_sil();

}

void elek(int i){  /*Tamponda duran ve istenmeyen girdileri temizler.*/
	while(getchar() != '\n')
		continue;
	if(i)
	    system("cls");
}

int kontrol(int girdi,int alt,int ust){  /*Girilen integer'�n verilen aral�kta olup olmad���n� kontrol eder.*/
	while( ( scanf("%d",&girdi) ) != 1 && girdi < alt || girdi > ust){
		printf("Yanl�� girdi.L�tfen tekrar deneyin: ");
		elek(0);
	}
	return girdi;
}

char kontrol_char(char cevap){      /*Verilen cevab�n a ve e aras�nda olup olmad���n� kontrol eder. */
	while( ( cevap=getchar() ) < 'A' || cevap > 'E' && cevap < 'a' || cevap > 'e'){
		if(cevap == ' ' || cevap == '\n')
			continue;
		printf("Yanl�� girdi.L�tfen tekrar deneyin: ");
		elek(0);
	}
	return cevap;
}

char tr_ceviri(char gelen){      /*Girdi fonksiyonlar� ile girdi il�nd���nda T�rk�e karakterlerde s�k�nt� ��k�yor.Bu fonksiyon bunu d�zeltir.*/
	int tr_char[12][2] = { {-89,-16} , {-127,-4} , {-97,-2} , {-115,-3} , {-108,-10} , {-121,-25},
	{-90,-48} , {-102,-36} , {-98,-34} , {-104,-35} , {-103,-42} , {-128,-57} },sayac;
	for(sayac = 0 ; sayac < 12 ; ++sayac){
		if(gelen == tr_char[sayac][0]){
		    gelen = tr_char[sayac][1];
		    break;
		}
	}
	return gelen;
}  






