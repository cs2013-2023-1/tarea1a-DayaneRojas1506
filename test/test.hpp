#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../tarea/foo.h"

using namespace std;

auto random(int x, int y){ return rand() % (y-x+1) + x;}