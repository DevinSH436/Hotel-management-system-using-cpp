#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<cstring>
#include<iomanip>
#include<windows.h>
#include<bits/stdc++.h>

using namespace std;

int order();

class HOTEL
{
private:
    int room_no;
    char name[30];
    char address[50];
    char phone[15];
    long days;
    long cost;
    char rtype[30];
    long pay;
    void breakfast(int);
    void lunch(int);
    void dinner(int);

public:
    void main_menu();
    void add();
    void display();
    void rooms();
    void edit();
    int check(int);
    void modify();
    void delete_rec();
    void restaurant();
    void modify_name(int);
    void modify_address(int);
    void modify_phone(int);
    void modify_days(int);
} h;

void HOTEL::main_menu()
{
    int choice;
    while(choice!=6)
    {
        system("cls");
        cout<<"\n\t\t\t\t * THE HOTEL *";
        cout<<"\n\t\t\t\t * MAIN MENU *";
        cout<<"\n\n\n\t\t\t\t1. Book A Room";
        cout<<"\n\t\t\t\t2. Customer Information";
        cout<<"\n\t\t\t\t3. Rooms Allotted";
        cout<<"\n\t\t\t\t4. Edit Customer Details";
        cout<<"\n\t\t\t\t5. Order Food from Restaurant";
        cout<<"\n\t\t\t\t6. Exit";
        cout<<"\n\n\t\t\t\tEnter Your Choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            add();
            break;
        case 2:
            display();
            break;
        case 3:
            rooms();
            break;
        case 4:
            edit();
            break;
        case 5:
            restaurant();
            break;
        case 6:
            return;
        default:
        {
            cout<<"\n\n\t\t\tWrong choice.";
            cout<<"\n\t\t\tPress any key to continue.";
            getchar();
        }
        }
    }
}

void HOTEL::add()
{
    system("cls");
    int r,flag;
    ofstream fout("Record.DAT",ios::app|ios::binary);
    cout<<"\n\t\t\t +-----------------------+";
    cout<<"\n\t\t\t | Rooms  |   Room Type  |";
    cout<<"\n\t\t\t +-----------------------+";
    cout<<"\n\t\t\t |   1-50 |    Deluxe    |";
    cout<<"\n\t\t\t |  51-80 |   Executive  |";
    cout<<"\n\t\t\t | 81-100 | Presidential |";
    cout<<"\n\t\t\t +-----------------------+";
    cout<<"\n\n ENTER CUSTOMER DETAILS";
    cout<<"\n ----------------------";
    cout<<"\n\n Room Number: ";
    cin>>r;
    flag=check(r);
    if(flag==1)
        cout<<"\n Sorry, Room is already booked.\n";
    else
    {
        if(flag==2)
            cout<<"\n Sorry, Room does not exist.\n";
        else
        {
            room_no=r;
            cout<<" Name: ";
            cin>>name;
            cout<<" Address: ";
            cin>>address;
            cout<<" Phone Number: ";
            cin>>phone;
            cout<<" Number of Days: ";
            cin>>days;
            if(room_no>=1&&room_no<=50)
            {
                strcpy(rtype,"Deluxe");
                cost=days*10000;
            }
            else
            {
                if(room_no>=51&&room_no<=80)
                {
                    strcpy(rtype,"Executive");
                    cost=days*12500;
                }
                else
                {
                    if(room_no>=81&&room_no<=100)
                    {
                        strcpy(rtype,"Presidential");
                        cost=days*15000;
                    }
                }
            }
            fout.write((char*)this, sizeof(HOTEL));
            cout<<"\n Room has been booked.";
        }
    }
    cout<<"\n Press any key to continue.";
    getchar();
    getchar();
    fout.close();
}


void HOTEL::display()
{
    system("cls");
    ifstream fin("Record.DAT",ios::in|ios::binary);
    int r,flag;
    cout<<"\n Enter Room Number: ";
    cin>>r;
    while(fin.read((char*)this,sizeof(HOTEL)))
    {
        if(room_no==r)
        {
            system("cls");
            cout<<"\n Customer Details";
            cout<<"\n ----------------";
            cout<<"\n\n Room Number: "<<room_no;
            cout<<"\n Name: "<<name;
            cout<<"\n Address: "<<address;
            cout<<"\n Phone Number: "<<phone;
            cout<<"\n Staying for "<<days<<" days.";
            cout<<"\n Room Type: "<<rtype;
            cout<<"\n Total cost of stay: "<<cost;
            flag=1;
            break;
        }
    }
    if(flag==0)
        cout<<"\n Room is Vacant.";
    cout<<"\n\n Press any key to continue.";
    getchar();
    getchar();
    fin.close();

}


