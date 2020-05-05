#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Kal {
public:
    int x;
    int y;
};

bool comparery(Kal a, Kal b) {
    return (a.y < b.y);
}
bool comparerx(Kal a, Kal b) {
    return (a.x < b.x);
}

int main() {
    multimap <int,int> hor;
    multimap <int,int> ver;
    int m,n,k,x,y;
    vector<Kal> vk;
    cin >> m >> n >> k;
    for(int i{0};i < k;i++){
        cin >> x >> y;
        vk.push_back({x,y});
    }

    sort(vk.begin(),vk.end(),comparery);

    for(int i{0};i < vk.size();i++){
        hor.insert(pair <int, int> (vk[i].x,vk[i].y));
    }
    sort(vk.begin(),vk.end(),comparerx);
    for(int i{0};i < vk.size();i++){
        ver.insert(pair <int, int> (vk[i].y,vk[i].x));
    }

    int count{0};
    set<pair<int,int>> single;
    for(int i{1};i<=m;i++) {
        if (hor.empty() || hor.count(i) == 0) {
            if (n-1 >= 1) count++;
            if (n == 1) {

                single.insert({i, 1});
                count++;
            }
            continue;
        };
        auto hitr1 = hor.lower_bound(i);
        auto hitr2 = hor.upper_bound(i);
        hitr2--;
        int turn{0};
        int prev{0};
        auto keyRange = hor.equal_range(i);

        if (hor.count(i) == 0) {

        }
        else {
            for (auto it{keyRange.first}; it != keyRange.second; it++) {

                if (turn == 0) {
                    if (it->second - 1 > 1) {

                        count++;
                    }
                    if (it->second - 1 == 1){
                        single.insert({i,it->second-1});

                        count++;
                    }
                    prev = it->second;
                } else {
                    if (it->second - 1 - prev > 1) {

                        count++;
                    }
                    if (it->second - prev - 1  == 1){

                        single.insert({i,it->second-1});
                        count++;
                    }
                    prev = it->second;
                }
                turn++;
            }

            if (n - hitr2->second > 1) {

                count++;
            }
            if (n - hitr2->second == 1) {

                single.insert({i,n});
                count++;
            }
        }

    }


    for(int i{1};i<=n;i++){
        if (ver.empty() || ver.count(i) == 0) {
            if (m > 1) count++;
            if (m == 1) {
                if (single.find({1,i}) != single.end()) count++;
            }
            continue;
        };
        int turn{0};
        int prev{0};
        auto vitr1 = ver.lower_bound(i);
        auto vitr2 = ver.upper_bound(i);
        vitr2--;
        auto vkeyRange = ver.equal_range(i);

        if (ver.count(i) == 0) {

        }
        else {
            for (auto it{vkeyRange.first}; it != vkeyRange.second; it++) {

                if (turn == 0) {
                    if (it->second - 1 > 1) {

                        count++;
                    }
                    if (it->second - 1 == 1) {

                        if (single.find({it->second - 1,i}) != single.end()){

                            count++;
                        }
                    }
                } else {
                    if (it->second - 1 - prev > 1) {

                        count++;
                    }
                    if (it->second - 1 - prev == 1){

                        if (single.find({it->second - 1,i}) != single.end()){

                            count++;
                        }
                    }
                }

                prev = it->second;
                turn++;
            }
            if (m - vitr2->second > 1) {

                count++;

            }
            if (m - vitr2->second == 1) {
                //cout << " IIIV : " << i << " | " << count << endl;
                if (single.find({m,i}) != single.end()){
                    //cout << "retard" << endl;
                    count++;
                }
            }


        }

    }
    //cout << count << endl;
    count -= single.size();
    cout << count;
}

