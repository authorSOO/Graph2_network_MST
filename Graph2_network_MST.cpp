#include <queue>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	bool c[1001];
	vector<pair<int,int>> a[1001];
	memset(c,false,sizeof(c));
	for(int i=0;i<m;i++){
		int start,end,cost;
		cin>>start>>end>>cost;
		a[start].push_back(make_pair(end,cost));
		a[end].push_back(make_pair(start,cost));
	}
	c[1]=true;
	int ans =0;
	priority_queue<pair<int,int>> q;
	for(auto &p : a[1]){
		q.push(make_pair(-p.second,p.first));
	}
	while(!q.empty()){
		auto x = q.top();
		q.pop();
		if(c[x.second])continue;
		c[x.second]=true;
		ans += -x.first;
		for(auto &p : a[x.second])q.push(make_pair(-p.second,p.first));
		
	}
	cout<<ans<<endl;
	
	return 0;
}
