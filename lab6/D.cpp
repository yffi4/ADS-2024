#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
#include <stdexcept>
using namespace std;


tuple<int, int, int> parseDate(const string &date) {
    int day = stoi(date.substr(0, 2));
    int month = stoi(date.substr(3, 2));
    int year = stoi(date.substr(6, 4));
    return make_tuple(day, month, year);
}


bool compareDates(const string &date1, const string &date2) {
    auto [day1, month1, year1] = parseDate(date1);
    auto [day2, month2, year2] = parseDate(date2);
    
    if (year1 != year2)
        return year1 < year2;
    if (month1 != month2)
        return month1 < month2;
    return day1 < day2;
}


int partition(vector<string>& dates, int low, int high) {
    string pivot = dates[high];
    int i = low - 1;
    
    for (int j = low; j <= high - 1; j++) {
        if (compareDates(dates[j], pivot)) {
            i++;
            swap(dates[i], dates[j]);
        }
    }
    swap(dates[i + 1], dates[high]);
    return (i + 1);
}

void quickSort(vector<string>& dates, int low, int high) {
    if (low < high) {
        int pi = partition(dates, low, high);
        quickSort(dates, low, pi - 1);
        quickSort(dates, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> dates(n);

    
    for (int i = 0; i < n; i++) {
        cin >> dates[i];
    }

    
    quickSort(dates, 0, n - 1);

    
    for (const string &date : dates) {
        cout << date << endl;
    }

    return 0;
}
