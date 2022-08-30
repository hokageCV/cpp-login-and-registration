#include "forgotPassword.h"
#include "main.h"

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
