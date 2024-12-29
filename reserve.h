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
    int attempts=3;
    cin.ignore();
    getline(cin, newReservation.name);
    while(!Validations::NameValidation(newReservation.name) && --attempts){
        cout<<setColor(white,yellow)<<" Invalid name format "<<resetColor()<<endl<<"Please enter a valid name: ";
        cin.ignore();
        getline(cin, newReservation.name);
    }
    if(!attempts){
        cout<<setColor(white, red)<<" Too many invalid attempts, going back to menu "<<resetColor()<<endl;
        return;
    }
    attempts=3;
    cout<<"Enter national ID: ";
    cin>>newReservation.nat_id;
    while(!Validations::NationalIDValidation(newReservation.nat_id) && --attempts){
        cout<<setColor(white,yellow)<<" Invalid national ID "<<resetColor()<<endl<<"Please enter a valid national ID: ";
        cin>>newReservation.nat_id;
    }
    if(!attempts){
        cout<<setColor(white, red)<<" Too many invalid attempts, going back to menu "<<resetColor()<<endl;
        return;
    }
    attempts=3;
    cout<<"Enter e-mail: ";
    cin>>newReservation.email;
    while(!Validations::EmailValidation(newReservation.email) && --attempts){
        cout<<setColor(white,yellow)<<" Invalid email "<<resetColor()<<endl<<"Please enter a valid email: ";
        cin>>newReservation.email;
    }
    if(!attempts){
        cout<<setColor(white, red)<<" Too many invalid attempts, going back to menu "<<resetColor()<<endl;
        return;
    }
    attempts=3;
    cout<<"Enter phone no: ";
    cin>>newReservation.phone;
    while(!Validations::PhoneNumberValidaion(newReservation.phone) && --attempts){
        cout<<setColor(white,yellow)<<" Invalid phone number "<<resetColor()<<endl<<"Please enter a valid phone number: ";
        cin>>newReservation.phone;
    }
    if(!attempts){
        cout<<setColor(white, red)<<" Too many invalid attempts, going back to menu "<<resetColor()<<endl;
        return;
    }
    attempts=3;
    cout<<"Enter Check In date(DD-MM-YYYY): ";
    cin>>newReservation.check_in;
    while(!Validations::DatesValidations(newReservation.check_in) && --attempts){
        cout<<setColor(white,yellow)<<" Invalid date "<<resetColor()<<endl<<"Please enter date in the format DD-MM-YYYY: ";
        cin>>newReservation.check_in;
    }
    if(!attempts){
        cout<<setColor(white, red)<<" Too many invalid attempts, going back to menu "<<resetColor()<<endl;
        return;
    }
    attempts=3;
    cout<<"Enter no of nights: ";
    cin>>newReservation.nights;
    while(!Validations::NightsValidation(newReservation.nights) && --attempts){
        cout<<setColor(white,yellow)<<" Invalid number "<<resetColor()<<endl<<"Please enter a valid number of nights (maximum is 30): ";
        cin>>newReservation.nights;
    }
    if(!attempts){
        cout<<setColor(white, red)<<" Too many invalid attempts, going back to menu "<<resetColor()<<endl;
        return;
    }

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
    while(searchRoomByNumber(roomNumber)==-1 || rooms[searchRoomByNumber(roomNumber)].type!=xdddd
        || rooms[searchRoomByNumber(roomNumber)].status!="Available" || searchReservationByRoomNumber(roomNumber)!=-1){
        cout<<setColor(white,yellow)<<" Invalid room number or mismatching category "<<resetColor()<<endl;
        cout<<"Choose room no: ";
        cin>>roomNumber;
    }
    newReservation.room_no = roomNumber;

    newID();
    newReservation.id = to_string(resID);

    newReservation.confirm = "unconfirmed";
    
    reservations.push_back(newReservation);
    bool x = sortReservations();
    if(x)cout<<endl<<setColor(white, green)<<" Reservation is successful, reservation id: "<<newReservation.id<<' '<<resetColor()<<endl<<endl;
    else cout<<endl<<setColor(white, red)<<" Reservation has been canceled "<<resetColor()<<endl<<endl;
}