void HOTEL::rooms()
{
    system("cls");
    const char separator=' ';
    const int NoWidth=8;
    const int GuestWidth=17;
    const int AddressWidth=16;
    const int RoomWidth=13;
    const int ContactNoWidth=13;
    ifstream fin("Record.DAT",ios::in|ios::binary);
    cout<<"\n\t\t\t    LIST OF ROOMS ALLOTED";
    cout<<"\n\t\t\t   -----------------------";
    cout<<"\n\n +---------+------------------+-----------------+--------------+--------------+";
    cout<<"\n | Room No.|    Guest Name    |      Address    |   Room Type  |  Contact No. |";
    cout<<"\n +---------+------------------+-----------------+--------------+--------------+";
    while(fin.read((char*)this,sizeof(HOTEL)))
    {
        cout<<"\n |"<<setw(NoWidth)<<setfill(separator)<<room_no<<" |";
        cout<<setw(GuestWidth)<<setfill(separator)<<name<<" |";
        cout<<setw(AddressWidth)<<setfill(separator)<<address<<" |";
        cout<<setw(RoomWidth)<<setfill(separator)<<rtype<<" |";
        cout<<setw(ContactNoWidth)<<setfill(separator)<<phone<<" |";
    }
    cout<<"\n +---------+------------------+-----------------+--------------+--------------+";
    cout<<"\n\n\n\t\t\tPress any key to continue.";
    getchar();
    getchar();
    fin.close();
}

void HOTEL::edit()
{
    system("cls");
    int choice,r;
    cout<<"\n EDIT MENU";
    cout<<"\n ---------";
    cout<<"\n\n 1. Modify Customer Information.";
    cout<<"\n 2. Customer Check Out.";
    cout<<"\n Enter your choice: ";
    cin>>choice;
    system("cls");
    switch(choice)
    {
    case 1:
        modify();
        break;
    case 2:
        delete_rec();
        break;
    default:
        cout<<"\n Wrong Choice.";
        break;
    }
    cout<<"\n Press any key to continue.";
    getchar();
    getchar();
}


int HOTEL::check(int r)
{
    int flag=0;
    ifstream fin("Record.DAT",ios::in|ios::binary);
    while(fin.read((char*)this,sizeof(HOTEL)))
    {
        if(room_no==r)
        {
            flag=1;
            break;
        }
        else
        {
            if(r>100)
            {
                flag=2;
                break;
            }
        }
    }
    fin.close();
    return(flag);
}


void HOTEL::modify()
{
    system("cls");
    int ch,r;
    cout<<"\n MODIFY MENU";
    cout<<"\n -----------";
    cout<<"\n\n\n 1. Modify Name";
    cout<<"\n 2. Modify Address";
    cout<<"\n 3. Modify Phone Number";
    cout<<"\n 4. Modify Number of Days of Stay";
    cout<<"\n Enter Your Choice: ";
    cin>>ch;
    system("cls");
    cout<<"\n Enter Room Number: ";
    cin>>r;
    switch(ch)
    {
    case 1:
        modify_name(r);
        break;
    case 2:
        modify_address(r);
        break;
    case 3:
        modify_phone(r);
        break;
    case 4:
        modify_days(r);
        break;
    default:
        cout<<"\n Wrong Choice";
        getchar();
        getchar();
        break;
    }
}

void HOTEL::modify_name(int r)
{
    long pos,flag=0;
    fstream file("Record.DAT",ios::in|ios::out|ios::binary);
    while(!file.eof())
    {
        pos=file.tellg();
        file.read((char*)this,sizeof(HOTEL));
        if(room_no==r)
        {
            cout<<"\n Enter New Name: ";
            cin>>name;
            file.seekg(pos);
            file.write((char*)this,sizeof(HOTEL));
            cout<<"\n Customer Name has been modified.";
            flag=1;
            break;
        }
    }
    if(flag==0)
        cout<<"\n Sorry, Room is vacant.";
    getchar();
    getchar();
    file.close();
}

