#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void login();
void registration();
void forgotPassword();

int main(){
    int choice;
    // menu
    cout << "\t ____________________________________" << "\n";
    cout << "\t      Login page me aapka swagat hai " << "\n";
    cout << "\t _____________  Menu      ___________" << "\n";
    cout << '\n';
    cout << "\t Press 1 to Login  " << '\n';
    cout << "\t Press 2 to Register  " << '\n';
    cout << "\t Press 3 to find password  " << '\n';
    cout << "\t Press 4 to exit " << '\n';
    cout << "\t Enter your choice : " ;
    cin >> choice ;

    switch(choice){
        case 1:
            login();
            break;
        case 2:
            registration();
            break;
        case 3:
            forgotPassword();
            break;
        case 4:
            cout << "Dhanyawad  " << '\n';
            break;
        default:
            system("cls");
            cout << "padhana aata hai, right?" << '\n';
            main();
    }

    return 0;
}

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

void forgotPassword(){
    int option;
    system("cls");

    cout << "Press 1 to search password by user ID " << '\n';
    cout << "Press 2 to go back to main menu " << '\n';
    cout << "Enter choice : " ;
    cin >> option;

    switch(option){
        case 1 : {
            int flag=0;
            string searchedID;
            string existingID;
            string existingPassword;

            cout << " enter user ID : " ;
            cin >> searchedID ;

            ifstream f2("records.txt");
            while(f2>> existingID >> existingPassword){
                if(existingID == searchedID) flag = 1;
            }
            f2.close();

            if(flag==1){
                cout << "\naccount found" << '\n';
                cout << "password is : " << existingPassword << '\n';
                main();
            }
            else{
                cout << "account not found.  user id toh nahi bhul gaye ?" << '\n';
                main();
            }
            break;
        }

        case 2 :
            main();
        default :
            cout << "wrong choice! try again" << '\n';
            forgotPassword();

    }


}
