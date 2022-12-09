//
// Created by student on 5/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_RANDOM_H
#define INC_2022_PROJECT_BWC00_RANDOM_H

#include <random>

namespace logic {
    class Random {
    public:
        Random(const Random&) = delete;
        static Random& _getInstance();
        static int uniformInt(int a, int b);
        static double uniformReal(double a, double b);
        static int Bernoulli(double p);
        static double Normal(double m, double n);
    private:
        Random();
        int _uniformInt(int a, int b);
        double _uniformReal(double a, double b);
        int _bernoulli(double p);
        double _normal(double m, double n);
        std::random_device _r;
        std::mt19937 _generator;
    };
}


#endif //INC_2022_PROJECT_BWC00_RANDOM_H