void HOTEL::modify_address(int r)
{
    long pos,flag=0;
    fstream file("Record.DAT",ios::in|ios::out|ios::binary);
    while(!file.eof())
    {
        pos=file.tellg();
        file.read((char*)this,sizeof(HOTEL));
        if(room_no==r)
        {
            cout<<"\n Enter New Address: ";
            cin>>address;
            file.seekg(pos);
            file.write((char*)this,sizeof(HOTEL));
            cout<<"\n Customer Address has been modified.";
            flag=1;
            break;
        }
    }
    if(flag==0)
        cout<<"\n Sorry, Room is vacant.";
    getchar();
    getchar();
    file.close();
}

void HOTEL::modify_phone(int r)
{
    long pos,flag=0;
    fstream file("Record.DAT",ios::in|ios::out|ios::binary);
    while(!file.eof())
    {
        pos=file.tellg();
        file.read((char*)this,sizeof(HOTEL));
        if(room_no==r)
        {
            cout<<"\n Enter New Phone Number: ";
            cin>>phone;
            file.seekg(pos);
            file.write((char*)this,sizeof(HOTEL));
            cout<<"\n Customer Phone Number has been modified.";
            flag=1;
            break;
        }
    }
    if(flag==0)
        cout<<"\n Sorry, Room is vacant.";
    getchar();
    getchar();
    file.close();
}

void HOTEL::modify_days(int r)
{
    long pos,flag=0;
    fstream file("Record.DAT",ios::in|ios::out|ios::binary);
    while(!file.eof())
    {
        pos=file.tellg();
        file.read((char*)this,sizeof(HOTEL));
        if(room_no==r)
        {
            cout<<" Enter New Number of Days of Stay: ";
            cin>>days;
            if(room_no>=1&&room_no<=50)
            {
                strcpy(rtype,"Deluxe");
                cost=days*10000;
            }
            else
            {
                if(room_no>=51&&room_no<=80)
                {
                    strcpy(rtype,"Executive");
                    cost=days*12500;
                }
                else
                {
                    if(room_no>=81&&room_no<=100)
                    {
                        strcpy(rtype,"Presidential");
                        cost=days*15000;
                    }
                }
            }
            file.seekg(pos);
            file.write((char*)this,sizeof(HOTEL));
            cout<<"\n Customer information is modified.";
            flag=1;
            break;
        }
    }
    if(flag==0)
        cout<<"\n Sorry, Room is Vacant.";
    getchar();
    getchar();
    file.close();
}

void HOTEL::delete_rec()
{
    int r,flag=0;
    char ch;
    cout<<"\n Enter Room Number: ";
    cin>>r;
    ifstream fin("Record.DAT",ios::in|ios::binary);
    ofstream fout("temp.DAT",ios::out|ios::binary);
    while(fin.read((char*)this,sizeof(HOTEL)))
    {
        if(room_no==r)
        {
            cout<<"\n Name: "<<name;
            cout<<"\n Address: "<<address;
            cout<<"\n Phone Number: "<<phone;
            cout<<"\n Room Type: "<<rtype;
            cout<<"\n Your total bill is: Rs. "<<cost;
            cout<<"\n\n Do you want to check out this customer(y/n): ";
            cin>>ch;
            if(ch=='n')
                fout.write((char*)this,sizeof(HOTEL));
            else
                cout<<"\n Customer Checked Out.";
            flag=1;
        }
        else
            fout.write((char*)this,sizeof(HOTEL));
    }
    fin.close();
    fout.close();
    if(flag==0)
        cout<<"\n Sorry, Room is Vacant.";
    else
    {
        remove("Record.dat");
        rename("temp.dat","Record.dat");
    }
    getchar();
    getchar();
}


void HOTEL::restaurant()
{
    system("cls");
    int r,ch,num;
    cout<<"\n RESTAURANT MENU:";
    cout<<"\n --------------- ";
    cout<<"\n\n 1. Order Breakfast\n 2. Order Lunch\n 3. Order Dinner";
    cout<<"\n\n Enter your choice: ";
    cin>>ch;
    system("cls");
    cout<<" Enter Room Number: ";
    cin>>r;
    switch(ch)
    {
    case 1:
        breakfast(r);
        break;

    case 2:
        lunch(r);
        break;

    case 3:
        dinner(r);
        break;
    }
    cout<<"\n\n Press any key to continue.";
    getchar();
    getchar();
    return;
}

