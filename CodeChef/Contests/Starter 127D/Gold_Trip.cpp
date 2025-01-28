#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
    cout<<"Enter t: ";
    cin>>t;
    cout<<"Input number of test cases: "<<T<<endl;;
	for(int i = 0 ; i < t ; i++){
	    int N;
        cout<<"Enter N: ";
        cin>>N; // N denotes the total number of Islands.
	    int arr[N];
	    for(int j = 0 ; j < N ; j++){
	        cin>>arr[j];	        
	    }
        cout<<"Input Array: ";
        for(int k = 0 ; k < N ; k++){
            cout<<arr[k]<<" ";
        }
        cout<<endl;
        int Q;
        cout<<"Enter Q value: ";
        cin>>Q;
        int Q1,Q2;
        for(int j = 0 ; j < Q ; j++){
            cin>>Q1>>Q2;  
            int sum = 0 ;     
            for(int z = Q1-1 ; z <= Q2-1 ; z++){
                sum += arr[z];
            }     
            cout<<sum<<endl;
        }
	}
}
