#ifndef UNTITLED_ENTRY_PERMIT_H
#define UNTITLED_ENTRY_PERMIT_H

#include "Document.h"
#include "iostream"
#include "vector"

class Entry_Permit : public Document {
private:
    std::vector<std::string> permission;
    std::string reason;
    Document *D;

public:
    Entry_Permit(const std::string &name, const std::string &expiryDate, const std::string &sex, const std::string &reason);

    void alter() override;

    void alter_date();

    void alter_permission();

    friend std::ostream &operator<<(std::ostream &os, const Entry_Permit &permit);
};


#endif //UNTITLED_ENTRY_PERMIT_H
