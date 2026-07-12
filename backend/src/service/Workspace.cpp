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
            throw EntityNotFoundException("bad user id " + user_id);
        }

        const EntryEntity getEntry(const string &entry_id) {
            for (const Entity *entry : *entries) {
                if (entry->getId() == entry_id) {
                    return *((EntryEntity *) entry);
                }
            }
            throw EntityNotFoundException("bad entry id " + entry_id);
        }

    public:
        Workspace(Repository &users, Repository &entries) :
            users(&users),
            entries(&entries) {}

        void addEntry(EntryEntity *new_entry) {
            entries->save(new_entry);
        }

        void addUser(UserEntity *new_user) {
            users->save(new_user);
        }

        vector<EntryEntity> listEntriesByUser(const string& user_id){
            vector<EntryEntity> user_entries = vector<EntryEntity>();
            for (const Entity *_entry : *entries) {
                EntryEntity *entry = (EntryEntity *) _entry;
                if (entry->getOwnerId() == user_id)
                    user_entries.push_back(*entry);
            }
            return user_entries;
        };

        bool userWithEmailExists(const string &email) const {
            for (const Entity *_user : *users) {
                UserEntity *user = (UserEntity *) _user;
                if (user->hasEmail(email))
                    return false;
            }
            return true;
        }
};

#endif


