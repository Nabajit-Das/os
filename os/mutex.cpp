#include <iostream>

#include <thread>

#include <mutex>

#include <unistd.h>

#include <random>



using namespace std;



const int num_philosophers = 5;

const int max_meals = 5;

mutex forks[num_philosophers];

mutex coutMutex;  // Added coutMutex to protect access to cout



void think(int philosopher) {

    unique_lock<mutex> lock(coutMutex);

    cout << "Philosopher " << philosopher << " is thinking....\n";

    lock.unlock();

    sleep(rand() % 3 + 1);

}



void eat(int philosopher) {

    unique_lock<mutex> lock(coutMutex);

    cout << "Philosopher " << philosopher << " is eating...\n";

    lock.unlock();

    sleep(rand() % 3 + 1);

}



void philosopher(int id) {

    int leftfork = id;

    int rightfork = (id + 1) % num_philosophers;  // Fixed variable name from rightform to rightfork

    int mealsEaten = 0;



    while (mealsEaten < max_meals) {

        think(id);



        if (id % 2 == 0) {

            forks[leftfork].lock();

            forks[rightfork].lock();

        } else {

            forks[rightfork].lock();

            forks[leftfork].lock();

        }



        eat(id);

        mealsEaten++;



        forks[rightfork].unlock();

        forks[leftfork].unlock();

    }



    unique_lock<mutex> lock(coutMutex);

    cout << "Philosopher " << id << " has finished eating " << max_meals << " meals.\n";

}



int main() {

    thread philosophers[num_philosophers];



    for (int i = 0; i < num_philosophers; i++) {

        philosophers[i] = thread(philosopher, i);

    }



    for (int i = 0; i < num_philosophers; i++) {

        philosophers[i].join();

    }



    return 0;

}

