#include <stdio.h>

int abs(int a){
    if(a<0){
        return -a;
    }
    else{
        return a;
    }
}

void update(int *a,int *b) {
    // Complete this function
      int pa, pb;
      pa = *a+*b;
      pb = abs(*a-*b);
      *a = pa;
      *b = pb;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}

