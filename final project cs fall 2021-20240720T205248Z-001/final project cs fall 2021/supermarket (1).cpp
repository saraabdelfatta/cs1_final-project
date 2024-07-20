#include <iostream> 
#include <fstream>
#include <stdlib.h>
using namespace std;




struct customer
{
    string email;
    string password;
    string address;
};
class accounts
{
public:
    customer user[50];
    char answer;
    int x;
    char ans1;
    int ans2;
    bool y;
    char ans;
    accounts()
    {
        x = 0;
        ans1 = 'n';
        y=1;
        ans = 'n';
    }

    void choice()
    {
        cout << "1- sign up \n" << "2- sign in \n";
        cin >> ans2;
        do
        {
            if(ans2 == 1)
            {
                getinfo();
                login();
                save();
            }
            else if (ans2 == 2 )
            {
                login();
                save();
            }
            else
            {
                cout << "invalid input \n";
                cin >> ans;
            }
        } while (ans != 'y');
        
    }
   
    void login()
    {
        string email;
        string password;
        cout << "\t\tSign In" << endl;
        cout << "====================================";
        load();
        do
        {
            cout << "\nemail: ";
            cin >> email;
            for(int i = 0 ; i < x ; i++)
            {
                if(email == user[i].email)
                {
                    cout << "password: ";
                    cin >> password;
                    if(password == user[i].password)
                    {
                        cout << "you logged in succesfully \n";
                        y = 0;
                        ans1 = 'n';
                    }

                }

                    
            }
            if(y==1)
            {


                cout << "invaild email or password\n";
                cout << "do you want to try again? (y/n)\n";
                cin >>ans1;
            }

        } while (ans1 == 'y');


           
    }
    void getinfo()
    {
        do
        {
            cout << "\t\tSign Up" << endl;
            cout << "====================================";
            cout << "\nEmail: ";
            cin >> user[x].email;
            cout << "Password: ";
            cin >> user[x].password;
            cout << "Address: ";
            cin >> user[x].address;
            cout << "Do you want to add another account?\n";
            cin >> answer;
            x++;
        } while (answer == 'y' || answer == 'Y');
        system("CLS");
        save();

    }
    void save()
    {
        ofstream write;
        write.open("account.txt");
        for(int i = 0 ; i < x ; i++)
        {
            write << user[i].email << "\t" << user[i].password << "\t" << user[i].address << endl;
        }
        write.close();
    }
    void load()
    {
        ifstream read;
        read.open("account.txt");
        while(user[x].email == "")
        {
            x++;
        }
        for(int i = 0 ; i < x ; i++)
            read >> user[i].email >> user[i].password >> user[i].address;

        read.close();
        
    }
};

class product
{
    public:
    struct items
    {
        float price;
        string name;
        int stock;
    };
    struct cart
    {
        string prodincart;   
        int amount;
    };
    

    cart c;
    items p[50];
    string category;
    int x;
    int ans1;
    int ans2;
    

    product()
    {
        x=0;
        category ="";
    }

    void save()
    {
        ofstream write;
        write.open(category);
        for(int i = 0 ; i < x ; i++)
        {
            write << p[i].name << "\t" << p[i].price <<"\t" << p[i].stock << endl; 
        }
        write.close();

    }

    void load()
    {
        ifstream read;
        read.open(category);
        for(int i = 0 ; i < x ; i++)
        {
            read >> p[i].name >> p[i].price >> p[i].stock;
        }
        read.close();
    }
    



    void ctg()
    {
        cout << "which category do you want to add from?\n";
        cout << "1-Bakeries\n" << "2-Butcheries and BBQ\n" << "3-Cosemtics and beauty\n" << "4-Pharmacies\n" << "5-Supermarket\n";
        cin >> ans1;
        switch(ans1)
        {
            case 1:
                category = "bake.txt";
                x=5;
                break;
            case 2:
                category = "butcheries.txt";
                x=2;
                break;
            case 3:
                category = "cosme.txt";
                x=2;
                break;
            case 4:
                category = "pharmacies.txt";
                x=4;
                break;
            case 5:
                category = "supermarket.txt";
                x=5;
                break;

            default:
                cout << "invalid input\n";
        }
    }


    void display()
    {
        load();
        if(category != "")
        {
            for(int i = 0 ; i < x ; i++)
            {
                cout << i+1 << "- " << p[i].name << "\t" << p[i].price << "\t" << p[i].stock << endl;
            }
        }
    }





};

class payment{

		public:
			
		struct wallet
		{
			float balance;
			long long int cardnum;
			int cvv;
			int exp_month;
			int exp_year;
			string name;
		};
		
		product prod;
		wallet w;
		char choice;
        int x;
		
		payment()
		{
			w.balance = 0;
            x = 0;
		}
		

		
		void save()
		{
			ofstream write;
			write.open("payment.txt");
			write << w.name << "\t"<< w.cardnum << "\t" << w.cvv << "\t" << w.exp_month << "\t" << w.exp_year << "\t" << w.balance << endl;
			write.close();
		}
		
		void get_info()
		{
			cout << "enter the name on the card \n";
			cin >> w.name;
			cout << "enter the card number \n";
			cin >> w.cardnum;
			cout << "enter the cvv\n";
			cin >> w.cvv;
			cout << "enter the expiry date\n";
			cin >> w.exp_month >> w.exp_year;
		}
		
		
	void get_balance()
	{
		if(w.balance - prod.p[x].price >= 0)
		{
			w.balance -= prod.p[x].price;
		}
	}	


	
	void payment_choice()
	{
		cout<<"Click C for Cash on Delivery or V for paying by Visa. (c/v)"<<endl;
		cin>>choice; 
	
		if (choice=='c')
		{
			cout<<"Your order will be arriving shortly."<<endl;
		}
		else if(choice=='v')
		{
			get_info();
            while(prod.p[x].price > -1)
            {
			    if(prod.p[x].stock == 0 && prod.p[x].name != "")
			    {
				    get_balance();
				    cout << prod.p[x].name << " is out of stock, price added to balance \n";
			    }     
                x++;           
            }
			save();
		}
	}
};

struct cart
{
    string name;
    int amount;
    float price;        
};

class shopping_cart
{
public:


    product prod;
    cart incart[50];
    payment pay;
	int sh;
	char ch;
    int neg;
	int xy;	// the item that will removed 
	float sum;
    shopping_cart()
    {
        neg=0;
    }

	void add()
	{
        sh = 0;
        do
        {
            prod.ctg();
            prod.display();
            cout << "which item do you want to add top the cart? \n";
            cin >> prod.ans2;
 
            incart[sh].name = prod.p[prod.ans2-1].name;
            incart[sh].price = prod.p[prod.ans2 -1].price; 
			cout << " Enter the amount of the product " << endl;
			cin >> incart[sh].amount;
            for(int i = 0 ; i < prod.x ; i++)
            {
                if(prod.p[i].name == incart[sh].name )
                {
                    prod.p[i].stock -= incart[sh].amount;
                }
            }
            prod.save();
            save();
            cout << "do you want to add another item (y/n):";
            cin >> ch;
            sh++;
	    } while ( ch == 'y');
	}
	void remove()
	{
		cout << " What item do you want to remove " << endl;
		do
		{
            display();
			cout << " your choice  " << endl;
			cin >> xy;
            for(int i = 0 ; i <sh ; i++)
            {
                if(xy - 1 == i)
                {
                    incart[i].name ="";
                    incart[i].amount = 0;
                    incart[i].price = 0;
                }
            }
			cout << " remove any item agin y/n " << endl;
            cin >> ch;
            neg++;
		} while (ch == 'y');
		for (int i = 0; i < sh; i++)
		{
			for (int j = i + 1; j < sh; j++)
			{
				if ( incart[i].name < incart[j].name && incart[i].price < incart[j].price && incart[i].amount < incart[j].amount)
				{
					swap(incart[i], incart[j]);
				}
			}
		}
		
	}
	void total_cost()
	{
		sum = 0;
		
		for (int i =0; i < sh; i++)
		{
			sum += incart[i].price * incart[i].amount;
		}
		cout << " the total cost is " << sum <<endl;
	}
	void swap(cart &x, cart &y)
	{
		cart z;
		z = x;
		x = y;
		y = z;
	}
	void checkout()
	{
        display();
		total_cost();
        pay.payment_choice();
	}
	void load()
	{
		ifstream read;
		read.open("cart.txt");
		for (int i = 0; i < sh - neg; i++)
		{
			read  >> incart[i].name >> incart[i].price >> incart[i].amount;
		}
		read.close();

	}
	void save()
	{
		ofstream write;
		write.open("cart.txt");
		for (int i = 0; i < sh; i++)
		{
			write << incart[i].name << "\t" << incart[i].price << "\t" << incart[i].amount <<  endl;

		}
		write.close();
	}
    void display()
    {
        load();
        for(int i = 0 ; i < sh - neg; i++)
        {
            cout << i+1 << "-" << incart[i].name <<"\t" << incart[i].price <<"\t" << incart[i].amount << endl;
        }
    }
};


class CustomerService{

    public:
    struct CS
    {  
        string pc;
        string dc;
        string yn;
        int num;
        float Prating;
        float Drating;
    };

    CS rate;

    void Ratings()
    {
        cout << "Rate The Products Ordered (1-10): ";
        cin >> rate.Prating;
        cout << endl;
        cout << "Rate Our Delivery Service (1-10): ";
        cin >> rate.Drating;
        cout << endl;
        cout << "\t" <<"\t" << "==========================================================================================="<< endl;
    }

