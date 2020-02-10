#include "ChrExpression.hpp"

ChrExpression::ChrExpression(Expression *e) : expr(e) {

}

void ChrExpression::accept(Visitor &visitor) {
    visitor.visit(this);
}
