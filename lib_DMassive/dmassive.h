// Copyright 2024 Dergynov Sergey

#ifndef LIB_DMASSIVE_DMASSIVE_H_
#define LIB_DMASSIVE_DMASSIVE_H_

#include <utility>
#include <iostream>

#define STEP_CAPACITY 15

enum State { empty, busy, deleted };

template <typename T>
class TDmassive {
	T* _data;			// динамический массив данных
	State* _states;		// состояния элементов
	size_t _capacity;	// текущая вместимость массив
	size_t _size;		// текущее количество элементов
public:
	TDmassive();								// конструктор по умолчанию
	TDmassive(const TDmassive& massive);		// конструктор копирования
	TDmassive(const T* mass, size_t n);
	TDmassive(size_t n, T value);
	TDmassive(const TDmassive& massive, size_t pos, size_t n); 

	~TDmassive();								// деструктор

	void print() const noexcept;				// метод для вывода данных

	inline bool empty() const noexcept;			// проверка на пустоту массива
	inline bool full () const noexcept;			// проверка на полноту массива

	size_t size() const noexcept;				// методы для работы с размером и ёмкостью
	size_t capacity() const noexcept;
	const T* data() const noexcept;

	void swap(TDmassive& massive) noexcept;		// метод обмена содержимым массивов

	TDmassive& assign(const TDmassive& massive);// метод присваивания значений

	void clear();								// очистка массива
	void resize(size_t n, const T& value);		// изменение размера массива
	void reserve(size_t n);						// резервирование памяти для нового размера

	void push_back(const T& value);				// добавление элемента (в конец)
	void pop_back();							// удаление элемента (из конца)
	void push_front(const T& value);			// добавление элемента (в начало)
	void pop_front();							// удаление элемента (из начала)

	TDmassive& insert(const T* mass, size_t n, size_t pos);// вставка элементов
	TDmassive& insert(const T& value, size_t pos);

	TDmassive& replace(size_t pos, const T& new_value);// замена элемента в позиции

	TDmassive& erase(size_t pos, size_t n);		// удаление элементов
	TDmassive& remove_all(const T& value);
	TDmassive& remove_first(const T& value);
	TDmassive& remove_last(const T& value);
	TDmassive& remove_by_index(size_t pos);

	size_t find_last(const T& value) const;		// поиск элементов
	size_t find_first(const T& value) const;
	size_t* find_all(const T& value) const noexcept;

private:
	size_t count_value(T value) const noexcept; // подсчёт кол-ва появлений элемента
};

template <typename T>
TDmassive<T>::TDmassive() {
	_size = 0;
	_capacity = STEP_CAPACITY;
	_data = new T[_capacity];
	_states = new State[_capacity];
	for (size_t i = 0; i < STEP_CAPACITY; i++) {
		_states[i] = State::empty;
	}
}

template <typename T>
TDmassive<T>::TDmassive(const TDmassive& massive) {
	_capacity = massive._capacity;
	_size = massive._size;
	_data = new T[_capacity];
	_states = new State[_capacity];
	for (size_t i = 0; i < _capacity; i++) {
		_states[i] = massive._states[i];
		if (_states[i] == State::busy) {
			_data[i] = massive._data[i];
		}
	}
}

template <typename T>
TDmassive<T>::TDmassive(const T* mass, size_t n) {
	_size = n;
	_capacity = n;
	_states = new State[_capacity];
	_data = new T[_capacity];
	for (size_t i = 0; i < n; i++) {
		_data[i] = mass[i];
		_states[i] = State::busy;
	}
}

template <typename T>
TDmassive<T>::TDmassive(size_t n, T value) {
	_size = n;
	_capacity = n;
	_states = new State[_capacity];
	_data = new T[_capacity];
	for (size_t i = 0; i < n; i++) {
		_data[i] = value;
		_states[i] = State::busy;
	}
}

template <typename T>
TDmassive<T>::TDmassive(const TDmassive& massive, size_t pos, size_t n) {
	_size = n;
	_capacity = n;
	_states = new State[_capacity];
	_data = new T[_capacity];
	for (size_t i = 0; i < n; i++) {
		_data[i] = massive._data[pos + i];
		_states[i] = State::busy;
	}
}

template <typename T>
TDmassive<T>::~TDmassive() {
	delete[] _data;
	_data = nullptr;
	delete[] _states;
	_states = nullptr;
}

