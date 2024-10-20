#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;
#define NUM_CITIES 4
// Distance matrix representing distances between cities
int distance_matrix[NUM_CITIES][NUM_CITIES] = {
   {0, 10, 15, 20},
   {10, 0, 35, 25},
   {15, 35, 0, 30},
   {20, 25, 30, 0}
};
int total_distance(const std::vector<int>& path) {
   // Calculate the total distance traveled in the given path
   int total = 0;
   for (size_t i = 0; i < path.size() - 1; i++) {
       total += distance_matrix[path[i]][path[i + 1]];
   }
   total += distance_matrix[path.back()][path[0]]; // Return to starting city
   return total;
}
void hill_climbing_tsp(int num_cities, int max_iterations) {
   vector<int> current_path(num_cities); // Initial solution, visiting cities in order
   for (int i = 0; i < num_cities; i++) {
      current_path[i] = i;
   }
   int current_distance = total_distance(current_path);
   for (int it = 0; it < max_iterations; it++) {
      // Generate a neighboring solution by swapping two random cities
      std::vector<int> neighbor_path = current_path;
      int i = rand() % num_cities;
      int j = rand() % num_cities;
      swap(neighbor_path[i], neighbor_path[j]);
      int neighbor_distance = total_distance(neighbor_path);
      // If the neighbor solution is better, move to it
      if (neighbor_distance < current_distance) {
         current_path = neighbor_path;
         current_distance = neighbor_distance;
      }
   }
   cout << "Optimal path: ";
   for (int city : current_path) {
      cout << city << " ";
   }
   cout << endl;
   cout << "Total distance: " << current_distance << endl;
}
int main() {
   srand(time(NULL));
   int max_iterations = 10000;
   hill_climbing_tsp(NUM_CITIES, max_iterations);
   return 0;
}