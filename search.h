#include <bits/stdc++.h>
#include "structs.h"
#include "colors.h"
#pragma once

using namespace std;

// ------------------------------------------------------------------- RESEVATION SEARCHES -------------------------------------------

int searchReservationByID(string ID) // returns the index of the reservation 
{
    for(int i=0;i<reservations.size();i++)
    {
        if(reservations[i].id == ID)return i;
    }
    return -1;
}

int searchReservationByRoomNumber(string number) // returns the index of the reservation
{
    for(int i=0;i<reservations.size();i++)
    {
        if(reservations[i].room_no == number)return i;
    }
    return -1;
}

int searchReservationByName(string name) // returns the index of the reservation
{
    for(int i=0;i<reservations.size();i++)
    {
        if(reservations[i].name == name)return i;
    }
    return -1;
}

//------------------------------------------------------------- ROOM SEARCHES ---------------------------------------------------------------------

int searchRoomByCategory(string cat)
{
    if(cat == "S")cat = "SeaView";
    if(cat == "L")cat = "LakeView";
    if(cat == "G")cat = "GardenView";
    for(int i=0;i<rooms.size();i++)
    {
        if(rooms[i].type == cat && rooms[i].status == "Available" && searchReservationByRoomNumber(rooms[i].room_no)==-1)return i;
    }
    return -1;
}

int searchRoomByNumber(string num)
{
    for(int i=0;i<rooms.size();i++)
    {
        if(rooms[i].room_no == num)return i;
    }
    return -1;
}

void showAvailableRoomsByCategory(string cat){
    cout<<"room_number\tprice\n";
    for(room r:rooms) if(r.type==cat && r.status!="Reserved" && searchReservationByRoomNumber(r.room_no)==-1) cout<<r.room_no<<'\t'<<r.price<<endl; 
}

//------------------------------------------------------------- Show Details ---------------------------------------------------------------------

void viewCustomerDetails()
{
    cout<<endl<<" Viewing customer details "<<endl;
    int option;
    bool flag = false;
    while(!flag){
        cout<<"Search by: "<<endl;
        cout<<"[0] "<<setColor(red, black)<<"Back"<<resetColor()<<endl;
        cout<<"[1] "<<"Reservation ID"<<endl;
        cout<<"[2] "<<"Room number"<<endl;
        cin>>option;
        if(option != 0 && option != 1 && option != 2)
            cout<<setColor(white, yellow)<<" Invalid option. "<<resetColor()<<endl;
        else
            flag=true;
    }
    if(option == 0)return;
    if(option == 1){
        int idx;
        cout<<"Enter ID: ";
        string id;
        cin>>id;
        idx = searchReservationByID(id);
        int attempts = 3;
        while(idx == -1 && --attempts){
            cout<<setColor(white, yellow)<<" Please enter a valid ID: "<<resetColor()<<endl;
            cin>>id;
            idx = searchReservationByID(id);
        }
        if(!attempts){
            cout<<setColor(white, red)<<" Too many invalid attempts, going back to menu "<<resetColor()<<endl;
            return;
        }
        cout<<left;
        cout<<setw(30)<<"Name"<<setw(30)<<"National ID"<<setw(30)<<"E-Mail"<<setw(30)<<"Phone"<<endl;
        cout<<setw(30)<<reservations[idx].name<<setw(30)<<reservations[idx].nat_id<<setw(30)<<reservations[idx].email<<setw(30)<<reservations[idx].phone<<endl;

    } else{
        int idx;
        cout<<"Enter Room No: ";
        string room_no;
        cin>>room_no;
        idx = searchReservationByRoomNumber(room_no);
        int attempts = 3;
        while(idx == -1 && --attempts){
            cout<<setColor(white, yellow)<<" Please enter a valid room number: "<<resetColor()<<endl;
            cin>>room_no;
            idx = searchReservationByRoomNumber(room_no);
        }
        if(!attempts){
            cout<<setColor(white, red)<<" Too many invalid attempts, going back to menu "<<resetColor()<<endl;
            return;
        }
        cout<<left;
        cout<<setw(30)<<"Name"<<setw(30)<<"National ID"<<setw(30)<<"E-Mail"<<setw(30)<<"Phone"<<endl;
        cout<<setw(30)<<reservations[idx].name<<setw(30)<<reservations[idx].nat_id<<setw(30)<<reservations[idx].email<<setw(30)<<reservations[idx].phone<<endl;
    }
}

//------------------------------------------------------------- Query ---------------------------------------------------------------------

