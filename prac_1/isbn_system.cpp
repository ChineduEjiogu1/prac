#include <iostream>
using namespace std;

int triple_num(int num){
   int tri_num = num * 3;
   return tri_num;
}

/*
If you like the Luhn formula problem, try writing a program for a different
check-digit system, like the 13-digit ISBN system. The program could take an
identification number and verify it or take a number without its check digit
and generate the check digit.
*/

int main()
{
   int numBy3, numBy1, total, checkDigit, remain, num = 0; 
   int counterDigit = 1;
   int mod10 = 10;

   cout << "Please enter your digits from 0 - 9: " << endl;

   num = cin.get();
   
   while(num != 10){
      
      if(counterDigit > 12){
         cout << "Not a valid ISBN - 13 number " << endl;
         cout << "Please enter a valid ISBN number: " << endl;
         num = cin.get();
      }
      if(counterDigit % 2 == 0){ 
         numBy3 += triple_num((num - '0'));
      }else{ 
         numBy1 += (num - '0'); 
      } 
         num = cin.get();
         counterDigit++;
         total = numBy3 + numBy1;
   }
   
   remain = (total % mod10);
   checkDigit = mod10 - remain;

   if(remain == 0){
      checkDigit = 0;
   }
   
   cout << "The ISBN number calculation is: " << total << endl;
   cout << "The ISBN check digit is: " << checkDigit << endl;
   //cout << remain << endl;
   //cout << numBy1 << endl;
   //cout << numBy3 << endl;
   
   
}