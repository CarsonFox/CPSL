#pragma once

#include <vector>
#include <tuple>
#include <memory>

#include "Type.hpp"
#include "FrontEnd/AST/IdentifierList.hpp"

struct RecordType : Type {
    using member = std::pair<std::vector<std::string>, std::shared_ptr<Type>>;
    std::vector<member> members;

    RecordType(IdentifierList *, Type *);

    RecordType(RecordType *, IdentifierList *, Type *);

    ~RecordType() override = default;

    void print() const override;
};