#ifndef REPOSITORY
#define REPOSITORY

#include "entity/Entity.cpp"
#include "exceptions/EntityNotFoundException.cpp"
#include "service/EntityParser.cpp"
#include <filesystem>
#include <fstream>
#include <ios>
#include <string>
#include <vector>

using std::fstream;
using std::ios;
using std::string;
using std::vector;

class Repository {
    private:
        fstream file;
        vector<const Entity *> entities;

    public:
        Repository(const string &file_path, const EntityParser &entity_parser) {
            fstream in_file;
            in_file.open(file_path, ios::in);

            if (!in_file.is_open())
                throw EntityNotFoundException("Bad input file path " + file_path);
            
            json data = json::array();

            if (!std::filesystem::is_empty(file_path)) {
                string line;
                while (std::getline(in_file, line)) {
                    if (line.empty()) continue;
                    data += json::parse(line);
                }
            }

            in_file.close();

            for (json j : data)
                entities.push_back(entity_parser.parseJson(j));

            file.open(file_path, ios::app);
        }

        const Entity &findById(const string &id) const {
            for (const Entity *entity : entities)
                if (entity->getId() == id) 
                    return *entity;

            throw EntityNotFoundException("Bad id " + id);
        }

        vector<const Entity *> findAll() const {
            return entities;
        }

        void save(const Entity *entity) {
            entities.push_back(entity);
            file << "\n" + entity->toJson().dump();
        }

        vector<const Entity *>::iterator begin() {
            return entities.begin();
        }

        vector<const Entity *>::iterator end() {
            return entities.end();
        }

        size_t size() {
            return entities.size();
        }
};

#endif
