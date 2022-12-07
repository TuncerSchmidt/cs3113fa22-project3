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
	for(int m =num1; m< numSpace; m++){
		num1 = num1+1;
		//printf("%s %d %s","--", m, "--");
		if(space[m] ==0){
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
				printf("%s", "DEADLOCK");
				return 3;
				break;
			}
		}}		
				if(num2 == Sayitutucu){
				//	printf("%s %d %d %d %s", "=>", Sayitutucu, num1, num2,  "<=");
					//num1 = num1-1;
					int start = num1-num2;
					for(int k =  start; k< num1; k++){
				// 		printf("%s %d %s","=>",num2, "<=");
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
				space[i] = 0;
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
	FILE *ptr = fopen("1.ins", "r");
	char line[50];
	fgets(line, 50, ptr);
	int sayac = 0;
	int sirasayac = 0;
	if(strcmp(modelName, "FIRSTFIT")==0) {
	   while(1){
		if(fgets(line, 50, ptr)== NULL) break;
		char tempMethod[50];
		char tempName[50];
		int tempSize = 0;
	    	
	     	sscanf(line, "%s %s %d",  tempMethod, tempName, &tempSize);
		//printf("%s%s", tempName, "<-");
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
	 }else{
	 	FINDA();
	 }
	 }
	}
	return 0;
}

