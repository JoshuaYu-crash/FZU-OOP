#include<stdio.h>
#include<string.h>
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
int main(){
	printf("欢迎使用，请按以下要求输入：\n1.该程序仅支持两位数以内数字输入，计算结果也应保证在两位数范围内且不为负数\n2.在程序第一行应定义变量，遵循如下格式(整数 定义变量名 等于 定义数字)\n3.输入数字请遵循以下规范:\n\t(1~9):一~~九、\n\t(11~19):十一~~十九、\n\t(21~29、31~39、···):二十一~~二十九、三十一~~三十九、···\n\t(10的倍数):十、二十、三十、···\n4.变量增加减少请按照(定义变量名 增加/减少 数字)进行\n5.查看变量结束程序请按如下格式(看看 定义变量名)\n"); 
	char name[20],command[100][20];
	int i=0,target;
	scanf("%s",command[i++]);
	if(strcmp(command[i-1],keywords[0])==0){
		scanf("%s",name);
		scanf("%s",command[i++]);
		if(strcmp(command[i-1],keywords[1])==0){
			scanf("%s",command[i++]);
			target=hz_to_num(command[i-1]);
			if(target==-1){
				printf("数字格式出错，请参考要求第2点");
				return 0;
			}
		}
		else{
			printf("输入错误！(应输入：等于 ~)\n");
			return 0;
		}		
	}
	else{
		printf("错误，请先定义变量！(应输入：整数 ~)\n");
		return 0;
	}
	while(1){
		scanf("%s",command[i++]);
		if(strcmp(command[i-1],keywords[4])==0){
			scanf("%s",command[i++]);
			if(strcmp(command[i-1],name)==0){
				num_to_hz(target);
				return 0;
			}
			else{
				printf("输入名称错误！(请输入：定义变量名)\n");
				return 0;
			}
		}
		else if(strcmp(command[i-1],name)==0){
			scanf("%s",command[i++]);
			scanf("%s",command[i++]);
			if(hz_to_num(command[i-1])==-1){
				printf("数字格式出错，请参考要求第2点");
				return 0;
			}
			if(calculate(target,command[i-2],command[i-1])==-1){
				return 0;
			}
			else{
				target=calculate(target,command[i-2],command[i-1]);
			}	
		}
		else{
			printf("输入名称错误！(请输入：定义变量名 或 看看)\n");
			return 0; 
		}
	}	
}
