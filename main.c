//
//  main.c
//  Massiv
//
//  Created by Алексей Баринов on 15.10.2017.
//  Copyright © 2017 Era Company. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, const char * argv[]) {
    int s1, s2, i1, i2, m2,m1; //строчки,столбцы,два счётчика,память
    int Mas[15][15];
    printf("Произвольный массив:\n");
    srand((unsigned int) time(NULL));
    s1 = rand()%(6-3) + 4; //Получаем случайное кол-во строк
    s2 = rand()%(6-4) + 5; //Получаем случайное кол-во столбцов
 
    for (i1=0; i1<s1; i1++) //Вводим случайный массив
    {
        for (i2=0; i2<s2; i2++) {
            Mas[i1][i2] = rand()%150-50;
            printf("%5i", Mas[i1][i2]);
        }
        printf("\n");
    }
    printf("Массив с изменённой первой и последней строкой\n");
    i2 = 1;
        for (i1=0; i1<(((int)s2/2)); i1++){  //Переворачиваем первую строчку
            m1 = Mas[0][i1];
            Mas[0][i1] = Mas[0][s2-i2];
            Mas[0][s2-i2] = m1;
            i2++;
        }
        i2=1;
        for (i1=0; i1<((int)(s2/2)); i1++){  //Переворачиваем последнюю строчку
            m1 = Mas[s1-1][i1];
            Mas[s1-1][i1] = Mas[s1-1][s2-i2];
            Mas[s1-1][s2-i2] = m1;
            i2++;
        }
    
    for (i1=0; i1<s1; i1++) {  //Выводим изменённый массив
        for (i2=0; i2<s2; i2++){
            printf("%5i", Mas[i1][i2]);
        }
        printf("\n");
    }
    m1=0;
    m2=0;
    for (i1=0; i1<s1; i1++) {
        for (i2=0; i2<s2; i2++) {
            if (Mas[i1][i2]<Mas[m1][m2]) {
                m1=i1;
                m2=i2;
            }
        }
    }
    printf("\n");
    printf("Минимум: %i", Mas[m1][m2]);
    printf("\n");
    for (i1=0; i1<s1-1; i1++) {
        for (i2=m2; i2<s2-1; i2++) {
            Mas[i1][i2]=Mas[i1][i2+1];
        }
    }
    for (i1=m1; i1<s1; i1++) {
        for (i2=0; i2<s2-1; i2++) {
            Mas[i1][i2]=Mas[i1+1][i2];
        }
    }
    
    for (i1=0; i1<(s2-1); i1++) {
        Mas[s1][i1] = 0;
    }
    for (i1=0; i1<(s2-1); i1++) {
        Mas[i1][s2] = 0;
    }
    for (i1=0; i1<(s1-1); i1++) {
        for (i2=0; i2<(s2-1); i2++) {
            printf("%5i",Mas[i1][i2]);
        }
        printf("\n");
    }
    //
    printf("\n");
    return 0;
}
