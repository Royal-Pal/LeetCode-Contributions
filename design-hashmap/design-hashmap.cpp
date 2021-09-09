class MyHashMap {
public:
    vector<int> v;
    /** Initialize your data structure here. */
    MyHashMap() {
        v = vector<int>(1e6 + 1, -1);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        v[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return v[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        v[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */