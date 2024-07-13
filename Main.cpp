#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Robot {
 public:
  Robot(int name, int position, int health, string direction)
      : name(name), position(position), health(health), direction(direction) {}

  int name;
  int position;
  int health;
  string direction;
};

class Collision {
 public:
  Collision(Robot robot1, Robot robot2) : robot1(robot1), robot2(robot2) {
    distance = abs(robot1.position - robot2.position);
  };
  int distance;
  Robot robot1;
  Robot robot2;
};

static vector<int> foo(vector<int>& positions, vector<int>& healths,
                       string directions) {
  // Add the robots to a vector so we can compare them
  vector<Robot> robots;
  for (int i = 0; i < positions.size(); ++i) {
    robots.emplace_back(i + 1, positions[i], healths[i],
                        string(1, directions[i]));
  }

  // ----- Simulation -----

  // Add all potential collisions to a vector
  vector<Collision> collisions;
  for (size_t i = 0; i < robots.size(); i++) {
    for (size_t j = 0; j < robots.size(); j++) {
      if (i == j) continue;

      // We have a collision
      if ((robots[i].direction == "L" && robots[j].direction == "R" &&
           robots[i].position > robots[j].position) ||
          (robots[i].direction == "R" && robots[j].direction == "L" &&
           robots[i].position < robots[j].position)) {
        collisions.emplace_back(robots[i], robots[j]);
      }
    }
  }

  // Sort the collisions based on distance
  sort(collisions.begin(), collisions.end(),
       [](const Collision& lhs, const Collision& rhs) {
         return lhs.distance < rhs.distance;
       });

  // Simulate collisions
  for (auto& collision : collisions) {
    bool robot1Exist = false;
    bool robot2Exist = false;

    // Do both robots exist?
    for (auto& robot : robots) {
      if (robot.name == collision.robot1.name)
        robot1Exist = true;
      else if (robot.name == collision.robot2.name)
        robot2Exist = true;

      if (robot1Exist && robot2Exist) break;
    }

    // Both exist, simulate collision
    if (robot1Exist && robot2Exist) {
      int robot1Name = collision.robot1.name;
      int robot2Name = collision.robot2.name;

      // Both have same health, remove both robots
      if (collision.robot1.health == collision.robot2.health) {
        auto it1 = find_if(robots.begin(), robots.end(),
                           [robot1Name](const Robot& robot) {
                             return robot.name == robot1Name;
                           });
        robots.erase(it1);

        auto it2 = find_if(robots.begin(), robots.end(),
                           [robot2Name](const Robot& robot) {
                             return robot.name == robot2Name;
                           });
        robots.erase(it2);
      }

      // Robot 1 have more health, remove robot 2 and decrease robot1 with one
      else if (collision.robot1.health > collision.robot2.health) {
        auto it1 = find_if(robots.begin(), robots.end(),
                           [robot1Name](const Robot& robot) {
                             return robot.name == robot1Name;
                           });
        it1->health--;

        auto it2 = find_if(robots.begin(), robots.end(),
                           [robot2Name](const Robot& robot) {
                             return robot.name == robot2Name;
                           });
        robots.erase(it2);
      }

      // Vice versa
      else {
        auto it1 = find_if(robots.begin(), robots.end(),
                           [robot1Name](const Robot& robot) {
                             return robot.name == robot1Name;
                           });
        robots.erase(it1);

        auto it2 = find_if(robots.begin(), robots.end(),
                           [robot2Name](const Robot& robot) {
                             return robot.name == robot2Name;
                           });
        it2->health--;
      }
    }
  }

  // Sort robots by name
  sort(robots.begin(), robots.end(),
       [](const Robot& lhs, const Robot& rhs) { return lhs.name < rhs.name; });

  vector<int> result;
  for (const auto& robot : robots) {
    result.push_back(robot.health);
  }

  return result;
}

int main() {
  vector<int> positions = {3, 47};
  vector<int> healths = {46, 26};
  string directions = "LR";
  vector<int> result = foo(positions, healths, directions);

  return 0;
}
