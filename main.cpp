#include <iostream>
#include <limits>
#include "./lib/pcb.hpp"

using namespace PCB_dynamic;

void init(pcb &main_class) {
    contact tmp(1,1,input);
    main_class.add_contact(tmp);
    contact tmp1(1,9,output);
    main_class.add_contact(tmp1);
    contact tmp2(4,1,input);
    main_class.add_contact(tmp2);
    contact tmp3(4,4,output);
    main_class.add_contact(tmp3);
    contact tmp4(3,4,input);
    main_class.add_contact(tmp4);
    contact tmp5(3,10,output);
    main_class.add_contact(tmp5);
    contact tmp6(2,1,input);
    main_class.add_contact(tmp6);
    contact tmp7(2,4,output);
    main_class.add_contact(tmp7);
}

int getValue(double &a) {
    std::cin >> a;
    if (std::cin.eof()) {
        return 0;
    }
    if (!std::cin.good()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return -1;
    }
    return 1;
}

int main() {
    std::cout << "Hello user in floor game!" << std::endl;
    std::cout << "Rule: you must go from first floor to 10!" << std::endl;
    std::cout << "You can go one path from in(^) to out(*) gate if x1 == x2!" << std::endl;
    std::cout << "Path already exit if y1 == y2!" << std::endl << std::endl;

    pcb main_class;
    init(main_class);
    double x_now=1, y_now=1, x, y;

    while (true) {
        std::cout << "Map:" << std::endl << main_class << std::endl
                << std::endl << "Position now: x: " << x_now << " y: " << y_now << std::endl;
        std::cout << "next x: ";
        getValue(x);
        std::cout << "next y: ";
        getValue(y);

        int flag = 0, k, l;

        for(int i=0; i < main_class.len_(); ++i) {
            if (main_class[i].p.x == x and main_class[i].p.y == y) {
                flag = 1;
                k = i;
            }
            if (main_class[i].p.x == x_now and main_class[i].p.y == y_now) {
                l = i;
            }
        }

        if (flag and y == y_now) {
            x_now = x;
        } else if (flag and x == x_now) {
            try {
                main_class.add_link(l, k);
                y_now = y;
            } catch (const std::logic_error &e) {
                std::cout << "Bad move!!" << std::endl;
            }
        } else {
            std::cout << "Bad move!!" << std::endl;
        }

        if (y_now == 10) {
            std::cout << "You win!!!!" << std::endl;
            break;
        }
    }

    return 0;
}
