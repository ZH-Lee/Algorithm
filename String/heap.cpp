#include <iostream>
#include <vector>
using namespace std;

void adjust(vector<int> &arr, int i, int len){
    int tmp = arr[i];
    for (int k = 2*i+1; k < len; k = 2*k+1){
        if(k+1 < len && arr[k+1] > arr[k]){
            k++;
        }
        if(arr[k] > arr[i]){
            swap(arr[i],arr[k]);
            i = k;
        }
    }
}

int main(){
    vector<int> arr = {4,6,8,5,9};
    for(int i = arr.size()/2-1; i >= 0; i--){
        adjust(arr,0,arr.size());
    }

    for (int i = arr.size()-1; i> 0; i--){
        swap(arr[0],arr[i]);
        adjust(arr,0,i);
    }

    return 0;

}