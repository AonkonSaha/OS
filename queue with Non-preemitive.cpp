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
bool cmp2(pair<int,int>x,pair<int,int>y)
{
    if(x.second<y.second)return false;
    return true;
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

    cout<<"Enter the priority numbers: "<<endl;
    int priority[p];
    for(int i=0;i<p;i++)cin>>priority[i];
    cout<<"Set the priority:"<<endl<<"press 1 for less value priority"<<endl<<"press 2 for higher value priority"<<endl;
    int priority_set;
    cin>>priority_set;
    map<int,int>pmap;
    for(int i=0;i<p;i++)
    {
        pmap[i+1]=priority[i];
    }


    vector<pair<int,int>>apair;
    for(int i=0;i<p;i++)
    {
        apair.push_back({i+1,arrival[i]});///store in pair (process number,arrival time)
    }
    sort(apair.begin(),apair.end(),cmp);
    vector<pair<int,int>>v;
    map<int,int>track;
    int  temp=0;
    map<int,int>ct;
    vector<int>final_process;
    for(int i=0;i<p;i++)
    {
        if(apair[i].second==0)
        {
            v.push_back({apair[i].first,priority[apair[i].first-1]});
        }

    }
    for(int i=0;i<p;i++)///calculate completion time
    {
        int a,b;

        if(v.empty())
        {
            bool check=false;
            for(int j=0;j<p;j++)
            {
                a=apair[j].first;
                if(track[a]==0)
                {
                    check=true;
                    break;
                }
            }
            if(check==false)break;
        }
        else
        {
          a=v[0].first;
          v.erase(v.begin()+0);
        }
        final_process.push_back(a);
        temp+=burst[a-1];
        ct[a]=temp;
        track[a]=1;
        for(int j=0;j<p;j++)
        {
            if(track[j+1]==0 and arrival[j]<=temp)
            {
                track[j+1]=1;
                v.push_back({j+1,priority[j]});
            }
        }
        if(priority_set==1)
        {
            sort(v.begin(),v.end(),cmp);

        }
        else sort(v.begin(),v.end(),cmp2);

        for(int j=0;j<v.size();j++)
        {
            for(int k=j+1;k<v.size();k++)
            {
                a=v[j].first;b=v[k].first;
                if(v[j].second==v[k].second and arrival[a-1]>arrival[b-1])swap(v[j],v[k]);
                else if(v[j].second==v[k].second and arrival[a-1]==arrival[b-1] and a>b)swap(v[j],v[k]);
            }
        }

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

    for(int i=0;i<final_process.size();i++)///print ANswer
    {
        int fp=final_process[i];
        cout<<"p"<<fp<<" priority: "<<priority[fp-1]<<" AT: "<<arrival[fp-1]<<" BT: "<<burst[fp-1]<<" CT: "<<ct[fp]<<" TAT: "<<tat[fp]<<" WT: "<<wt[fp]<<endl;
    }

}
