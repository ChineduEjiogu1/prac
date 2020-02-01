#include <iostream>
using namespace std;

int main()
{
    
    char outputChar;
    enum modeType {UPPERCASE, LOWERCASE, PUNCTUATION};
    int number;
    modeType mode = UPPERCASE; 
    cout << "Please enter your number (use commas to seperate numbers): ";
    
    char charNum;
    do{
        char charNum = cin.get();
        int num = (charNum - '0');

        charNum = cin.get();
        while((charNum != 10) && (charNum != ',')){
            num = num * 10 + (charNum - '0');
            charNum = cin.get();
        }   
        switch(mode){
            case UPPERCASE:
                num = num % 27;
                outputChar = num + 'A' - 1;
                if(num == 0) {
                    //cout << "Switch to LOWERCASE";
                    mode = LOWERCASE;
                    continue;
                }
                break;
            case LOWERCASE:
                num = num % 27;
                outputChar = num + 'a' - 1;
                if(num == 0){
                    //cout << "Switch to PUNCTUATION";
                    mode = PUNCTUATION;
                    continue;
                }
                break;
            case PUNCTUATION: 
                num = num % 9;
                switch(num){
                    case 1: outputChar = '!'; break;
                    case 2: outputChar = '?'; break;
                    case 3: outputChar = ','; break;
                    case 4: outputChar = '.'; break;
                    case 5: outputChar = ' '; break;
                    case 6: outputChar = ';'; break;
                    case 7: outputChar = '"'; break;
                    case 8: outputChar = '\''; break;
                }
                if(num == 0){
                    //cout << "Switch to UPPERCASE";
                    mode = UPPERCASE;
                    continue;
                }
                break;
        }
        cout << outputChar;
    } while(charNum != 10);
    cout << endl;
}






  