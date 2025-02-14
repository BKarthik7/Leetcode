class ProductOfNumbers {
public:
    vector<int> v{1};
    ProductOfNumbers() {}

    void add(int num) {
        if (num != 0) {
            v.push_back(num * v.back());
        } else {
            v.clear();
            v.push_back(1);
        }
    }

    int getProduct(int k) {
        return k < v.size() ? v.back() / v[v.size() - k - 1] : 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */