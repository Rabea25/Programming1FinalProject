#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <vector>
using namespace std;

void EditReservation(string  reservationID)
{
    string roomNumber;

    //part el reservation.txt
    ifstream file("Reservation.txt");
    vector<string> data;
    string line;
    while (getline(file, line))
    {
        data.push_back(line);
    }
    file.close();

    int flag1 = 0;
    for (int i = 0; i < data.size(); i++)
    {
        //part reservation
        stringstream x(data[i]);
        string token;
        vector<string> PPLDetails;

        while (getline(x, token, ','))
        {
            PPLDetails.push_back(token);
        }
        if (PPLDetails[0] == reservationID)
        {
            flag1 = 1;
            // 3shan part el rooms:
            roomNumber = PPLDetails[1];

            cout << "PLease help us to collect all your data with modifications: \n";
            cout << "Please enter your name: \n";
            getline(cin, PPLDetails[3]);

            cout << "Please enter your mobile number: \n";
            getline(cin, PPLDetails[8]);

            cout << "Please enter your email address: \n";
            getline(cin, PPLDetails[7]);

            //Reservations Date::




            cout << "Please enter your number of nights: \n";
            getline(cin, PPLDetails[5]);

            //Updating el data 
            data[i] = "";
            for (int j = 0; j < PPLDetails.size(); j++)
            {
                data[i] += PPLDetails[j];
                //el commas
                if (j < PPLDetails.size() - 1)
                    data[i] += ",";
            }
            break;

        }
    }
    //Update el file zat nafso
    if (flag1)
    {
        ofstream reservationFile("Reservation.txt");
        for (const string& res : data)
        {
            reservationFile << res << endl;
        }
        reservationFile.close();
        cout << "Reservation updated successfully.\n";
    }
    else
    {
        cout << "Reservation ID not found.\n";
    }


    //part el room.txt
    ifstream file2("Room.txt");
    vector<string> data2;
    string line2;
    while (getline(file2, line2))
    {
        data2.push_back(line2);
    }
    file2.close();

    int flag2 = 0;
    for (int i = 0; i < data2.size(); i++)
    {
        //part el room
        stringstream y(data2[i]);
        string token2;
        vector<string> Rooms;

        while (getline(y, token2, ' '))
        {
            Rooms.push_back(token2);
        }
        if (Rooms[0] == roomNumber)
        {
            flag2 = 1;
            cout << "Please enter the new room category: \n";
            getline(cin, Rooms[2]);

            data2[i] = "";
            for (int j = 0; j < Rooms.size(); j++)
            {
                data2[i] += Rooms[j];
                //el spaces
                if (j < Rooms.size() - 1)
                    data2[i] += " ";
            }
            break;
        }


    }

    if (flag2)
    {
        ofstream roomsFile("Rooms.txt");
        for (const string& room : data2)
        {
            roomsFile << room << endl;
        }
        roomsFile.close();
        cout << "Room category updated successfully.\n";
    }
    else
    {
        cout << "Room number not found.\n";
    }


}
