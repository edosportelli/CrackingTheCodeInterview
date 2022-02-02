/* Hash table implementation as a vector of linked lists */

#include <vector>
#include <boost/functional/hash.hpp>
#include <iostream>

#define SIZE 10

class Node
{
    public:
        Node(std::string key_, std::string value_) : key(key_), value(value_) {}
        std::shared_ptr<Node> next;
        std::string key{};
        std::string value{};
    
    private:
};

class HashTable
{
  public:
    HashTable() {}

    void insert(std::string key, std::string value)
    {
        int index = get_index(key);
        std::shared_ptr<Node> new_node = std::make_shared<Node>(key, value);

        if (table[index] == nullptr)
        {
            table[index] = new_node;
        }
        else 
        {
            std::shared_ptr<Node> empty_node = table[index];    // Start from the beginning

            while (empty_node->next != nullptr)
            {
                empty_node = empty_node->next;
            }

            empty_node->next = new_node;
        }
    }

    std::string get_value(std::string key)
    {
        uint8_t index = get_index(key);
        std::string value;

        std::shared_ptr<Node> search_node = table[index];

        while (search_node != nullptr)
        {
            if (search_node->key == key)
            {
                value = search_node->value;
                std::cout << "Value for key: " << key << " " << value << std::endl;
                return value;
            }

            search_node = search_node->next;
        }

        std::cout << "No value for key: " << key << std::endl;

        return "";
    }

    void print_all(std::shared_ptr<Node> entry)
    {
        std::shared_ptr<Node> n = entry;

        while (n != nullptr)
        {
            if (n->key == "7" | n->key == "8" | n->key == "9")
                std::cout << n->key << " " << n->value << std::endl;
            n = n->next;
        }
    }

  private:
    int get_index(std::string key)
    {
        int hash_code = std::hash<std::string>()(key);

        if (hash_code < 0)
            hash_code *= -1;

        return hash_code % SIZE;
    }

    std::shared_ptr<Node> table[SIZE];
};

int main()
{
    HashTable table;
    table.insert("1", "bello");
    table.insert("2", "figo");
    table.insert("3", "mio");
    table.insert("4", "amore");
    table.insert("5", "pino");
    table.insert("6", "piano");
    table.insert("7", "cielo");
    table.insert("8", "rosa");
    table.insert("9", "vino");

    table.get_value("1");
    table.get_value("2");
    table.get_value("3");    
    table.get_value("4");
    table.get_value("5");
    table.get_value("6");
    table.get_value("7");
    table.get_value("8");
    table.get_value("9");
    table.get_value("10");
}