#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "rtweekend.h"
#include "vec3.h"

TEST_CASE("Vector class methods", "[vector]"){

 vec3 a(1,2,3);
 vec3 b(2,3,4);

 SECTION("vector addition"){
   vec3 sum = a+b;
   vec3 c(3, 5, 7);
   REQUIRE( sum[0] == c[0] );
   REQUIRE( sum[1] == c[1] );
   REQUIRE( sum[2] == c[2] );
 }
  
}
