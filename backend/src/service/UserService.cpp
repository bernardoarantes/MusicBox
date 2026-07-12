#ifndef USERSERVICE
#define USERSERVICE

#include "RegistryService.cpp"
#include "Workspace.cpp"

class UserService {
    private:
        Workspace *workspace;
        RegistryService *registry;

    public:
        UserService(Workspace &workspace, RegistryService &registry) {
            this->workspace = &workspace;
            this->registry = &registry;
        }

        void addUser(const string &name, const string &password) {
            string user_id = registry->generateUserId();
            workspace->addUser(user_id, name, password);
            registry->incrementUserCount();
        }
};

#endif
