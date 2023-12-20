#include<stdio.h>
int airthmeticTological(int x) {
    int res = num >> shift_val;
    int mask = -1 << 32 - shift_val;
    mask = mask ^ res;
    res = res & mask;
    return res;
}
void printBinary(int num) {
    for (int i = sizeof(num) * 8 - 1; i >= 0; i--) {
        int bit = (num >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}
int main() {
    int num;
    printf("num : ");
    scanf("%d", &num);
    int shift_val;
    printf("Shifting : ");
    scanf("%d", &shift_val); 
    printBinary(mask);
    printBinary(res);
    res = arithmeticTological;
    printBinary(res);
}
