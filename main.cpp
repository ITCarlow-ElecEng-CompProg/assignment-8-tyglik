/** OpAmp calculations
 *
 * Martina Nunvarova
 * 9/10/2017
 */

///includes
#include <iostream>
#include <math.h>
#include <windows.h>
#include <cstdio>

///namespace
using namespace std;



/// /////////////////////////////////////////////////////////////////
///                     Conversion to Polar
/// /////////////////////////////////////////////////////////////////

///the pointer using function - a calculation - straightforward
void convert2p(double x, double y, double *r, double *t)
{
    *r=sqrt(x*x+y*y);
    *t=atan2(y,x);          ///CAREFUL HERE! - atan would not be correct in the 2nd and 3rd quadrant! (* Mike Mahon)
    /// ATAN alternative
    // *t=atan(y/x);
    //if (x<0)
    //  *t+=180
}

///The user frontend function - as usual, nothing special to comment
void C2P()
{
    char input[100];
    double x,y;
    double r,t;

    system("cls");
    cout << "        Cartesian --> Polar " << endl <<endl;
    cout << "Please enter the X and Y coordinates, separated by space (i.e.: '17 3'<enter>):"<<endl;
    cin >> x >> y;
    convert2p(x,y,&r,&t);
    cout <<"Cartesian ["<< x<<","<<y<<"] converts to polar "<<r<<" < "<<t<<"r or "<<r<<" < "<<(t*180/M_PI)<<"o"<<endl<<endl<<"Please enter 'x' to return to main menu."<<endl;
//    fflush(stdout); //make sure it's displayed to user

//    fflush(stdin);
//    getchar();
    cin >> input;

}

/// /////////////////////////////////////////////////////////////////
///                     Conversion to Cartesian
/// /////////////////////////////////////////////////////////////////

///the pointer using function - maths calculation, straightforward
void convert2c(double r, double t, double *x, double *y)
{
    *x=r*cos(M_PI*t/180);
    *y=r*sin(M_PI*t/180);
}

///The user frontend function - as usual, nothing special to comment
void P2C()
{
    char input[100];
    double x,y;
    double r,t;

    system("cls");
    cout << "        Polar --> Cartesian" << endl <<endl;
    cout << "Please enter the R and Theta (in degrees) separated by space (i.e.: '25 45'<enter>):"<<endl;
    cin >> r >> t;
    convert2c(r,t,&x,&y);
    cout <<"Polar [ "<< r<<" < "<<t<<"o ] converts to cartesian ["<<x<<", "<<y<<"]"<<endl<<endl<<"Please enter 'x' to return to main menu."<<endl;
//    fflush(stdout); //make sure it's displayed to user

//    fflush(stdin);
//    getchar();
    cin >> input;

}

/// /////////////////////////////////////////////////////////////////
///                             Main function
/// /////////////////////////////////////////////////////////////////
int main()
{
    char choice[100];
    do {
        ///present the menu
        system("cls");
        cout << "        Cartesian <==> Polar " << endl <<endl;
        cout << "'p'     ::     convert to Polar coordinates"<<endl
             << "'c'     ::     convert to Cartesian coordinates"<<endl
             << "'q'     ::     to QUIT"<<endl<<endl
             << "Please Enter Your Choice: "<<endl;
        ///wait for choice
        cin >> choice;
        switch ( choice[0] ) {
            case 'p': C2P(); break;         ///convert to POLAR
            case 'c': P2C(); break;         ///convert to CARTESIAN
            case 'q': break;                ///EXIT
            default:
                cout << "Invalid choice, try again"<<endl;
                Sleep(1500);

        }
    } while (choice[0] != 'q');             ///repeat until q is pressed
    return 0;
}