void HOTEL::breakfast(int r)
{
    int num,flag=0;
    long pos;
    fstream file("Record.DAT",ios::in|ios::out|ios::binary);
    while(!file.eof())
    {
        pos=file.tellg();
        file.read((char*)this,sizeof(HOTEL));
        if(room_no==r)
        {
            pay=order();
            cost=cost+pay;
            file.seekg(pos);
            file.write((char*)this,sizeof(HOTEL));
            cout<<"\n Amount added to the bill: Rs. "<<pay;
            flag=1;
            break;
        }
    }
    if(flag==0)
        cout<<"\n Sorry, Room is Vacant.";
    getchar();
    getchar();
    file.close();
}


void HOTEL::lunch(int r)
{
    int num,flag=0;
    long pos;
    fstream file("Record.DAT",ios::in|ios::out|ios::binary);
    while(!file.eof())
    {
        pos=file.tellg();
        file.read((char*)this,sizeof(HOTEL));
        if(room_no==r)
        {
            pay=order();
            cost=cost+pay;
            file.seekg(pos);
            file.write((char*)this,sizeof(HOTEL));
            cout<<"\n Amount added to the bill: Rs. "<<pay;
            flag=1;
            break;
        }
    }
    if(flag==0)
        cout<<"\n Sorry, Room is vacant.";
    getchar();
    getchar();
    file.close();
}


void HOTEL::dinner(int r)
{
    int num,flag=0;
    long pos;
    fstream file("Record.DAT",ios::in|ios::out|ios::binary);
    while(!file.eof())
    {
        pos=file.tellg();
        file.read((char*)this,sizeof(HOTEL));
        if(room_no==r)
        {
            pay=order();
            cost=cost+pay;
            file.seekg(pos);
            file.write((char*)this,sizeof(HOTEL));
            cout<<"\n Amount added to the bill: Rs. "<<pay;
            flag=1;
            break;
        }
    }
    if(flag==0)
        cout<<"\n Sorry, Room is Vacant.";
    getchar();
    getchar();
    file.close();
}


int main()
{
    cout<<"\t\t\t  Press any key to continue...      ";
    getch();
    system("cls");
    h.main_menu();
    return 0;
}

class one
{


public:
    void menu1();

};
void one::menu1()

// Menu
{

    cout<<"\n\n\n\t\t\t\t\t\t ========== WELCOME TO FOOD ORDERING SYSTEM =========="<<endl;
    cout<<"\n\n\t\t\t\t\t\t\t       =====START YOUR ORDER====="<<endl;
    cout<<"\n\n\n\t================================================================================================================================"<<endl;
    cout<<"\n\n\n\t\t\t\t\t\t[1] Veggie Supreme (Rs.480)\t\t\t"<<endl;
    cout<<"\t\t\t\t\t\t[2] Exotica Pizza(Rs.440)\t\t\t\t"<<endl;
    cout<<"\t\t\t\t\t\t[3] Chicken Sizzler (Rs.580)\t"<<endl;
    cout<<"\t\t\t\t\t\t[4] Chrispy Chicken (Rs.520)\t\t\t"<<endl;
    cout<<"\t\t\t\t\t\t[5] Spaghetti (Rs.350)\t\t\t\t\t"<<endl;
    cout<<"\t\t\t\t\t\t[6] Country Feast (Rs.400)\t"<<endl;
    cout<<"\t\t\t\t\t\t[7] Tetrazzini (Rs.420)\t\t\t\t"<<endl;
    cout<<"\t\t\t\t\t\t[8] Double Cheese (Rs.540)\t\t\t\t"<<endl;
    cout<<"\t\t\t\t\t\t[9] Makizushi (Rs.548)\t"<<endl;
    cout<<"\t\t\t\t\t\t[10] Ham Burger (Rs.390)\t\t\t"<<endl;
    cout<<"\t\t\t\t\t\t[11] Margherita Pizza(Rs.525)\t\t\t\t"<<endl;
    cout<<"\t\t\t\t\t\t[12] Fish 'n' Chips (Rs.425)\t"<<endl;
    cout<<"\t\t\t\t\t\t[13] Fajitas (Rs.335)\t\t\t\t"<<endl;
    cout<<"\t\t\t\t\t\t[14] Tempura (Rs.324)\t\t\t\t\t"<<endl;
    cout<<"\t\t\t\t\t\t[15] Hot Dog (Rs.360)\t"<<endl;
    cout<<"\t\t\t\t\t\t[16] EXIT"<<endl;
    cout<<"\n\t======================================================================================================================================="<<endl;
}
class two:public one
{
protected:
    int  pizza=0;
    int ch=0;
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    int e=0;
    int f=0;
    int g=0;
    int h=0;
    int i=0;
    int j=0;
    int k=0;
    int l=0;
    int m=0;
    int n=0;
    int o=0;
    int p=0;
    int q=0;
    int r=0;
    int s=0;
    string y;
    string ye;
public:
    int menu2()

//writing in file

