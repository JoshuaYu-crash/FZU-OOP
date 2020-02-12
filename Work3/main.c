#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void PositiveNumToCN(int num);
void NegativeNumToCN(int num);
void NumToCNJudge(int num);
int CNJudge(char* str);
int CNToNumJudge(char str[]);
int CNToNum_6(char str[]);
int CNToNum_4(char str[]);
int CNToNum_2(char str[]);
int CNToNumLen(char str[]);
char* StrInput();
void SetVar();
void DealVar();
void CalculateVar();
void OutPutVar();


const char CN[11][10]={"��","һ","��","��","��","��","��","��","��","��","ʮ"}; // �������� 
char keywords[7][20]={"����","����","����","����","����","��","����"}; // �ؼ��� 
int target; // ��������Ӧ�ı�������Ϊȫ�ֱ��� 
char name[20]; // ��������������Ķ���Ϊȫ�ֱ��� 


//�ж�Ϊ��������� 
void PositiveNumToCN(int num) {
	if(num>=10){
		if(num%10==0){
			if(num==10){
				printf("%s\n",CN[10]); // �պ�Ϊʮ 
			}
			else{
				printf("%s%s\n",CN[num/10],CN[10]); // ��ʮ���
			}
		}
		else{
			if(num<20){
				printf("%s%s\n",CN[10],CN[num%10]); // ʮ������� 
			}
			else{
				printf("%s%s%s\n",CN[num/10],CN[10],CN[num%10]); // ������� 
			}
		}
	}
	else{
		printf("%s\n",CN[num]); // һλ����� 
	}
}


// �ж�Ϊ��������� 
void NegativeNumToCN(int num) {
	printf("��");
	PositiveNumToCN(-num);
}


// �ж������� 
void NumToCNJudge(int num) {
	if(num>0) {
		PositiveNumToCN(num);
	}
	else if(num<0) {
		NegativeNumToCN(num);
	}
	else {
		printf("%s",CN[0]);
	}
}


// ���ֶԱ�ѭ���ж� 
int CNJudge(char* str) {
	int i;
	for(i=0;i<11;i++){
		if(strcmp(str,CN[i])==0){
			return i;
		}
	}
	return -1;
}


// ��һλ�Ƿ�Ϊ���ж� 
int CNToNumJudge(char str[]) {
	char a[3],*p=str;
	a[0]=str[0];
	a[1]=str[1];
	a[2]=0;
	if(strcmp(keywords[5],a)==0) {
		return -CNToNumLen(p+2);
	}
	else {
		return CNToNumLen(str);
	}
}


// ����Ϊ��
int CNToNum_6(char str[]) {
	char a[3],b[3]; 
	a[0]=str[0];
	a[1]=str[1];
	a[2]=0;
	b[0]=str[4];
	b[1]=str[5];
	b[2]=0;
	return CNJudge(a)*10+CNJudge(b);
}


// ����Ϊ��
int CNToNum_4(char str[]) {
	char a[3],b[3];
	a[0]=str[0];
	a[1]=str[1];
	a[2]=0;
	b[0]=str[2];
	b[1]=str[3];
	b[2]=0;
	if(strcmp(a,CN[10])==0) {
		return CNJudge(b)+10;
	}
	else {
		return CNJudge(a)*10;
	}
}


// ����Ϊ��
int CNToNum_2(char str[]) {
	return CNJudge(str);
} 


// �����ж� 
int CNToNumLen(char str[]) {
	int len=strlen(str);
	if(len==6) {
		return CNToNum_6(str);
	}
	else if(len==4) {
		return CNToNum_4(str);
	}
	else if(len==2) {
		return CNToNum_2(str);
	}
}


// �ַ������� 
char* StrInput() {
	char* str;
    str = (char*)malloc(10);
    scanf("%s",str);
    return str;
}


// �������
void SetVar() {
	char* command=StrInput();
	if(strcmp(command,keywords[0])==0) {
		scanf("%s",name);
		free(command);
		command=StrInput();
		if(strcmp(command,keywords[1])==0) {
			command=StrInput();
			target=CNToNumJudge(command);
			free(command);
		}
		else {
			printf("����Ӧ���룺����\n");
			exit(0);
		}
	}
	else {
		printf("����Ӧ���룺����\n");
		exit(0);
	}
}


// �������
void DealVar() {
	while(1) {
		char* command=StrInput();
		if(strcmp(command,name)==0) {
			CalculateVar();
		}
		else if(strcmp(command,keywords[4])==0) {
			OutPutVar();
		}
		else if(strcmp(command,keywords[6])==0) {
			break; 
		}
		else {
			printf("����Ӧ���룺���� / %s",name);
			exit(0);
		}
		free(command);	
	}
}


// �������
void CalculateVar() {
	char* command=StrInput();
	if(strcmp(command,keywords[2])==0) {
		free(command);
		command=StrInput();
		target+=CNToNumJudge(command);
	}
	else if(strcmp(command,keywords[3])==0) {
		free(command);
		command=StrInput();
		target-=CNToNumJudge(command);
	}
	else {
		printf("����Ӧ���룺���� / ����");
		exit(0);
	}
	free(command);
}


// �������
void OutPutVar() {
	char* command=StrInput();
	if(strcmp(command,name)==0) {
		NumToCNJudge(target);
	}
	else {
		printf("����Ӧ���룺%s",name);
	}
	free(command); 
} 


int main() {
	SetVar();
	DealVar();
	return 0;
} 
