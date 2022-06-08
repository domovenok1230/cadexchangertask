#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <circle.h>
#include <ellipse.h>
#include <helix.h>
#include <base_curves.h>
#include <memory>
#include <vector>
#include <algorithm>

// generate random curve
std::shared_ptr<BaseCurve> RandomFactory() {
    const int type_number = 3;
    const int max_radius = 100;
    const int min_radius = 1;
    const int max_step = 100;
    const int min_step = 1;
    int type = std::rand() % 3;
    if (type == 0) {
        double radius = min_radius + (static_cast<float>(std::rand()) *
                                      static_cast<float>(max_radius - min_radius)) /
                                      RAND_MAX;
        return std::static_pointer_cast<BaseCurve>(std::make_shared<Circle>(radius));
    } else if (type == 1) {
        double radius_1 = min_radius + (static_cast<float>(std::rand()) *
                                        static_cast<float>(max_radius - min_radius)) /
                                        RAND_MAX;
        double radius_2 = min_radius + (static_cast<float>(std::rand()) *
                                        static_cast<float>(max_radius - min_radius)) /
                                           RAND_MAX;
        return std::static_pointer_cast<BaseCurve>(std::make_shared<Ellipse>(radius_1,
                                                                             radius_2));
    } else  {
        double radius = min_radius + (static_cast<float>(std::rand()) *
                                        static_cast<float>(max_radius - min_radius)) /
                                           RAND_MAX;
        double step = min_step + (static_cast<float>(std::rand()) *
                                        static_cast<float>(max_step - min_step)) /
                                           RAND_MAX;
        return std::static_pointer_cast<BaseCurve>(std::make_shared<Helix>(radius,
                                                                            step));
    }
}

int main() {
    int objects_number = 20;
    std::vector<std::shared_ptr<BaseCurve>> rand_curves;
    // generate random objects
    rand_curves.resize(objects_number);
    for (int i = 0; i < objects_number;i++) {
        rand_curves[i] = RandomFactory();
    }
    // print coord and first derivative in point PI/4
    for (int i = 0; i < objects_number; i++) {
        std::cout << " Point at PI/4 " << rand_curves[i]->GetPoint(M_PI_4);
        std::cout << " Derivative at PI/4 " << rand_curves[i]->GetDerivative(M_PI_4);
        rand_curves[i]->PrintCurveInfo();
        std::cout << std::endl;
    }
    // select only circles
    std::vector<std::shared_ptr<Circle>> circles;
    circles.resize(objects_number);
    int circle_number = 0;
    for (int i = 0; i < objects_number; i++) {
        auto cur_circle = std::dynamic_pointer_cast<Circle>(rand_curves[i]);
        if (cur_circle) {
            circles[circle_number] = cur_circle;
            circle_number++;
        }
    }
    circles.resize(circle_number);
    for (int i = 0; i < circles.size(); i++) {
        std::cout << " " << circles[i].use_count();
    }
    // sort by radius
    std::sort(circles.begin(), circles.end(),
              [](const std::shared_ptr<Circle>& var1, const std::shared_ptr<Circle>& var2) {
                  return var1->GetRadius() < var2->GetRadius();
              });
    // calculate sum of radius
    double radius_sum = 0;
    std::for_each(circles.begin(), circles.end(), [&radius_sum](const std::shared_ptr<Circle> &var)
                                                {var->PrintCurveInfo();
                                                 std::cout << std::endl;
                                                 radius_sum += var->GetRadius();});
    std::cout << "Sum of radius: " << radius_sum;
    return 0;
}