#include <iostream>
using namespace std;

class Product {
private:
    string name;
    double price;
    int quantity;

public:
    void input() {
        cout << "Product Name: ";
        cin >> name;

        cout << "Price: ";
        cin >> price;

        cout << "Quantity Sold: ";
        cin >> quantity;
    }

    double sales() {
        return price * quantity;
    }

    string getName() {
        return name;
    }
};

class Store {
private:
    Product products[50];
    int n;

public:
    static double overallSales;

    void input() {

        cout << "\nProducts in Store: ";
        cin >> n;

        for(int i=0;i<n;i++)
            products[i].input();
    }

    double calculateStoreSales() {

        double total=0;

        for(int i=0;i<n;i++)
            total+=products[i].sales();

        overallSales+=total;

        return total;
    }
};

double Store::overallSales = 0;

int main() {

    int stores;

    cout << "Enter Number of Stores: ";
    cin >> stores;

    Store s[20];

    double bestSales=-1;
    int bestStore=0;

    for(int i=0;i<stores;i++) {

        cout<<"\nStore "<<i+1<<endl;

        s[i].input();

        double sale =
            s[i].calculateStoreSales();

        cout<<"Store Sales = "
            <<sale<<endl;

        if(sale>bestSales){
            bestSales=sale;
            bestStore=i+1;
        }
    }

    cout << "\nOverall Sales = "
         << Store::overallSales;

    cout << "\nBest Performing Store = "
         << bestStore;

    return 0;
}