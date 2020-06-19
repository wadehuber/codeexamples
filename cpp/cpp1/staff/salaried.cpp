#include<iostream>
#include"salaried.hpp"

int Salaried::pay() const {
  return (payrate / 26);
}
