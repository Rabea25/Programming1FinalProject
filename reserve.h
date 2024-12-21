// validation required when adding a reservation, i.e, checkAvailablity() func
#include <bits/stdc++.h>
#include "structs.h"
#include "colors.h"
#include "search.h"

using namespace std;

void sortReservations()
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
}

void reserveRoom()
{
    reservation newReservation;
    cout<<endl<<"Adding a reservation"<<endl;

    cout<<"Enter Name: "<<endl;
    cin.ignore();
    getline(cin, newReservation.name);

    cout<<"Enter national ID: "<<endl;
    cin>>newReservation.nat_id;

    cout<<"Enter e-mail: "<<endl;
    cin>>newReservation.email;

    cout<<"Enter phone no: "<<endl;
    cin>>newReservation.phone;


    //---------------temporary placeholders for testing until checkAvailibilty func is finished----------//
    cout<<"Enter Check In date(DD-MM-YYYY): "<<endl;
    cin>>newReservation.check_in;

    cout<<"Enter no of nights: "<<endl;
    cin>>newReservation.nights;
    
    cout<<"Enter room no: "<<endl;
    cin>>newReservation.room_no;
    ///////////////////////////////////////////////////////////////////////////////////////////////////////

    // do{
    //     cout<<"Choose room type: "<<endl;
    //     cout<<"[1] "<<"SeaView"<<endl;
    //     cout<<"[2] "<<"LakeView"<<endl;
    //     cout<<"[3] "<<"GardenView"<<endl;
    //     int option;
    //     cin>>option;
    
    //     cout<<"Enter Check In date(DD-MM-YYYY): "<<endl;
    //     cin>>newReservation.check_in;

    //     cout<<"Enter no of nights: "<<endl;
    //     cin>>newReservation.nights;

    // } while(checkAvailablity(option, newReservation.check_in, newReservation.nights) == -1);
    //newReservation.room_no = checkAvailablity(option, newReservation.check_in, newReservation.nights);

    for(int no=1;no<101;no++){
        bool exists = false;
        for(auto r:reservations){
            if(stoi(r.id) == no) exists = true;
        }
        if(!exists) {newReservation.id = "1432" + to_string(no);break;}
    }


    newReservation.confirm = "unconfirmed";

    cout<<" Successfully canceled the reservation "<<endl;

    reservations.push_back(newReservation);

    sortReservations();
}

void reservationReport()
{
    cout<<endl<<" Reservation Report! "<<endl;
    cout<<"ID\tRoom\tStatus\t\tDate\t\tNo of nights\tName\t\tNational ID\t\tE-mail\t\t\tPhone\n";
    for(auto r:reservations){
        cout<<r.id<<"\t"<<r.room_no<<"\t"<<r.confirm<<"\t"<<r.check_in<<"\t"<<r.nights<<"\t\t"<<r.name<<"\t"<<r.nat_id<<"\t\t"<<r.email<<"\t"<<r.phone<<"\n";
    }
    cout<<"\n\n";
}