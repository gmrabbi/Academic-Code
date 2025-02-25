#include <iostream>
using namespace std;

class time {
private:
    int hours, minutes, seconds;

public:
    time() {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    time(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
    }

    void display() const {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }

    time add(const time& t) const {
        int h = hours + t.hours;
        int m = minutes + t.minutes;
        int s = seconds + t.seconds;

        if (s >= 60) {
            s -= 60;
            m++;
        }
        if (m >= 60) {
            m -= 60;
            h++;
        }

        return time(h, m, s);
    }
};

int main() {
    const time t1(1, 30, 45);
    const time t2(3, 20, 15);
    time t3;

    t3 = t1.add(t2);

    cout << "Time 1: ";
    t1.display();
    cout << "Time 2: ";
    t2.display();
    cout << "Time 3: ";
    t3.display();

    return 0;
}

