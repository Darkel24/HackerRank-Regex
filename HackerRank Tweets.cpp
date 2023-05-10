#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<ctype.h>
using namespace std;
int main()
{
    long long num,count,C,L,a[100000],i,j,k,l,m,n,kase;
    string s,s1;
    vector<long>v1;
    vector<long>v2;
    map<char,int>m1;
    map<char,int>m2;
    cin>>kase;
    count=0;
    string str="hackerrank";
    getchar();
    while(kase--)
    {
        s1="";
        getline(cin,s);
        int len=s.size();
        for(i=0; i<len; i++)
        {
            if(s[i]=='h'||s[i]=='H')
            {
                s1="";
                int len1=i+10;
                if(len1>len)
                {
                    break;
                }
                for(j=i; j<len1; j++)
                {
                    char ch=tolower(tolower(s[j]));
                    s1+=ch;
                }
                if(s1==str)
                {
                    count++;
                }
            }
        }
    }
     cout<<count<<endl;
        return 0;
    }
