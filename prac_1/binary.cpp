#include <iostream>
#include <list>
#include <cmath>
using namespace std;

int main()
{
    
    const long long int divisor = 2;
    int remain = 0;
    int reverseNum = 0;
    int result = 0;

    std::list<int> number;
    

    // needs to be reversed 

    while(true){
        
        cout << "Please enter an integer besides 0: (0 - exit): ";
        long long int currNum = 0;
        
        if(!(cin >> currNum) || (currNum == 0) ) break; 
        
        cout << endl;
        
        do
        {
            result = currNum - ((currNum / divisor) * divisor);
            
            currNum /= divisor;
            number.push_front(result);
                
        } while (currNum);

        std::list<int>::const_iterator i = number.begin();
        for(; i!=number.end(); i++)
        {
            cout << *i;
        }

        cout << endl;

        int origNumber = 0;

        //12
        //vector
        //begin 1 || 2^3 = [8]
        //      1 || 2^2 = [4]
        //      0 || 2^1 = 2 [0 dont count]
        //      0 || 2^0 = 1 [0 dont count]
        // end ptr

        i = number.end();
        i--;
        int z=0;
        bool loopEnd = false;
        for(; !loopEnd; i--, z++)
        {
            //cout << *i << endl;
            if(*i==1)
            {
                //cout << pow(2,z) << endl;
                origNumber += pow(2,z);

            }

            if(number.begin() == i)
            {
                loopEnd = true;
            }
        }

        cout << endl << origNumber << endl;


        number.clear();

    }
    return 0;

}
    
//cout << currNum << " / " << divisor;
//cout << " = " << currNum << endl;  

// times 4 then times 2 times 1