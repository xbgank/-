#include<bits/stdc++.h>
using namespace std;
int x,y,ans;
char v;
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};//4个方向
typedef struct
{
	int z;//值
	int vis;//是否被访问过
}test;
test k[520][520];//结构体
void find(int x,int y)//嘎嘎搜
{
	
	for(int i=0;i<4;i++)//4个方向
	{
		if(k[x+dx[i]][y+dy[i]].vis==0&&k[x+dx[i]][y+dy[i]].z==0)//没被访问过且值为0
		{
			k[x+dx[i]][y+dy[i]].vis=1;//记为被访过
			k[x+dx[i]][y+dy[i]].z=2;//值变为2
			find(x+dx[i],y+dy[i]);//寻找这个
			k[x+dx[i]][y+dy[i]].vis=0;//循环前返回变成为被访
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);//稍微快点吧
	cin>>x>>y;
	for(int i=1;i<=x+2;i++)for(int j=1;j<=y+2;j++)k[i][j].z=1,k[i][j].vis=1;//打墙，外面打一圈
	for(int i=2;i<=x+1;i++)
	{
		for(int j=2;j<=y+1;j++)
		{
			cin>>v;
			if(v=='*')
			{
				k[i][j].z=1;
				k[i][j].vis=1;//初始化，*转换成1，我感觉好受一点，其实没什么卵用，然后墙的visit都设为1
			}
			else k[i][j].z=0,k[i][j].vis=0;//莫忘之前打墙的设置，得重新换回来
		}
	}
	//从除墙外的最外面一圈挨个看，有0就钻进去，直到不能再走（ps：因为打了墙，所以得注意数据从哪开始、到哪结束）
	for(int j=3;j<=y+1;j++)if(k[2][j].z==0){k[2][j].vis=1;k[2][j].z=2;find(2,j);}
	for(int i=3;i<=x+1;i++)if(k[i][y+1].z==0){k[i][y+1].vis=1;k[i][y+1].z=2;find(i,y+1);}
	for(int j=2;j<=y;j++)if(k[x+1][j].z==0){k[x+1][j].vis=1;k[x+1][j].z=2;find(x+1,j);}
	for(int i=2;i<=x;i++)if(k[i][2].z==0){k[i][2].vis=1;k[i][2].z=2;find(i,2);}
	for(int i=2;i<=x+1;i++)
	{
		for(int j=2;j<=y+1;j++)
		{
			if(k[i][j].z==0)ans++;//最后剩下的0都是完好的，没被洪水冲跨
		}
	}
	cout<<ans;
	return 0;
}