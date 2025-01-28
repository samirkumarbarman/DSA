#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

// Helper function to check if a given number of pages can be allocated to students
bool isPossible(const vector<int>& books, int students, int maxPages) {
    int studentCount = 1;
    int currentPageSum = 0;
    
    for (int pages : books) {
        if (pages > maxPages) {
            return false; // A single book has more pages than maxPages
        }
        
        if (currentPageSum + pages > maxPages) {
            studentCount++;
            currentPageSum = pages;
            
            if (studentCount > students) {
                return false;
            }
        } else {
            currentPageSum += pages;
        }
    }
    
    return true;
}

// Function to find the minimum number of pages
int findMinPages(const vector<int>& books, int students) {
    if (students > books.size()) {
        return -1; // Not enough books for each student
    }
    
    int low = *max_element(books.begin(), books.end());
    int high = accumulate(books.begin(), books.end(), 0);
    int result = high;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (isPossible(books, students, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    return result;
}

int main() {
    vector<int> books = {12, 34, 67, 90}; // Example book page counts
    int students = 2; // Number of students
    
    int result = findMinPages(books, students);
    
    if (result == -1) {
        cout << "It is not possible to allocate books to each student." << endl;
    } else {
        cout << "The minimum number of pages each student has to read is " << result << "." << endl;
    }
    
    return 0;
}
