#include "CheeseShop.h"

namespace sdds {

    CheeseShop::CheeseShop() : shopName(""), shopCheeses(nullptr), shopCount(0) {}

    CheeseShop::CheeseShop(const std::string& name) : shopName(name), shopCheeses(nullptr), shopCount(0) {}

    CheeseShop::~CheeseShop() {
        delete[] shopCheeses;
    }

    void CheeseShop::setName(const std::string& name) {
        shopName = name;
    }

    CheeseShop::CheeseShop(const CheeseShop& src) : shopName(src.shopName), shopCount(src.shopCount) {
        if (src.shopCheeses != nullptr) {
            shopCheeses = new Cheese[src.shopCount];
            for (size_t i = 0; i < src.shopCount; ++i) {
                shopCheeses[i] = src.shopCheeses[i];
            }
        }
        else {
            shopCheeses = nullptr;
        }
    }

    CheeseShop& CheeseShop::operator=(const CheeseShop& src) {
        if (this != &src) {
            delete[] shopCheeses;
            shopName = src.shopName;
            shopCount = src.shopCount;
            if (src.shopCheeses != nullptr) {
                shopCheeses = new Cheese[src.shopCount];
                for (size_t i = 0; i < src.shopCount; ++i) {
                    shopCheeses[i] = src.shopCheeses[i];
                }
            }
            else {
                shopCheeses = nullptr;
            }
        }
        return *this;
    }

    CheeseShop::CheeseShop(CheeseShop&& src) noexcept : shopName(std::move(src.shopName)), shopCheeses(src.shopCheeses), shopCount(src.shopCount) {
        src.shopCheeses = nullptr;
        src.shopCount = 0;
    }

    CheeseShop& CheeseShop::operator=(CheeseShop&& src) noexcept {
        if (this != &src) {
            delete[] shopCheeses;
            shopName = std::move(src.shopName);
            shopCheeses = src.shopCheeses;
            shopCount = src.shopCount;
            src.shopCheeses = nullptr;
            src.shopCount = 0;
        }
        return *this;
    }

    void CheeseShop::addCheese(const Cheese& cheese) {
        Cheese* newShopCheeses = new Cheese[shopCount + 1];
        for (size_t i = 0; i < shopCount; ++i) {
            newShopCheeses[i] = shopCheeses[i];
        }
        newShopCheeses[shopCount] = cheese;
        delete[] shopCheeses;
        shopCheeses = newShopCheeses;
        shopCount++;
    }

    bool CheeseShop::isEmpty() const {
        return shopCount == 0;
    }

    std::ostream& operator<<(std::ostream& os, const CheeseShop& shop) {
        os << "--------------------------\n";
        os << shop.shopName << " (";
        if (shop.isEmpty()) {
            os << "empty)\n";
            os << "--------------------------\n";
            os << "Cheese Magic\n";
            os << "--------------------------\n";
            os << "This shop is out of cheese!\n";
        }
        else {
            os << "add cheeses to empty shop)\n";
            os << "--------------------------\n";
            os << "Cheese Magic\n";
            os << "--------------------------\n"; // Add this line
            for (size_t i = 0; i < shop.shopCount; i++) {
                os << shop.shopCheeses[i];
            }
        }
        os << "--------------------------\n"; // Add this line
        return os;
    }
}