#include <Voxelize.hpp>
#include <iostream>
#include <nlohmann/json.hpp>
#include <set>
#include <tuple>
#include <algorithm>

static int IndexOfPoint(vector<tuple<double, double, double>> &points, const tuple<double, double, double> &point)
{
    auto it = find(points.begin(), points.end(), point);
    if (it == points.end())
        return -1;
    return it - points.begin();
}

void RemoveDuplicatePoints(shared_ptr<vector<tuple<double, double, double>>> &points){
    auto unique_points = make_shared<vector<tuple<double, double, double>>>(points->size());
    
    auto it = copy_if(points->begin(),points->end(),unique_points->begin(),[&](auto p1){
        double x = get<0>(p1);
        double y = get<1>(p1);
        double z = get<2>(p1);
        return find_if(unique_points->begin(),unique_points->end(),[&](auto p2){
            return get<0>(p2) == x && get<1>(p2) == y && get<2>(p2) == z;
        }) == unique_points->end();
    });

    unique_points->resize(distance(unique_points->begin(),it));

    points = unique_points;
}

void Voxelize(VoxelMask &mask, nlohmann::json &output, double L)
{
    using namespace std;
    double x, y, z, x_other, y_other, z_other, length;
    int idx;
    auto points = make_shared<vector<tuple<double, double, double>>>();
    vector<tuple<int, int, double>> edges;
    mask.ForEachVoxel([&](int i, int j, int k, bool val) {
        if (val)
        {
            points->push_back(make_tuple(i - 0.5, j - 0.5, k - 0.5));
            points->push_back(make_tuple(i - 0.5, j - 0.5, k + 0.5));
            points->push_back(make_tuple(i - 0.5, j + 0.5, k - 0.5));
            points->push_back(make_tuple(i - 0.5, j + 0.5, k + 0.5));
            points->push_back(make_tuple(i + 0.5, j - 0.5, k - 0.5));
            points->push_back(make_tuple(i + 0.5, j - 0.5, k + 0.5));
            points->push_back(make_tuple(i + 0.5, j + 0.5, k - 0.5));
            points->push_back(make_tuple(i + 0.5, j + 0.5, k + 0.5));
        }
    });
    RemoveDuplicatePoints(points);

    // add unique particles
    for (int i = 0; i < points->size(); ++i)
    {
        x = get<0>((*points)[i]);
        y = get<1>((*points)[i]);
        z = get<2>((*points)[i]);

        nlohmann::json point;
        point["x"] = x * L;
        point["y"] = y * L;
        point["z"] = z * L;
        output["vertices"].push_back(point);

        // main structural
        if ((idx = IndexOfPoint((*points), make_tuple(x, y, z + 1))) != -1)
        {
            x_other = get<0>((*points)[idx]);
            y_other = get<1>((*points)[idx]);
            z_other = get<2>((*points)[idx]);
            length = pow(pow(x - x_other, 2) + pow(y - y_other, 2) + pow(z - z_other, 2), 0.5) * L;
            edges.push_back(make_tuple(max(i, idx), min(i, idx), length));
        }
        if ((idx = IndexOfPoint((*points), make_tuple(x, y + 1, z))) != -1)
        {
            x_other = get<0>((*points)[idx]);
            y_other = get<1>((*points)[idx]);
            z_other = get<2>((*points)[idx]);
            length = pow(pow(x - x_other, 2) + pow(y - y_other, 2) + pow(z - z_other, 2), 0.5) * L;
            edges.push_back(make_tuple(max(i, idx), min(i, idx), length));
        }
        if ((idx = IndexOfPoint((*points), make_tuple(x + 1, y, z))) != -1)
        {
            x_other = get<0>((*points)[idx]);
            y_other = get<1>((*points)[idx]);
            z_other = get<2>((*points)[idx]);
            length = pow(pow(x - x_other, 2) + pow(y - y_other, 2) + pow(z - z_other, 2), 0.5) * L;
            edges.push_back(make_tuple(max(i, idx), min(i, idx), length));
        }
        if ((idx = IndexOfPoint((*points), make_tuple(x + 1, y + 1, z))) != -1)
        {
            x_other = get<0>((*points)[idx]);
            y_other = get<1>((*points)[idx]);
            z_other = get<2>((*points)[idx]);
            length = pow(pow(x - x_other, 2) + pow(y - y_other, 2) + pow(z - z_other, 2), 0.5) * L;
            edges.push_back(make_tuple(max(i, idx), min(i, idx), length));
        }
        if ((idx = IndexOfPoint((*points), make_tuple(x + 1, y, z + 1))) != -1)
        {
            x_other = get<0>((*points)[idx]);
            y_other = get<1>((*points)[idx]);
            z_other = get<2>((*points)[idx]);
            length = pow(pow(x - x_other, 2) + pow(y - y_other, 2) + pow(z - z_other, 2), 0.5) * L;
            edges.push_back(make_tuple(max(i, idx), min(i, idx), length));
        }
        if ((idx = IndexOfPoint((*points), make_tuple(x, y + 1, z + 1))) != -1)
        {
            x_other = get<0>((*points)[idx]);
            y_other = get<1>((*points)[idx]);
            z_other = get<2>((*points)[idx]);
            length = pow(pow(x - x_other, 2) + pow(y - y_other, 2) + pow(z - z_other, 2), 0.5) * L;
            edges.push_back(make_tuple(max(i, idx), min(i, idx), length));
        }
        if ((idx = IndexOfPoint((*points), make_tuple(x + 1, y + 1, z + 1))) != -1)
        {
            x_other = get<0>((*points)[idx]);
            y_other = get<1>((*points)[idx]);
            z_other = get<2>((*points)[idx]);
            length = pow(pow(x - x_other, 2) + pow(y - y_other, 2) + pow(z - z_other, 2), 0.5) * L;
            edges.push_back(make_tuple(max(i, idx), min(i, idx), length));
        }

        if ((idx = IndexOfPoint((*points), make_tuple(x + 1, y - 1, z))) != -1)
        {
            x_other = get<0>((*points)[idx]);
            y_other = get<1>((*points)[idx]);
            z_other = get<2>((*points)[idx]);
            length = pow(pow(x - x_other, 2) + pow(y - y_other, 2) + pow(z - z_other, 2), 0.5) * L;
            edges.push_back(make_tuple(max(i, idx), min(i, idx), length));
        }
        if ((idx = IndexOfPoint((*points), make_tuple(x, y - 1, z))) != -1)
        {
            x_other = get<0>((*points)[idx]);
            y_other = get<1>((*points)[idx]);
            z_other = get<2>((*points)[idx]);
            length = pow(pow(x - x_other, 2) + pow(y - y_other, 2) + pow(z - z_other, 2), 0.5) * L;
            edges.push_back(make_tuple(max(i, idx), min(i, idx), length));
        }
        if ((idx = IndexOfPoint((*points), make_tuple(x + 1, y - 1, z + 1))) != -1)
        {
            x_other = get<0>((*points)[idx]);
            y_other = get<1>((*points)[idx]);
            z_other = get<2>((*points)[idx]);
            length = pow(pow(x - x_other, 2) + pow(y - y_other, 2) + pow(z - z_other, 2), 0.5) * L;
            edges.push_back(make_tuple(max(i, idx), min(i, idx), length));
        }
        if ((idx = IndexOfPoint((*points), make_tuple(x + 1, y - 1, z - 1))) != -1)
        {
            x_other = get<0>((*points)[idx]);
            y_other = get<1>((*points)[idx]);
            z_other = get<2>((*points)[idx]);
            length = pow(pow(x - x_other, 2) + pow(y - y_other, 2) + pow(z - z_other, 2), 0.5) * L;
            edges.push_back(make_tuple(max(i, idx), min(i, idx), length));
        }
        if ((idx = IndexOfPoint((*points), make_tuple(x - 1, y - 1, z + 1))) != -1)
        {
            x_other = get<0>((*points)[idx]);
            y_other = get<1>((*points)[idx]);
            z_other = get<2>((*points)[idx]);
            length = pow(pow(x - x_other, 2) + pow(y - y_other, 2) + pow(z - z_other, 2), 0.5) * L;
            edges.push_back(make_tuple(max(i, idx), min(i, idx), length));
        }
    }

    for (auto &edge : edges)
    {
        nlohmann::json edgeOutput;
        edgeOutput["i"] = get<0>(edge);
        edgeOutput["j"] = get<1>(edge);
        edgeOutput["length"] = get<2>(edge);
        output["edges"].push_back(edgeOutput);
    }

    // output["faces"] = "faces";
}