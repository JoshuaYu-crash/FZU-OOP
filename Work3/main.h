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






