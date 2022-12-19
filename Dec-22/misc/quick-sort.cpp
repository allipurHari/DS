#include </Users/allipur.reddy/Delete Folder/cpp/stdc++.h>
using namespace std;

int arrange(vector<int> &a, int low, int high){
    int i = 0;
    for(int j = low;j < high;j++){
        if(a[j] < a[high])
            swap(a[i++], a[j]);
    }
    swap(a[i], a[high]);
    return i;
}

void sort(vector<int> &v, int low, int high){
    if(low < high){
        int pivot = arrange(v, low, high);
        sort(v, low, pivot-1);
        sort(v, pivot+1, high);
    }
}

void printV(vector<int> v){
    for(int i = 0;i < v.size();i++)
        cout<<" "<<v[i];
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i = 0;i < n;i++)
        cin>>v[i];
    sort(v, 0, n-1);
    printV(v);
}
