#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    int add = 2;
    for(int r = 0; r < 8; r++){
        if(add < 8){
            if(r == 0)
                cout << "   ";
            if(r == 1)
                cout << "  ";
            if(r == 2)
                cout << " ";
            if(r == 5)
                cout << " ";
            if(r == 6)
                cout << "  ";
            if(r == 7)
                cout << "   ";
            for(int c = 0; c < 8 - (8 - r) + add; c++){
                cout << "#" ;
            }
            if(r == 3)
                add = 3;
            if(r == 4)
                add = 0;
            if(r == 5)
                add = -3;
            if(r == 6)
                add = -6;
            cout << endl;
            add++;
        }
    }
}