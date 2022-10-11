#include <iostream>
#include "line.h"


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
    printf("\n1 - get y from x\n"
           "2 - get r from phi\n"
           "3 - get R\n"
           "4 - get area AOM1\n"
           "5 - get volume\n"
           "6 - get area OU’ - OV’\n"
           "7 - exit.\n");
}

int main() {
    double a_x;
    int buf;

    std::cout << "Enter x of a: " << std::endl;
    buf = getValue(a_x);
    if (buf == 0)
        return 0;

    Line main_class(a_x;

    while (true) {
        int k;
        print_menu();
        do {
            std::cout << ">>> " << std::endl;
            buf = getInt(k);
            if (buf == 0) {
                return 0;
            }
        } while (buf == -1);

        switch (k) {
            case 7:
                std::cout << "Exit!" << std::endl;
                return 0;
            case 1:
                double x;
                std::cout << "Input x: " << std::endl;
                getValue(x);
                try {
                    std::cout << "Y: " << main_class.y_dependence_on_x(x) << " " << -main_class.y_dependence_on_x(x) << std::endl;
                }
                catch (const std::invalid_argument& e) {
                    std::cout << "SQRT from negative number!" << std::endl;
                }
                break;
            case 2: {
                double phi;
                std::cout << "Input phi: " << std::endl;
                getValue(phi);
                if (main_class.r_dependence_on_phi(phi) < 0) {
                    std::cout << "Out of range!\n";
                    break;
                }
                std::cout << "r: " << main_class.r_dependence_on_phi(phi) << std::endl;
                break;
            }
            case 3: {
                std::cout << "R: " << main_class.curvature_radius() << std::endl;
                break;
            }
            case 4: {
                std::cout << "Area: " << main_class.loop_area() << std::endl;
                break;
            }
            case 5: {
                std::cout << "Volume: " << main_class.volume_x() << std::endl;
                break;
            }
            case 6: {
                std::cout << "Volume x: " << main_class.volume() << std::endl;
                break;
            }
            default:
                std::cout << "Incorrect command!" << std::endl;
                break;
        }
    }
}