void query()
{
    cout<<endl<<" Searching details "<<endl;
    int option;
    bool flag = false;
    while(!flag){
        cout<<"Search by: "<<endl;
        cout<<"[0] "<<setColor(red, black)<<"Back"<<resetColor()<<endl;
        cout<<"[1] "<<"Name"<<endl;
        cout<<"[2] "<<"Room No"<<endl;
        cout<<"[3] "<<"Room Status"<<endl;
        cin>>option;
        if(option !=0 && option != 1 && option != 2 && option != 3)
            cout<<setColor(white, yellow)<<"Invalid option."<<resetColor()<<endl;
        else
            flag=true;
    }
    if(option == 0)return;
    if(option == 1){
        int idx;
        cout<<"Enter Name: ";
        string name;
        cin.ignore();
        getline(cin, name);
        idx = searchReservationByName(name);
        if(idx == -1)
            cout<<endl<<setColor(white, red)<<" No reservations under this name "<<resetColor()<<endl;
        else{
            cout<<left;
            cout<<setw(20)<<"ID"<<setw(20)<<"Room NO"<<setw(20)<<"Status"<<setw(20)<<"Date"<<setw(20)<<"NO of nights"
                <<setw(20)<<"Name"<<setw(20)<<"National ID"<<setw(20)<<"E-Mail"<<setw(20)<<"Phone"<<endl;
            cout<<setw(20)<<reservations[idx].id<<setw(20)<<reservations[idx].room_no<<setw(20)<<reservations[idx].confirm<<setw(20)<<reservations[idx].check_in
                <<setw(20)<<reservations[idx].nights
                <<setw(20)<<reservations[idx].name<<setw(20)<<reservations[idx].nat_id<<setw(20)<<reservations[idx].email<<setw(20)<<reservations[idx].phone<<endl;
        }
    } else if(option == 2){
        int idx;
        string room_no;
        cout<<"Enter Room No: ";
        cin>>room_no;
        idx = searchRoomByNumber(room_no);
        int attempts = 3;
        while(idx==-1 && --attempts){
            cout<<setColor(white, yellow)<<" Invalid room number, please try again "<<resetColor()<<endl;
            cin>>room_no;
            idx = searchRoomByNumber(room_no);
        }
        if(!attempts){
            cout<<setColor(white, red)<<" Too many invalid attempts, going back to menu "<<resetColor()<<endl;
            return;
        }
        if(rooms[idx].status == "Reserved"){
            idx = searchReservationByRoomNumber(room_no);
            cout<<left;
            cout<<setw(20)<<"ID"<<setw(20)<<"Room NO"<<setw(20)<<"Status"<<setw(20)<<"Date"<<setw(20)<<"NO of nights"
                <<setw(20)<<"Name"<<setw(20)<<"National ID"<<setw(20)<<"E-Mail"<<setw(20)<<"Phone"<<endl;
            cout<<setw(20)<<reservations[idx].id<<setw(20)<<reservations[idx].room_no<<setw(20)<<reservations[idx].confirm<<setw(20)<<reservations[idx].check_in
                <<setw(20)<<reservations[idx].nights
                <<setw(20)<<reservations[idx].name<<setw(20)<<reservations[idx].nat_id<<setw(20)<<reservations[idx].email<<setw(20)<<reservations[idx].phone<<endl;
        } else{
            cout<<"\nRoom\tStatus\t\tCategory\tPrice\n";
            if(rooms[idx].type == "SeaView")
                cout<<rooms[idx].room_no<<"\t"<<rooms[idx].status<<"\t"<<rooms[idx].type<<"\t\t"<<rooms[idx].price<<"\n\n";
            else
                cout<<rooms[idx].room_no<<"\t"<<rooms[idx].status<<"\t"<<rooms[idx].type<<"\t"<<rooms[idx].price<<"\n\n";
        }
    } else{
        cout<<"[1] "<<"Show Available"<<endl;
        cout<<"[2] "<<"Show Reserved"<<endl;
        int option;
        cin>>option;

        if(option == 1){
            cout<<"\nRoom\tStatus\t\tCategory\tPrice\n";
            for(auto r:rooms){
                if(r.status == "Available")
                    if(r.type == "SeaView")
                        cout<<r.room_no<<"\t"<<r.status<<"\t"<<r.type<<"\t\t"<<r.price<<"\n\n";
                    else
                        cout<<r.room_no<<"\t"<<r.status<<"\t"<<r.type<<"\t"<<r.price<<"\n\n";
            }
        } else {
            cout<<"\nRoom\tStatus\t\tCategory\tPrice\n";
            for(auto r:rooms){
                if(r.status == "Reserved")
                    if(r.type == "SeaView")
                        cout<<r.room_no<<"\t"<<r.status<<"\t"<<r.type<<"\t\t"<<r.price<<"\n\n";
                    else
                        cout<<r.room_no<<"\t"<<r.status<<"\t"<<r.type<<"\t"<<r.price<<"\n\n";
            }
        }

    }
}
