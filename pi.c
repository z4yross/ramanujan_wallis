#include<stdio.h>
#include<math.h>
#include<stdlib.h>

long double PI = 3.1415926535897932384626433;

unsigned long long factorial(int n){
    unsigned long long fact = 1;
    for (int i = 1; i <= n; ++i) fact *= i;
    return fact;
}

long double wallis(int n){
    long double prd = 1.0;

    for(double i = 1.0; i < n; i++){
        long double a = (2.0 * i) / (2.0 * i - 1.0);
        long double b = (2.0 * i) / (2.0 * i + 1.0);

        prd *= (a*b);
    }

    return 2 * prd;
}


long double ramanujan(int n){
    long double sum = 0;
    long double a = (2 * sqrt(2)) / pow(99, 2);

    for (int i = 0; i < n; i++){
        long double b = factorial(4 * i) / pow(factorial(i), 4);
        long double c = (26390 * i + 1103) / pow(396, 4*i);

        sum += b * c;
    }

    return 1 / (a * sum);
}



int main(){
    int n = 100;

    int l = snprintf(NULL, 0, "%Lf", PI);
    char* pi = malloc( l + 1 );
    snprintf(pi, l + 1, "%Lf", PI);

    printf(pi);

    //scanf("%d", &n);


    //printf("Valores:\npi:        %LF\nwallis:    %LF\nramanujan: %LF", PI, wallis(n), ramanujan(n));

    free(pi);

    return 0;
}

