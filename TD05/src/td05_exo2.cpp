#include "td05_exo2.hpp"

std::vector<std::pair<Insect, int>> get_insect_observations(
    const size_t number_of_observations,
    std::vector<float> const& insect_probabilities,
    const unsigned int seed) 
{
    // Create a random engine with a given seed
    std::default_random_engine random_engine(seed);

    auto randInsectIndex { std::bind(std::discrete_distribution<size_t>{insect_probabilities.begin(), insect_probabilities.end()}, random_engine) };
    
    std::vector<std::pair<Insect, int>> observations {};
    observations.reserve(number_of_observations);

    for(size_t i {0}; i < number_of_observations; ++i) {
        size_t const random_insect_index { randInsectIndex() };
        Insect const random_insect { insect_values[random_insect_index] };
        
        //If we have already seen the same insect, increment the count on the last observation
        auto& previous_observation { observations.back() };
        if(previous_observation.first == random_insect) {
            previous_observation.second++;
            i -= 1;
        } else {
            observations.push_back({random_insect, 1});
        }
    }

    return observations;
}

std::vector<float> probabilities_from_count(std::vector<int> const& counts)
{
    std::vector<float> proba {};
    float total {};
    for (int i {0}; i < counts.size(); i++)
    {
        total += static_cast<float>(counts[i]);
    }
    for (int j {0}; j < counts.size(); j++)
    {
        proba.push_back(static_cast<float>(counts[j])/total);
    }
    return proba;
}

std::unordered_map<Insect, int> show_insect_number(size_t nb_observ)
{
    std::vector<float> insec_proba {probabilities_from_count(expected_insect_counts)};
    std::vector<std::pair<Insect,int>> observations {get_insect_observations(nb_observ,insec_proba)};
    //std::cout << observations.size() << std::endl;
    std::unordered_map<Insect, int> count_insect {};
    for (size_t i {0} ; i < observations.size(); i++)
    {
        if (count_insect.find(std::get<0>(observations[i])) == count_insect.end())
        {
            count_insect[std::get<0>(observations[i])] = std::get<1>(observations[i]);
        }
        else
        {
            count_insect[std::get<0>(observations[i])] += std::get<1>(observations[i]);
        }
    }
    for (int j {0}; j < count_insect.size(); j++ )
    {   
        std::cout << insect_to_string.find(insect_values[j])->second  << " est apparu " << count_insect[static_cast<Insect>(j)]  << std::endl;   
    }
    return count_insect;
}

std::vector<int> convert_count (std::unordered_map<Insect, int> const& count_insect)
{

}

int main()
{
    std::unordered_map<Insect, int> count_insect {show_insect_number(10000)};
    return 0;
}