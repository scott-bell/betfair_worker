//
// Created by scott on 07/02/2020.
//

#ifndef SXCLIENT_DATAMODEL_H
#define SXCLIENT_DATAMODEL_H

#include <unordered_map>
#include <algorithm>
#include <data_models/Sorter.h>

template <typename T>
class DataModel {
    std::unordered_map<std::string,T> m_items;
public:
    T& add(const T& t);
    T* getById(const std::string& id);
    int nodeCount();
    const std::unordered_map<std::string,T>& items();
    std::vector<T*> toVector(const Data::Sorter& sorter);

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

template<typename T>
std::vector<T*> DataModel<T>::toVector(const Data::Sorter& sorter) {
    std::vector<T*> itemsCopy;
    for (auto& item: m_items) {
        T *ug = (&item.second);
        itemsCopy.push_back(ug);
    }
    std::sort(itemsCopy.begin(), itemsCopy.end(),
            [&](const T* a, const T* b) -> bool
            {
                return sorter.compare(*a,*b);
            }
    );
    return itemsCopy;
}

#endif //SXCLIENT_DATAMODEL_H
