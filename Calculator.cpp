#include <stdio.h>
int main(){
	int i=1;
	while(i==1){
		int entry1;
		char entry2;
	    double carpim=1;
	    printf("\n1. Toplama\n2. Cikarma\n3. Carpma\n4. Bolme");
	    printf("\n\nYapmak istediginiz islemi secin(cikmak icin q'ya basin'): ");
	    scanf("%d",&entry1);
	    scanf("%c",&entry2);
		    double sum,case1;
		    char cikis;
		    if(entry2=='q'){
		    	i=0;
			}
		    if(entry1==1){
			    while(1){
				    printf("\nSayi girin(cikmak icin q'ya basin):");
				    scanf("%lf",&case1);
				    scanf("%c",&cikis);
				    sum+=case1;
				    if(cikis=='q'){
					    break;
				    }
				    printf("\n------------------\n%.2lf\n",sum);
				}
			}
				
		    else if(entry1==2){
			    while(1){
				    printf("\nAzalacak sayiyi pozitif girin\n2.Cikartilacak sayiyinin basina - koyun (cikmak icin q'ya basin):");
				    scanf("%lf",&case1);
				    scanf("%c",&cikis);
				    sum+=case1;
				    if(cikis=='q'){
					    break;
				    }
				    printf("\n------------------\n%.2lf\n",sum);
				    
				
			    }
			}
		    else if(entry1==3){
			    while(1){
				    printf("\nSayi girin(cikmak icin q'ya basin):");
				    scanf("%lf",&case1);
				    scanf("%c",&cikis);
				    carpim*=case1;
				    if(cikis=='q'){
				        break;
				    }
				    printf("\n------------------\n%.2lf\n",carpim);
			    }
			    }
		    else if(entry1==4){
			    while(1){
				    double case2,case3,case4;
				    printf("\nBolunen sayiyi girin(cikmak icin q'ya basin): ");
				    scanf("%lf",&case2);
				    printf("\nBolen sayiyi girin(cikmak icin q'ya basin): ");
				    scanf("%lf",&case3);
				    scanf("%c",&cikis);
				    case4=case2/case3;
				    if(cikis=='q'){
					    break;
				    }
				    printf("\n------------------\n%.2lf\n",case4);
			    }
			    }
	    
		}
    

	return 0;
}
