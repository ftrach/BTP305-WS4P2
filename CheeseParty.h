#ifndef SDDS_CHEESEPARTY_H
#define SDDS_CHEESEPARTY_H

#include "Cheese.h"

namespace sdds {

    class CheeseParty {
        Cheese* partyCheeses;
        size_t partyCount;

    public:
        CheeseParty();
        ~CheeseParty();

        CheeseParty(const CheeseParty& src);
        CheeseParty& operator=(const CheeseParty& src);

        CheeseParty(CheeseParty&& src) noexcept;
        CheeseParty& operator=(CheeseParty&& src) noexcept;

        void addCheese(const Cheese& cheese);
        bool isEmpty() const;
        void removeCheese();

        friend std::ostream& operator<<(std::ostream& os, const CheeseParty& party);
    };

}

#endif