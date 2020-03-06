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

    auto zero = NegExpression(new LiteralExpression(0)).try_fold();

    BOOST_CHECK(zero.has_value());
    BOOST_CHECK_EQUAL(*zero, 0);
}

BOOST_AUTO_TEST_CASE(fold_not) {
    auto f = NotExpression(new LiteralExpression(true)).try_fold();
    auto t = NotExpression(new LiteralExpression(false)).try_fold();

    BOOST_CHECK(f.has_value());
    BOOST_CHECK_EQUAL(*f, false);

    BOOST_CHECK(t.has_value());
    BOOST_CHECK_EQUAL(*t, true);
}

BOOST_AUTO_TEST_CASE(fold_add) {
    auto sum = new AddExpression(new LiteralExpression(2), new LiteralExpression(2));
    auto four = sum->try_fold();

    BOOST_CHECK(four.has_value());
    BOOST_CHECK_EQUAL(*four, 4);

    auto four_plus_x = AddExpression(sum, new IdentifierExpression(std::string("x")));
    auto fail = four_plus_x.try_fold();

    BOOST_CHECK(!fail.has_value());
    BOOST_CHECK_NO_THROW(dynamic_cast<LiteralExpression *>(four_plus_x.left.get()));
    BOOST_CHECK_EQUAL(dynamic_cast<LiteralExpression *>(four_plus_x.left.get())->value, 4);
}

BOOST_AUTO_TEST_CASE(fold_sub) {
    auto sum = new SubExpression(new LiteralExpression(6), new LiteralExpression(2));
    auto four = sum->try_fold();

    BOOST_CHECK(four.has_value());
    BOOST_CHECK_EQUAL(*four, 4);

    auto four_sub_x = SubExpression(sum, new IdentifierExpression(std::string("x")));
    auto fail = four_sub_x.try_fold();

    BOOST_CHECK(!fail.has_value());
    BOOST_CHECK_NO_THROW(dynamic_cast<LiteralExpression *>(four_sub_x.left.get()));
    BOOST_CHECK_EQUAL(dynamic_cast<LiteralExpression *>(four_sub_x.left.get())->value, 4);
}

BOOST_AUTO_TEST_CASE(fold_mul) {
    auto sum = new MulExpression(new LiteralExpression(2), new LiteralExpression(2));
    auto four = sum->try_fold();

    BOOST_CHECK(four.has_value());
    BOOST_CHECK_EQUAL(*four, 4);

    auto four_mul_x = MulExpression(sum, new IdentifierExpression(std::string("x")));
    auto fail = four_mul_x.try_fold();

    BOOST_CHECK(!fail.has_value());
    BOOST_CHECK_NO_THROW(dynamic_cast<LiteralExpression *>(four_mul_x.left.get()));
    BOOST_CHECK_EQUAL(dynamic_cast<LiteralExpression *>(four_mul_x.left.get())->value, 4);
}

BOOST_AUTO_TEST_CASE(fold_div) {
    auto sum = new DivExpression(new LiteralExpression(8), new LiteralExpression(2));
    auto four = sum->try_fold();

    BOOST_CHECK(four.has_value());
    BOOST_CHECK_EQUAL(*four, 4);

    auto four_div_x = DivExpression(sum, new IdentifierExpression(std::string("x")));
    auto fail = four_div_x.try_fold();

    BOOST_CHECK(!fail.has_value());
    BOOST_CHECK_NO_THROW(dynamic_cast<LiteralExpression *>(four_div_x.left.get()));
    BOOST_CHECK_EQUAL(dynamic_cast<LiteralExpression *>(four_div_x.left.get())->value, 4);
}

BOOST_AUTO_TEST_CASE(fold_mod) {
    auto sum = new ModExpression(new LiteralExpression(14), new LiteralExpression(10));
    auto four = sum->try_fold();

    BOOST_CHECK(four.has_value());
    BOOST_CHECK_EQUAL(*four, 4);

    auto four_mod_x = ModExpression(sum, new IdentifierExpression(std::string("x")));
    auto fail = four_mod_x.try_fold();

    BOOST_CHECK(!fail.has_value());
    BOOST_CHECK_NO_THROW(dynamic_cast<LiteralExpression *>(four_mod_x.left.get()));
    BOOST_CHECK_EQUAL(dynamic_cast<LiteralExpression *>(four_mod_x.left.get())->value, 4);
}

BOOST_AUTO_TEST_CASE(fold_and) {
    auto t = AndExpression(new LiteralExpression(true), new LiteralExpression(true)).try_fold();
    BOOST_CHECK(t.has_value() && *t);

    auto f = AndExpression(new LiteralExpression(false), new LiteralExpression(true)).try_fold();
    BOOST_CHECK(f.has_value() && !*f);

    f = AndExpression(new LiteralExpression(true), new LiteralExpression(false)).try_fold();
    BOOST_CHECK(f.has_value() && !*f);

    f = AndExpression(new LiteralExpression(false), new LiteralExpression(false)).try_fold();
    BOOST_CHECK(f.has_value() && !*f);
}

BOOST_AUTO_TEST_CASE(fold_or) {
    auto t = OrExpression(new LiteralExpression(true), new LiteralExpression(true)).try_fold();
    BOOST_CHECK(t.has_value() && *t);

    t = OrExpression(new LiteralExpression(false), new LiteralExpression(true)).try_fold();
    BOOST_CHECK(t.has_value() && *t);

    t = OrExpression(new LiteralExpression(true), new LiteralExpression(false)).try_fold();
    BOOST_CHECK(t.has_value() && *t);

    auto f = OrExpression(new LiteralExpression(false), new LiteralExpression(false)).try_fold();
    BOOST_CHECK(f.has_value() && !*f);
}