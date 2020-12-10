#include "core/config.h"
#include "yaml-cpp/yaml.h"



/*
 * 配置初始化
 * 默认顺序： 1. 配置文件  2. nacos
 * 当运行目录 config下config.yaml不存在时， 使用nacos 配置
 */
CConfig::CConfig() {

    YAML::Node config = YAML::LoadFile("./config/config.yaml");

    std::string author = config["app"]["author"].as<std::string>();

    std::cout << "config: author is "  << author << std::endl;
}

CConfig::~CConfig() {

    std::cout << "deconstruction" << std::endl;
}