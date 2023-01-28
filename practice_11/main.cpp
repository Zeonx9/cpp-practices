//
// Created by musht on 26.12.2022.
//

#include <unordered_map>
#include <string>
#include <utility>
#include <vector>
#include <set>
#include <iostream>
#include <deque>

#define C

class Solution_display_table_of_food_oreders {
    using Strings = std::vector<std::string>;
    using Table = std::vector<Strings>;
public:
    static Table displayTable(Table & orders) {

        std::set<std::string> foods;
        std::set<int> table_numbers;
        std::unordered_map<std::string, std::unordered_map<int, int>> counter;

        // count every orders
        for (auto &order : orders) {
            int tab_num = std::stoi(order[1]);
            foods.insert(order[2]);
            table_numbers.insert(tab_num);

            if (counter[order[2]].contains(tab_num))
                ++counter[order[2]][tab_num];
            else
                counter[order[2]][tab_num] = 1;
        }

        Table output(table_numbers.size() + 1);
        output[0].push_back("Table");

        for (auto &food : foods)
            output[0].push_back(food);

        int i = 1;
        for (auto & t_num : table_numbers) {
            output[i].push_back(std::to_string(t_num));
            for (auto &food : foods) {
                if (counter[food].contains(t_num))
                    output[i].push_back(std::to_string(counter[food][t_num]));
                else
                    output[i].push_back("0");
            }
            ++i;
        }
        return output;
    }
};

#ifdef A
int main() {
    std::vector<std::vector<std::string>> inp{
        {"David","3","Ceviche"}, {"Corina","10","Beef Burrito"},
        {"David","3","Fried Chicken"}, {"Carla","5","Water"},
        {"Carla","5","Ceviche"}, {"Rous","3","Ceviche"}
    };
    auto res = Solution_display_table_of_food_oreders::displayTable(inp);
    std::cout << "done\n";
}
#endif

class UndergroundSystem {
private:
    using station = std::string;
    using timeData = std::pair<int, int>;

    struct path {
        station in, out;
        bool operator==(const path &other) const {
            return in == other.in and out == other.out;
        }
    };
    struct hasher {
        auto operator()(const path &p) const -> std::size_t {
            return std::hash<station>{}(p.in) ^ (std::hash<station>{}(p.out) << 1);
        }
    };

    struct rideInfo {
        station in;
        int t=0;
    };

    std::unordered_map<int, rideInfo> rides;
    std::unordered_map<path, timeData, hasher> statistics;

public:
    UndergroundSystem()=default;

    void checkIn(int id, const std::string &stationName, int t) {
        rides[id] = rideInfo{stationName, t};
    }

    void checkOut(int id, const std::string &stationName, int t) {
        auto &info = rides[id];
        int time = t - info.t;

        path p{info.in, stationName};
        if (statistics.find(p) != statistics.end()) {
            auto &prev = statistics[p];
            ++prev.first;
            prev.second += time;
        } else {
            statistics[p] = std::pair{1, time};
        }
    }

    double getAverageTime(const std::string &startStation, const std::string &endStation) {
        path p = {startStation, endStation};
        if (statistics.find(p) == statistics.end())
            return 0;
        auto &info = statistics[p];
        return (double) info.second / (double) info.first;
    }
};

#ifdef B
int main() {
    UndergroundSystem us;
    us.checkIn(45,"Leyton",3);
    us.checkIn(32,"Paradise",8);
    us.checkIn(27,"Leyton",10);
    us.checkOut(45,"Waterloo",15);
    us.checkOut(27,"Waterloo",20);
    us.checkOut(32,"Cambridge",22);
    std::cout << us.getAverageTime("Paradise","Cambridge") << "\n";
    std::cout << us.getAverageTime("Leyton","Waterloo") << "\n";
    us.checkIn(10,"Leyton",24);
    std::cout << us.getAverageTime("Leyton","Waterloo") << "\n";
    us.checkOut(10,"Waterloo",38);
    std::cout << us.getAverageTime("Leyton","Waterloo") << "\n";
}
#endif

class Employee {
public:
    int id;
    int importance;
    std::vector<int> subordinates;
    Employee(int i, int m, std::initializer_list<int> ini) : id(i), importance(m), subordinates(ini) {}
};

class SolutionEmployeeImportance {
public:
    static int getImportance(const std::vector<Employee*> &employees, int id) {
        std::unordered_map<int, Employee*> employee_index;
        for (auto emp : employees) {
            employee_index[emp->id] = emp;
        }
        int out = 0;
        std::deque<int> ids{id};
        while (not ids.empty()) {
            int cur = ids.front();
            ids.pop_front();

            out += employee_index[cur]->importance;

            for (auto e : employee_index[cur]->subordinates) {
                ids.push_back(e);
            }
        }
        return out;
    }
};

#ifdef C
int main() {
    std::vector<Employee *> employees{
        new Employee{1, 5, {2, 3}}, 
        new Employee{2, 3, {}}, 
        new Employee{3, 3, {}}
    };
    
    std::cout << SolutionEmployeeImportance::getImportance(employees, 1);
}
#endif