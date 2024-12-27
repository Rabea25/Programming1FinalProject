#include <bits/stdc++.h>
#include "structs.h"
#include "login.h"
#include "colors.h"
#include "io.h"
#include "edit.h"
#include "cancel.h"
#include "reserve.h"
#include "report.h"
#include "CheckIN.h"
#include "CheckOut.h"

using namespace std;

bool loggedin = false;
string wackadoodle;



void menu(){
    int opt;
    cout<<"Welcome to the hotel management system"<<endl<<endl;
    while(!loggedin){
        cout<<"Please select an option:"<<endl;
        cout<<"[1] Login"<<endl;
        cout<<"[2] "<<setColor(red, black)<<"Quit"<<resetColor()<<endl;
        cin>>opt;
        if(opt==1){
            loggedin = login(users);
        } 
        else if(opt==2){
            cout<<"Goodbye!"<<endl;
            exit(0);
        }
        else cout<<setColor(white,yellow)<<endl<<" Invalid input. "<<resetColor()<<endl<<endl;
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
                reserveRoom(); //i think is done
                break;
            case 2:
                checkIN(); //all goodie 
                break;
            case 3:
                cancelReservation();
                break;
            case 4:
                CheckOut();
                break;
            case 5: 
                for(room r:rooms){
                    if(r.status=="Available" && searchReservationByRoomNumber(r.room_no)==-1) cout<<r.room_no<<" "<<r.status<<" "<<r.type<<" "<<r.price<<endl;
                }
                cout<<endl;
                break;
            case 6:
                viewCustomerDetails();
                break;
            case 7:
                editReservationDetails();
                break;
            case 8:
                query();
                break;
            case 9:
                reservationReport();
                break;
            case 10:
                cout<<endl<<setColor(red, black)<<"---Logging Out---"<<resetColor()<<endl<<endl;
                loggedin = 0;
                break;
            case 11:
                cout<<setColor(red, black)<<"---Logging Out---"<<resetColor()<<endl;
                cout<<"Goodbye!"<<endl;
                exit(0);
            default:
                cout<<setColor(white,yellow)<<endl<<" Invalid input, options are numbered 1 through 11. "<<resetColor()<<endl;
        }       cout<<endl;
    }
}

int main(){
    cout<<resetColor();
    users = loadUsers();
    reservations = loadReservations();
    reservationsOG = reservations;
    rooms = loadRooms();
    roomsOG = rooms;
    today = "02-02-2025"; //if you want to set a custom date comment getDate() and change this
    //getDate(); 
    //cout<<today<<endl;
    while(1){
        menu();
    }
}
