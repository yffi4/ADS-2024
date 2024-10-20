#include <iostream>
#include <map>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

map<string, double> grade = {
    {"A+", 4.00}, {"A", 3.75}, {"B+", 3.50}, {"B", 3.00}, 
    {"C+", 2.50}, {"C", 2.00}, {"D+", 1.50}, {"D", 1.00}, {"F", 0.00}
};

class Info {
public:
    string name;
    double mark;

    Info(string name, double mark) : name(name), mark(mark) {}
};

class F {
public:
    void display(const vector<Info>& arr) {
        for (const auto& el : arr) {
            cout << el.name << " " << fixed << setprecision(3) << el.mark << endl;
        }
    }

    void quickSort(vector<Info>& arr, int low, int high) {
        if (low < high) {
            int p = partition(arr, low, high);
            quickSort(arr, low, p - 1);
            quickSort(arr, p + 1, high);
        }
    }

private:
    int partition(vector<Info>& arr, int low, int high) {
        Info pivot = arr[high];
        int j = low;

        for (int i = low; i <= high; i++) {
            if (isLess(arr[i], pivot)) {
                swap(arr[i], arr[j]);
                j++;
            }
        }
        return j - 1;
    }

    bool isLess(const Info& a, const Info& b) {
        return a.mark < b.mark || (a.mark == b.mark && a.name <= b.name);
    }

    void swap(Info& a, Info& b) {
        Info temp = a;
        a = b;
        b = temp;
    }
};

int main() {
    int n;
    cin >> n;

    vector<Info> arr;
    F qs;

    for (int i = 0; i < n; i++) {
        string last, first;
        int m;
        cin >> last >> first >> m;
        
        double numerator = 0.0, denominator = 0.0;
        for (int j = 0; j < m; j++) {
            string mark;
            float credit;
            cin >> mark >> credit;
            numerator += grade[mark] * credit;
            denominator += credit;
        }
        arr.emplace_back(last + " " + first, numerator / denominator);
    }

    qs.quickSort(arr, 0, n - 1);
    qs.display(arr);

    return 0;
}