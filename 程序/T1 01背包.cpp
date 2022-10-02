#include<bits/stdc++.h>//01背包
using namespace std;
int n,m;
int v[27],p[30000];
int w[27];
int main()
{
	cin>>n>>m;//
	for(int i=1;i<=m;i++)
	{
		cin>>v[i]>>p[i];
		w[i]=v[i]*p[i];
	}
	memset(p,0,sizeof(p));
	for(int i=1;i<=m;i++)
	{
		for(int j=n;j>=v[i];j--)
		{
			if(j>=v[i])p[j]=max(p[j],p[j-v[i]]+w[i]);
		}
	}
	cout<<p[n];
	return 0;
}