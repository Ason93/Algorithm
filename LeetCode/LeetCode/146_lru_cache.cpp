#include "questions.h"

//class LRUCache {
//public:
//    LRUCache(int capacity) : capa_(capacity) {
//    }
//
//    int get(int key) {
//        if (map_.find(key) != map_.end()) {
//            // If key exists, update it.
//            const auto value = map_[key]->second;
//            update(key, value);
//            return value;
//        }
//        else {
//            return -1;
//        }
//    }
//
//    void put(int key, int value) {
//        // If cache is full while inserting, remove the last one.
//        if (map_.find(key) == map_.end() && list_.size() == capa_) {
//            auto del = list_.back(); 
//            list_.pop_back();
//            map_.erase(del.first);
//        }
//        update(key, value);
//    }
//
//private:
//    list<pair<int, int>> list_; // key, value
//    unordered_map<int, list<pair<int, int>>::iterator> map_; // key, list iterator
//    int capa_;
//
//    // Update (key, iterator of (key, value)) pair
//    void update(int key, int value) {
//        auto it = map_.find(key);
//        if (it != map_.end()) {
//            list_.erase(it->second);
//        }
//        list_.emplace_front(key, value);
//        map_[key] = list_.begin();
//    }
//};

class LRUCache {
public:
    LRUCache(int capacity) : capa_(capacity) {
    }

    int get(int key) {
        if (map_.find(key) != map_.end()) {
            const int value = map_[key]->second;
            update(key, value);
            return value;
        }
        else{
            return -1;
        }
    }

    void put(int key, int value) {
        auto iter = map_.find(key);
        if (iter == map_.end() && list_.size() == capa_) {
            auto del = list_.back();
            list_.pop_back();
            map_.erase(del.first);
        }
        update(key, value);
    }

private:
    int capa_;
    list<pair<int, int>> list_;
    unordered_map<int, list<pair<int, int>>::iterator> map_;

    void update(int key, int value) {
        auto iter = map_.find(key);
        if (iter != map_.end()) {
            list_.erase(iter->second);
        }
        list_.emplace_front(key, value);
        map_[key] = list_.begin();
    }
};


int UseLRUCache() {
    cout << "*************** 146.LRU Cache ***************" << endl;
    LRUCache* cache = new LRUCache(2 /* capacity */);

    int get_result;
    cache->put(1, 1);
    cache->put(2, 2);
    get_result = cache->get(1);       // returns 1
    cout << "The Got Result Is: " << get_result << endl;
    cache->put(3, 3);    // evicts key 2
    get_result = cache->get(2);       // returns -1 (not found)
    cout << "The Got Result Is: " << get_result << endl;
    cache->put(4, 4);    // evicts key 1
    get_result = cache->get(1);       // returns -1 (not found)
    cout << "The Got Result Is: " << get_result << endl;
    get_result = cache->get(3);       // returns 3
    cout << "The Got Result Is: " << get_result << endl;
    get_result = cache->get(4);       // returns 4
    cout << "The Got Result Is: " << get_result << endl;

    return 0;
}
