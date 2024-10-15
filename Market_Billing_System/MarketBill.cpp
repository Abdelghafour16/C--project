
#include <iostream>
#include <fstream>
#include <sstream>
#ifdef _WIN32
    #include <windows.h>
    #define CLEAR_SCREEN() system("cls")
#endif
using namespace std;

class Bill{
    private :
        string Item;
        double Rate; 
        int Quantity;

    public :
        Bill() : Item(""), Rate(0), Quantity(0){

        }
        // Bill(){
        //     Item = "";
        //     Rate = 0.0;
        //     Quantity = 0;
        // } the same constructor

    void setItem(string item){
        Item = item;
    } 
    void setRate(double rate){
        Rate = rate;
    }
    void setQuant(int quatity){
        Quantity = quatity;
    }
    string getItem(){
        return Item;
    }
    double getRate(){
        return Rate;
    }
    int getQuant(){
        return Quantity;
    }
};

void addItem(Bill b){
    bool close = true;
    int choice;
    while (close){
        
        cout << "\t1.Add" <<endl;
        cout << "\t2.close" <<endl;
        cout << "\tEnter Choice : ";
        cin  >> choice;

        cout <<endl;

        switch (choice)
        {
        case 1 : {
                 string item;
                 double rate;
                 int quant;

                 cout << "\tEnter Item Name : ";
                 cin  >> item;
                 b.setItem(item);

                 cout << "\tEnter Rate Of Item : ";
                 cin  >> rate;
                 b.setRate(rate);

                 cout << "\tEnter Quantity Of Items : ";
                 cin  >> quant;
                 b.setQuant(quant);

                 ofstream out("C:/Users/foura/OneDrive/Desktop/C++ projects/Market Billing System/Bill.txt",ios::app); //means append mode. It ensures that new data is added at the end of the file instead of overwriting its contents.
                
                // cout << "Hello, World!" << endl;   // writes to the console
                // ofstream out("file.txt");
                // out << "Hello, World!" << endl;    // writes to the file

                 if(!out){
                    cout << "\tError : FileCan't Open!!" <<endl;
                 }
                 else{
                    out << "\t" << b.getItem() << " : " <<b.getRate() << " : " <<b.getQuant() <<endl;
                 }
                 out.close();
                 cout << "\tItem Added Successfully...." <<endl<<endl;
                 Sleep(2000);
            break;
        }
        case 2 :{CLEAR_SCREEN();
                 close = false;
                 cout << "\tBack Tom Main Menu...." <<endl;
                 Sleep(1000);
            break;
        }
            
        }
    }    
}

void PrintBill(){
    CLEAR_SCREEN();
    int count = 0;
    bool close = true;
    while (close){
        CLEAR_SCREEN();
        int choice ;

        cout << "\t1.Add Bill" << endl;
        cout << "\t2.Close Session" << endl;
        cout << "\tEnter Choice : ";
        cin  >> choice;

        cout <<endl;

        switch (choice)
        {
        case 1 :{string item;
                 int quant;

                 cout << "\tEnter Item : ";
                 cin  >> item;

                 cout << "\tEnter Quantity : ";
                 cin  >> quant; 
                 
                 ifstream in("C:/Users/foura/OneDrive/Desktop/C++ projects/Market Billing System/Bill.txt");
                 ofstream out("C:/Users/foura/OneDrive/Desktop/C++ projects/Market Billing System/Bill Temp.txt");
                 // using for file input and output respectively
                 // You can now read data from this file using "in" just like you would use "cin" to read input from the console.
                 

                 string line;
                 bool found = true;
                 while (getline(in, line)){ // reads each line from the Bill.txt file into the line string variable.
                    stringstream ss(line);
                    // ss << line;             //Writes the line to Bill Temp.txt
                    string itemName;
                    double itemRate;
                    int itemQuant;
                    char delimiter; // to absorbe the seperator 
                    ss >> itemName >> delimiter >> itemRate >> delimiter >> itemQuant;

                    //The delimiter character acts as a separator between different pieces of data in each line of your file. For example, if your lines are formatted like this: itemName:itemRate:itemQuant, where : is the delimiter, then delimiter helps to extract itemName, itemRate, and itemQuant correctly.
                    //The line ss >> itemName >> delimiter >> itemRate >> delimiter >> itemQuant; reads itemName, then reads and discards the delimiter character (which is expected to be : in this case), then reads itemRate, reads and discards another delimiter, and finally reads itemQuant.

                    if(item == itemName){
                        found = false;
                        if(quant <= itemQuant){

                            int amount = itemRate * quant;
                            cout << "\tItem | Rate | Quantity | Amount"<< endl;
                            cout << "\t" << itemName << "\t" << itemRate << "\t" << quant << "\t " << amount << endl;  
                            string choice = "no";

                            while (choice == "no")
                            {
                                cout << "\tWrite Yes To Continue : " ;
                                cin  >> choice;
                                
                            }
                            
                                                       
                            int newquant = itemQuant - quant;
                            itemQuant = newquant;
                            count += amount;

                            out << "\t" << itemName << " : " << itemRate << " : " << itemQuant << endl;
                            Sleep(500);
                        }
                        
                        else{
                            cout << "\tSorry There Is No Enough Item" << item << endl;
                            Sleep(3000);
                        }
                    }
                    else{
                        // no item found
                        out << line << endl;
                    }
                    
                 
        
        }
        if (found)
        {
            cout << "\tItem Not Available!!!" <<endl;
        }
        out.close();
        in.close();
        remove("C:/Users/foura/OneDrive/Desktop/visual studio apps/Market Billing System/Bill.txt");
        rename("C:/Users/foura/OneDrive/Desktop/visual studio apps/Market Billing System/Bill Temp.txt", "C:/Users/foura/OneDrive/Desktop/visual studio apps/Market Billing System/Bill.txt");

         break;
       }
        case 2 : {
        close = false;
        cout << "\tCounting Total Bill....." << endl;
        Sleep(2000);
        break;
       }





        } // switch
    }// while
    CLEAR_SCREEN();
    cout << endl<<endl;
    cout << "\tTotal Bill............... : " << count << " DT" << endl << endl;
    cout << "\tThanks For Shopping :)" << endl;
    Sleep(2000);
}   // function

    

int main(){

    Bill b;
    int choice;
    bool exit = true;
    while (exit)
    {
        system("cls");
        
        cout << "\tWelcome to Super Market Billing System" <<endl;
        cout << "\t--------------------------------------" <<endl;
        cout << "\t1.Add Item" <<endl;
        cout << "\t2.Print Bill" <<endl;
        cout << "\t3.Exit" <<endl<<endl;
        cout << "\tEnter Your Choice : " ;
        cin  >> choice;

        cout <<endl;

        switch (choice)
        {
        case 1 :{system("cls");
                 addItem(b);
                 Sleep(2000);

            break;
        }
        case 2 :{
                 PrintBill();
                 Sleep(2000);
                 break;        
        }
        case 3 : {system("cls");
            exit = false ;
            cout << "\t Good Bye!" << endl;
            Sleep(2000);
            break;
        }
        }
        
    }
    
    return 0;
}