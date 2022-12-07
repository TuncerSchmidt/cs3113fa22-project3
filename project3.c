#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct disk{
	char processMethod[50];
	char processName[50];
	int sizeProcess;
	int addressNo;
};
typedef struct disk disk;
int main(int argc, char **argv){
	//disk disks[400];
	char NameTutucu[16];
	int diskSayaci = 0;
	int Sayitutucu = 0;
	int numQuantum = atoi(argv[1]);
	int numProcess = atoi(argv[2]);
	int numSpace = atoi(argv[3]);
	char* modelName = argv[4];
	int space[numSpace];
	int checker =0;
	int redFlag = 0;
	disk disks[numSpace];
	for(int i = 0; i<numSpace; i++){
		space[i] = 0;
	}
int checkForAlloc(int num3, int num2){
	//int redFlag = 0;
	//int num1 = 0;
	//int num2 = 0;
	int num1 = num3;
//	num1 = 0;
	//int checker = 0;
	int m;
	for(m =num1; m< numSpace; m++){
		num1 = num1+1;
		//printf("%s %d %s","--", m, "--");
		if(space[m] ==0){
//		printf("%s%d%s","<", Sayitutucu, ">"); 
			num2 = num2 + 1;
		  //num1 = num1 + 1;
		     	if(m+1 < numSpace){
				if(space[m+1] ==0 && num2<Sayitutucu){
				//num2 = num2 + 1;
				//printf("%s %d %s", "<", num2, ">");
				}else{
					break;
				}

			}else{
				redFlag = redFlag + 1;
				if(redFlag == 2){
				printf("%s\n", "DEADLOCK DETECTED");
				break;	
				}
				printf("%s %s %d\n", "FAIL REQUEST",  NameTutucu, Sayitutucu); 
				break;
			}
		}}		
				if(num2 == Sayitutucu){
				//	printf("%s %d %d %d %s", "=>", Sayitutucu, num1, num2,  "<=");
					//num1 = num1-1;
					int start = num1-num2;
					
					for(int k =  start; k< num1; k++){
					//	printf("%s %d %s","=>",num1, "<=");
						space[k] = 1;
                                                
					} 
					
				//	printf("%s%d%s","<", start, ">");
					strcpy(disks[start].processMethod, "ALLOCATED");
					strcpy( disks[start].processName, NameTutucu);
				       disks[start].sizeProcess = num2;
			       		disks[start].addressNo = start;	
				 	//diskSayaci = diskSayaci + 1;
					//printf("%s%d%s%d%s", "<", num1,"-", num2, ">");
					checker = 1;
					printf("%s %s %d\n", disks[start].processMethod, disks[start].processName, disks[start].addressNo);	
					//num1 = num1-1;
					
					num2= 0;
				}else{
					num2 = 0;
					//printf("%s", "buradayim");
					checkForAlloc(num1, num2);

				}		
		       
	
	
	if(checker == 0){
		
		printf("%s %s %d\n", "FAIL REQUEST", NameTutucu, Sayitutucu);
	}
	return 0;
}
int checkForFree(){
	int checker = 0;
	for(int i = 0; i< numSpace; i++){
		if(strcmp(disks[i].processName, NameTutucu)==0){
			strcpy(disks[i].processName, "saldik");
			for(int k = disks[i].addressNo; k<disks[i].addressNo+disks[i].sizeProcess; k++){
				space[k] = 0;
				//printf("%s%d%s","<", i,">");
			}
			checker = 1;
			printf("%s %s %d %d\n", "FREE", NameTutucu, disks[i].sizeProcess, disks[i].addressNo);
			break;
		}
	}
	if(checker == 0){
		printf("%s %s\n", "FAIL RELEASE",NameTutucu); 
	}
}

int ListAvailable(){
	int siraCounter = 0;
	int flag = 0;
	int counter = 0;
	for(int i = 0; i< numSpace; i++){
		siraCounter = siraCounter + 1;
		if(space[i] == 0){
			flag = 1;
			counter = counter + 1;
			if(space[i+1]==0){
				//counter = counter + 1;
			}else{
				printf("%s%d%s %d%s", "(", counter, ",", siraCounter-counter, ")");
				//printf("%s%d%s","<",counter,">");
				counter = 0;
			}
		}
	}
	if(flag == 0){
		printf("%s", "NONE");
	}
	printf("\n");
	return 0;
}

int ListAssigned(){
	int counter= 0;
	for(int i = 0; i<numSpace; i++){
		if(strcmp(disks[i].processMethod, "ALLOCATED")==0 && strcmp(disks[i].processName, "saldik") !=0){
			//printf("%s","buradayim");
			counter = 1;
			printf("%s%s%s %d%s %d%s ", "(", disks[i].processName, ",", disks[i].sizeProcess, ",", disks[i].addressNo, ")");
		}
	}
	if(counter ==0){
		printf("%s", "NONE");
	}
	printf("\n");
	return 0;
}

int FINDA(){
	int counter = 0;
	for(int i = 0; i<numSpace; i++){
		if(strcmp(NameTutucu, disks[i].processName)==0){
			counter = 1;
			printf("%s%s%s%d%s%d%s", "(", disks[i].processName, ",", disks[i].sizeProcess, ",", disks[i].addressNo, ")");
			break;
		}
	}
	if(counter == 0){
		printf("%s\n", "FAULT");
	}
	return 0;
}
	//FILE *ptr = fopen("0.ins", "r");
	//FILE *ptr1 = fopen("1.ins", "r");
	//FILE *ptr2 = fopen("2.ins", "r");
	//FILE *ptr3 = fopen("3.ins", "r");
	//FILE *ptr4 = fopen("4.ins", "r");
	//FILE *ptr5 = fopen("5.ins", "r");
	//FILE *ptr6 = fopen("6.ins", "r");
	//FILE *ptr7 = fopen("7.ins", "r");

	char line[50];

	FILE *a[8];
	
	for(int i =0; i<8; i++){
		char filename[100];
		//printf("%s", "buradayim");
		sprintf(filename, "%d.ins", i);
		a[i] = fopen(filename, "r");
	}
	
	int processCounter = 0;
	//while(processCounter < numProcess){
		
	//}

	//fgets(line, 50, a[1]);
	int sayac = 0;
	int sirasayac = 0;
	if(strcmp(modelName, "FIRSTFIT")==0) {
		while(1){
	   //while(processCounter < numProcess){
	//	   for(int i=0; i< numProcess; i++){
	//	   
	//	   for(int k = 0; k<numQuantum; k++){
		if(fgets(line, 50, a[1])== NULL){ 
			//fclose(a[i]);
			//processCounter = processCounter + 1;
			break; 
		};
		char tempMethod[50];
		char tempName[50];
		int tempSize = 0;
	    	
	     	sscanf(line, "%s %s %d",  tempMethod, tempName, &tempSize);
		printf("%s%s%d", tempMethod, tempName, tempSize);
		Sayitutucu = tempSize;
		strcpy(NameTutucu, tempName);
	//	printf("%s", tempName);
	 if(strcmp(tempMethod, "REQUEST")==0){
		 //printf("%s", "Buradayim");
		// int sayac = 0;
		// int sirasayac = 0;
		 checkForAlloc(sirasayac, sayac);
	 }else if(strcmp(tempMethod, "RELEASE")==0){
	    	sayac = 0;
		 sirasayac = 0;
		checkForFree();
	    }
	 else if(strcmp(tempName, "AVAILABLE")==0){
	 	 ListAvailable();
	 }else if(strcmp(tempName, "ASSIGNED")==0){
	 	ListAssigned();
		//printf("%s", "buradyim");
	 }else if(strcmp(tempName, "FIND")==0){
	 	FINDA();
	 }
	   }
		   }
	 //}
	//}
	return 0;
}

