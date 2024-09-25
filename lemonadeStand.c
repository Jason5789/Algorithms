#include <stdio.h>
#include <stdbool.h>

bool lemonadeChange(const int* bills, int billsSize) {
    int d5 = 0;
    int d10 = 0;
    for (int i = 0; i < billsSize; i++) {
        if (bills[i] == 5) {
            d5++;
        }
        else if (bills[i] == 10) {
            if (d5 > 0) { d5--; d10++; }
            else { return false; }
        }
        else { // bill is $20
            if (d10 > 0 && d5 > 0) { d10--; d5--; }
            else if (d5 >= 3) { d5 -= 3; }
            else { return false; }
        }
    }
    return true;
}

int main() {
    int bills1[] = {5, 5, 5, 10, 20};
    int bills2[] = {5, 5, 10, 10, 20};
    int bills3[] = {5, 10, 5, 5, 5, 10, 20};
    printf("%s\n", lemonadeChange(bills1, sizeof(bills1) / sizeof(bills1[0])) ? "true" : "false");
    printf("%s\n", lemonadeChange(bills2, sizeof(bills2) / sizeof(bills2[0])) ? "true" : "false");
    printf("%s\n", lemonadeChange(bills3, sizeof(bills3) / sizeof(bills3[0])) ? "true" : "false");
    return 0;
}