
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 3;
const int MIN = 10000;
const int MAX = 99999;

class Chair {
private:
    int legs;
    double* prices;

public:
    // Default constructor: random legs and prices
    Chair() {
        prices = new double[SIZE];

        legs = rand() % 2 + 3;

        for (int i = 0; i < SIZE; i++) {
            prices[i] =
                (rand() % (MAX - MIN + 1) + MIN) / 100.0;
        }
    }

    // Parameterized constructor
    Chair(int l, const double p[]) {
        legs = l;
        prices = new double[SIZE];

        for (int i = 0; i < SIZE; i++) {
            prices[i] = p[i];
        }
    }

    // Copy constructor
    Chair(const Chair& other) {
        legs = other.legs;
        prices = new double[SIZE];

        for (int i = 0; i < SIZE; i++) {
            prices[i] = other.prices[i];
        }
    }

    // Copy assignment operator
    Chair& operator=(const Chair& other) {
        if (this != &other) {
            legs = other.legs;

            for (int i = 0; i < SIZE; i++) {
                prices[i] = other.prices[i];
            }
        }
        return *this;
    }

    // Setters and getters
    void setLegs(int l) {
        legs = l;
    }

    int getLegs() {
        return legs;
    }

    void setPrices(double p1, double p2, double p3) {
        prices[0] = p1;
        prices[1] = p2;
        prices[2] = p3;
    }

    double getAveragePrices() {
        double sum = 0;

        for (int i = 0; i < SIZE; i++) {
            sum += prices[i];
        }

        return sum / SIZE;
    }

    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: ";

        for (int i = 0; i < SIZE; i++) {
            cout << "$" << prices[i] << " ";
        }

        cout << endl;
        cout << "Historical avg price: $"
             << getAveragePrices() << endl << endl;
    }

    // Destructor
    ~Chair() {
        delete[] prices;
    }
};

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    cout << fixed << setprecision(2);

    // First chair: default constructor
    cout << "=== FIRST CHAIR: DEFAULT CONSTRUCTOR ===\n";

    Chair* chairPtr = new Chair;
    chairPtr->print();

    // Second chair: parameterized constructor
    cout << "=== SECOND CHAIR: PARAMETERIZED CONSTRUCTOR ===\n";

    double livingPrices[SIZE] = {
        525.25, 434.34, 252.52
    };

    Chair* livingChair = new Chair(3, livingPrices);
    livingChair->print();

    // Third part: dynamic array using default constructors
    cout << "=== COLLECTION OF RANDOM CHAIRS ===\n";

    Chair* collection = new Chair[SIZE];

    for (int i = 0; i < SIZE; i++) {
        cout << "Chair " << i + 1 << ":\n";
        collection[i].print();
    }

    // Clean up dynamically allocated memory
    delete chairPtr;
    chairPtr = nullptr;

    delete livingChair;
    livingChair = nullptr;

    delete[] collection;
    collection = nullptr;

    return 0;
}
