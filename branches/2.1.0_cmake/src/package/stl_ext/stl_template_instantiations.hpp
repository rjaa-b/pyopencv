#ifndef SD_stl_TEMPLATE_INSTANTIATIONS_HPP
#define SD_stl_TEMPLATE_INSTANTIATIONS_HPP

class stl_dummy_struct {
public:
    struct dummy_struct2 {};
    static const int total_size = 0
        + sizeof(std::vector<char>)
        + sizeof(std::vector<double>)
        + sizeof(std::vector<float>)
        + sizeof(std::vector<int>)
        + sizeof(std::vector<long long>)
        + sizeof(std::vector<long>)
        + sizeof(std::vector<short>)
        + sizeof(std::vector<std::vector<float> >)
        + sizeof(std::vector<std::vector<int> >)
        + sizeof(std::vector<unsigned char *>)
        + sizeof(std::vector<unsigned char>)
        + sizeof(std::vector<unsigned int>)
        + sizeof(std::vector<unsigned long long>)
        + sizeof(std::vector<unsigned long>)
        + sizeof(std::vector<unsigned short>);
};

#endif
