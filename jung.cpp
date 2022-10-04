#include <stdio.h> // main
//#include <stdlib.h> srand(time(NULL))
//#include <time.h> time(NULL)
//#include<math.h> sqrt(루트값)
#include <string.h>
#pragma warning(disable : 4996) // scanf

int main() {
    char N[100], cnt = 0;
    scanf("%s", N);

    for (int i = 0; i < strlen(N); i++) {
        if (N[i] == 'c') {
            cnt++;
            if (N[i + 1] == '=')
                i++;
            else if (N[i + 1] == '-')
                i++;
        } else if (N[i] == 'd') {
            cnt++;
            if (N[i + 1] == 'z') {
                if (N[i + 2] == '=')
                    i += 2;
                else
                    i++;
            } else if (N[i + 1] == '-')
                i++;
        } else if (N[i] == 'l' and N[i + 1] == 'j') {
            i++;
            cnt++;
        } else if (N[i] == 'n' and N[i + 1] == 'j') {
            i++;
            cnt++;
        } else if (N[i] == 's' and N[i + 1] == '=') {
            i++;
            cnt++;
        } else if (N[i] == 'z' and N[i + 1] == '=') {
            i++;
            cnt++;
        } else
            cnt++;
    }
    printf("%d", cnt);
}