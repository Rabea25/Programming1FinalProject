#include <bits/stdc++.h>
#include "structs.h"
#include "reserve.h"

using namespace std;

void CheckOut()
{

    cout <<"Checking out:" << endl;
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
    cout << "Please enter you reservation ID" << endl;
    string reservationID;
    cin >> reservationID;

    string TodayDate = today;

    string roomNumber;
    string CheckINDate;
    int PricePerNight = 0;
    int NoOfNights = 0;
    int Bill = 0;

    int flag = 0;
    for (int i = 0; i < reservations.size(); i++)
    {
        //part reservation
        if (reservations[i].id == reservationID && reservations[i].confirm == "confirmed")
        {
            flag = 1;
            roomNumber = reservations[i].room_no;
            CheckINDate = reservations[i].check_in;

            //Hamsa7 el details beta3et el reservation "BYEEE"
            reservations.erase(reservations.begin() + i);
            break;
        }
        if (reservations[i].id == reservationID && reservations[i].confirm == "unconfirmed") flag=-1;
    }
    
    if (!flag)
    {
        cout <<setColor(white, yellow)<< "Invalid Reservation ID "<<resetColor()<<endl;
        return;
    }
    if (flag == -1)
    {
        cout <<setColor(white, red)<< " Customer hasn't checked in yet "<<resetColor()<<endl;
        return;
    }

    //Part room.txt
    for (int i = 0; i < rooms.size(); i++)
    {
        
        if (rooms[i].room_no == roomNumber)
        {
            rooms[i].status = "Available";
            PricePerNight = stoi(rooms[i].price);
            break;

        }

    }

    //Calculating el bill '_'
    tm checkIn = {};
    stringstream CID(CheckINDate);
    string token;
    cin.ignore();
    getline(CID, token, '-');
    checkIn.tm_mday = stoi(token);

    //cin.ignore();
    getline(CID, token, '-');
    checkIn.tm_mon = stoi(token) - 1;

    //cin.ignore();
    getline(CID, token, '-');
    checkIn.tm_year = stoi(token) - 1900;

    tm today = {};
    stringstream TD(TodayDate);
    //cin.ignore();
    getline(TD, token, '-');
    today.tm_mday = stoi(token);

    //tm betsta3mel el 0 indecies bellah eftekryyyyy
    //cin.ignore();
    getline(TD, token, '-');
    today.tm_mon = stoi(token) - 1;

    //since 1900 w ma7ade4 ye3raf leh as he mentioned be4
    //cin.ignore();
    getline(TD, token, '-');
    today.tm_year = stoi(token) - 1900;

    //3shan a7awel lel no of seconds:
    time_t checkInTime = mktime(&checkIn);
    time_t todayTime = mktime(&today);

    double seconds = difftime(todayTime, checkInTime);

    NoOfNights = max(seconds / (60 * 60 * 24), 1.0);
    Bill = NoOfNights * PricePerNight;

    cout << "The required bill is: " << Bill << endl;
        
    bool x = sortReservations();
    if(x)cout<<endl<<setColor(white, green)<<" Checked out succesfully. "<<resetColor()<<endl<<endl;
    else cout<<endl<<setColor(white, red)<<" Check-out has been cancelled. "<<resetColor()<<endl<<endl;
}
