#include<stdio.h>
int gcd(int a ,int b)
{
    if(a==b)
        return a;
    if((a%2==0)){
        if(!(b%2==0))
            return gcd(a>>1,b);
        else
            return gcd(a>>1,b>>1)<<1;
    }
    if(b%2==0){
        return gcd(a,b>>1);
    }
    if(a>b)
        return gcd((a-b)>>1,b);
    return gcd((b-a)>>1,a);
}
int main()
{
    int a,b,c;
    scanf("%d %d",&a,&b);
    c=gcd(a,b);
    printf("%d",&c);
}

