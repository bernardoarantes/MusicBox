#ifndef USERSERVICE
#define USERSERVICE

#include "service/RegistryService.cpp"
#include "service/Workspace.cpp"

class UserService {
    private:
        Workspace *workspace;
        RegistryService *registry;

    public:
        UserService(Workspace &workspace, RegistryService &registry) {
            this->workspace = &workspace;
            this->registry = &registry;
        }

        void addUser(const string &name, const string &email, const string &password) {
            if (workspace->userWithEmailExists(email))
                throw ValidationException("user with email " + email + " already exists");

            string user_id = registry->generateUserId();
            workspace->addUser(new UserEntity(user_id, name, email, password));
            registry->incrementUserCount();
        }
};

#endif
