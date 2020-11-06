int fibo(int a)
{
    if (a<2) return 1;
    else
        return fibo(--a)+fibo(--a);
}
void main()
{
    int i;
    for(i=0;i<10;i++)
        printf("%d's: %d\n",i+1,fibo(i));
}