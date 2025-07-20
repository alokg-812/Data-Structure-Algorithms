#include<iostream>
using namespace std;
int main(){
    int numbers[3] = {10, 20, 30};
    // int numbers[3] = {10, 20.7, 30}; cannot be a value of non integer type
    cout << "Array elements: ";
    for (int i = 0; i < 3; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    // 2D array;
    int arr[3][6];
    int cnt = 0;
    for(int i = 0; i<3;i++){
        for(int j = 0;j<6;j++){
            arr[i][j] = cnt;
            cnt++;
        }
    }
    for(int i = 0; i<3;i++){
        for(int j = 0;j<6;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";


    // Strings
    // * Mutable

    string s = "strivers";
    int len = s.size();
    cout<<s[len-1]<<endl;
    s[len-1] = 'z';
    cout<<s[len-1]<<endl;
    return 0;
}