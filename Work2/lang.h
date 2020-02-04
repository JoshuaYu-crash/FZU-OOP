#include<stdio.h>
#include<string.h>
int hz_judge(char* str);
int calculate(int num,char* command,char* number);
int hz_to_num(char* str);
int num_to_hz(int num);
char hz[11][10]={"零","一","二","三","四","五","六","七","八","九","十"};
char keywords[5][20]={"整数","等于","增加","减少","看看"};
int hz_judge(char* str){
	int i;
	for(i=0;i<11;i++){
		if(strcmp(str,hz[i])==0){
			return i;
		}
	}
	return -1;
} 
int calculate(int num,char* command,char* number){
	int n;
	if(strcmp(command,keywords[2])==0){
		n=hz_to_num(number);
		return num+=n;
	}
	else if(strcmp(command,keywords[3])==0){
		n=hz_to_num(number);
		return num-=n;
	}
	else{
		return -1;
	}
}
int hz_to_num(char* str)
{
	char a[3],b[3],c[3];
	int len,i,j;
	len=strlen(str);
	if(len==4){
		a[0]=str[0];
		a[1]=str[1];
		a[2]=0;
		b[0]=str[2];
		b[1]=str[3];
		b[2]=0;
		if((strcmp(a,hz[10])!=0&&strcmp(b,hz[10])!=0)||(strcmp(a,hz[10])==0&&strcmp(b,hz[10])==0)){
			return -1;
		}
		else if(strcmp(a,hz[10])==0){
			return hz_judge(b)+10;
		}
		else{
			return hz_judge(a)*10;
		}
	}
	else if(len==6){
		a[0]=str[0];
		a[1]=str[1];
		a[2]=0;
		c[0]=str[2];
		c[1]=str[3];
		c[2]=0;
		b[0]=str[4];
		b[1]=str[5];
		b[2]=0;
		if(strcmp(a,hz[1])==0||strcmp(c,hz[10])!=0||hz_judge(a)==-1||hz_judge(b)==-1){
			return -1;
		}
		return hz_judge(a)*10+hz_judge(b);
	}
	else if(len==2){
		if(hz_judge(str)==-1){
			return -1;
		}
		return hz_judge(str);
	}
}
int num_to_hz(int num){
	if(num>=10){
		if(num%10==0){
			if(num==10){
				printf("%s\n",hz[10]);
			}
			else{
				printf("%s%s\n",hz[num/10],hz[10]);
			}
		}
		else{
			if(num<20){
				printf("%s%s\n",hz[10],hz[num%10]);
			}
			else{
				printf("%s%s%s\n",hz[num/10],hz[10],hz[num%10]);
			}
		}
	}
	else{
		printf("%s\n",hz[num]);
	}
}
