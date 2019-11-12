#include <iostream>
#include <Voxelize.hpp>
#include <nlohmann/json.hpp>
#include <algorithm>

using namespace std;
int main(int argc, char **argv)
{
    nlohmann::json j;
    int n = 1;
    VoxelMask mask(n);
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            for(int z = 0; z < n; z++){
                mask.set(x,y,z,true);
            }
        }
    }
    Voxelize(mask,j);
    // cout << j.dump(4) << endl;
    cout << j["edges"].size() << endl;
    cout << j["vertices"].size() << endl;
    return 0;
}