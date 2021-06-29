#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include "pair.hpp"


template <typename K, typename V>
class Dict {
    using container_t = std::vector<Pair<K, V>>;
    container_t data_;

    // Returns iterator to entry containing the key, or end()
    auto hasKey(const K& key) const {
        auto it = std::find_if(data_.begin(), data_.end(), [=](Pair<K, V> p) -> bool
                               { return (key == p.first()); });
        return it;
    }
public:
    // add new value to dict
    void add(const K& key, const V& value) {
        if (hasKey(key) == data_.end())
            data_.push_back(Pair<K, V>(key, value));
        else
            throw std::invalid_argument("Key exists");
    }

    // get the value associated with a key 
    // or throw exception if no such key
    V getValue(const K& key) const {
        const auto it = hasKey(key);
        if (it == data_.end())
            throw std::invalid_argument("Key does not exist");
        return (*it).second();
    }

    // get a value associated with a key or a default
    V getValueOfDefault(const K& key, const V& defaultValue) const {
        const auto it = hasKey(key);
        if (it != data_.end())
            return (*it).second();
        else
            return defaultValue;
    }

    // alternative to getValue()
    V operator[](const K& key) const {
        return getValue(key);
    }
};

int main() {
    std::cout << "Associative array example\n";

    Dict<std::string, int> dict;
    dict.add("first", 10);
    dict.add("second", 100);

    std::cout << "dict[\"first\"] = " << dict["first"] << "\n";
    std::cout << "getValueOrDefault: " << dict.getValueOfDefault("t", 0) << "\n";

    try {
        dict.add("first", 7);
    }
    catch(const std::invalid_argument& e) {
        std::cerr << e.what() << "\n";
    }

    return 0;
}