#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int monotoneIncreasingDigits(int n) {
    int a=0;
    int b=0;
    char s[11];
    sprintf(s, "%d", n);
    int len = strlen(s);
    
    int flag = len;
    for (int i = len - 1; i > 0; i--) {a++;
        if ( s[i-1] > s[i]) {
            flag = i;
            s[i - 1]--;
        }
    }
    
    for (int j = flag; j < len; j++) {b++;
        s[j] = '9';
    }
    printf("a=%d b=%d\n",a,b);
    return atoi(s);
}

int main() {
    printf("%d\n", monotoneIncreasingDigits(10));
    printf("%d\n", monotoneIncreasingDigits(1234));
    printf("%d\n", monotoneIncreasingDigits(332));
    return 0;
}
