#define BOOST_TEST_MODULE M_Test

#include <boost/test/unit_test.hpp>

#include "FrontEnd/AST/AllNodes.hpp"

BOOST_AUTO_TEST_CASE(trivial) {
    BOOST_CHECK(true);
}