#pragma once
#include "clsBankClien.h"
#include "clsScreen.h"
#include <iomanip>

class clsShowAllClientsScreen : protected clsScreen
{
private:

    static void _PrintClientData(clsBankClient Client)
    {
        cout << setw(8) << left << "" << "| " << left << setw(20) << Client.AccountNumber();
        cout  << "| " << left << setw(15) << Client.FullName();
        cout  << "| " << left << setw(12) << Client.Phone;
        cout  << "| " << left << setw(20) << Client.Email;
        cout  << "| " << left << setw(12) << Client.PinCode;
        cout  << "| " << left << setw(10) << Client.AccountBalance;
    }

public:

    static void ShowClientsList()
    {
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        string Titel = "\t Clients List Screen";
        string SubTitel = "\t Client List (" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(Titel, SubTitel);
        cout << setw(8) << left << "" << "\n\t______________________________________";
        cout << "_____________________________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(20) << "Account Number";
        cout << "| " << left << setw(15) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(12) << "Pin Code";
        cout << "| " << left << setw(10) << "Balance";
        cout << setw(8) << left << "" << "\n\t______________________________________";
        cout << "_____________________________________________________________\n";

        if (vClients.size() == 0)
            cout << "\n\n\t\t No Clients Availble";

        for (clsBankClient Client : vClients)
        {
            _PrintClientData(Client);
            cout << endl;
        }
        cout << setw(8) << left << "" << "\n\t____________________________________";
        cout << "________________________________________________________________\n";
    }
};

