/*QUESTION:Discover 3 different logic to swap two integers. Ensure correctness is
guaranteed; logic must work for all inputs.*/
//SWAP TWO NUMBERS
#include<stdio.h>
void swap_with_variable(int a,int b)
{
    int temp=b;
    b=a;
    a=temp;
    printf("%d %d\n",a,b); 
}
void swap_without_variable(int a,int b)
{
    a=a+b;
    b=a-b;
    a=a-b;
    printf("%d %d\n",a,b); 
}
void swap_using_bitwise(int a,int b)
{
    a=a^b;
    b=a^b;
    a=a^b;
    printf("%d %d\n",a,b); 
}
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    swap_with_variable(a,b);
    swap_without_variable(a,b);
    swap_using_bitwise(a,b);
    
}
