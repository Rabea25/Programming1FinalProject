#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <vector>
#include "structs.h"
#include "colors.h"
using namespace std;

void checkIN()
{
    cout<<endl<<"Checking in:"<<endl;
    cout<<"[0] "<<setColor(red, black)<<"Back"<<resetColor()<<endl;
    cout<<"[1] Continue"<<endl;
    string O;
    cin>>O;
    while( !( O == "0" || O == "1" ) )
    {
        cout<<setColor(white, yellow)<<" Please enter a valid option "<<resetColor()<<endl;
        cin>>O;
    }
    if(O == "0")return;

    //hat el reservation id
    cout<<"Enter reservation id: ";
    string reservationID;
    cin>>reservationID;

    //3shan a5do mn el reservations.txt
    string roomNumber;

    int flag = 0;
    for (int i = 0; i < reservations.size(); i++)
    {
        //part reservation
        if (reservations[i].id == reservationID && reservations[i].check_in == today)
        {
            flag = 1;

            // 3shan part el rooms:
            roomNumber = reservations[i].room_no;

            if (reservations[i].confirm == "unconfirmed")
            {
                reservations[i].confirm = "confirmed";
            }
            else
            {
                cout<<endl<<setColor(white, red)<<" Customer has already checked-in. "<<resetColor()<<endl<<endl;
                return;
            }
            break;
        }
    }

    if (!flag)
    {
        cout<<endl<<setColor(white, yellow)<<" Invalid Check in date or reservation not found "<<resetColor()<<endl<<endl;
        return; 
    }

    //Part room.txt

    for (int i = 0; i < rooms.size(); i++)
    {
        //part el room
        if (rooms[i].room_no == roomNumber)
        {
            if (rooms[i].status == "Available")
                rooms[i].status = "Reserved";

    
            break;
        }
    }
    bool x = save();
    if(x)cout<<endl<<setColor(white, green)<<" Customer has checked-in successfully. "<<resetColor()<<endl<<endl;
    else cout<<endl<<setColor(white, red)<<" Customer check-in has been canceled. "<<resetColor()<<endl<<endl;
}
