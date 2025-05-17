#pragma once
#include <functional>
#include <string>
#include <unordered_map>
#include "Algorithm.hpp"

class Registry {
public:
    using Creator = std::function<Algorithm*()>;

    static Registry& instance() {
        static Registry r;
        return r;
    }

    void register_class(const std::string& name, Creator creator) {
        creators[name] = creator;
    }

    Algorithm* create(const std::string& name) {
        if (creators.count(name)) {
            return creators[name]();
        }
        return nullptr;
    }

private:
    std::unordered_map<std::string, Creator> creators;
};

#define REGISTER_ALGORITHM(ClassName) \
    namespace { \
        struct ClassName##Register { \
            ClassName##Register() { \
                Registry::instance().register_class(#ClassName, []() -> Algorithm* { return new ClassName(); }); \
            } \
        }; \
        static ClassName##Register global_##ClassName##_register; \
    }

