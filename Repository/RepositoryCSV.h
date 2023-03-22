#ifndef PROIECTTOYSOCIALNETWORK_REPOSITORYCSV_H
#define PROIECTTOYSOCIALNETWORK_REPOSITORYCSV_H

#include <fstream>
#include <string>
#include <sstream>
#include <utility>
#include "../Domain/User.h"
#include "../DataStructures/List.h"
#include "RepositoryException.h"


template<class T>
class RepositoryCSV {
private:
    List<T> entities;
    std::string fileName;

public:
    /**
     * Constructor
     * @param fileName
     */
    RepositoryCSV(std::string fileName) {
        this->fileName = std::move(fileName);
        this->readRecord();

    }

    /**
     * Read existing entities from the file
     */
    void readRecord() {
        std::ifstream file(fileName);
        std::string element;
        while (std::getline(file, element)) {
            T entity(element, ',');
            entities.add(entity);
        }
    }

    /**
     * Save changes to file
     */
    void saveToFile() {
        std::ofstream file(fileName);
        file.clear();
        for (int i = 0; i < this->entities.lSize(); i++) {
            T entity;
            entity = entities[i];
            List<std::string> elements = entity.split();

            for (int i = 0; i < elements.lSize(); i++)
                file << elements[i] << ',';
            file << '\n';

        }
        file.close();
    }

    /**
     * Add an entity
     * @param entity
     */
    void add(const T &entity) {
        if (!exist(entity)) {
            this->entities.add(entity);
            this->saveToFile();
        } else
            throw RepositoryException("RepoError: The entity already exist!");
    }

    /**
     * Remove an entity
     * @param entity
     */
    void remove(T entity) {
        if (exist(entity)) {
            this->entities.remove(entity);
            this->saveToFile();
        } else
            throw RepositoryException("RepoError: The entity does not exist!");

    }

    /**
     * Update an entity
     * @param entity
     */
    void update(const T &entity) {
        if (exist(this->getEntity(entity.getId()))) {
            for (int i = 0; i < entities.lSize(); i++) {
                if (entities[i].getId() == entity.getId()) {
                    this->entities.remove(entities[i]);
                    this->entities.insert(i, entity);
                }
            }
            this->saveToFile();
        } else
            throw RepositoryException("RepoError: The entity does not exist!");
    }

    /**
     * Verify if an entity exist
     * @param entity
     * @return
     */
    bool exist(T entity) {
        for (int i = 0; i < entities.lSize(); i++) {
            if (entities[i] == entity) {
                return true;
            }
        }
        return false;
    }

    /**
     * Get all entities
     * @return
     */
    List<T> getAll() {
        return entities;
    }

    /**
     * Get an entity with a given id
     * @param id
     * @return
     */
    T &getEntity(unsigned int id) {

        for (int i = 0; i < this->entities.lSize(); i++) {
            if (entities[i].getId() == id) {
                return entities[i];
            }
        }
        throw RepositoryException("RepoError: The entity does not exist!");
    }

    /**
     * Get an entity from its position in memory
     * @param index
     * @return
     */
    T &getEntityByIndex(unsigned int index) {
        return entities[index];
    }

    /**
     * @return - number of entities
     */
    unsigned int noEntities() {
        return entities.lSize();
    }
};

#endif //PROIECTTOYSOCIALNETWORK_REPOSITORYCSV_H
