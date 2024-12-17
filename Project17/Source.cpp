#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

// ������� ��� ������ ������������ ��������
struct MinValue {
    int operator()(const std::vector<int>& vec) const {
        return *std::min_element(vec.begin(), vec.end());
    }
};

// ������� ��� ������ ������������� ��������
struct MaxValue {
    int operator()(const std::vector<int>& vec) const {
        return *std::max_element(vec.begin(), vec.end());
    }
};

// ������� ��� ���������� �� ��������
struct SortDescending {
    void operator()(std::vector<int>& vec) const {
        std::sort(vec.begin(), vec.end(), std::greater<int>());
    }
};

// ������� ��� ���������� �� �����������
struct SortAscending {
    void operator()(std::vector<int>& vec) const {
        std::sort(vec.begin(), vec.end());
    }
};

// ������� ��� ���������� �������� �� �������� ���������
struct IncreaseBy {
    int delta;
    IncreaseBy(int d) : delta(d) {}
    void operator()(std::vector<int>& vec) const {
        std::transform(vec.begin(), vec.end(), vec.begin(),
            [this](int val) { return val + delta; });
    }
};

// ������� ��� ���������� �������� �� �������� ���������
struct DecreaseBy {
    int delta;
    DecreaseBy(int d) : delta(d) {}
    void operator()(std::vector<int>& vec) const {
        std::transform(vec.begin(), vec.end(), vec.begin(),
            [this](int val) { return val - delta; });
    }
};

// ������� ��� �������� ���������, ������ ��������� ��������
struct RemoveValue {
    int target;
    RemoveValue(int t) : target(t) {}
    void operator()(std::vector<int>& vec) const {
        vec.erase(std::remove(vec.begin(), vec.end(), target), vec.end());
    }
};

int main() {
    // ������ ������
    std::vector<int> numbers = { 5, 3, 8, 1, 3, 7, 9, 3 };

    // ����� ������������ � ������������� ��������
    MinValue minFinder;
    MaxValue maxFinder;
    std::cout << "Min: " << minFinder(numbers) << std::endl;
    std::cout << "Max: " << maxFinder(numbers) << std::endl;

    // ����������
    SortDescending descSorter;
    SortAscending ascSorter;
    descSorter(numbers);
    std::cout << "Sorted Descending: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;

    ascSorter(numbers);
    std::cout << "Sorted Ascending: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;

    // ���������� � ���������� ��������
    IncreaseBy increaseBy(2);
    DecreaseBy decreaseBy(1);
    increaseBy(numbers);
    std::cout << "Increased by 2: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;

    decreaseBy(numbers);
    std::cout << "Decreased by 1: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;

    // �������� ��������
    RemoveValue remover(3);
    remover(numbers);
    std::cout << "After removing 3: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;

    return 0;
}