    #include<stdio.h>
    int a[1000000]={0};
    int main()
    {
        int s,n,i;
        scanf("%d",&s);
        for(i=0;i<s;i++)
        {
            scanf("%d",&n);
            a[n]++;
        }
        for(i=0;i<1000001;i++)
        {
            while(a[i]>0)
            {
                printf("%d\n",i);
                a[i]--;
            }
        }
        return 0;
    }   