#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   int n;
   ll x, res = 0;
   cin>>n>>x;
   ll left_size = (n + 1) / 2;
   ll right_size = n - left_size;
   vector<ll> left(left_size), left_subs(1 << left_size);
   vector<ll> right(right_size), right_subs(1 << right_size);
   for(ll i=0;i<n;i++) {
      if (i < left_size)
         cin>>left[i];
      else
         cin>>right[i - left_size];
   }

   for(ll i = 0; i < 1 << left_size; i++) {
      ll sum = 0;
      bitset<64> bs(i);
      for (ll j = 0; j < left_size; j++) {
         if (bs[j])
            sum += left[j];
      }
      left_subs[i] = sum;
   }

   for(ll i = 0; i < 1 << right_size; i++) {
      ll sum = 0;
      bitset<64> bs(i);
      for (ll j = 0; j < right_size; j++) {
         if (bs[j])
            sum += right[j];
      }
      right_subs[i] = sum;
   }

   sort(right_subs.begin(), right_subs.end());

   for(ll i=0;i<1<<left_size;i++) {
      ll target = x - left_subs[i];
      auto range = equal_range(right_subs.begin(), right_subs.end(), target);
      res += distance(range.first, range.second);
   }
   cout<<res;
   return 0;
}
