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
    while (!Validations::NameValidation(s) && s!="")
    {
        cout <<setColor(white, yellow)<< " Please enter a valid name "<<resetColor()<<endl;
        getline(cin, s);
        attempts++;
        if (attempts == 3)
        {
            cout<<setColor(white, red)<<" Too many invalid attempts, going back to menu "<<resetColor()<<endl;
            return;
        }
    }
    tempReservation.name = (s=="" ? reservations[idx].name : s);

    cout << "Phone: ";
    getline(cin, s);
    attempts = 0;
    while (!Validations::PhoneNumberValidaion(s) && s!="")
    {
        cout <<setColor(white, yellow)<< " Please enter a valid phone number "<<resetColor()<<endl;
        getline(cin, s);
        attempts++;
        if (attempts == 3)
        {
            cout<<setColor(white, red)<<" Too many invalid attempts, going back to menu "<<resetColor()<<endl;
            return;
        }
    }
    tempReservation.phone = (s=="" ? reservations[idx].phone : s);

    cout << "Email: ";
    getline(cin, s);
    attempts = 0;
    while (!Validations::EmailValidation(s) && s!="")
    { 
        cout <<setColor(white, yellow)<< " Please enter a valid Email "<<resetColor()<<endl;
        getline(cin, s);
        attempts++;
        if (attempts == 3)
        {
            cout<<setColor(white, red)<<" Too many invalid attempts, going back to menu "<<resetColor()<<endl;
            return;
        }
    }

    tempReservation.email = (s=="" ? reservations[idx].email : s);

    cout << "Check-in date: ";
    getline(cin, s);
    attempts = 0;
    while (!Validations::DatesValidations(s) && s!="")
    {
        cout <<setColor(white, yellow)<< " Please enter a valid date "<<resetColor()<<endl;
        getline(cin, s);
        attempts++;
        if (attempts == 3)
        {
            cout<<setColor(white, red)<<" Too many invalid attempts, going back to menu "<<resetColor()<<endl;
            return;
        }
    }
    tempReservation.check_in = (s=="" ? reservations[idx].check_in : s);


    cout << "Room category (S:SeaView, G:GardenView, L:LakeView): ";
    getline(cin, s);
    attempts = 3;
    while (!(s == "S" || s == "G" || s == "L" || s == "") && --attempts)
    {
        cout <<setColor(white, yellow)<< " Please Enter a valid input "<<resetColor()<<endl;
        getline(cin, s);
    }
    if(!attempts){
        cout<<setColor(white, red)<<" Too many invalid attempts, going back to menu "<<resetColor()<<endl;
        return;
    }
    if (s != "")
    {
        string xdddd = s=="S"?"SeaView":s=="L"?"LakeView":"GardenView";
        showAvailableRoomsByCategory(xdddd);
        cout<<"Choose room no: ";
        string roomNumber; 
        cin>>roomNumber;
        while(searchRoomByNumber(roomNumber)==-1 || rooms[searchRoomByNumber(roomNumber)].type!=xdddd){
            cout<<setColor(white,yellow)<<" Invalid room number or mismatching category "<<resetColor()<<endl;
            cout<<"Choose room no: ";
            cin>>roomNumber;
        }
        tempReservation.room_no = roomNumber;
    }

    cout << "Number of nights: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, s);
    attempts = 3;
    while(s!="" && !Validations::NightsValidation(s) && --attempts){
        cout <<setColor(white, yellow)<< " Please Enter a valid input "<<resetColor()<<endl;
        getline(cin, s);
    }
    if(!attempts){
        cout<<setColor(white, red)<<" Too many invalid attempts, going back to menu "<<resetColor()<<endl;
        return;
    }
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
        cout <<setColor(white, yellow)<< "Please enter a valid option "<<resetColor()<<endl;
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
            if (temp == -1)cout <<setColor(white, yellow)<< "Sorry this ID doesn't exist, please try again "<<resetColor()<<endl;

        } while (temp == -1);
        if(reservations[temp].confirm == "confirmed")
        {
            cout<<setColor(white, red)<< " Sorry, you can't edit a confirmed reservation " <<resetColor()<<endl;
            return -1;
        }

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
            if (temp == -1) cout <<setColor(white, red)<< "Sorry this room doesn't exist, please try again "<<resetColor()<<endl;

        } while (temp == -1);
        if(reservations[temp].confirm == "confirmed")
        {
            cout<<setColor(white, red)<< " Sorry, you can't edit an confirmed reservation " <<resetColor()<<endl;
            return -1;
        }
        EDIT(temp);
    }

    return 1;
}
