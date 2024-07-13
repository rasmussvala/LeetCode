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

using RobotPtr = shared_ptr<Robot>;

class Collision {
 public:
  Collision(RobotPtr robot1, RobotPtr robot2) : robot1(robot1), robot2(robot2) {
    distance = abs(robot1->position - robot2->position);
  };
  int distance;
  RobotPtr robot1;
  RobotPtr robot2;
};

static vector<int> foo(vector<int>& positions, vector<int>& healths,
                       string directions) {
  // Add the robots to a vector so we can compare them
  vector<RobotPtr> robots;
  for (int i = 0; i < positions.size(); ++i) {
    robots.emplace_back(make_shared<Robot>(i + 1, positions[i], healths[i],
                                           string(1, directions[i])));
  }

  // Add all potential collisions to a vector
  vector<Collision> collisions;
  for (size_t i = 0; i < robots.size(); i++) {
    for (size_t j = 0; j < robots.size(); j++) {
      if (i == j) continue;

      // We have a collision
      if ((robots[i]->direction == "L" && robots[j]->direction == "R" &&
           robots[i]->position > robots[j]->position) ||
          (robots[i]->direction == "R" && robots[j]->direction == "L" &&
           robots[i]->position < robots[j]->position)) {
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
    // Both robots still exist in the vector
    if (find(robots.begin(), robots.end(), collision.robot1) != robots.end() &&
        find(robots.begin(), robots.end(), collision.robot2) != robots.end()) {
      // Both have same health, remove both robots
      if (collision.robot1->health == collision.robot2->health) {
        robots.erase(remove(robots.begin(), robots.end(), collision.robot1),
                     robots.end());
        robots.erase(remove(robots.begin(), robots.end(), collision.robot2),
                     robots.end());
      }
      // Robot 1 has more health, remove robot 2 and decrease robot1 health by
      // one
      else if (collision.robot1->health > collision.robot2->health) {
        collision.robot1->health--;
        robots.erase(remove(robots.begin(), robots.end(), collision.robot2),
                     robots.end());
      }
      // Vice versa
      else {
        collision.robot2->health--;
        robots.erase(remove(robots.begin(), robots.end(), collision.robot1),
                     robots.end());
      }
    }
  }
  // Sort robots by name
  sort(robots.begin(), robots.end(),
       [](const RobotPtr& lhs, const RobotPtr& rhs) {
         return lhs->name < rhs->name;
       });

  vector<int> result;
  for (const auto& robot : robots) {
    result.push_back(robot->health);
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
