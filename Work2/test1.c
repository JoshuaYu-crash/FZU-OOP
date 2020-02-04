#include"lang.h"
char str[10][8]={"六十五","九十六","二十七","六十四","九十一","十四","二十","十九","四十三","九十二"}; 
int main()
{
	if(hz_to_num(str[0])==65){
		printf("六十五 %d pass\n",hz_to_num(str[0]));
	}
	else{
		printf("OutPut is %d,WRONG!!!\n",hz_to_num(str[0]));
	}
	if(hz_to_num(str[1])==96){
		printf("九十六 %d pass\n",hz_to_num(str[1]));
	}
	else{
		printf("OutPut is %d,WRONG!!!\n",hz_to_num(str[1]));
	}
	if(hz_to_num(str[2])==27){
		printf("二十七 %d pass\n",hz_to_num(str[2]));
	}
	else{
		printf("OutPut is %d,WRONG!!!\n",hz_to_num(str[2]));
	}
	if(hz_to_num(str[3])==64){
		printf("六十四 %d pass\n",hz_to_num(str[3]));
	}
	else{
		printf("OutPut is %d,WRONG!!!\n",hz_to_num(str[3]));
	}
	if(hz_to_num(str[4])==91){
		printf("九十一 %d pass\n",hz_to_num(str[4]));
	}
	else{
		printf("OutPut is %d,WRONG!!!\n",hz_to_num(str[4]));
	}
	if(hz_to_num(str[5])==14){
		printf("十四 %d pass\n",hz_to_num(str[5]));
	}
	else{
		printf("OutPut is %d,WRONG!!!\n",hz_to_num(str[5]));
	}
	if(hz_to_num(str[6])==20){
		printf("二十 %d pass\n",hz_to_num(str[6]));
	}
	else{
		printf("OutPut is %d,WRONG!!!\n",hz_to_num(str[6]));
	}
	if(hz_to_num(str[7])==19){
		printf("十九 %d pass\n",hz_to_num(str[7]));
	}
	else{
		printf("OutPut is %d,WRONG!!!\n",hz_to_num(str[7]));
	}
	if(hz_to_num(str[8])==43){
		printf("四十三 %d pass\n",hz_to_num(str[8]));
	}
	else{
		printf("OutPut is %d,WRONG!!!\n",hz_to_num(str[8]));
	}
	if(hz_to_num(str[9])==92){
		printf("九十二 %d pass\n",hz_to_num(str[9]));
	}
	else{
		printf("OutPut is %d,WRONG!!!\n",hz_to_num(str[9]));
	}
}
