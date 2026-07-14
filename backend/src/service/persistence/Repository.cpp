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
        const string file_path;
        vector<const Entity *> entities;

        void update() {
            fstream w_file(file_path, ios::out);

            if (!w_file.is_open())
                throw EntityNotFoundException("Bad input file path " + file_path);

            json j = json::array();
            for (const Entity *entity : entities)
                j += entity->toJson();

            w_file << j.dump();
            w_file.close();
        }

    public:
        Repository(const string &file_path, const EntityParser &entity_parser) : file_path(file_path) {
            fstream in_file;
            in_file.open(file_path, ios::in);

            if (!in_file.is_open())
                throw EntityNotFoundException("Bad input file path " + file_path);
            
            json data;

            if (!std::filesystem::is_empty(file_path))
                data = json::parse(in_file);

            in_file.close();

            for (json j : data)
                entities.push_back(entity_parser.parseJson(j));
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
            update();
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
