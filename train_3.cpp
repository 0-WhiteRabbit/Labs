#include "train_3.h"

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
    auto *tmp = new Carriage[train_length - count];
    for (int i = 0, j = 0; i < train_length; ++i) {
        tmp[i-j] = carriages[i];
        if (i == numbers[j]-1 && j <= count-1) {
            ++j;
        }
    }
    delete[] carriages;
    carriages = tmp;
    train_length -= count;
}

void Train::add_carriage(Carriage carriage) {
    if (carriages == nullptr) {
        carriages = new Carriage[1];
    } else {
        auto *carriage_tmp = new Carriage[train_length+1];
        for (int i = 0; i < train_length; ++i) {
            carriage_tmp[i] = carriages[i];
        }
        delete[] carriages;
        carriages = carriage_tmp;
    }
    carriages[train_length] = carriage;
    ++train_length;
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
    if (number < 1 || number > train_length) {
        throw std::invalid_argument("incorrect number");
    }

    carriages[number-1].capacity = carriage.capacity;
    carriages[number-1].busy = carriage.busy;
}

Train& Train::operator =(Train& train) {
    train_length = train.train_length;
    for (int i = 0; i < train_length; ++i) {
        carriages[i].busy = train.carriages[i].busy;
        carriages[i].capacity = train.carriages[i].capacity;
    }
    return *this;
}

Train::Train(const Train &other) : train_length(other.train_length) {
    carriages = new Carriage[train_length];
    for (int i=0; i < other.train_length; ++i) {
        carriages[i] = other.carriages[i];
    }
}

Train::Train(Train &&obj) noexcept {
    carriages = obj.carriages;
    train_length = obj.train_length;

    obj.train_length = 0;
}

Train &Train::operator=(Train &&obj) noexcept {
    if (&obj == this)
        return *this;

    delete[] carriages;

    carriages = obj.carriages;
    train_length = obj.train_length;
    obj.train_length = 0;

    return *this;
}

Train operator +(Train train, Carriage carriage) {
    Train tmp;
    tmp = train;
    if (tmp.get_train_length() > 99) {
        throw std::invalid_argument("Bad train length");
    }
    tmp.set_train_length(tmp.get_train_length() + 1);
    tmp.set_carriage(tmp.get_train_length(), carriage);
    return tmp;
}

Train operator -(Train train, int num) {
    Train tmp;
    tmp = train;
    --num;
    if (num > 0 and num < tmp.get_train_length()) {
        throw std::invalid_argument("Bad train length");
    }

    for (int i = num; i < tmp.get_train_length(); ++i) {
        tmp.set_carriage(i-1, tmp.get_carriages(i));
    }

    return tmp;
}