#include <bits/stdc++.h>
#include "structs.h"
#include "colors.h"
#include "search.h"
#pragma once

using namespace std;

void reservationReport(){
	cout<<endl<<"Reservation Report:"<<endl;
    cout<<"[0] "<<setColor(red, black)<<"Back"<<resetColor()<<endl;
    cout<<"[1] Continue"<<endl;
    string O;
    cin>>O;
    while( !( O == "0" || O == "1" ) )
    {
        cout<<"Please enter a valid option"<<endl;
        cin>>O;
    }
    if(O == "0")return;

	cout<<"Enter the date for the report (dd-mm-yyyy): ";
	string date;
	cin>>date;
	int attempts=3;
    while(!Validations::DatesValidations(date) && attempts--){
        cout<<setColor(white,yellow)<<" Invalid date "<<resetColor()<<endl<<"Please enter date in the format DD-MM-YYYY: ";
        cin>>date;
    }
    if(!attempts){
        cout<<setColor(white, red)<<" Too many invalid attempts, going back to menu "<<resetColor()<<endl;
        return;
    }

	vector<reservation> report;

	for(reservation i:reservations){
		if(i.check_in == date && i.confirm == "confirmed") report.push_back(i);
	}

	if(!report.size()){
		cout<<endl<<setColor(white, yellow)<<"No reservations found on "<<date<<resetColor()<<endl<<endl;
		return;
	}

	cout<<"Reservations on "<<date<<":"<<endl<<endl;
	cout<<left;
    cout<<setw(20)<<"ID"<<setw(20)<<"Room NO"<<setw(20)<<"Status"<<setw(20)<<"Date"<<setw(20)<<"NO of nights"
        <<setw(20)<<"Name"<<setw(20)<<"National ID"<<setw(20)<<"E-Mail"<<setw(20)<<"Phone"<<endl;
	for(reservation r:report){
	    cout<<setw(20)<<r.id<<setw(20)<<r.room_no<<setw(20)<<r.confirm<<setw(20)<<r.check_in<<setw(20)<<r.nights
        <<setw(20)<<r.name<<setw(20)<<r.nat_id<<setw(20)<<r.email<<setw(20)<<r.phone<<endl;
	}
	cout<<endl;
	return;
}
