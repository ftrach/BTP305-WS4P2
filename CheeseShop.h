#ifndef SDDS_CHEESESHOP_H
#define SDDS_CHEESESHOP_H

#include "Cheese.h"

namespace sdds {

    class CheeseShop {
        std::string shopName;
        Cheese* shopCheeses;
        size_t shopCount;

    public:
        CheeseShop();
        CheeseShop(const std::string& name);
        ~CheeseShop();

        void setName(const std::string& name);

        CheeseShop(const CheeseShop& src);
        CheeseShop& operator=(const CheeseShop& src);

        CheeseShop(CheeseShop&& src) noexcept;
        CheeseShop& operator=(CheeseShop&& src) noexcept;

        void addCheese(const Cheese& cheese);
        bool isEmpty() const;

        friend std::ostream& operator<<(std::ostream& os, const CheeseShop& shop);
    };

}

#endif