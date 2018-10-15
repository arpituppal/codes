#include<stdio.h>
int main()
{
	int a1,a2,a3;
	int d,e;
	int r,c;
	while(1)
	{
		scanf("%d %d %d",&a1,&a2,&a3);
		if(a1==0&&a2==0&&a3==0)
			break;
		d=a2-a1;
		e=a3-a2;
		if(d==e)
			printf("AP %d\n",(a3+d));
		else
		{
			r=a3/a2;
			c=a3*r;		
			printf("GP %d\n",c);
		}
	}
	return 0;
}