    {
        ofstream write;
        write.open("order.text");
        if(!write)
        {
            cout<<"file can not open"<<endl;
            exit (-1);
        }

a:
b:
c:
        cout<<"\n\n\tENTER YOUR ORDER (one order at a time): ";
        cin>>ch;


        cout<<"\n\n\tDO YOU WANT TO UPDATE YOUR ORDER (y/n) :";

        cin>>ye;

        if(ye=="y"|| ye=="Y")
        {
            goto b;
        }
        else
        {
            switch(ch)
            {

            // taking input for pizza

            case 1:
                cout<<"\n\n\tHOW MANY PIZZA YOU WANT :";
                cin>>pizza;

                a=480;
                s=s+a*pizza;
                write<<"YOU ORDER  Veggie Supreme : 480";
                write<<" \n";
                write<<"NUMBER OF PIZZA IS : "<<pizza;
                write<<"\n";
                cout<<"\n\n\n\tYOU ORDER  Veggie Supreme "<<endl;
                cout<<"\tYOUR ORDER SUCCESSFULLY SAVED "<<endl;
               
                break;

            //taking input for exotica

            case 2:
                cout<<"\n\n\tHOW MANY Exotica YOU WANT :";
                cin>>pizza;

                b=440;
                s=s+b*pizza;
                write<<"YOU ORDER  Exotica : 440";
                write<<" \n";
                write<<"NUMBER OF Exotica IS : "<<pizza;
                write<<"\n";
                cout<<"\n\n\n\tYOU ORDER  Exotica "<<endl;
                cout<<"\tYOUR ORDER SUCCESSFULLY SAVED "<<endl;
                
                break;

            //taking input for sizzler

            case 3:
                cout<<"\n\n\tHOW MANY CHICKEN SIZZLER YOU WANT :";
                cin>>pizza;

                c=580;
                s=s+c*pizza;
                write<<"YOU ORDER  Chicken Sizzler : 580";
                write<<" \n";
                write<<"NUMBER OF Chicken Sizzler IS : "<<pizza;
                write<<"\n";
                cout<<"\n\n\n\tYOU ORDER  Chicken Sizzler "<<endl;
                cout<<"\tYOUR ORDER SUCCESSFULLY SAVED "<<endl;
               
                break;

            //taking input for chicken

            case 4:
                cout<<"\n\n\tHOW MANY CHRISPY CHICKEN YOU WANT :";
                cin>>pizza;

                d=520;
                s=s+d*pizza;
                write<<"YOU ORDER  Chrispy Chicken : 520";
                write<<" \n";
                write<<"NUMBER OF Chrispy Chicken IS : "<<pizza;
                write<<"\n";
                cout<<"\n\n\n\tYOU ORDER  Chrispy Chicken "<<endl;
                cout<<"\tYOUR ORDER SUCCESSFULLY SAVED "<<endl;
                
                break;

            // taking input for spaghetti pizza

            case 5:
                cout<<"\n\n\tHOW MANY SPAGHETTI YOU WANT:";
                cin>>pizza;

                e=350;
                s=s+e*pizza;
                write<<"YOU ORDER  Spaghetti : 350";
                write<<" \n";
                write<<"NUMBER OF Spaghetti IS : "<<pizza;
                write<<"\n";
                cout<<"\n\n\n\tYOU ORDER  Spaghetti "<<endl;
                cout<<"\tYOUR ORDER SUCCESSFULLY SAVED "<<endl;
                
                break;

            //taking input for country feast

            case 6:
                cout<<"\n\n\tHOW MANY Country Feast YOU WANT:";
                cin>>pizza;

                f=400;
                s=s+f*pizza;
                write<<"YOU ORDER Country Feast : 400";
                write<<"\n ";
                write<<"NUMBER OF Country feast IS : "<<pizza;
                write<<"\n";
                cout<<"\n\n\n\tYOU ORDER Country Feast "<<endl;
                cout<<"\tYOUR ORDER SUCCESSFULLY SAVED "<<endl;
                
                break;

            //taking input for tetrazzini

            case 7:
                cout<<"\n\n\tHOW MANY TETRAZZINI YOU WANT:";
                cin>>pizza;

                g=420;
                s=s+g*pizza;
                write<<"YOU ORDER Tetrazzini : 420";
                write<<"\n ";
                write<<"NUMBER OF Tetrazzini IS : "<<pizza;
                write<<"\n";
                cout<<"\n\n\n\tYOU ORDER  Tetrazzini "<<endl;
                cout<<"\tYOUR ORDER SUCCESSFULLY SAVED "<<endl;
                
                break;

            //taking order for double cheese pizza

            case 8:
                cout<<"\n\n\tHOW MANY PIZZA YOU WANT :";
                cin>>pizza;

                h=540;
                s=s+h*pizza;
                write<<"YOU ORDER Double Cheese : 540";
                write<<" \n";
                write<<"NUMBER OF PIZZA IS : "<<pizza;
                write<<"\n";
                cout<<"\n\n\n\tYOU ORDER   Double Cheese "<<endl;
                cout<<"\tYOUR ORDER SUCCESSFULLY SAVED "<<endl;
                
                break;

            //taking input for makizushi

            case 9:
                cout<<"\n\n\tHOW MANY MAKIZUSHI YOU WANT :";
                cin>>pizza;

                i=548;
                s=s+i*pizza;
                write<<"YOU ORDER Makizushi : 548";
                write<<" \n";
                write<<"NUMBER OF Makizushi IS : "<<pizza;
                write<<"\n";
                cout<<"\n\n\n\tYOU ORDER Makizushi "<<endl;
                cout<<"\tYOUR ORDER SUCCESSFULLY SAVED "<<endl;
                
                break;

            //taking input for ham burger

            case 10:
                cout<<"\n\n\tHOW MANY HAM BURGER YOU WANT :";
                cin>>pizza;

                j=390;
                s=s+j*pizza;
                write<<"YOU ORDER Ham Burger : 390";
                write<<" \n";
                write<<"NUMBER OF Ham Burger IS : "<<pizza;
                write<<"\n";
                cout<<"\n\n\n\tYOU ORDER Ham Burger "<<endl;
                cout<<"\tYOUR ORDER SUCCESSFULLY SAVED "<<endl;
                
                break;

            //taking input for Margherita

            case 11:
                cout<<"\n\n\tHOW MANY PIZZA YOU WANT :";
                cin>>pizza;

                k=525;
                s=s+k*pizza;
                write<<"YOU ORDER Margherita : 525";
                write<<" \n";
                write<<"NUMBER OF PIZZA IS : "<<pizza;
                write<<"\n";
                cout<<"\n\n\n\tYOU ORDER   Margherita "<<endl;
                cout<<"\tYOUR ORDER SUCCESSFULLY SAVED "<<endl;
                
                break;

            //taking order for fish

            case 12:
                cout<<"\n\n\tHOW MANY FISH 'n' CHIPS YOU WANT :";
                cin>>pizza;

                l=425;
                s=s+l*pizza;
                write<<"YOU ORDER Fish 'n' Chips : 425";
                write<<" \n";
                write<<"NUMBER OF Fish 'n' Chips IS : "<<pizza;
                write<<"\n";
                cout<<"\n\n\n\tYOU ORDER  Fish 'n' Chips "<<endl;
                cout<<"\tYOUR ORDER SUCCESSFULLY SAVED "<<endl;
                
                break;

            //taking order for fajitas

            case 13:
                cout<<"\n\n\tHOW MANY FAJITAS YOU WANT :";
                cin>>pizza;

                m=335;
                s=s+m*pizza;
                write<<"YOU ORDER  Fajitas  : 335";
                write<<" \n";
                write<<"NUMBER OF Fajitas IS : "<<pizza;
                write<<"\n";
                cout<<"\n\n\n\tYOU ORDER Fajitas "<<endl;
                cout<<"\tYOUR ORDER SUCCESSFULLY SAVED "<<endl;
                
                break;

            //taking order for tempura

            case 14:
                cout<<"\n\n\tHOW MANY TEMPURA YOU WANT :";
                cin>>pizza;

                n=324;
                s=s+n*pizza;
                write<<"YOU ORDER Tempura : 324";
                write<<" \n";
                write<<"NUMBER OF Tempura IS : "<<pizza;
                write<<"\n";
                cout<<"\n\n\n\tYOU ORDER  Tempura "<<endl;
                cout<<"\tYOUR ORDER SUCCESSFULLY SAVED "<<endl;
                
                break;

            //taking order for hot dog

            case 15:
                cout<<"\n\n\tHOW MANY HOT DOG YOU WANT :";
                cin>>pizza;

                o=360;
                s=s+o*pizza;

                //fn1353

                write<<"YOU ORDER  Hot Dog : 360";
                write<<"\n ";
                write<<"NUMBER OF Hot Dog IS : "<<pizza;
                write<<"\n";
                cout<<"\n\n\n\tYOU ORDER  Hot Dog "<<endl;
                cout<<"\tYOUR ORDER SUCCESSFULLY SAVED "<<endl;
               
                break;

            case 16:
                cout<<"\n\t\t\t\t\t Thank you"<<endl;
                exit(0);
                break;

            default:
                cout<<"\n\n\t\t\t\t\t\t\tYOU ENTERED WRONG ORDER KEY !!!!! "<<endl;
                cout<<"\n\n\t\t\t\t\t\t\t Please Re-enter!!!!"<<endl;
                goto c;
                break;
            }
            cout<<"\n\tDO YOU WANT ANOTHER ORDER (yes/no) :";
            cin>>y;
            if(y=="yes"|| y=="YES")
            {
                goto a;
            }
            else
            {
                cout<<"\n\t\t\t\t\t\t\tTHANK YOU FOR YOUR ORDER :D"<<endl;
                cout<<"\n\t\t\t\t\t\t\t Have a Great Day!!!"<<endl;
                cout<<"GENERATING BILL "<<endl;
                for(int a=1; a<8; a++)

                    // Change 'a<?' to how many * you want

                {
                    Sleep(500);
                    cout << "...";
                }
                cout<<"\n\t\t\t\t\t\t\t";
                system("PAUSE");
            }
        }
        system("cls");
        cout << "\n\t\t\t\t\t\t\t ================================================"<<endl;
        cout << "\t\t\t\t\t\t\t|               Food Ordering System             |"<<endl;
        cout << "\t\t\t\t\t\t\t ================================================"<<endl;
        cout << endl;
        cout << endl;

        cout << endl;
        cout << endl;
        cout<<"\t\t\t\t\t\t\t\t    YOUR TOTAL BILL IS Rs."<<s<<endl;
        write<<"\t\t\t\t\t\t\t ";
        write<<"\t\t\t\t\t\t\tTOTAL BILL IS : "<<s;
        cout << "\n\t\t\t\t\t\t\t ================================================"<<endl;


        write.close();
        return s;
    }
    int show1()
    {
        menu1();
        int s = menu2();
        return s;
    }

};
class three:public one,public two
{
public:
    int total()
    {
        int s;



d:
        long userId;

        cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t---------------------";
        cout<<"\n\t\t\t\t\t\t\tEnter Login Id for security reasons = ";
        cin>>userId;
        cout<<"\t\t\t\t\t\t\t---------------------";



        if(userId!=12345)
        {
            cout<<"\n Please Enter correct id\n";
            goto d;
        }
        else
            cout<<"\n\n\n\t\t\t\t\t\t\tAccess Granted!!!!!!\n";
z:
        string pwd="password";



        string pass="";

        char c;


        cout<<"\n\n\n\t\t\t\t\t\t\tPassword = ";
p:
        c=getch();
        cout<<"*";



        if(c!=13)
        {
            pass=pass+c;



            goto p;
        }

        {

            if(pass==pwd)
            {
                cout<<"\n\n\t\t\t\t\t\t\tWelcome to our Restaurant\n\n\n";
                system("PAUSE");
                system("CLS");
                s = show1();
                return s;
            }

            else
            {
                cout<<"\n\n\n\t\t\t\t\t\t\tWrong Password\n";
                
                cout<<"\n\n\n\t\t\t\t\t\t\t Enter Again\n";
                goto z;
            }
        }
    }
};
int order()
{

    three ob;

    int s = ob.total();
    cout<<endl;
    return s;
}
