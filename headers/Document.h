#ifndef UNTITLED_DOCUMENT_H
#define UNTITLED_DOCUMENT_H

#include "iostream"

class Document {
protected:
    std::string name, expiry_date, sex;

public:
    explicit Document(const std::string &name, const std::string &expiry_date, const std::string &sex);

    virtual ~Document();

    virtual void alter() = 0;

    static void generate_name(std::string &name, std::string &sex);

    void setExpiryDate(const std::string &expiryDate);
};


#endif //UNTITLED_DOCUMENT_H
