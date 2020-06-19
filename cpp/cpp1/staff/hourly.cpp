#include<iostream>
#include"hourly.hpp"

int Hourly::pay() const {
  return (payrate * hours);
}
