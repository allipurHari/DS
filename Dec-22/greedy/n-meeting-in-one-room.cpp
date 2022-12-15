https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    bool comp(const pair<int, int> p1, const pair<int, int> p2){
        if(p1.first == p2.first)
            return p1.second < p2.second;
        return p1.first < p2.first;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        pair<int,int> v[n];
        for(int i = 0;i < n;i++){
            v[i].first = start[i];
            v[i].second = end[i];
        }
        sort(v, v+n);
        int ans = 0;
        int mn = INT_MIN;
        for(int i = 0;i < n;i++){
            if(v[i].first > mn){
                mn = v[i].second;
                ans++;
                // cout<<mn<<endl;
            }
            else{
                mn = min(mn, v[i].second);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
