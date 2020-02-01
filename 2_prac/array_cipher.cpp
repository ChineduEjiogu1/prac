#include <iostream> 
#include <string>
using namespace std;

char cipherMessage(char userInput)
{
    const int SIZE = 26;
    char arr[SIZE] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                      'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    };

     for(int i=0; i< SIZE; i++)
     {
         if(userInput == arr[i])
         {
             if(i <= 13)
             {
                 return arr[13 + i];
             }
             else
             {
                 return arr[i - 13];
             }

         }
     }
     return '$';
}

int main()
{

    string userInput;
    
    //get the line as a string
    cout << "Enter message: " << endl;
    getline(cin, userInput);

    cout << endl << "Original message is: " << userInput << endl << "Cipher message is: ";

    for(int i=0; i < userInput.size(); i++)
    {
        cout << cipherMessage(userInput[i]);
    }
    cout << endl;
   
    return 0;

}