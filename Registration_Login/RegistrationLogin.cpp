#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <windows.h>

using namespace std;

class User
{
private:
    string username, password;
public :
    User(string name,string pass){
        username = name;
        password = pass;
    }
   string getUsername(){
        return username; 
   } 
   string getPassword(){
        return password; 
   } 
} ;

class UserManager
{
private:

    vector<User> users ; // create object of vector

public:
    void RegisterUser(){
        string username, password;
        cout << "\t\tEnter User name : ";
        cin  >> username;
        cout << "\t\tEnter Your Password : ";
        cin  >> password;

        User newUser(username, password);
        users.push_back(newUser);
        // ofstream out("C:/Users/foura/OneDrive/Desktop/visual studio apps/Registration Login/register.txt",ios::app);

        
        
        cout << "\t\t User Registration successfully....." <<endl;
  }
    void LoginUser(string name, string pass){
            for (int i = 0; i < users.size(); i++)
            {
                if (users[i].getUsername() == name && users[i].getPassword() == pass){
                    cout << "\t\tLogin Successfully......" << endl;
                    // return true;
                }               
            }
            cout << "\n\n\t\tInvalid Username Or Password..." << endl;
            // return false;
    }
    void showUser(){
        cout << "\t\t--- Users List---"<<endl;
        for (int i = 0; i < users.size(); i++)
        {
            cout << "\t\t" << users[i].getUsername()<< endl;
        }        
    }
    void SearchUser(string username){
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i].getUsername() == username)
            {
                cout << "\t\tUser Found" << endl;
            } 
        } 
        cout << "\t\tNo User Registerd " << endl; 
    }
    void DeleteUser(string username){
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i].getUsername() == username)
            {
                users.erase(users.begin() + 1);
                cout << "\t\tUser Removed Successfully...." << endl;
            }            
        }        
    }
    void Exit(){

    }
};

int main(){

    UserManager usermanage ;

    int op;
    string choice;
    do{
        system("cls");
    cout << "\n\n\t\t1. Register User" << endl;
    cout << "\t\t2. Login "            << endl; 
    cout << "\t\t3. Show User List "   << endl;
    cout << "\t\t4. Search User "      << endl;
    cout << "\t\t5. Delete User "      << endl;
    cout << "\t\t6. Exit "             << endl;
    cout << "\t\t6. Enter Your Choice : ";
    cin  >> op;

    switch (op)
    {
    case 1 :{
        usermanage.RegisterUser();
        break;
    }
    case 2 :{
        string username, password;
        cout << "\t\tEnter User :";
        cin  >> username;
        cout << "\t\tEnter Password :";
        cin  >> password;
        usermanage.LoginUser(username, password);
        break;
    }
    case 3 :{
        usermanage.showUser();
        break;
    }
    case 4 : {
        string username;
        cout << "\t\tEnter User Name : ";
        cin  >> username;
        usermanage.SearchUser(username);
        break; 
    }
    case 5 :{
        string username;
        cout << "\t\tEnter User Name : ";
        cin  >> username;
        usermanage.DeleteUser(username);
        break;
    }
    case 6 :{
        exit(1);
    }
    }
    cout << "\t\tDo You Want To Continue [YES / NO] : ";
    cin >> choice;
    }while (choice == "yes" || choice == "YES");
   
    
    
    return 0 ;
}
