// validation required when adding a reservation, i.e, checkAvailablity() func
#include <bits/stdc++.h>
#include "structs.h"
#include "colors.h"
#include "search.h"
#include "Validations.h"
#pragma once
using namespace std;

bool sortReservations()
{
    vector<int> idx = {6, 7, 8, 9, 3, 4, 0, 1};
    for(int i=0;i<reservations.size()-1;i++){
        for(int j=0;j<reservations.size()-i-1;j++){
            for(int k=0;k<8;k++){
                if(reservations[j].check_in[idx[k]] > reservations[j+1].check_in[idx[k]]){
                    swap(reservations[j], reservations[j+1]);
                    break;
                } else if(reservations[j].check_in[idx[k]] < reservations[j+1].check_in[idx[k]]){
                    break;
                }
            }
        }
    }
    return save();
}

void reserveRoom()
{
    reservation newReservation;
    cout<<endl<<"Adding a reservation:"<<endl;

    cout<<"[0] "<<setColor(red, black)<<"Back"<<resetColor()<<endl;
    cout<<"[1] Continue"<<endl;
    string O;
    cin>>O;
    while( !( O == "0" || O == "1" ) )
    {
        cout<<"Please enter a valid option"<<endl;
        cin>>O;
    }
    if(O == "0")return;

    cout<<"Enter Name: ";
    cin.ignore();
    getline(cin, newReservation.name);
    while(!Validations::NameValidation(newReservation.name)){
        cout<<setColor(white,yellow)<<" Invalid name format "<<resetColor()<<endl<<"Please enter a valid name: ";
        getline(cin, newReservation.name);
    }

    cout<<"Enter national ID: ";
    cin>>newReservation.nat_id;
    while(!Validations::NationalIDValidation(newReservation.nat_id)){
        cout<<setColor(white,yellow)<<" Invalid national ID "<<resetColor()<<endl<<"Please enter a valid national ID: ";
        cin>>newReservation.nat_id;
    }


    cout<<"Enter e-mail: ";
    cin>>newReservation.email;
    while(!Validations::EmailValidation(newReservation.email)){
        cout<<setColor(white,yellow)<<" Invalid email "<<resetColor()<<endl<<"Please enter a valid email: ";
        cin>>newReservation.email;
    }

    cout<<"Enter phone no: ";
    cin>>newReservation.phone;
    while(!Validations::PhoneNumberValidaion(newReservation.phone)){
        cout<<setColor(white,yellow)<<" Invalid phone number "<<resetColor()<<endl<<"Please enter a valid phone number: ";
        cin>>newReservation.phone;
    }


    cout<<"Enter Check In date(DD-MM-YYYY): ";
    cin>>newReservation.check_in;
    while(!Validations::DatesValidations(newReservation.check_in)){
        cout<<setColor(white,yellow)<<" Invalid date "<<resetColor()<<endl<<"Please enter date in the format DD-MM-YYYY: ";
        cin>>newReservation.check_in;
    }

    cout<<"Enter no of nights: ";
    cin>>newReservation.nights;
    while(!Validations::NightsValidation(newReservation.nights)){
        cout<<setColor(white,yellow)<<" Invalid number "<<resetColor()<<endl<<"Please enter a valid number of nights (maximum is 30): ";
        cin>>newReservation.nights;
    }
    //---------------temporary placeholders for testing until checkAvailibilty func is finished----------//
    // cout<<"Enter room no: ";
    // cin>>newReservation.room_no;
    ///////////////////////////////////////////////////////////////////////////////////////////////////////

    int option;
    string cat;
    cout<<"Choose room type: "<<endl;
    cout<<"[1] "<<"SeaView"<<endl;
    cout<<"[2] "<<"LakeView"<<endl;
    cout<<"[3] "<<"GardenView"<<endl;
    cin>>option;
    option==1?cat="S":option==2?cat="L":option==3?cat="G":cat="";
    while(searchRoomByCategory(cat) == -1){
        cout<<setColor(white,yellow)<<" No available rooms in chosen category "<<resetColor()<<endl;
        cout<<"Choose room type: "<<endl;
        cout<<"[1] "<<"SeaView"<<endl;
        cout<<"[2] "<<"LakeView"<<endl;
        cout<<"[3] "<<"GardenView"<<endl;
        cin>>option;
        option==1?cat="S":option==2?cat="L":option==3?cat="G":cat="";
    }
    string xdddd = cat=="S"?"SeaView":cat=="L"?"LakeView":"GardenView";
    showAvailableRoomsByCategory(xdddd);
    cout<<"Choose room no: ";
    string roomNumber; 
    cin>>roomNumber;
    while(searchRoomByNumber(roomNumber)==-1 || rooms[searchRoomByNumber(roomNumber)].type!=xdddd){
        cout<<setColor(white,yellow)<<" Invalid room number or mismatching category "<<resetColor()<<endl;
        cout<<"Choose room no: ";
        cin>>roomNumber;
    }

    newReservation.room_no = roomNumber;
    rooms[searchRoomByNumber(roomNumber)].status = "Reserved";

    newID();
    newReservation.id = to_string(resID);
    

    newReservation.confirm = "unconfirmed";
    
    cout<<endl<<setColor(white, green)<<" Reservation is successful, reservation id:  "<<newReservation.id<<resetColor()<<endl<<endl;
    reservations.push_back(newReservation);
    sortReservations();
}

/*void reservationReport()
{
    cout<<endl<<" Reservation Report! "<<endl;
    cout<<"ID\tRoom\tStatus\t\tDate\t\tNo of nights\tName\t\tNational ID\t\tE-mail\t\t\tPhone\n";
    for(auto r:reservations){
        cout<<r.id<<"\t"<<r.room_no<<"\t"<<r.confirm<<"\t"<<r.check_in<<"\t"<<r.nights<<"\t\t"<<r.name<<"\t"<<r.nat_id<<"\t\t"<<r.email<<"\t"<<r.phone<<"\n";
    }
    cout<<"\n\n";
}
*/