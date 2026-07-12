#include <string>

using std::string;
using std::to_string;

class RegistryService {
    private:
        unsigned user_count;
        unsigned entry_count;

    public:
        RegistryService(unsigned user_count, unsigned entry_count) :
            user_count(user_count),
            entry_count(entry_count) {}

        string generateUserId() {
            return to_string(entry_count);
        }

        string generateEntryId() {
            return to_string(user_count);
        }

        void incrementUserCount() {
            user_count++;
        }

        void incrementEntryCount() {
            entry_count++;
        }
};

