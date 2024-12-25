#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <vector>
#include <string>
#include "reserve.h"
#include "Validations.h""
#include "structs.h"

using namespace std;
void EditReservation()
{

    cout << "Editing Reservation:" << endl;
    cout << "Please enter you reservation ID" << endl;
    string reservationID;
    cin >> reservationID;

    string roomNumber;
    //part el reservation.txt
    

    int flag = 0;
    for (int i = 0; i < reservations.size(); i++)
    {
        //part reservation
        if (reservations[i].id == reservationID)
        {
            flag = 1;
            roomNumber = reservations[i].room_no;

            cout << "PLease help us to collect all your data with modifications: \n";
            cout << "Notice you have only 3 trails to edit anything\n";

            for (int h = 0; h < 3; h++)
            {
                cout << "Please enter your name: \n";
                string name;
                getline(cin, name);
                if (Validations::NameValidation(name))
                {
                    reservations[i].name = name;
                    break;
                }
                else
                {
                    cout << "Invalid name and you have " << 3 - h << " trails left\n";

                }
                if (h == 2)
                {
                    "You have consumed all your trails please try again later\n";
                    return;
                }
            }

            for (int h = 0; h < 3; h++)
            {
                cout << "Please enter your phone number: \n";
                string phoneNumber;
                getline(cin, phoneNumber);
                if (Validations::PhoneNumberValidaion(phoneNumber))
                {
                    reservations[i].phone = phoneNumber;
                    break;
                }
                else
                {
                    cout << "Invalid phone Number and you have " << 3 - h << " trails left\n";

                }
                if (h == 2)
                {
                    "You have consumed all your trails please try again later\n";
                    return;
                }
            }

            for (int h = 0; h < 3; h++)
            {
                cout << "Please enter your Email Address: \n";
                string EmailAddress;
                getline(cin, EmailAddress);
                if (Validations::EmailValidation(EmailAddress))
                {
                    reservations[i].email = EmailAddress;
                    break;
                }
                else
                {
                    cout << "Invalid Email Address and you have " << 3 - h << " trails left\n";

                }
                if (h == 2)
                {
                    "You have consumed all your trails please try again later\n";
                    return;
                }
            }

            for (int h = 0; h < 3; h++)
            {
                cout << "Please enter your Number of Nights: \n";
                string NoOFNights;
                getline(cin, NoOFNights);
                if (Validations::NightsValidation(NoOFNights))
                {
                    reservations[i].nights = NoOFNights;
                    break;
                }
                else
                {
                    cout << "Invalid Number of nights and you have " << 3 - h << " trails left\n";

                }
                if (h == 2)
                {
                    "You have consumed all your trails please try again later\n";
                    return;
                }
            }
            break;

        }   
    }
   
    if (!flag)
    {
        cout << "Reservation ID not found.\n";
        return;
    }
   
    for (int i = 0; i < rooms.size(); i++)
    {
        
        if (rooms[i].room_no == roomNumber)
        {
           
            for (int h = 0; h < 3; h++)
            {
                cout << "Please enter your Room category (S:SeaView, G:GardenView, L:LakeView): \n";
                string roomCategory;
                getline(cin, roomCategory);
                if ( roomCategory == "S" || roomCategory == "G" || roomCategory == "L" )
                {
                    rooms[i].type = roomCategory;
                    break;
                }
                else
                {
                    cout << "Invalid room category and you have " << 3 - h << " trails left\n";

                }
                if (h == 2)
                {
                    "You have consumed all your trails please try again later\n";
                    return;
                }
            }
            break;
        }


    }


    cout << "Details updated successfully\n";
    sortReservations();
}
