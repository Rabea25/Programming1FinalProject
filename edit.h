// just call editReservationDetails() when you want to edit :)
// missing the update room status
// i think it's done bas i did go to the techincal writing w nemt fel nos fa momken akon naset 7aga xD // lazy ass

#include <bits/stdc++.h>
#include "structs.h"
#include "colors.h"
#include "search.h"
#include "reserve.h"
using namespace std;

void EDIT(int idx) // takes index in the reservations vector
{
    reservation tempReservation = reservations[idx];
    // name, mobile, email address, reservation date, room category or number of nights only
    string s;
    cout << "Editing ...\n(press enter to skip)" << endl;
    fflush(stdin);
    cout << "Name: ";
    getline(cin, s);
    int attempts=0;
    while (!Validations::NameValidation(s))
    {
        cout << "Please enter a valid name\n";
        getline(cin, s);
        attempts++;
        if (attempts == 3)
        {
            cout << "Pelease try again later\n";
            return;
        }
    }
    tempReservation.name = s;

    cout << "Phone: ";
    getline(cin, s);
    attempts = 0;
    while (!Validations::PhoneNumberValidaion(s))
    {
        cout << "Please enter a valid phone number\n";
        getline(cin, s);
        attempts++;
        if (attempts == 3)
        {
            cout << "Pelease try again later\n";
            return;
        }
    }
    tempReservation.phone = s;

    cout << "Email: ";
    getline(cin, s);
    attempts = 0;
    while (!Validations::EmailValidation(s))
    {
        cout << "Please enter a valid Email\n";
        getline(cin, s);
        attempts++;
        if (attempts == 3)
        {
            cout << "Pelease try again later\n";
            return;
        }
    }

    tempReservation.email = s;

    cout << "Check-in date: ";
    getline(cin, s);
    attempts = 0;
    while (!Validations::DatesValidations(s))
    {
        cout << "Please enter a valid date\n";
        getline(cin, s);
        attempts++;
        if (attempts == 3)
        {
            cout << "Pelease try again later\n";
            return;
        }
    }
    tempReservation.check_in = s;


    cout << "Room category (S:SeaView, G:GardenView, L:LakeView): ";
    getline(cin, s);
    while (!(s == "S" || s == "G" || s == "L" || s == ""))
    {
        cout << "Enter a valid input ";
        getline(cin, s);
    }
    if (s != "")
    {
        int room_id;
        room_id = searchRoomByCategory(s);
        if (room_id == -1)cout << "Sorry there aren't any available rooms of the chosen category" << endl;
        else
        {
            //UpdateRoomStatus( searchRoomByNumber( reservations[idx].room_no ) );----------------------------------------------------------5las not needed------------------------------
            rooms[searchRoomByNumber(reservations[idx].room_no)].status = "Available";
            tempReservation.room_no = rooms[room_id].room_no;
            rooms[room_id].status = "Reserved";
            cout << "Your new room is room " << rooms[room_id].room_no << endl;
        }
    }

    cout << "Number of nights: ";
    getline(cin, s);
    tempReservation.nights = (s == "" ? reservations[idx].nights : s);

    reservations[idx] = tempReservation;
    bool x = sortReservations(); //incase checkin date is changed, and then it saves
    if (x)cout << setColor(white, green) << " Reservation edited successfully " << resetColor() << endl << endl;
    else cout << setColor(white, red) << " Reservation edited has been canceled " << resetColor() << endl << endl;
}

int editReservationDetails()
{
    cout << endl << "Editing an existing reservation" << endl;
    cout << "Please select an option:" << endl;
    cout << "[0] " << setColor(red, black) << "Back" << resetColor() << endl;
    cout << "[1] Reservation ID" << endl;
    cout << "[2] Room Number" << endl;

    string option;
    cin >> option;
    while (!(option == "0" || option == "1" || option == "2"))
    {
        cout << "Please enter a valid option" << endl;
        cin >> option;
    }

    if (option == "0") return -1;
    if (option == "1")
    {
        string reservation_ID;
        int temp;
        do
        {
            cout << "Reservation ID: ";
            cin >> reservation_ID;
            temp = searchReservationByID(reservation_ID);
            if (temp == -1)cout << "Sorry this ID doesn't exist, please try again" << endl;

        } while (temp == -1);

        EDIT(temp);
    }
    if (option == "2")
    {
        string room_no;
        int temp;
        do
        {
            cout << "Room Number: ";
            cin >> room_no;
            temp = searchReservationByRoomNumber(room_no);
            if (temp == -1) cout << "Sorry this room doesn't exist, please try again" << endl;

        } while (temp == -1);

        EDIT(temp);
    }

    return 1;
}
