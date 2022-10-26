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
    void set_carriage(int number, Carriage carriage);

    Train() {
        train_length = 0;
        carriages[0].busy = 0;
        carriages[0].capacity = 35;
    }

    void reserved_seat(int number, int quantity);

    int number_of_reserved_seats(int number);

    int number_of_passenger();

    void add_carriage(Carriage carriage);

    void change_train(int count, int *numbers);
};

std::istream& operator >> (std::istream& in, Train& train);
std::ostream& operator << (std::ostream &os, const Train &train);


#endif //LAB_3_TRAIN_H
