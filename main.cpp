#include <bits/stdc++.h>
#include "structs.h"
#include "login.h"
#include "colors.h"
#include "io.h"
using namespace std;

bool loggedin = false;
vector<user> users;
vector<reservation> reservations;
vector<room> rooms;


void menu(){
    int opt;
    cout<<"Welcome to the hotel management system"<<endl<<endl;
    while(!loggedin){
        cout<<"Please select an option:"<<endl;
        cout<<"[1] Login"<<endl;
        cout<<"[2] "<<setColor(red, black)<<"Quit"<<resetColor()<<endl;
        cin>>opt;
        if(opt==1){
            loggedin |= login(users);
        } 
        else if(opt==2){
            cout<<"Goodbye!"<<endl;
            exit(0);
        }
        else cout<<"Invalid option. ";
    }
    cout<<setColor(brightWhite, black)<<"Welcome staff member, this is the main menu:"<<endl<<endl;
    while(loggedin){ 
        cout<<"[1] "<<"Reserve a room"<<endl;
        cout<<"[2] "<<"Check-in"<<endl;
        cout<<"[3] "<<"Cancel reservation"<<endl;
        cout<<"[4] "<<"Check-out"<<endl;
        cout<<"[5] "<<"Check Room Availability"<<endl;
        cout<<"[6] "<<"View customer details"<<endl;
        cout<<"[7] "<<"Edit reservation details"<<endl; 
        cout<<"[8] "<<"Search details (Query)"<<endl;
        cout<<"[9] "<<"Reservations report"<<endl;
        cout<<"[10] "<<setColor(red, black)<<"Logout"<<resetColor()<<endl;
        cout<<"[11] "<<setColor(red, black)<<"Quit"<<resetColor()<<endl;

        cin>>opt;
        switch(opt){
            case 1:
                //reserveRoom();
                break;
            case 2:
                //checkIn();
                break;
            case 3:
                //cancelReservation();
                break;
            case 4:
                //checkOut();
                break;
            case 5:
                //checkRoomAvailability();
                break;
            case 6:
                //viewCustomerDetails();
                break;
            case 7:
                //editReservationDetails();
                break;
            case 8:
                //query();
                break;
            case 9:
                //reservationReport();
                break;
            case 10:
                cout<<endl<<setColor(red, black)<<"--Logging Out--"<<resetColor()<<endl<<endl;
                loggedin = 0;
                break;
            case 11:
                cout<<setColor(red, black)<<"--Logging Out--"<<resetColor()<<endl;
                cout<<"Goodbye!"<<endl;
                save(reservations, rooms);
                exit(0);
            default:
                cout<<endl<<"Invalid input, options are numbered 1 through 11. "<<endl<<endl;
        }
    }
}

int main(){
    users = loadUsers();
    loginAttempts = 3;
    reservation r;
    r.id = "1";
    r.room_no = "101";
    r.confirm = "confirmed";
    r.name = "John Doe";
    r.nat_id = "123456789";
    r.nights = "3";
    r.check_in = "10-10-2025";
    r.email = "mm@gmail.com";
    r.phone = "123456789";
    reservations.push_back(r);
    while(1){
        menu();
    }
}