#include <ArduinoSTL.h>
#include <limits.h>
//int randomNumb = random(0, 1000);



using namespace std;

int tsp(vector<vector<int>> &cost,vector<int> &routeTaken) {
    int numNodes = cost.size();
    vector<int> nodes;

    for (int i = 1; i < numNodes; i++) 
        nodes.push_back(i);

    int minCost = INT_MAX;

    do {
        int currCost = 0;
        int currNode = 0;
        for (int i = 0; i < nodes.size(); i++) {
            currCost += cost[currNode][nodes[i]];
            currNode = nodes[i];
        }

        currCost += cost[currNode][0];

        if(currCost < minCost) {
            //Serial.println(currCost);
            routeTaken = nodes;
        }
        minCost = min(minCost, currCost);
         
        //Serial.println(minCost);
    } while (next_permutation(nodes.begin(), nodes.end()));

    return minCost;
}

void setup() {
    Serial.begin(300); // I know 300 baud is slow. But It leaves more space for the CPU to work on solving the problem and less on the comms (Plus it makes the text scroll like an 80s terminal.. so funny)
    vector<int> routeTaken;
    vector<vector<int>> cost = {
                                {16, 0, 10, 8, 15, 20, 3, 144, 101, 80, 6},// 564}, // 1
                                {10, 0, 35, 25, 93, 44, 100, 50, 78, 103, 1456},// 69}, // 2
                                {15, 35, 0, 30, 67, 25, 74, 92, 110, 85, 1371},// 728}, // 3
                                {20, 25, 30, 0, 3, 23, 8, 100, 138, 7, 1377},// 383}, // 4
                                {70, 30, 12, 99, 7, 99, 9, 3, 55, 46, 302},// 1263}, // 5
                                {0, 44, 8, 12, 54, 3, 5, 102, 26, 153, 1115},// 966}, //6
                                {4, 6, 7, 2, 69, 420, 42, 46, 108, 136, 883},// 880}, // 7
                                {9, 44, 33, 3, 12, 87, 39, 14, 90, 128, 1319},// 528}, // 8
                                {8, 122, 136, 107, 28, 26, 34, 121, 94, 35, 818},// 361}, // 9
                                {669, 1485, 195, 467, 827, 549, 844, 1383, 990, 533, 571},// 1483}, // 10
                                {610, 278, 1011, 684, 1100, 687, 43, 1418, 1026,157, 16}  //146 11
                                //{1380, 144, 870, 678, 1139, 975, 765, 890, 938, 563, 346, 383} // 12
                                }; // You can further expand this, but my UNO ran out of SRAM at 11, I bet a Mega could do more (However do be prepared to wait for an hour(s))


    //unsigned long StartTime = millis();
    Serial.println(F("Started"));
    Serial.println(F("-----------"));

    unsigned long StartTime = millis();
    int res = tsp(cost, routeTaken);
    unsigned long CurrentTime = millis();

    Serial.print(F("Minimum cost:"));
    Serial.println(res);
    Serial.println(F("-----------"));
    
    unsigned long ElapsedTime = (CurrentTime - StartTime);
    Serial.print(F("Time elapsed: "));
    Serial.print(ElapsedTime / 1000);
    Serial.println(F("s"));
    Serial.println(F("-----------"));
    Serial.print(F("Time elapsed in millisecond: ")); // My personal record for the longest time It took It to figure out an answer is 162s (2m 42s)
    Serial.println((String)ElapsedTime + "ms");
    //Serial.println(F("ms"));

    Serial.println(F("-----------"));
    Serial.print(F("The best route taken: 0 > "));
    for (int node : routeTaken) {
        Serial.print(node);
        Serial.print(F(" > "));
    }
    Serial.println(F("0"));

    //cout << res << endl;
    //return 0;
    
}


void loop() {
    
}