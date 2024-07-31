// demo_map.cpp
// example for "C++17 In Detail"
// by Bartlomiej Filipek
// 2018/2019

#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> mapUsersAge { { "Alex", 45 }, { "John", 25 } };
    
    std::map mapCopy{mapUsersAge};
    
    if (auto [iter, wasAdded] = mapCopy.insert_or_assign("John", 26); !wasAdded)
        std::cout << iter->first << " reassigned...\n";
        
    for (const auto& [key, value] : mapCopy)
        std::cout << key << ", " << value << '\n';

    /**
     * 
     * iter->first:
        Accesses the key of the element pointed to by the iterator iter.
        In the context of std::map, iter is an iterator to a std::pair<const std::string, int>, and first is the key of this pair.
     
        mapCopy.insert_or_assign("John", 26):

        This function tries to insert a key-value pair ("John", 26) into the mapCopy. If the key "John" already exists in the map, it updates the value to 26. The function returns a pair:
        An iterator pointing to the element in the map.
        A boolean indicating whether a new element was inserted (true) or an existing element was updated (false).
        auto [iter, wasAdded] = mapCopy.insert_or_assign("John", 26):

        This uses C++17 structured bindings to unpack the returned pair from insert_or_assign into iter and wasAdded.
        iter->first:

        iter is an iterator to a std::pair<const std::string, int> in the map. In a std::map, each element is a pair where first is the key and second is the value.
        iter->first accesses the key part of the pair that the iterator points to. So, iter->first is "John" in this case.


     * auto&:
        Declares key and value as references to the elements of the map during iteration.
        const auto& ensures that elements are not modified and avoids unnecessary copying, providing efficient read-only access to the elements.
     
        const auto& [key, value]:

        This is another example of C++17 structured bindings. It declares key and value as references to the components of each element in the map. Here:
        auto& indicates that key and value are references.
        const means that the elements of the map will not be modified within the loop.
        Why auto&?:

        Using auto& ensures that we are not copying the elements of the map. Instead, we are referencing them directly, which can be more efficient.
        const is used to prevent modifications to the elements, ensuring read-only access.
     * 
    */
}