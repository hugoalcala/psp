#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
 
std::mutex mtx;
int sharedCounter = 0;
 
void incrementCounter(int threadId) {
    for (int i = 0; i < 100; ++i) {
        std::lock_guard<std::mutex> lock(mtx);
        ++sharedCounter;
        std ::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    std::cout << "Thread " << threadId << " finished.\n";
}
 
int main() {
    const int numThreads = 5;
    std::vector<std::thread> threads;
    // Launch multiple threads to increment the counter
    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(incrementCounter, i);
    }
    // Join all threads to ensure they complete before exiting
    for (auto &t : threads) {
        t.join();
    }
    // Output the final value of the shared counter
    std::cout << "Final sharedCounter value: " << sharedCounter << std::endl;
    return 0;
}