#ifndef SDDS_CHEESE_H
#define SDDS_CHEESE_H

#include <iomanip>
#include <sstream>
#include <iostream>
#include <vector>


namespace sdds {

    class Cheese {
        std::string cheeseName;
        double cheesePrice;
        int cheeseAmount;
        std::string cheeseDescription;
        std::vector<std::string> m_features;

    public:
        Cheese();
        Cheese(const std::string& name, double price, int amount, const std::string& description);
        ~Cheese();
        explicit Cheese(const std::string& name);
        friend std::ostream& operator<<(std::ostream& os, const Cheese& cheese);
        std::string getFormattedString() const;

        void setName(const std::string& name);
        void setPrice(double price);
        void setAmount(int amount);
        void setDescription(const std::string& description);

        std::string getName() const;
        double getPrice() const;
        int getAmount() const;
        std::string getDescription() const;

        bool isEmpty() const;

        Cheese slice(int grams) const;
        void display(std::ostream& os) const;

        friend std::ostream& operator<<(std::ostream& os, const Cheese& cheese);

        std::vector<std::string> getFeatures() const;
    };

}

#endif