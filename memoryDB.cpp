#include "memoryDB.h"
#include <iostream>
using namespace std;

class memoryDB : public InMemoryDB {
private:
    unordered_map<string, int> mainStore;
    unique_ptr<unordered_map<string, int>> transactionStore;
    bool inTransaction = false;

public:
    int get(const string& key) override {
        if (inTransaction && transactionStore->count(key))
            return (*transactionStore)[key];
        if (mainStore.count(key))
            return mainStore[key];
        throw runtime_error("Key not found");
    }

    void put(const string& key, int value) override {
        if (!inTransaction) {
            throw runtime_error("No transaction is in progress.");
        }
        (*transactionStore)[key] = value;
    }

    void begin_transaction() override {
        if (inTransaction) {
            throw runtime_error("Transaction already in progress.");
        }
        inTransaction = true;
        transactionStore.reset(new unordered_map<string, int>);
    }

    void commit() override {
        if (!inTransaction) {
            throw runtime_error("No transaction is in progress.");
        }
        for (const auto& kv : *transactionStore) {
            mainStore[kv.first] = kv.second;
        }
        transactionStore.reset(nullptr);
        inTransaction = false;
    }

    void rollback() override {
        if (!inTransaction) {
            throw runtime_error("No transaction is in progress.");
        }
        transactionStore.reset(nullptr);
        inTransaction = false;
    }
};
