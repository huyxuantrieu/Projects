/* gymMembership.cpp : This file cwill print out the pricing information for the gym including discounts. 
it will prompt the user to type in if they want to calculate the gym cost or quit the propgram. After storing and calculating, it will re-prompt the user until it is told to quit. */
//Huy trieu



using namespace std;
#include <cctype>
#include <iostream>


void information()
{
    cout << "PRICING INFORMATION: \n" << "- Membership is $50/mo" << endl << "- Personal training sessions are $30 each\n" << endl <<
        "DISCOUNTS BELOW: \n" << "- Senior Citizens receives a 30 % discount\n" << "- Members who purchase 12 or more months will receive a 15% discount \n" << "- Members who purchases 6 or more than each session is 20% off \n \n";
}; 

void getInfo(bool &senior, int &months, int &personal)// this will store values on the user to see if they qualify for discounts and pricing.
{
    char ageChoice;

    do
    {
    cout << "Please enter y or n. Are at least 65 years old? (y/n) \n";
    cin >> ageChoice;
    } while ((ageChoice != 'n') && (ageChoice != 'y'));

    if (ageChoice == 'y')
    {
        senior = true;
    }
    else 
    {
        senior = false;
    }
    cout << "How many Months of Membership do you want? \n";
    cin >> months;
    cout << "How many Personal training sessions? \n ";
    cin >> personal;
}


double calcCost(bool senior, int months, int personal) //this will use the information stored to calculate the price of the gym membership and the training sessions.
{
    double total;
    double seniorTotal;
    double monthsTotal;
    double personalTotal;

    if(senior == true)
    {
        seniorTotal = .7;
    }
    else
    {
        seniorTotal = 1;
    }

    if (months >= 12)
    {
        monthsTotal = (months * 50 * .85);
    }
    else
    {
        monthsTotal = (months * 50);
    }

    if (personal > 5)
    {
        personalTotal = (personal * 30 * .8);
    }
    else
    {
        personalTotal = (personal * 30);
    }

    total = seniorTotal * (monthsTotal + personalTotal);
    cout << "$" << total << " is the cost of the membership." << endl;
    return total;
    
}

int main()
{
    char response;
    bool senior;
    int months, personal;

    information(); 
    do
    {
        cout << "Type 1 of the following letters: " << endl << "a : Calculate membership costs" << endl << "b : Quit this program" << endl;
        cin >> response;
        tolower(response);

        if (response == 'a') 
        {
        
            cout << "You chose reponse A." << endl;
            getInfo(senior, months, personal);
            calcCost(senior, months, personal);
        }
        else if (response == 'b')
        {
            cout << "You chose option b. This program will quit." <<  endl;
            break;
        }
        else
        {
            cout << "Please enter a valid input" << endl;
        }
    } while ((response = 'a')); 


}
