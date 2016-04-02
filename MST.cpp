/*NAME : Re-connecting Computer Sites*/
/*ID   : 908*/
/*Lang.: c++*/



#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#define pi pair<int,int>

using namespace std;

vector< pair<int,pi> > edges;
int edge,src,dst,wet;
int i,j,k,l,M,K;
int parent[1000000];
int res1,res2,res3,mx,sum;


int find(int p)
{
	if(parent[p]==p)
		return p;
	return parent[p]=find(parent[p]);
}

int MST(int val)
{
	sum=0;
	for(i=0;i<=mx;i++)parent[i]=i;
	for(i=0;i<val;i++)
	{
		int u = find(edges[i].second.first);
		int v = find(edges[i].second.second);
		if(u!=v)
		{
			parent[u]=v;
			sum+=edges[i].first;
		}
	}
	return sum;
}


void Input_Graph()
{
	bool valid=true;
	while(cin>>edge)
	{
		edges.clear();
		sum=0;
		for(i=0;i<edge-1;i++)
		{
			cin>>src>>dst>>wet;
			sum+=wet;
		}
		res1=sum;


		cin>>K;
		mx=INT_MIN;
		edges.clear();
		for(i=0;i<K;i++)
		{
			cin>>src>>dst>>wet;
			edges.push_back(make_pair(wet,make_pair(src,dst)));
			if(mx<src)mx=src;
			if(mx<dst)mx=dst;
		}

		cin>>M;
		for(i=0;i<M;i++)
		{
			cin>>src>>dst>>wet;
			edges.push_back(make_pair(wet,make_pair(src,dst)));
			if(mx<src)mx=src;
			if(mx<dst)mx=dst;
		}
		sort(edges.begin(),edges.end());
		res2=MST(M+K);
		if(valid==false)cout<<endl;
		valid=false;
		cout<<res1<<endl<<res2<<endl;
	}
}


int main()
{
	Input_Graph();
	return 0;
}


/*NAME : IP-TV*/
/*ID   : 1174*/
/*Lang.: c++*/

#pragma warning (disable:4786)
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


typedef pair<int,int> pi;

map<string,int> M;
map<string,int>::iterator it;
vector< pair<int,pi> > edges;
string str,src,dst;
int i,j,k,l,vertex,edge,wet,u,v;
int parent[100000],tc;

int find(int p)
{
	if(parent[p]==p)return p;
	return parent[p]=find(parent[p]);
}


int MST()
{
	int sum=0;
	for(i=1;i<=vertex;i++)parent[i]=i;
	for(i=0;i<edge;i++)
	{
		int s = find(edges[i].second.first);
		int t = find(edges[i].second.second);
		if(s!=t)
		{
			parent[s]=t;
			sum+=edges[i].first;
		}
	}
	return sum;
}


void Input_Graph()
{
	cin>>tc;
	for(k=0;k<tc;k++)
	{
		M.clear();
		edges.clear();
		cin>>vertex>>edge;
		j=1;
		for(i=0;i<edge;i++)
		{
			cin>>src>>dst>>wet;
			if(M[src]==0)M[src]=j++;
			if(M[dst]==0)M[dst]=j++;
			int u=M[src];
			int v=M[dst];
			edges.push_back(make_pair(wet,make_pair(u,v)));
		}
		sort(edges.begin(),edges.end());
		cout<<MST()<<endl;
		if(k<(tc-1))cout<<endl;
	}
}

int main()
{
	Input_Graph();
	return 0;
}


/*NAME : Oreon*/
/*ID   : 1208*/
/*Lang.: c++*/


#pragma warning(disable:4786)
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;


int i,j,k,l,tc;
int vertex,parent[10000];
char ch;
int num;
set<pair<int,pair<int,int> > > edges;
set<pair<int,pair<int,int> > >::iterator sit;



int find(int p)
{
	if(parent[p]==p)return p;
	return parent[p]=find(parent[p]);
}

void MST(int v)
{
	for(i=0;i<v;i++)parent[i]=i;
	for(sit=edges.begin();sit!=edges.end();sit++)
	{
		int u = find(sit->second.first);
		int v = find(sit->second.second);
		if(u!=v)
		{
			parent[u]=v;
			cout<<char(sit->second.first+65)<<"-"<<char(sit->second.second+65)<<" "<<sit->first<<endl;
		}
	}
}


void Input_Graph()
{
	cin>>tc;
	for(k=1;k<=tc;k++)
	{
		edges.clear();
		cin>>vertex;
		for(i=0;i<vertex;i++)
		{
			for(j=0;j<vertex-1;j++)
			{
				cin>>num;
				cin>>ch;
				if(num>0)
				{
					if(j>=i)edges.insert(make_pair(num,make_pair(i,j)));
					else edges.insert(make_pair(num,make_pair(j,i)));
				}
			}
			cin>>num;
			if(num>0)
			{
				
				if(j>=i)edges.insert(make_pair(num,make_pair(i,j)));
				else edges.insert(make_pair(num,make_pair(j,i)));
			}
		}
		cout<<"Case "<<k<<":"<<endl;
		MST(vertex);
	}
}

int main()
{
	Input_Graph();
	return 0;
}


