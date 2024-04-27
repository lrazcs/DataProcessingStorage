#include <string>
#include <unordered_map>
#include <stdexcept>
#include <memory>
using namespace std;

class InMemoryDB {
public:
    virtual ~InMemoryDB() {}
    virtual int get(const string& key) = 0;
    virtual void put(const string& key, int value) = 0;
    virtual void begin_transaction() = 0;
    virtual void commit() = 0;
    virtual void rollback() = 0;
};
