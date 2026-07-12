#ifndef ENTRYSERVICE
#define ENTRYSERVICE

#include "json.hpp"
#include "service/RegistryService.cpp"
#include "service/Workspace.cpp"

using nlohmann::json;

class EntryService {
    private:
        Workspace *workspace;
        RegistryService *registry;

    public:
        EntryService(Workspace &workspace, RegistryService &registry) {
            this->workspace = &workspace;
            this->registry = &registry;
        }

        void addEntry(const string &user_id, const string &type, const string &target_id, const string &comment, unsigned rating) {
            string entry_id = registry->generateEntryId();
            workspace->addEntry(user_id, entry_id, type, target_id, comment, rating);
            registry->incrementEntryCount();
        }
        string fetchEntriesFromOwnerId(const string& id){
            string s = "[";
            for (EntryEntity entry: workspace->findAllUserEntries(id)) {
                s += entry.toJson() + ",";
            }
            s += "]";
            return s;
        }
};

#endif
