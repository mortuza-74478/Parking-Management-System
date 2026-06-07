#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<string> parking;
    int choice;

    const int MAX_SLOT = 10;

    do
    {
        cout << "\n===== PARKING MANAGEMENT SYSTEM =====\n";
        cout << "1. Park Multiple Cars\n";
        cout << "2. Remove Specific Car\n";
        cout << "3. Show Parked Cars\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                int n;

                cout << "How many cars do you want to park? ";
                cin >> n;

                if(parking.size() + n > MAX_SLOT)
                {
                    cout << "Not enough parking slots available!\n";
                    break;
                }

                for(int i = 1; i <= n; i++)
                {
                    string car;
                    cout << "Enter Car " << i << " Number: ";
                    cin >> car;

                    parking.push(car);
                }

                cout << n << " Cars Parked Successfully.\n";
                break;
            }

            case 2:
            {
                if(parking.empty())
                {
                    cout << "Parking is Empty!\n";
                    break;
                }

                string target;
                cout << "Enter Car Number to Remove: ";
                cin >> target;

                stack<string> temp;
                bool found = false;

                while(!parking.empty())
                {
                    if(parking.top() == target && !found)
                    {
                        found = true;
                        parking.pop();
                    }
                    else
                    {
                        temp.push(parking.top());
                        parking.pop();
                    }
                }

                while(!temp.empty())
                {
                    parking.push(temp.top());
                    temp.pop();
                }

                if(found)
                    cout << target << " Removed Successfully.\n";
                else
                    cout << "Car Not Found!\n";

                break;
            }

            case 3:
            {
                if(parking.empty())
                {
                    cout << "Parking is Empty!\n";
                    break;
                }

                stack<string> temp = parking;

                cout << "\nParked Cars (Top to Bottom):\n";

                while(!temp.empty())
                {
                    cout << temp.top() << endl;
                    temp.pop();
                }

                break;
            }

            case 4:
                cout << "Program Ended.\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while(choice != 4);

    return 0;
}