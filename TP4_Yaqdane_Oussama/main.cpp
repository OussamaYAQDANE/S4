#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

#ifndef EXO
    #define EXO 5
#endif


#if EXO == 1
int main(){
    int arr[] = {10,20,30,40,50};
    int sum = 0;
    cout << "Elements: ";
    for (auto i: arr){
        sum+=i;
        cout<< i<<" ";
    }
    cout<<endl;
    cout<<sum<<endl;
}


#elif EXO == 2

int main(){
    int matrix[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int sum = 0;
    for (int i=0; i<3; ++i){
        for (int j=0; j<3; ++j){
            cout<<matrix[i][j] <<" ";
        }
        sum+=matrix[i][i];
        cout<<endl;
    }
    cout<<sum<<endl;

}


#elif EXO == 3

int main(){
    array<int, 5> arr = {2, 9, 8, 6, 5};

    cout << "Original array: ";
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        cout << *it << " ";
    }
    
    std::cout << "\nReversed array: ";
    for (auto it = arr.rbegin(); it != arr.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

#elif EXO == 4


int main() {
    vector<int> numbers;
    cout << "Enter your list: " << std::endl;
    string input;
    getline(cin, input);
    
    int index = 0;
    string chunk;
    
    while (index < input.length()) {
        if (input[index] != ' ') {
            chunk += input[index];
        } else {
            if (!chunk.empty()) {
                numbers.push_back(std::stoi(chunk));
                chunk.clear();
            }
        }
        ++index;
    }
    if (!chunk.empty()) {
        numbers.push_back(stoi(chunk));
    }

    cout << "The doubled list is: ";
    for (int& num : numbers) {
        num *= 2;
        cout << num << " ";
    }
    cout<<endl;

    return 0;
}


#elif EXO == 5


int main() {
    list<int> numbers;
    int value;

    cout << "Enter numbers (end input with any non-integer):" << endl;
    
    while (cin >> value) {
        numbers.push_back(value);
    }
    
    cin.clear();
    cin.ignore(); 

    cout << "Enter the number you want to add at the beginning: ";
    int firstNumber;
    cin >> firstNumber;
    numbers.push_front(firstNumber);

    cout << "Enter the number you want to add at the end: ";
    int lastNumber;
    cin >> lastNumber;
    numbers.push_back(lastNumber);

    cout << "Updated list: ";
    for (int num : numbers) {
        cout << num << " ";
    }

    cout << endl;
    return 0;
}

#elif EXO == 6

int main() {
    set<int> numbersSet;
    cout << "Enter your set: " << endl;

    string input;
    getline(cin, input);

    string currentNumber;
    for (char c : input) {
        if (c != ' ') {
            currentNumber += c;
        } else {
            if (!currentNumber.empty()) {
                numbersSet.insert(stoi(currentNumber));
                currentNumber.clear();
            }
        }
    }
    if (!currentNumber.empty()) {
        numbersSet.insert(stoi(currentNumber));
    }

    cout << "The original set: ";
    for (int num : numbersSet) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Try a number you know you already added: ";
    int knownNumber;
    cin >> knownNumber;
    numbersSet.insert(knownNumber);

    cout << "After insertion: ";
    for (int num : numbersSet) {
        cout << num << " ";
    }
    cout << " (no duplicates)" << endl;

    return 0;
}

#elif EXO == 7

int main() {
    // Déclaration du std::map
    std::map<std::string, int> notes;

    // Ajout des étudiants et leurs notes
    notes["John"] = 85;
    notes["Alice"] = 90;
    notes["Bob"] = 78;

    // Affichage des notes
    for (const auto& pair : notes) {
        std::cout << pair.first << " : " << pair.second << std::endl;
    }

    return 0;
}

#elif EXO == 8

int main() {
    unordered_map<string, int> wordCount;
    cout << "Enter your words: " << endl;

    string input;
    getline(cin, input);

    string currentWord;
    for (char c : input) {
        if (c != ' ') {
            currentWord += c;
        } else {
            if (!currentWord.empty()) {
                wordCount[currentWord]++;
            }
            currentWord.clear();
        }
    }

    if (!currentWord.empty()) {
        wordCount[currentWord]++;
    }

    cout << "Word count: " << endl;
    for (const auto& pair : wordCount) {
        cout << pair.first << " : " << pair.second << endl;
    }

    return 0;
}

#elif EXO == 9

int main() {
    vector<int> numbers;
    cout << "Enter your list: " << endl;

    string input;
    getline(cin, input);

    string currentNumber;
    for (char c : input) {
        if (c != ' ') {
            currentNumber += c;
        } else {
            if (!currentNumber.empty()) {
                numbers.push_back(stoi(currentNumber));
            }
            currentNumber.clear();
        }
    }

    // Handle last number if any
    if (!currentNumber.empty()) {
        numbers.push_back(stoi(currentNumber));
    }

    cout << "The original list: ";
    for (int num : numbers) {
        cout << num << " ";
    }

    sort(numbers.begin(), numbers.end());

    cout << "\nThe sorted list: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

#elif EXO == 10

int main(){
    set<int> s={100,4,200,1,3,2};
    int longest=0;
    vector<int> best;
    for(int x:s){
        if(!s.count(x-1)){
            vector<int> temp;
            temp.push_back(x);
            int y=x+1;
            while(s.count(y)){
                temp.push_back(y);
                y++;
            }
            if(temp.size()>longest){
                longest=temp.size();
                best=temp;
            }
        }
    }
    cout<<"Longest sequence: "<<longest<<" (";
    for(int i=0;i<best.size();i++){
        cout<<best[i]<<(i+1<best.size()?", ":"");
    }
    cout<<")"<<endl;
    return 0;
}

#elif EXO == 11

// Function to get a value from the cache. If not found, return -1.
int get(list<pair<int, int>>& cache, unordered_map<int, list<pair<int, int>>::iterator>& lru, int key) {
    // If key is not found in the LRU map, return -1 (cache miss)
    if (lru.find(key) == lru.end()) return -1;

    // Fetch the iterator to the key-value pair
    list<pair<int, int>>::iterator it = lru[key];
    
    // Save the item, then erase it from its current position in the list
    pair<int, int> item = *it;
    cache.erase(it);
    
    // Place the item at the front of the cache (most recently used)
    cache.push_front(item);
    
    // Update the position of the item in the LRU map
    lru[key] = cache.begin();
    
    // Return the value of the item (second element of the pair)
    return item.second;
}

// Function to put a key-value pair into the cache
void put(list<pair<int, int>>& cache, unordered_map<int, list<pair<int, int>>::iterator>& lru, int key, int value, int cap) {
    // If the key already exists in the cache, update its value and move it to the front
    if (lru.find(key) != lru.end()) {
        list<pair<int, int>>::iterator it = lru[key];
        pair<int, int> item = *it;
        item.second = value; // Update value
        
        // Remove the old position and move the updated item to the front
        cache.erase(it);
        cache.push_front(item);
        
        // Update the LRU map to point to the new front position
        lru[key] = cache.begin();
    } else {
        // If the cache is at full capacity, remove the least recently used item
        if (cache.size() == cap) {
            int lrukey = cache.back().first;
            lru.erase(lrukey);  // Remove from the LRU map
            cache.pop_back();    // Remove from the cache
        }
        
        // Add the new key-value pair to the front of the cache
        cache.push_front({key, value});
        
        // Update the LRU map to point to the front of the cache
        lru[key] = cache.begin();
    }
}

// Function to display the current state of the cache
void display(list<pair<int, int>>& cache) {
    cout << "Current state of the cache: ";
    
    // Loop through the cache list and print all key-value pairs
    for (auto i : cache) {
        cout << "( " << i.first << ", " << i.second << " ) ";
    }
    cout << endl;
}

int main() {
    list<pair<int, int>> cache;  // The cache itself (a doubly linked list)
    unordered_map<int, list<pair<int, int>>::iterator> lru;  // LRU map to store iterators to cache positions
    int capacity;

    // Prompt the user to enter the cache capacity
    cout << "Enter the capacity of the LRU cache: ";
    cin >> capacity;

    // Add some values to the cache
    put(cache, lru, 1, 10, capacity);
    put(cache, lru, 2, 20, capacity);
    
    // Test getting a value from the cache
    cout << "Value for key 1: " << get(cache, lru, 1) << endl;

    // Add more values, evicting least recently used ones if necessary
    put(cache, lru, 55, 22, capacity);
    put(cache, lru, 2, 33, capacity);
    
    // Display the cache state
    display(cache);

    return 0;
}

#endif