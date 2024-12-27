#include <bits/stdc++.h>
#include "structs.h"
#include "colors.h"
using namespace std;

vector<user> loadUsers(){
    vector<user> users;
    ifstream file("users.txt");
    if(file.is_open()){
        string line;
        while(getline(file, line)){
            string tmp="";
            user u;
            for(char c:line){
                if(c==' '){
                    u.username = tmp;
                    tmp = "";
                }
                else tmp+=c;
            }
            u.pw = tmp;
            users.push_back(u);
        }
    }
    else cout<<setColor(white, red)<<" Error opening users.txt file. "<<resetColor()<<endl;
    file.close();

    return users;
}

vector<reservation> loadReservations(){
    vector<reservation> reservations;
    ifstream file("Reservation.txt");
    if(file.is_open()){
        string line;
        while(getline(file, line)){
            string tmp="";
            reservation r;
            int i=0;
            for(char c:line){
                if(c==','){
                    if(i==0){r.id = tmp;tmp = "";i++;}
                    else if(i==1){r.room_no = tmp;tmp = "";i++;}
                    else if(i==2){r.confirm = tmp;tmp = "";i++;}
                    else if(i==3){r.name = tmp;tmp = "";i++;}
                    else if(i==4){r.nat_id = tmp;tmp = "";i++;}
                    else if(i==5){r.nights = tmp;tmp = "";i++;}
                    else if(i==6){r.check_in = tmp;tmp = "";i++;}
                    else if(i==7){r.email = tmp;tmp = "";i++;}
                }
                else tmp+=c;
            }
            r.phone = tmp;
            resID = max(resID, stoll(r.id)+1);
            reservations.push_back(r);
        }
    }
    else cout<<setColor(white, red)<<"Error opening reservations.txt file."<<resetColor()<<endl;
    file.close();

    return reservations;
}

vector<room> loadRooms(){
    vector<room> rooms;
    ifstream file("rooms.txt");
    if(file.is_open()){
        string line;
        while(getline(file, line)){
            string tmp="";
            room r;
            int i=0;
            for(char c:line){
                if(c==' '){
                    if(i==0){r.room_no = tmp;tmp = "";i++;}
                    else if(i==1){r.status = tmp;tmp = "";i++;}
                    else if(i==2){r.type = tmp;tmp = "";i++;}
                }
                else tmp+=c;
            }
            r.price = tmp;

            rooms.push_back(r);
        }
    }
    else cout<<setColor(white, red)<<"Error opening reservations.txt file."<<resetColor()<<endl;
    file.close();

    return rooms;
}

bool save(){

    cout<<endl<<"Save Changes?"<<endl;
    cout<<"[1] "<<setColor(green,black)<<"Save"<<resetColor()<<endl;
    cout<<"[2] "<<setColor(red,black)<<"Cancel"<<resetColor()<<endl;
    int option;
    cin>>option;
    while(option != 1 && option != 2)
    {
        cout<<"Please enter a valid input"<<endl;
        cin>>option;
    }
    if(option == 2)
    {
        reservations = reservationsOG;
        roomsOG = rooms;
        return 0;
    }


    ofstream file("Reservation.txt");
    if(file.is_open()){
        for(reservation r:reservations){
            file<<r.id<<","<<r.room_no<<","<<r.confirm<<","<<r.name<<","<<r.nat_id<<","<<r.nights<<","<<r.check_in<<","<<r.email<<","<<r.phone<<endl;
        }
    }
    else cout<<setColor(white, red)<<"Error opening Reservation.txt file."<<resetColor()<<endl;
    file.close();

    ofstream file2("rooms.txt");
    if(file2.is_open()){
        for(room r:rooms){
            file2<<r.room_no<<" "<<r.status<<" "<<r.type<<" "<<r.price<<endl;
        }
    }
    else cout<<setColor(white, red)<<"Error opening rooms.txt file."<<resetColor()<<endl;

    reservationsOG = reservations;
    roomsOG = rooms;
    return 1;
}

//void cancelSave() 7atetha fel save function w 5las
//{
//    reservations = reservationsOG;
//    roomsOG = rooms;
//}
