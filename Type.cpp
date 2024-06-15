#include "Type.h"

Type::Type(std::string &&type):type{type} {
    id++;
    typeId = id;
}

Type::Type():Type{"Default"} {
    typeId = 0;
    id++;
}

std::string Type::getType() {
    return type;
}

void Type::setType(const std::string &new_type) {
    type = new_type;
}

int Type::GetId() const {
    return typeId;
}

std::ostream &operator <<(std::ostream &os, Type &type) {
    os << type.typeId << std::endl << type.type << std::endl;
    return os;
}
std::istream &operator >>(std::istream &is, Type &type) {
    is >> type.typeId >> type.type;
    return is;
}
int Type::id = 0;

Type &Type::operator=(const Type &n_type) {
    this->typeId = n_type.typeId;
    this->type = n_type.type;
    return *this;
}

bool Type::operator==(const Type &type) const {
    return (typeId == type.typeId);
}


