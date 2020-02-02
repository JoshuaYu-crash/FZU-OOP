#include<stdio.h>
#include<string.h>
char hz[11][10]={"��","һ","��","��","��","��","��","��","��","��","ʮ"};
char keywords[5][20]={"����","����","����","����","����"};
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
	printf("��ӭʹ�ã��밴����Ҫ�����룺\n1.�ó����֧����λ�������������룬������ҲӦ��֤����λ����Χ���Ҳ�Ϊ����\n2.�ڳ����һ��Ӧ�����������ѭ���¸�ʽ(���� ��������� ���� ��������)\n3.������������ѭ���¹淶:\n\t(1~9):һ~~�š�\n\t(11~19):ʮһ~~ʮ�š�\n\t(21~29��31~39��������):��ʮһ~~��ʮ�š���ʮһ~~��ʮ�š�������\n\t(10�ı���):ʮ����ʮ����ʮ��������\n4.�������Ӽ����밴��(��������� ����/���� ����)����\n5.�鿴�������������밴���¸�ʽ(���� ���������)\n"); 
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
				printf("���ָ�ʽ������ο�Ҫ���2��");
				return 0;
			}
		}
		else{
			printf("�������(Ӧ���룺���� ~)\n");
			return 0;
		}		
	}
	else{
		printf("�������ȶ��������(Ӧ���룺���� ~)\n");
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
				printf("�������ƴ���(�����룺���������)\n");
				return 0;
			}
		}
		else if(strcmp(command[i-1],name)==0){
			scanf("%s",command[i++]);
			scanf("%s",command[i++]);
			if(hz_to_num(command[i-1])==-1){
				printf("���ָ�ʽ������ο�Ҫ���2��");
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
			printf("�������ƴ���(�����룺��������� �� ����)\n");
			return 0; 
		}
	}	
}
