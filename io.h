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
    else cout<<setColor(white, red)<<"Error opening users.txt file."<<resetColor()<<endl;
    file.close();

    return users;
}

void save(vector<reservation> reservations, vector<room> rooms){
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
}