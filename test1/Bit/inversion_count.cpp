#include<iostream>
using namespace std;

int[] Merge(int a[], int b[], int n, int n2) {
    int p1 = 0;
    int p2 = 0;
    int merged_array[n + n2];
    int i = 0;
    while (p1 < n && p2 < n2) {
        if(a[p1] < b[p2]) {
            merged_array[i] = b[p2];
            if (i != p2) cnt++;
            p2++;
            i++;
        }
        else {
            mergerd_array[i] = a[p1]; 
            if (i != p1) cnt++;
            p1++;
            i++;
        }
    }
    return merged_array;
}
void mergeSort(int a[], int b[]) {
     
}
int main() {

}
