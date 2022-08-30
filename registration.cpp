#include "registration.h"
#include "main.h"

void registration(){
    string registeredID;
    string registeredPassword;
    string existingID;
    string existingPassword;
    system("cls");

    cout << "\t enter user id : " ;
    cin >> registeredID ;
    cout << "\t enter password : " ;
    cin >> registeredPassword ;

    ofstream f1("records.txt", ios::app);  //ofstream kyuki file me write karna hai ; ios=input output stream; app= append mode
    f1<< registeredID << ' ' << registeredPassword << '\n' ;
    f1.close();
    system("cls");

    cout << "\n registration successful " << '\n';
    main();
}
