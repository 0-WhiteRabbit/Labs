#ifndef LAB_2_LINE_H
#define LAB_2_LINE_H

#include <cmath>
#include <stdexcept>

class Line {
private:
    double a;

public:
    explicit Line(double x = 0): a(x){}
    [[nodiscard]] double get_x() const { return a; }
    void set_x(double x) { a = x; }
    [[nodiscard]] double y_dependence_on_x(double x) const;
    [[nodiscard]] double r_dependence_on_phi(double phi) const;
    [[nodiscard]] double curvature_radius() const;
    [[nodiscard]] double loop_area()  const;
    [[nodiscard]] double volume_x() const;
    [[nodiscard]] double volume()  const;
};

#endif //LAB_2_LINE_H
