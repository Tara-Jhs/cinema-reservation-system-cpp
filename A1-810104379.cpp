#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
struct Data_Film
{
    int time;
    int hall_number;
    string movie_name;
    vector<int> seat_number;
    map<int, string> seat_name;
};
void Add_Show(Data_Film &film, vector<Data_Film> &shows);
void Reserve(Data_Film &film, vector<Data_Film> &shows, string name, int hall, int time, int seat);
int Count_available_seat(const Data_Film &film);
void List_Movie(Data_Film &film, vector<Data_Film> &shows);
void Report_Seat(const Data_Film &film, vector<Data_Film> &shows);
int main(void)
{
    string input;
    Data_Film film;
    vector<Data_Film> shows;
    string name;
    const string add_show = "add_show";
    const string reserve = "reserve";
    const string list = "list_movies";
    const string report = "report_seats";
    while (cin >> input)
    {
        if (input == add_show)
        {
            cin >> film.movie_name >> film.time >> film.hall_number;
            Add_Show(film, shows);
        }
        else if (input == reserve)
        {
            int hall, time, seat;
            cin >> hall >> time >> seat >> name;
            Reserve(film, shows, name, hall, time, seat);
        }
        else if (input == list)
        {
            cin >> film.hall_number;
            List_Movie(film, shows);
        }
        else if (input == report)
        {
            cin >> film.hall_number >> film.time;
            Report_Seat(film, shows);
        }
    }
    return 0;
}
void Add_Show(Data_Film &film, vector<Data_Film> &shows)
{
    bool found = false;
    const string output1_addshow = "A movie is already scheduled in this hall at this time";
    const string output2_addshow = "OK";
    for (auto &s : shows)
    {
        if (s.time == film.time && s.hall_number == film.hall_number)
        {
            found = true;
            break;
        }
    }

    if (found)
    {
        cout << output1_addshow << endl;
    }
    else
    {
        if (film.hall_number == 1)
        {
            film.seat_number = vector<int>(10, 0);
        }
        else if (film.hall_number == 2)
        {
            film.seat_number = vector<int>(20, 0);
        }
        else if (film.hall_number == 3)
        {
            film.seat_number = vector<int>(30, 0);
        }
        shows.push_back(film);
        cout << output2_addshow << endl;
    }
}
void Reserve(Data_Film &film, vector<Data_Film> &shows, string name, int hall, int time, int seat)
{
    bool found = false;
    const string output1_reserve = "This seat is already reserved";
    const string output2_reserve = "No show is scheduled in this hall at the specified time";
    for (auto &s : shows)
    {
        if (s.hall_number == hall && s.time == time)
        {
            found = true;
            if (s.seat_number[seat - 1] == 1)
            {
                cout << output1_reserve << endl;
            }
            else if (s.seat_number[seat - 1] != 1)
            {
                cout << "OK" << endl;
                s.seat_number[seat - 1] = 1;
                s.seat_name[seat - 1] = name;
            }
            break;
        }
    }
    if (!found)
    {
        cout << output2_reserve << endl;
    }
}
int Count_available_seat(const Data_Film &film)
{
    int count = 0;
    const int hall1_seats = 10;
    const int hall2_seats = 20;
    const int hall3_seats = 30;
    for (int seat : film.seat_number)
    {
        if (seat == 1)
            count++;
    }
    switch (film.hall_number)
    {
    case 1:
        count = hall1_seats - count;
        break;
    case 2:
        count = hall2_seats - count;
        break;
    default:
        count = hall3_seats - count;
        break;
    }
    return count;
}
void List_Movie(Data_Film &film, vector<Data_Film> &shows)
{
    bool check = false;
    const string output_listmovie = "No movie found";
    sort(shows.begin(), shows.end(),
         [](const Data_Film &a, const Data_Film &b)
         {
             return a.time < b.time;
         });
    for (auto &s : shows)
    {
        if (s.hall_number == film.hall_number)
        {
            int number_of_available_seats = Count_available_seat(s);
            cout << s.movie_name << " at " << s.time << ":00: " << number_of_available_seats << " seats available" << endl;
            check = true;
        }
    }
    if (check == false)
    {
        cout << output_listmovie << endl;
    }
}
void Report_Seat(const Data_Film &film, vector<Data_Film> &shows)
{
    bool check = false;
    const string output_reportseat = "All seats are available";
    for (auto &s : shows)
    {
        if (s.hall_number == film.hall_number && s.time == film.time)
        {
            for (int i = 0; i < s.seat_number.size(); i++)
            {
                if (s.seat_number[i] == 1)
                {
                    check = true;
                    int chair = i + 1;
                    string first_name = s.seat_name[i];
                    cout << "Seat " << chair << " is reserved by " << first_name << endl;
                }
            }
            if (check == false)
            {
                cout << output_reportseat << endl;
                break;
            }
        }
    }
}