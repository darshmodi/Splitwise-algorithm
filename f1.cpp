#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll i,j,k,n,x,y,z,sum,l,r;
    cin>>n;
    ll a[n]={0};
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>x>>y>>z;
        a[x]+=(-z);
        a[y]+=z;
    }
    pair<ll,ll>p[n];
    for(i=0;i<n;i++)
    {
        p[i].first=a[i];
        p[i].second=i;
    }
    sort(p,p+n);
    l=0;
    r=n-1;
    while(l<=r)
    {
        i=l;
        j=r;
        if(p[i].second==p[j].second )
        {
            break;
        }
        if(-p[i].first<=p[j].first)
        {
            while(-p[i].first<=p[j].first)
            {
				if(p[i].second==p[j].second || p[i].first==0 || p[j].first==0)
		        {
		        	i++;
		            break;
		        }
                cout<<p[i].second<<" TO "<<p[j].second<<" - "<<-p[i].first<<"\n";
                p[j].first+=p[i].first;
                p[i].first=0;
                i++;
                
            }
            if(p[j].first!=0)
            {
            	if(p[i].second==p[j].second)
		        {
		            break;
		        }
                cout<<p[i].second<<" TO "<<p[j].second<<" - "<<p[j].first<<"\n";
                p[i].first+=p[j].first;
                p[j].first=0;
                j--;
            }
        }
        else
        {
            while(-p[i].first>=p[j].first)
            {
            	if(p[i].second==p[j].second || p[i].first==0 || p[j].first==0)
		        {
		        	j--;
		            break;
		        }
                cout<<p[i].second<<" TO "<<p[j].second<<" - "<<p[j].first<<"\n";
                p[i].first+=p[j].first;
                p[j].first=0;
                j--;
            }
            if(p[i].first!=0)
            {
            	if(p[i].second==p[j].second)
		        {
		            break;
		        }
                cout<<p[i].second<<" TO "<<p[j].second<<" - "<<-p[i].first<<"\n";
                p[j].first+=p[i].first;
                p[i].first=0;
                i++;
            }
        }

        l=i;
        r=j;
    }
}

