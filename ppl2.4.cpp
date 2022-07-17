#include <bits/stdc++.h>
using namespace std;

typedef struct transaction{
    string name;
    string author;
    float price,total;
    int nos;
    bool sucess;
};

class books{
    string name,author,publisher;
    float price;
    int stock;
public:
    books();
    void show();
    void update_price();
    bool update_stock(int a);
    void add_record(int req, bool success);
    pair<string, string> connect(){
        return {name, author};
    }
};
map<pair<string,string>,books *> database;
vector<transaction> records;

books::books(){
    price = -1;
    cout<<"Enter the name of the book: ";
    while(!name.size()) getline(cin,name);
    cout<<"Enter the author's name: ";
    while(!author.size()) getline(cin,author);
    cout<<"Enter the publisher's name: ";
    while(!publisher.size()) getline(cin,publisher);
    cout<<"Enter the price: ";
    while(price == -1) cin>>price;
    cout<<"Enter stock: ";cin>>stock;
}

void books::show(){
    cout<<"***************BOOK DETAILS********************"<<endl;
    cout<<"book name: "<<name<<endl;
    cout<<"author name: "<<author<<endl;
    cout<<"publisher name: "<<publisher<<endl;
    cout<<"price: "<<price<<endl;
    cout<<"stock: "<<stock<<endl;
    cout<<"*****************END******************"<<endl;
}

void books::update_price(){
    cout<<"Enter the new price of book: ";
    cin>>price;
    cout<<"price updated!!"<<endl;
}
bool books::update_stock(int req){
    if(req>stock){
        cout<<"Don't have the required stock"<<endl;
        return false;
    }
    stock -= req;
    return true;
}

void books::add_record(int req, bool sucess = false){
    transaction transactions;
    transactions.name = name;
    transactions.author = author;
    transactions.price = price;
    transactions.nos = req;
    transactions.total = req*price;
    cout<<"bill amount: "<<transactions.total<<endl;
    if(sucess){
        cout<<"paid?(0/1) ";
        cin>>transactions.sucess;
    }
    if(!transactions.sucess)
        stock += req;
    records.push_back(transactions);
};

void record_display(){
    cout<<"********** Transcation detail**********";
    for(int i=0;i<records.size();i++){
        cout<<"***********************************"<<endl;
        transaction ts=records[i];
        cout<<"book name:"<<ts.name<<endl;
        cout<<"author name: "<<ts.author<<endl;
        cout<<"no of books ordered: "<<ts.nos<<endl;
        cout<<"price per piece: "<<ts.price<<endl;
        cout<<"total bill: "<<ts.total<<endl;
        if(ts.sucess)cout<<"sucessfull"<<endl;
        else cout<<"transaction failed"<<endl;
        cout<<"***********************************"<<endl;
    }
    cout<<"****************END*******************"<<endl;
}

books *search(){
    string r_name, r_author;
    cout<<"Enter book name: ";
    while(!r_name.size())getline(cin, r_name);
    cout<<"Enter author name: ";
    while(!r_author.size())getline(cin, r_author);
    pair<string, string> key = make_pair(r_name, r_author);
    map<pair<string,string>, books*>::iterator mp = database.find(key);
    if(mp == database.end())
        return NULL;
    return mp->second;
}
void transaction(){
    books *ptr = search();
    if(!ptr){
        cout<<"Book not in database"<<endl;
        return;
    }
    ptr->show();
    int req;
    cout<<"Enter the required book nos: ";
    cin>>req;
    if(ptr->update_stock(req)== false)
        ptr->add_record(0, false);
    else
        ptr->add_record(req,true);
    cout<<"transaction sucessfull"<<endl;
}

int main()
{
    int ch;
    books *ptr;
    cout<<"1. Transaction"<<endl;
    cout<<"2. Add book to database"<<endl;
    cout<<"3. Update price"<<endl;
    cout<<"4. Record_display"<<endl;
    cout<<"0. Exit"<<endl;
    do{
        cout<<"ENTER CHOICE: ";
        cin>>ch;
        switch(ch){
            case 1:
                transaction();
                break;
            case 2:
                ptr = new books;
                database[ptr->connect()] = ptr;
                break;
            case 3:
                ptr = search();
                if(!ptr)
                    cout<<"book not found"<<endl;
                else
                    ptr->update_price();
                break;
            case 4:
                record_display();
            case 0:
                break;
            default:
                cout<<"wrong choice"<<endl;
        }
    }while(ch);
    return 0;
}

