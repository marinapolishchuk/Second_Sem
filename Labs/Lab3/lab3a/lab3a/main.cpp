//
//  main.cpp
//  lab3a
//
//  Created by Marina Polishchuk on 4/13/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//
// Список 1. Варіант 5. Текстові рядки, лексикографічний порядок, за зростанням (A < AA < AB < B); //+
//
// Cписок 2. Варіант 2. Insertion sort; //+
//
// Список 3. Ефективний алгоритм сортування Quick sort: 3. Lomuto partition scheme, rightmost pivot; //+
//
// Список 4. Ефективний алгоритм сортування Merge sort: 1. top-down, two arrays.
//
// Демонстрацiйний режим - задається розмір масиву, генерується масив відповідного розміру, масив сортується різними алгоритмами, виводяться проміжні кроки кожного алгоритму


#include <iostream>
#include <vector>
#include <string>
#include <ctime>

//#define DEBUG_

void print_vec(std::vector<std::string>);

void insertion_sort(std::vector<std::string>&, int, int);

int partition(std::vector<std::string>&, int, int);
void quick_sort(std::vector<std::string>&, int, int);

void merge(std::vector<std::string>&, int, int, int);
void merge_sort(std::vector<std::string>&, int, int);
    
int min(int, int);
void combined_sort(std::vector<std::string>&, int);

char get_random_char();
std::string get_random_str(int);

void demo_mode();
void benchmark_mode();


int main() {
    
    std::cout << "Choose mode: " <<
                 "\n1. Demonstration mode." <<
                 "\n2. Benchmark mode." << std::endl;
    int choice = 0;
    std::cin >> choice;
    switch (choice) {
        case 1: {
            demo_mode();
            break;
        }
        case 2: {
            benchmark_mode();
            break;
        }
        default: {
            std::cout << "An option was chosen incorrectly." << std::endl;
            break;
        }
    }
    return 0;
}

void print_vec(std::vector<std::string> vec) {
    for(int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << ' ';
    }
    std::cout << std::endl;
}

// Insertion sort
void insertion_sort(std::vector<std::string> &vec, int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        std::string temp = vec[i];
        int j = i - 1;
        while (vec[j] > temp && j >= left)
        {
            vec[j+1] = vec[j];
#ifdef DEBUG_
            std::cout << "Step: ";
            print_vec(vec);
#endif
            j--;
        }
        vec[j+1] = temp;
#ifdef DEBUG_
        std::cout << "Step: ";
        print_vec(vec);
#endif
    }
}
// Lomuto partition scheme, rightmost pivot
int partition(std::vector<std::string> &vec, int low, int high) {
    std::string pivot = vec[high];
    int i = low;
    for (int j = low; j <= high - 1; j++) {
        if (vec[j] <= pivot) {
            std::swap(vec[j], vec[i]);
#ifdef DEBUG_
            std::cout << "Step: ";
            print_vec(vec);
#endif
            i++;
        }
    }
    std::swap(vec[i], vec[high]);
#ifdef DEBUG_
    std::cout << "Step: ";
    print_vec(vec);
#endif
    return i;
}

void quick_sort(std::vector<std::string> &vec, int low, int high){
    if (low < high) {
        int p = partition(vec, low, high);
        quick_sort(vec, low, p - 1);
        quick_sort(vec, p + 1, high);
    }
}

// Merge sort. Top-down. Two arrays.
void merge(std::vector<std::string> &vec, int start, int mid, int end) {
    std::string temp[end - start + 1];
    int left = start;
    int right = mid + 1;
    
    int k = 0;
    while (left <= mid && right <= end) {
        if (vec[left] < vec[right]) {
            temp[k++] = vec[left++];
        }
        else {
            temp[k++] = vec[right++];
        }
    }
    if (left <= mid) {
        while (left <= mid) {
            temp[k++] = vec[left++];
        }
    }
    else {
        while (right <= end) {
            temp[k++] = vec[right++];
        }
    }
    k = 0;
    for (int i = start; i <= end; i++) {
        vec[i] = temp[k++];
        
    }
}


void merge_sort(std::vector<std::string> &vec, int start, int end) {
    if (start >= end) return;
    
    int mid = (start + end) / 2;
    merge_sort(vec, start, mid);
    merge_sort(vec, mid + 1, end);
    merge(vec, start, mid, end);
#ifdef DEBUG_
    std::cout << "Step: ";
    print_vec(vec);
#endif

}

