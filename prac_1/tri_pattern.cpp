#include <iostream>
using namespace std;

int main()
{
    int minus = 0;
    
    for(int r = 0; r < 4; r++){
        if( minus < 4){
          if(minus == 1){
                cout << " ";
            }else if(minus == 2){
                cout << "  ";
            }else if(minus == 3){
                cout << "   ";
            }
            for(int c = 0; c < 8 - r - minus; c++){ 
                cout << "#";
            }
            cout << endl;
            minus++;
            
        }
    }
}