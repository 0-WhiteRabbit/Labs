#ifndef TESTS_TRAIN_2_H
#define TESTS_TRAIN_2_H

#include <iostream>
#include <algorithm>

struct Carriage {
    int capacity;
    int busy;
};

class Train {
private:
    Carriage *carriages = nullptr;
    int train_length;

public:
    [[nodiscard]] int get_train_length() const {
        return train_length;
    }

    [[nodiscard]] Carriage get_carriages(int number) const {
        if (number < 1 || number > train_length) {
            throw std::invalid_argument("incorrect number");
        }
        return carriages[number-1];
    }

    void set_train_length(int length) {
        train_length = length;
    }
    void set_carriage(int number, Carriage carriage);

    Train() {
        train_length = 0;
    }

    ~Train() {
        delete[] carriages;
    }

    void reserved_seat(int number, int quantity);

    int number_of_reserved_seats(int number);

    int number_of_passenger();

    void add_carriage(Carriage carriage);

    void change_train(int count, int *numbers);

    Train operator= (Train train);
};

std::istream& operator >> (std::istream& in, Train& train);
std::ostream& operator << (std::ostream &os, const Train &train);

Train operator +(Train train, Carriage carriage);

#endif //TESTS_TRAIN_2_H