template <typename T>
void TDmassive<T>::print() const noexcept {
	for (size_t i = 0; i < _size; i++) {
		if (_states[i] != State::deleted) {
			std::cout << _data[i] << ", ";
		}
	}
	std::cout << "\n";
}

template <typename T>
inline bool TDmassive<T>::empty() const noexcept {
	return _size == 0;
}

template <typename T>
inline bool TDmassive<T>::full() const noexcept {
	return _size == _capacity;
}

template <typename T>
size_t TDmassive<T>::size() const noexcept {
	return _size;
}

template <typename T>
size_t TDmassive<T>::capacity() const noexcept {
	return _capacity;
}

template <typename T>
const T* TDmassive<T>::data() const noexcept {
	return _data;
}

template <typename T>
void TDmassive<T>::swap(TDmassive& massive) noexcept {
	std::swap(_data, massive._data); 
	std::swap(_states, massive._states);
	std::swap(_size, massive._size);
	std::swap(_capacity, massive._capacity);
}

template <typename T>
TDmassive<T>& TDmassive<T>::assign(const TDmassive& massive) {
	if (this != &massive) {
		delete[] _data;
		delete[] _states;

		_capacity = massive._capacity;
		_size = massive._size;
		_data = new T[_capacity];
		_states = new State[_capacity];

		for (size_t i = 0; i < _size; i++) {
			_data[i] = massive._data[i];
			_states[i] = massive._states[i];
		}

		for (size_t = _size; i < _capacity; i++) {
			_states[i] = State::empty;
		}
	}
	return *this;
}

template <typename T>
void TDmassive<T>::clear() {
	_capacity = STEP_CAPACITY;
	_size = 0;
	_data = nullptr;
	_states = nullptr;
}

template <typename T>
void TDmassive<T>::resize(size_t n, const T& value) {
	if (n < _size) {
		for (size_t i = n; i < _size; i++) {
			_states[i] = State::empty;
		}
		_size = n;
	} else if (n > _size) {
		if (n > _capacity) {
			reserve(n);
		}
		for (size_t i = _size; i < n; i++) {
			_data[i] = value;
			_states[i] = State::busy;
		}
		_size = n;
	}
}

template <typename T>
void TDmassive<T>::reserve(size_t n) {
	if (n <= _capacity) {
		return;
	}
	T* new_data = new T[n];
	State* new_states = new State[n];
	
	for (size_t i = 0; i < _size; i++) {
		new_data[i] = _data[i];
		new_states[i] = _states[i];
	}

	for (size_t i = _size; i < n; i++) {
		new_states[i] = State::empty;
	}

	delete[] _data;
	_data = new_data;
	delete[] _states;
	_states = new_states;
	_capacity = n;
}

template <typename T>
void TDmassive<T>::push_back(const T& value) {
	insert(value, _size);
}

template <typename T>
void TDmassive<T>::pop_back() {
	if (_size == 0) {
		throw std::out_of_range("EMPTY MASSIVE!!!");
		std::cout << "\n";
	}
	_states[_size - 1] = State::empty;
	_size--;
}

template <typename T>
void TDmassive<T>::push_front(const T& value) {
	insert(value, 0);
}

template <typename T>
void TDmassive<T>::pop_front() {
	if (_size == 0) {
		throw std::out_of_range("EMPTY MASSIVE!!!");
		std::cout << "\n";
	}
	erase(0, 1);
}

template <typename T>
TDmassive<T>& TDmassive<T>::insert(const T* mass, size_t n, size_t pos) {
	if (pos > _size) {
		throw std::out_of_range("OUT OF RANGE!!!");
		std::cout << "\n";
	}
	if (n == 0) {
		return *this;
	}
	if (_size + n > _capacity) {
		reserve(_size + n);
	}
	for (size_t i = _size; i > pos; i--) {
		_data[i + n - 1] = _data[i - 1];
		_states[i + n - 1] = _states[i - 1];
	}
	for (size_t i = 0; i < n; i++) {
		_data[pos + i] = mass[i];
		_states[pos + i] = State::busy;
	}
	_size += n;
	return *this;
}

