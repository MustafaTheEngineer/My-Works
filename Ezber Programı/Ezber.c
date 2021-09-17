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

void veri_alma(void){   /*Metin dosyasýnda bulunan verileri diziye alýr.*/
	FILE *fptr;
	char read,read_list,read_row;
    int satir,sutun,counter1;
    fptr = fopen("depo.txt","rb");
    
	if(fptr == NULL){
	    printf("Hiçbir veri bulunamadý. ");
	    elek(0);
	    fclose(fptr);
    }
    satir = 0;
    sutun = 0;

    while( fscanf(fptr,"%c",&read) != EOF ){
    	erisim.kutular[satir][sutun] = read;  /*Dizinin baþýnda olmasý gereken sayýyý alýr(Sorunun hangi seviyede olduðunu belirlemek için).*/
    	++erisim.kutuda_soru_sayisi[read - 49];  /*Hangi seviye sorudan kaç tane olduðunu depolar.*/
    	++sutun;
    	counter1 = 0;
    	
    	while(counter1 != 7){
    		fscanf(fptr,"%c",&read_row);
    		if(read_row == '#'){          /*Soru ve cevaplar birbirinden # iþareti ile ayrýlýr.Ýlk #'den sonra þýklar gelir.*/
    		    ++counter1;               /*Son #'den önce doðru cevabýn hangisi ollduðu yazýlýdýr.*/
    		}
    		erisim.kutular[satir][sutun] = read_row;
    		++sutun;                      /*7. #'den sonra diðer soru gelir.*/
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
	printf("\t\t\t\t1. Kutu Menüsüne Git\
	        \n\t\t\t\t2. Yardým\
			\n\t\t\t\t3. Çýkýþ \t ");

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
	         \n\t\t\t\t2. Hepsini ilk kutuya taþý\
	        \n\t\t\t\t3. Tüm veriyi sil\
			\n\t\t\t\t4. Geri\n\t\t\t\t\t");
	switch( kontrol(girdi1,1,4) ){
		case 1:
			elek(1);
			bilgi_sil();
			break;
		case 2:
			elek(1);
			verileri_duzenle('1',"Tüm sorularý ilk kutuya taþýmak istediðinizden emin misiniz?");
			break;
		case 3:
			elek(1);
			verileri_duzenle('\0',"Tüm verileri silmek istediðinizden emin misiniz?");
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
	\t\t\t\t1. Evet      2.Hayýr\n\n\t\t\t\t",metin);
	switch( kontrol(girdi,1,2) ){
		case 1:
			for(i = 0 ; i < erisim.satir_sonu ; ++i){
				erisim.kutular[i][0] = duzen;
			}
			veri_isle();
			system("cls");
			elek(1);
			printf("\n\n\n\t\t\tTamamlandý.");
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
	printf("Beþ adet kutunuz olduðunu var sayýn. Baþta sizden ilk kutu için bilgiler girmeniz istenecek.\
Bir soru ve 5 seçenek\ngirmelisiniz. Girdiðiniz bilgiler ilk kutuda depolanýr. Teste baþlarsanýz, size, \
sizin girdiðiniz sorular sorulacak.\nEðer doðru seçeneði seçerseniz bilgi bir sonraki kutuya taþýnacak.\
Eðer oradayken de bilirseniz diðerine ve bu þekilde \nson kutuya kadar gidecek.Eger son kutuya geldiðinizde de\
 soruyu bilirseniz, bu bilgiyi artýk öðrenmiþsiniz demektir.\nAncak eðer soruyu bilemezseniz, bilgi bir önceki\
kutuya geri dönecek. Tüm bilgileri son kutuya getirmelisiniz.\n");
	printf("\nGeri dönmek için 1 girin: ");
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
void test(int n){                                /*Hangi seviye seçilmiþse o seviyenin sorularý kullanýcýya sorulur.*/
	int sayac1,sayac2,sayac3,secenek;
	short asagi;
	char girdi,dogru_cevap,cevap,seviye = (48 + n);    /*48 sayýsal olarak '0'ýn yerini tutar.*/
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
		    printf("Cevap doðru. ");
		    if( erisim.kutular[sayac1][0] != 53){
		        erisim.kutular[sayac1][0] = erisim.kutular[sayac1][0] + 1;
		        ++erisim.kutuda_soru_sayisi[n];
		    }
		    veri_isle();
		    elek(1);
	    }
	else{
		printf("Cevap yanlýþ. Doðru cevap: %c  ",dogru_cevap);
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
	    printf("Kutu boþ.");
	else{
		veri_isle();
	    printf("Test bitti.  ");
	}
	elek(1);
	
	kutular();
}

void bilgi_ekle(void){ /*Ýlk kutuya bilgi eklenir.*/
	char girdi,cevap;
	int sayac,sayac2,sayac3;
	int karar;
	
	while(1){
		sayac = 0;
		erisim.kutular[erisim.satir_sonu][sayac++] = '1';
	    erisim.kutular[erisim.satir_sonu][sayac++] = ' ';
	printf("Soruyu yazýn: ");
	while( ( girdi=getchar() ) != '\n'){
		erisim.kutular[erisim.satir_sonu][sayac] = tr_ceviri(girdi);
		++sayac;
	}
	erisim.kutular[erisim.satir_sonu][sayac] = '#';
	++sayac;
	printf("\n");
	
	for(sayac2 = 0 ; sayac2 < 5 ; ++sayac2){
		printf("%c seçeneðini yazin: ",65 + sayac2);
		while( (girdi = getchar() ) != '\n'){
		    erisim.kutular[erisim.satir_sonu][sayac++] = tr_ceviri(girdi);
		}
		erisim.kutular[erisim.satir_sonu][sayac++] = '#';
		
	}
	printf("\nDogru seçeneði yazýn: ");
	
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

void veri_isle(void){ /*Listedeki veriler text dosyasýna iþlenir. */
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
	while(sayac1 < 5){ /*Kutular 1'den 5'e sýralanýr.*/
		bool empty = false;  /*Kutu boþsa false olarak kalýr.*/
		sayac3 = 0;
		printf("KUTU %d\n---------------------------\n",sayac1 + 1);
		while(sayac3 < erisim.satir_sonu){ /*Tüm sorularýn üzerinden geçilir.*/
		    if(erisim.kutular[sayac3][0] == 49 + sayac1){  /*Eðer soru istenilen kutunun içinde ise, o kutunun içinde gösterilir.*/
		    	empty = true ;
		    	sira_sayi[sayac4 - 1]=sayac3;   /*Gösterilecek karakter dizisinin listedeki konumunu tutar.*/
		    	printf("%d - ",sayac4++);       /*Sorulara numaralar verilir.*/
		    	
		        for(sayac2 = 2 ; erisim.kutular[sayac3][sayac2] != '#' ; ++sayac2){ /*Soru yazýlýr.*/
			    putchar( erisim.kutular[sayac3][sayac2] );
		        }
			    printf("\n");
	        }
	        ++sayac3;
	    }
	    if(!empty)
	        printf("Kutu boþ\n");
	    printf("---------------------------\n\n");
	    ++sayac1;
	}
	printf("q. Geri\t\t");
	
	while( scanf("%d",&cevap) != 1 && cevap < 1 || cevap > sayac4 - 1 ){/*Kullanýcýnýn cevabý integer deðilse veya istenilen aralýkta deðilse*/
		if( scanf("%c",&cevap2) == 1 && cevap2 == 'Q' || cevap2 == 'q' ){ /*Girdi karakter ise ve q ise fonksiyondan çýkýlýr.*/
		    elek(1);
			ayarlar();
		}
		printf("Yanlýþ girdi.Lütfen tekrar deneyin: ");
		elek(0);
	}
	for(silme_sirasi = sira_sayi[cevap - 1] ; silme_sirasi < erisim.satir_sonu ; ++silme_sirasi){ /*Soruya verilen numara girildiðinde*/
	    strcpy(erisim.kutular[silme_sirasi],erisim.kutular[silme_sirasi + 1]);                    /*sira_sayi dizisinde depolanmýþ olan*/
    }                               															  /*Listedeki yeriyle sorunun üstüne,*/
    elek(1);																				      /*Bir sonraki soru kopyalanýr ve böylece*/
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

int kontrol(int girdi,int alt,int ust){  /*Girilen integer'ýn verilen aralýkta olup olmadýðýný kontrol eder.*/
	while( ( scanf("%d",&girdi) ) != 1 && girdi < alt || girdi > ust){
		printf("Yanlýþ girdi.Lütfen tekrar deneyin: ");
		elek(0);
	}
	return girdi;
}

char kontrol_char(char cevap){      /*Verilen cevabýn a ve e arasýnda olup olmadýðýný kontrol eder. */
	while( ( cevap=getchar() ) < 'A' || cevap > 'E' && cevap < 'a' || cevap > 'e'){
		if(cevap == ' ' || cevap == '\n')
			continue;
		printf("Yanlýþ girdi.Lütfen tekrar deneyin: ");
		elek(0);
	}
	return cevap;
}

char tr_ceviri(char gelen){      /*Girdi fonksiyonlarý ile girdi ilýndýðýnda Türkçe karakterlerde sýkýntý çýkýyor.Bu fonksiyon bunu düzeltir.*/
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






