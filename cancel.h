#include <bits/stdc++.h>
#include "structs.h"
#include "colors.h"

using namespace std;



void CANCEL(int idx)// takes index in the reservations vector
{
    reservation toBeCanceled = reservations[idx];
    int room_idx;
    //room_idx = searchRoomBynumber(toBeCanceled.room_no);-------------------------------------------------------------
    if(rooms[room_idx].status == "Confimed")
    {
        cout<<"Sorry you can't cancel a confirmed room"<<endl;
        return;
    }
    reservations.erase(reservations.begin() + idx);
    rooms[room_idx].status = "Available";
    return;
}




int cancelReservation()
{
    cout<<"Canceling an existing reservation"<<endl;
    cout<<"Please select an option:"<<endl;
    cout<<"[0] "<<setColor(red, black)<<"Back"<<resetColor()<<endl;
    cout<<"[1] Reservation ID"<<endl;
    cout<<"[2] Room Number"<<endl;

    string option;
    cin>>option;
    while( !( option == "0" || option == "1" || option == "2" ) )
    {
        cout<<"Please enter a valid option"<<endl;
        cin>>option;

    }

    if(option == "0")return -1;
    if(option == "1")
    {
        string reservation_ID;
        int temp;
        do
        {
            cout<<"Reservation ID: ";
            cin>>reservation_ID;
            //temp = searchResrvationByID(reservation_ID);------------------------------------------------------------
            if(temp == -1)cout<<"Sorry this ID doesn't exist, please try again"<<endl;

        }while(temp == -1);

        CANCEL(temp);
    }
    if(option == "2")
    {
        string room_no;
        int temp;
        do
        {
            cout<<"Room Number: ";
            cin>>room_no;
            //temp = searchReservationByRoomNumber(room_no);----------------------------------------------------------------------------------------------
            if(temp == -1) cout<<"Sorry this room doesn't exist, please try again"<<endl;
            
        }while(temp == -1);

        CANCEL( temp );
    }

    return 1;
}