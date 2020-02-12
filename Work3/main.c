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


const char CN[11][10]={"零","一","二","三","四","五","六","七","八","九","十"}; // 汉字数字 
char keywords[7][20]={"整数","等于","增加","减少","看看","负","结束"}; // 关键字 
int target; // 将变量对应的变量定义为全局变量 
char name[20]; // 将定义变量的中文定义为全局变量 


//判断为正数的情况 
void PositiveNumToCN(int num) {
	if(num>=10){
		if(num%10==0){
			if(num==10){
				printf("%s\n",CN[10]); // 刚好为十 
			}
			else{
				printf("%s%s\n",CN[num/10],CN[10]); // 整十情况
			}
		}
		else{
			if(num<20){
				printf("%s%s\n",CN[10],CN[num%10]); // 十几的情况 
			}
			else{
				printf("%s%s%s\n",CN[num/10],CN[10],CN[num%10]); // 其余情况 
			}
		}
	}
	else{
		printf("%s\n",CN[num]); // 一位数情况 
	}
}


// 判断为负数的情况 
void NegativeNumToCN(int num) {
	printf("负");
	PositiveNumToCN(-num);
}


// 判断正负号 
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


// 汉字对比循环判断 
int CNJudge(char* str) {
	int i;
	for(i=0;i<11;i++){
		if(strcmp(str,CN[i])==0){
			return i;
		}
	}
	return -1;
}


// 第一位是否为负判断 
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


// 长度为六
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


// 长度为四
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


// 长度为二
int CNToNum_2(char str[]) {
	return CNJudge(str);
} 


// 长度判断 
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


// 字符串输入 
char* StrInput() {
	char* str;
    str = (char*)malloc(10);
    scanf("%s",str);
    return str;
}


// 定义变量
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
			printf("错误，应输入：等于\n");
			exit(0);
		}
	}
	else {
		printf("错误，应输入：整数\n");
		exit(0);
	}
}


// 处理变量
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
			printf("错误，应输入：看看 / %s",name);
			exit(0);
		}
		free(command);	
	}
}


// 计算变量
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
		printf("错误，应输入：增加 / 减少");
		exit(0);
	}
	free(command);
}


// 输出变量
void OutPutVar() {
	char* command=StrInput();
	if(strcmp(command,name)==0) {
		NumToCNJudge(target);
	}
	else {
		printf("错误，应输入：%s",name);
	}
	free(command); 
} 


int main() {
	SetVar();
	DealVar();
	return 0;
} 
