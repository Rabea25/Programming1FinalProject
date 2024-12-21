#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <vector>
using namespace std;

void CheckIN(string reservationID, string TodayDate)
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

    int flag = 0;
    for (int i = 0; i < reservations.size(); i++)
    {
        //part reservation
        stringstream x(reservations[i]);
        string token;
        vector<string> ResDetails;

        while (getline(x, token, ','))
        {
            ResDetails.push_back(token);
        }

        if (ResDetails[0] == reservationID && ResDetails[6] == TodayDate)
        {
            flag = 1;

            // 3shan part el rooms:
            roomNumber = ResDetails[1];

            if (ResDetails[2] == "unconfirmed")
            {
                ResDetails[2] = "confirmed";

                reservations[i] = "";
                for (int j = 0; j < ResDetails.size(); j++)
                {
                    reservations[i] += ResDetails[j];
                    //El commas

                    if (j < ResDetails.size() - 1)
                        reservations[i] += ",";
                }
            }

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
            if (RoomsDetails[1] == " Available")
                RoomsDetails[1] = " Reserved";

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
        ofstream roomsFile("Rooms.txt");
        for (const string& room : rooms)
        {
            roomsFile << room << endl;
        }
        roomsFile.close();
        cout << "Check in Successful.\n";
    }
    else
    {
        cout << "Invalid Check in date or reservation not found\n";
    }

}
