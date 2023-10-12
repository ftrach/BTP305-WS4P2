#include <iomanip>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

#include "Cheese.h"

namespace sdds {

    Cheese::Cheese() : cheeseName(""), cheesePrice(0.0), cheeseAmount(0), cheeseDescription("") {}

    Cheese::Cheese(const std::string& name, double price, int amount, const std::string& description)
        : cheeseName(name), cheesePrice(price), cheeseAmount(amount), cheeseDescription(description) {}

    Cheese::~Cheese() {}



    Cheese::Cheese(const std::string& line) : cheeseName(""), cheesePrice(0.0), cheeseAmount(0), cheeseDescription("") {
        // Split the input line by ',' and remove extra spaces
        std::vector<std::string> values;
        std::istringstream iss(line);
        std::string value;
        while (std::getline(iss, value, ',')) {
            // Remove leading and trailing spaces from each value
            value.erase(0, value.find_first_not_of(" "));
            value.erase(value.find_last_not_of(" ") + 1);
            values.push_back(value);
        }

        // Check if there are enough values (Name, Weight, Price Per Gram, Features)
        if (values.size() >= 4) {
            cheeseName = values[0];
            cheeseAmount = std::stoi(values[1]);
            cheesePrice = std::stod(values[2]);

            // Store the features
            for (size_t i = 3; i < values.size(); ++i) {
                cheeseDescription += values[i];
                if (i < values.size() - 1) {
                    cheeseDescription += ", ";  // Add a comma and space if not the last feature
                }
            }
        }
    }




    void Cheese::setName(const std::string& name) {
        cheeseName = name;
    }

    void Cheese::setPrice(double price) {
        cheesePrice = price;
    }

    void Cheese::setAmount(int amount) {
        cheeseAmount = amount;
    }

    void Cheese::setDescription(const std::string& description) {
        cheeseDescription = description;
    }

    std::string Cheese::getName() const {
        return cheeseName;
    }

    double Cheese::getPrice() const {
        return cheesePrice;
    }

    int Cheese::getAmount() const {
        return cheeseAmount;
    }

    std::string Cheese::getDescription() const {
        return cheeseDescription;
    }

    bool Cheese::isEmpty() const {
        return cheeseName.empty() || cheesePrice == 0.0 || cheeseAmount == 0;
    }


    Cheese Cheese::slice(int grams) const {
        Cheese slicedCheese(*this);

        if (grams >= slicedCheese.getAmount()) {
            slicedCheese.setAmount(0);
            slicedCheese.setDescription("");
            slicedCheese.setPrice(0.0);
            slicedCheese.setName("NaC");
        }
        else {
            slicedCheese.setAmount(grams); // Set the amount to the sliced grams
        }

        return slicedCheese;
    }


    std::vector<std::string> Cheese::getFeatures() const {
        std::vector<std::string> features;
        std::istringstream iss(cheeseDescription);
        std::string feature;

        while (std::getline(iss, feature, ',')) {
            // Trim leading and trailing spaces from each feature
            feature.erase(0, feature.find_first_not_of(" "));
            feature.erase(feature.find_last_not_of(" ") + 1);

            // Transform the feature to title case (capitalizing each word)
            std::transform(feature.begin(), feature.end(), feature.begin(), [](unsigned char c) {
                return std::tolower(c);
                });
            feature[0] = std::toupper(feature[0]);

            features.push_back(feature);
        }

        return features;
    }


    std::ostream& operator<<(std::ostream& os, const Cheese& cheese) {
        os << "|" << std::left << std::setw(21) << cheese.cheeseName << "|"
            << std::left << std::setw(5) << cheese.cheeseAmount << " |";

        // Ensure that the price has a fixed format with 2 decimal places
        os << std::fixed << std::setprecision(2) << std::setw(6) << cheese.cheesePrice << " |";

        // Join the features without commas
        std::string features = cheese.cheeseDescription;
        size_t found = features.find(",");
        while (found != std::string::npos) {
            features.replace(found, 2, " ");
            found = features.find(",", found + 1);
        }

        // Calculate the number of dashes based on the maximum width
        int numDashes = 69 - (21 + 5 + 6 + features.length());  // 69 instead of 70
        os << std::right << std::setw(numDashes) << features << " |" << std::endl;

        return os;
    }






}  // namespace sdds