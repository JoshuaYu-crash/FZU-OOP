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






