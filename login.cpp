#include "login.h"
#include "main.h"

void login(){
    int flag=0;
    string userID;
    string userPassword;
    string existingID;
    string existingPassword;
    system("cls");

    cout << "\t enter user id : " ;
    cin >> userID ;
    cout << "\t enter password : " ;
    cin >> userPassword ;

    ifstream input("records.txt");

    while(input >> existingID >> existingPassword){
        if( existingID == userID && existingPassword == userPassword ){
            flag=1;
            system("cls");
        }
    }
    input.close();
    if(flag==1) {
        cout << userID << "\n login successful  " << '\n';
        main();
    }
    else{
        cout << "ERROR \n  check username and password " << '\n';
        main();
    }
}
