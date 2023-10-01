#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int>x,pair<int,int>y)
{
    if(x.second>y.second)return false;
    if(x.second==y.second)
    {
        if(x.first>y.first)return false;
        else return true;
    }
    else return true;
}
int main()
{
    cout<<"Enter the number of processes: "<<endl;
    int p;
    cin>>p;

    cout<<"Enter the arrival time: "<<endl;
    int arrival[p];
    for(int i=0;i<p;i++)cin>>arrival[i];

    cout<<"Enter the burst time: "<<endl;
    int burst[p];
    for(int i=0;i<p;i++)cin>>burst[i];

    map<int,int>mp;
    for(int i=0;i<p;i++)
    {
        mp[i+1]=burst[i];///burst mapping
    }

    vector<pair<int,int>>vec;
    for(int i=0;i<p;i++)
    {
        vec.push_back({i+1,arrival[i]});
    }
    sort(vec.begin(),vec.end(),cmp);

   map<int,int>ct;
   int sum=0;
   for(int i=0;i<p;i++)
   {
       int a=vec[i].first;
       int b=vec[i].second;
       if(i==0)ct[a]=mp[a],sum+=mp[a];
       else ct[a]=sum+mp[a],sum+=mp[a];
   }
   //for(auto i:vec)cout<<"p"<<i.first<<" "<<"AT:"<<i.second<<" BT:"<<mp[i.first]<<" "<<"CT:"<<ct[i.first]<<endl;
   map<int,int>tat;
   for(int i=1;i<=p;i++)
   {
       tat[i]=ct[i]-arrival[i-1];
   }
   //for(auto i:vec)cout<<"p"<<i.first<<" "<<"AT:"<<i.second<<" BT:"<<mp[i.first]<<" "<<"CT:"<<ct[i.first]<<" tat:"<<tat[i.first]<<endl;

    map<int,int>wt;
   for(int i=1;i<=p;i++)
   {
       wt[i]=tat[i]-mp[i];
   }
      for(auto i:vec)cout<<"p"<<i.first<<" "<<"AT:"<<i.second<<" BT:"<<mp[i.first]<<" "<<"CT:"<<ct[i.first]<<" TAT:"<<tat[i.first]<<" WT:"<<wt[i.first]<<endl;


    return 0;
}
