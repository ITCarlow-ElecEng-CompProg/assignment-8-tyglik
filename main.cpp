/** Lab08 - Inverting and non-inverting operational amplifier
 *
 * Martina Nunvarova
 * 26/10/2017
 */

///Preprocessor includes
#include <iostream>
#include <stdio.h>
#include <windows.h>

///Namespace
using namespace std;

///define structures, don't like many parametres into the functions, too much writing.
struct  strOpAmpParam {
            double Vcc,Vee,Vin,R1in,R2f;
        };
struct  strOpAmpResult {
            double Av,Vout;
        };



///Prints the main menu (UI)
void printMenu ()
{
    cout << "Op Amp Calculator" <<endl <<endl;

    cout    <<"a/i    - Inverting amplifier calculations" <<endl
            <<"b/n    - Non-inverting amplifier calculations"<<endl
            <<"q/x/e  - QUIT"<<endl<<endl;
    cout <<"Please make your choice: ";
    fflush(stdout);
}

///getKey - read keyboard input, return the first letter entered converted to lowercase
char getKey(void)
{
    char key[10]; ///allow multiple character input
    fflush(stdout);
    fflush(stdin);
    cin >> key;
    return tolower(key[0]);
}

///Input:
///     prompt - the text to be displayed
///     zeroOptions - 0=no option, only positive value; 1=Zero and positive; 2=Any real number
double getDoubleValue(string prompt, int zeroOptions)
{
    double output;
    char outOK;

    do {
        outOK=1;
        cout << prompt;
        fflush(stdout);
        fflush(stdin);
        cin>>output;
        if (output<0) {
            if (zeroOptions<2)
                outOK=0;
        } else if (output==0) {
            if (zeroOptions<1)
                outOK=0;
        }
        if (!outOK)
            cout << "Illegal input. ";
    } while (!outOK);
    return output;
}

///common maths in separate function, why do the same thing twice?
void calcAmpOutAndRailCheck(strOpAmpParam opp, strOpAmpResult *opr)
{
    opr->Vout=opr->Av*opp.Vin;
    if (opr->Vout>opp.Vcc)
        opr->Vout=opp.Vcc;
    if (opr->Vout<opp.Vee)
        opr->Vout=opp.Vee;
}

///calculate the inverting op Gain
void calcInvertingMath(strOpAmpParam opp, strOpAmpResult *opr)
{
    (*opr).Av=-opp.R2f/opp.R1in;
    calcAmpOutAndRailCheck(opp,opr);
}

///calculate the noninverting op Gain
void calcNoninvertingMath(strOpAmpParam opp, strOpAmpResult *opr)
{
    (*opr).Av=1+opp.R2f/opp.R1in;
    calcAmpOutAndRailCheck(opp,opr);
}

///inverting opAmp UI
void calcInverting ()
{
    strOpAmpParam opPar;
    strOpAmpResult opRes;
    system("cls");
    cout << endl<<"####################################################################################"<<endl
        << "                                 INVERTING Amplifier"<<endl
        << "####################################################################################"<<endl<<endl<<endl;
    do {
        opPar.Vcc=getDoubleValue("Please enter the value Vcc: ",0);
        opPar.Vee=getDoubleValue("Please enter the value Vee: ",2);
        opPar.Vin=getDoubleValue("Please enter the value Vin: ",2);
        opPar.R1in=getDoubleValue("Please enter the value Rin: ",0);
        opPar.R2f=getDoubleValue("Please enter the value Rf:  ",0);

        calcInvertingMath(opPar,&opRes);

        cout << "####################################################################################"<<endl;
        cout << "#     Gain (Av) = "<<opRes.Av<<"     ###      Vout = "<<opRes.Vout<<endl;
        cout << "#####################################################################################"<<endl<<endl;

        cout << "Enter 'q' to return to main menu, anything else to calculate with different parametres!"<<endl<<"Your choice: ";
    } while (getKey()!='q');
}

///non-inverting opAmp UI
void calcNoninverting()
{
    strOpAmpParam opPar;
    strOpAmpResult opRes;
    system("cls");
    cout << endl<<"####################################################################################"<<endl
        << "                                NON-INVERTING Amplifier"<<endl
        << "####################################################################################"<<endl<<endl<<endl;
    do {
        opPar.Vcc=getDoubleValue("Please enter the value Vcc: ",0);
        opPar.Vee=getDoubleValue("Please enter the value Vee: ",2);
        opPar.Vin=getDoubleValue("Please enter the value Vin: ",2);
        opPar.R1in=getDoubleValue("Please enter the value R1:  ",0);
        opPar.R2f=getDoubleValue("Please enter the value R2:  ",0);

        calcNoninvertingMath(opPar,&opRes);

        cout << "####################################################################################"<<endl;
        cout << "#     Gain (Av) = "<<opRes.Av<<"     ###      Vout = "<<opRes.Vout<<endl;
        cout << "#####################################################################################"<<endl<<endl;

        cout << "Enter 'q' to return to main menu, anything else to calculate with different parametres!"<<endl<<"Your choice: ";
    } while (getKey()!='q');
}

///The main loop
int main()
{
    char key;
    do {
        printMenu();
        key=getKey();
        switch (key) {
            case 'a':
            case 'i':
                calcInverting();
                break;
            case 'b':
            case 'n':
                calcNoninverting();
                break;
            case 'q':
            case 'e':
            case 'x':
                key='q';
                break;
            default:
                cout <<"This in an illegal option!"<<endl;
                Sleep(2000);
        }
        system("cls");
    } while (key!='q');

    return 0;
}
