//
// Created by scott on 07/02/2020.
//

#ifndef SXCLIENT_DATAMODEL_H
#define SXCLIENT_DATAMODEL_H

#include <unordered_map>

template <typename T>
class DataModel {
    std::unordered_map<std::string,T> m_items;
public:
    T& add(const T& t);
    T* getById(const std::string& id);
    int nodeCount();
    const std::unordered_map<std::string,T>& items();

    explicit DataModel(int size);
};

template<typename T>
T &DataModel<T>::add(const T &t) {
    auto item = m_items.emplace(t.id(), t);
    return item.first->second;
}

template<typename T>
DataModel<T>::DataModel(int size) {
    m_items.reserve(size);
}

template<typename T>
T *DataModel<T>::getById(const std::string &id) {
    auto item = m_items.find(id);
    if (item != m_items.end())
        return &item->second;
    else
        return nullptr;
}

template<typename T>
int DataModel<T>::nodeCount() {
    return 0;
}

template<typename T>
const std::unordered_map<std::string, T>& DataModel<T>::items() {
    return m_items;
}

#endif //SXCLIENT_DATAMODEL_H
