#include <iostream>

using namespace std;

// a = q(b) + r

void euclides(int a, int b)
{
    int q = 0;
    int r = 0;


    while(b != 0)
    {
        q = a/b;
        r = a - (q*b);//2
        a = b;
        b = r;
    }
    cout << a;
}

void euclidesPLUS(int a, int b)
{
    int x, y, d, q = 0, r = 0;
    int x1 = 0, x2 = 1, y1 = 1, y2 = 0;

    if(b == 0){
        d = a; x = 1; y = 0;
        cout << "\n" << d << ", " << x << ", " << y << endl;
    }
    else{
        while(b > 0)
        {
            q = a/b;
            r = a -(q*b);
            x = x2 - (q*x1);
            y = y2 - (q*y1);

            a = b;
            b = r;
            x2 = x1;
            x1 = x;
            y2 = y1;
            y1 = y;
        }
        d = a;
        x = x2;
        y = y2;
        cout << d << ", " << x << ", " << y << endl;
    }
}

int main()
{
    euclides(12378,3054);
    euclidesPLUS(356,260);
    return 0;
}
