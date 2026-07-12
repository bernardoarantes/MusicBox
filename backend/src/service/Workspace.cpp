#ifndef WORKSPACE
#define WORKSPACE
#include "exception"
#include "entity/EntryEntity.cpp"
#include "entity/UserEntity.cpp"
#include "json.hpp"
#include <map>
#include <string>
#include <fstream>
#include <vector>
#include <stdexcept>
#include "exceptions\EntityNotFoundException.cpp"

using std::map;
using std::string;
using std::vector;

class Workspace {
    private:
        vector<UserEntity*> users = vector<UserEntity*>();
        vector<EntryEntity*> entries = vector<EntryEntity*>();
        string path_users;
        string path_entries;
        UserEntity findUser(const string& id){
            for (UserEntity* user: users) {
                if (user->getId() == id) return *user;
            }
        };
        EntryEntity findEntry(const string& id){
            for (EntryEntity* entry: entries) {
                if (entry->getId() == id) return *entry;
            }
        };
    public:
        Workspace(const string& path_u, const string& path_e) {
            path_users = path_u;
            path_entries = path_e;
            try{
            std::ifstream arc(path_users);
            if(!arc.is_open()) throw EntityNotFound("Caminho do Arquivo de Users não pôde ser aberto");
            arc.close();
            } catch(const EntityNotFound& e){
            }
            try{
            std::ifstream arc(path_entries);
            if(!arc.is_open()) throw EntityNotFound("Caminho do Arquivo de Reviews não pôde ser aberto");
            arc.close();
            } catch(const EntityNotFound& e){
            }
        }
        void addEntry(const string &user_id, const string &entry_id, const string &type, const string &target_id, const string &comment, unsigned rating) {
            entries.push_back(new EntryEntity(entry_id, type, target_id, comment, rating));
        }

        void addUser(const string &user_id, const string &name, const string &password) {
            users.push_back(new UserEntity(user_id, name, password));
        }

        vector<EntryEntity>& findAllUserEntries(const string& id){
            vector<EntryEntity> v = vector<EntryEntity>();
            for (EntryEntity* entry: entries) {
                if(entry->getOwnerId() == id) v.push_back(*entry);
            }
            return v;
        };
};

#endif


