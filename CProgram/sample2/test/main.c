#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=3 ,b=4 ,c=5;
    int *pa = &a , *pb=&b,*pc=&c;
    printf("1.a=b*c\n");
    a=b*c;
    printf("a = %d\tb = %d\tc = %d\tpa = %d\tpb = %d\tpc = %d\n",a,b,c,*pa,*pb,*pc);
    a=3 ,b=4 ,c=5;
pa = &a , pb=&b,pc=&c;
    printf("2.a*=c\n");
    a*=c;
      printf("a = %d\tb = %d\tc = %d\tpa = %d\tpb = %d\tpc = %d\n",a,b,c,*pa,*pb,*pc);
     a=3 ,b=4 ,c=5;
pa = &a , pb=&b,pc=&c;
    printf("3.b=*pa\n");
    b=*pa;
       printf("a = %d\tb = %d\tc = %d\tpa = %d\tpb = %d\tpc = %d\n",a,b,c,*pa,*pb,*pc);
     a=3 ,b=4 ,c=5;
pa = &a , pb=&b,pc=&c;
    pc=pa;
       printf("4.a = %d\tb = %d\tc = %d\tpa = %d\tpb = %d\tpc = %d\n",a,b,c,*pa,*pb,*pc);
     a=3 ,b=4 ,c=5;
pa = &a , pb=&b,pc=&c;
     *pb=b*c;
       printf("5.a = %d\tb = %d\tc = %d\tpa = %d\tpb = %d\tpc = %d\n",a,b,c,*pa,*pb,*pc);
    a=3 ,b=4 ,c=5;
pa = &a , pb=&b,pc=&c;
     c=(*pa)*(*pc);
      printf("6.a = %d\tb = %d\tc = %d\tpa = %d\tpb = %d\tpc = %d\n",a,b,c,*pa,*pb,*pc);
     a=3 ,b=4 ,c=5;
pa = &a , pb=&b,pc=&c;
    *pc=a*(*pb);
     printf("7.a = %d\tb = %d\tc = %d\tpa = %d\tpb = %d\tpc = %d\n",a,b,c,*pa,*pb,*pc);

    return 0;
}
