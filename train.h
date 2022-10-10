#ifndef LAB_3_TRAIN_H
#define LAB_3_TRAIN_H

#include <iostream>
#include <algorithm>

struct Carriage {
    int capacity;
    int busy;
};

class Train {
private:
    Carriage carriages[100]{};
    int train_length;

public:
    [[nodiscard]] int get_train_length() const {
        return train_length;
    }

    [[nodiscard]] Carriage get_carriages(int number) const {
        return carriages[number-1];
    }

    void set_train_length(int length) {
        train_length = length;
    }
    void set_carriage(int number, Carriage carriage) {
        carriages[number-1].capacity = carriage.capacity;
        carriages[number-1].busy = carriage.busy;
    }

    Train() {
        train_length = 0;
        carriages[0].busy = 0;
        carriages[0].capacity = 35;
    }

    void reserved_seat(int number, int quantity) {
        if (carriages[number-1].capacity < carriages[number-1].busy + quantity) {
            throw std::invalid_argument("Exceeded the limit of seats");
        }
        carriages[number-1].busy += quantity;
    }

    int number_of_reserved_seats(int number) {
        return carriages[number-1].busy;
    }

    int number_of_passenger() {
        int quantity = 0;
        for (int i = 0; i < train_length; ++i) {
            quantity += carriages[i].busy;
        }
        return quantity;
    }

    void add_carriage(Carriage carriage) {
        if (train_length > 99) {
            throw std::invalid_argument("Bad train length");
        }
        set_carriage(++train_length, carriage);
    }

    void change_train(int count, int *numbers) {
        std::sort(numbers, numbers +  sizeof(int)*count);
        for (int i = numbers[0], j = 1; i < train_length; ++i) {
            carriages[i-j] = carriages[i];
            if (i == numbers[j] && j <= count) {
                ++j;
            }
        }
    }
};

std::istream& operator >> (std::istream& in, Train& train) {
    int length;
    in >> length;
    train.set_train_length(length);
    if (!in || length < 0 || length > 100) {
        train = Train();
    }
    Carriage carriage{};
    for (int i = 0; i < length; ++i) {
        std::cout << "Carriage " << i << ":\nInput max capacity: ";
        in >> carriage.capacity;
        std::cout << "Input how many seats are busy: ";
        in >> carriage.busy;
        if (!in || carriage.busy < 0 || carriage.busy < carriage.capacity
            || carriage.capacity < 0) {
            std::cout << "Error!\n";
            --i;
        } else {
            train.set_carriage(i+1, carriage);
        }
    }
    return in;
}

std::ostream& operator << (std::ostream &os, const Train &train) {
    int length = train.get_train_length();
    for (int i = 0; i < length; ++i) {
        os << train.get_carriages(i+1).capacity << ' '
           << train.get_carriages(i+1).busy << std::endl;
    }
    return os;
}

#endif //LAB_3_TRAIN_H
