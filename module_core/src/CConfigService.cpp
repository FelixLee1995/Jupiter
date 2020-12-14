#include "impl/service/CConfigService.h"
#include <fstream>

#include <thread>
#include <functional>
#include <memory>
#include <pthread.h>
#include <semaphore.h>
#include <stdint.h>
#include <atomic>
#include <list>

using namespace jupiter;

/*
 * 配置初始化
 * 默认顺序： 1. 配置文件  2. nacos
 * 当运行目录 config下config.yaml不存在时， 使用nacos 配置
 */
void CConfigService::Init() {

    std::ifstream  ifs("config/config.yaml");
    if (ifs) {
        // 读取 config.yaml配置

    }

    else {
        //todo  读取nacos 配置

    }

}


void CConfigService::Dispose() {

}

CConfigService::~CConfigService() {

    std::cout << "deconstruction" << std::endl;
}

template<class T>
T CConfigService::LookUpConfigVar(const std::string &key, T defaultValue) {
    return defaultValue;
}



ConfigVarBase::ptr Config::LookupBase(const std::string& name) {
    RWMutexType::ReadLock lock(GetMutex());
    auto it = GetDatas().find(name);
    return it == GetDatas().end() ? nullptr : it->second;
}

//"A.B", 10
//A:
//  B: 10
//  C: str

static void ListAllMember(const std::string& prefix,
                          const YAML::Node& node,
                          std::list<std::pair<std::string, const YAML::Node> >& output) {
    if(prefix.find_first_not_of("abcdefghikjlmnopqrstuvwxyz._012345678")
       != std::string::npos) {
        std::cout << "Config invalid name: " << prefix << " : " << node;
        return;
    }
    output.push_back(std::make_pair(prefix, node));
    if(node.IsMap()) {
        for(auto it = node.begin();
            it != node.end(); ++it) {
            ListAllMember(prefix.empty() ? it->first.Scalar()
                                         : prefix + "." + it->first.Scalar(), it->second, output);
        }
    }
}

void Config::LoadFromYaml(const YAML::Node& root) {
    std::list<std::pair<std::string, const YAML::Node> > all_nodes;
    ListAllMember("", root, all_nodes);

    for(auto& i : all_nodes) {
        std::string key = i.first;
        if(key.empty()) {
            continue;
        }

        std::transform(key.begin(), key.end(), key.begin(), ::tolower);
        ConfigVarBase::ptr var = LookupBase(key);

        if(var) {
            if(i.second.IsScalar()) {
                var->fromString(i.second.Scalar());
            } else {
                std::stringstream ss;
                ss << i.second;
                var->fromString(ss.str());
            }
        }
    }
}

static std::map<std::string, uint64_t> s_file2modifytime;
static Mutex s_mutex;

void Config::LoadFromConfDir(const std::string& path, bool force) {
    std::string absoulte_path = "";
    std::vector<std::string> files;
    //FSUtil::ListAllFile(files, absoulte_path, ".yml");

    for(auto& i : files) {

        try {
            YAML::Node root = YAML::LoadFile(i);
            LoadFromYaml(root);
            std::cout << "LoadConfFile file="
                                     << i << " ok";
        } catch (...) {
            std::cout << "LoadConfFile file="
                                      << i << " failed";
        }
    }
}

void Config::Visit(std::function<void(ConfigVarBase::ptr)> cb) {
    RWMutexType::ReadLock lock(GetMutex());
    ConfigVarMap& m = GetDatas();
    for(auto it = m.begin();
        it != m.end(); ++it) {
        cb(it->second);
    }

}