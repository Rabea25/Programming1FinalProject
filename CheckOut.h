#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <vector>
using namespace std;

void CheckOut(string reservationID, string TodayDate)
{
    ifstream reservationFile("Reservation.txt");
    ifstream roomFile("Room.txt");

    vector<string> reservations;
    vector<string> rooms;

    string line;
    while (getline(reservationFile, line))
    {
        reservations.push_back(line);
    }
    reservationFile.close();

    while (getline(roomFile, line))
    {
        rooms.push_back(line);
    }
    roomFile.close();

    //3shan a5do mn el reservations.txt
    string roomNumber;
    //Elli ha7tago 3shan adfa3 el bill
    string CheckINDate;
    int PricePerNight = 0;
    int NoOfNights = 0;
    int Bill = 0;

    int flag = 0;
    for (int i = 0; i < reservations.size(); i++)
    {
        //part el reservation
        stringstream x(reservations[i]);
        string token;
        vector<string> ResDetails;

        while (getline(x, token, ','))
        {
            ResDetails.push_back(token);
        }

        if (ResDetails[0] == reservationID && ResDetails[2] == "confirmed")
        {
            flag = 1;
            // 3shan part el rooms:
            roomNumber = ResDetails[1];
            CheckINDate = ResDetails[6];

            //Hamsa7 el details beta3et el reservation "BYEEE"
            reservations.erase(reservations.begin() + i);

            break;

        }

    }
    if (flag)
    {
        ofstream reservationFile("Reservation.txt");
        for (const string& res : reservations)
        {
            reservationFile << res << endl;
        }
        reservationFile.close();
    }

    //Part room.txt

    int flag2 = 0;
    for (int i = 0; i < rooms.size(); i++)
    {
        //part el room
        stringstream x(rooms[i]);
        string token;
        vector<string> RoomsDetails;

        while (getline(x, token, ' '))
        {
            RoomsDetails.push_back(token);
        }

        if (RoomsDetails[0] == roomNumber)
        {
            flag2 = 1;

            if (RoomsDetails[1] == "Reserved")
                RoomsDetails[1] = "Available";

            PricePerNight = stoi(RoomsDetails[3]);

            rooms[i] = "";
            for (int j = 0; j < RoomsDetails.size(); j++)
            {
                rooms[i] += RoomsDetails[j];
                //el spaces
                if (j < RoomsDetails.size() - 1)
                    rooms[i] += " ";
            }
            break;

        }


    }
    if (flag2)
    {
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


        //el editing 
        ofstream roomsFile("Rooms.txt");
        for (const string& room : rooms)
        {
            roomsFile << room << endl;
        }
        roomsFile.close();
        cout << "Check out Successful.\n";
    }
    else
    {
        cout << "Invalid Check out\n";
    }


}
