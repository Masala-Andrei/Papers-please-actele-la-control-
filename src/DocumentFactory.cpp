#include "../headers/DocumentFactory.h"

Document *DocumentFactory::createDocument(const std::string &type, const std::string &name, const std::string &sex,
                                          const std::string &expiry_date, const std::string &code,
                                          const std::string &zone, const std::string &city,
                                          const std::string &purpose) {
    if (type == "Passport") {
        return new Passport(name, sex, code, zone, city, expiry_date);
    } else if (type == "Entry_Permit") {
        return new Entry_Permit(name, expiry_date, sex, purpose);
    } else if (type == "Identity_Card") {
        return new Identity_Card(name, sex, expiry_date, zone);
    }
    return nullptr;
}