    void Ask()
    {
        cout << "\t" <<"\t" << "\t" << "\t" << "Do You have any complaints? (yes - no )" << endl;
        cin >> rate.yn;
        cout << endl;

            if ( rate.yn == "yes")
                {
                    cout << "\t"<<"\t" <<"Please Enter The Problem Number: " << endl;
                    cout << endl;
                    cout << "\t"<<"\t" <<"1- Packaging " << endl;
                    cout << "\t"<<"\t" <<"2- Delivery " << endl;
                    cout << "\t"<<"\t" <<"3- Product Rip/Broken "<< endl;
                    cout << "\t"<<"\t" <<"4- Item Not As Expected "<< endl;
                    cout << "\t"<<"\t" <<"5- Product Quality Not Good " << endl;
                    cout << "\t"<<"\t" <<"6- Other " << endl;
                    cin >> rate.num;

                        if (rate.num == 1)
                        {
                            rate.pc = "Packaging";
                        }
                        else if (rate.num == 2)
                        {
                            rate.pc = "Delivery";
                        }
                        else if (rate.num == 3)
                        {
                            rate.pc = "Product Rip/Broken ";
                        }
                        else if (rate.num == 4)
                        {
                            rate.pc = "Item Not As Expected";
                        }
                        else if (rate.num == 5)
                        {
                            rate.pc = "Product Quality Not Good";
                        }
                        else if (rate.num == 6)
                        {
                            rate.pc = "Other";
                            cout << endl;
                            cout << "\t" << "\t" << "Please Contact Customer Service Office to Specify your Problem."<< endl;
                            cout << endl;
                        }
                        else
                        {
                            rate.pc = "DNE";
                        }
                }
            else
                {
                    rate.pc = "Null";
                    cout << endl;
                    cout << "\t" <<"\t" << "Great!" << endl;
                    cout << endl;
                }
        cout <<"\t" <<"\t" << "                                Thank you for your feedback!                               "<< endl;
        cout << endl;
        cout <<"\t" <<"\t" << "==========================================================================================="<< endl;
    }

    void Solver()
    {
            if (rate.yn == "yes" && rate.pc != "DNE" && rate.pc != "Other")
            {
                cout << "\t" <<"\t" << "Your Problem " << rate.pc << " will be solved in approximately "<< rate.Drating << " days";
                cout << endl;
                cout << endl;
                cout <<"\t" <<"\t" << "                                 We will keep you Updated!                                 "<< endl;
            }
            else if ( rate.pc == "DNE")
            {
                cout << "\t" <<"\t" << "Your Problem is invalid ";
                cout << endl;
            }
            else
            {
                cout << endl;
            }
            cout << endl;
            cout <<"\t" <<"\t" << "==========================================================================================="<< endl;
    }

    void Contacts() 
    {
        cout << endl;
        cout << endl;
        cout <<"\t" <<"\t" << "==========================================================================================="<< endl;
        cout <<"\t" <<"\t" << "|                                                                                         |"<< endl;
        cout <<"\t" <<"\t" << "|   For any more Inconveniences do not hesitate to contact us at our Email and Hotline    |"<< endl;
        cout <<"\t" <<"\t" << "|                                                                                         |"<< endl;
        cout <<"\t" <<"\t" << "|                     Customer Service Email: cs_supermarket@smcs.com                     |"<< endl;
        cout <<"\t" <<"\t" << "|                                                                                         |"<< endl;
        cout <<"\t" <<"\t" << "|                        Customer Service Hotline: 01903657322                            |"<< endl;
        cout <<"\t" <<"\t" << "|                                                                                         |"<< endl;
        cout <<"\t" <<"\t" << "|                         Thank you for using our Supermarket!                            |"<< endl;
        cout <<"\t" <<"\t" << "|                                                                                         |"<< endl;    
        cout <<"\t" <<"\t" << "==========================================================================================="<< endl;    
    }

    void Save()
    {
        ifstream read;
        read.open("ServCustomer.txt");
        read >> rate.Prating >> rate.pc >> rate.Drating;
        read.close();
    }

    void Load()
    {
        ofstream write;
        write.open("ServCustomer.txt");
        write << "Product Rating" << "\t" << "\t" << "Delivery Rating" << "\t" << "\t" << "Complaint" << endl;
        write << rate.Prating << "\t" << "\t" << "\t" << rate.Drating << "\t" << "\t" << "\t" << rate.pc << endl;
        write.close();
        cout << endl;
    }

};


int main()
{
    char ans;
    shopping_cart cart;
    accounts user;
    user.choice();
    cart.add();
    cout << "do you want to remove an item from your cart? (y/n)";
    cin >> ans;
    if(ans == 'y')
        cart.remove();
    cout << "that is " << cart.neg << endl;
    cart.checkout();
        CustomerService find;

    find.Ratings();

    find.Ask();

    find.Load();

    find.Solver();

    find.Contacts();

}