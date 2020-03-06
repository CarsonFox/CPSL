#define BOOST_TEST_MODULE M_Test

#include <boost/test/unit_test.hpp>

#include "FrontEnd/AST/AllNodes.hpp"

BOOST_AUTO_TEST_CASE(trivial) {
    BOOST_CHECK(true);
}

BOOST_AUTO_TEST_CASE(fold_neg) {
    auto neg_10 = NegExpression(new LiteralExpression(10)).try_fold();

    BOOST_CHECK(neg_10.has_value());
    BOOST_CHECK_EQUAL(*neg_10, -10);
}