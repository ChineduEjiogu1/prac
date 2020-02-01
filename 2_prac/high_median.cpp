#include <iostream>
using namespace std;

int compareFunc(const void * voidA, const void * voidB) {
  int * intA = (int *)(voidA);
  int * intB = (int *)(voidB);
  return *intA - *intB;
}

int main()
{
    const int NUM_AGENTS = 3;
    const int NUM_MONTHS = 12;

    int sales[NUM_AGENTS][NUM_MONTHS] = {
        {1856, 493, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
        {5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534},
        {23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}
    };

    qsort(sales, NUM_AGENTS*NUM_MONTHS, sizeof(int),compareFunc);

    int median = 0;
    int middle = (NUM_MONTHS / 2);
    int max = sales[0][0];

    int highestSales = sales[0][0];
    int agentPos = 0;

        for(int agent = 0; agent < NUM_AGENTS; agent++){
            for(int month = 0; month < NUM_MONTHS; month++){
                if(sales[agent][month] > highestSales)
                    highestSales = sales[agent][month];
        
                if( (NUM_MONTHS % 2) == 1 )
                median = sales[agent][middle];

                else{
                    if((NUM_MONTHS % 2) == 0){
                        for(int i = 0; i < middle; i++){
                        if(sales[agent][i] > max){
                                max = sales[agent][i];
                                agentPos = agent; 
                            }
                        }
                        median = (max + sales[agent][middle]) / 2;
                    }
                } 
            }       
        }   

        cout << "The Highest Average median: " << median << endl; 
        cout << "The agent with the highest median: " << agentPos << endl;
        
        
        for(int j = 0; j < NUM_AGENTS; j++)
            for(int i = 0; i < NUM_MONTHS; i++){
                cout << sales[j][i] << " ";
            }
    
}