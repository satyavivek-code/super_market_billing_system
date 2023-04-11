/*
SuperMarket Billing System
*/

#include<iostream>
#include<fstream>

using namespace std;

class shopping
{
    private:
        int pcode;
        float price;
        float discount;
        string product_name;

        public:
            void menu();
            void administrator();
            void buyer();
            void add();
            void edit();
            void rem();
            void list();
            void receipt();
};

void shopping::menu()
{
    m:
    int choice;
    string email;
    string password;

    cout << "\t\t\t\t________________________________________________________________" << endl;
    cout << "\t\t\t\t                                                                " << endl;
    cout << "\t\t\t\t                     Supermarket Main Menu                      " << endl;
    cout << "\t\t\t\t________________________________________________________________" << endl;
    cout << "\t\t\t\t                                                                " << endl;
    cout << "\t\t\t\t|                      1) Administrator                        |"<< endl;
    cout << "\t\t\t\t|                                                              |"<< endl;
    cout << "\t\t\t\t|                      2) Buyer                                |"<< endl;
    cout << "\t\t\t\t|                                                              |"<< endl;
    cout << "\t\t\t\t|                      3) Exit                                 |"<< endl;


    cout <<"\n\t\t\t Please Select !";
    cin >> choice;

    switch(choice)
    {
        case 1 : 
            cout << "\t\t\tPlease Login" << endl;
            cout << "\t\t\tEnter Email Id." << endl;
            cin >> email;
            cout << "\t\t\tEnter Password " << endl;
            cin >> password;
            
            if (email == "abc@email.com" && password == "abc" )
            {
                administrator();
            }
            else{
                cout << "Invalid Username and password" << endl;
            }
            break;
        
        case 2 :
        {
            buyer();
        }
        case 3 :
        {
            exit(0);
        }
        default :
        {
            cout <<" Please Select from Given options ! " << endl;
        }
            
    }
    goto m; 
}

void shopping :: administrator()
{
    m:
    int choice;
    cout <<"\n\n\n\t\t\t Administrator menu "<< endl;
    cout <<"\n\t\t\t|_____1) Add product_____|";
    cout <<"\n\t\t\t|                        |";
    cout <<"\n\t\t\t|_____2) Modify product__|";
    cout <<"\n\t\t\t|                        |";
    cout <<"\n\t\t\t|_____3) Delete product__|";
    cout <<"\n\t\t\t|                        |";
    cout <<"\n\t\t\t|_____4) Back to Menu____|";

    cout << "\n\n\t Please Enetr the choice ";
    cin >> choice;
    
    switch (choice) 
    {
        case 1 :
            add();
            break;
        
        case 2:
            edit();
            break;
        
        case 3:
            rem();
            break;
        
        case 4:
            menu();
            break;

        default :
            cout<< " Invalid choice" ;
    }
    goto m;
}

void shopping:: buyer()
{
    m:
    int choice;
    cout <<"\t\t\t      Buyer       \n";
    cout <<"\t\t\t__________________\n";
    cout <<"                        \n";
    cout <<"\t\t\t 1) Buy Product   \n";
    cout <<"                        \n";
    cout <<"\t\t\t 2) Go Back       \n";

    cout <<"\t\t\t Enter the choice:\n";
    cin >> choice;

    switch (choice)
    {
        case 1:
            receipt();
            break;
        
        case 2:
            menu();
            break;
        
        default:
            cout <<"Invalid Choice" << endl;
    }
    goto m;
}

