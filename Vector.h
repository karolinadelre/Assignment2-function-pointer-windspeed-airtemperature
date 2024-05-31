#ifndef VECTOR_H
#define VECTOR_H


/**
 * @brief A dynamic array implementation.
 *
 * This class provides functionality similar to std::vector, allowing
 * dynamic storage of elements of any type.
 *
 * @tparam T The type of elements stored in the vector.
 */
template <class T>
class Vector {
public:
    // Interface

    /**
     * @brief Default constructor.
     *
     * Constructs an empty vector with a default capacity of 10.
     */
    Vector();

    /**
     * @brief Constructs a vector with a specified initial capacity.
     *
     * Constructs an empty vector with the specified initial capacity.
     *
     * @param n The initial capacity of the vector.
     */
    Vector(int n);

    /**
     * @brief Adds an element to the end of the vector.
     *
     * If the current size is less than the capacity, the element is added
     * to the end of the vector. If the capacity is reached, the vector is resized
     * to double its capacity before adding the element.
     *
     * @param value The value to be added to the vector.
     */
    void push_back(const T& value);

    /**
     * @brief Accesses the element at the specified index (const version).
     *
     * Returns a const reference to the element at the specified index.
     *
     * @param index The index of the element to access.
     * @return A const reference to the element at the specified index.
     */
    const T& operator[](int index) const;

    /**
     * @brief Returns the number of elements in the vector.
     *
     * @return The number of elements in the vector.
     */
    int size() const;

private:
    // Implementation

    /**
     * @brief Resizes the vector to accommodate a new size.
     *
     * If the new size is greater than the current capacity, the vector is resized
     * to double its capacity. Otherwise, no action is taken.
     *
     * @param newSize The new size of the vector.
     */
    void resize(int newSize);

    T* array;        /**< Pointer to the dynamically allocated array. */
    int capacity;    /**< The capacity of the vector (maximum number of elements it can hold). */
    int currentSize; /**< The current number of elements in the vector. */
};

template <class T>
Vector<T>::Vector() : capacity(10), currentSize(0) {
    array = new T[capacity]; // Allocate memory for the array with default capacity
}

template <class T>
Vector<T>::Vector(int n) : capacity(n), currentSize(0) {
    array = new T[capacity]; // Allocate memory for the array with specified capacity
}

template <class T>
void Vector<T>::push_back(const T& value) {
    if (currentSize >= capacity) {
        resize(2 * capacity); // Double the capacity if the vector is full
    }
    array[currentSize++] = value; // Add the value to the array and increment size
}

template <class T>
void Vector<T>::resize(int newSize) {
    T* newArray = new T[newSize]; // Create a new array with the new size
    for (int i = 0; i < currentSize; ++i) {
        newArray[i] = array[i]; // Copy elements from the old array to the new array
    }
    delete[] array; // Deallocate memory for the old array
    array = newArray; // Update the pointer to the new array
    capacity = newSize; // Update the capacity
}


template <class T>
const T& Vector<T>::operator[](int index) const {
    return array[index]; // Return a const reference to the element at the specified index
}

template <class T>
int Vector<T>::size() const {
    return currentSize; // Return the current number of elements in the vector
}

#endif
