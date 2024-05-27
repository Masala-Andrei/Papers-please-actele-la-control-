#ifndef UNTITLED_DOCUMENTFACTORY_H
#define UNTITLED_DOCUMENTFACTORY_H

#include "Document.h"
#include "Passport.h"
#include "Identity_Card.h"
#include "Entry_Permit.h"

class DocumentFactory {
public:
    static Document *createDocument(const std::string &type, const std::string &name, const std::string &sex,
                                    const std::string &expiry_date, const std::string &code = "",
                                    const std::string &zone = "", const std::string &city = "",
                                    const std::string &purpose = "");
};


#endif //UNTITLED_DOCUMENTFACTORY_H
