#include<bits/stdc++.h>
using namespace std;
#define Fast_read         ios_base::sync_with_stdio(false);
#define ll long long int

int main()
{
        int t;
        cin>>t;
        while(t--)
        {
            int n;
            ll x;

            cin>>n;

            cin>>x;
            vector<ll>smaller;
            vector<ll>v;
            for(int i= 0 ; i<n; i++)
            {
                ll a;
                cin>>a;
                if(a<=x)
                {
                    smaller.push_back(a);
                }
                else
                {
                    v.push_back(a);
                }
            }
            ll ans = 0;
            sort(v.begin(),v.end());
            for(int i = 0; i < v.size() ; i++)
            {
                if(x>=v[i])
                {
                    ans++;
                    x = v[i]*2;

                    continue;
                }
                while(x<v[i])
                {
                    ans++;
                    x*=2;

                }
                ans++;
                x = v[i]*2;

            }
            cout<<ans+smaller.size()<<endl;

        }
}
