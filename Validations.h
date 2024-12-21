#pragma once
#include <iostream>
#include <string>
#include <regex>
using namespace std;

class Validations
{
public:

    //For ppl to reserve a room:
	static bool NameValidation(string name)
	{
		for (int i = 0; i < name.length(); i++) {
            if (!isalpha(name[i]) && name[i] != ' ' && name[i] != '-')
            {
                return 0;
            }
        }
        return 1;
	}

    static bool NationalIDValidation(string ID)
    {
        if (ID.length() != 14)
        {
            return 0;
        }
        for (int i = 0; i < ID.length(); i++) {
            if (!isdigit(ID[i])) {

                return 0;
            }
        }
        return 1;

    }

    static bool EmailValidation(string email)
    {
        const regex pattern(R"(^[a-zA-Z0-9._%+-]+@gmail\.com$)");
        
        return regex_match(email, pattern);
    }

    static bool PhoneNemberValidaion(string PhoneNumber)
    {
        if (PhoneNumber.length() < 10 || PhoneNumber.length() > 15)
        {
            return 0;
        }

        for (int i = 0; i < PhoneNumber.length(); i++) {
            if (!isdigit(PhoneNumber[i])) {

                return 0;
            }
        }
        return 1;
    }
    
    static bool DatesValidations(string date)
    {
        char Date[11]; //El 11 3shan el null fel a5er beta3 strcpy
        strcpy(Date, date.c_str());


        char* dayString = strtok(Date, "-");
        char* monthString = strtok(nullptr, "-");
        char* yearString = strtok(nullptr, "-");

        if (!dayString || !monthString || !yearString) return 0;


        int day = stoi(dayString);
        int month = stoi(monthString);
        int year = stoi(yearString);

        if (day > 30 || day < 1)
            return 0;

        if (month > 12 || month < 1)
            return 0;

        if (year < 2025)
        {
            if (day > 29 && day < 31 && month == 12 && year == 2024)
                return 1;
            return 0;
        }

        return 1;

    }
    

};
