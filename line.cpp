#include "line.h"

double Line::y_dependence_on_x(double x) const {
    if ((fabs(a) - x) == 0) {
        throw std::invalid_argument("Division by zero. X can't equal a!");
    }
    if ((fabs(a) + x) / (fabs(a) - x) < 0) {
        throw std::invalid_argument("sqrt received negative argument!");
    }
    return x * sqrt((fabs(a) + x) / (fabs(a) - x));
}

double Line::r_dependence_on_phi(double phi) const {
    if (cos(phi) != 0) {
        return -(fabs(a)*cos(2*phi)/cos(phi));
    }
    return 100; //const
}

double Line::curvature_radius() const { return fabs(a)*sqrt(2); }

double Line::loop_area() const { return 2*a*a - 0.5*M_PI*a*a; }

double Line::volume_x() const { return M_PI*fabs(a*a*a)*(2*log(2) - 4.0/3.0); }

double Line::volume() const { return 2*a*a + 0.5*M_PI*a*a; }
