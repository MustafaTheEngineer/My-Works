#include <stdio.h>
#include <math.h>
int main(){
	
	int girdi1,aktarim,sayac1=0,bolucu,sayac2,degisken1=1,sayac3=0;
	printf("Palindrom Sayi Tespit Programi\n");
	printf("Bir tamsayi girin: ");
	scanf("%d",&girdi1);
	aktarim=girdi1;
	while(girdi1!=0){
		girdi1/=10;
		++sayac1;
	}
	sayac2=sayac1;
	bolucu=pow(10,sayac1-1);
	if(sayac1%2==1){
		while(sayac2-1!=(sayac1-1)/2){
			if((aktarim/bolucu)%10==(aktarim%(degisken1*10)/degisken1)){
				++sayac3;
			}
			
			--sayac2;
			bolucu/=10;
			degisken1*=10;
	}
	if(sayac3==(sayac1-1)/2){
			printf("%d bir palindrom sayidir.",aktarim);
			}
			else{
				printf("%d bir palindrom sayi degildir.",aktarim);
			}
		}
		else{
				while(sayac2!=sayac1/2){
			if((aktarim/bolucu)%10==(aktarim%(degisken1*10)/degisken1)){
				++sayac3;
			}
			
			--sayac2;
			bolucu/=10;               
			degisken1*=10;
	}
	if(sayac3==sayac1/2){
			printf("%d bir palindrom sayidir.",aktarim);
			}
			else{
				printf("%d bir palindrom sayi degildir.",aktarim);
			}
		}
	return 0;
}
