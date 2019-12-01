#include <unordered_map>
#include <string>
#include <vector>
#include "../clustering/clustering.h"


struct WeightedNewsCluster {
    std::reference_wrapper<const NewsCluster> Cluster;
    std::string Category;
    std::string Title;
    double Weight = 0.0;
    WeightedNewsCluster(const NewsCluster& cluster, const std::string& category, const std::string& title, double weight)
        : Cluster(cluster)
        , Category(category)
        , Title(title)
        , Weight(weight)
    {}

};

std::string ComputeClusterCategory(const NewsCluster& cluster);

double ComputeClusterWeight(
    const NewsCluster& cluster,
    const std::unordered_map<std::string, double>& agencyRating
);

std::unordered_map<std::string, std::vector<WeightedNewsCluster>> Rank(
    const std::vector<NewsCluster>& clusters,
    const std::unordered_map<std::string, double>& agencyRating
);