#include "RecordAccess.hpp"

RecordAccess::RecordAccess(char *record, char *member) : record(record), member(member) {
    free(record);
    free(member);
}

void RecordAccess::prettyPrint() const {
    std::cout << this->record << "." << this->member;
}
