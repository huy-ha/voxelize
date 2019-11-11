#include <Voxelize.hpp>
#include <iostream>
#include <nlohmann/json.hpp>

void Voxelize(VoxelMask &mask,nlohmann::json &output){
    using namespace std;
    mask.set(0,0,0,true);
    mask.set(0,1,0,true);
    mask.ForEachVoxel([](int i, int j, int k, bool val){
        cout << i << j << k << ":" << val<<endl;
    });
    output["vertices"] = "vertices";
    output["edges"] = "edges";
    output["faces"] = "faces";
}