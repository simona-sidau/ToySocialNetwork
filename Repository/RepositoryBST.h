#ifndef MAIN_CPP_REPOSITORYBST_H
#define MAIN_CPP_REPOSITORYBST_H

#include <string>
#include <fstream>
#include "../DataStructures/BST.h"
#include "../DataStructures/List.h"
#include "RepositoryException.h"

template<class T>
class RepositoryBST {
private:
    ABC<T> entities;
public:
    /**
     * Add a T entity
     * @param entity
     */
    void add(T entity) {
        if (!exist(entity)) {
            this->entities.add(entity);
        } else
            throw RepositoryException("RepoErr: The entity already exist!");
    }

    /**
     * Remove a T entity
     * @param entity
     */
    void remove(T entity) {
        if (exist(entity)) {
            entities.remove(entity);
        } else throw RepositoryException("RepoErr: The entity does not exist!");
    }

    /**
     * Update an entity
     * @param entity
     * @param newEntity
     */
    void update(T entity, T newEntity) {
        if (exist(entity)) {
            entities.remove(entity);
            entities.add(newEntity);
        } else throw RepositoryException("RepoErr: The entity does not exist!");
    }

    /**
     * Verify if an entity exist
     * @param entity
     * @return
     */
    bool exist(T entity) {
        return entities.search(entity);
    }

    /**
     * Get an entity
     * @param entity
     * @return
     */
    T &getEntity(T entity) {
        return entities.getNode(entity);
    }

    /**
     * Get all entities
     * @return
     */
    ABC<T> getAll() {
        return this->entities;
    }

};

#endif //MAIN_CPP_REPOSITORYBST_H
