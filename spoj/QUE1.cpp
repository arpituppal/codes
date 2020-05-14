    #include<cstdio>
    #include<algorithm>
    int a[1000],b[1000],c[1000],ans[1000];
    int main()
    {
    int t;
    scanf("%d",&t);
    while(t--)
    {
    int i,n,j,k=1,ind=0,f=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    scanf("%d",&b[i]);
    for(i=0;i<n;i++)
    c[i]=a[i];
    std::sort(c,c+n);
    for(i=0;i<n;i++)
    {
      k=0,f=0;
      for(j=0;j<n;j++)
      {
        if(a[j]==c[i])
         ind=j;
      }
    for(j=0;j<n;j++)
    {
      if(ans[j]==0)
        k++;
        if(k==(b[ind]+1))
       {
       	     
          ans[f]=c[i];
         
           break;
         }
         f++;
       }
    }
    for(i=0;i<n;i++)
    printf("%d ",ans[i]);
    printf("\n");
    for(i=0;i<n;i++)
    ans[i]=0;
    }
    
    return 0;
    }