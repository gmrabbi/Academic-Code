#include <iostream>
using namespace std;

class tollBooth {
private:
    unsigned int numCars;
    double totalCash;

public:
    tollBooth() {
        numCars = 0;
        totalCash = 0.0;
    }

    void payingCar() const {
        numCars++;
        totalCash += 0.5;
    }

    void nopayCar() const {
        numCars++;
    }

    void display() const {
        cout << "Number of cars: " << numCars << endl;
        cout << "Total cash collected: $" << totalCash << endl;
    }
};

int main() {
    tollBooth booth;

    // 3 cars pay toll
    booth.payingCar();
    booth.payingCar();
    booth.payingCar();

    // 2 cars don't pay toll
    booth.nopayCar();
    booth.nopayCar();

    booth.display();

    return 0;
}