/*NAME : Anti Brute Force Lock*/
/*ID   : 1235*/
/*Lang.: c++11*/


#pragma warning(disable:4786)
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <climits>

using namespace std;

typedef pair<int,int > ii;
vector<string> V;
vector<pair < int,ii > > edges;
int parent[10000];
int tc,num,wet,ans;
int i,j,k,l,c;
string str;


int find(int p)
{
	if(parent[p]==p)return p;
	return parent[p]=find(parent[p]);
}

int MST(int V)
{
	for(i=0;i<V;i++)parent[i]=i;
	for(i=0;i<edges.size();i++)
	{
		int u = find(edges[i].second.second);
		int v = find(edges[i].second.first);
		if(u!=v)
		{
			parent[u]=v;
			ans+=edges[i].first;
		}
	}
	return ans;
}

int distance(string flag1,string flag2)
{
	wet=0;
	for(k=0;k<4;k++)
	{
		int temp1 = flag1[k]-48;
		int temp2 = flag2[k]-48;
		if(temp1==temp2)wet+=0;
		if(temp1<temp2)
		{
			c=0;
			for(l=temp1;l<temp2;l++)c++;
			if((10-c)>c)wet+=c;
			else wet+=(10-c);
		}
		if(temp1>temp2)
		{
			c=0;
			for(l=temp1;l>temp2;l--)c++;
			if((10-c)>c)wet+=c;
			else wet+=(10-c);
		}
	}
	return wet;
}


void Input_Graph()
{
	cin>>tc;
	while(tc--)
	{
		V.clear();
		edges.clear();
		cin>>num;
		int mn = INT_MAX;
		ans=0;
		for(i=0;i<num;i++)
		{
			cin>>str;
			V.push_back(str);
			int d = distance("0000",str);
			if(d<mn)mn=d;
		}
		ans+=mn;
		for(i=0;i<num;i++)
		{
			for(j=i+1;j<num;j++)
				edges.push_back(make_pair(distance(V[i],V[j]),make_pair(i,j)));
		}

		sort(edges.begin(),edges.end());

		cout<<MST(num)<<endl;
	}
}


int main()
{
	Input_Graph();
	return 0;
}


/*NAME : Freckles*/
/*ID   : 10034*/
/*Lang.: c++*/

#pragma warning(disable:4786)
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;


pair<double,double> pr[10000];
typedef pair<int,int> prr;
vector<pair<double,prr > > edges;

int vertex,edge,src,dst,wet;
int i,j,tc;
double x,y;
int parent[10000];

int find(int p)
{
	if(parent[p]==p)return p;
	return parent[p]=find(parent[p]);
}

void MST(int E)
{
	cout.setf(ios::floatfield,ios::fixed);
	cout.precision(2);
	double sum=0.00;
	for(i=0;i<E;i++)parent[i]=i;
	for(i=0;i<edges.size();i++)
	{
		int u = find(edges[i].second.first);
		int v = find(edges[i].second.second);
		if(u!=v)
		{
			parent[u]=v;
			sum+=edges[i].first;
		}
	}
	cout<<sum<<endl;
}


void Input_Graph()
{
	bool flag=false;
	cin>>tc;
	while(tc--)
	{
		edges.clear();
		cin>>edge;
		for(i=0;i<edge;i++)
		{
			cin>>x>>y;
			pr[i]=make_pair(x,y);
		}

		for(i=0;i<edge;i++)
		{
			for(j=i+1;j<edge;j++)
			{
				edges.push_back(make_pair(sqrt(pow(pr[i].first-pr[j].first,2)+pow(pr[i].second-pr[j].second,2)),make_pair(i,j)));
			}
		}
		sort(edges.begin(),edges.end());
		if(flag)cout<<endl;
		else flag=true;
		MST(edge);
	}
}


int main()
{
	Input_Graph();
	return 0;
}


/*NAME : Transportation system*/
/*ID   : 11228*/
/*Lang.: c++*/

#pragma warning(disable:4786)
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

pair<int,int> pr[10000];
vector<pair<double,pair<int,int > > > edges;
int vertex,x,y;
int i,j,k,l,num;
int threshold,tc;
int parent[10000];


int find(int p)
{
	if(parent[p]==p)return p;
	return parent[p]=find(parent[p]);
}

void MST(int V,int T)
{
	double road = 0;
	double railroad = 0;
	num=1;
	for(j=0;j<V;j++)parent[j]=j;
	for(j=0;j<edges.size();j++)
	{
		int u = find(edges[j].second.first);
		int v = find(edges[j].second.second);
		if(u!=v)
		{
			parent[u]=v;
			if(edges[j].first<=T)
			{
				road+=edges[j].first;
			}
			else
			{
				railroad+=edges[j].first;
				num++;
			}
		}
	}
	printf("Case #%d: %d %.lf %.lf\n", i, num, road ,railroad);
}

