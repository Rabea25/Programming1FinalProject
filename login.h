#include <bits/stdc++.h>
#include "structs.h"
#include <conio.h> //for getch
#include "colors.h"

using namespace std;

int loginAttempts = 3;

bool login(vector<user> users){
    loginAttempts--;
    string username="", pw="";
    char c;
    cout<<"Enter username: ";
    cin.ignore();
    getline(cin, username);
    cout<<"Enter password: ";
    while((c=_getch())!='\r'){
        if(c=='\b'){
            if(pw.size()>0){
                cout<<"\b \b"; //move back, print space, move back again
                pw.pop_back();
            }
            continue;
        }
        pw+=c;
        cout<<"*";
    }
    cout<<endl;
    bool valid=0;
    for(user i:users) {if(i.pw == pw && i.username == username) valid = 1;}
    if(valid){
        cout<<endl;
        cout<<setColor(brightGreen, black)<<"---Logging In!---"<<resetColor()<<endl;
        cout<<setColor(brightGreen, grey)<<"Login successful!"<<resetColor()<<endl<<endl;
        return 1;
    }
    else{
        if(loginAttempts==0){
            cout<<setColor(brightRed, black)<<"You have exceeded the maximum number of login attempts. Goodbye!"<<resetColor()<<endl;
            exit(0);
        }
        cout<<"Invalid username or password. You have "<<loginAttempts<<" attempts left, do you wish to try again?"<<endl;
        cout<<"[1] Yes"<<endl;
        cout<<"[2] Go back to main menu"<<endl;
        int opt;
        cin>>opt;
        return opt==1 ? login(users) : 0;
    }
}
