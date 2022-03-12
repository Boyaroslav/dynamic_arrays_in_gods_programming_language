#include<stdio.h>
#include<stdlib.h>
int to_int(char x[]){
    int ans = 0;
    int l = 1;
    int i=1;
    int negative = 0;
    while(x[i]>='0' && x[i] <= '9'){
        l*=10;i++;
    }
    if(x[0] == '-'){
        x[0] = '0';negative = 1;
    }
    for(int i = 0; x[i]>='0' && x[i] <= '9'; i++){
        ans += (x[i] - '0') * l;l/=10;
    }
    if (negative){ans *=-1;}
    return ans;
}
int main(){
    int *x = (int*)calloc(5, sizeof(int));
    char v;
    for(int i=0;i<5;i++){
        char buf[1000] = {'\n'};
        v = getchar();
        int j=0;
        while((v>='0' && v<='9' ) || v=='-'){buf[j]=v;j++;v=getchar();}
        x[i] = to_int(buf);
    }
    int sum=0;
    for(int i=0;i<5;i++){
        printf("%d ", x[i]);sum+=x[i];
    }
    printf("\n%d", sum);
}