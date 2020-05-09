#include <stdio.h>
#define bool int
#define true 1;
#define false 0;

bool isHappy(int num){
    int n=num, x, d, sum;
    while(1) {
        sum = 0;
        x = n;
        while(x!=0) {
            d = x%10;
            sum += d*d;
            x = x/10;
        }
        if(sum==1)
            return true;
        else if(sum==num)
            return false;
        else
            n = sum;
    }

}

int main() {
    isHappy(19);
}