void Input_Graph()
{
	cin>>tc;
	for(i=1;i<=tc;i++)
	{
		edges.clear();
		cin>>vertex>>threshold;
		for(j=0;j<vertex;j++)
		{
			cin>>x>>y;
			pr[j]=make_pair(x,y);
		}
		for(j=0;j<vertex;j++)
		{

			for(k=j+1;k<vertex;k++)
			{
				edges.push_back(make_pair((sqrt(pow(pr[j].first-pr[k].first,2)+pow(pr[j].second-pr[k].second,2))),make_pair(j,k)));
			}
		}
		sort(edges.begin(),edges.end());
		MST(vertex,threshold);
	}
}


int main()
{
	Input_Graph();
	return 0;
}


/*NAME : Dark Roads*/
/*ID   : 11631*/
/*Lang.: c++*/

#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#define paii pair<int,int>

using namespace std;

vector< pair<int,paii> > edges;
int i;
int u,v;
int parent[100000];

int Find_Set(int p)
{
	if(parent[p]==p) return p;
	return parent[p] = Find_Set(parent[p]);
}


bool Join_Set(int m,int n)
{
	if(m!=n)
	{
		parent[m]=n;
		return true;
	}
	return false;
}


int MST(int vertex,int edge)
{
	int sum=0;
	for(i=0;i<edge;i++)
	{
		u=edges[i].second.first;
		v=edges[i].second.second;
		int s=Find_Set(u);
		int t=Find_Set(v);
		if(Join_Set(s,t))
		{
			sum=sum+edges[i].first;
		}
	}
	return sum;
}

void Input_Graph()
{
	int vertex,edge,src,dst,wet;
	int cnt;
	while(cin>>vertex>>edge)
	{
		if(!vertex && !edge)
			break;
		for(i=0;i<vertex;i++)
		{
			parent[i]=i;
		}
		cnt=0;
		edges.clear();
		for(i=0;i<edge;i++)
		{
			cin>>src>>dst>>wet;
			cnt+=wet;
			edges.push_back(make_pair(wet,make_pair(src,dst)));
		}
		(edges.begin(),edges.end());
		cout<<cnt-MST(vertex,edge)<<endl;
	}
}

int main()
{
	Input_Graph();
	return 0;
}


/*NAME : Expensive subway*/
/*ID   : 11710*/
/*Lang.: c++*/

#pragma warning(disable:4786)
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#define pi pair<int,int>

using namespace std;
map<string,int> M;
vector< pair < int,pi > > edges;
int vertex,edge,wet;
string src,dst;
string temp;
int i,j,k,l,u,v;  
int parent[100000];

int find(int u)
{
	if(parent[u]==u)
		return u;
	return parent[u]=find(parent[u]);
}


void MST()
{
	int sum=0;
	for(i=0;i<vertex;i++)
		parent[i]=i;
	for(i=0;i<edge;i++)
	{
		u = find(edges[i].second.first);
		v = find(edges[i].second.second);
		if(u!=v)
		{
			parent[u]=v;
			sum+=edges[i].first;
		}
	}
	u=find(0);
	int valid=0;
	for(i=1;i<vertex;i++)
	{
		if(find(i)!=u)
			valid=1;
	}
	if(valid==1)
		cout<<"Impossible"<<endl;
	else
		cout<<sum<<endl;
}


void Input_Graph()
{
	while(cin>>vertex>>edge)
	{
		if(edge==0&&vertex==0)break;
		M.clear();
		edges.clear();
		for(i=0;i<vertex;i++)
		{
			cin>>temp;
			M[temp]=i;
		}
		for(i=0;i<edge;i++)
		{
			cin>>src>>dst>>wet;
			u=M[src];
			v=M[dst];
			edges.push_back(make_pair(wet,make_pair(u,v)));
		}
		cin>>src;
		sort(edges.begin(),edges.end());
		MST();
	}
}

int main()
{
	Input_Graph();
	return 0;
}


/*NAME : Airports*/
/*ID   : 11733*/
/*Lang.: c++*/

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#define pi pair<int,int>

using namespace std;

vector< pair < int,pi > > edges;
int vertex,edge,src,dst,wet,ap,xtra;
int i,j,k,l,p,q,sum;
int parent[100050];


int find(int u)
{
	if(parent[u]==u)
		return u;
	return parent[u]=find(parent[u]);
}

int MST()
{
	for(i=1;i<=vertex;i++)
	{
		parent[i]=i;
	}
	sum=0;
	xtra=0;
	for(i=0;i<edge;i++)
	{
		p=find(edges[i].second.first);
		q=find(edges[i].second.second);
		if(p!=q)
		{
			parent[p]=q;
			if(ap>edges[i].first)
				sum+=edges[i].first;
			else
				xtra++;

		}
	}
	return sum;
}


void Input_Graph()
{
	int tc,res,count,cs;
	cin>>tc;
	cs=1;
	while(tc--)
	{
		cin>>vertex>>edge>>ap;
		edges.clear();
		for(i=0;i<edge;i++)
		{
			cin>>src>>dst>>wet;
			edges.push_back(make_pair(wet,make_pair(src,dst)));
		}
		sort(edges.begin(),edges.end());
		res=MST();
		count=0;
		for(i=1;i<=vertex;i++)
		{
			if(parent[i]==i)
				count++;
		}
		cout<<"Case #"<<cs++<<": "<<res+(ap*(count+xtra))<<" "<<count+xtra<<endl;
	}
}


int main()
{
	Input_Graph();
	return 0;
}


