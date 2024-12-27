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
	//if(!validateDate(date)){
	//cout<<endl<<setColor(white, yellow)<<"Invalid Date or incorrect format"<<resetColor()<<endl<<endl;
	//	return;
	//}


	vector<reservation> report;

	for(reservation i:reservations){
		if(i.check_in == date && i.confirm == "confirmed") report.push_back(i);
	}

	if(!report.size()){
		cout<<endl<<setColor(white, yellow)<<"No reservations found on "<<date<<resetColor()<<endl<<endl;
		return;
	}

	cout<<"Reservations on "<<date<<":"<<endl<<endl;
	cout<<"ID\tRoom\tStatus\t\tDate\t\tNo of nights\tName\t\tNational ID\t\tE-mail\t\t\tPhone"<<endl;
	for(reservation r:report){
		cout<<r.id<<"\t"<<r.room_no<<"\t"<<r.confirm<<"\t"<<r.check_in<<"\t"<<r.nights<<"\t\t"<<r.name<<"\t"<<r.nat_id<<"\t\t"<<r.email<<"\t"<<r.phone<<endl;
	}
	cout<<endl;
	return;

}