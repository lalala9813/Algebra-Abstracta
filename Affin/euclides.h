#ifndef EUCLIDES_H_INCLUDED
#define EUCLIDES_H_INCLUDED

string alfabeto1 = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ.,_-0123456789";

int euclides(int a, int b)
{
   int q = 0;
   int r = 0;
   while(b != 0){
        q = a/b;
        r = a - (q*b);
        a = b;
        b = r;
   }
   return a;
}

int euclidePLUS(int a, int b)
{
    int r1 = a,r2 = b;
    int s1 = 1,s2 = 0;
    int t1 = 0,t2 = 1;

    while(r2 > 0)
    {
        int q = r1/r2;
        int r = r1-(q*r2);
        r1=r2;r2=r;
        int s = s1-(q*s2);
        s1=s2;s2=s;
        int t = t1-(q*t2);
        t1=t2;t2=t;
    }
    if(s1 < 0)
    {
        s1 = alfabeto1.size() + s1;
        return s1;
    }
    else
    {
        return s1;
    }
}

#endif // EUCLIDES_H_INCLUDED