/*NAME : Heavy Cycle Edges*/
/*ID   : 11747*/
/*Lang.: c++*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#define pi pair<int,int>

using namespace std;

vector< pair < int,pi > > edges;
int vertex,edge,src,dst,wet;
int i,j,k,l,p,q;
int parent[1000000];
int arr[1000000];

int find(int u)
{
	if(parent[u]==u)
		return u;
	return parent[u]=find(parent[u]);
}

void MST()
{
	for(i=0;i<vertex;i++)
		parent[i]=i;
	j=0;
	for(i=0;i<edge;i++)
	{
		p = find(edges[i].second.first);
		q = find(edges[i].second.second);

		if(p!=q)
			parent[p]=q;
		else
			arr[j++]=edges[i].first;
	}
	if(j==0)
		cout<<"forest"<<endl;
	else
	{
		cout<<arr[0];
		for(i=1;i<j;i++)
			cout<<" "<<arr[i];
		cout<<endl;
	}
}


void Input_Graph()
{
	while(cin>>vertex>>edge)
	{
		if(vertex==0 && edge==0)
			break;
		edges.clear();
		for(i=0;i<edge;i++)
		{
			cin>>src>>dst>>wet;
			edges.push_back(make_pair(wet,make_pair(src,dst)));
		}
		sort(edges.begin(),edges.end());
		MST();
	}
}


int main()
{
	Input_Graph();
	return 0;
}


/*NAME : Driving Range*/
/*ID   : 11857*/
/*Lang.: c++*/


#pragma warning(disable:4786)
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<map>
#define pi pair<int,int>

using namespace std;

vector<pair < int,pi> > edges;
int vertex,edge,src,dst,wet,s,d;
int i,j,k,l;
int parent[1000000],cnt,mx;


int find(int p)
{
	if(parent[p]==p)return p;
	return parent[p]=find(parent[p]);
}

int MST()
{
	cnt=0;
	for(i=0;i<vertex;i++)parent[i]=i;
	mx=INT_MIN;
	for(i=0;i<edge;i++)
	{
		int  u =find(edges[i].second.first);
		int  v =find(edges[i].second.second);
		if(u!=v)
		{
			parent[u]=v;
			if(edges[i].first>mx)mx=edges[i].first;
			cnt++;
		}
	}
	return mx;
}


void Input_Graph()
{
	while(cin>>vertex>>edge)
	{
		if(vertex==0&&edge==0)break;
		edges.clear();
		for(i=0;i<edge;i++)
		{
			cin>>src>>dst>>wet;
			edges.push_back(make_pair(wet,make_pair(src,dst)));
		}
		sort(edges.begin(),edges.end());
		int res=MST();
		if(cnt==(vertex-1))
			cout<<res<<endl;
		else
			cout<<"IMPOSSIBLE"<<endl;
	}
}


int main()
{
	Input_Graph();
	return 0;
}


/*NAME : Frogger*/
/*ID   : 534*/
/*Lang.: c++*/


#pragma warning(disable:4786)
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cmath>

using namespace std;


pair<double,double> pr[100000];
vector<pair<double,pair<int,int> > > edges; 
int i,j,x,y;
int edge,tc;
int parent[100000];

int find(int p)
{
	if(parent[p]==p)return p;
	return parent[p]=find(parent[p]);
}

double MST(int E)
{
	cout.setf(ios::floatfield,ios::fixed);
	cout.precision(3);
	double sum=0.00;
	for(i=0;i<E;i++)parent[i]=i;
	for(i=0;i<edges.size();i++)
	{
		int u = find(edges[i].second.first);
		int v = find(edges[i].second.second);
		if(u!=v)
		{
			parent[u]=v;
			if(find(0)==find(1))
			{
				return edges[i].first;
				break;
			}
		}
	}
}

void Input_Graph()
{
	tc=1;
	while(cin>>edge)
	{
		if(edge==0)break;
		edges.clear();
		for(i=0;i<edge;i++)
		{
			cin>>x>>y;
			pr[i]=make_pair(x,y);
		}

		for(i=0;i<edge;i++)
		{
			for(j=i+1;j<edge;j++)
			{
				edges.push_back(make_pair(sqrt(pow(pr[i].first-pr[j].first,2)+pow(pr[i].second-pr[j].second,2)),make_pair(i,j)));
			}
		}
		sort(edges.begin(),edges.end());
		cout<<"Scenario #"<<tc++<<endl<<"Frog Distance = "<<MST(edge)<<endl<<endl;
	}
}


int main()
{
	Input_Graph();
	return 0;
}


/*NAME : Heavy Cargo*/
/*ID   : 544*/
/*Lang.: c++*/

#pragma warning(disable:4786)
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<climits>
#include<set>
#define pi pair<int,int>


using namespace std;

vector< pair < int,pi > > edges;
map<string,int> M;
map<string,int>::iterator it;
int vertex,edge,wet;
string src,dst;
int parent[100000];
int i,j,k,l,u,v,m,n;


int find(int g)
{
	if(parent[g]==g)return g;
	return parent[g]=find(parent[g]);
}

