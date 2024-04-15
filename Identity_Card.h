#ifndef UNTITLED_IDENTITY_CARD_H
#define UNTITLED_IDENTITY_CARD_H

#include <ostream>
#include "Document.h"

class Identity_Card : public Document {
private:
    std::string zone;

public:
    Identity_Card(const std::string &name,
                  const std::string &sex,
                  const std::string &expiry_date,
                  const std::string &zone);

    void setZone(const std::string &zone);

    ~Identity_Card() override;

    void alter() override;

    void alter_zone();

    friend std::ostream &operator<<(std::ostream &os, const Identity_Card &card);

};
#endif //UNTITLED_IDENTITY_CARD_H
