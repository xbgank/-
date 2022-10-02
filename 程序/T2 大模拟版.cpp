//title :总之我是大冤种
//一开始题目看错，以为只要暴力就可以完事(我才不会承认没有第一时间认出是搜索的哼（doge）)
//因为T1是01背包，所以我以为T2也不会太 咳咳
//于是就开始 “快乐” 的写 大 模 拟
//写到一半发现才不太对劲，然后才发现这是一个(我是洪水我要走迷宫）的破坏王游戏
//但是为时已晚，写就写了，总得写完吧，于是就有了下面这个冤种版 惊天大模拟 
//（还不知道能得多少分，于是就没敢放到上面 O-_-O 真的栓Q）
//但还是请笑纳吧
#include<bits/stdc++.h>
using namespace std;
int x,y,ans;
char v;//读入
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};//走迷宫必备
typedef struct 
{
	int z;//0还是1
//	int w,a,s,d;//上左下右
	int vis;//搜索中判断是否走过
}test;//结构体
test k[500][500];
void find(int h,int l)//4个方向找找有没有墙（4处看看）
{
	int boom=0;
	for(int i=h+1;i<=x;i++)if(k[i][l].z==1){boom++;break;}//向下找
	for(int i=h-1;i>=1;i--)if(k[i][l].z==1){boom++;break;}//向上找
	for(int j=l-1;j>=1;j--)if(k[h][j].z==1){boom++;break;}//向左找
	for(int j=l+1;j<=y;j++)if(k[h][j].z==1){boom++;break;}//向右找
	if(boom==4)k[h][l].z=4;//4面都有墙的标记一下（这是暂时符合的）（就是不管远（和墙之间还有O的）近（直接靠墙））
	else k[h][l].z=2;//否则标记成汪，已经绝对不符合了
}
void find2(int x,int y)
{
	for(int i=0;i<4;i++)
	{
		
		if(k[x+dx[i]][y+dy[i]].vis==0&&k[x+dx[i]][y+dy[i]].z==4)
		{
			k[x+dx[i]][y+dy[i]].vis=1;
			k[x+dx[i]][y+dy[i]].z=2;
			find2(x+dx[i],y+dy[i]);
			k[x+dx[i]][y+dy[i]].vis=0;		
		}
	}
}


/*
void find2(int h,int l)//检验（排除一种情况）
//* * * * *      * * * *
//* 4 2 4 *      * 4 4 *
//* * 0 * *      * * 2 *     总之就是需要走迷宫，也就是需要搜索
{
	cout<<h<<" "<<l<<endl;
	int xl,yl;
	//int t=1;
	//if(k[h-1][l].vis==1&&k[h][l-1].vis==1&&k[h][l+1].vis==1&&k[h+1][l].vis==1)t=1;
	//if(t)return ;
	if(!k[h][l].vis)
	{
		k[h][l].vis=1;
		k[h][l].z=2;
		for(int i=0;i<4;i++)
		{
			xl=h+dx[i];
			yl=l+dy[i];
			find2(xl,yl);
		}
		k[h][l].vis=0;
	}
}
*/



int main()
{
	cin>>x>>y;
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=y;j++)
		{
			cin>>v;
			if(v=='*')k[i][j].z=1,k[i][j].vis=1;//初始化，*转换成1，我感觉好受一点，其实没什么卵用，然后墙的visit都设为1
		}
	}
//	for(int i=2;i<=x-1;i++)
//	{
//		for(int j=2;j<=y-1;j++)
//		{
//			if(k[i][j].z==0)
//			{
//				if(k[i-1][j].z==1)k[i-1][j].w=1;
//				if(k[i][j-1].z==1)k[i][j-1].a=1;
//				if(k[i][j+1].z==1)k[i][j+1].d=1;
//				if(k[i+1][j].z==1)k[i+1][j].s=1;
//				//这个点的上左右下
//			}
//		}
//	}
	for(int i=2;i<=x-1;i++)//最外面的一圈不用管（当然不是，只是省一点点）
	{
		for(int j=2;j<=y-1;j++)
		{
			if(k[i][j].z==0)find(i,j);//如果不是墙那么找找4周看看有没有墙
		}
	}
	
	
	
	for(int j=2;j<=y;j++)if(k[1][j].z==0)k[1][j].z=2;
	for(int i=2;i<=x;i++)if(k[i][y].z==0)k[i][y].z=2;
	for(int j=1;j<=y-1;j++)if(k[x][j].z==0)k[x][j].z=2;
	for(int i=1;i<=x-1;i++)if(k[i][1].z==0)k[i][1].z=2;
	
	
	for(int i=2;i<=x-1;i++)
	{	
		for(int j=2;j<=y-1;j++)
		{
			if(k[i][j].z==2)find2(i,j);//找到不符合的点，那么再看看能不能连通其他值为4的点
			//但是也不能break，因为不知道所有O是不是连通的，只能继续找
			//写到这我就知道自己当了个大冤种
		}
	}
	
	for(int i=2;i<=x-1;i++)//一如既往的扔了最外面一圈
	{
		for(int j=2;j<=y-1;j++)
		{
			if(k[i][j].z==4)ans++;//找到符合的，答案+1
		}
	}
	cout<<ans;
	//写完这个感觉我和初学者一样  -_-O（只是不承认忘的差不多了罢了）
	
	/*
	cout<<endl;
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=y;j++)
		{
			cout<<k[i][j].z<<" ";
		}
		cout<<endl;
	}
	*/
	
	return 0;
}