int MST(int p,int q)
{
	int mn = INT_MAX;
	for(i=0;i<vertex;i++)
		parent[i]=i;
	for(i=0;i<edge;i++)
	{
		u = find(edges[i].second.first);
		v = find(edges[i].second.second);
		if(u!=v)
			parent[u]=v;
		if(find(p)==find(q))
		{
			if(mn>edges[i].first)
			{
				mn=edges[i].first;
				break;
			}
		}
	}
	return mn;
}

int main()
{
	int cs=0;
	while(cin>>vertex>>edge)
	{
		if(vertex==0&&edge==0)break;
		edges.clear();
		M.clear();
		j=0;
		for(i=0;i<edge;i++)
		{
			cin>>src>>dst>>wet;
			if(M[src]==0)
				M[src]=j++;
			if(M[dst]==0)
				M[dst]=j++;
			u=M[src];
			v=M[dst];
			edges.push_back(make_pair(wet,make_pair(u,v)));
		}
		cin>>src>>dst;
		u=M[src];
		v=M[dst];
		sort(edges.begin(),edges.end());
		reverse(edges.begin(),edges.end());
		cout<<"Scenario #"<<++cs<<endl;
		cout<<MST(u,v)<<" tons"<<endl<<endl;
	}
	return 0;
}


/*NAME : X-Plosives*/
/*ID   : 1160*/
/*Lang.: c++*/

#pragma warning (disable:4786)
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<map>
#define pi pair<int,int>

using namespace std;

vector<pi> edges;
vector<pi>::iterator it;
int i,j,k,l,src,dst,sum;
int parent[1000000];

int find(int p)
{
	if(parent[p]==p)return p;
	return parent[p]=find(parent[p]);
}

int main()
{
	int mx;
	edges.clear();
	mx=0;
	while(cin>>src)
	{
		if(src==-1)
		{
			for(i=1;i<=mx;i++)parent[i]=i;
			mx=0;
			sum=0;
			for(it=edges.begin();it!=edges.end();it++)
			{
				int u = find(it->first);
				int v = find(it->second);
				if(u!=v)parent[u]=v;
				else sum++;
			}
			cout<<sum<<endl;
			edges.clear();
		}
		else
		{
			cin>>dst;
			edges.push_back(make_pair(src,dst));
			if(mx<src)mx=src;
			if(mx<dst)mx=dst;
		}
	}
	return 0;
}

/*NAME : The Bug Sensor Problem*/
/*ID   : 1216*/
/*Lang.: c++*/


#pragma warning(disable:4786)
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

pair<int,int> pr[100010];
vector<pair<double,pair<int,int > > > edges;
int meter,tc,i,j,k;
int x,y,parent[100010];


int find(int p)
{
	if(parent[p]==p)return p;
	return parent[p]=find(parent[p]);
}

int MST(int edge,int m)
{
	for(j=0;j<edge;j++)parent[j]=j;
	int d=0;
	int mx = 0;
	for(j=0;j<edges.size() && d<(edge-m);j++)
	{
		int u = find(edges[j].second.first);
		int v = find(edges[j].second.second);
		if(u!=v)
		{
			parent[u]=v;
			if(mx<edges[j].first)
				mx=edges[j].first;
			d++;
		}
	}
	return mx;
}

void Input_Graph()
{
	cin>>tc;
	while(tc--)
	{
		edges.clear();
		cin>>meter;
		i=0;
		while(cin>>x)
		{
			if(x==-1)break;
			cin>>y;
			pr[i++]=make_pair(x,y);
		}
		for(j=0;j<i;j++)
		{
			for(k=j+1;k<i;k++)
			{
				edges.push_back(make_pair(ceil(sqrt(pow(pr[j].first-pr[k].first,2)+pow(pr[j].second-pr[k].second,2))),make_pair(j,k)));
			}
		}
		sort(edges.begin(),edges.end());
		cout<<MST(i,meter)<<endl;
	}
}



int main()
{
	Input_Graph();
	return 0;
}

/*NAME : RACING*/
/*ID   : 1234*/
/*Lang.: c++*/


#pragma warning(disable:4786)
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


typedef pair<int,int> ii;
vector<pair<int,ii> > edges;
int V,E,ans;
int src,dst,wet;
int parent[100000];
int tc,i;

int find(int p)
{
	if(parent[p]==p)return p;
	return parent[p]=find(parent[p]);
}

int MST(int V)
{
	for(i=1;i<=V;i++)parent[i]=i;
	for(i=0;i<edges.size();i++)
	{
		int u = find(edges[i].second.first);
		int v = find(edges[i].second.second);
		if(u!=v)
		{
			parent[u]=v;
			ans-=edges[i].first;
		}
	}
	return ans;
}


void Input_Graph()
{
	while(cin>>tc)
	{
		if(tc==0)break;
		for(int j=0;j<tc;j++)
		{
			cin>>V>>E;
			edges.clear();
			ans=0;
			for(i=0;i<E;i++)
			{
				cin>>src>>dst>>wet;
				edges.push_back(make_pair(wet,make_pair(src,dst)));
				ans+=wet;
			}
			sort(edges.begin(),edges.end());
			reverse(edges.begin(),edges.end());
			cout<<MST(V)<<endl;
		}
	}
}


