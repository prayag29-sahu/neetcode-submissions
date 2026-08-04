class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int, int>> cars;

        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }

        // nearest car first
        sort(cars.begin(), cars.end(), greater<pair<int, int>>());

        int fleets = 0;

        double prevTime = 0;

        for (auto& car : cars) {
            int pos = car.first;

            int spd = car.second;

            double time = (double)(target - pos) / spd;

            if (time > prevTime) {
                fleets++;

                prevTime = time;
            }
        }

        return fleets;
    }
};
