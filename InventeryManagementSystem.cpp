#include <iostream>
#include <cctype>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{
    cout << "|--------------------------------------------------------------------------------------------------------------------|" << endl;
    cout << "|--------------------------------------------------------------------------------------------------------------------|" << endl;

    cout << "|                                                                                                                    |" << endl;
    cout << "|                                    WELCOME TO INVENTORY MANAGEMENT SYSTEM                                          |" << endl;
    cout << "|                                                                                                                    |" << endl;

    cout << "|--------------------------------------------------------------------------------------------------------------------|" << endl;
    cout << "|--------------------------------------------------------------------------------------------------------------------|" << endl;

    char choice = 'Y';

    int order;

    int num1 = 0, num2 = 0, num3 = 0;
    int sentinel = 0;
    // const double UnitPrice1,UnitPrice2,UnitPrice3;
    double unitPrice[3] = {0, 0, 0};
    double AmountofSale1 = 0, AmountofSale2 = 0, AmountofSale3 = 0;
    int stock[3] = {0, 0, 0};
    // int stock1, stock2, stock3;
    int input_discount;
    int percent_discount;
    double net_total;
    double sum_total = net_total;
    int gst_permission;
    double gst = 5;

    cout << "#################### ORDERING SYSTEM ####################\n\n";
    cout << "\tPRODUCTS" << "\t" << "STOCK" << "\t" << "UNIT PRICE" << endl;
    cout << "\t[1] Apple\t" << stock[0] << "\t" << unitPrice[0] << endl;
    cout << "\t[2] Oranges\t" << stock[1] << "\t" << unitPrice[1] << endl;
    cout << "\t[3] Mangoes\t" << stock[2] << "\t" << unitPrice[2] << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "Enter the stock available for product: " << i + 1 << endl;
        cin >> stock[i];
        cout << "Enter the unit  price of product: " << i + 1 << endl;
        cin >> unitPrice[i];
    }

    cout << "#################### ORDERING SYSTEM ####################\n\n";
    cout << "\tPRODUCTS" << "\t" << "STOCK" << "\t" << "UNIT PRICE" << endl;
    cout << "\t[1] Apple\t" << stock[0] << "\t" << unitPrice[0] << endl;
    cout << "\t[2] Oranges\t" << stock[1] << "\t" << unitPrice[1] << endl;
    cout << "\t[3] Mangoes\t" << stock[2] << "\t" << unitPrice[2] << endl;

    while (order != sentinel)
    {
        cout << "\nPlease choose your order!:\n";
        cin >> order;
        switch (order)
        {

        case 0:
            break;

        case 1:

            cout << "\nHow Many Apple?:\n";
            cin >> num1;
            if (num1 > stock[0])
            {
                cout << "=====NOT ENOUGH STOCK=====" << endl;
                cout << "Plz order below: " << stock[0] << endl;

                break;
            }
            stock[0] = stock[0] - num1;
            AmountofSale1 = unitPrice[0] * num1;
            break;

        case 2:
            cout << "\nHow Many Oranges?:\n";
            cin >> num2;
            if (num2 > stock[1])
            {
                cout << "=====NOT ENOUGH STOCK=====" << endl;
                cout << "Plz order below: " << stock[1] << endl;
                break;
            }
            stock[1] = stock[1] - num2;
            AmountofSale2 = unitPrice[1] * num2;
            break;

        case 3:
            cout << "\nHow Many Mangos?:\n";
            cin >> num3;
            if (num3 > stock[2])
            {
                cout << "=====NOT ENOUGH STOCK=====" << endl;
                cout << "Plz order below: " << stock[2] << endl;

                break;
            }
            stock[2] = stock[2] - num3;
            AmountofSale3 = unitPrice[2] * num3;
            break;
        }
        net_total = AmountofSale1 + AmountofSale2 + AmountofSale3;

        cout << "You Have Ordered:\n\n";
        cout << "======================================================================================================\n";
        cout << "\tPRODUCT" << "\t\t" << "AVAILABLE STOCK" << "\t\t" << "UNIT PRICE" << "\t\t" << "AMOUNT" << endl;
        cout << "======================================================================================================\n";
        cout << "\tAPPLE" << "\t\t" << stock[0] << "\t\t\t" << unitPrice[0] << "\t\t\t" << AmountofSale1 << endl;
        cout << "\tORANGES" << "\t\t" << stock[1] << "\t\t\t" << unitPrice[1] << "\t\t\t" << AmountofSale2 << endl;
        cout << "\tMANGOES" << "\t\t" << stock[2] << "\t\t\t" << unitPrice[2] << "\t\t\t" << AmountofSale3 << endl;
        cout << "======================================================================================================\n";
        cout << "\tNET TOTAL: " << "                                                     " << net_total << endl;
        cout << "======================================================================================================\n";
    }

    cout << "You want to apply discount:" << endl;
    cout << "[1] - YES" << endl;
    cout << "[2] - NO" << endl;
    cin >> input_discount;

    if (input_discount == 1)
    {
        if (net_total > 5000)
        {
            int tax_deductable = sum_total * (5 / 100);
            sum_total = sum_total - tax_deductable;
            percent_discount = 5;
        }
        else if (net_total > 10000)
        {
            int tax_deductable1 = sum_total * (10 / 100);
            sum_total = sum_total - tax_deductable1;
            percent_discount = 10;
        }
    }

    cout << "You want to apply gst: " << endl;
    cout << "[1] - YES" << endl;
    cout << "[2] - NO" << endl;
    cin >> gst_permission;

    if (gst_permission == 1)
    {
        int gst_deducable = sum_total * (gst / 100);
        sum_total = sum_total + gst_deducable;
    }

    // cout<<"You Have Ordered:\n\n";
    cout << "======================================================================================================\n";
    cout << "\tPRODUCT" << "\t\t" << "AVAILABLE STOCK" << "\t\t" << "UNIT PRICE" << "\t\t" << "AMOUNT" << endl;
    cout << "======================================================================================================\n";
    cout << "\tAPPLE" << "\t\t" << stock[0] << "\t\t\t" << unitPrice[0] << "\t\t\t" << AmountofSale1 << endl;
    cout << "\tORANGES" << "\t\t" << stock[1] << "\t\t\t" << unitPrice[1] << "\t\t\t" << AmountofSale2 << endl;
    cout << "\tMANGOES" << "\t\t" << stock[2] << "\t\t\t" << unitPrice[2] << "\t\t\t" << AmountofSale3 << endl;
    cout << "======================================================================================================\n";
    cout << "\tTOTAL: " << "                                                          " << net_total << endl;
    cout << "\tDISCOUNT: " << "                                                       " << percent_discount << "%" << endl;
    cout << "\tGST: " << "                                                            " << gst << "%" << endl;

    cout << "======================================================================================================\n";
    cout << "\tNET TOTAL: " << "                                                      " << sum_total << endl;

    return 0;
}
