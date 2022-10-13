#include "train.h"

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

void Train::change_train(int count, int *numbers) {
    std::sort(numbers, numbers +  sizeof(int)*(count-1));
    for (int i = numbers[0], j = 0; i < train_length; ++i) {
        carriages[i-j] = carriages[i];
        if (i == numbers[j] && j <= count) {
            ++j;
            --train_length;
        }
    }
}

void Train::add_carriage(Carriage carriage) {
    if (train_length > 99) {
        throw std::invalid_argument("Bad train length");
    }
    set_carriage(++train_length, carriage);
}

int Train::number_of_passenger() {
    int quantity = 0;
    for (int i = 0; i < train_length; ++i) {
        quantity += carriages[i].busy;
    }
    return quantity;
}

int Train::number_of_reserved_seats(int number) {
    if (train_length < number) {
        throw std::invalid_argument("Exceeded the limit of seats");
    }
    return carriages[number-1].busy;
}

void Train::reserved_seat(int number, int quantity) {
    if (train_length < number || carriages[number-1].capacity < carriages[number-1].busy + quantity) {
        throw std::invalid_argument("Exceeded the limit of seats");
    }
    carriages[number-1].busy += quantity;
}

void Train::set_carriage(int number, Carriage carriage) {
    carriages[number-1].capacity = carriage.capacity;
    carriages[number-1].busy = carriage.busy;
}
