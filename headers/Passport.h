#ifndef UNTITLED_PASSPORT_H
#define UNTITLED_PASSPORT_H

#include "iostream"
#include "Document.h"


class Passport : public Document {
private:
    std::string zone, code, city;
    Document *D;
public:

    Passport() = default;

    Passport(
            const std::string &name,
            const std::string &sex,
            const std::string &code,
            const std::string &zone,
            const std::string &city,
            const std::string &expiry_date);

    ~Passport() override;

    [[maybe_unused]] Passport(const Passport &other);

    friend std::ostream &operator<<(std::ostream &out, const Passport &passport);

    Passport &operator=(const Passport &passport);

    void alter() override;

    static void generate_Passport(std::string &code, std::string &zone, std::string &city);

    static void generate_code(std::string &code);

    static void generate_city_zone(std::string &city, std::string &zone);

    void alter_date();

    void alter_zone();

    void setZone(const std::string &zone_);

    [[nodiscard]] const std::string &getZone() const;

};


#endif //UNTITLED_PASSPORT_H
