#include <vector>
#include <iostream>

class FrequencyTracker
{
public:
    FrequencyTracker() : nums(100001, 0), freq(100001, 0)
    {
    }

    void add(int number)
    {
        std::cout << "freq[[" << number << "]] = " << freq[nums[number]] << std::endl;
        --freq[nums[number]];
        std::cout << "freq[[" << number << "]] = " << freq[nums[number]] << std::endl;

        ++nums[number];
        std::cout << "freq[[" << number << "]] = " << freq[nums[number]] << std::endl;

        ++freq[nums[number]];
        std::cout << "freq[[" << number << "]] = " << freq[nums[number]] << std::endl;
        std::cout << "-------------" << std::endl;
    }

    void deleteOne(int number)
    {
        if (nums[number] == 0)
        {
            std::cout << "nums[[" << number << "]] = " << nums[number] << std::endl;
            return;
        }
        --freq[nums[number]];
        --nums[number];
        ++freq[nums[number]];
    }

    bool hasFrequency(int frequency)
    {
        return 0 < freq[frequency];
    }

private:
    std::vector<int> nums;
    std::vector<int> freq;
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */