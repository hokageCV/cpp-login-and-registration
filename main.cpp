#include "login.h"
#include "registration.h"
#include "forgotPassword.h"
#include "main.h"

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