int main()
{
	Input_Graph();
	return 0;
}

/*NAME : Audiophobia*/
/*ID   : 10048*/
/*Lang.: c++*/

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#define pi pair<int,int>

using namespace std;

vector< pair<int,pi> > edges;
int vertex,edge,src,dst,wet,qry;
int a,b;
int i,j,k,l;
int parent[100000];
int E[100000];


int find(int p)
{
	if(parent[p]==p)return p;
	return parent[p]=find(parent[p]);
}

int MST(int m,int n)
{
	int mx = INT_MIN;
	for(i=1;i<=vertex;i++)parent[i]=i;
	for(i=0;i<edge;i++)
	{
		int u = find(edges[i].second.first);
		int v = find(edges[i].second.second);
		if(u!=v)
		{
			parent[u]=v;
			if(edges[i].first>mx)mx=edges[i].first;
		}
		if(find(m)==find(n))
			return mx;
	}
	return -1;
}


void Input_Graph()
{
	int cs=1;
	int valid=true;
	while(cin>>vertex>>edge>>qry)
	{
		if(vertex==0&&edge==0&&qry==0)break;
		edges.clear();
		for(i=0;i<edge;i++)
		{
			cin>>src>>dst>>wet;
			edges.push_back(make_pair(wet,make_pair(src,dst)));
		}
		sort(edges.begin(),edges.end());

		for(k=0;k<qry;k++)
		{
			cin>>a>>b;
			E[k]= MST(a,b);
		}
		if(valid==false)cout<<endl;
			valid=false;
		cout<<"Case #"<<cs++<<endl;
		{
			for(i=0;i<qry;i++)
			{
				if(E[i]==-1)cout<<"no path"<<endl;
				else
					cout<<E[i]<<endl;
			}
		}
	}
}



int main()
{
	Input_Graph();
	return 0;
}

/*NAME : The Tourist Guide*/
/*ID   : 10099*/
/*Lang.: c++*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define pi pair<int,int>

using namespace std;

vector< pair <int,pi > > edges;
int vertex,edge,src,dst,wet,s,d,tourist;
int i,j,k,l,res;
int parent[1000000];



int find(int p)
{
	if(parent[p]==p)return p;
	return parent[p]=find(parent[p]);
}

int MST(int S,int D)
{
	for(i=1;i<=vertex;i++)parent[i]=i;
	for(i=0;i<edge;i++)
	{
		int  u = find(edges[i].second.first);
		int  v = find(edges[i].second.second);
		if(u!=v)
			parent[u]=v;
		if(find(S)==find(D))
		{
			res = ceil(double(tourist)/double(edges[i].first-1));
			return res;
		}
	}
}


void Input_Graph()
{
	int cs=1;
	while(cin>>vertex>>edge)
	{
		if(vertex==0&&edge==0)break;
		edges.clear();
		for(i=0;i<edge;i++)
		{
			cin>>src>>dst>>wet;
			edges.push_back(make_pair(wet,make_pair(src,dst)));
		}
		sort(edges.begin(),edges.end());
		reverse(edges.begin(),edges.end());
		cin>>s>>d>>tourist;
		cout<<"Scenario #"<<cs++<<endl;
		cout<<"Minimum Number of Trips = "<<MST(s,d)<<endl<<endl;
	}
}


int main()
{
	Input_Graph();
	return 0;
}


/*NAME : Highways*/
/*ID   : 10147*/
/*Lang.: c++*/


#pragma warning (disable:4786)
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

pair<int,int> pr[10000];
vector<pair<double,pair<int,int > > > edges1;
vector<pair<double,pair<int,int > > > edges2;
set<pair<int,int > > S;
set<pair<int,int > >::iterator sit;
int edge,num,src,dst;
int i,j,k,l,tc,x,y;
int parent[10000];
int u,v;

int find(int p)
{
	if(parent[p]==p)return p;
	return parent[p]=find(parent[p]);
}

int MST(int edge)
{
	int count=0;
	for(i=1;i<=edge;i++)parent[i]=i;
	for(i=0;i<edges2.size();i++)
	{
		u = find(edges2[i].second.first);
		v = find(edges2[i].second.second);
		if(u!=v)parent[u]=v;
	}
	for(i=0;i<edges1.size();i++)
	{
		u = find(edges1[i].second.first);
		v = find(edges1[i].second.second);
		if(u!=v)
		{
			parent[u]=v;
			S.insert(make_pair(edges1[i].second.first,edges1[i].second.second));
			count++;
		}
	}
	return count;
}


void Input_Graph()
{
	cin>>tc;
	while(tc--)
	{
		edges1.clear();
		edges2.clear();
		S.clear();
		cin>>edge;
		for(i=1;i<=edge;i++)
		{
			cin>>x>>y;
			pr[i] = make_pair(x,y);
		}

		for(i=1;i<=edge;i++)
		{
			for(j=i+1;j<=edge;j++)
			{
				edges1.push_back(make_pair(sqrt(pow(pr[i].first-pr[j].first,2)+pow(pr[i].second-pr[j].second,2)),make_pair(i,j)));
			}
		}
		sort(edges1.begin(),edges1.end());

		cin>>num;
		for(i=0;i<num;i++)
		{
			cin>>src>>dst;
			edges2.push_back(make_pair(sqrt(pow(pr[src].first-pr[dst].first,2)+pow(pr[src].second-pr[dst].second,2)),make_pair(src,dst)));
		}

		sort(edges2.begin(),edges2.end());
		if(MST(edge)==0)cout<<"No new highways need"<<endl;
		else
		{
			for(sit=S.begin();sit!=S.end();sit++)
			{
				cout<<sit->first<<" "<<sit->second<<endl;
			}
		}
		if(tc)cout<<endl;
	}
}


