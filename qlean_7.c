#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int plot[120]={	-1,-1,-1,-1,-1,-1,-1,-1,-1 ,-1,
				-1,-1,-1,-1,-1,-1,-1,-1,-1 ,-1,
				-1, 0, 0, 0, 0, 0, 0, 0, 0 ,-1,
				-1, 0,-1,-1, 0,-1,-1,-1, 0 ,-1,
				-1, 0, 0,-1, 0, 0, 0, 0, 0 ,-1,
				-1,-1,-1,-1, 0,-1,-1,-1, 0 ,-1,
				-1, 0, 0, 0, 0,-1, 0,-1, 0 ,-1,
				-1, 0,-1,-1, 0,-1, 0,-1, 0 ,-1,
				-1, 0,-1,-1, 0, 0, 0,-1,-1 ,-1,
				-1, 0, 0, 0, 0,-1, 0, 0,1,-1,
				-1,-1,-1,-1,-1,-1,-1,-1,-1 ,-1,
				-1,-1,-1,-1,-1,-1,-1,-1,-1 ,-1};
int rand_num(int paturn);
void change_plot();
void loot();
int check();
void qchenge();
void plotfile();
void plota();
void set();
void result();
void eplcheack();
void resultadd();
double qlean[120][4];
int flag_act[4];
int max;
int maxloot=5;
int beforeplot=0;
int finish=0;
int nowplot=0;
int root[50000];
int data=0;

int rootdata=0;
int outputroot=0;
int main(void){
	int counter;
	int block_no;
	srand(time(NULL));
    	
	    for(counter=0;counter<=12;counter++){
		    for(block_no=0;block_no<4;block_no++){
		    	qlean[counter][block_no]=0;
		    }
	    }
	    for(counter=0;counter<100;counter++){
	    	printf("\n\n");
		    nowplot=21;
            root[data]=nowplot;
            data++;
		   // data=0;
            while(counter<100){
                int width;
                printf("\n,%d , %d, %d ,%d\n",nowplot,data,counter,finish);
                for(width=0;width<4;width++){
                    printf("%f\n",qlean[nowplot][width]);
                }
                max=5;
                     
                loot();
				eplcheack();
				change_plot();
				root[data]=nowplot;
				data++;
                qchenge();
                counter=counter+check();
				if(nowplot==98){
					finish++;
					break;
				}
                if(data>50000){
                    break;   
                }	

			}
            if(data>50000){
                break;   
            }	
	    }
      
	result();
}


void qchenge(){
	if(!(nowplot==21)){
		qlean[beforeplot][max]=(0.8*qlean[beforeplot][max]+0.2*(plot[nowplot]+0.9*qlean[nowplot][max]));
	}
}
int rand_num(int paturn){
	int number=(int)((double)(rand()/(double)(0x7fffffff))*3);
	return number%paturn;
}
void change_plot(){
	int wid;
	if(max==5){
		max=rand_num(4);
	}
	beforeplot=nowplot;
	if(max==0){
		nowplot=nowplot+10;
	}else if(max==1){
		nowplot=nowplot+1;
	}else if(max==2){
		nowplot=nowplot-10;
	}else if(max==3){
		nowplot=nowplot-1;
	}	

}
void loot(){
	int	wide=0;
	static int epsilon=5;
	
	epsilon=epsilon-1;
	if(epsilon){
		for(wide=0;wide<4;wide++){
			if(qlean[nowplot][wide]>qlean[nowplot][maxloot]){
				maxloot=wide;
			
			}
		}
	}else{
		max=5;
	}
	if(epsilon==0){
		epsilon=5;
	}

	max=maxloot;
}
void eplcheack(){
	if((maxloot==3)&&((qlean[nowplot][3]<=qlean[nowplot][0])||(qlean[nowplot][3]<=qlean[nowplot][1])||(qlean[nowplot][3]<=qlean[nowplot][2]))){
 		max=5;
	}
}
int check(){
	if((nowplot<10)||(nowplot>109)||(max==1||max==3)&&(beforeplot/10!=nowplot/10)){
		
		nowplot=21;
        root[data];
        data++;
		
		printf("\r\n\r\n");
		return 1;			
	}else{
		return 0;
	}
}
void result(){
	
	printf("\n");
    outputroot=finish;
    while(outputroot){
	    while(root[rootdata]!=98){
		    printf("%d ,",root[rootdata]);
		    rootdata++;
	    }
        printf("%d ,",root[rootdata]);
		resultadd();
    }
	printf("\nfin %d",finish);
	printf("\n");
}
void resultadd(){
        rootdata++;
        printf("\n\n");
        outputroot=outputroot-1;
}