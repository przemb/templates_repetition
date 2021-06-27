#include <iostream>
#include <vector>
#include <algorithm>
#include "pair.hpp"

template <typename K, typename V>
class Dict {
    using container_t = std::vector<Pair<K, V>>;
    container_t data_;

    auto hasKey(const K& key) const {
        auto it = std::find_if(data_.begin(), data_.end(), 
        [=](Pair<K, V> p) -> bool
        { return (key == p.first()); });

        return it;
    }
public:
    // Add a new entry
    // if duplicate - error
    void add(const K& key, const V& value) {
        if (hasKey(key) == data_.end())
            data_.push_back(Pair<K, V>(key, value));
        else
            throw std::invalid_argument("Key exists");
    }

    // Get the value associated with a key
    // Throw if no such key
    V getValue(const K& key) const {
        auto it = hasKey(key);
        if (it != data_.end())
            return (*it).second();
        else
            throw std::invalid_argument("No such key");
    }

    V getValueOrDefault(const K& key, const V& defaultValue) const {
        auto it = hasKey(key);
        if (it != data_.end())
            return (*it).second();
        else
            return defaultValue;
    }

    V operator[](const K& key) const {
        return getValue(key);
    }
};



int main() {
    std::cout << "Associative array example \n\n";

    Dict<std::string, int> dict;
    dict.add("first", 10);
    dict.add("second", 100);

    std::cout << "dict[\"first\"] = " << dict["first"] << "\n";
    std::cout << "getValueOrDefault: " << dict.getValueOrDefault("t", 0) << "\n";

    // should throw
    // dict.add("first", 777);

    return 0;
}