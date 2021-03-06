/*
 * 
 * Title: A KI Simulator
 * Author: Maik
 * Date: 2011/28/12
 * 
 * Depends = ('person.class.h','ki.ns.h')
 */

//#include "std_lib_facilites.h"
#include <iostream>

#include "person.class.h"
#include "ki.ns.h"

//using namespace std;

void fillIn(PersonNS::Person& person, std::string& firstName, std::string& age);
void kiInit(PersonNS::Person& person);
void kiQuestion(PersonNS::Person& person, std::string& frage);
void kiLoop(PersonNS::Person& person, std::string& frage);

int main()
{
    PersonNS::Person person;
    //Variablen
    const std::string line = "=============================="; // Trennlinie
    char datacheck; // Use ' ' instead of " "
    
    std::string age;
    std::string firstName;
    std::string frage;
    
    // IO
    std::cout << "Getting Data" << std::endl << line << std::endl;
    
    std::cout << "Your First Name: "; std::cin >> firstName; // Um den Vornamen zu bekommen
    std::cout << "Your age: "; std::cin >> age; // Um das Alter zu bekommen | Berechne ich spaeter anhand des Geburtsjahrs
    std::cout << std::endl;
    
    std::cout << "Data Check" << std::endl << line << std::endl;
    
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Age: " << age << std::endl;
    
    std::cout << std::endl << line << std::endl;
    std::cout << "All right\?[y/n]"; std::cin >> datacheck; // Nutzerueberpruefung
    
    if (datacheck == 'y' && age.length() <= 2)
    {
        
        fillIn(person, firstName, age);
        
        // KI
        std::cout << std::endl << line << std::endl;
        kiInit(person);
        
        while (true)
        {
            try {
                
                kiQuestion(person, frage);
            }
            catch (int e) {
                break;
            }
        }
        
        return 0;
    }
    else
    {
        return 1;
    }
    
    
    return 0;
}

void fillIn(PersonNS::Person& person, std::string& firstName, std::string& age)
{
    person.setAttribute(1, firstName);
    person.setAttribute(2, age);
}

void kiInit(PersonNS::Person& person)
{
    // Get Name
    std::string name = person.getAttribute(1);
    std::string text = KI::Welcome(name);
    std::cout << text << std::endl;
}

void kiLoop(PersonNS::Person& person, std::string& frage)
{
    person.setAttribute(3, frage);
    std::cout << KI::GetSimpleAnswer(person.getAttribute(3)) << std::endl;
}

void kiQuestion(PersonNS::Person& person, std::string& frage)
{
    std::cout << "<< "; 
    std::cin.ignore();
    getline(std::cin, frage, '\n'); 
    if (frage != "")
    {
        kiLoop(person, frage);
        frage = "";
    } else 
    {
        // Do nothing
        throw 1;
    }
}
