#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <vector>
#include <string>
#include "structs.h"
#include "reserve.h"
using namespace std;

void CheckOut()
{

    cout <<"Checking out:" << endl;
    cout << "Please enter you reservation ID" << endl;
    string reservationID;
    cin >> reservationID;

    cout << "Please enter today's date" << endl;
    string TodayDate;
    cin >> TodayDate;

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
    }
    
    if (!flag)
    {
        cout << "Invalid Reservation ID\n";
        return;
    }

    //Part room.txt

    for (int i = 0; i < rooms.size(); i++)
    {
        
        if (rooms[i].room_no == roomNumber)
        {
            if (rooms[i].status == "Reserved")
                rooms[i].status = "Available";

            PricePerNight = stoi(rooms[i].price);
            break;

        }

    }

        //Calculating el bill '_'
        tm checkIn = {};
        stringstream CID(CheckINDate);
        string token;
        getline(CID, token, '-');
        checkIn.tm_mday = stoi(token);

        getline(CID, token, '-');
        checkIn.tm_mon = stoi(token) - 1;

        getline(CID, token, '-');
        checkIn.tm_year = stoi(token) - 1900;


        tm today = {};
        stringstream TD(TodayDate);
        getline(TD, token, '-');
        today.tm_mday = stoi(token);

        //tm betsta3mel el 0 indecies bellah eftekryyyyy
        getline(TD, token, '-');
        today.tm_mon = stoi(token) - 1;

        //since 1900 w ma7ade4 ye3raf leh as he mentioned be4
        getline(TD, token, '-');
        today.tm_year = stoi(token) - 1900;

        //3shan a7awel lel no of seconds:
        time_t checkInTime = mktime(&checkIn);
        time_t todayTime = mktime(&today);

        double seconds = difftime(todayTime, checkInTime);

        NoOfNights = seconds / (60 * 60 * 24);
        Bill = NoOfNights * PricePerNight;

        cout << "The required bill is: " << Bill << endl;
        cout << "Checked out succesfully\n";
        sortReservations();

}

