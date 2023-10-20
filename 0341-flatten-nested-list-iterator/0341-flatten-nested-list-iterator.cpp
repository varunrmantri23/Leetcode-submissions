class NestedIterator {
    vector<int> flatList;
    int iterator;
public:
    NestedIterator(std::vector<NestedInteger>& nestedList) {
        iterator = 0;
        flattenList(nestedList);
    }
    
    void flattenList(std::vector<NestedInteger>& nestedList) {
        for (NestedInteger ele : nestedList) {
            if (ele.isInteger()) {
                flatList.push_back(ele.getInteger());
            } else {
                flattenList(ele.getList());
            }
        }
    }
    
    int next() {
        if (hasNext()) {
            return flatList[iterator++];
        } else {
            return NULL;
        }
    }
    
    bool hasNext() {
        return iterator < flatList.size();
    }
};