int min(int a, int b) { return a < b ? a : b; }

// Combined sort. Merge-insertion sort
void combined_sort(std::vector<std::string> &vec, int n) {
    int run = 32;
    for (int i = 0; i < n; i += run)
        insertion_sort(vec, i, min((i + 31), (n - 1)));

    for (int size = run; size < n; size = 2 * size)
    {
        for (int left = 0; left < n; left += 2 * size)
        {
            int mid = left + size - 1;
            int right = min((left + 2 * size - 1), (n - 1));
            merge(vec, left, mid, right);
        }
    }
}

char get_random_char() {
    return static_cast<char>('A' + rand() % (('Z' - 'A') + 1));
}

std::string get_random_str(int max_length) {
    int str_length = (rand() % max_length + 1);
    std::string str;
    for(int i = 0; i < str_length; ++i) {
        str.push_back(get_random_char());
    }
    return str;
}

void demo_mode() {
    std::cout << "Welcome to the demonstration mode." << std::endl;
    std::cout << "Enter the number of strings and max length of one separate string: ";
    int vec_size, str_len;
    std::cin >> vec_size >> str_len;
    
    std::cout << "Here is an unsorted randomly generated list of strings:" << std::endl;
    
    std::vector<std::string> vec;
    for (int i = 0; i < vec_size; ++i) {
        vec.push_back(get_random_str(str_len));
    }
    print_vec(vec);
    
    std::cout << "\nInsertion sort:" << std::endl;
    std::vector<std::string> ins_vec = vec;
    insertion_sort(ins_vec, 0, ins_vec.size() - 1);
    std::cout << "SORTED: ";
    print_vec(ins_vec);
    
    std::cout << "\nQuick sort:" << std::endl;
    std::vector<std::string> q_vec = vec;
    quick_sort(q_vec, 0, q_vec.size() - 1);
    std::cout << "SORTED: ";
    print_vec(q_vec);
    
    std::cout << "\nMerge sort:" << std::endl;
    std::vector<std::string> m_vec = vec;
    merge_sort(m_vec, 0, m_vec.size() - 1);
    std::cout << "SORTED: ";
    print_vec(m_vec);
    
    std::cout << "\nCombined sort:" << std::endl;
    std::vector<std::string> c_vec = vec;
    combined_sort(c_vec, c_vec.size());
    std::cout << "SORTED: ";
    print_vec(c_vec);
}

void benchmark_mode() {
    std::cout << "Welcome to the benchmark mode." << std::endl;
    std::cout << "Enter the number of strings and max length of one separate string: ";
    int vec_size, str_len;
    std::cin >> vec_size >> str_len;
    
    std::cout << "\nHere is an unsorted RANDOMLY generated list of strings:" << std::endl;
    
    std::vector<std::string> vec;
    for (int i = 0; i < vec_size; ++i) {
        vec.push_back(get_random_str(str_len));
    }
    print_vec(vec);
    std::cout << "\nInsertion sort:" << std::endl;
    std::vector<std::string> ins_vec = vec;
    clock_t start0 = clock();
    insertion_sort(ins_vec, 0, ins_vec.size() - 1);
    clock_t end0 = clock();
    clock_t res0 = end0 - start0;
    std::cout << "SORTED: ";
    print_vec(ins_vec);
    std::cout << "Time of working: " << res0 << std::endl;
    
    std::cout << "\nQuick sort:" << std::endl;
    std::vector<std::string> q_vec = vec;
    clock_t start1 = clock();
    quick_sort(q_vec, 0, q_vec.size() - 1);
    clock_t end1 = clock();
    clock_t res1 = end1 - start1;
    std::cout << "SORTED: ";
    print_vec(q_vec);
    std::cout << "Time of working: " << res1 << std::endl;
    
    
    std::cout << "\nMerge sort:" << std::endl;
    std::vector<std::string> m_vec = vec;
    clock_t start2 = clock();
    merge_sort(m_vec, 0, m_vec.size() - 1);
    clock_t end2 = clock();
    clock_t res2 = end2 - start2;
    std::cout << "SORTED: ";
    print_vec(m_vec);
    std::cout << "Time of working: " << res2 << std::endl;
    
    
    std::cout << "\nCombined sort:" << std::endl;
    std::vector<std::string> c_vec = vec;
    clock_t start3 = clock();
    combined_sort(c_vec, c_vec.size());
    clock_t end3 = clock();
    clock_t res3 = end3 - start3;
    std::cout << "SORTED: ";
    print_vec(c_vec);
    std::cout << "Time of working: " << res3 << std::endl;
    
    std::vector<std::string> almost_sorted = {"A","B","C","D","E","F","G","H","I","K","J"};
    
    std::vector<std::string> totally_unsorted = {"K","J","I","H","G","F","E","D","C","B","A"};
    
    std::cout << "\n###################################"<< std::endl;
    std::cout << "\nALMOST SORTED LIST: " << std::endl;
    print_vec(almost_sorted);
    
    std::cout << "\nInsertion sort:" << std::endl;
    std::vector<std::string> ins_vec0 = almost_sorted;
    clock_t start00 = clock();
    insertion_sort(ins_vec0, 0, ins_vec0.size() - 1);
    clock_t end00 = clock();
    clock_t res00 = end00 - start00;
    std::cout << "SORTED: ";
    print_vec(ins_vec0);
    std::cout << "Time of working: " << res00 << std::endl;
    
    std::cout << "\nQuick sort:" << std::endl;
    std::vector<std::string> q_vec0 = almost_sorted;
    clock_t start10 = clock();
    quick_sort(q_vec0, 0, q_vec0.size() - 1);
    clock_t end10 = clock();
    clock_t res10 = end10 - start10;
    std::cout << "SORTED: ";
    print_vec(q_vec0);
    std::cout << "Time of working: " << res10 << std::endl;
    
    
    std::cout << "\nMerge sort:" << std::endl;
    std::vector<std::string> m_vec0 = almost_sorted;
    clock_t start20 = clock();
    merge_sort(m_vec0, 0, m_vec0.size() - 1);
    clock_t end20 = clock();
    clock_t res20 = end20 - start20;
    std::cout << "SORTED: ";
    print_vec(m_vec0);
    std::cout << "Time of working: " << res20 << std::endl;
    
    
    std::cout << "\nCombined sort:" << std::endl;
    std::vector<std::string> c_vec0 = almost_sorted;
    clock_t start30 = clock();
    combined_sort(c_vec0, c_vec0.size());
    clock_t end30 = clock();
    clock_t res30 = end30 - start30;
    std::cout << "SORTED: ";
    print_vec(c_vec0);
    std::cout << "Time of working: " << res30 << std::endl;
    
    std::cout << "\n###################################"<< std::endl;
    
    std::cout << "\nTOTALLY UNSORTED LIST:" << std::endl;
    print_vec(totally_unsorted);
    
    
    std::cout << "\nInsertion sort:" << std::endl;
    std::vector<std::string> ins_vec1 = totally_unsorted;
    clock_t start01 = clock();
    insertion_sort(ins_vec1, 0, ins_vec1.size() - 1);
    clock_t end01 = clock();
    clock_t res01 = end01 - start01;
    std::cout << "SORTED: ";
    print_vec(ins_vec1);
    std::cout << "Time of working: " << res01 << std::endl;
    
    std::cout << "\nQuick sort:" << std::endl;
    std::vector<std::string> q_vec1 = totally_unsorted;
    clock_t start11 = clock();
    quick_sort(q_vec1, 0, q_vec1.size() - 1);
    clock_t end11 = clock();
    clock_t res11 = end11 - start11;
    std::cout << "SORTED: ";
    print_vec(q_vec1);
    std::cout << "Time of working: " << res11 << std::endl;
    
    
    std::cout << "\nMerge sort:" << std::endl;
    std::vector<std::string> m_vec1 = totally_unsorted;
    clock_t start21 = clock();
    merge_sort(m_vec1, 0, m_vec1.size() - 1);
    clock_t end21 = clock();
    clock_t res21 = end21 - start21;
    std::cout << "SORTED: ";
    print_vec(m_vec1);
    std::cout << "Time of working: " << res21 << std::endl;
    
    
    std::cout << "\nCombined sort:" << std::endl;
    std::vector<std::string> c_vec1 = totally_unsorted;
    clock_t start31 = clock();
    combined_sort(c_vec1, c_vec1.size());
    clock_t end31 = clock();
    clock_t res31 = end31 - start31;
    std::cout << "SORTED: ";
    print_vec(c_vec1);
    std::cout << "Time of working: " << res31 << std::endl;
    
    
}
