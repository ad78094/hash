// Returns the load factor for the table
double getLoadFactor() const {
    double loadFactor = static_cast<double>(size) / static_cast<double>(table.size());
    return loadFactor;
}

// Calculates and returns the number collisions
int countCollisions() const {
    int collisionCount = 0;
    for (const auto& bucket : table) {
        if (bucket.size() > 1) {
            collisionCount += bucket.size() - 1;
        }
    }
    return collisionCount;
}

// Finds and returns the size of the bucket with the longest chain
int maxBucketsize() const {
    int largestBucket = 0;
    for (const auto& bucket : table) {
        if (bucket.size() > largestBucket) {
            largestBucket = bucket.size();
        }
    }
    return largestBucket;
} 
class YourContainerClass {
private:
    HashTable<YourKeyType, YourValueType> table;

public:
    // ... (existing functions)

    // Precondition - Receives a pointer to a user-defined hash function
    // Postcondition - Sets the hash function in HashTable.h to the user-defined function
    void setHashFunction(std::function<size_t(const YourKeyType&)> hashFunc) {
        table.setHashFunction(hashFunc);
    }

    // Postcondition - Displays the size of the hash table,
    // the number of buckets in the hash table,
    // the load factor of the hash table,
    // the number of collisions,
    // and the length of the longest chain
    void statistics() {
        std::cout << "Table size: " << table.size() << std::endl;
        std::cout << "Number of buckets: " << table.bucketCount() << std::endl;
        std::cout << "Load factor: " << table.getLoadFactor() << std::endl;
        std::cout << "Number of collisions: " << table.countCollisions() << std::endl;
        std::cout << "Length of the longest chain: " << table.maxBucketsize() << std::endl;
    }
}; 
// Function to get hash index using a custom hash function
size_t customHashFunction(const std::string& key) {
    // Use one of the provided hash functions or create your own
    size_t hashVal = 0;
    // ... (your hash function code)
    return hashVal % tableSize; // Adjust with your chosen table size
}

int main() {
    YourContainerClass container;
    
    // Set the table size and default hash function
    container.setHashFunction(std::hash<YourKeyType>());
    
    // Run the program with default hash function
    // ... (your existing program logic)

    // Display table statistics
    container.statistics();

    // Set a custom hash function
    container.setHashFunction(customHashFunction);

    // Run the program with custom hash function
    // ... (your existing program logic)

    // Display table statistics
    container.statistics();

    return 0;
} 
#include <iostream>
#include <string>

int main() {
    // Create an instance of YourContainerClass
    YourContainerClass container;

    // Set the table size and default hash function
    container.setHashFunction(std::hash<std::string>());

    // Add some key-value pairs to the hash table
    container.insert("John", 25);
    container.insert("Alice", 30);
    container.insert("Bob", 22);

    // Display table statistics after inserting initial data
    std::cout << "After Insertion:" << std::endl;
    container.statistics();

    // Run the program with custom hash function
    // Assuming you have a function 'runProgram()' that interacts with the hash table
    // ... runProgram();

    // Display table statistics after running the program with custom hash function
    std::cout << "After Running Program with Custom Hash Function:" << std::endl;
    container.statistics();

    return 0;
} 