template <typename T>
TDmassive<T>& TDmassive<T>::insert(const T& value, size_t pos) {
	if (pos > _size) {
		throw std::out_of_range("OUT OF RANGE!!!");
		std::cout << "\n";
	}
	if (_size >= _capacity) {
		reserve(_capacity + STEP_CAPACITY);
	}
	for (size_t i = _size; i > pos; i--) {
		_data[i] = _data[i - 1];
		_states[i] = _states[i - 1];
	}
	_data[pos] = value;
	_states[pos] = State::busy;
	_size++;
	return *this;
}

template <typename T>
TDmassive<T>& TDmassive<T>::replace(size_t pos, const T& new_value) {
	if (pos >= _size) {
		throw std::out_of_range("OUT OF RANGE!!!");
		std::cout << "\n";
	}
	if (_states[pos] != State::busy) {
		throw std::logic_error("CAN NOT REPLACE EMPTY OR DELETED POS");
		std::cout << "\n";
	}
	_data[pos] = new_value;
	return *this;
}

template <typename T>
TDmassive<T>& TDmassive<T>::erase(size_t pos, size_t n) {
	if (pos >= _size) {
		throw std::out_of_range("OUT OF RANGE!!!");
		std::cout << "\n";
	}
	if (n == 0) {
		return *this;
	}
	size_t erase_count = n;
	if (pos + n > _size) {
		erase_count = _size - pos;
	}
	for (size_t i = pos; i + erase_count < _size; i++) {
		_data[i] = _data[i + erase_count];
		_states[i] = _states[i + erase_count];
	}
	for (size_t i = _size - erase_count; i < _size; i++) {
		_states[i] = State::empty;
	}
	_size -= erase_count;
	return *this;
}

template <typename T>
TDmassive<T>& TDmassive<T>::remove_all(const T& value) {
	size_t i = 0;
	while (i < _states) {
		if (_states[i] == State::busy && _data[i] == value) {
			erase(i, 1);
		}
		else if {
			i++;
		}
	}
	return *this;
}

template <typename T>
TDmassive<T>& TDmassive<T>::remove_first(const T& value) {
	for (size_t i = 0; i < _size; i++) {
		if (_states[i] == State::busy && _data[i] == value) {
			erase(i, 1);
			return *this;
		}
	}
	throw std::logic_error("NOT FOUND IN MASS.");
	std::cout << "\n";
}

template <typename T>
TDmassive<T>& TDmassive<T>::remove_last(const T& value) {
	for (size_t i = _size; i > 0; i--) {
		size_t tmp = i - 1;
		if (_states[tmp] == State::busy && _data[tmp] == value) {
			erase(tmp, 1);
			return *this;
		}
	}
	throw std::logic_error("NOT FOUND IN MASS.");
	std::cout << "\n";
}

template <typename T>
TDmassive<T>& TDmassive<T>::remove_by_index(size_t pos) {
	if (pos >= _size) {
		throw std::out_of_range("OUT OF RANGE!!!");
		std::cout << "\n";
	}
	erase(pos, 1);
	return *this;
}

template <typename T>
size_t TDmassive<T>::find_last(const T& value) const {
	for (size_t i = _size; i > 0; i--) {
		size_t tmp = i - 1;
		if (_states[tmp] == State::busy && _data[tmp] == value) {
			return tmp;
		}
	}
	throw std::logic_error("NOT FOUND IN MASS.");
	std::cout << "\n";
}

template <typename T>
size_t TDmassive<T>::find_first(const T& value) const {
	for (size_t i = 0; i < _size; i++) {
		if (_states[i] == State::busy && _data[i] == value) {
			return i;
		}
	}
	throw std::logic_error("NOT FOUND IN MASS.");
	std::cout << "\n";
}

template <typename T>
size_t* TDmassive<T>::find_all(const T& value) const noexcept {
	size_t count = count_value(value);
	if (count == 0) {
		return nullptr;
	}
	size_t* index = new size_t[count + 1];
	index[0] = count;
	size_t tmp = 1;
	for (size_t i = 0; i < _size; i++) {
		if (_states[i] == State::busy && _data[i] == value) {
			index[tmp++] = i;
		}
	}
	return index;
}

template <typename T>
size_t TDmassive<T>::count_value(T value) const noexcept {
	size_t count = 0;
	for (size_t i = 0; i < _size; i++) {
		if (_data[i] == value) {
			count++;
		}
	}
	return count;
}

#endif  // LIB_DMASSIVE_DMASSIVE_H_