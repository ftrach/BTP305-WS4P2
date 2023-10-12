#include "CheeseParty.h"

namespace sdds {

    CheeseParty::CheeseParty() : partyCheeses(nullptr), partyCount(0) {}

    CheeseParty::~CheeseParty() {
        delete[] partyCheeses;
    }

    CheeseParty::CheeseParty(const CheeseParty& src) : partyCount(src.partyCount) {
        if (src.partyCheeses != nullptr) {
            partyCheeses = new Cheese[src.partyCount];
            for (size_t i = 0; i < src.partyCount; ++i) {
                partyCheeses[i] = src.partyCheeses[i];
            }
        }
        else {
            partyCheeses = nullptr;
        }
    }

    CheeseParty& CheeseParty::operator=(const CheeseParty& src) {
        if (this != &src) {
            delete[] partyCheeses;
            partyCount = src.partyCount;
            if (src.partyCheeses != nullptr) {
                partyCheeses = new Cheese[src.partyCount];
                for (size_t i = 0; i < src.partyCount; ++i) {
                    partyCheeses[i] = src.partyCheeses[i];
                }
            }
            else {
                partyCheeses = nullptr;
            }
        }
        return *this;
    }

    CheeseParty::CheeseParty(CheeseParty&& src) noexcept : partyCheeses(src.partyCheeses), partyCount(src.partyCount) {
        src.partyCheeses = nullptr;
        src.partyCount = 0;
    }

    CheeseParty& CheeseParty::operator=(CheeseParty&& src) noexcept {
        if (this != &src) {
            delete[] partyCheeses;
            partyCheeses = src.partyCheeses;
            partyCount = src.partyCount;
            src.partyCheeses = nullptr;
            src.partyCount = 0;
        }
        return *this;
    }

    void CheeseParty::addCheese(const Cheese& cheese) {
        Cheese* newPartyCheeses = new Cheese[partyCount + 1];
        for (size_t i = 0; i < partyCount; ++i) {
            newPartyCheeses[i] = partyCheeses[i];
        }
        newPartyCheeses[partyCount] = cheese;
        delete[] partyCheeses;
        partyCheeses = newPartyCheeses;
        partyCount++;
    }

    bool CheeseParty::isEmpty() const {
        return partyCount == 0;
    }

    void CheeseParty::removeCheese() {
        if (partyCount > 0) {
            Cheese* newPartyCheeses = new Cheese[partyCount - 1];
            for (size_t i = 0; i < partyCount - 1; ++i) {
                newPartyCheeses[i] = partyCheeses[i];
            }
            delete[] partyCheeses;
            partyCheeses = newPartyCheeses;
            partyCount--;
        }
    }

    std::ostream& operator<<(std::ostream& os, const CheeseParty& party) {
        os << "--------------------------\n";
        os << "Cheese Party\n";
        if (party.partyCount > 0) {
            for (size_t i = 0; i < party.partyCount; ++i) {
                os << party.partyCheeses[i];
            }
        }
        else {
            os << "This party is just getting started!\n";
        }
        os << "--------------------------\n";
        return os;
    }
}