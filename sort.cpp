#include <iostream>
using namespace std;

int main()
{
    int temp, min;

    int subject[5][7] = {{20001, 30, 30, 20, 20, 0, 0},
                         {20002, 27, 24, 13, 18, 0, 0},
                         {20003, 25, 28, 16, 17, 0, 0},
                         {20004, 30, 24, 19, 20, 0, 0},
                         {20005, 29, 26, 20, 19, 0, 0}};

    char name[][8] = {"민우", "동현", "철수", "진영", "태영"};
    char scor[5];

    for (int i = 0; i < 5; i++){
        for (int j = 1; j < 5; j++){
            subject[i][5] = subject[i][5] + subject[i][j];
        }

        subject[i][6] = subject[i][5] / 4;

        if (subject[i][5] >= 90) scor[i] = 'A';
        else if (subject[i][5] >= 80) scor[i] = 'B';
        else if (subject[i][5] >= 70) scor[i] = 'C';
        else if (subject[i][5] >= 60) scor[i] = 'D';
    }

    printf("학번  이름  중간  기말  출석  과제  합계  평균    등급\n");
    printf("----------------------------------------------------------------\n");

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 4-i; j++){
            if(subject[j][5] < subject[j+1][5]){
                for(int k = 0; k<7; k++){
                    temp = subject[j][k];
                    subject[j][k] = subject[j+1][k];
                    subject[j+1][k] = temp;
                }
            }
        }
    }


    for (int i = 0; i < 5; i++) {

        printf("%5d", subject[i][0]);
        printf(" %s", name[i]);

        for (int j = 1; j < 7; j++) { printf("%6d", subject[i][j]); }

        printf("   %c등급", scor[i]);
        printf("\n");
    }
}