class ProductOfNumbers {
    int n = 0;
    vector<int> prefixProd;

public:
    ProductOfNumbers() {
        prefixProd.emplace_back(1);
        n = 0;
    }

    void add(int num) {
        if (num == 0) {
            prefixProd.clear();
            prefixProd.emplace_back(1);
            n = 0;
        } else {
            prefixProd.emplace_back(prefixProd[n] * num);
            n += 1;
        }
    }

    int getProduct(int k) {
        if (k > n)
            return 0;
        return prefixProd[n] / prefixProd[n - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */