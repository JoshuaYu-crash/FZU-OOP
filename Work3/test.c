#include"main.h"
int main()
{
	char num[15][12]={"��","ʮ","ʮ��","��ʮ","��ʮ��","��ʮһ","��","��һ","��ʮ","��ʮ��","����ʮ","����ʮ��"};
	int i;
	for(i=0;i<12;i++)
	{
		printf("%d\n",CNToNumJudge(num[i]));
	} 
}
