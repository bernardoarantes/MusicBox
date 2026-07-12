#ifndef ENTRYSERVICE
#define ENTRYSERVICE

#include "RegistryService.cpp"
#include "Workspace.cpp"

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
};

#endif
