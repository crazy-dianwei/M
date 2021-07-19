#include <map>
#include <unordered_map>
#include <vector>
#include <iostream>

using std::vector;
using std::map;
using std::cout;
using std::endl;
using std::pair;
using std::unordered_map;

int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    //method2
    {
        if(startFuel >= target)return 0;
        int res = target + 1;
        sort(stations.begin(), stations.end(), [](vector<int> &v1, vector<int> &v2){return v1[0] < v2[0];});
        pair<int, unordered_map<int,int> > last;
        last.first = 0;
        last.second[0] = startFuel;
        for(int i = 0;i<stations.size();++i){
            int idx = stations[i][0];
            int fuel = stations[i][1];
            int last_idx = last.first;

            pair<int, unordered_map<int,int> > tmp;
            tmp.first = idx;

            for(auto &node: last.second){
                int step = node.first;
                int left = node.second - (idx - last_idx);
                if(left < 0){
                    continue;
                }                
                
                int fuel_c1 = left;//case1
                int fuel_c2 = left + fuel;//case2
                cout<<"fuel_c1: "<<fuel_c1<<" .fuel_c2: "<<fuel_c2<<" .step: "<<step<<" distance: "<<target - idx<<endl;

                if(fuel_c1 >= 0 && (!tmp.second.count(step) || tmp.second[step] < fuel_c1)){
                    tmp.second[step] = fuel_c1;
                }

                if(fuel_c2 >= 0 && (!tmp.second.count(step + 1) || tmp.second[step + 1] < fuel_c1)){
                    tmp.second[step + 1] = fuel_c2;
                }

                if(fuel_c1 >= (target - idx) && res > step){
                    res = step;
                }

                if(fuel_c2 >= (target - idx) && res > step + 1){
                    res = step + 1;
                }
                cout<<"res: "<<res<<endl;
            }
            last.swap(tmp);
        }
        return res > target ? -1 : res;
    }
















    if(startFuel >= target)return 0;

    map<int, vector<pair<int,int>> > um;
    um[0].push_back(pair<int,int>(startFuel, 0));

    sort(stations.begin(), stations.end(), [](vector<int> &v1, vector<int> &v2){ return v1[0] < v2[0]; });

    int res = target;
    for(int i = 0;i<stations.size();++i){
        int key = stations[i][0];
        int cur_fuel = stations[i][1];

        cout<<"stations->i: "<<i<<" .um.size(): "<<um.size()<<endl;
        for(auto &node: um){
            int idx = node.first;
            if(idx > key){
                break;
            }
            cout<<"    node.second.len:"<<node.second.size()<<endl;
            for(auto &info: node.second){
                int step = info.second + 1;
                if(step > res){
                    continue;
                }
                int node_fuel = info.first;
                node_fuel -= (key - idx);
                if(node_fuel >= 0){
                    node_fuel += cur_fuel;
                    if(node_fuel >= (target - key) && step < res){
                        res = step;
                    }
                    um[key].push_back(pair<int,int>(node_fuel, step));
                }
            }
        }
    }
    return res == target ? -1 : res;
}


int main(){
    /*
        target = 100, startFuel = 10, stations = [[10,60],[20,30] 
        1000000000, 905020228
          [151262030,251558705],
          [314274596,493894928],
          [488425232,83502071],
          [497662083,150054169],
          [511685071,384937300],
          [561251876,210964978],
          [678990826,281637332],
          [698362701,443188544],
          [850324303,106796722],
          [936328052,32852657]]
   
        100
        1
        [[10,100]]

        200
        50
        [[25,25],[50,100],[100,100],[150,40]]

    */
    {
        vector<vector<int>> stations{{25,25}, {50,100}, {100,100}, {150,40}};
        cout<<minRefuelStops(200, 50, stations)<<endl;

        return 0;

    }
    {
        vector<vector<int>> stations{{10,100}};
        cout<<minRefuelStops(100, 1, stations)<<endl;

        return 0;

    }



    {


        vector<vector<int>> stations{
            {7,13},{10,11},{12,31},{22,14},{32,26},
            {38,16},{50,8},{54,13},{75,4},{85,2},
            {88,35},{90,9},{96,35},{103,16},{115,33},
            {121,6},{123,1},{138,2},{139,34},{145,30},
            {149,14},{160,21},{167,14},{188,7},{196,27},
            {248,4},{256,35},{262,16},{264,12},{283,23},
            {297,15},{307,25},{311,35},{316,6},{345,30},
            {348,2},{354,21},{360,10},{362,28},{363,29},
            {367,7},{370,13},{402,6},{410,32},{447,20},
            {453,13},{454,27},{468,1},{470,8},{471,11},
            {474,34},{486,13},{490,16},{495,10},{527,9},
            {533,14},{553,36},{554,23},{605,5},{630,17},
            {635,30},{640,31},{646,9},{647,12},{659,5},
            {664,34},{667,35},{676,6},{690,19},{709,10},
            {721,28},{734,2},{742,6},{772,22},{777,32},
            {778,36},{794,7},{812,24},{813,33},{815,14},
            {816,21},{824,17},{826,3},{838,14},{840,8},
            {853,29},{863,18},{867,1},{881,27},{886,27},
            {894,26},{917,3},{953,6},{956,3},{957,28},
            {962,33},{967,35},{972,34},{984,8},{987,12}
        };
        cout<<minRefuelStops(1000, 36, stations)<<endl;
        //return 0;
    }



    {
        vector<vector<int>> stations{
            {4,192},{17,204},{53,373},{168,348},{188,403},
            {197,390},{237,201},{260,175},{307,191},{316,263},
            {322,242},{378,285},{412,459},{432,179},{448,281},
            {529,96},{557,285},{662,292},{800,339},{816,226},
            {875,69},{897,176},{899,138},{929,94},{941,463}
        };

        cout<<minRefuelStops(1000, 75, stations)<<endl;
        //return 0;

    }
    {   
        vector<vector<int>> stations{{151262030,251558705}, {314274596,493894928}, {488425232,83502071}, {497662083,150054169}, {511685071,384937300},
                                    {561251876,210964978}, {678990826,281637332}, {698362701,443188544}, {850324303,106796722}, {936328052,32852657}
                                    };
        cout<<minRefuelStops(1000000000, 905020228, stations)<<endl;
        //return 0;

    }

    vector<vector<int>> stations{{10, 60}, {20, 30}, {30,30},{60,40}};
    cout<<minRefuelStops(100, 10, stations)<<endl;
    return 0;
}

