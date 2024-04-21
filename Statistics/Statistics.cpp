
#include "Statistics.h"
Statistics* Statistics::Instance= nullptr;
Statistics::Statistics() {}

Statistics *Statistics::getInstance() {
if(Instance== nullptr){
Instance=new Statistics;
}
    return Instance;
}
void Statistics::isEligible(string DOB) {
    int count=0;
    json data;
    ifstream file("persons_data.json");
    if (!file.is_open()) {
        cerr << "Error opening file!"  << std::endl;
        return;
    }
    file>>data;
int ttlcount=0;
    int dob;
    for (auto& person: data["Persons"]){
        for (auto& details:person.items()){
            auto& personData=details.value()[0];
            string  dobString = personData["DOB"];
             dob = stoi(dobString);
             if (stoi(DOB)-dob>=18){
                count++;
            }
            ttlcount++;
        }
    }

    cout<<"The Total number of Persons eligible for year "<<stoi(DOB)<<" are :" <<count<<endl;
    cout<<"Total Persons: "<<ttlcount<<endl;
    file.close();
}
void Statistics::get_gender_info() {
    int maleCount=0,femaleCount=0,otherGender=0,ttlcount=0;
    string GENDER;
    json data;

    ifstream file("persons_data.json");
    if (!file.is_open()) {
        cerr << "Error opening file!"  << std::endl;
        return;
    }
    file>>data;
    for (auto& person: data["Persons"]){
        for (auto& details:person.items()) {
            auto &personData = details.value()[0];
             GENDER =personData["Gender"];
            if(GENDER=="M"){
                maleCount++;
            } else if(GENDER=="F"){
                femaleCount++;
            }
            else {
                otherGender++;
            }
            ttlcount++;
        }
    }
    cout<<"Gender Stats :"<<endl;
    cout<<"Total Persons: "<<ttlcount<<endl;
    cout<<"Male Voters  : "<<maleCount<<endl;
    cout<<"Female Voters: "<<femaleCount<<endl;
    cout<<"Khusre/Trans : "<<otherGender<<endl;

}