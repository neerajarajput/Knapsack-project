#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight, value;
    double valuePerUnitWeight;

    Item(int weight, int value) {
        this->weight = weight;
        this->value = value;
        valuePerUnitWeight = (double)(value) / (weight);
    }
};

struct CompareItems {
    bool operator()(const Item& i1, const Item& i2) const {
        return i1.valuePerUnitWeight > i2.valuePerUnitWeight;
    }
};

double getMax(int weight[], int value[], int capacity) {
    int n = sizeof(weight) / sizeof(weight[0]);
    vector<Item> list;
    for (int i = 0; i < n; i++) {
        list.push_back(Item(weight[i], value[i]));
    }
    sort(list.begin(), list.end(), CompareItems());
    double ans = 0;
    for (int i = 0; i < n; i++) {
        int wt = list[i].weight;
        int val = list[i].value;
        double valuePerUnitWeight = list[i].valuePerUnitWeight;
        if (capacity >= wt) {
            ans += val;
            capacity -= wt;
        } else {
            ans += valuePerUnitWeight * capacity;
            capacity = 0;
            break;
        }
    }
    return ans;
}
int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;
    int weight[n], value[n];
    for(int i=0; i<n; i++){
        cout << "Enter the weight and profit of item " << i+1 << ": ";
        cin >> weight[i] >> value[i];
    }
    int capacity;
    cout << "Enter the capacity of knapsack: ";
    cin >> capacity;
    cout << "Maximum value that can be obtained is " << getMax(weight, value, capacity) << endl;

    return 0;
}