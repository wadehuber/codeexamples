#include"hourly.hpp"

int Hourly::pay() const {
    return (payrate * hours);
}

int Hourly::bonus(int b) const {
    return (b * (hours / 40.0));
}
