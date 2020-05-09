#include <iostream>
using namespace std;

class CNlang {
private:
    const string CN[11]={"零","一","二","三","四","五","六","七","八","九","十"}; // 汉字数字 
    string keywords[7]={"整数","等于","增加","减少","看看","负","结束"}; // 关键字 
    int target; // 将变量对应的变量定义为全局变量 
    string name[20]; // 将定义变量的中文定义为全局变量 
public:
    void PositiveNumToCN(int num);
    void NegativeNumToCN(int num);
    void NumToCNJudge(int num);
    int CNJudge(char* str);
    int CNToNumJudge(char str[]);
    int CNToNum_6(char str[]);
    int CNToNum_4(char str[]);
    int CNToNum_2(char str[]);
    int CNToNumLen(char str[]);
    string StrInput();
    void SetVar();
    void DealVar();
    void CalculateVar();
    void OutPutVar();
};