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
            workspace->addEntry(new EntryEntity(entry_id, user_id, type, target_id, comment, rating));
            registry->incrementEntryCount();
        }

        json fetchEntriesFromOwner(const string &user_id) {
            json entries = json::array();
            for (EntryEntity entry : workspace->listEntriesByUser(user_id))
                entries += entry.toJson();

            return entries;
        }

        json fetchEntriesFromMusic(const string &music_id) {
            json entries = json::array();
            for (EntryEntity entry : workspace->listEntriesByMusic(music_id))
                entries += entry.toJson();

            return entries;
        }

        json checkForEntry(const string &user_id, const string &target_id) {
            for (EntryEntity entry : workspace->listEntriesByMusic(user_id))
                if (entry.getTargetId() == target_id)
                    return json::parse("{\"bool\":false}");
            return json::parse("{\"bool\":true}");
        }
};

#endif
