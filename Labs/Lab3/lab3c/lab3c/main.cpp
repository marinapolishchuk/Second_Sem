//
//  main.cpp
//  lab3c
//
//  Created by Marina Polishchuk on 4/8/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//
// 1. Comb sort
// 2. Gnome sort
// 10. Heap sort
//

#include <iostream>

const int SIZE = 10;

//#define DEBUG_

void comb_sort(int *); //+
void gnome_sort(int *); //+


void heap_sort(int *); //+
void build_max_heap(int*, int, int&); //+

int main() {


    int arr[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % 101;
    }

    std::cout << "Array before sorting: " << std::endl;
    for (int i = 0; i < SIZE; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;

    std::cout << "\nThe list of available sorting algorithms: " <<
                 "\n\t1. Comb sort." <<
                 "\n\t2. Heap sort." <<
                 "\n\t3. Gnome sort." << std::endl;

    int choice = 0;
    std::cout << "Enter the number: ";
    std::cin >> choice;

    switch (choice) {
        case 1: {
            std::cout << "\nComb sort was chosen." << std::endl;
            clock_t start_time =  clock();
            comb_sort(arr);
            clock_t end_time = clock();
            clock_t search_time = end_time - start_time;
            std::cout << "Function working time: " << search_time << std::endl;
            std::cout << "Array after sorting: " << std::endl;
            for (int i = 0; i < SIZE; ++i) {
                std::cout << arr[i] << ' ';
            }
            std::cout << std::endl;
            break;
        }
        case 2: {
            std::cout << "\nHeap sort was chosen." << std::endl;
            clock_t start_time =  clock();
            heap_sort(arr);
            clock_t end_time = clock();
            clock_t search_time = end_time - start_time;
            std::cout << "Function working time: " << search_time << std::endl;
            std::cout << "Array after sorting: " << std::endl;
            for (int i = 0; i < SIZE; ++i) {
                std::cout << arr[i] << ' ';
            }
            std::cout << std::endl;
            break;
        }
        case 3: {
            std::cout << "\nGnome sort was chosen." << std::endl;
            clock_t start_time =  clock();
            gnome_sort(arr);
            clock_t end_time = clock();
            clock_t search_time = end_time - start_time;
            std::cout << "Function working time: " << search_time << std::endl;
            std::cout << "Array after sorting: " << std::endl;
            for (int i = 0; i < SIZE; ++i) {
                std::cout << arr[i] << ' ';
            }
            std::cout << std::endl;
            break;
        }

        default: {
            std::cout << "\nThe option was chosen incorrectly." << std::endl;
            break;
        }
    }

    return 0;
}


void comb_sort(int *arr) {
    {
        double fakt = 1.2473309;
        double step = SIZE - 1;
#ifdef DEBUG_
        int n = 0;
#endif

        while (step >= 1)
        {
            for (int i = 0; i + step < SIZE; ++i)
            {
                int temp = i + step;
                if (arr[i] > arr[temp])
                {
                    std::swap(arr[i], arr[temp]);
#ifdef DEBUG_
                    n++;
                    std::cout << "Step " << n << ": ";
                    for (int m = 0; m < SIZE; ++m) {
                        std::cout << arr[m] << ' ';
                    }
                    std::cout << std::endl;
#endif
                }
            }
            step /= fakt;
        }
#ifdef DEBUG_
        std::cout << "Number of rearrangements: " << n << std::endl;
#endif
    }
}

void build_max_heap(int *arr, int heap_size, int &n) {
    int i = heap_size/2-1;
    bool heapyfy = true;
    while(heapyfy) {
        for(; i >= 0; --i) {
            int left = 2*i + 1;
            int right = 2*i + 2;
            if(right > heap_size - 1) {
                if(arr[left] > arr[i]) {
                    std::swap(arr[left], arr[i]);
#ifdef DEBUG_
                    n++;
                    std::cout << "Step " << n << ": ";
                    for (int m = 0; m < SIZE; ++m) {
                        std::cout << arr[m] << ' ';
                    }
                    std::cout << std::endl;
        
#endif
            }

            } else {
                if(arr[left] >= arr[right] && arr[left] > arr[i]) {
                    std::swap(arr[left], arr[i]);
#ifdef DEBUG_

                    n++;
                    std::cout << "Step " << n << ": ";
                    for (int m = 0; m < SIZE; ++m) {
                        std::cout << arr[m] << ' ';
                    }
                    std::cout << std::endl;
#endif

                    if(arr[right] > arr[0] || arr[left] > arr[0] || (arr[right] > arr[0] && arr[left] > arr[0])) heapyfy = false;
                    continue;
                }
                if(arr[right] > arr[left] && arr[right] > arr[i]) { std::swap(arr[right], arr[i]);
#ifdef DEBUG_

                    n++;
                    std::cout << "Step " << n << ": ";
                    for (int m = 0; m < SIZE; ++m) {
                        std::cout << arr[m] << ' ';
                    }
                    std::cout << std::endl;
#endif

                    if(arr[right] > arr[0] || arr[left] > arr[0] || (arr[right] > arr[0] && arr[left] > arr[0])) heapyfy = false;
                    continue;
                }
            }
        }
        if(heapyfy == true) break;
        i = heap_size/2-1;
        heapyfy = true;
    }
}

void heap_sort(int *arr) {
    int heap_size = SIZE;
    int n = 0;
    build_max_heap(arr, heap_size, n);
    while (heap_size > 1) {
        std::swap(arr[0], arr[heap_size-1]);
#ifdef DEBUG_
        n++;
        std::cout << "Step " << n << ": ";
        for (int m = 0; m < SIZE; ++m) {
            std::cout << arr[m] << ' ';
        }
        std::cout << std::endl;
#endif

        heap_size--;
        build_max_heap(arr, heap_size, n);
    }
#ifdef DEBUG_
    std::cout << "Number of rearrangements: " << n << std::endl;
#endif

}

void gnome_sort(int *arr) {
    int n = 0;
    for(int i = 0; i < SIZE; ++i) {
        if(i != SIZE - 1 && arr[i] > arr[i+1]) {
            std::swap(arr[i], arr[i + 1]);
#ifdef DEBUG_
            n++;
            std::cout << "Step " << n << ": ";
            for (int m = 0; m < SIZE; ++m) {
                std::cout << arr[m] << ' ';
            }
            std::cout << std::endl;
#endif
            if (i != 0) i -= 2;
        }
    }
}
