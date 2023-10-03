#include<bits/stdc++.h>
using  namespace std;
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

    cout<<"Enter the time quantum: "<<endl;
    int q;
    cin>>q;
    map<int,int>bmap;
    for(int i=0;i<p;i++)bmap[i+1]=burst[i];
    vector<pair<int,int>>bpair;
    for(int i=0;i<p;i++)
    {
        bpair.push_back({i+1,arrival[i]});///store in pair (process number,arrival time)
    }
    sort(bpair.begin(),bpair.end(),cmp);
    //vector<pair<int,int>>v;
    queue<int>v;
    map<int,int>track;
    int  temp=0;
    map<int,int>ct;
    vector<int>final_process;
    for(int i=0;i<p;i++)
    {
        if(bpair[i].second==0)
        {
            v.push(bpair[i].first);

        }

    }
    while(1)///calculate completion time
    {
        if(v.empty())
        {
            bool check=false;
            for(int j=0;j<p;j++)
            {
                if(track[bpair[j].first]==0)
                {
                    v.push(bpair[j].first);
                    check=true;
                    break;
                }
            }
            if(check==false)break;
        }

        int a=v.front();
        v.pop();
        if(bmap[a]<q)temp+=bmap[a];
        else temp+=q;
        ct[a]=temp;
        track[a]=1;
        bmap[a]-=q;
        for(int j=0;j<p;j++)
        {
            if(track[j+1]==0 and arrival[j]<=temp)
            {
                track[j+1]=1;
                v.push(j+1);
            }
        }
        if(bmap[a]>0)v.push(a);
    }
    map<int,int>tat;///catculate turn around time
    for(int i=0;i<p;i++)
    {
        tat[i+1]=ct[i+1]-arrival[i];
    }
     map<int,int>wt;///calculate waiting time
    for(int i=0;i<p;i++)
    {
        wt[i+1]=tat[i+1]-burst[i];
    }

    for(int i=0;i<p;i++)///print ANswer
    {
        int fp=i+1;
        cout<<"p"<<fp<<" AT: "<<arrival[fp-1]<<" BT: "<<burst[fp-1]<<" CT: "<<ct[fp]<<" TAT: "<<tat[fp]<<" WT: "<<wt[fp]<<endl;
    }

}
