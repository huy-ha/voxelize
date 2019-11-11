#include <Voxelize.hpp>
#include <iostream>

void Voxelize(VoxelMask mask){
    using namespace std;
    mask.set(0,0,0,true);
    mask.set(0,1,0,true);
    mask.ForEachVoxel([](int i, int j, int k, bool val){
        cout << i << j << k << ":" << val<<endl;
    });
}