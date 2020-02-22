#include "main.h"
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

int main() {
    SetVar();
    DealVar();
    return 0;
}
