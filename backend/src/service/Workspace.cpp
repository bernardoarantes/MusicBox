#ifndef WORKSPACE
#define WORKSPACE

#include "entity/EntryEntity.cpp"
#include "entity/UserEntity.cpp"
#include "json.hpp"
#include <map>
#include <string>
#include <vector>

using std::map;
using std::string;
using std::vector;

class Workspace {
    private:
        map<string, vector<string>> user_to_entry = map<string, vector<string>>();

    public:
        void addEntry(const string &user_id, const string &entry_id, const string &type, const string &target_id, const string &comment, unsigned rating) {
            new EntryEntity(entry_id, type, target_id, comment, rating);
            user_to_entry[user_id].push_back(entry_id);
        }

        void addUser(const string &user_id, const string &name, const string &password) {
            new UserEntity(user_id, name, password);
            user_to_entry.insert({user_id, vector<string>()});
        }
};

#endif
