#ifndef TYPE_H
#define TYPE_H
#include<iostream>

class Type {
private:
    int typeId;
    std::string type;
public:
    static int id;
    Type();
    explicit Type(std::string &&type);
    ~Type() = default;
    Type(Type &&m_type) noexcept ;
    Type(const Type &c_type);

    void setType(const std::string &new_type);
    std::string getType();

    [[nodiscard]] int GetId() const;

    Type &operator =(const Type &type);
    bool operator ==(const Type &type) const;

    friend std::ostream &operator <<(std::ostream &os, Type &type);
    friend std::istream &operator >>(std::istream &is, Type &type);
};



#endif //TYPE_H
