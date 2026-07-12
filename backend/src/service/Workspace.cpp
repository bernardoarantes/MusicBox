#ifndef WORKSPACE
#define WORKSPACE

#include "entity/EntryEntity.cpp"
#include "entity/UserEntity.cpp"
#include "exceptions/EntityNotFoundException.cpp"
#include "json.hpp"
#include "service/persistence/Repository.cpp"
#include "service/UserParser.cpp"
#include "service/EntryParser.cpp"
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

using std::map;
using std::string;
using std::vector;

class Workspace {
    private:
        Repository *users;
        Repository *entries;

        const UserEntity getUser(const string& user_id){
            for (const Entity *user : *users) {
                if (user->getId() == user_id) {
                    return *((UserEntity *) user);
                }
            }
            throw EntityNotFoundException("Bad user id " + user_id);
        }

        const EntryEntity getEntry(const string &entry_id) {
            for (const Entity *entry : *entries) {
                if (entry->getId() == entry_id) {
                    return *((EntryEntity *) entry);
                }
            }
            throw EntityNotFoundException("Bad entry id " + entry_id);
        }

    public:
        Workspace(Repository &users, Repository &entries) :
            users(&users),
            entries(&entries) {}

        void addEntry(const string &user_id, const string &entry_id, const string &type, const string &target_id, const string &comment, unsigned rating) {
            entries->save(new EntryEntity(entry_id, user_id, type, target_id, comment, rating));
        }

        void addUser(const string &user_id, const string &email, const string &name, const string &password) {
            users->save(new UserEntity(user_id, email, name, password));
        }

        vector<EntryEntity> listEntriesByUser(const string& user_id){
            vector<EntryEntity> user_entries = vector<EntryEntity>();
            for (const Entity *entry : *entries) {
                EntryEntity *_entry = (EntryEntity *) entry;
                if (_entry->getOwnerId() == user_id)
                    user_entries.push_back(*_entry);
            }
            return user_entries;
        };
};

#endif