int main()
{
	Input_Graph();
	return 0;
}

/*NAME : Arctic Network*/
/*ID   : 10369*/
/*Lang.: c++*/



#pragma warning (disable:4786)
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int tc,x,y;
int i,j,k,vertex,edge,S,P;
vector<pair<double,pair<int,int > > > edges;
pair<int,int> pr[10000];
int parent[10000];

int find(int p)
{
	if(parent[p]==p)return p;
	return parent[p]=find(parent[p]);
}

void MST(int s,int p)
{
	cout.setf(ios::floatfield,ios::fixed);
	cout.precision(2);
	double mx = 0;
	for(i=0;i<p;i++)parent[i]=i;
	int d=0;
	for(i=0;i<edges.size() && d<(p-s);i++)
	{
		int u = find(edges[i].second.second);
		int v = find(edges[i].second.first);
		if(u!=v)
		{
			parent[u]=v;
			if(mx<edges[i].first)
				mx = edges[i].first;
			d++;
		}
	}
	cout<<mx<<endl;
}

void Input_Graph()
{
	cin>>tc;
	while(tc--)
	{
		cin>>S>>P;
		edges.clear();
		for(i=0;i<P;i++)
		{
			cin>>x>>y;
			pr[i] = make_pair(x,y);
		}
		for(i=0;i<P;i++)
		{
			for(j=i+1;j<P;j++)
			{
				edges.push_back(make_pair(sqrt(pow(pr[i].first-pr[j].first,2)+pow(pr[i].second-pr[j].second,2)),make_pair(i,j)));
			}
		}
		sort(edges.begin(),edges.end());
		MST(S,P);
	}
}


int main()
{
	Input_Graph();
	return 0;
}


/*NAME : Connect the Campus*/
/*ID   : 10397*/
/*Lang.: c++*/


#pragma warning (disable:4786)
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

pair<int,int> pr[10000];

vector<pair< double,pair<int,int> > > edges1;
vector<pair< double,pair<int,int> > > edges2;
int edge,i,j,k;
int parent[10000];
int x,y,num,src,dst;
int u,v;


int find(int p)
{
	if(parent[p]==p)return p;
	return parent[p]=find(parent[p]);
}


void MST(int E)
{
	cout.setf(ios::floatfield,ios::fixed);
	cout.precision(2);
	double sum=0.00;
	for(i=1;i<=edge;i++)parent[i]=i;
	for(i=0;i<edges2.size();i++)
	{
		u = find(edges2[i].second.first);
		v = find(edges2[i].second.second);
		if(u!=v)parent[u]=v;
	}

	for(i=0;i<edges1.size();i++)
	{
		u = find(edges1[i].second.first);
		v = find(edges1[i].second.second);
		if(u!=v)
		{
			parent[u]=v;
			sum=sum+edges1[i].first;
		}
	}
	cout<<sum<<endl;
}


void Input_Graph()
{
	while(cin>>edge)
	{
		edges1.clear();
		edges2.clear();
		for(i=1;i<=edge;i++)
		{
			cin>>x>>y;
			pr[i]=make_pair(x,y);
		}

		for(i=1;i<=edge;i++)
		{
			for(j=i+1;j<=edge;j++)
			{
				edges1.push_back(make_pair(sqrt(pow(pr[i].first-pr[j].first,2)+pow(pr[i].second-pr[j].second,2)),make_pair(i,j)));
			}
		}
		sort(edges1.begin(),edges1.end());
		cin>>num;
		for(i=1;i<=num;i++)
		{
			cin>>src>>dst;
			edges2.push_back(make_pair(sqrt(pow(pr[src].first-pr[dst].first,2)+pow(pr[src].second-pr[dst].second,2)),make_pair(src,dst)));
		}
		sort(edges2.begin(),edges2.end());
		MST(edge);
	}
}


int main()
{
	Input_Graph();
	return 0;
}


