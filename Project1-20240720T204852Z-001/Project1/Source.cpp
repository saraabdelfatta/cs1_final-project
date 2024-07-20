#include <iostream>
#include <fstream>
using namespace std;

struct product
{
    string name;
    int amount;
    float price;
};

class cart
{
public:
    int option;
    char ans;
    product* item = new product[50];
    int x;
    float sum;
    cart()
    {
        for (int i = 0; i < 50; i++)
        {
            item[i].price = 50;
        }
        sum = 0;
        x = 0;
    }

    void addtc()

    {
        ofstream write;
        write.open("cart.txt");
        do
        {
            cout << "what item do you want to add? \n";
            cin >> item[x].name;
            cout << "how much do you need ?\n";
            cin >> item[x].amount;
            write << item[x].name << "/t" << item[x].amount << "\t" << item[x].price << endl;
            cout << "do you want to add another item? (y/n) \n";
            cin >> ans;
            x++;
        } while (ans == 'y');



    }

    void editc()
    {
        ofstream write;
        write.open("cart.txt");
        char edito;
        cout << "do you want to edit cart? (y/n) \n";
        cin >> edito;
        if (edito == 'y')
        {
            do
            {
                int edited_num;
                cout << "what do you want to do? \n" << "1-remove product\n" << "2-edit the amount of products\n";
                cin >> option;
                if (option == 1)
                {
                    for (int i = 0; i < x; i++)
                    {
                        cout << i + 1 << "-" << item[i].name << "\t" << item[i].amount << "\t" << item[i].price << endl;
                    }
                    cout << "which item do you want to do remove? \n";
                    cin >> x;
                    item[x - 1].name = "";
                    item[x - 1].amount = 0;
                    x--;
                    write << item[x].name << "\t" << item[x].price << "\t" << item[x].amount << endl;
                }

                else if (option == 2)
                {
                    for (int i = 0; i < x; i++)
                    {
                        cout << i + 1 << "-" << item[x].name << "\t" << item[x].amount << "\t" << item[x].price << endl;
                    }
                    cout << "which item do you want to edit ? \n";
                    cin >> x;
                    cout << "how many items do you need to add/remove? \n";
                    cin >> edited_num;
                    item[x - 1].amount += edited_num;
                    if (item[x - 1].amount == 0)
                    {
                        item[x - 1].name = "";
                        item[x - 1].amount = 0;
                        x--;
                        write << item[x].name << "\t" << item[x].price << "\t" << item[x].amount << endl;
                    }
                }

                else
                {
                    cout << "invalid input \n";
                }

                cout << "do you want to edit again? (y/n) \n";
                cin >> ans;

            } while (ans == 'y');
        }


    }


    void calc()
    {
        ofstream read;
        read.open("cart.txt");

        for (int i = 0; i < x; i++)
        {
            sum += item[i].price * item[i].amount;
        }

    }

    void checkout()
    {
        ifstream read;
        read.open("cart.txt");
        for (int i = 0; i < x; i++)
        {
            read >> item[i].name >> item[i].price >> item[i].amount;
            cout << item[i].name << "\t" << item[i].price << "\t" << item[i].amount << endl;
        }

        cout << "your total is " << sum << endl;
    }
};

int main()
{
    cart c;
    char ans;
    c.addtc();
    c.editc();
    cout << "do you want to add anything else to the cart? (y/n) \n";
    cin >> ans;
    if (ans == 'y')
    {
        c.addtc();
    }
    c.calc();
    c.checkout();
}