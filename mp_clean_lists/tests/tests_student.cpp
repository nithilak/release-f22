#include <catch2/catch_test_macros.hpp>
#include "tests_helper.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

#include "List.h"

using namespace cs225;

// THESE TESTS ARE NOT GRADED AND ARE FOR YOU ONLY

TEST_CASE("Hello World", "") {
    std::string hello = "Hello World!";

    REQUIRE( hello == "Hello World!" );
}

TEST_CASE("\"In an empty list, both head and tail are NULL.\"", "[empty]") {
    List<int> list;

    REQUIRE( list.empty() == true );
}

TEST_CASE("insertFront and insertBack at start are the same", "[length][insertFront][insertBack]") {
    List<int> list1;

    REQUIRE( list1.empty() == true );

    list1.insertFront(1);

    List<int> list2;

    list2.insertBack(1);

    // REQUIRE(list1 == list2);
}