void shopping::add()
{
    m:
    fstream data;  // object Data is name of object
    int c;          // code of product
    int token = 0;  
    float p;        // price of product
    float d;        // discount on product
    string n;       // name of product

    cout <<"\n\n\t\t\t Add New Product" ;
    cout <<"\n\n\t     Product Code   " ;
    cin >> pcode ;
    cout <<"\n\n\t  Name of the product";
    cin >> product_name;
    cout <<"\n\n\t   Price of product  ";
    cin >> price;
    cout <<"\n\n\t Discount on product ";
    cin >> discount ;
    cout <<"\n\n\t Record inserted ";

    /*
    (ios::in) open file in reading mode
    (ios::out) open file in writing mode
    (ios::app) append in file
    */
    data.open("database.txt",ios::in);

    if (!data)
    {
        data.open("database.txt",ios::app|ios::out);
        data << " "<< pcode << " " << product_name << " "<<price << " " << discount << "\n";
        data.close(); 
    }
    else{
        data >> c >> n >> p >> d; // initialize index of file

        while(!data.eof()) // eof() end of file function 
        {
            if (c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();

        if (token == 1)
            goto m;
        else
        {
            data.open("database.txt",ios::app|ios::out);
            data << " "<< pcode << " " << product_name << " "<<price << " " << discount << "\n";
            data.close();
        }
        cout<< "\n\n\t\t  Record Inserted !";
    }
}

void shopping::edit()
{
    m:
    fstream data;
    fstream data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout<< "\n\t\t\t Modify the record ";
    cout<<"\n\t\t\t Product code       ";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data)
    {
        cout<<"\n\n File Dosen't exist" ;
    }
    else
    {
        data1.open("database1.txt", ios::app|ios::out);
        
        data>>pcode>>product_name>>price>>discount;
        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout <<"\n\t\t Product new code : ";
                cin >> c;
                cout << "\n\t\t Product Name :    ";
                cin >> n;
                cout << "\n\t\t Price        :    ";
                cin >> p;
                cout << "\n\t\t Discount     :    ";
                cin >> d;

                data1 << " " << c << " " << n<< " " << p<< " " << d<< " " <<endl;
                cout << "\n\n\t\t Record Edited ";
                token++;     

            }
            else{
                data1 << " " << pcode << " " <<product_name << " " << price<< " " << discount<< " " << endl;

            }
            data >> pcode >> product_name >>price >>discount >> discount;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if (token == 0)
        {
            cout << "\n\n Record Not Found Sorry !";
        }
    }
    goto m;

    
}
void shopping::rem()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\n\n\t Delete product";
    cout << "\n\n\t Product code  ";
    cin >> pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout << "File Doesn't Exist" << endl;
    }
    else
    {
        data.open("database1.txt",ios::app|ios::out);    
        data >> pcode >> product_name >> price >> discount;

        while (!data.eof())
        {
            if (pcode == pkey)
            {
                cout << "\n\n\t Product deleted successfully" ;
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<product_name<<" "<< price<<" "<< discount<<endl;
            }
            data >> pcode >> product_name >> price >> discount;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if (token == 0)
        {
            cout << "\n\n Record not found ";

        }


    }

}

void shopping::list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout<<"\n\n_____________________________________";
    cout <<"ProNo\t\tName\t\tPrice \n";
    data>>pcode >>product_name >> price >> discount;
    while(!data.eof())
    {
        cout << pcode << "\t\t" << product_name <<"\t\t" << price <<endl;
        data>>pcode >>product_name >> price >> discount;
    }
    data.close();
}
void shopping::receipt()
{

    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float discount = 0;
    float total = 0;
    

    cout << "\n\n\n\t\t\t RECEIPT ";

    data.open("database.txt",ios::in);
    if (!data){
        cout << "\n\n\n Empty database ";
    }
    else{
        data.close();
        list();
        cout <<" \n _______________________________________\n";
        cout <<" \n|                                      |\n";
        cout <<" \n    Please place the order you want     \n";
        cout <<" \n|                                      |\n";
        cout <<" \n _______________________________________\n";
        
        do
        {
            m:
            cout <<"\n\n Enter product code : ";
            cin >> arrc[c];
            cout <<"\n\n Enter product quantity : ";
            cin >> arrq[c];

            for (int i = 0; i < c; i++)
            {
                if(arrc[c] == arrc[i])
                {
                    cout <<"\n\n Duplicate product code, \n Please try again \n";
                    goto m;
                }
            }
            c++;
            cout << "\n\n Do you want to buy another product? \n if yes press y else press n ";
            cin >> choice;
            
        }
        while(choice =='y');

        cout <<"\n\n\t\t_______________RECEIPT_______________";
        cout <<"\n Product No \t Product Name \t Product Quantity \t Price \t Amount \t Amount with discount ";

        for(int i = 0; i<c; i++)
        {
            data.open("database.txt",ios::in);
            data>>pcode>>product_name>>price>>discount;

            while(!data.eof()){
                if (pcode == arrc[i]){
                    amount = price * arrq[i];
                    discount = amount - (amount * discount / 100);
                    total = total + discount;
                    cout << "\n" << pcode <<"\t\t"<< product_name <<"\t\t"<< arrq[i] <<"\t\t"<< price <<"\t\t"<< amount <<"\t\t"<< discount;
                }

                data>>pcode>>product_name>>price>>discount;
            }
        }
        data.close();   
    }
    cout << "\n\n ______________________________________\n";
    cout << "\n Total Amount : " << amount <<endl;
}
int main()
{
    shopping s;
    s.menu();

}