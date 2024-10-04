#include "globals.h"
#include <iostream>
#include <ostream>
#include <pthread.h>

using std::cout;
using std::endl;

int main() {
  global_array = new int[3];

  global_array[0] = 1;
  global_array[1] = 2;
  global_array[2] = 3;

  cout << global_array[1] << endl;
  return 0;
}
