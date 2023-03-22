#ifndef PROIECTTOYSOCIALNETWORK_LIST_H
#define PROIECTTOYSOCIALNETWORK_LIST_H

template<class T>
class List {
private:

    int size{};
    int index{};
    int maxCapacity;
    const static int INITIAL_CAPACITY = 20;
    T *array;
public:
    /*
     * Constructor
     */
    List() {
        this->index = 0;
        this->size = 0;
        this->maxCapacity = INITIAL_CAPACITY;
        array = new T[this->maxCapacity];
        //array = nullptr;
    }

    /**
     * Copy constructor
     */

    List(const List<T> &lst) {
        this->index = lst.index;
        this->size = lst.size;
        this->maxCapacity = lst.maxCapacity;
        this->array = new T[this->maxCapacity];

        for (int i = 0; i < this->size; i++) {
            this->array[i] = lst.array[i];
        }
    }

/**
 * Add an element to a list
 * @param elem - T entity
 */
    void add(T elem) {
        if (this->size >= this->maxCapacity) {
            this->maxCapacity *= 2;
            T *temp = new T[this->maxCapacity];
            for (int i = 0; i < this->size; i++)
                temp[i] = array[i];
            delete[] array;
            array = temp;
            //delete[] temp;
        }
        this->array[this->index] = elem;
        this->index++;
        this->size++;
    }

/**
 * Remove an element from a list
 * @param elem - T entity
 */
    void remove(T elem) {
        if (this->size != 0) {
            for (int i = 0; i <= this->size; i++) {
                if (array[i] == elem) {
                    for (int j = i; j < this->size - 1; j++)
                        this->array[j] = this->array[j + 1];
                    this->size--;
                    this->index--;
                    return;
                }
            }

        }
    }

/**
 * Get size of the list
 * @return - size of the list
 */
    int lSize() {
        return this->size;
    }


    T &operator[](int index) {
        return this->array[index];
    }

/**
 * Insert sn element to a list
 * @param index - index where the element will be insert
 * @param elem - T entity
 */
    void insert(unsigned int index, T elem) {
        for (int i = this->size; i > index; i--) {
            this->array[i + 1] = this->array[i];
        }
        this->array[index] = elem;
        this->size++;
        this->index++;
    }

/**
 * Get the position in a list for an element
 * @param elem - T entitti
 * @return - index of element
 */
    int position(T elem) {
        for (int i = 0; i < this->size; i++) {
            if (array[i] == elem) {
                return i;
            }
        }
    }

/**
 * Get an entity with a given index
 * @param index - int
 * @return - the entity from the given index
 */
    T getEntity(int index) {
        return array[index];
    }
};

#endif //PROIECTTOYSOCIALNETWORK_LIST_H
