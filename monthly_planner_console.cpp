#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>
#include <cassert>

using namespace std;


int main() {

    vector <vector<int>> months(12);

    for (int i = 0; i < months.size(); i++)
    {
        if (i == 1)
        {
            months[i].resize(28);
        }
        else if (i % 2 == 0 && i < 7)
        {
            months[i].resize(31);
        }
        else if (i != 1 && i % 2 != 0 && i < 7)
        {
            months[i].resize(30);
        }
        else if (i % 2 == 0 && i >= 7)
        {
            months[i].resize(30);
        }
        else if (i % 2 != 0 && i >= 7)
        {
            months[i].resize(31);
        }
    }



    int current_month_index = 0;

    vector<vector<string>> current_month(months[current_month_index].size());

    bool keep_going = true;

    while (keep_going)
    {
        int Q{};
        cout << "Enter how many operations do you want to make:" << endl;
        cin >> Q;

        for (int i = 0; i < Q; i++)
        {
            string option;
            cout << "Enter option to follow (ADD, DUMP, NEXT):" << endl;
            cin >> option;

            if (option == "ADD")
            {
                int day{};
                cout << "Enter day number:" << endl;
                cin >> day;
                //assert(day > 0 && day <= months[current_month_index].size() && "Day must be from 0 to 28(February),30,31.");
                try
                {
                    if (day < 0 || day > months[current_month_index].size())
                    {
                        throw exception("Day must be from 1 to 28(February),30,31.");
                    }
                    day--;
                    string appointment;
                    cout << "Enter what will you do during this day:" << endl;
                    cin >> appointment;
                    current_month[day].push_back(appointment);
                }
                catch (const exception& obj_excep)
                {
                    cout << "We caught exception " << obj_excep.what() << endl;
                }

            }
            else if (option == "DUMP")
            {
                int day{};
                cout << "Enter day number:" << endl;
                cin >> day;
                //assert(day > 0 && day <= months[current_month_index].size() && "Day must be from 0 to 28(February),30,31.");
                try
                {
                    if (day < 0 || day > months[current_month_index].size())
                    {
                        throw exception("Day must be from 1 to 28(February),30,31.");
                    }
                    day--;
                    cout << current_month[day].size() << " ";
                    if (current_month[day].size() != 0)
                    {
                        for (auto& elem : current_month[day])
                        {
                            cout << elem << " ";
                        }
                    }
                    cout << endl;
                }
                catch (const exception& obj_excep)
                {
                    cout << "We caught exception " << obj_excep.what() << endl;
                }

            }

            else if (option == "NEXT")
            {
                int size_prev = current_month.size();
                current_month_index++;
                if (current_month_index == 12)
                {
                    current_month_index = 0;
                }
                vector<vector<string>>copy_curr_month{ current_month };

                current_month.resize(months[current_month_index].size());
                int size_new = current_month.size();
                if (size_prev > size_new)
                {
                    int diff = size_prev - size_new;
                    if (diff == 1)
                    {
                        current_month[size_new - 1].insert(end(current_month[size_new - 1]), begin(copy_curr_month[size_prev - 1]), end(copy_curr_month[size_prev - 1]));

                    }
                    else if (diff == 3)
                    {
                        for (int i = 1; i <= 3; i++)
                        {
                            current_month[size_new - 1].insert(end(current_month[size_new - 1]), begin(copy_curr_month[size_prev - i]), end(copy_curr_month[size_prev - i]));
                        }
                    }
                }
            }

        }

        cout << endl << "To stop please enter 0, to continue please enter 1" << endl;
        cin >> keep_going;

    }



    return 0;
}