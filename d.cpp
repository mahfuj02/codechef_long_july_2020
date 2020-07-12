#include<bits/stdc++.h>
using namespace std;
#define Fast_read         ios_base::sync_with_stdio(false);
#define ll long long int
int main()
{
    Fast_read
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        map<ll,ll>all, mp, mp1;
        int flag = 0;
        ll arr[n+5],ara[n+5];
        //vector<int>v,v1;
        for(int i = 0; i<n; i++)
        {
            cin>>arr[i];
            all[arr[i] ]++;
            mp[arr[i] ]++;

        }
        for(int i = 0; i<n; i++)
        {
            cin>>ara[i];
            all[ara[i] ]++;

        }
        for(int i = 0; i<n; i++)
        {
            if(all[arr[i]]%2)
            {
                flag =1;
                break;
            }
            if(all[ara[i]]%2)
            {
                flag =1;
                break;
            }
        }

        if(flag)
        {
            cout<<-1<<endl;
            continue;
        }
        map<ll,ll> :: iterator it;
        ll cnt = 0;
        for( it = all.begin() ; it!= all.end(); it++)
        {
            if(mp[it->first ] != it->second/2)
            {
                mp1[it->first]= abs((it->second/2)-mp[it->first] );
                // cout<<mp1[it->first]<<endl;
                cnt+=mp1[it->first];
            }

        }

        cnt/=2;
       // cout<<cnt<<endl;
        // for(int)


        ll tmp ;

        it = all.begin();
        tmp = it->first;
        //a  cout<<tmp<<endl;
        ll ans =0;
        for(it = mp1.begin(); it!=mp1.end() ; it++)
        {

            if(cnt<=0)break;
            if(it->first<=tmp*2)
            {

                if(cnt>=it->second)  ans+=it->first*it->second;
                else ans+=it->first*cnt;
            }
            else
            {
                if(cnt>=it->second)   ans+=(tmp*2)*it->second;
                else ans+=(tmp*2)*cnt;
            }
            cnt-=it->second;
        }

        cout<<ans<<endl;
    }

}
