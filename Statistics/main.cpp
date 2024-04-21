#include <iostream>
#include "Statistics.h"
using namespace std;
 int main(){
     cout<<"_______________________________ \n"
           " Welcome To Statistics Section\n"
           "_______________________________\n"
           "Choose An Option:\n1.Check Voter Eligibility\n2.Gender Statistics\n";
     Statistics *stat=Statistics::getInstance();
     int choice=0;
     cin>>choice;
     switch (choice) {
         case 1: {
             string year ;
             cout << "Enter the Year For Which You Want to Check the Vote Eligibility :";
             cin >> year;
             stat->isEligible(year);
             break;
         }
         case 2:
             stat->get_gender_info();
         break;
         default:
             cerr<<"Please Choose A Valid Option!\nExiting...\n";
             break;

     }



     return 0;
 }