/*NAME : Is There A Second Way Left ?*/
/*ID   : 10462*/
/*Lang.: c++*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<climits>
#define inf 1000000
#define pi pair<int,int>

using namespace std;

vector< pair<int,pi> > edges;
vector< pair<int,pi> > E;
vector< pair<int,pi> >::iterator it;
int vertex,edge,src,dst,wet;
int i,j,k,l,tc,res1,res2,temp,d;
int parent[1000000];
bool valid;

int findmin(int a,int b)
{
	return a<b?a:b;
}

int find(int p)
{
	if(parent[p]==p)return p;
	return parent[p]=find(parent[p]);
}


int MST()
{
	int sum=0;
	for(i=1;i<=vertex;i++)parent[i]=i;
	for(i=0;i<edge;i++)
	{
		int u=find(edges[i].second.first);
		int v=find(edges[i].second.second);
		if(u!=v)
		{
			parent[u]=v;
			sum+=edges[i].first;
			if(valid==true)
			{
				E.push_back(make_pair(edges[i].first,make_pair(edges[i].second.first,edges[i].second.second)));
			}
		}
	}
	return sum;
}


void Input_Graph()
{
	cin>>tc;
	for(j=1;j<=tc;j++)
	{
		edges.clear();
		E.clear();
		cin>>vertex>>edge;
		for(i=0;i<edge;i++)
		{
			cin>>src>>dst>>wet;
			edges.push_back(make_pair(wet,make_pair(src,dst)));
		}
		sort(edges.begin(),edges.end());
		valid=true;
		res1 = MST();
		valid=false;
		if(E.size()<vertex-1)
			cout<<"Case #"<<j<<" : No way"<<endl;
		else
		{
			res2=inf;
			for(k=0;k<E.size();k++)
			{
				for(l=0;l<edges.size();l++)
				{
					if(E[k]==edges[l])
					{
						temp=edges[l].first;
						edges[l].first=inf;
						sort(edges.begin(),edges.end());
						res2=findmin(res2,MST());
					}
				}
				for(l=0;l<edges.size();l++)
				{
					if(edges[l].first==inf)edges[l].first=temp;
				}
			}
			if(res2!=inf)
				cout<<"Case #"<<j<<" : "<<res2<<endl;
			else
				cout<<"Case #"<<j<<" : No second way"<<endl;
		}
	}
		
}

int main()
{
	Input_Graph();
	return 0;
}


/*NAME : ACM Contest and Blackout*/
/*ID   : 10600*/
/*Lang.: c++*/

#pragma warning(disable: 4786)
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cstring>
#include<climits>
#define inf 1000000
#define pi pair<int,int>

using namespace std;

vector< pair<int,pi> > edges;
vector< pair<int,pi> > E;
vector< pair<int,pi> >::iterator it;
int vertex,edge,src,dst,wet;
int i,j,k,l,tc,res1,res2,temp;
int parent[10000000];
bool valid;

int findmin(int a,int b)
{
	return a<b?a:b;
}

int find(int p)
{
	if(parent[p]==p)return p;
	return parent[p]=find(parent[p]);
}


int MST()
{
	int sum=0;
	for(i=1;i<=vertex;i++)parent[i]=i;
	for(i=0;i<edge;i++)
	{
		int u=find(edges[i].second.first);
		int v=find(edges[i].second.second);
		if(u!=v)
		{
			parent[u]=v;
			sum+=edges[i].first;
			if(valid==true)
			{
				E.push_back(make_pair(edges[i].first,make_pair(edges[i].second.first,edges[i].second.second)));
			}
		}
	}
	return sum;
}

void Input_Graph()
{
	cin>>tc;
	while(tc--)
	{
		edges.clear();
		E.clear();
		cin>>vertex>>edge;
		for(i=0;i<edge;i++)
		{
			cin>>src>>dst>>wet;
			edges.push_back(make_pair(wet,make_pair(src,dst)));
		}
		sort(edges.begin(),edges.end());
		valid=true;
		res1 = MST();
		valid=false;
		res2=inf;
		for(k=0;k<E.size();k++)
		{
			for(l=0;l<edges.size();l++)
			{
				if(E[k]==edges[l])
				{
					temp=edges[l].first;
					edges[l].first=inf;
					sort(edges.begin(),edges.end());
					res2=findmin(res2,MST());
				}
			}
			for(l=0;l<edges.size();l++)
			{
				if(edges[l].first==inf)edges[l].first=temp;
			}
		}
		cout<<res1<<" "<<res2<<endl;
	}
}
int main()
{
	Input_Graph();
	return 0;
}


/*NAME : Traffic Flow*/
/*ID   : 10842*/
/*Lang.: c++*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#define pi pair<int,int>

using namespace std;

vector< pair<int,pi> > edges;
int vertex,edge,src,dst,wet;
int i,j,k,l,sum,mn,tc,cs;
int parent[1000000];


int find(int p)
{
	if(parent[p]==p)return p;
	return parent[p]=find(parent[p]);
}


int MST()
{
	for(i=0;i<vertex;i++)parent[i]=i;
	mn = INT_MAX;
	for(i=0;i<edge;i++)
	{
		int  u = find(edges[i].second.first);
		int  v = find(edges[i].second.second);
		if(u!=v)
		{
			parent[u]=v;
			if(edges[i].first<mn)
				mn=edges[i].first;
		}
	}
	return mn;
}

void Input_Graph()
{
	cin>>tc;
	for(cs=1;cs<=tc;cs++)
	{
		cin>>vertex>>edge;
		edges.clear();
		for(i=0;i<edge;i++)
		{
			cin>>src>>dst>>wet;
			edges.push_back(make_pair(wet,make_pair(src,dst)));
		}
		sort(edges.begin(),edges.end());
		reverse(edges.begin(),edges.end());
		cout<<"Case #"<<cs<<": "<<MST()<<endl;
	}
}


int main()
{
	Input_Graph();
	return 0;
}
