#include <iostream>
#include "train_2.h"

int getInt(int &a) {
    std::cin >> a;
    if (std::cin.eof()) {
        return 0;
    }
    if (a < 1 || !std::cin.good()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return -1;
    }
    return 1;
}

void print_menu() {
    printf("\n1 - create empty train\n"
           "2 - read train\n"
           "3 - reserved seat\n"
           "4 - delete carriage\n"
           "5 - get busy seat in carriage\n"
           "6 - add carriage\n"
           "7 - delete carriages\n"
           "8 - get num of busy seat\n"
           "9 - print train\n"
           "10 - exit.\n");
}

int main() {
    int k, buf;
    Train main_class;

    while (true) {
        print_menu();
        do {
            std::cout << ">>> " << std::endl;
            buf = getInt(k);
            if (buf == 0) {
                return 0;
            }
        } while (buf == -1);

        switch (k) {
            case 10:
                std::cout << "Exit!" << std::endl;
                return 0;
            case 1:
                main_class = Train();
                break;
            case 2: {
                std::cin >> main_class;
                break;
            }
            case 3: {
                int num;
                Train tmp1;
                std::cin >> tmp1;
                std::cout << main_class + tmp1;
                break;
            }
            case 4: {
                int num[] = {0};
                std::cout << "Delete carriages number: " << std::endl;
                do {
                    std::cout << ">>> ";
                    buf = getInt(num[0]);
                    if (buf == 0) {
                        return 0;
                    }
                } while (buf == -1);

                try {
                    main_class.change_train(1, num);
                }
                catch (const std::invalid_argument& e) {
                    std::cout << "Bad carriages number!" << std::endl;
                }
                break;
            }
            case 5: {
                int num;
                printf("Enter carriages number: \n");
                do {
                    std::cout << ">>> ";
                    buf = getInt(num);
                    if (buf == 0) {
                        return 0;
                    }
                } while (buf == -1);
                try {
                    std::cout << main_class.number_of_reserved_seats(num) << std::endl;
                }
                catch (const std::invalid_argument& e) {
                    std::cout << "Bad carriages number!" << std::endl;
                }
                break;
            }
            case 6: {
                int num;
                printf("Enter carriages capacity: \n");
                do {
                    std::cout << ">>> ";
                    buf = getInt(num);
                    if (buf == 0) {
                        return 0;
                    }
                } while (buf == -1);
                Carriage t = {num, 0};
                try {
                    main_class.add_carriage(t);
                }
                catch (const std::invalid_argument& e) {
                    std::cout << "Train end!" << std::endl;
                }
                break;
            }
            case 7: {
                int num;
                printf("Count delete carriages number: \n");
                do {
                    std::cout << ">>> ";
                    buf = getInt(num);
                    if (buf == 0) {
                        return 0;
                    }
                } while (buf == -1);
                int *arr = new int[num];
                for (int i=0; i < num; ++i) {
                    do {
                        std::cout << "\n" << i+1 << " >>> ";
                        buf = getInt(arr[i]);
                        if (buf == 0) {
                            return 0;
                        }
                    } while (buf == -1);
                }

                try {
                    main_class.change_train(num, arr);
                }
                catch (const std::invalid_argument& e) {
                    std::cout << "Bad carriages number!" << std::endl;
                }
                delete[] arr;
                break;
            }
            case 8: {
                std::cout << main_class.number_of_passenger() << std::endl;
                break;
            }
            case 9: {
                std::cout << main_class;
                break;
            }
            default:
                std::cout << "Incorrect command!" << std::endl;
                break;
        }
    }
    return 0;
}
