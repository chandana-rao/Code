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

int findMax(vector<int> & nums)
{
	int n = nums.size();
	vector<int> p;
	p.resize(n, -999);
	vector<int> pf;
	pf.resize(n);

	for (int i = 0; i < n; i++)
	{
		p[i] = nums[i];
		for (int j = i + 1; j < n; j++)
		{
			p[j] = p[j - 1] * nums[j];
		}
		pf[i] = max(p);
		p[i] = -999;
	}
	return max(pf);
}


int main()
{

	vector<int> a = { 2,3,-2,4 };
	cout<<findMax(a);
	getchar();
	getchar();
	return 0;
}
