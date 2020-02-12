#include"main.h"
int main()
{
	char num[15][12]={"五","十","十二","二十","三十五","九十一","零","负一","负十","负十五","负二十","负五十六"};
	int i;
	for(i=0;i<12;i++)
	{
		printf("%d\n",CNToNumJudge(num[i]));
	} 
}
