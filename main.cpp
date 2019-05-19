/*=======================================================
This application is to be used to sort a list of names
from a .txt file, sort it and export to a .txt file
created by Rahasano Sitorus for PT. KST
=========================================================*/

//Include libraries
#include <iostream> //input output console
#include <string>  //use of String
#include <fstream> //read-write file
#include <vector>
#include <algorithm> //included for std::sort

using namespace std;

char loadByFirstName(char orgFileName[50]);
char loadByLastName(char orgFileName[50]);

//main function as to start application
int main()
{
    string input;
    char inputFileName[50]; //file name no more than 50 chars

    //console message to choose from
    cout << "Name Sorting Command Line" << endl;
    cout << "===================================" << endl;
    cout << "     Please enter option 1 or 2    " << endl;
    cout << "    1 - Sort Names by First Name   " << endl;
    cout << "    2 - Sort Names by Last Name    " << endl;
    cout << "    0 - To Exit Application        " << endl;
    cout << "===================================" << endl;
    cout << "Option: ";
    cin >> input;
    cout << endl;

    //There are 3 options
    //If selection is 0, exit application
    if (input=="0")
    {
        exit(0);
    }
    //if selection is 1, then input Filename
    else if (input=="1")
    {
        cout << "You have selected to sort names in alphabetical order by First Name." << endl;
        cout << "Please type the file name." << endl;
        cout << "File name: " ;
        cin.ignore();
        cin.getline(inputFileName,50); //to function where the filename has space (" ") character.
        cout << endl;
        loadByFirstName(inputFileName);
    }
    //if selection is 2, then input Filename
    else if (input=="2")
    {
        cout << "You have selected to sort names in alphabetical order by Last Name" << endl;
        cout << "Please type the file name." << endl;
        cout << "File name: " ;
        cin.ignore();
        cin.getline(inputFileName,50);//to function where the filename has space (" ") character.
        cout << endl;
        loadByLastName(inputFileName);
    }
    //make sure the selection is correct.
    else
    {
        main();
    }

    return 0;
}

//
//Reading TXT file for option 1
//
char loadByFirstName(char orgFileName[50])
{
    cout << "Reading File: " << orgFileName << endl;
    // Empty vector holding all names from file
    vector<string> names;
    ifstream loader(orgFileName);

    //creating new file ready
    ofstream newFile;
    newFile.open ("sorted-names-list.txt");

    //housekeeping, if file not found. show message, end.
    if(!loader.is_open())
    {
        cout << "==========================================" << endl;
        cout << " Unable to open file " << orgFileName << endl;
        cout << "==========================================" << endl;
    }
    else
    {
        string word;
        while(getline(loader, word))
        names.push_back(word);

        //sort names in alphabetical order by first name
        sort(names.begin(), names.end());
        for (size_t i = 0; i < names.size(); i++)

        //write the names while sorting
        newFile << names[i] << endl;
        newFile.close();

        //end message
        cout << "====================================================" << endl;
        cout << "Names are sorted and placed in sorted-names-list.txt" << endl;
        cout << "                Process completed.                  " << endl;
        cout << "====================================================" << endl;
    }

    return 0;
}

//
//Reading TXT file for option 2
//
char loadByLastName(char orgFileName[50])
{
    cout << "Reading File: " << orgFileName << endl;
    // Empty vector holding all names from file
    vector<string> names;
    ifstream loader(orgFileName);

    //creating new file ready
    ofstream newFile;
    newFile.open ("sorted-names-list.txt");

    //housekeeping, if file not found. show message, end.
    if(!loader.is_open())
    {
        cout << "==========================================" << endl;
        cout << " Unable to open file " << orgFileName << endl;
        cout << "==========================================" << endl;
    }
    else
    {
        string word;
        //int idx;
        while(getline(loader, word))
        names.push_back(word);

        //sort names in alphabetical order by first name
        sort(names.begin(), names.end());
        for (size_t i = 0; i < names.size(); i++)
        {
           newFile << names[i] << endl;


        }



            //newFile << names[i] << endl;

        //write the names while sorting

        newFile.close();

        //end message
        cout << "====================================================" << endl;
        cout << "Names are sorted and placed in sorted-names-list.txt" << endl;
        cout << "                Process completed.                  " << endl;
        cout << "====================================================" << endl;
    }

    return 0;
}
