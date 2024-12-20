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
        if(rooms[i].type == cat && rooms[i].type == "Available")return i;
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

//------------------------------------------------------------- Show Details ---------------------------------------------------------------------

void viewCustomerDetails()
{
    int option;
    bool flag = false;
    while(!flag){
        cout<<"Search by: "<<endl;
        cout<<"[1] "<<"ID"<<endl;
        cout<<"[2] "<<"Room No"<<endl;
        cin>>option;
        if(option != 1 && option != 2)
            cout<<"Invalid option."<<endl;
        else
            flag=true;
    }
    if(option == 1){
        int idx;
        do{
            cout<<"Enter ID: "<<endl;
            string id;
            cin>>id;
            idx = searchReservationByID(id);
        }while(idx == -1);
        cout<<"\nID\tRoom\tStatus\t\tDate\t\tNo of nights\tName\t\tNational ID\t\tE-mail\t\t\tPhone\n";
        cout<<reservations[idx].id<<"\t"<<reservations[idx].room_no<<"\t"<<reservations[idx].confirm<<"\t"<<reservations[idx].check_in<<"\t";
        cout<<reservations[idx].nights<<"\t\t"<<reservations[idx].name<<"\t"<<reservations[idx].nat_id<<"\t\t"<<reservations[idx].email<<"\t";
        cout<<reservations[idx].phone<<"\n\n";
    } else{
        int idx;
        do{
            cout<<"Enter Room No: "<<endl;
            string room_no;
            cin>>room_no;
            idx = searchReservationByRoomNumber(room_no);
        }while(idx == -1);
        cout<<"\nID\tRoom\tStatus\t\tDate\t\tNo of nights\tName\t\tNational ID\t\tE-mail\t\t\tPhone\n";
        cout<<reservations[idx].id<<"\t"<<reservations[idx].room_no<<"\t"<<reservations[idx].confirm<<"\t"<<reservations[idx].check_in<<"\t";
        cout<<reservations[idx].nights<<"\t\t"<<reservations[idx].name<<"\t"<<reservations[idx].nat_id<<"\t\t"<<reservations[idx].email<<"\t";
        cout<<reservations[idx].phone<<"\n\n";
    }
}

void query()
{
    int option;
    bool flag = false;
    while(!flag){
        cout<<"Search by: "<<endl;
        cout<<"[1] "<<"Name"<<endl;
        cout<<"[2] "<<"Room No"<<endl;
        cout<<"[3] "<<"Room Status"<<endl;
        cin>>option;
        if(option != 1 && option != 2 && option != 3)
            cout<<"Invalid option."<<endl;
        else
            flag=true;
    }
    if(option == 1){
        int idx;
        cout<<"Enter Name: "<<endl;
        string name;
        cin.ignore();
        getline(cin, name);
        idx = searchReservationByName(name);
        if(idx == -1)
            cout<<"\nNo reservations under this name :(\n\n";
        else{
            cout<<"\nID\tRoom\tStatus\t\tDate\t\tNo of nights\tName\t\tNational ID\t\tE-mail\t\t\tPhone\n";
            cout<<reservations[idx].id<<"\t"<<reservations[idx].room_no<<"\t"<<reservations[idx].confirm<<"\t"<<reservations[idx].check_in<<"\t";
            cout<<reservations[idx].nights<<"\t\t"<<reservations[idx].name<<"\t"<<reservations[idx].nat_id<<"\t\t"<<reservations[idx].email<<"\t";
            cout<<reservations[idx].phone<<"\n\n";
        }
    } else if(option == 2){
        int idx;
        string room_no;
        do{
            cout<<"Enter Room No: "<<endl;
            cin>>room_no;
            idx = searchRoomByNumber(room_no);
        }while(idx == -1);
        if(rooms[idx].status == "Reserved"){
            idx = searchReservationByRoomNumber(room_no);
            cout<<"\nID\tRoom\tStatus\t\tDate\t\tNo of nights\tName\t\tNational ID\t\tE-mail\t\t\tPhone\n";
            cout<<reservations[idx].id<<"\t"<<reservations[idx].room_no<<"\t"<<reservations[idx].confirm<<"\t"<<reservations[idx].check_in<<"\t";
            cout<<reservations[idx].nights<<"\t\t"<<reservations[idx].name<<"\t"<<reservations[idx].nat_id<<"\t\t"<<reservations[idx].email<<"\t";
            cout<<reservations[idx].phone<<"\n\n";
        } else{
            cout<<"\nRoom\tStatus\t\tCategory\tPrice\n";
            if(rooms[idx].type == "SeaView")
                cout<<rooms[idx].room_no<<"\t"<<rooms[idx].status<<"\t"<<rooms[idx].type<<"\t\t"<<rooms[idx].price<<"\n\n";
            else
                cout<<rooms[idx].room_no<<"\t"<<rooms[idx].status<<"\t"<<rooms[idx].type<<"\t"<<rooms[idx].price<<"\n\n";
        }
    } else{
        cout<<"\nRoom\tStatus\t\tCategory\tPrice\n";
        for(auto r:rooms){
            if(r.type == "SeaView")
                cout<<r.room_no<<"\t"<<r.status<<"\t"<<r.type<<"\t\t"<<r.price<<"\n\n";
            else
                cout<<r.room_no<<"\t"<<r.status<<"\t"<<r.type<<"\t"<<r.price<<"\n\n";

        }
    }
}
