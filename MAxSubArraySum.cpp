#include<vector>
#include<iostream>
using namespace std;

int max(vector<int> &a)
{
	int max = a[0];
	for (int i = 1; i < a.size(); i++)
	{
		if (max < a[i])
			max = a[i];
	}
	return max;
}

int max(int a, int b)
{
  return a>b? a:b;
}

int MaxSubArraySum(vector<int> &a)
{
  int n= a.size();
  vector<int> sum;
  sum.resize(n);
  sum[0] = a[0];
  for(int i=1;i<n;i++)
  {
    sum[i] = max(sum[i-1]+ a[i] , a[i]);
  }
  return max(sum);
  
}
