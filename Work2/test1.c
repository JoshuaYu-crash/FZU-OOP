#include"lang.h"
char str[10][8]={"��ʮ��","��ʮ��","��ʮ��","��ʮ��","��ʮһ","ʮ��","��ʮ","ʮ��","��ʮ��","��ʮ��"}; 
int main()
{
	if(hz_to_num(str[0])==65){
		printf("��ʮ�� %d pass\n",hz_to_num(str[0]));
	}
	else{
		printf("OutPut is %d,WRONG!!!\n",hz_to_num(str[0]));
	}
	if(hz_to_num(str[1])==96){
		printf("��ʮ�� %d pass\n",hz_to_num(str[1]));
	}
	else{
		printf("OutPut is %d,WRONG!!!\n",hz_to_num(str[1]));
	}
	if(hz_to_num(str[2])==27){
		printf("��ʮ�� %d pass\n",hz_to_num(str[2]));
	}
	else{
		printf("OutPut is %d,WRONG!!!\n",hz_to_num(str[2]));
	}
	if(hz_to_num(str[3])==64){
		printf("��ʮ�� %d pass\n",hz_to_num(str[3]));
	}
	else{
		printf("OutPut is %d,WRONG!!!\n",hz_to_num(str[3]));
	}
	if(hz_to_num(str[4])==91){
		printf("��ʮһ %d pass\n",hz_to_num(str[4]));
	}
	else{
		printf("OutPut is %d,WRONG!!!\n",hz_to_num(str[4]));
	}
	if(hz_to_num(str[5])==14){
		printf("ʮ�� %d pass\n",hz_to_num(str[5]));
	}
	else{
		printf("OutPut is %d,WRONG!!!\n",hz_to_num(str[5]));
	}
	if(hz_to_num(str[6])==20){
		printf("��ʮ %d pass\n",hz_to_num(str[6]));
	}
	else{
		printf("OutPut is %d,WRONG!!!\n",hz_to_num(str[6]));
	}
	if(hz_to_num(str[7])==19){
		printf("ʮ�� %d pass\n",hz_to_num(str[7]));
	}
	else{
		printf("OutPut is %d,WRONG!!!\n",hz_to_num(str[7]));
	}
	if(hz_to_num(str[8])==43){
		printf("��ʮ�� %d pass\n",hz_to_num(str[8]));
	}
	else{
		printf("OutPut is %d,WRONG!!!\n",hz_to_num(str[8]));
	}
	if(hz_to_num(str[9])==92){
		printf("��ʮ�� %d pass\n",hz_to_num(str[9]));
	}
	else{
		printf("OutPut is %d,WRONG!!!\n",hz_to_num(str[9]));
	}
}
