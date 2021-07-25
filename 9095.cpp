#include <iostream>
#include <stdlib.h>

int factorial (int n) {
    if (n==0){
        return 1;
    }
    if (n==1){
        return 1;
    }
    else
        return n*factorial(n-1);
}

int div2(int n){
    int quo,rem,returnval;
    quo=n/2;
    returnval=0;
    for (int i=1;i<=quo;i++){
        returnval+=factorial(n-i)/(factorial(n-i-i)*factorial(i));
    }
    //printf("div2:%d\n",returnval);
    return returnval;
}

int div3(int n){
    int quo,rem,returnval;
    quo=n/3;
    returnval=0;
    for (int i=1;i<=quo;i++){
        returnval+=factorial(n-2*i)/(factorial(n-2*i-i)*factorial(i));
    }
    //printf("div3:%d\n",returnval);
    return returnval;
}
int divtot(int n){
    int one,two,thr;
    int returnval=0;
    one=n-5;
    two=1;
    thr=1;
    while (true){
        returnval += factorial(one+two+thr)/(factorial(one)*factorial(two)*factorial(thr));
        if (one>=2){
            two++;
            one-=2;
        }
        else {
            thr++;
            two=1;
            one=n-2-3*thr;
        }
        if (one<0 ||one+2*two+3*thr>n){
            //printf("divtot:%d\n",returnval);
            return returnval;
        }
    }
}

int main()
{
    int n;
    std::cin >> n;
    int* arr;
    arr = (int*)malloc (n*sizeof(int));
    for (int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    int result=0;

    for (int i=0;i<n;i++){
        result=1+div2(arr[i])+div3(arr[i]);
        if (arr[i]>4){
            result += divtot(arr[i]);
        }
        printf("%d\n",result);
    }
    return 0;
}
