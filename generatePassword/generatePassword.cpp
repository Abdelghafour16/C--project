#include <iostream>
#include <cstdlib>
#include <string.h>
#include <ctime>
using namespace std;

string getpassword(long length){
    string password = "";
    string characteres = "qwertyyuioplkjhgfdsazxcvbnmQWERTYUIOPLKJHGFDSAZXCVBNM1234567890";
    long charsize = characteres.size();
    srand(time(0));
    
    cout << charsize << endl;
    
    long randomIndex;
    for (int i = 0; i < length; i++)
    {
        randomIndex = rand() % charsize;
        password = password + characteres[randomIndex];
    }
    return password;
}

int main(){

    long length ;
    cout << "give me the length of the password :: ";
    cin  >> length; 
    string password = getpassword(length) ;
    cout << "generate password ::" << password;

    return 0;
    
}