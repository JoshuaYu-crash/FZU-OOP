#include <iostream>
using namespace std;

class CNlang {
private:
    const string CN[11]={"��","һ","��","��","��","��","��","��","��","��","ʮ"}; // �������� 
    string keywords[7]={"����","����","����","����","����","��","����"}; // �ؼ��� 
    int target; // ��������Ӧ�ı�������Ϊȫ�ֱ��� 
    string name[20]; // ��������������Ķ���Ϊȫ�ֱ��� 
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