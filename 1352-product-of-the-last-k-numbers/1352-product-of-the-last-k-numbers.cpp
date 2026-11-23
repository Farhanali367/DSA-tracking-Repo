class ProductOfNumbers {
    vector<int>preprods;
public:
    ProductOfNumbers() {
        preprods.push_back(1);
    }
    
    void add(int num) {
        if (num == 0) {
            preprods.clear();
            preprods.push_back(1);
            return;
        }
        preprods.push_back(preprods[preprods.size() - 1] * num);

    }
    
    int getProduct(int k) {
        if (k > preprods.size() - 1) return 0;
        return preprods[preprods.size() - 1] / preprods[preprods.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */